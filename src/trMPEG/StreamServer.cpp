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

#include <trMPEG/StreamServer.h>

#include <trUtil/Logging/Log.h>
#include <trUtil/StringUtils.h>
#include <trUtil/Timer.h>

#include <osg/Timer>
#include <osgDB/WriteFile>

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <chrono>

namespace trMPEG
{   
    const trUtil::RefStr StreamServer::DEFAULT_TITLE = trUtil::RefStr("trMPEG Broadcast");
    const trUtil::RefStr StreamServer::DEFAULT_PUBLISHER = trUtil::RefStr("trMPEG");
    const trUtil::RefStr StreamServer::DEFAULT_COPYRIGHT = trUtil::RefStr("Acid Rain Studios LLC");
    const trUtil::RefStr StreamServer::DEFAULT_FILE_NAME = trUtil::RefStr("OutputVid");
    const trUtil::RefStr StreamServer::DEFAULT_UDP_ADDRS = trUtil::RefStr("127.0.0.1:7000");
    const int StreamServer::DEFAULT_BIT_RATE = 2000;
    const int StreamServer::DEFAULT_FRAME_WIDTH = 800;
    const int StreamServer::DEFAULT_FRAME_HEIGHT = 600;
    const int StreamServer::DEFAULT_FRAME_RATE = 60;

	//////////////////////////////////////////////////////////////////////////
	StreamServer::StreamServer()
	{
        mFileName = DEFAULT_FILE_NAME;
        mUDPAddrs = DEFAULT_UDP_ADDRS;
        mBitRate = DEFAULT_BIT_RATE;
        mFrameWidth = DEFAULT_FRAME_WIDTH;
        mFrameHeight = DEFAULT_FRAME_HEIGHT;
        mFrameRate = DEFAULT_FRAME_RATE;

        // Set up the Encoder worker thread
        mEncodeThreadPtr = new std::thread(std::ref(*this));
        LOG_D("Setting up rendering thread")
	}

	//////////////////////////////////////////////////////////////////////////
	StreamServer::~StreamServer()
	{
        // Wait for threads to comeback and terminate
        if (mEncodeThreadPtr)
        {           
            if (!mSilent)
            {
                std::cerr << "Deleting Dead Encoding Thread " << std::endl;
            }

            delete mEncodeThreadPtr;
            mEncodeThreadPtr = nullptr;   
            
            if (!mSilent)
            {
                std::cerr << "Exiting Main Thread " << std::endl;
            }
            LOG_D("Main Rendering thread terminated")
        }        
	}

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::Init()
    {
        int ret; // Error checking return
        AVCodec *videoCodec = nullptr;
        AVDictionary *videoDict = nullptr;

        av_register_all();
        avformat_network_init();

        // Check to make sure a codec container was passed in
        if (!mCodecContainer.Valid())
        {
            LOG_E("No Codec container specified.")
            exit(1);
        }

        /* Allocate the output Format context */
        if (mIsBroadcast)
        {
            // Allocate context for streaming
            mFileName = "udp://" + mUDPAddrs;
            avformat_alloc_output_context2(&mFormatContextPtr, nullptr, "mpegts", mFileName.c_str());
        }
        else
        {
            // Allocate context for file writing
            mFileName = mFileName + mCodecContainer->GetFileExtension();
            avformat_alloc_output_context2(&mFormatContextPtr, nullptr, mCodecContainer->GetMpegType().c_str(), mFileName.c_str());
        }
        
        // Detect output format from file extension
        if (!mFormatContextPtr)
        {
            LOG_W("Could not deduce output format from file extension: using MPEG.")
            avformat_alloc_output_context2(&mFormatContextPtr, nullptr, "mpeg", mFileName.c_str());
        }
        if (!mFormatContextPtr)
        {
            LOG_E("Could not deduce output format.")
            exit(1);
        }

        mOutputFormatPtr = mFormatContextPtr->oformat;
        
        if (mOutputFormatPtr->video_codec != AV_CODEC_ID_NONE)
        {
            // Make sure that the codec found is the one we want, no matter what the extension is. 
            // Some extensions can be codec egnostic, like mpg, avi, etc etc
            if (mOutputFormatPtr->video_codec != mCodecContainer->GetEncoderType())
            {
                mOutputFormatPtr->video_codec = mCodecContainer->GetEncoderType();
            }
            ConfigureStream(&mVidStream, mFormatContextPtr, &videoCodec, mOutputFormatPtr->video_codec);
        }

        /* 
        * Now that all the parameters are set, we can open the audio and
        * video codecs and allocate the necessary encode buffers. 
        */
        if (mCodecContextPtr)
        {
            OpenVideoCodec(mCodecContextPtr, videoCodec, &mVidStream, videoDict);
        }
        else
        {
            LOG_E("Codec Context not set up ")
            exit(1);
        }

        /* Open the output file, if needed */
        if (!(mOutputFormatPtr->flags & AVFMT_NOFILE)) 
        {
            ret = avio_open(&mFormatContextPtr->pb, mFileName.c_str(), AVIO_FLAG_WRITE);
            if (ret < 0) 
            {
                LOG_E("Could not open " +  mFileName)
                exit(1);
            }
        }

        /* Write the stream header, if any. */
        ret = avformat_write_header(mFormatContextPtr, &videoDict);
        if (ret < 0) 
        {
            LOG_E("Error occurred while trying to write the stream header. ")
            exit(1);
        }

        if (!mSilent)
        {
            std::cerr << "Stream configuration - ";
            av_dump_format(mFormatContextPtr, 0, mFileName.c_str(), 1);
        }

        mIsInit = true;
    }

    //////////////////////////////////////////////////////////////////////////
    bool StreamServer::IsInit() const
    {
        return mIsInit;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::ShutDown()
    {
        //Signal the worker thread to shut down
        mMainThreadActive = false; 
        
        if (!mSilent)
        {
            std::cerr << "Main thread waiting for Encoder thread " << mEncodeThreadPtr->get_id() << " to join Main thread " << std::this_thread::get_id() << std::endl;
        }

        mEncodeThreadPtr->join();

        if (!mSilent)
        {
            std::cerr << "Encoding Thread " << mEncodeThreadPtr->get_id() << " Joined Main thread " << std::this_thread::get_id() << std::endl;
        }

        //Write the file trailer if needed
        av_write_trailer(mFormatContextPtr);

        avcodec_flush_buffers(mCodecContextPtr);

        // Close the stream
        avcodec_free_context(&mCodecContextPtr);
        av_frame_free(&mVidStream.finalFrame);
        av_frame_free(&mVidStream.tempFrame);
        sws_freeContext(mVidStream.swsContext);
        swr_free(&mVidStream.swrContext);

        /* Close the output file. */
        if (!(mOutputFormatPtr->flags & AVFMT_NOFILE))
        {
            avio_closep(&mFormatContextPtr->pb);
        }          
        
        /* free the stream */
        avformat_free_context(mFormatContextPtr);   

        LOG_D("Shutting down the MPEG Stream")
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetSilent(bool silent)
    {
        mSilent = silent;
        if (mSilent)
        {
            av_log_set_level(AV_LOG_QUIET);
        }
        else
        {
            av_log_set_level(AV_LOG_INFO);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool StreamServer::IsSilent()
    {
        return mSilent;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::ConfigureStream(StreamContainer *strCont, AVFormatContext *formatContext, AVCodec **codec, enum AVCodecID codecId)
    {
        /* Find the Encoder Codec */
        *codec = FindEncoderCodecByID(codecId);

        strCont->stream = avformat_new_stream(formatContext, nullptr);
        if (!strCont->stream)
        {
            LOG_E("Could not allocate stream")
            exit(1);
        }
        strCont->stream->id = formatContext->nb_streams - 1;
        mCodecContextPtr = avcodec_alloc_context3(*codec);
        if (!mCodecContextPtr)
        {
            LOG_E("Could not allocate an encoding context")
            exit(1);
        }

        mCodecContextPtr->codec_id = codecId;
        mCodecContextPtr->bit_rate = mBitRate;

        /* Resolution must be a multiple of two. */
        mCodecContextPtr->width = mFrameWidth;
        mCodecContextPtr->height = mFrameHeight;
        
        /* Threading options */
        mCodecContextPtr->thread_count = 1;
        mCodecContextPtr->thread_type = FF_THREAD_SLICE;
        mCodecContextPtr->slices = 16;

        /* 
        * This is the fundamental unit of time (in seconds) in terms
        * of which frame timestamps are represented. For fixed-fps content,
        * timebase should be 1/framerate and timestamp increments should be
        * identical to 1. 
        */
        mFrameRateRat.num = 1;
        mFrameRateRat.den = mFrameRate;
        strCont->stream->time_base = mFrameRateRat;
        strCont->stream->codec->time_base = strCont->stream->time_base;

        mCodecContextPtr->time_base = strCont->stream->time_base;
        mCodecContextPtr->gop_size = 3;               // Emit one intra frame every three frames at most
        mCodecContextPtr->keyint_min = 1;
        mCodecContextPtr->pix_fmt = AV_PIX_FMT_YUV420P;

        //Set Buffering options
        AVCPBProperties *props;
        props = (AVCPBProperties*)av_stream_new_side_data(strCont->stream, AV_PKT_DATA_CPB_PROPERTIES, sizeof(*props));
        props->buffer_size = mBitRate;
        props->max_bitrate = 0;
        props->min_bitrate = 0;
        props->avg_bitrate = 0;
        props->vbv_delay = 120000;// UINT64_MAX;

        if (mCodecContextPtr->codec_id == AV_CODEC_ID_H264 || mCodecContextPtr->codec_id == AV_CODEC_ID_HEVC)
        {
            av_opt_set(mCodecContextPtr->priv_data, "crf", "18", AV_OPT_SEARCH_CHILDREN);
            av_opt_set(mCodecContextPtr->priv_data, "preset", "fast", AV_OPT_SEARCH_CHILDREN);
            av_opt_set(mCodecContextPtr->priv_data, "tune", "zerolatency", AV_OPT_SEARCH_CHILDREN);
            av_opt_set(mCodecContextPtr->priv_data, "gpu", "any", AV_OPT_SEARCH_CHILDREN);
            av_opt_set(mCodecContextPtr->priv_data, "vsync", "vfr", AV_OPT_SEARCH_CHILDREN);
        }
        else if (mCodecContextPtr->codec_id == AV_CODEC_ID_MPEG2VIDEO)
        {
            /* just for testing, we also add B-frames */
            mCodecContextPtr->max_b_frames = 2;
        }        
        else if (mCodecContextPtr->codec_id == AV_CODEC_ID_MPEG1VIDEO)
        {
            /* Needed to avoid using macroblocks in which some coeffs overflow.
            * This does not happen with normal video, it just happens here as
            * the motion of the chroma plane does not match the luma plane. */
            mCodecContextPtr->mb_decision = FF_MB_DECISION_RD;
        }

        /* Some formats want stream headers to be separate. */
        if (formatContext->oformat->flags & AVFMT_GLOBALHEADER)
        {
            mCodecContextPtr->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
        }  

        // Set stream metadata
        av_dict_set(&strCont->stream->metadata, "publisher", DEFAULT_PUBLISHER, 0);
        av_dict_set(&formatContext->metadata, "publisher", DEFAULT_PUBLISHER, 0);
        av_dict_set(&strCont->stream->metadata, "copyright", DEFAULT_COPYRIGHT, 0);
        av_dict_set(&formatContext->metadata, "copyright", DEFAULT_COPYRIGHT, 0);
        av_dict_set(&strCont->stream->metadata, "service_name", DEFAULT_PUBLISHER, 0);
        av_dict_set(&formatContext->metadata, "service_name", DEFAULT_PUBLISHER, 0);
        av_dict_set(&strCont->stream->metadata, "service_provider", DEFAULT_COPYRIGHT, 0);
        av_dict_set(&formatContext->metadata, "service_provider", DEFAULT_COPYRIGHT, 0);
        av_dict_set(&strCont->stream->metadata, "title", DEFAULT_TITLE, 0);
        av_dict_set(&formatContext->metadata, "title", DEFAULT_TITLE, 0);  
        
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::OpenVideoCodec(AVCodecContext *codecContext, AVCodec *codec, StreamContainer *strCont, AVDictionary *optArg)
    {
        int ret;
        AVDictionary *opt = nullptr;

        av_dict_copy(&opt, optArg, 0);

        /* Open the codec */
        ret = avcodec_open2(codecContext, codec, &opt);
        av_dict_free(&opt);

        if (ret < 0) 
        {
            LOG_E("Could not open video codec.")
            exit(1);
        }

        /* Allocate and init a re-usable frame */
        strCont->finalFrame = AllocateFrame(codecContext->pix_fmt, codecContext->width, codecContext->height);
        if (!strCont->finalFrame)
        {
            LOG_E("Could not allocate video frame.")
            exit(1);
        }

        /* 
        * If the output format is not YUV420P, then a temporary YUV420P
        * picture is needed too. It is then converted to the required
        * output format. 
        */
        strCont->tempFrame = nullptr;
        if (codecContext->pix_fmt != AV_PIX_FMT_YUV420P)
        {
            strCont->tempFrame = AllocateFrame(AV_PIX_FMT_YUV420P, codecContext->width, codecContext->height);
            if (!strCont->tempFrame)
            {
                LOG_E("Could not allocate temporary video frame.")
                exit(1);
            }
        }

        /* Copy the stream parameters to the muxer */
        ret = avcodec_parameters_from_context(strCont->stream->codecpar, codecContext);
        if (ret < 0) 
        {
            LOG_E("Could not copy the stream parameters.")
            exit(1);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    AVFrame* StreamServer::GenerateVideoFrame(AVCodecContext *codecContext, StreamContainer *strCont) const
    {           
        if (codecContext->pix_fmt != AV_PIX_FMT_YUV420P)
        {
            if (!strCont->swsContext)
            {
                strCont->swsContext = sws_getContext(codecContext->width, codecContext->height,
                    AV_PIX_FMT_YUV420P,
                    codecContext->width, codecContext->height, codecContext->pix_fmt,
                    SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);

                if (!strCont->swsContext)
                {
                    LOG_E("Could not initialize the conversion context")
                    exit(1);
                }
            }

            strCont->tempFrame = strCont->finalFrame;
            sws_scale(strCont->swsContext, (const uint8_t * const *)strCont->tempFrame->data, strCont->tempFrame->linesize, 0, codecContext->height, strCont->finalFrame->data, strCont->finalFrame->linesize);
        }                     

        //Set the current Presentation Time Stamp(PTS) and calculate one for the next frame
        strCont->finalFrame->pts = strCont->nextPts;
        mFramePTSLength = av_rescale_q(mFrameTimeLength, mTimeBaseRat, mFrameRateRat);

        //Make sure the Frame PTS is never 0
        if (mFramePTSLength == 0)
        {
            mFramePTSLength = 1;
        }

        //Check to make sure we don't have a PTS overflow and all frames add up to 1 second sharp
        if ((mTotalFramePTSCounter + mFramePTSLength) > mFrameRateRat.den)
        {
            //Increase the current PTS to the end of the second
            strCont->finalFrame->pts += (mFrameRateRat.den - mTotalFramePTSCounter);
            strCont->nextPts = strCont->finalFrame->pts;

            //Calculate the overflow length and set it as the PTS of the next frame
            mFramePTSLength = (mTotalFramePTSCounter + mFramePTSLength) - mFrameRateRat.den;           
            
            //Reset the counter
            mTotalFramePTSCounter = 0;
        }
        else if ((mTotalFramePTSCounter + mFramePTSLength) == mFrameRateRat.den)
        {
            //Reset the counter
            mTotalFramePTSCounter = 0;
        }
        else
        {
            //Increase the PTS counter
            mTotalFramePTSCounter += mFramePTSLength;
        }

        //Update the next frames PTS
        strCont->nextPts += mFramePTSLength;

        return strCont->finalFrame;
    }
    
    //////////////////////////////////////////////////////////////////////////
    void StreamServer::EncodeVideoFrame(AVCodecContext *codecContext, AVFormatContext *frmtCont, StreamContainer *strCont) const
    {
        int gotPacket = 0;

        AVFrame* framePtr = GenerateVideoFrame(codecContext, strCont);

        if (framePtr)
        {
            av_init_packet(&mVidPkt);

            /* Encode the image */
            int ret = avcodec_encode_video2(codecContext, &mVidPkt, framePtr, &gotPacket);
            if (ret < 0)
            {
                LOG_E("Error encoding video frame.")
                exit(1);
            }

            if (gotPacket)
            {
                /* Rescale output packet timestamp values from codec to stream timebase */
                av_packet_rescale_ts(&mVidPkt, codecContext->time_base, strCont->stream->time_base);
                mVidPkt.stream_index = strCont->stream->index;

                /* Write the compressed frame to the media file. */
                ret = av_interleaved_write_frame(frmtCont, &mVidPkt);

                av_packet_unref(&mVidPkt);
            }
            else
            {
                ret = 0;
            }
            if (ret < 0)
            {
                LOG_E("Error while writing video frame.")
                exit(1);
            }
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetFlipImageVertically(bool flip)
    {
        if (!mIsInit)
        {
            mFlipImageVertically = flip;
        }
    }

    //////////////////////////////////////////////////////////////////////////   
    void StreamServer::operator()() const
    {
        while (!mIsInit)
        {
            // Wait until the StreamServer is initialized 
            std::this_thread::yield();
        }

        //Get a lock to allocate resources
        mEncodeThreadLock.lock();

        const unsigned char* rgbDataPtr = nullptr;
        SwsContext* rgbToYuvCtx = nullptr;
        AVFrame *rgbFrame;
        trUtil::Timer frameTimer;
        trUtil::TimeTicks oldTicks = 0;
        trUtil::TimeTicks newTicks = 0;

        // Set the input frame pixel format and conversion context
        if (mPixFmt == PixelFormat::RGB)
        {
            rgbToYuvCtx = sws_getContext(mFrameWidth, mFrameHeight, AV_PIX_FMT_RGB24, 
                mFrameWidth, mFrameHeight, AV_PIX_FMT_YUV420P, SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);

            rgbFrame = AllocateFrame(AV_PIX_FMT_RGB24, mFrameWidth, mFrameHeight);
        }
        else if (mPixFmt == PixelFormat::RGBA)
        {
            rgbToYuvCtx = sws_getContext(mFrameWidth, mFrameHeight, AV_PIX_FMT_RGBA, 
                mFrameWidth, mFrameHeight, AV_PIX_FMT_YUV420P, SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);

            rgbFrame = AllocateFrame(AV_PIX_FMT_RGBA, mFrameWidth, mFrameHeight);
        }
        else
        {
            LOG_E("Invalid pixel format detected")
        }

        mEncodeThreadLock.unlock();

        while (mMainThreadActive)
        {
            if (mNewFrameReady && mTextureData.size() > 0)
            {
                //Lock the encoding thread mutex for this scope
                std::lock_guard<std::mutex> lock(mEncodeThreadLock);

                //Update the time it took to encode one frame
                if (oldTicks == 0)
                {
                    oldTicks = frameTimer.Tick();
                    newTicks = frameTimer.Tick();
                }
                else
                {
                    oldTicks = newTicks;
                }                

                //Check if our frame time is shorter than our frame rate, and even it out
                while (frameTimer.DeltaMil(oldTicks, newTicks) < (1000.0 / mFrameRate))
                {
                    newTicks = frameTimer.Tick();
                }

                //Saves off the time it takes to encode a frame for FPS calculations later
                mFrameTimeLength = frameTimer.DeltaMil(oldTicks, newTicks);

                fflush(stdout);

                /* Copy the image from rgb data into an RGB(A) Frame */
                for (int y = 0; y < mFrameHeight; ++y)
                {
                    for (int x = 0; x < rgbFrame->linesize[0]; ++x)
                    {

                        //Get the RGBA/RGB Data
                        rgbDataPtr = &mTextureData[y * rgbFrame->linesize[0] + x];
                        

                        //Set the R component
                        rgbFrame->data[0][y * rgbFrame->linesize[0] + x] = rgbDataPtr[0];
                        
                        //Set the G component
                        ++x;
                        rgbFrame->data[0][y * rgbFrame->linesize[0] + x] = rgbDataPtr[1];
                        
                        //Set the B component
                        ++x;
                        rgbFrame->data[0][y * rgbFrame->linesize[0] + x] = rgbDataPtr[2];
                        
                        if (mPixFmt == PixelFormat::RGBA)
                        {
                            //Set the A component
                            ++x;
                            rgbFrame->data[0][y * rgbFrame->linesize[0] + x] = 255;
                        }                        
                    }
                }                             

                //Change the image from RGBA/RGB to YUV
                sws_scale(rgbToYuvCtx, rgbFrame->data, rgbFrame->linesize, 0, rgbFrame->height, mVidStream.finalFrame->data, mVidStream.finalFrame->linesize);

                //Flip the image vertically 
                if (mFlipImageVertically)
                {
                    FlipYUV420Frame(mVidStream.finalFrame);
                }                 

                EncodeVideoFrame(mCodecContextPtr, mFormatContextPtr, &mVidStream);   

                //Mark that we just consumed a frame and can use a new one on the next loop
                mNewFrameReady = false;
            } 
            else
            {
                //Make sure this thread is not hugging the CPU core.
                std::this_thread::yield();
            }
        }        

        if (!mSilent)
        {
            std::cerr << "Encoding Thread " << std::this_thread::get_id() << " done!!!" << std::endl;
        }
        
    }    

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::Encode(const GLubyte* frameData) const
    {
        //If the encoding frame is not done or we have no data, skip this loop
        if (!mNewFrameReady && frameData)
        {
            // Copy Frame Data into a variable that will be used by the encoding thread. 
            mTextureData.assign(frameData, frameData + mFrameWidth * mFrameHeight * mPixFmtSize);
                                 
            // Send signal to the Encoder thread that New Frame Data is ready
            mNewFrameReady = true;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetFileName(std::string fileName)
    {
        if (fileName != "")
        {
            mFileName = fileName;
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    std::string StreamServer::GetFileName()
    {
        return mFileName;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetBroadcast(bool isBroadcast)
    {
        if (!mIsInit)
        {
            mIsBroadcast = isBroadcast;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool StreamServer::IsBroadcast()
    {
        return mIsBroadcast;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetUDPAddress(std::string address)
    {
        if (!mIsInit)
        {
            mUDPAddrs = address;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetMpegType(trMPEG::CodecBase *type)
    {
        if (!mIsInit)
        {
            mCodecContainer = type;
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    const trMPEG::CodecBase* StreamServer::GetMpegType()
    {
        return mCodecContainer.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetStreamType(StreamType& type)
    {
        if (!mIsInit)
        {
            mStreamType = type;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    const StreamServer::StreamType& StreamServer::GetStreamType() const
    {
        return mStreamType;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetResolution(int width, int height)
    {
        if (!mIsInit)
        {
            mFrameWidth = width;
            mFrameHeight = height;
        }
        
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::GetResolution(int& width, int& height)
    {
        width = mFrameWidth;
        height = mFrameHeight;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetWidth(int width)
    {
        if (!mIsInit)
        {
            mFrameWidth = width;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    int StreamServer::GetWidth()
    {
        return mFrameWidth;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetHeight(int height)
    {
        if (!mIsInit)
        {
            mFrameHeight = height;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    int StreamServer::GetHeight()
    {
        return mFrameHeight;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetFrameRate(int fps)
    {
        if (!mIsInit)
        {
            //Make sure that the film is at least 2 FPS
            if (fps < 2)
            {
                fps = 2;
            }
            mFrameRate = fps;
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    int StreamServer::GetFrameRate()
    {
        return mFrameRate;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetBitRate(int bitRate)
    {
        if (!mIsInit)
        {
            mBitRate = bitRate;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    int StreamServer::GetBitRate()
    {
        return mBitRate;
    }

    //////////////////////////////////////////////////////////////////////////
    void StreamServer::SetInputPixelFormat(PixelFormat format)
    {
        if (!mIsInit)
        {
            mPixFmt = format;

            if (mPixFmt == PixelFormat::RGB)
            {                
                mPixFmtSize = 3;
            }
            else if (mPixFmt == PixelFormat::RGBA)
            {
                mPixFmtSize = 4;
            }
            else
            {
                LOG_E("Unsupported pixel format was detected")
                mPixFmtSize = 0;
            }  
        }
    }

    //////////////////////////////////////////////////////////////////////////
    StreamServer::PixelFormat StreamServer::GetInputPixelFormat()
    {
        return mPixFmt;
    }
}