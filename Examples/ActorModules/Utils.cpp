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

#include "Utils.h"

#include <trUtil/ArgumentParser.h>
#include <trUtil/Exception.h>
#include <trUtil/Logging/Log.h>

#include <iostream>
#include <cstdlib>
#include <sstream>

/*
* Parses the command line variables that are passed in to the executable
*/
void ParseCmdLineArgs(int& argc, char** argv, std::string& logFileName, std::string& logLevel)
{
    trUtil::ArgumentParser arguments(&argc, argv);

    arguments.SetApplicationName(PROGRAM_NAME);

    arguments.AddCommandLineOption("\n--logFileName <filename>   ", "The name of the log file to use.  Defaults to TrueRealityLog.html");
    arguments.AddCommandLineOption("\n--logLevel <level>         ", "Logging level to use. \nLevel options are: " + trUtil::Logging::LOG_DEBUG_STR + ", " +
        trUtil::Logging::LOG_INFO_STR + ", " +
        trUtil::Logging::LOG_WARNING_STR + ", " +
        trUtil::Logging::LOG_ERROR_STR + "");
    arguments.AddCommandLineOption("\n--help, /help, -h, /h, /?  ", "Show this help screen.");

    if (arguments.Read("--help") == true ||
        arguments.Read("/help") == true ||
        arguments.Read("-h") == true ||
        arguments.Read("/h") == true ||
        arguments.Read("/?") == true)
    {
        arguments.Write(std::cout);
        exit(0);
    }

    arguments.Read("--logFileName", logFileName);
    arguments.Read("--logLevel", logLevel);
}