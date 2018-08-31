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

#include <Examples/MPEGServer/Utils.h>

#include <trUtil/Exception.h>
#include <trUtil/Logging/Log.h>

#include <osg/ArgumentParser>
#include <osg/Light>
#include <osgDB/FileNameUtils>

#include <iostream>
#include <cstdlib>
#include <sstream>

void ParseCmdLineArgs(int& argc, char** argv, std::string& ip, std::string& logFileName, std::string& logLevel)
{
    osg::ArgumentParser arguments(&argc, argv);

    arguments.getApplicationUsage()->setApplicationName(PROGRAM_NAME);
        
    arguments.getApplicationUsage()->addCommandLineOption("\n--help, /help, -h, /h, /?  ", "Show this help screen.");
    arguments.getApplicationUsage()->addCommandLineOption("\n--logFileName <filename>   ", "The name of the log file to use.  Defaults to TrueRealityLog.html");
    arguments.getApplicationUsage()->addCommandLineOption("\n--logLevel <level>         ", "Logging level to use. \nLevel options are: " + trUtil::Logging::LOG_DEBUG_STR + ", " +
        trUtil::Logging::LOG_INFO_STR + ", " +
        trUtil::Logging::LOG_WARNING_STR + ", " +
        trUtil::Logging::LOG_ERROR_STR + "");
    arguments.getApplicationUsage()->addCommandLineOption("\n--ip <IP:PORT>", "Sets the IP and Port for input stream");

    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " --ip 130.46.208.38:7000", "Opens an Mpeg stream through UDP on 130.46.208.38:7000 and reads the data");

    if (arguments.read("--help") == true ||
        arguments.read("/help") == true ||
        arguments.read("-h") == true ||
        arguments.read("/h") == true ||
        arguments.read("/?") == true)
    {
        arguments.getApplicationUsage()->write(std::cout);
        exit(1);
    }

    arguments.read("--logFileName", logFileName);
    arguments.read("--logLevel", logLevel);
    arguments.read("--ip", ip);
}