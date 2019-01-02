/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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

#include <trUtil/Export.h>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::DefaultSettings
{
    /**
        * @fn  void SetDefaultSettings(dtABC::BaseABC& app);
        *
        * @brief   Sets the default Scene, Camera, and Window Settings.
        *
        * @param [in,out]  app The application.
        */
    //void TR_UTIL_EXPORT SetDefaultSettings(dtABC::BaseABC& app);

    /**
        * @fn  void ParseMapNameArgument(int argc, char** argv, std::string &mapName);
        *
        * @brief   Finds and returns the name of the map to be loaded from the command line.
        *
        * @param           argc    The argc.
        * @param [in,out]  argv    If non-null, the argv.
        * @param [in,out]  mapName Name of the map.
        */
    void TR_UTIL_EXPORT ParseMapNameArgument(int argc, char** argv, std::string &mapName);

    /**
        * @fn  void SetDefaultPaths();
        *
        * @brief   Sets engines default paths and project context.
        */
    //void TR_UTIL_EXPORT SetDefaultPaths();

    /**
        * @fn  void SetupLoggingOptions(const std::string& logFileName, const std::string& logLevel);
        *
        * @brief   Sets up all the default logging options for the software.
        *
        * @return  A TR_UTIL_EXPORT.
        *
        * @param   logFileName Filename of the log file.
        * @param   logLevel    The log level.
        */
    void TR_UTIL_EXPORT SetupLoggingOptions(const std::string& logFileName, const std::string& logLevel);
}