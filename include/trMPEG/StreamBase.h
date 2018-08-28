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
* @author Maxim Serebrennik
*/

#pragma once

#include "Export.h"

extern "C"
{
    // Includes for FFMPEG
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
#include <libavutil/mathematics.h>
#include <libavutil/opt.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>

#pragma comment(lib, "avcodec")
#pragma comment(lib, "avutil")
#pragma comment(lib, "avformat")
#pragma comment(lib, "swscale")
#pragma comment(lib, "swresample")
}

namespace trMPEG
{
    /**
     * @class   StreamBase
     *
     * @brief   Base class for the Server and Slave stream classes
     */
    class TR_MPEG_EXPORT StreamBase
    {
    public:

        /**
         * @fn  StreamBase::StreamBase();
         *
         * @brief   Default constructor.
         */
        StreamBase();

        /**
         * @fn  StreamBase::~StreamBase();
         *
         * @brief   Destructor.
         */
        ~StreamBase();

    protected:

        /**
         * @fn  AVFrame* StreamBase::AllocateFrame(enum AVPixelFormat pixFmt, int width, int height) const;
         *
         * @brief   Creates and Allocates a frame.
         *
         * @param   pixFmt  The pixel format.
         * @param   width   The width of the frame.
         * @param   height  The height of the frame.
         *
         * @return  Null if it fails, else a pointer to an AVFrame.
         */
        AVFrame* AllocateFrame(enum AVPixelFormat pixFmt, int width, int height) const;
    };
}