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

#include <trVR/OpenVRTexture.h>

#include <trUtil/Logging/Log.h>
#include <trUtil/StringUtils.h>

#include <osg/RenderInfo>

namespace trVR
{
    const trUtil::RefStr OpenVRTexture::CLASS_TYPE = trUtil::RefStr("trVR::OpenVRTexture");
    
    //////////////////////////////////////////////////////////////////////////
    OpenVRTexture::OpenVRTexture(const std::string& name) : BaseClass(name)
    {
    }
    
    //////////////////////////////////////////////////////////////////////////
    OpenVRTexture::OpenVRTexture(osg::State& state, int width, int height, const std::string& name) : BaseClass(name)
    {
        Initialize(state, width, height);
    }
    
    //////////////////////////////////////////////////////////////////////////
    const std::string& OpenVRTexture::GetType() const
    {
        return CLASS_TYPE;
    }
    
    //////////////////////////////////////////////////////////////////////////
    bool OpenVRTexture::Initialize(osg::State& state, const int width, const int height)
    {
        mWidth = width;
        mHeight = height;
        
        const osg::GLExtensions* fbo_ext = state.get<osg::GLExtensions>();
    
        if (fbo_ext)
        {
            float* test = new float[4*width*height];
            static int i = 0;
            
            for (int y = 0; y < height; ++y)
            {
                for (int x = 0; x < width;)
                {
                    test[y*4*width + x] = x + y + i * 3.0;
                    ++x;
                    test[y*4*width + x] = 128 + y + i * 2.0;
                    ++x;
                    test[y*4*width + x] = 64 + x + i * 5.0;
                    ++x;
                    test[y*4*width + x] = 1.0;
                    ++x;
                }
            }
            
            fbo_ext->glGenFramebuffers(1, &mResolveFbo);

            glGenTextures(1, &mColorTex);
            glBindTexture(GL_TEXTURE_2D, mColorTex);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, test);
            
            // check FBO status
            GLenum status = fbo_ext->glCheckFramebufferStatus(GL_FRAMEBUFFER_EXT);
            if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
            {
                LOG_W("Problem setting up frame buffer object.")
                return false;
            }

            return true;
        }
        
        LOG_E("Initialization of the texture buffer has failed. Chances are the "
              "graphics context is not available during the initialization.")

        return false;
    }
    
    //////////////////////////////////////////////////////////////////////////
    void OpenVRTexture::PostRenderUpdate(osg::RenderInfo& info)
    {
        const osg::GLExtensions* fbo_ext = info.getState()->get<osg::GLExtensions>();
    
        if (fbo_ext)
        {
            //fbo_ext->glBindFramebuffer(GL_FRAMEBUFFER_EXT, mResolveFbo);

#ifdef _DEBUG
            GLenum status = fbo_ext->glCheckFramebufferStatus(GL_FRAMEBUFFER_EXT);

            if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
            {
                LOG_W("GL status of buffer: " + trUtil::StringUtils::ToString(status))
            }
#endif

            fbo_ext->glBindFramebuffer(GL_FRAMEBUFFER_EXT, 0);
        }
    }
    
    //////////////////////////////////////////////////////////////////////////
    void OpenVRTexture::PreRenderUpdate(osg::RenderInfo& info)
    {
        const osg::GLExtensions* fbo_ext = info.getState()->get<osg::GLExtensions>();
    
        if (fbo_ext)
        {
            fbo_ext->glBindFramebuffer(GL_FRAMEBUFFER_EXT, mResolveFbo);

#ifdef _DEBUG
            GLenum status = fbo_ext->glCheckFramebufferStatus(GL_FRAMEBUFFER_EXT);

            if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
            {
                LOG_W("GL status of buffer: " + trUtil::StringUtils::ToString(status))
            }
#endif
        }
    }
    
    //////////////////////////////////////////////////////////////////////////
    GLuint OpenVRTexture::GetColorTex()
    {
        return mColorTex;
    }
    
    //////////////////////////////////////////////////////////////////////////
    GLuint OpenVRTexture::GetHeight() const
    {
        return mHeight;
    }
    
    //////////////////////////////////////////////////////////////////////////
    GLuint OpenVRTexture::GetResolveFbo()
    {
        return mResolveFbo;
    }
    
    //////////////////////////////////////////////////////////////////////////
    GLuint OpenVRTexture::GetWidth() const
    {
        return mWidth;
    }
}