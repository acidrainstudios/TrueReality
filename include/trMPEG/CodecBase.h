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

#include <trBase/Base.h>
#include <trUtil/RefStr.h>

extern "C"
{
// Includes for FFMPEG
#include <libavcodec/avcodec.h>

#pragma comment(lib, "avcodec")
}

#include <string>

namespace trMPEG
{
    /**
     * @class   CodecBase
     *
     * @brief   A codec base. This should be extended and used to add new codec handling to trMPEG
     */
    class TR_MPEG_EXPORT CodecBase : public trBase::Base
    {
    public:

        /** @brief   / Adds an easy and swappable access to the base class. */
        using BaseClass = trBase::Base;

        /** @brief   / Holds the class type name for efficient comparisons. */
        const static trUtil::RefStr CLASS_TYPE;

        /**
        * @fn  CodecBase::CodecBase(const std::string& name = CLASS_TYPE);
        *
        * @brief   Default constructor.
        *
        * @param   name    (Optional) The name.
        */
        CodecBase(const std::string& name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& CodecBase::GetType() const override;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

        /**
         * @fn  virtual const std::string& CodecBase::GetFileExtension() const;
         *
         * @brief   Gets file extension.
         *
         * @return  The file extension.
         */
        virtual const std::string& GetFileExtension() const;

        /**
         * @fn  virtual const std::string& CodecBase::GetMpegType() const;
         *
         * @brief   Gets the MPEG type.
         *
         * @return  The MPEG type.
         */
        virtual const std::string& GetMpegType() const;

        /**
         * @fn  virtual const AVCodecID& CodecBase::GetEncoderType();
         *
         * @brief   Gets encoder type in the form of AV Codec ID.
         *
         * @return  Null if it fails, else the encoder type.
         */
        virtual const AVCodecID& GetEncoderType() const;

    protected:

        /** @brief   The file Extension for the given codec. */
        trUtil::RefStr mExtension;

        /** @brief   Type of the MPEG. */
        trUtil::RefStr mMpegType;

        /** @brief   Identifier for the codec. */
        AVCodecID mCodecID;

        /**
        * @fn  CodecBase::~CodecBase();
        *
        * @brief   Destructor.
        */
        ~CodecBase();
    };
}