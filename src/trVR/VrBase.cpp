/*
 * True Reality Open Source Game and Simulation Engine
 * Copyright � 2018 Acid Rain Studios LLC
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 3.0 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * @author Alexander Koufos <alexander.p.koufos@leidos.com>
 *
 * Created on July 24, 2018, 7:08 PM
 */
#include <trVR/VrBase.h>

#include <trUtil/Logging/Log.h>
#include <trUtil/StringUtils.h>

namespace trVR
{
    const trUtil::RefStr VrBase::CLASS_TYPE = trUtil::RefStr("trVR::VrBase");
    
    //////////////////////////////////////////////////////////////////////////
    VrBase::VrBase(const std::string& name) : BaseClass(name)
    {
    }
    
    //////////////////////////////////////////////////////////////////////////
    const std::string& VrBase::GetType() const
    {
        return CLASS_TYPE;
    }
    
    //////////////////////////////////////////////////////////////////////////
    void VrBase::Init()
    {
        vr::EVRInitError initErr = vr::VRInitError_None;
        mVrSystem = vr::VR_Init(&initErr, vr::VRApplication_Scene);

        if (initErr != vr::VRInitError_None)
        {
            mVrSystem = nullptr;
            LOG_E("Unable to initialize the OpenVR library. OpenVR error: "
                + std::string(vr::VR_GetVRInitErrorAsEnglishDescription(initErr)))
            return;
        }
        else
        {
            LOG_I("Connected to OpenVR library successfully!")
        }

        if (!vr::VRCompositor())
        {
            mVrSystem = nullptr;
            LOG_E("Unable to initialize the compositor.")
            return;
        }
        else
        {
            LOG_I("Compositor initialized successfully!")
        }

        mVrRenderModels = static_cast<vr::IVRRenderModels*>(vr::VR_GetGenericInterface(vr::IVRRenderModels_Version, &initErr));

        if (!mVrRenderModels)
        {
            mVrSystem = nullptr;
            vr::VR_Shutdown();
            LOG_E("Unable to get render models interface. OpenVR error: "
                + std::string(vr::VR_GetVRInitErrorAsEnglishDescription(initErr)))
            return;
        }
        else
        {
            LOG_I("Render models interface initialized!")
        }

        LOG_I("Driver name: " + GetDeviceProperty(vr::k_unTrackedDeviceIndex_Hmd, vr::Prop_TrackingSystemName_String))
        LOG_I("Device serial number: " + GetDeviceProperty(vr::k_unTrackedDeviceIndex_Hmd, vr::Prop_SerialNumber_String))
        LOG_I("HMD model: " + GetDeviceProperty(vr::k_unTrackedDeviceIndex_Hmd, vr::Prop_ModelNumber_String))

//        if (!InitializeRenderTargets())
//        {
//            LOG_W("Problem initializing render targets.")
//        }
        
        mInit = true;
    }

    //////////////////////////////////////////////////////////////////////////
    bool VrBase::InitializeRenderTargets()
    {
        bool lInit = false;
        bool rInit = false;
        
        if (!mVrSystem)
        {
            return false;
        }

        mVrSystem->GetRecommendedRenderTargetSize(&mRenderWidth, &mRenderHeight);
        
        lInit = CreateFrameBuffer(mRenderWidth, mRenderHeight, mLeftEyeDesc);
        rInit = CreateFrameBuffer(mRenderWidth, mRenderHeight, mRightEyeDesc);

        return lInit && rInit;
    }

    //////////////////////////////////////////////////////////////////////////
    bool VrBase::CreateFrameBuffer(int width, int height, FramebufferDesc& framebufferDesc)
    {
        glGenFramebuffers(1, &framebufferDesc.mRenderFramebufferId);
        glBindFramebuffer(GL_FRAMEBUFFER, framebufferDesc.mRenderFramebufferId);
        
        glGenRenderbuffers(1, &framebufferDesc.mDepthBufferId);
	glBindRenderbuffer(GL_RENDERBUFFER, framebufferDesc.mDepthBufferId);
	glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH_COMPONENT, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER,	framebufferDesc.mDepthBufferId);

	glGenTextures(1, &framebufferDesc.mRenderTextureId );
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, framebufferDesc.mRenderTextureId );
	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, GL_RGBA8, width, height, true);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, framebufferDesc.mRenderTextureId, 0);

	glGenFramebuffers(1, &framebufferDesc.mResolveFramebufferId );
	glBindFramebuffer(GL_FRAMEBUFFER, framebufferDesc.mResolveFramebufferId);

	glGenTextures(1, &framebufferDesc.mResolveTextureId );
	glBindTexture(GL_TEXTURE_2D, framebufferDesc.mResolveTextureId );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebufferDesc.mResolveTextureId, 0);

	// check FBO status
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		return false;
	}

	glBindFramebuffer( GL_FRAMEBUFFER, 0 );

	return true;
    }

    //////////////////////////////////////////////////////////////////////////
    vr::IVRSystem* VrBase::GetVrSystem()
    {
            return mVrSystem;
    }
    
    //////////////////////////////////////////////////////////////////////////
    trBase::Quat VrBase::GetOrientation() const
    {
        return mOrientation;
    }
    
    //////////////////////////////////////////////////////////////////////////
    trBase::Vec3 VrBase::GetPosition() const
    {
        return mPosition;
    }
    
    //////////////////////////////////////////////////////////////////////////
    void VrBase::GetHeadsetPose()
    {
        vr::VRCompositor()->SetTrackingSpace(vr::TrackingUniverseStanding);
        
        vr::TrackedDevicePose_t poses[vr::k_unMaxTrackedDeviceCount];
        
        for (unsigned int i = 0; i < vr::k_unMaxTrackedDeviceCount; ++i)
        {
            poses[i].bPoseIsValid = false;
        }
        
        vr::VRCompositor()->WaitGetPoses(poses, vr::k_unMaxTrackedDeviceCount, nullptr, 0);
        
        const vr::TrackedDevicePose_t& pose = poses[vr::k_unTrackedDeviceIndex_Hmd];
        
        if (pose.bPoseIsValid)
        {
            trBase::Matrix matrix = ConvertOpenvrMatrix(pose.mDeviceToAbsoluteTracking);
            trBase::Matrix poseTransform = trBase::Matrix::Inverse(matrix);
            mOrientation.Set(poseTransform.GetRotate());
            mPosition.Set(poseTransform.GetTrans());
            LOG_D("Orientation: " + mOrientation.ToString())
            LOG_D("Position: " + mPosition.ToString())
        }
    }
    
//    //////////////////////////////////////////////////////////////////////////
//    void VrBase::GetControllerPose()
//    {
//        vr::VRCompositor()->SetTrackingSpace(vr::TrackingUniverseStanding);
//        
//        vr::TrackedDevicePose_t poses[vr::k_unMaxTrackedDeviceCount];
//        
//        for (unsigned int i = 0; i < vr::k_unMaxTrackedDeviceCount; ++i)
//        {
//            poses[i].bPoseIsValid = false;
//        }
//        
//        vr::VRCompositor()->WaitGetPoses(poses, vr::k_unMaxTrackedDeviceCount, nullptr, 0);
//        
//        for (unsigned int i = 0; i < vr::k_unMaxTrackedDeviceCount; ++i)
//        {
//            const vr::TrackedDevicePose_t& pose = poses[i];
//            
//            if (mVrSystem->IsTrackedDeviceConnected(i))
//            {
//                LOG_D("Device class: " + GetDeviceProperty(i, vr::Prop_DeviceClass_Int32));
//                LOG_D("Tracking system: " + GetDeviceProperty(i, vr::Prop_TrackingSystemName_String));
//                LOG_D("Model number: " + GetDeviceProperty(i, vr::Prop_ModelNumber_String));
//            }
//            
//            if (vr::VRSystem()->GetTrackedDeviceClass(i) == vr::TrackedDeviceClass::TrackedDeviceClass_HMD)
//            {
//                LOG_D("Found HMD!")
//                if (pose.bPoseIsValid)
//                {
//                    trBase::Matrix matrix = ConvertOpenvrMatrix(pose.mDeviceToAbsoluteTracking);
//                    trBase::Matrix poseTransform = trBase::Matrix::Inverse(matrix);
//                    mOrientation.Set(poseTransform.GetRotate());
//                    mPosition.Set(poseTransform.GetTrans());
//                    LOG_D("Orientation: " + mOrientation.ToString())
//                    LOG_D("Position: " + mPosition.ToString())
//                }
//            }
//        }
//    }
    
    //////////////////////////////////////////////////////////////////////////
    trBase::Matrix VrBase::ConvertOpenvrMatrix(const vr::HmdMatrix34_t& mat)
    {
        trBase::Matrix matrix(
            mat.m[0][0], mat.m[1][0], mat.m[2][0], 0.0,
            mat.m[0][1], mat.m[1][1], mat.m[2][1], 0.0,
            mat.m[0][2], mat.m[1][2], mat.m[2][2], 0.0,
            mat.m[0][3], mat.m[1][3], mat.m[2][3], 1.0
        );
        
        return matrix;
    }
    
    //////////////////////////////////////////////////////////////////////////
    trBase::Matrix VrBase::ConvertOpenvrMatrix(const vr::HmdMatrix44_t& mat)
    {
        trBase::Matrix matrix(
            mat.m[0][0], mat.m[1][0], mat.m[2][0], mat.m[3][0],
            mat.m[0][1], mat.m[1][1], mat.m[2][1], mat.m[3][1],
            mat.m[0][2], mat.m[1][2], mat.m[2][2], mat.m[3][2],
            mat.m[0][3], mat.m[1][3], mat.m[2][3], mat.m[3][3]
        );
        
        return matrix;
    }
    
    //////////////////////////////////////////////////////////////////////////
    bool VrBase::IsHMDPresent() const
    {
        return vr::VR_IsHmdPresent();
    }
    
    //////////////////////////////////////////////////////////////////////////
    bool VrBase::IsInit() const
    {
        return mInit;
    }
    
    //////////////////////////////////////////////////////////////////////////
    bool VrBase::IsSystemReady() const
    {
        return mVrSystem != nullptr && mVrRenderModels != nullptr;
    }
    
    //////////////////////////////////////////////////////////////////////////
    void VrBase::Shutdown()
    {
        vr::VR_Shutdown();
        LOG_I("Shutting down VR system.")
    }
    
    //////////////////////////////////////////////////////////////////////////
    bool VrBase::SubmitFrame(osg::Texture2D* leftTex, osg::Texture2D* rightTex,
                             int contextID, vr::EColorSpace colorSpace)
    {
        // Do left eye stuff
        LOG_D("Creating left eye texture.")
        GLuint texL = leftTex->getTextureObject(contextID)->id();
        
        // Do right eye stuff
        LOG_D("Creating right eye texture.")
        GLuint texR = rightTex->getTextureObject(contextID)->id();
        
        return SubmitFrame(texL, texR, colorSpace);
    }

    //////////////////////////////////////////////////////////////////////////
    bool VrBase::SubmitFrame(GLuint leftTex, GLuint rightTex, vr::EColorSpace colorSpace)
    {
        LOG_D("Using left eye texture.")
        vr::Texture_t leftEyeTex = {(void*)(uintptr_t)leftTex, vr::TextureType_OpenGL, colorSpace};

        LOG_D("Submitting left eye texture.")
        vr::EVRCompositorError lErr = vr::VRCompositor()->Submit(vr::Eye_Left, &leftEyeTex);

        if (lErr != vr::VRCompositorError_None)
        {
            LOG_E("Left eye submit error: " + DisplayCompositorError(lErr))
        }
        else
        {
            LOG_D("Left eye successfully submitted.")
        }

        LOG_D("Using right eye texture.")
        vr::Texture_t rightEyeTex = {(void*)(uintptr_t)rightTex, vr::TextureType_OpenGL, colorSpace};

        LOG_D("Submitting right eye texture.")
        vr::EVRCompositorError rErr = vr::VRCompositor()->Submit(vr::Eye_Right, &rightEyeTex);

        if (rErr != vr::VRCompositorError_None)
        {
            LOG_E("Right eye submit error: " + DisplayCompositorError(rErr))
        }

        return lErr == vr::VRCompositorError_None && rErr == vr::VRCompositorError_None;
    }
    
    //////////////////////////////////////////////////////////////////////////
    std::string VrBase::GetDeviceProperty(vr::TrackedDeviceIndex_t deviceIndex, vr::TrackedDeviceProperty property)
    {
        uint32_t bufferLen = mVrSystem->GetStringTrackedDeviceProperty(deviceIndex, property, nullptr, 0);
        
        if (bufferLen == 0)
        {
            return "Blank device property.";
        }
        
        char* buffer = new char[bufferLen];
        bufferLen = mVrSystem->GetStringTrackedDeviceProperty(deviceIndex, property, buffer, bufferLen);
        std::string result = buffer;
        delete []buffer;
        return result;
    }
    
    //////////////////////////////////////////////////////////////////////////
    std::string VrBase::DisplayCompositorError(vr::EVRCompositorError error)
    {
        switch (error)
        {
            case vr::EVRCompositorError::VRCompositorError_AlreadySubmitted:
                return "Already submitted.";
            case vr::EVRCompositorError::VRCompositorError_DoNotHaveFocus:
                return "Compositor doesn't have focus.";
            case vr::EVRCompositorError::VRCompositorError_IncompatibleVersion:
                return "Incompatible version.";
            case vr::EVRCompositorError::VRCompositorError_IndexOutOfRange:
                return "Index out of range.";
            case vr::EVRCompositorError::VRCompositorError_InvalidBounds:
                return "Invalid bounds.";
            case vr::EVRCompositorError::VRCompositorError_InvalidTexture:
                return "Invalid texture.";
            case vr::EVRCompositorError::VRCompositorError_IsNotSceneApplication:
                return "This is not a scene application";
            case vr::EVRCompositorError::VRCompositorError_None:
                return "No error.";
            case vr::EVRCompositorError::VRCompositorError_RequestFailed:
                return "Request has failed.";
            case vr::EVRCompositorError::VRCompositorError_SharedTexturesNotSupported:
                return "Shared texture is not supported.";
            case vr::EVRCompositorError::VRCompositorError_TextureIsOnWrongDevice:
                return "Texture is on the wrong device.";
            case vr::EVRCompositorError::VRCompositorError_TextureUsesUnsupportedFormat:
                return "Texture format is unsupported.";
            default:
                return "Error is unknown! This should never happen.";
        }
    }
}