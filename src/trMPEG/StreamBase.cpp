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

#include <trMPEG/StreamBase.h>

#include <trUtil/Logging/Log.h>
#include <trUtil/StringUtils.h>

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
    //////////////////////////////////////////////////////////////////////////
    StreamBase::StreamBase()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    StreamBase::~StreamBase()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    std::string StreamBase::GetUDPAddress()
    {
        return mUDPAddrs;
    }

    //////////////////////////////////////////////////////////////////////////
    AVFrame* StreamBase::AllocateFrame(enum AVPixelFormat pixFmt, int width, int height) const
    {
        AVFrame *newFrame;
        int ret;
        newFrame = av_frame_alloc();
        if (!newFrame)
        {
            LOG_E("Could not allocate frame")
            return nullptr;
        }

        newFrame->format = pixFmt;
        newFrame->width = width;
        newFrame->height = height;

        /* Allocate the data buffers for the frame */
        ret = av_frame_get_buffer(newFrame, 32);
        if (ret < 0)
        {
            LOG_E("Could not allocate frame data.")
            exit(1);
        }

        /* Make sure the frame data is writable */
        if (int val = av_frame_make_writable(newFrame) < 0)
        {
            LOG_E("Frame data is not writable: " + trUtil::StringUtils::ToString<int>(val))
            exit(1);
        }

        return newFrame;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamBase::FlipYUV420Frame(AVFrame* frame) const
    {
        for (int i = 0; i < 4; i++)
        {
            if (i != 0)
            {
                frame->data[i] += frame->linesize[i] * ((frame->height >> 1) - 1);
            }
            else
            {
                frame->data[i] += frame->linesize[i] * (frame->height - 1);
            }
            frame->linesize[i] = -frame->linesize[i];
        }
    }

    //////////////////////////////////////////////////////////////////////////
    AVCodec * StreamBase::FindDecoderCodecByID(AVCodecID id)
    {        
        AVCodec* codec = avcodec_find_decoder(id);
        CheckCodecValidity(codec);
        return codec;
    }

    //////////////////////////////////////////////////////////////////////////
    AVCodec* StreamBase::FindEncoderCodecByID(AVCodecID id)
    {
        AVCodec* codec = avcodec_find_encoder(id);
        CheckCodecValidity(codec);
        return codec;
    }

    //////////////////////////////////////////////////////////////////////////
    bool StreamBase::CheckCodecValidity(const AVCodec* codec) const
    {
        // Make sure we found some codec
        if (codec == nullptr)
        {
            LOG_E("Could not find the needed Codec")
            exit(1);
        }

        // Check if the found codec is supported
        if (codec->id == AV_CODEC_ID_MPEG1VIDEO || codec->id == AV_CODEC_ID_MPEG2VIDEO
            || codec->id == AV_CODEC_ID_H264 || codec->id == AV_CODEC_ID_HEVC)
        {
            LOG_D("The Codec " + trUtil::RefStr(avcodec_get_name(codec->id)) + " is supported")
            return true;
        }
        else
        {
            LOG_W(trUtil::RefStr(avcodec_get_name(codec->id)) + " is an unsupported Codec, trMPEG might not work correctly")
            return false;
        }
    }
}
