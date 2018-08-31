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

#include <trBase/SmrtPtr.h>
#include <trMPEG/CodecBase.h>
#include <trMPEG/StreamBase.h>
#include <trUtil/RefStr.h>

#include <osg/Matrix>
#include <osg/Texture2D>
#include <osg/Vec4>

//#include <boost/thread/thread.hpp>

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

namespace trMPEG
{
    /**
     * @struct  StreamContainer
     *
     * @brief   A container that holds values for a broadcast stream
     */
    struct TR_MPEG_EXPORT StreamContainer
    {
        AVStream *stream;       
        int64_t nextPts;                /// PTS of the next frame that will be generated
        AVFrame *finalFrame;
        AVFrame *tempFrame;
        struct SwsContext *swsContext;
        struct SwrContext *swrContext;
    };

	/**
	 * @class	StreamServer
	 *
	 * @brief	This class can stream a captured set of images over a network or to a file in an mpeg format
	 */
	class TR_MPEG_EXPORT StreamServer : public trMPEG::StreamBase
	{
	public:    

        /**
         * @enum    StreamType
         *
         * @brief   Used to specify the type of Stream trMPEG will create.
         */
        enum class StreamType
        {
            FILE,
            BROADCAST
        };

        /**
         * @enum    PixelFormat
         *
         * @brief   Values that represent streamer input pixel formats.
         */
        enum class PixelFormat
        {
            RGB,
            RGBA
        };
        
        const static trUtil::RefStr DEFAULT_TITLE;
        const static trUtil::RefStr DEFAULT_PUBLISHER;
        const static trUtil::RefStr DEFAULT_COPYRIGHT;
        const static trUtil::RefStr DEFAULT_FILE_NAME;
        const static trUtil::RefStr DEFAULT_UDP_ADDRS;
        const static int DEFAULT_BIT_RATE;
        const static int DEFAULT_FRAME_WIDTH;
        const static int DEFAULT_FRAME_HEIGHT;
        const static int DEFAULT_FRAME_RATE;

        /**
         * @fn  StreamServer::StreamServer();
         *
         * @brief   Default constructor.
         */
		StreamServer();

        /**
         * @fn  StreamServer::~StreamServer();
         *
         * @brief   Destructor.
         */
		~StreamServer();

        /**
         * @fn  void StreamServer::Init();
         *
         * @brief   Initializes the MPEG Stream. This should be called after all the settings and presets
         *          are set.
         */
        void Init();

        /**
         * @fn  bool StreamServer::IsInit() const;
         *
         * @brief   Query if this object is initialized.
         *
         * @return  True if init, false if not.
         */
        bool IsInit() const;

        /**
         * @fn  void StreamServer::ShutDown();
         *
         * @brief   Shuts down the MPEG Stream and frees any resources it is using.
         */
        void ShutDown();

        /**
         * @fn  void StreamServer::SetSilent(bool silent);
         *
         * @brief   Sets logging and general screen messaging off. 
         *          
         * @param   silent  True to silent.
         */
        void SetSilent(bool silent);

        /**
         * @fn  bool StreamServer::IsSilent();
         *
         * @brief   Query if this objects logging and general screen messaging is on or off. 
         *
         * @return  True if silent, false if not.
         */
        bool IsSilent();

        /**
         * @fn  void StreamServer::Encode(const GLubyte* frameData) const;
         *
         * @brief   Encodes the given texture data.
         *
         * @param   frameData   Frame Pixel Data
         */
        void Encode(const GLubyte* frameData) const;

        /**
         * @fn  void StreamServer::SetFileName(std::string fileName);
         *
         * @brief   Sets name of the output file.
         *          
         *
         * @param   fileName    Filename of the file.
         */
        void SetFileName(std::string fileName);

        /**
         * @fn  std::string StreamServer::GetFileName();
         *
         * @brief   Gets file name of the output file.
         *
         * @return  The file name.
         */
        std::string GetFileName();

        /**
         * @fn  void StreamServer::SetBroadcast(bool isBroadcast);
         *
         * @brief   Sets if the stream should be a broadcast instead of a file
         *
         * @param   isBroadcast True if this object is broadcast.
         */
        void SetBroadcast(bool isBroadcast);

        /**
         * @fn  bool StreamServer::IsBroadcast();
         *
         * @brief   Query if the stream is
         *           a broadcast instead of a file.
         *
         * @return  True if broadcast, false if not.
         */
        bool IsBroadcast();

        /**
         * @fn  void StreamServer::SetUDPAddress(std::string address);
         *
         * @brief   Sets UDP address where the stream will be broadcast. Ex: SetUDPAddress(130.46.208.38:7000);
         *
         * @param   address The address.
         */
        void SetUDPAddress(std::string address);

        /**
         * @fn  std::string StreamServer::GetUDPAddress();
         *
         * @brief   Gets UDP address where the stream will be broadcast.
         *
         * @return  The UDP address.
         */
        std::string GetUDPAddress();

        /**
         * @fn  void StreamServer::SetMpegType(trMPEG::CodecBase type);
         *
         * @brief   Sets MPEG typy by taking in a codec type class derived from CodecBase
         *          This method takes ownership of the passed in pointer and will release 
         *          the memory on the classes destruction
         *
         * @param   type    The type.
         */
        void SetMpegType(trMPEG::CodecBase *type);

        /**
         * @fn  const trMPEG::CodecBase* StreamServer::GetMpegType();
         *
         * @brief   Gets MPEG type downcast to CodecBase.
         *
         * @return  The MPEG type.
         */
        const trMPEG::CodecBase* GetMpegType();

        /**
         * @fn  void StreamServer::SetStreamType(StreamType& type);
         *
         * @brief   Sets stream output type. It can be a file, or a broadcast to a network port.
         *
         * @param [in,out]  type    The type.
         */
        void SetStreamType(StreamType& type);

        /**
         * @fn  const StreamType& StreamServer::GetStreamType() const;
         *
         * @brief   Gets stream type.
         *
         * @return  The stream type.
         */
        const StreamType& GetStreamType() const;

        /**
         * @fn  void StreamServer::SetResolution(int width, int height);
         *
         * @brief   Sets the MPEG resolution.
         *
         * @param   width   The width.
         * @param   height  The height.
         */
        void SetResolution(int width, int height);

        /**
         * @fn  void StreamServer::GetResolution(int& width, int& height);
         *
         * @brief   Gets a resolution but filling out the passed in parameters by reference.
         *
         * @param [in,out]  width   The width.
         * @param [in,out]  height  The height.
         */
        void GetResolution(int& width, int& height);

        /**
         * @fn  void StreamServer::SetWidth(int width);
         *
         * @brief   Sets the MPEG width.
         *
         * @param   width   The width.
         */
        void SetWidth(int width);

        /**
         * @fn  int StreamServer::GetWidth();
         *
         * @brief   Gets the MPEG width.
         *
         * @return  The width.
         */
        int GetWidth();

        /**
         * @fn  void StreamServer::SetHeight(int height);
         *
         * @brief   Sets the MPEG height.
         *
         * @param   height  The height.
         */
        void SetHeight(int height);

        /**
         * @fn  int StreamServer::GetHeight();
         *
         * @brief   Gets the MPEG height.
         *
         * @return  The height.
         */
        int GetHeight();

        /**
         * @fn  void StreamServer::SetFrameRate(int fps);
         *
         * @brief   Sets frame rate of the created MPEG or stream.
         *
         * @param   fps The FPS.
         */
        void SetFrameRate(int fps);

        /**
         * @fn  int StreamServer::GetFrameRate();
         *
         * @brief   Gets frame rate of the created MPEG or stream.
         *
         * @return  The frame rate.
         */
        int GetFrameRate();

        /**
         * @fn  void StreamServer::SetBitRate(int bitRate);
         *
         * @brief   Sets bit rate of the created MPEG in bits.
         *
         * @param   bitRate The bit rate.
         */
        void SetBitRate(int bitRate);

        /**
         * @fn  int StreamServer::GetBitRate();
         *
         * @brief   Gets bit rate of the created MPEG in bits.
         *
         * @return  The bit rate.
         */
        int GetBitRate();

        /**
         * @fn  void StreamServer::SetInputPixelFormat(PixelFormat format);
         *
         * @brief   Sets input pixel format.
         *
         * @param   format  Describes the format to use.
         */
        void SetInputPixelFormat(PixelFormat format);

        /**
         * @fn  PixelFormat StreamServer::GetInputPixelFormat();
         *
         * @brief   Gets input pixel format.
         *
         * @return  The input pixel format.
         */
        PixelFormat GetInputPixelFormat();

        /**
         * @fn  void StreamServer::SetFlipImageVertically(bool flip);
         *
         * @brief   Flip image vertically.
         *
         * @param   flip    True to flip.
         */
        void SetFlipImageVertically(bool flip);

        /**
         * @fn  void StreamServer::operator()() const;
         *
         * @brief   Operator that is used for the worker thread.
         */
        void operator()() const;

    protected:

        std::atomic<bool> mIsInit = false;
        bool mSilent = true;
        bool mIsBroadcast = false;
        trUtil::RefStr mPublisher;
        trUtil::RefStr mCopyright;

        int mBitRate;
        int mFrameWidth;
        int mFrameHeight;
        int mFrameRate;
        int mPixFmtSize = 3;
        PixelFormat mPixFmt = PixelFormat::RGB;
        AVRational mFrameRateRat;
        const AVRational mTimeBaseRat = { 1, 1000 };

        bool mFlipImageVertically = false;

        osg::Vec4 mRGBData;

        StreamType mStreamType;
        trUtil::RefStr mFileName;

        trBase::SmrtPtr<trMPEG::CodecBase> mCodecContainer;

        AVOutputFormat *mOutputFormatPtr = nullptr;
        AVCodecContext *mCodecContextPtr = nullptr;
        mutable AVFormatContext *mFormatContextPtr = nullptr;

        mutable AVPacket mVidPkt = { 0 };
        mutable StreamContainer mVidStream = { 0 };

        //Variables used in encoding thread
        std::thread* mEncodeThreadPtr = nullptr;
        mutable std::mutex mEncodeThreadLock;
        std::atomic<bool> mMainThreadActive = true;
        mutable std::vector<uint8_t> mTextureData;
        mutable std::atomic<bool> mNewFrameReady = false;
        mutable double mFrameTimeLength = 0.01;
        mutable int mTotalFramePTSCounter = 0;
        mutable int mFramePTSLength = 0;

        /**
         * @fn  AVFrame* StreamServer::GenerateVideoFrame(AVCodecContext *codecContext, StreamContainer *strCont) const;
         *
         * @brief   Generates a video frame converting color spectrums if needed.
         *
         * @param [in,out]  codecContext    If non-null, context for the codec.
         * @param [in,out]  strCont         If non-null, the stream container.
         *
         * @return  Null if it fails, else the video frame.
         */
        AVFrame* GenerateVideoFrame(AVCodecContext *codecContext, StreamContainer *strCont) const;

        /**
         * @fn  void StreamServer::ConfigureStream(OutputStream *outputStream, AVFormatContext *formatContext, AVCodec **codec, enum AVCodecID codecId);
         *
         * @brief   Configure the output stream.
         *
         * @param [in,out]  outputStream    If non-null, the stream container.
         * @param [in,out]  formatContext   If non-null, the oc.
         * @param [in,out]  codec           If non-null, the codec.
         * @param           codecId         Identifier for the codec.
         */
        void ConfigureStream(StreamContainer *strCont, AVFormatContext *formatContext, AVCodec **codec, enum AVCodecID codecId);

        /**
         * @fn  void StreamServer::OpenVideoCodec(AVCodecContext *codecContext, AVCodec *codec, StreamContainer *strCont, AVDictionary *optArg);
         *
         * @brief   Opens the video codec.
         *
         * @param [in,out]  codecContext    If non-null, context for the codec.
         * @param [in,out]  codec           If non-null, the codec.
         * @param [in,out]  strCont         If non-null, the stream container.
         * @param [in,out]  optArg          If non-null, the options argument.
         */
        void OpenVideoCodec(AVCodecContext *codecContext, AVCodec *codec, StreamContainer *strCont, AVDictionary *optArg);

        /**
         * @fn  void StreamServer::EncodeVideoFrame(AVCodecContext *codecContext, AVFormatContext *frmtCont, StreamContainer *strCont) const;
         *
         * @brief   Encode one video frame and send it to the muxer.
         *
         * @param [in,out]  codecContext    If non-null, context for the codec.
         * @param [in,out]  frmtCont        If non-null, context for the format.
         * @param [in,out]  strCont         If non-null, the stream container.
         */
        void EncodeVideoFrame(AVCodecContext *codecContext, AVFormatContext *frmtCont, StreamContainer *strCont) const;       
	};
}