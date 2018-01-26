/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
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
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* Author: Matthew W. Campbell
* Author: Erik Johnson
* Author: David Guthrie
* Author: Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <string>

namespace trUtil
{
    namespace Logging
    {
        /**
        * String value for DEBUG Logging level
        */
        const static std::string LOG_DEBUG_STR("Debug");

        /**
        * String value for INFO Logging level
        */
        const static std::string LOG_INFO_STR("Info");
        /**
        * String value for WARNING Logging level
        */
        const static std::string LOG_WARNING_STR("Warning");

        /**
        * String value for ERROR Logging level
        */
        const static std::string LOG_ERROR_STR("Error");

        /**
        * String value for ALWAYS Logging level
        */
        const static std::string LOG_ALWAYS_STR("Always");

        /**
        * Identifies the Logging level for an individual Logger and Log message
        */
        enum TR_UTIL_EXPORT LogLevel
        {
            LOG_DEBUG,
            LOG_INFO,
            LOG_WARNING,
            LOG_ERROR,
            LOG_ALWAYS
        };

        /**
        * @return the LogLevel matching a string or WARNING if there is no match.
        * The values that are checked against are the LogLevel Strings:
        * LOG_DEBUG_STR, LOG_INFO_STR, LOG_WARNING_STR, LOG_ERROR_STR, LOG_ALWAYS_STR
        */
        TR_UTIL_EXPORT LogLevel LogLevelFromString(const std::string& levelString);

        /**
        * @return a string version of a LogLevel.
        * LOG_WARNING_STR is returned if there is no match.
        */
        const TR_UTIL_EXPORT std::string& LogLevelToString(LogLevel logLevel);
    }
}
