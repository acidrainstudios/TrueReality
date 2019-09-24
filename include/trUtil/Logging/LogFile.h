/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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
* @author Matthew W. Campbell
* @author Erik Johnson
* @author David Guthrie
* @author Maxim Serebrennik
*/

#pragma once
#include <trUtil/Export.h>

#include <osg/observer_ptr>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::Logging
{
    /**
        * @class   LogFile
        *
        * @brief   A log file.
        */
    class TR_UTIL_EXPORT LogFile
    {
    public:
        /** @brief   Log file default name. */
        static const std::string LOG_FILE_DEFAULT_NAME;

        /**
            * @fn  static void LogFile::SetFileName(const std::string& name);
            *
            * @brief   Change the name of the log file (defaults to "TrueRealityLog.html")
            *
            * @param   name    The name.
            */
        static void SetFileName(const std::string& name);

        /**
            * @fn  static const std::string LogFile::GetFileName();
            *
            * @brief   Get the current filename of the log file.
            *
            * @return  The file name.
            */
        static const std::string GetFileName();

        /**
            * @fn  static void LogFile::SetTitle(const std::string& title);
            *
            * @brief   Change the title string used in HTML.
            *
            * @param   title   The title.
            */
        static void SetTitle(const std::string& title);

        /**
            * @fn  static const std::string& LogFile::GetTitle();
            *
            * @brief   Get the current HTML title string.
            *
            * @return  The title.
            */
        static const std::string& GetTitle();  
    private:
        static std::string mLogFileName;
        static std::string mTitle;
    };
}