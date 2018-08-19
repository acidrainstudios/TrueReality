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

#include <Examples/Logging/Utils.h>

#include <iostream>
#include <cstdlib>
#include <sstream>

#include <osg/ArgumentParser>
#include <osgDB/FileNameUtils>

#include <trUtil/Exception.h>
#include <trUtil/Logging/Log.h>

void ParseCmdLineArgs(int& argc, char** argv, std::string& mpegType, std::string& fileName, std::string& ip, std::string& logFileName, std::string& logLevel)
{
    osg::ArgumentParser arguments(&argc, argv);

    arguments.getApplicationUsage()->setApplicationName(PROGRAM_NAME);
        
    arguments.getApplicationUsage()->addCommandLineOption("\n--help, /help, -h, /h, /?  ", "Show this help screen.");
    arguments.getApplicationUsage()->addCommandLineOption("\n--logFileName <filename>   ", "The name of the log file to use.  Defaults to TrueReality_Log.html");
    arguments.getApplicationUsage()->addCommandLineOption("\n--logLevel <level>         ", "Logging level to use. \nLevel options are: " + trUtil::Logging::LOG_DEBUG_STR + ", " +
        trUtil::Logging::LOG_INFO_STR + ", " +
        trUtil::Logging::LOG_WARNING_STR + ", " +
        trUtil::Logging::LOG_ERROR_STR + "");
    arguments.getApplicationUsage()->addCommandLineOption("\n--ip <IP:PORT>", "Sets the IP and Port for broadcasting");
    arguments.getApplicationUsage()->addCommandLineOption("\n--mpegType <Mpeg Type>", "Records a file with a given mpeg format. Values are mpeg2, mpeg4, h264, h265");
    arguments.getApplicationUsage()->addCommandLineOption("\n--output <File Name/UDP>", "Sets a file name (don not put an extension). Use UDP for the name to start a broadcast");

    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " --mpegType h264", "Records OutputVid.h264");
    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " --mpegType mpeg2 --output test", "Records test.mpg");
    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " --mpegType mpeg4 --output MyTest", "Records MyTest.mp4");
    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " --mpegType h265 --output UDP --ip 130.46.208.38:7000", "Broadcasts h265 format through UDP on 130.46.208.38:7000");

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
    arguments.read("--mpegType", mpegType);
    arguments.read("--output", fileName);
    arguments.read("--ip", ip);

    //Check what kind of MPEG compression we want. 
    if ((mpegType != "mpeg4") && (mpegType != "h264") && (mpegType != "h265"))
    {
        mpegType = "mpeg2";
    }

    //Check if we have a set IP if UDP was selected
    if ((fileName == "UDP") && (ip == ""))
    {
        fileName = "";
    }
}