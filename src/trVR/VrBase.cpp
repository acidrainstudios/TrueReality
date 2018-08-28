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
    VrBase::VrBase(const std::string name) : BaseClass(name)
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

        LOG_I("Driver name: " + GetDeviceProperty(vr::Prop_TrackingSystemName_String))
        LOG_I("Device serial number: " + GetDeviceProperty(vr::Prop_SerialNumber_String))
        LOG_I("HMD model: " + GetDeviceProperty(vr::Prop_ModelNumber_String))

        mInit = true;
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
    std::string VrBase::GetDeviceProperty(vr::TrackedDeviceProperty property)
    {
        uint32_t bufferLen = mVrSystem->GetStringTrackedDeviceProperty(vr::k_unTrackedDeviceIndex_Hmd, property, nullptr, 0);
        
        if (bufferLen == 0)
        {
            return trUtil::StringUtils::STR_BLANK;
        }
        
        char* buffer = new char[bufferLen];
        bufferLen = mVrSystem->GetStringTrackedDeviceProperty(vr::k_unTrackedDeviceIndex_Hmd, property, buffer, bufferLen);
        std::string result = buffer;
        delete []buffer;
        return result;
    }
}