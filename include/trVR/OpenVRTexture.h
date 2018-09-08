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
 * Created on September 7, 2018, 5:46 PM
 */
#pragma once

#include <GL/glew.h>

#include <trVR/Export.h>

#include <trBase/Base.h>

#include <osg/State>

namespace trVR
{
    class TR_VR_EXPORT OpenVRTexture : public trBase::Base
    {
    public:
        using BaseClass = trBase::Base;             /// Adds an easy and swappable access to the base class
        
        const static trUtil::RefStr CLASS_TYPE;   /// Holds the class type name for efficient comparisons
        
        /**
         * @fn OpenVRTexture::OpenVRTexture()
         * 
         * @brief   ctor
         * @param   name    The name of the class type.
         */
        OpenVRTexture(const std::string& name = CLASS_TYPE);
        
        /**
         * @brief Specialized constructor that initializes the class with the
         * provided parameters
         * 
         * @param state OSG state from within a graphics context
         * @param width Width of the texture
         * @param height Height of the texture
         * @param name Name/type of the class
         */
        OpenVRTexture(osg::State& state, int width, int height, const std::string& name = CLASS_TYPE);

        /**
         * @fn OpenVRTexture::OpenVRTexture(const OpenVRTexture& orig)
         * 
         * @brief   Deleted copy constructor as this is not needed.
         * 
         * @param   orig    Original object to be copied
         */
        OpenVRTexture(const OpenVRTexture& orig) = delete;
        
        /** 
         * @brief   Deleted as this is not needed.
         * @param   orig    Original object to be copied
         * @return 
         */
        OpenVRTexture& operator=(const OpenVRTexture& orig) = delete;
        
        /**
         * Returns the class type
         */
        virtual const std::string& GetType() const override;
        
        /**
         * @brief Initialization method for the class
         * 
         * @param state OSG state from within a graphics context
         * @param width Width of the texture
         * @param height Height of the texture
         * @param name Name/type of the class
         */
        bool Initialize(osg::State& state, int width, int height);
        
        /**
         * Returns the GL handle for the color texture
         * @return GL handle for the color texture
         */
        GLuint GetColorTex();
        
        /**
         * Returns the height of the GL texture
         * @return Height of the GL texture
         */
        GLuint GetHeight() const;
        
        /**
         * Returns the GL handle for the resolve FBO
         * @return GL handle for the resolve FBO
         */
        GLuint GetResolveFbo();
        
        /**
         * Returns the width of the GL texture
         * @return Width of the GL texture
         */
        GLuint GetWidth() const;
    protected:
        /**
         * @fn OpenVRTexture::~OpenVRTexture()
         * 
         * @brief   dtor
         */
        virtual ~OpenVRTexture() = default;
    private:
        GLuint mColorTex = 0;
        GLuint mHeight = 1200;
        GLuint mResolveFbo = 0;
        GLuint mWidth = 1080;
    };
}