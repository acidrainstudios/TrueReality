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
#pragma once

#include <GL/glew.h>

#include <trVR/Export.h>

#include <trBase/Base.h>
#include <trBase/Matrix.h>
#include <trBase/Quat.h>
#include <trBase/SmrtPtr.h>
#include <trBase/Vec3.h>

#include <openvr/openvr.h>
#include <osg/Texture2D>

namespace trVR
{
    class TR_VR_EXPORT VrBase : public trBase::Base
    {
    public:
        using BaseClass = trBase::Base;             /// Adds an easy and swappable access to the base class
        
        const static trUtil::RefStr CLASS_TYPE;   /// Holds the class type name for efficient comparisons
        
        /**
         * @fn VrBase::VrBase()
         * 
         * @brief   ctor
         * @param   name    The name of the class type.
         */
        VrBase(const std::string& name = CLASS_TYPE);

        /**
         * @fn VrBase::VrBase(const VrBase& orig)
         * 
         * @brief   Deleted copy constructor as this is not needed.
         * 
         * @param   orig    Original object to be copied
         */
        VrBase(const VrBase& orig) = delete;
        
        /** 
         * @brief   Deleted as this is not needed.
         * @param   orig    Original object to be copied
         * @return 
         */
        VrBase& operator=(const VrBase& orig) = delete;
        
        /**
         * Returns the class type
         */
        virtual const std::string& GetType() const override;
        
        /**
         * Initializes the VR instance
         */
        void Init();

        bool InitializeRenderTargets();
        
        /**
         * Calculates and stores the left and right eye adjustment distances
         * from the center of the headset
         */
        void CalculateEyeAdjustments();
        
        /**
         * Calculates and stores the center, left and right projection matrices
         * needed for the cameras to render the correct scene data
         */
        void CalculateProjectionMatrices();
        
        /**
         * Calculates and stores the center, left and right view matrices needed
         * for the cameras to render the correct scene data
         */
        void CalculateViewMatrices();
        
        /**
         * Returns the center projection matrix of the headset
         * @return Center projection matrix of the headset
         */
        trBase::Matrix GetCenterProjectionMatrix() const;
        
        /**
         * Returns the left eye projection matrix of the headset
         * @return Left projection matrix of the headset
         */
        trBase::Matrix GetLeftProjectionMatrix() const;
        
        /**
         * Returns the right eye projection matrix of the headset
         * @return Right projection matrix of the headset
         */
        trBase::Matrix GetRightProjectionMatrix() const;
        
        /**
         * Returns the left view matrix of the headset
         * @return Left view matrix of the headset
         */
        trBase::Matrix GetLeftViewMatrix() const;
        
        /**
         * Returns the right view matrix of the headset
         * @return Right view matrix of the headset
         */
        trBase::Matrix GetRightViewMatrix() const;

        /**
         * Gets the IVRSystem pointer to be used outside the class.
         * @return Pointer to the IVRSystem.
         */
        vr::IVRSystem* GetVrSystem();
        
        /**
         * Returns the last orientation of the device.
         * @return quaternion holding the orientation of the device
         */
        trBase::Quat GetOrientation() const;
        
        /**
         * Returns the last position of the device.
         * @return vector containing the position of the device.
         */
        trBase::Vec3 GetPosition() const;
        
        /**
         * Gets the current pose of the headset and sets the member variables.
         */
        void GetHeadsetPose();
        
        /**
         * Takes an OpenVR matrix and converts it to a trBase::Matrix
         * @param mat OpenVR matrix type
         * @return trBase::Matrix containing the OpenVR matrix data.
         */
        trBase::Matrix ConvertOpenvrMatrix(const vr::HmdMatrix34_t& mat);
        
        /**
         * Takes an OpenVR matrix and converts it to a trBase::Matrix
         * @param mat OpenVR matrix type
         * @return trBase::Matrix containing the OpenVR matrix data.
         */
        trBase::Matrix ConvertOpenvrMatrix(const vr::HmdMatrix44_t& mat);
        
        /**
         * Returns the status of the HMD
         * @return Boolean containing the status of the headset
         */
        bool IsHMDPresent() const;
        
        /**
         * Returns the status of the OpenVR/SteamVR system
         * @return Boolean containing the status of the OpenVR/SteamVR system
         */
        bool IsSystemReady() const;
        
        /**
         * Returns the initialization status of the class.
         * @return Boolean containing the status of the initialization of the class
         */
        bool IsInit() const;
        
        /**
         * Performs the shutdown process of OpenVR/SteamVR
         */
        void Shutdown();
        
        /**
         * Takes two OSG 2D textures, representing the left and right eye scenes,
         * as input, gets their locations within the graphics context and submits
         * these to the headset via the other SubmitFrame method.
         * @param leftTex OSG Texture2D containing the left eye scene
         * @param rightTex OSG Texture2D containing the right eye scene
         * @param contextID The graphics context in which to pull the textures
         * @param colorSpace OpenVR color space used for the textures within the headset
         * @return Boolean containing the success of the submission to the headset
         */
        bool SubmitFrame(osg::Texture2D* leftTex, osg::Texture2D* rightTex, int contextID = 0,
                         vr::EColorSpace colorSpace = vr::EColorSpace::ColorSpace_Gamma);

        /**
         * Takes two GL handles, representing the left and right eye textures, as
         * input and submits these to the headset.
         * @param leftTex GL texture location within the corresponding context
         * @param rightTex GL texture location within the corresponding context
         * @param colorSpace OpenVR color space used for the textures within the headset
         * @return Boolean containing the success of the submission to the headset
         */
        bool SubmitFrame(GLuint leftTex, GLuint rightTex, 
                         vr::EColorSpace colorSpace = vr::EColorSpace::ColorSpace_Gamma);

    protected:
        /**
         * @fn VrBase::~VrBase()
         * 
         * @brief   dtor
         */
        virtual ~VrBase() = default;
        
        vr::IVRSystem* mVrSystem = nullptr; /// Pointer for OpenVR's IVRSystem
        vr::IVRRenderModels* mVrRenderModels = nullptr; /// Pointer for OpenVR's IVRRenderModels
        
    private:
        struct FramebufferDesc
        {
            GLuint mDepthBufferId;
            GLuint mRenderTextureId;
            GLuint mRenderFramebufferId;
            GLuint mResolveTextureId;
            GLuint mResolveFramebufferId;
        };

        std::string GetDeviceProperty(vr::TrackedDeviceIndex_t deviceIndex, vr::TrackedDeviceProperty property);
        
        std::string DisplayCompositorError(vr::EVRCompositorError error);

        bool CreateFrameBuffer(int width, int height, FramebufferDesc& framebufferDesc);

        uint32_t mRenderHeight = 0; /// Preferred height of the render target
        uint32_t mRenderWidth = 0; /// Preferred width of the render target
        bool mInit = false; /// Class initialization status
        trBase::Quat mOrientation; /// Headset orientation
        trBase::Vec3 mPosition; /// Headset position
        bool mSysReady = false; /// OpenVR system initialization status
        trBase::Matrix mCenterProjectionMatrix; /// Projection matrix for center of headset
        trBase::Matrix mLeftProjectionMatrix; /// Projection matrix for left eye
        trBase::Matrix mRightProjectionMatrix; /// Projection matrix for right eye
        trBase::Matrix mLeftViewMatrix; /// View matrix for left eye
        trBase::Matrix mRightViewMatrix; /// View matrix for right eye
        trBase::Vec3 mLeftEyeAdjustment; /// View adjustment for left eye
        trBase::Vec3 mRightEyeAdjustment; /// View adjustment for right eye
        FramebufferDesc mLeftEyeDesc;
        FramebufferDesc mRightEyeDesc;
    };
}