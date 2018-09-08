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
#include <trVR/MirrorTexture.h>

#include <trUtil/Logging/Log.h>

#include <osg/GLExtensions>
#include <osg/GraphicsContext>

namespace trVR
{
    const trUtil::RefStr MirrorTexture::CLASS_TYPE = trUtil::RefStr("trVR::MirrorTexture");
    
    //////////////////////////////////////////////////////////////////////////
    MirrorTexture::MirrorTexture(const std::string& name) : BaseClass(name)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& MirrorTexture::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    MirrorTexture::MirrorTexture(osg::State* state, GLuint width, GLuint height)
    : mHeight(height)
    , mWidth(width)
    {
        const osg::GLExtensions* fbo_ext = state->get<osg::GLExtensions>();

        if (fbo_ext)
        {
            fbo_ext->glGenFramebuffers(1, &mMirrorFBO);
            fbo_ext->glBindFramebuffer(GL_READ_FRAMEBUFFER_EXT, mMirrorFBO);

            glGenTextures(1, &mMirrorTex);
            glBindTexture(GL_TEXTURE_2D, mMirrorTex);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

            fbo_ext->glFramebufferTexture2D(GL_READ_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, mMirrorTex, 0);
            fbo_ext->glFramebufferRenderbuffer(GL_READ_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);
            fbo_ext->glBindFramebuffer(GL_READ_FRAMEBUFFER_EXT, 0);

            LOG_A("Mirror Texture created successfully")
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void MirrorTexture::Destroy(osg::GraphicsContext* gc)
    {
        const osg::GLExtensions* fbo_ext = gc->getState()->get<osg::GLExtensions>();

        if (fbo_ext)
        {
            fbo_ext->glDeleteFramebuffers(1, &mMirrorFBO);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void MirrorTexture::BlitTexture(osg::GraphicsContext* gc)
    {
        const osg::GLExtensions* fbo_ext = gc->getState()->get<osg::GLExtensions>();

        if (fbo_ext)
        {
            fbo_ext->glBindFramebuffer(GL_DRAW_FRAMEBUFFER_EXT, mMirrorFBO);
            fbo_ext->glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, mMirrorTex, 0);
            fbo_ext->glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);

            glClearColor(1, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            //--------------------------------
            // Copy left eye image to mirror
            fbo_ext->glBindFramebuffer(GL_READ_FRAMEBUFFER_EXT, mLeftEyeTex->GetResolveFbo());
            fbo_ext->glFramebufferTexture2D(GL_READ_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, mLeftEyeTex->GetColorTex(), 0);
            fbo_ext->glFramebufferRenderbuffer(GL_READ_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);

            fbo_ext->glBlitFramebuffer(0, 0, mLeftEyeTex->GetWidth(), mLeftEyeTex->GetHeight(),
                                       0, 0, mWidth / 2, mHeight,
                                       GL_COLOR_BUFFER_BIT, GL_NEAREST);
            //--------------------------------
            // Copy right eye image to mirror
            fbo_ext->glBindFramebuffer(GL_READ_FRAMEBUFFER_EXT, mRightEyeTex->GetResolveFbo());
            fbo_ext->glFramebufferTexture2D(GL_READ_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, mRightEyeTex->GetColorTex(), 0);
            fbo_ext->glFramebufferRenderbuffer(GL_READ_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);

            fbo_ext->glBlitFramebuffer(0, 0, mRightEyeTex->GetWidth(), mRightEyeTex->GetHeight(),
                                       mWidth / 2, 0, mWidth, mHeight,
                                       GL_COLOR_BUFFER_BIT, GL_NEAREST);
            //---------------------------------

            fbo_ext->glBindFramebuffer(GL_FRAMEBUFFER_EXT, 0);

            // Blit mirror texture to back buffer
            fbo_ext->glBindFramebuffer(GL_READ_FRAMEBUFFER_EXT, mMirrorFBO);
            fbo_ext->glBindFramebuffer(GL_DRAW_FRAMEBUFFER_EXT, 0);
            GLint w = mWidth;
            GLint h = mHeight;
            fbo_ext->glBlitFramebuffer(0, 0, w, h,
                                       0, 0, w, h,
                                       GL_COLOR_BUFFER_BIT, GL_NEAREST);
            fbo_ext->glBindFramebuffer(GL_READ_FRAMEBUFFER_EXT, 0);
        }
    }
}