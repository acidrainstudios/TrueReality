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
* @author Robert Osfield
* @author Karl Cary
* @author Maxim Serebrennik
*/

#pragma once

#include <GL/glew.h> //Needs to be included before the export macros. 

#include <trMPEG/Export.h>

#include <osg/Camera>
#include <osg/GLExtensions>
#include <osg/RenderInfo>

#include <vector>


namespace trMPEG
{

    typedef std::vector<GLuint> PBOBuffer;

    /**
     * @class   PBOCopyCallback
     *
     * @brief   A pbo copy callback that copies the image data from a texture camera to local RAM using Pixel Buffer Objects.
     */
    class TR_MPEG_EXPORT PBOCopyCallback : public osg::Camera::DrawCallback
    {
    public:

        /**
         * @fn  PBOCopyCallback::PBOCopyCallback(int width, int height, int PBOCopyCallbackSize = 2, GLenum pixelFormat = GL_RGBA);
         *
         * @brief   Constructor.
         *
         * @param   width               The width of the frame.
         * @param   height              The height of the frame.
         * @param   PBOCopyCallbackSize (Optional) Size of the pbo copy callback.
         * @param   pixelFormat         (Optional) The pixel format.
         */
        PBOCopyCallback(int width, int height, int PBOCopyCallbackSize = 2, GLenum pixelFormat = GL_RGBA);

        /**
         * @fn  PBOCopyCallback::~PBOCopyCallback();
         *
         * @brief   Destructor.
         */
        ~PBOCopyCallback();

        /**
         * @fn  virtual void PBOCopyCallback::operator()(osg::RenderInfo& renderInfo) const;
         *
         * @brief   Function call operator that is called at every frame.
         *
         * @param [in,out]  renderInfo  Information describing the render objects.
         */
        virtual void operator()(osg::RenderInfo& renderInfo) const;

        /**
         * @fn  virtual void PBOCopyCallback::GenerateBuffer(GLuint& PBOCopyCallback) const;
         *
         * @brief   Generates the PBOCopyCallback buffers.
         *
         * @param [in,out]  PBOCopyCallback The PBOCopyCallback.
         */
        virtual void GenerateBuffer(GLuint& PBOCopyCallback) const;

        /**
         * @fn  virtual void PBOCopyCallback::ReadPixels() const;
         *
         * @brief   Reads the pixels from buffers.
         */
        virtual void ReadPixels() const;

        /**
         * @fn  virtual void PBOCopyCallback::HandleData(const GLubyte* src) const = 0;
         *
         * @brief   Method that will receive the copied data for users post processing. Should be
         *          overwritten by the user to get the data.
         *
         * @param   src Source for the.
         */
        virtual void HandleData(const GLubyte* src) const = 0;

        /**
         * @fn  virtual void PBOCopyCallback::SetSilent(bool silent);
         *
         * @brief   Sets logging and general screen messaging off.
         *
         * @param   silent  True to silent.
         */
        virtual void SetSilent(bool silent);

    protected:
        
        bool mSilent = true;

        mutable bool mGlewInit = false;

        mutable PBOBuffer mPBOBuffer;
        mutable unsigned int mCurrentPBOIndex = 0;
        mutable unsigned int mNextPBOIndex = 0;
        mutable bool mReadyForCopying = false;

        GLenum mPixelFormat = GL_RGBA;
        GLenum mType = GL_UNSIGNED_BYTE;
        int mWidth = 800;
        int mHeight = 600;
    };
}