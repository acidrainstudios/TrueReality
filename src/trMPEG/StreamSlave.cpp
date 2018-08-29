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
        av_frame_free(&mPictureYUV);
        av_frame_free(&mPictureRGB);

        av_read_pause(mFrmtContext);
        avio_close(mOutputFrmtContext->pb);
        avformat_free_context(mOutputFrmtContext);

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

        //Open a UDP port
        LOG_D("Opening Input")
            if (avformat_open_input(&mFrmtContext, "udp://192.168.1.152:7000", nullptr, nullptr) != 0)
            //if (avformat_open_input(&mFrmtContext, "udp://130.46.208.38:7000", nullptr, nullptr) != 0)
            {
                exit(1);
            }

        LOG_D("Finding Input Stream")
            if (avformat_find_stream_info(mFrmtContext, nullptr) < 0)
            {
                exit(1);
            }

        //search video stream
        for (unsigned int i = 0; i < mFrmtContext->nb_streams; ++i)
        {
            if (mFrmtContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
            {
                mVideoStreamIndex = i;
            }
        }

        av_init_packet(&mPacket);

        //Open output file
        mOutputFrmtContext = avformat_alloc_context();

        

        //start reading packets from stream
        av_read_play(mFrmtContext);    //play Stream

        // Get the codec
        //AVCodec *codec = avcodec_find_decoder(AV_CODEC_ID_H264);
        AVCodec *codec = avcodec_find_decoder(AV_CODEC_ID_MPEG2VIDEO);
        if (!codec)
        {
            exit(1);
        }

        // Add this to allocate the context by codec
        mCodecContext = avcodec_alloc_context3(codec);

        avcodec_get_context_defaults3(mCodecContext, codec);
        avcodec_copy_context(mCodecContext, mFrmtContext->streams[mVideoStreamIndex]->codec);

        if (avcodec_open2(mCodecContext, codec, nullptr) < 0)
        {
            exit(1);
        }

        mFrameConvertCtx = sws_getContext(mCodecContext->width, mCodecContext->height,
            mCodecContext->pix_fmt, mCodecContext->width, mCodecContext->height, AV_PIX_FMT_RGB24,
            SWS_BICUBIC, nullptr, nullptr, nullptr);

        mPictureYUV = AllocateFrame(AV_PIX_FMT_YUV420P, mCodecContext->width, mCodecContext->height);
        mPictureRGB = AllocateFrame(AV_PIX_FMT_RGB24, mCodecContext->width, mCodecContext->height);
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::Update()
    {
        av_read_frame(mFrmtContext, &mPacket);

        if (mPacket.stream_index == mVideoStreamIndex)
        {    

            if (mStream == nullptr)
            {
                //create stream in file
                std::cerr << "3 create stream" << std::endl;
                mStream = avformat_new_stream(mOutputFrmtContext, mFrmtContext->streams[mVideoStreamIndex]->codec->codec);
                avcodec_copy_context(mStream->codec, mFrmtContext->streams[mVideoStreamIndex]->codec);
                mStream->sample_aspect_ratio = mFrmtContext->streams[mVideoStreamIndex]->codec->sample_aspect_ratio;
            }

            int check = 0;
            mPacket.stream_index = mStream->id;
            
            int result = avcodec_decode_video2(mCodecContext, mPictureYUV, &check, &mPacket);
            std::cerr << "Frame: " << mFrameCounter <<" Bytes decoded " << result << " check " << check << std::endl;

            if (mFrameCounter > 100)    //cnt < 0)
            {
                sws_scale(mFrameConvertCtx, mPictureYUV->data, mPictureYUV->linesize, 0, mCodecContext->height, mPictureRGB->data, mPictureRGB->linesize);

                if (mImageTarget.Valid())
                {
                    std::cerr << "Writing Frame: " << mFrameCounter << std::endl;
                    memcpy(mImageTarget->data(), mPictureRGB->data[0], mPictureRGB->linesize[0] * mCodecContext->height);
                    std::cerr << "Copied Data" << std::endl;
            
                    mImageTarget->dirty();
                    std::cerr << "Done!" << std::endl;
                }
            }
            ++mFrameCounter;
        }
        av_packet_unref(&mPacket);
        av_init_packet(&mPacket);
    }
}