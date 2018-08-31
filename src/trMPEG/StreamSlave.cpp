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

#include <trMPEG/StreamSlave.h>

#include <trUtil/Logging/Log.h>
#include <trUtil/StringUtils.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

extern "C" 
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
#include <libswscale/swscale.h>
}

namespace trMPEG
{
    //////////////////////////////////////////////////////////////////////////
    StreamSlave::StreamSlave()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    StreamSlave::~StreamSlave()
    {
        av_frame_free(&mFrameYUV);
        av_frame_free(&mFrameRGB);
        av_read_pause(mFrmtContext);
        avformat_close_input(&mFrmtContext);
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::SetUDPAddress(std::string address)
    {        
        mUDPAddrs = address;        
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::Connect(osg::Image* targetImage)
    {

        mImageTarget = targetImage;

        // Open the initial context variables that are needed        
        mFrmtContext = avformat_alloc_context();        

        // Register everything
        av_register_all();
        avformat_network_init();

        if (mUDPAddrs == trUtil::StringUtils::STR_BLANK)
        {
            mUDPAddrs = "udp://130.46.208.38:7000";
        }

        // Open a UDP port
        LOG_D("Opening Input")
        if (avformat_open_input(&mFrmtContext, trUtil::RefStr("udp://" + mUDPAddrs), nullptr, nullptr) != 0)
        {
            LOG_E("Cant open an input at " + mUDPAddrs)
            exit(1);
        }

        LOG_D("Finding Input Stream")
        if (avformat_find_stream_info(mFrmtContext, nullptr) < 0)
        {
            LOG_E("Cant Finding an Input Stream")
            exit(1);
        }

        // Search video stream
        for (unsigned int i = 0; i < mFrmtContext->nb_streams; ++i)
        {
            if (mFrmtContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
            {
                mInputStream = mFrmtContext->streams[i];
            }
        }

        if (mInputStream == nullptr)
        {
            LOG_E("No Video Stream found")
            exit(1);
        }   

        av_init_packet(&mPacket);

        // Start playing the stream
        av_read_play(mFrmtContext);    

        // Get the codec
        AVCodec *codec = FindDecoderCodecByID(mInputStream->codecpar->codec_id);

        // Add this to allocate the context by codec
        mCodecContext = avcodec_alloc_context3(codec);

        avcodec_get_context_defaults3(mCodecContext, codec);
        avcodec_parameters_to_context(mCodecContext, mInputStream->codecpar);

        /* Threading options */
        mCodecContext->thread_count = 4;
        mCodecContext->thread_type = FF_THREAD_SLICE;
        mCodecContext->slices = 16;

        mCodecContext->slice_flags = SLICE_FLAG_ALLOW_FIELD;

        //AVDictionaryEntry *tag = nullptr;
        //tag = av_dict_get(mFrmtContext->metadata, "publisher", tag, AV_DICT_IGNORE_SUFFIX);
        //if (tag != nullptr)
        //{
        //    std::cout << tag->key << " : " << tag->value << std::endl;
        //}
        //else
        //{
        //    std::cout << "NOP" << std::endl;
        //}   

        // Initialize context
        if (avcodec_open2(mCodecContext, codec, nullptr) < 0)
        {
            LOG_E("Could not initialize Context with " + trUtil::RefStr(avcodec_get_name(codec->id)) + " codec")
            exit(1);
        }

        // Create a color conversion context
        mFrameConvertCtx = sws_getContext(mCodecContext->width, mCodecContext->height, mCodecContext->pix_fmt, 
                                            mCodecContext->width, mCodecContext->height, AV_PIX_FMT_RGB24, SWS_BICUBIC, nullptr, nullptr, nullptr);

        mFrameYUV = AllocateFrame(AV_PIX_FMT_YUV420P, mCodecContext->width, mCodecContext->height);
        mFrameRGB = AllocateFrame(AV_PIX_FMT_RGB24, mCodecContext->width, mCodecContext->height);
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::Update()
    {
        // Read one frame from the Formant Context Stream
        av_init_packet(&mPacket);
        av_read_frame(mFrmtContext, &mPacket);
            
        // Send a packet for decoding to the codec context
        avcodec_send_packet(mCodecContext, &mPacket);
            
        //Read one frame from the Context, if one is read, save it into a YUV Frame
        if (avcodec_receive_frame(mCodecContext, mFrameYUV) >= 0)
        {                
            //Flip the image vertically 
            if (mFlipImageVertically)
            {
                FlipYUV420Frame(mFrameYUV);
            }

            // Convert YUV to RGB
            sws_scale(mFrameConvertCtx, mFrameYUV->data, mFrameYUV->linesize, 0, mCodecContext->height, mFrameRGB->data, mFrameRGB->linesize);

            if (mImageTarget.Valid())
            { // Copy the frame data into the Image, and dirty the image to make sure it refreshes
                memcpy(mImageTarget->data(), mFrameRGB->data[0], mFrameRGB->linesize[0] * mCodecContext->height);
                mImageTarget->dirty();
            }
        } 
        else
        {
            LOG_D("No (Bad) Frame Data...")
        }
        
        // Clear Packet Data
        av_packet_unref(&mPacket);        
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::SetFlipImageVertically(bool flip)
    {
        mFlipImageVertically = flip;
    }
}