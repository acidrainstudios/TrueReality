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

#pragma comment(lib, "avcodec")
}

#include <trMPEG/CodecBase.h>

namespace trMPEG
{
    /**
    * @class   CodecH265
    *
    * @brief   A codec definition for encoding in raw H265/HEVC format.
    */
    class TR_MPEG_EXPORT CodecH265 : public CodecBase
    {
    public:
        /** @brief   / Adds an easy and swappable access to the base class. */
        using BaseClass = CodecBase;

        /** @brief   / Holds the class type name for efficient comparisons. */
        const static trUtil::RefStr CLASS_TYPE;

        /**
         * @fn  CodecH265::CodecH265(const std::string& name = CLASS_TYPE);
         *
         * @brief   Default constructor.
         *
         * @param   name    (Optional) The name.
         */
        CodecH265(const std::string& name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& CodecH265::GetType() const override;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

    protected:

        /**
        * @fn  CodecH265::~CodecH265();
        *
        * @brief   Destructor.
        */
        ~CodecH265();
    };
}