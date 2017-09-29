/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <string>

namespace trUtil
{
    namespace DefaultSettings
    {
        /**
        * Sets the default Scene, Camera, and Window Settings.
        */
        //void TR_UTIL_EXPORT SetDefaultSettings(dtABC::BaseABC& app);

        /**
        * Finds and returns the name of the map to be loaded from the command line. 
        */
        void TR_UTIL_EXPORT ParseMapNameArgument(int argc, char** argv, std::string &mapName);

        /**
        * Sets engines default paths and project context.
        */
        //void TR_UTIL_EXPORT SetDefaultPaths();

        /**
        * Sets up all the default logging options for the software.
        */
        void TR_UTIL_EXPORT SetupLoggingOptions(const std::string logFileName, const std::string& logLevel);
    }
}