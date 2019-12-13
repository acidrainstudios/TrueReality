/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
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

#include <trUtil/DefaultSettings.h>
#include <trUtil/Exception.h>
#include <trUtil/PathUtils.h>
#include <trUtil/StringUtils.h>
#include <trUtil/Console/Logo.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/Logging/Log.h>

#include <iostream>
#include <sstream>

static const std::string LOG_FILE_NAME = "LoggingExample.html";

/**
* Software's main function. 
*/
int main(int argc, char** argv)
{

    //Parse command line arguments
    ParseCmdLineArgs(argc, argv);

    //Creates the default folders in the User Data folder. 
    trUtil::PathUtils::CreateUserDataPathTree();

    
    try
    {
        //Show Logo
        trUtil::Console::Logo();

        //Sets the output type
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "Changing the output stream to File and Console (Standard) " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        /**
        * Set the OutputStreamOptions bits for all stored Loggers
        * The bits correspond to:
        * NO_OUTPUT = 0x00000000, ///<Log messages don't get written to any device
        * TO_FILE = 0x00000001,   ///<Log messages get sent to the output file
        * TO_CONSOLE = 0x00000002,///<Log messages get sent to the console
        * TO_WRITER = 0x00000004,///<Log messages get sent to all registered writers
        * STANDARD = TO_FILE | TO_CONSOLE | TO_WRITER ///<The default setting
        */
        trUtil::Logging::Log::GetInstance().SetAllOutputStreamBits(trUtil::Logging::Log::STANDARD);

        //Setting the file name of the Log File
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "Setting the file name of the Log File to " << LOG_FILE_NAME << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        trUtil::Logging::LogFile::SetFileName(LOG_FILE_NAME);

        //Change Logging Level and printing test messages
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "\nSetting Logging Level to DEBUG " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_DEBUG);
        
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "\nTesting << and + operators " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        //Testing << and + operators
        std::string tstMsg = "Log String";
        char tstChar[] = "Log Char";
        int numInt = 5;
        double dbNum = 6.69696969696969696969;
        LOG_D("Message" << " " << tstMsg << " " << tstChar << " " << numInt++ << " " << dbNum)
        LOG_I("Message" << " " + tstMsg + " " << tstChar << " " << numInt++ << " " << dbNum);
        LOG_W(tstMsg + " Message " + tstChar + " " << ++numInt << " " << dbNum)
        LOG_E("Message" << " " + tstMsg + " " + tstChar + " " << numInt++ << " " + trUtil::StringUtils::ToString<double>(dbNum, 20));
        LOG_A("Message" << " " << tstMsg << " " << tstChar << " " << ++numInt << " " << trUtil::StringUtils::ToString<double>(dbNum, 2))

        std::cerr << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "\nTesting Logging Level at DEBUG " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        LOG_D("Sending a Debug Log Message")
        LOG_I("Sending an Info Log Message")
        LOG_W("Sending a Warning Log Message")
        LOG_E("Sending an Error Log Message")
        LOG_A("Sending a Always Log Message")
        
        std::cerr << std::endl;
        LOG_PRINT_TEST

        //Change Logging Level and printing test messages
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "\nSetting Logging Level to Info " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_INFO);
        LOG_D("Sending a Debug Log Message")
        LOG_I("Sending an Info Log Message")
        LOG_W("Sending a Warning Log Message")
        LOG_E("Sending an Error Log Message")
        LOG_A("Sending a Always Log Message")

        std::cerr << std::endl;
        LOG_PRINT_TEST

        //Change Logging Level and printing test messages
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "\nSetting Logging Level to Warning " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_WARNING);
        LOG_D("Sending a Debug Log Message")
        LOG_I("Sending an Info Log Message")
        LOG_W("Sending a Warning Log Message")
        LOG_E("Sending an Error Log Message")
        LOG_A("Sending a Always Log Message")

        std::cerr << std::endl;
        LOG_PRINT_TEST

        //Change Logging Level and printing test messages
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "\nSetting Logging Level to Error " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_ERROR);
        LOG_D("Sending a Debug Log Message")
        LOG_I("Sending an Info Log Message")
        LOG_W("Sending a Warning Log Message")
        LOG_E("Sending an Error Log Message")
        LOG_A("Sending a Always Log Message")

        std::cerr << std::endl;
        LOG_PRINT_TEST

        //Change Logging Level and printing test messages
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
        std::cerr << "\nSetting Logging Level to Always " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

        trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_ALWAYS);
        LOG_D("Sending a Debug Log Message")
        LOG_I("Sending an Info Log Message")
        LOG_W("Sending a Warning Log Message")
        LOG_E("Sending an Error Log Message")
        LOG_A("Sending a Always Log Message")

        std::cerr << std::endl;
        LOG_PRINT_TEST

        //Ending program
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_RED);
        std::cerr << "\nTrue Reality is now shutting down ... " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
        LOG_A("True Reality is now shutting down ... ");
    }
    catch (const trUtil::Exception& ex)
    {
        LOG_E(EXE_NAME + " caught an unhandled exception:\n" + ex.ToString());
        ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
        return -1;
    }
    return 0;
}