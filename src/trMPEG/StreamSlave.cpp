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

        av_free(mPictureYUV);
        av_free(mPictureRGB);
        av_free(mPictureYUVBuffer);
        av_free(mPictureRGBBuffer);

        av_read_pause(mFrmtContext);
        avio_close(mOutputFrmtContext->pb);
        avformat_free_context(mOutputFrmtContext);

    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::Connect()
    {
        // Open the initial context variables that are needed        
        mFrmtContext = avformat_alloc_context();
        

        // Register everything
        av_register_all();
        avformat_network_init();

        //Open a UDP port
        LOG_D("Opening Input")
            //if (avformat_open_input(&mFrmtContext, "udp://192.168.1.152:7000", nullptr, nullptr) != 0)
            if (avformat_open_input(&mFrmtContext, "udp://130.46.208.38:7000", nullptr, nullptr) != 0)
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
            if (mFrmtContext->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
            {
                mVideoStreamIndex = i;
            }
        }

        av_init_packet(&mPacket);

        //Open output file
        mOutputFrmtContext = avformat_alloc_context();

        

        //start reading packets from stream and write them to file
        av_read_play(mFrmtContext);    //play RTSP

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

        int yuvSize = avpicture_get_size(AV_PIX_FMT_YUV420P, mCodecContext->width, mCodecContext->height);

        mPictureYUVBuffer = (uint8_t*)(av_malloc(yuvSize));
        mPictureYUV = av_frame_alloc();
        mPictureRGB = av_frame_alloc();
        int rgbSize = avpicture_get_size(AV_PIX_FMT_RGB24, mCodecContext->width, mCodecContext->height);

        uint8_t* mPictureRGBBuffer = (uint8_t*)(av_malloc(rgbSize));
        avpicture_fill((AVPicture *)mPictureYUV, mPictureYUVBuffer, AV_PIX_FMT_YUV420P, mCodecContext->width, mCodecContext->height);
        avpicture_fill((AVPicture *)mPictureRGB, mPictureRGBBuffer, AV_PIX_FMT_RGB24, mCodecContext->width, mCodecContext->height);
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::Update()
    {
        AVStream* stream = nullptr;
        int cnt = 0;

        while (av_read_frame(mFrmtContext, &mPacket) >= 0 && cnt < 1000)
        { //read ~ 1000 frames

            std::cerr << "1 Frame: " << cnt << std::endl;
            if (mPacket.stream_index == mVideoStreamIndex)
            {    //packet is video

                std::cerr << "2 Is Video" << std::endl;
                if (stream == nullptr)
                {
                    //create stream in file
                    std::cerr << "3 create stream" << std::endl;
                    stream = avformat_new_stream(mOutputFrmtContext, mFrmtContext->streams[mVideoStreamIndex]->codec->codec);
                    avcodec_copy_context(stream->codec, mFrmtContext->streams[mVideoStreamIndex]->codec);
                    stream->sample_aspect_ratio = mFrmtContext->streams[mVideoStreamIndex]->codec->sample_aspect_ratio;
                }

                int check = 0;
                mPacket.stream_index = stream->id;
                std::cerr << "4 decoding" << std::endl;
                int result = avcodec_decode_video2(mCodecContext, mPictureYUV, &check, &mPacket);
                std::cerr << "Bytes decoded " << result << " check " << check << std::endl;

                //memcpy(mImage->data(), src, mWidth * mHeight * (mPixelFormat == GL_RGB ? 3 : 4));

                if (cnt > 500)    //cnt < 0)
                {
                    sws_scale(mFrameConvertCtx, mPictureYUV->data, mPictureYUV->linesize, 0, mCodecContext->height, mPictureRGB->data, mPictureRGB->linesize);
                    std::stringstream file_name;
                    file_name << "test" << cnt << ".ppm";
                    mOutputFile.open(file_name.str().c_str());
                    mOutputFile << "P3 " << mCodecContext->width << " " << mCodecContext->height << " 255\n";

                    for (int y = 0; y < mCodecContext->height; ++y)
                    {
                        for (int x = 0; x < mCodecContext->width * 3; ++x)
                        {
                            mOutputFile << (int)(mPictureRGB->data[0] + y * mPictureRGB->linesize[0])[x] << " ";
                        }

                    }
                    mOutputFile.close();
                }
                cnt++;
            }
            av_free_packet(&mPacket);
            av_init_packet(&mPacket);
        }
    }
}