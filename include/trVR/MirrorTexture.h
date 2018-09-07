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
 * Created on September 7, 2018, 5:25 PM
 */
#pragma once

#include <GL/glew.h>

#include <trVR/Export.h>
#include <trVR/OpenVRTexture.h>

#include <trBase/Base.h>
#include <trBase/SmrtPtr.h>

#include <osg/State>

namespace trVR
{
    class TR_VR_EXPORT MirrorTexture : public trBase::Base
    {
    public:
        using BaseClass = trBase::Base;             /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;   /// Holds the class type name for efficient comparisons

        /**
         * @fn MirrorTexture::MirrorTexture()
         * 
         * @brief   ctor
         * @param   name    The name of the class type.
         */
        MirrorTexture(const std::string& name = CLASS_TYPE);

        /**
         * Specialized constructor
         * @param state osg state 
         * @param width
         * @param height
         */
        MirrorTexture(osg::State* state, GLuint width, GLuint height);

        /**
         * @fn MirrorTexture::MirrorTexture(const MirrorTexture& orig)
         * 
         * @brief   Deleted copy constructor as this is not needed.
         * 
         * @param   orig    Original object to be copied
         */
        MirrorTexture(const MirrorTexture& orig) = delete;
        
        /** 
         * @brief   Deleted as this is not needed.
         * @param   orig    Original object to be copied
         * @return 
         */
        MirrorTexture& operator=(const MirrorTexture& orig) = delete;

        /**
         * Returns the class type
         */
        virtual const std::string& GetType() const override;

        void Destroy(osg::GraphicsContext* gc);
        
        void BlitTexture(osg::GraphicsContext* gc);
    protected:
        /**
         * @fn MirrorTexture::~MirrorTexture()
         * 
         * @brief   dtor
         */
        virtual ~MirrorTexture() = default;

        GLuint mHeight;
        GLuint mMirrorFBO;
        GLuint mMirrorTex;
        GLuint mWidth;
        trBase::SmrtPtr<trVR::OpenVRTexture> mLeftEyeTex;
        trBase::SmrtPtr<trVR::OpenVRTexture> mRightEyeTex;
    };
}