/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* @author Karl Cary
* @author Maxim Serebrennik         
*/

#include <trMPEG/PBOCopyCallback.h>
#include <trUtil/Logging/Log.h>
#include <trUtil/StringUtils.h>

#include <osg/BufferObject>
#include <osg/Camera>
#include <osg/RenderInfo>

#include <vector>
#include <iostream>

namespace trMPEG
{
    //////////////////////////////////////////////////////////////////////////
    PBOCopyCallback::PBOCopyCallback(int width, int height, int PBOCopyCallbackSize, GLenum pixelFormat)
    {
        mPixelFormat = pixelFormat;
        mHeight = height;
        mWidth = width;

        for (int i = 0; i < PBOCopyCallbackSize; i++)
        {
            mPBOBuffer.push_back(0);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    PBOCopyCallback::~PBOCopyCallback()
    {

    }

    //////////////////////////////////////////////////////////////////////////
    void PBOCopyCallback::operator()(osg::RenderInfo& renderInfo) const
    {
        if (!mGlewInit)
        {
            LOG_I("Detecting presence of GLEW")
            GLenum err = glewInit();
            if (GLEW_OK != err)
            {
                /* Problem: glewInit failed, something is seriously wrong. */
                std::cout << "Error: " << glewGetErrorString(err) << std::endl;
            }
            if (!mSilent)
            {
                std::cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;
                std::cout << "Using GL Version: " << osg::getGLVersionNumber() << std::endl;
            }            

            mGlewInit = true;
        }

        mNextPBOIndex = (mCurrentPBOIndex + 1) % mPBOBuffer.size();

        GLuint& copyPBOCopyCallback = mPBOBuffer[mCurrentPBOIndex];
        GLuint& readPBOCopyCallback = mPBOBuffer[mNextPBOIndex];

        //Check if we have something to copy
        if(copyPBOCopyCallback != 0)
        {
            mReadyForCopying = true;
        }
        else
        {
            mReadyForCopying = false;
        }

        if (copyPBOCopyCallback == 0)
        {
            LOG_D("Generating PBO copy buffer")
            GenerateBuffer(copyPBOCopyCallback);
        }
            
        if (readPBOCopyCallback == 0)
        {
            LOG_D("Generating PBO read buffer")
            GenerateBuffer(readPBOCopyCallback);
        }            

        if (mReadyForCopying)
        {
            //Start the read of the current buffer
            glBindBuffer(GL_PIXEL_PACK_BUFFER, readPBOCopyCallback);
            ReadPixels();

            //Get the data from the previous read
            glBindBuffer(GL_PIXEL_PACK_BUFFER, copyPBOCopyCallback);
            GLubyte *src = static_cast<GLubyte*>(glMapBuffer(GL_PIXEL_PACK_BUFFER_ARB, GL_READ_ONLY_ARB));

            if (src)
            {
                glUnmapBuffer(GL_PIXEL_PACK_BUFFER);

                HandleData(src);
            }

            glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
        }

        mCurrentPBOIndex = mNextPBOIndex;
    }

    //////////////////////////////////////////////////////////////////////////
    void PBOCopyCallback::ReadPixels() const
    {
        glReadPixels(0, 0, mWidth, mHeight, mPixelFormat, mType, 0);
    }

    //////////////////////////////////////////////////////////////////////////
    void PBOCopyCallback::SetSilent(bool silent)
    {
        mSilent = silent;
    }

    //////////////////////////////////////////////////////////////////////////
    void PBOCopyCallback::GenerateBuffer(GLuint& PBOCopyCallback) const
    {
        glGenBuffers(1, &PBOCopyCallback);
        glBindBuffer(GL_PIXEL_PACK_BUFFER, PBOCopyCallback);

        if (mPixelFormat == GL_RGB)
        {
            mPixelFormatSize = 3;
        }
        else if (mPixelFormat == GL_RGBA)
        {
            mPixelFormatSize = 4;
        }
        else
        {
            LOG_E("Unsupported pixel format was detected")
            mPixelFormatSize = 0;
        }
        glBufferData(GL_PIXEL_PACK_BUFFER, mWidth * mHeight * mPixelFormatSize, 0, GL_STREAM_READ);
    }
}