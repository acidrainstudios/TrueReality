/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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

#include <trUtil/Exception.h>

namespace trUtil
{
    /**
     * @class   ExceptionInvalidParameter
     *
     * @brief   Exception used for methods invalid parameters.
     *
     * @author  Maxim Serebrennik
     */
    class TR_UTIL_EXPORT ExceptionInvalidParameter : public trUtil::Exception
    {
    public:

        /**
         * @fn  ExceptionInvalidParameter::ExceptionInvalidParameter(const std::string& message, const std::string& filename, unsigned int linenum);
         *
         * @brief   Constructor.
         *
         * @param   message     The message.
         * @param   filename    Filename of the file.
         * @param   linenum     The linenum.
         */
        ExceptionInvalidParameter(const std::string& message, const std::string& filename, unsigned int linenum);

        /**
         * @fn  virtual ExceptionInvalidParameter::~ExceptionInvalidParameter()
         *
         * @brief   Destructor.
         */
        virtual ~ExceptionInvalidParameter() {};
    };

}