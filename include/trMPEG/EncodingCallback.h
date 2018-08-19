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

#include <trMPEG/Export.h>

#include <trMPEG/PBOCopyCallback.h>
#include <trMPEG/Streamer.h>

#include <trBase/SmrtPtr.h>

#include <osg/Camera>
#include <osg/Image>
#include <osg/Texture>

#include <iostream>

namespace trMPEG
{
    class TR_MPEG_EXPORT EncodingCallback : public trMPEG::PBOCopyCallback
    {
    public:

        typedef trMPEG::PBOCopyCallback BaseClass;                 /// Adds an easy and swappable access to the base class.

        /**
         * @fn  EncodingCallback::EncodingCallback(osg::Texture* texture, GLenum pixelFormat = GL_RGBA, int pboSize = 2);
         *
         * @brief   Constructor.
         *
         * @param           height  The height.
         *
         * @param [in,out]  texture     The texture that is to be used as input.
         * @param           pixelFormat (Optional) The pixel format. GL_RGBA or GL_RGB are supported.
         * @param           pboSize     (Optional) Size of the PBO.
         */
        EncodingCallback(osg::Texture* texture, GLenum pixelFormat = GL_RGBA, int pboSize = 2);

        /**
         * @fn  EncodingCallback::~EncodingCallback();
         *
         * @brief   Destructor.
         */
        ~EncodingCallback();

        /**
         * @fn  void EncodingCallback::Init();
         *
         * @brief   Initializes the MPEG Stream. This should be called after all the settings and presets
         *          are set.
         */
        void Init();

        /**
         * @fn  bool EncodingCallback::IsInit();
         *
         * @brief   Query if this object is initialized.
         *
         * @return  True if init, false if not.
         */
        bool IsInit();

        /**
         * @fn  virtual void EncodingCallback::SetSilent(bool silent) override;
         *
         * @brief   Sets logging and general screen messaging off.
         *
         * @param   silent  True to silent.
         */
        virtual void SetSilent(bool silent) override;

        /**
         * @fn  bool EncodingCallback::IsSilent();
         *
         * @brief   Query if this objects logging and general screen messaging is on or off.
         *
         * @return  True if silent, false if not.
         */
        bool IsSilent();

        /**
         * @fn  void EncodingCallback::SetEnabled(bool enabled);
         *
         * @brief   Enables the Mpeg Encoding.
         *
         * @param   enabled True to enable, false to disable.
         */
        void SetEnabled(bool enabled);

        /**
         * @fn  bool EncodingCallback::GetEnabled();
         *
         * @brief   Returns true if Mpeg Encoding is enabled.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetEnabled();

        /**
         * @fn  void EncodingCallback::SetFileName(std::string fileName);
         *
         * @brief   Sets the name of the output file.
         *
         * @param   fileName    Filename of the file.
         */
        void SetFileName(std::string fileName);

        /**
         * @fn  std::string EncodingCallback::GetFileName();
         *
         * @brief   Gets file name of the output file.
         *
         * @return  The file name.
         */
        std::string GetFileName();

        /**
         * @fn  void EncodingCallback::SetBroadcast(bool isBroadcast);
         *
         * @brief   Sets if the stream should be a broadcast instead of a file.
         *
         * @param   isBroadcast True if this object is broadcast.
         */
        void SetBroadcast(bool isBroadcast);

        /**
         * @fn  bool EncodingCallback::IsBroadcast();
         *
         * @brief   Query if the stream is
         *           a broadcast instead of a file.
         *
         * @return  True if broadcast, false if not.
         */
        bool IsBroadcast();

        /**
         * @fn  void EncodingCallback::SetUDPAddress(std::string address);
         *
         * @brief   Sets UDP address where the stream will be broadcast. Ex:
         *          SetUDPAddress(130.46.208.38:7000);
         *
         * @param   address The address.
         */
        void SetUDPAddress(std::string address);

        /**
         * @fn  std::string EncodingCallback::GetUDPAddress();
         *
         * @brief   Gets UDP address where the stream will be broadcast.
         *
         * @return  The UDP address.
         */
        std::string GetUDPAddress();

        /**
         * @fn  void EncodingCallback::SetMpegType(trMPEG::CodecBase *type);
         *
         * @brief   Sets MPEG typy by taking in a codec type class derived from CodecBase This method
         *          takes ownership of the passed in pointer and will release the memory on the classes
         *          destruction.
         *
         * @param [in,out]  type    The type.
         */
        void SetMpegType(trMPEG::CodecBase *type);

        /**
         * @fn  const trMPEG::CodecBase* EncodingCallback::GetMpegType();
         *
         * @brief   Gets MPEG type downcast to CodecBase.
         *
         * @return  The MPEG type.
         */
        const trMPEG::CodecBase* GetMpegType();

        /**
         * @fn  void EncodingCallback::SetStreamType(Streamer::StreamType type);
         *
         * @brief   Sets stream output type. It can be a file, or a broadcast to a network port.
         *
         * @param   type    The type.
         */
        void SetStreamType(Streamer::StreamType type);

        /**
         * @fn  Streamer::StreamType EncodingCallback::GetStreamType();
         *
         * @brief   Gets stream type.
         *
         * @return  The stream type.
         */
        Streamer::StreamType GetStreamType();

        /**
         * @fn  void EncodingCallback::SetResolution(int width, int height);
         *
         * @brief   Sets the MPEG resolution.
         *
         * @param   width   The width.
         * @param   height  The height.
         */
        void SetResolution(int width, int height);

        /**
         * @fn  void EncodingCallback::GetResolution(int& width, int& height);
         *
         * @brief   Gets a resolution but filling out the passed in parameters by reference.
         *
         * @param [in,out]  width   The width.
         * @param [in,out]  height  The height.
         */
        void GetResolution(int& width, int& height);

        /**
         * @fn  void EncodingCallback::SetWidth(int width);
         *
         * @brief   Sets the MPEG width.
         *
         * @param   width   The width.
         */
        void SetWidth(int width);

        /**
         * @fn  int EncodingCallback::GetWidth();
         *
         * @brief   Gets the MPEG width.
         *
         * @return  The width.
         */
        int GetWidth();

        /**
         * @fn  void EncodingCallback::SetHeight(int height);
         *
         * @brief   Sets the MPEG height.
         *
         * @param   height  The height.
         */
        void SetHeight(int height);

        /**
         * @fn  int EncodingCallback::GetHeight();
         *
         * @brief   Gets the MPEG height.
         *
         * @return  The height.
         */
        int GetHeight();

        /**
         * @fn  void EncodingCallback::SetBitRate(int bitRate);
         *
         * @brief   Sets bit rate of the created MPEG.
         *
         * @param   bitRate The bit rate.
         */
        void SetBitRate(int bitRate);

        /**
         * @fn  int EncodingCallback::GetBitRate();
         *
         * @brief   Gets bit rate of the created MPEG in bits.
         *
         * @return  The bit rate.
         */
        int GetBitRate();

        /**
         * @fn  void EncodingCallback::SetFrameRate(int fps);
         *
         * @brief   Sets frame rate of the created MPEG.
         *
         * @param   fps The FPS.
         */
        void SetFrameRate(int fps);

        /**
         * @fn  int EncodingCallback::GetFrameRate();
         *
         * @brief   Gets frame rate of the created MPEG or stream.
         *
         * @return  The frame rate.
         */
        int GetFrameRate();

        /**
         * @fn  virtual void EncodingCallback::operator()(osg::RenderInfo& renderInfo) const override;
         *
         * @brief   Function call operator that is called by the Camera at every frame.
         *
         * @param [in,out]  renderInfo  Information describing the render.
         */
        virtual void operator ()(osg::RenderInfo& renderInfo) const override;

        /**
         * @fn  virtual void EncodingCallback::ReadPixels() const override;
         *
         * @brief   Reads the pixels.
         */
        virtual void ReadPixels() const override;

    protected:

        bool mEnabled = true;

        osg::Texture* mTexturePtr;
        trMPEG::Streamer mStream;
    };
}