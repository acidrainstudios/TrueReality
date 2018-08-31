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

#include <trBase/SmrtPtr.h>
#include <trMPEG/StreamBase.h>

#include <osg/Image>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
//#include <libavformat/avio.h>
#include <libswscale/swscale.h>
}

#include <fstream>

namespace trMPEG
{
    /**
     * @class   StreamSlave
     *
     * @brief   This class is used to read in a UDP MPEG broadcast from a network or a file source
     */
    class TR_MPEG_EXPORT StreamSlave : public trMPEG::StreamBase
    {
    public:

        /**
         * @fn  StreamSlave::StreamSlave();
         *
         * @brief   Default constructor.
         */
        StreamSlave();

        /**
         * @fn  StreamSlave::~StreamSlave();
         *
         * @brief   Destructor.
         */
        ~StreamSlave();

        /**
         * @fn  void StreamSlave::Connect(osg::Image* targetImage);
         *
         * @brief   Connects to the network stream, and sets the target image 
         *
         * @param [in,out]  targetImage If non-null, the target image to connect.
         */
        void Connect(osg::Image* targetImage);

        /**
         * @fn  void StreamSlave::Update();
         *
         * @brief   Updates the target image from connected stream data
         */
        void Update();

        /**
         * @fn  virtual void StreamSlave::SetFlipImageVertically(bool flip) override;
         *
         * @brief   Flip image vertically.
         *
         * @param   flip    True to flip.
         */
        virtual void SetFlipImageVertically(bool flip) override;

    protected:

        trBase::SmrtPtr<osg::Image> mImageTarget;

        AVFrame* mFrameYUV = nullptr;
        AVFrame* mFrameRGB = nullptr;

        AVStream* mInputStream = nullptr;
        AVFormatContext* mFrmtContext = nullptr;

        AVCodecContext* mCodecContext = nullptr;

        SwsContext* mFrameConvertCtx = nullptr;

        AVPacket mPacket;
    };
}