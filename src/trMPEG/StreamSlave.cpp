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
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamSlave::Run()
    {
        // Open the initial context variables that are needed
        SwsContext *img_convert_ctx;
        AVFormatContext* format_ctx = avformat_alloc_context();
        AVCodecContext* codec_ctx = nullptr;
        int video_stream_index;

        // Register everything
        av_register_all();
        avformat_network_init();

        //open RTSP
        if (avformat_open_input(&format_ctx, "rtsp://134.169.178.187:8554/h264.3gp", nullptr, nullptr) != 0)
        {
            exit(1);
        }

        if (avformat_find_stream_info(format_ctx, nullptr) < 0)
        {
            exit(1);
        }

        //search video stream
        for (unsigned int i = 0; i < format_ctx->nb_streams; ++i)
        {
            if (format_ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
            {
                video_stream_index = i;
            }                
        }

        AVPacket packet;
        av_init_packet(&packet);

        //open output file
        AVFormatContext* output_ctx = avformat_alloc_context();

        AVStream* stream = nullptr;
        int cnt = 0;

        //start reading packets from stream and write them to file
        av_read_play(format_ctx);    //play RTSP

        // Get the codec
        AVCodec *codec = avcodec_find_decoder(AV_CODEC_ID_H264);
        if (!codec)
        {
            exit(1);
        }

        // Add this to allocate the context by codec
        codec_ctx = avcodec_alloc_context3(codec);

        avcodec_get_context_defaults3(codec_ctx, codec);
        avcodec_copy_context(codec_ctx, format_ctx->streams[video_stream_index]->codec);
        std::ofstream output_file;

        if (avcodec_open2(codec_ctx, codec, nullptr) < 0)
        {
            exit(1);
        }

        img_convert_ctx = sws_getContext(codec_ctx->width, codec_ctx->height,
            codec_ctx->pix_fmt, codec_ctx->width, codec_ctx->height, AV_PIX_FMT_RGB24,
            SWS_BICUBIC, nullptr, nullptr, nullptr);

        int size = avpicture_get_size(AV_PIX_FMT_YUV420P, codec_ctx->width, codec_ctx->height);

        uint8_t* picture_buffer = (uint8_t*)(av_malloc(size));
        AVFrame* picture = av_frame_alloc();
        AVFrame* picture_rgb = av_frame_alloc();
        int size2 = avpicture_get_size(AV_PIX_FMT_RGB24, codec_ctx->width, codec_ctx->height);

        uint8_t* picture_buffer_2 = (uint8_t*)(av_malloc(size2));
        avpicture_fill((AVPicture *)picture, picture_buffer, AV_PIX_FMT_YUV420P, codec_ctx->width, codec_ctx->height);
        avpicture_fill((AVPicture *)picture_rgb, picture_buffer_2, AV_PIX_FMT_RGB24, codec_ctx->width, codec_ctx->height);

        while (av_read_frame(format_ctx, &packet) >= 0 && cnt < 1000)
        { //read ~ 1000 frames

            std::cout << "1 Frame: " << cnt << std::endl;
            if (packet.stream_index == video_stream_index)
            {    //packet is video

                std::cout << "2 Is Video" << std::endl;
                if (stream == nullptr)
                {
                    //create stream in file
                    std::cout << "3 create stream" << std::endl;
                    stream = avformat_new_stream(output_ctx, format_ctx->streams[video_stream_index]->codec->codec);
                    avcodec_copy_context(stream->codec, format_ctx->streams[video_stream_index]->codec);
                    stream->sample_aspect_ratio = format_ctx->streams[video_stream_index]->codec->sample_aspect_ratio;
                }

                int check = 0;
                packet.stream_index = stream->id;
                std::cout << "4 decoding" << std::endl;
                int result = avcodec_decode_video2(codec_ctx, picture, &check, &packet);
                std::cout << "Bytes decoded " << result << " check " << check << std::endl;

                if (cnt > 100)    //cnt < 0)
                {
                    sws_scale(img_convert_ctx, picture->data, picture->linesize, 0, codec_ctx->height, picture_rgb->data, picture_rgb->linesize);
                    std::stringstream file_name;
                    file_name << "test" << cnt << ".ppm";
                    output_file.open(file_name.str().c_str());
                    output_file << "P3 " << codec_ctx->width << " " << codec_ctx->height << " 255\n";

                    for (int y = 0; y < codec_ctx->height; y++)
                    {
                        for (int x = 0; x < codec_ctx->width * 3; x++)
                        {
                            output_file << (int)(picture_rgb->data[0] + y * picture_rgb->linesize[0])[x] << " ";
                        }

                    }
                    output_file.close();
                }
                cnt++;
            }
            av_free_packet(&packet);
            av_init_packet(&packet);
        }
        av_free(picture);
        av_free(picture_rgb);
        av_free(picture_buffer);
        av_free(picture_buffer_2);

        av_read_pause(format_ctx);
        avio_close(output_ctx->pb);
        avformat_free_context(output_ctx);
    }
}