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

void ParseCmdLineArgs(int& argc, char** argv, std::string& arg1, std::string& arg2, std::string& arg3, std::string& logFileName, std::string& logLevel)
{
    osg::ArgumentParser arguments(&argc, argv);

    arguments.getApplicationUsage()->setApplicationName(PROGRAM_NAME);
        
    arguments.getApplicationUsage()->addCommandLineOption("\n--help, /help, -h, /h, /?  ", "Show this help screen.");
    arguments.getApplicationUsage()->addCommandLineOption("\n--logFileName <filename>   ", "The name of the log file to use.  Defaults to TrueReality_Log.html");
    arguments.getApplicationUsage()->addCommandLineOption("\n--logLevel <level>         ", "Logging level to use. \nLevel options are: " + trUtil::Logging::LOG_DEBUG_STR + ", " +
        trUtil::Logging::LOG_INFO_STR + ", " +
        trUtil::Logging::LOG_WARNING_STR + ", " +
        trUtil::Logging::LOG_ERROR_STR + "");
    arguments.getApplicationUsage()->addCommandLineOption("\n--mpeg <Mpeg Type> <UDP> <IP:PORT>", "Records a file with a given mpeg format");
    arguments.getApplicationUsage()->addCommandLineOption("\n--mpeg <Mpeg Type>", "Records a file with a given mpeg format");
    arguments.getApplicationUsage()->addCommandLineOption("\n--mpeg <Mpeg Type> <File Name>", "Records a custom named file with a given mpeg format");

    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " mpeg2 test", "Records test.mpg");
    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " mpeg4 MyTest", "Records MyTest.mp4");
    arguments.getApplicationUsage()->addCommandLineOption("Example: " + std::string(argv[0]) + " h265 UDP 130.46.208.38:7000", "Broadcasts h265 format through UDP on 130.46.208.38:7000");
    arguments.getApplicationUsage()->addCommandLineOption("<Mpeg Type>", "mpeg2, mpeg4, h264, h265");
    arguments.getApplicationUsage()->addCommandLineOption("<File Name>", "File name with no extension. Use 'UDP' as the name to enable broadcasting.");

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
    arguments.read("--mpeg", arg1);
    arguments.read("--mpeg", arg1, arg2);
    arguments.read("--mpeg", arg1, arg2, arg3);

    //Check what kind of MPEG compression we want. 
    if ((arg1 != "mpeg4") && (arg1 != "h264") && (arg1 != "h265"))
    {
        arg1 = "mpeg2";
    }

    //Check if the user wants to set a file name.
    if (argc > 2)
    {
        arg2 = argv[2];

        //Check is this should be a UDP broadcast
        if (arg2 == "UDP" && argc > 3)
        {
            arg3 = argv[3];
        }
        else if (arg2 == "UDP")
        {
            arg2 = "";
        }
    }
}