/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
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
* Author: Matthew W. Campbell
* Author: Erik Johnson
* Author: David Guthrie
* Author: Maxim Serebrennik
*/

#include "LogLevel.h"

namespace tcUtil
{
    namespace Logging
    {
        //////////////////////////////////////////////////////////////////////////
        LogLevel LogLevelFromString(const std::string& levelString)
        {
            if (levelString == LOG_ALWAYS_STR)
            {
                return LogLevel::LOG_ALWAYS;
            }
            else if (levelString == LOG_ERROR_STR)
            {
                return LogLevel::LOG_ERROR;
            }
            else if (levelString == LOG_WARNING_STR)
            {
                return LogLevel::LOG_WARNING;
            }
            else if (levelString == LOG_INFO_STR)
            {
                return LogLevel::LOG_INFO;
            }
            else if (levelString == LOG_DEBUG_STR)
            {
                return LogLevel::LOG_DEBUG;
            }
            else
            {
                return LogLevel::LOG_WARNING;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        const std::string& LogLevelToString(LogLevel logLevel)
        {
            switch (logLevel)
            {
            case LogLevel::LOG_ALWAYS:  return LOG_ALWAYS_STR;
            case LogLevel::LOG_ERROR:   return LOG_ERROR_STR;
            case LogLevel::LOG_WARNING: return LOG_WARNING_STR;
            case LogLevel::LOG_INFO:    return LOG_INFO_STR;
            case LogLevel::LOG_DEBUG:   return LOG_DEBUG_STR;
            default:                    return LOG_WARNING_STR;
            }
        }
    }
}
