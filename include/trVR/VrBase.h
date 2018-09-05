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
        
        bool SubmitFrame(osg::Texture2D* leftTex, osg::Texture2D* rightTex, int contextID = 0,
                         vr::EColorSpace colorSpace = vr::EColorSpace::ColorSpace_Gamma);

		bool SubmitFrame(GLuint leftTex, GLuint rightTex, int contextID = 0,
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
		FramebufferDesc mLeftEyeDesc;
		FramebufferDesc mRightEyeDesc;
    };
}