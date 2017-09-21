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
* Author: Erik Johnson
* Author: Maxim Serebrennik
*/

#include <trUtil/Logging/LogWriterConsole.h>

#include <trUtil/Console/ConsoleTextColor.h>

#include <iostream>
#include <iomanip>

namespace trUtil
{
    namespace Logging
    {
        ////////////////////////////////////////////////////////////////////////////////
        LogWriterConsole::LogWriterConsole()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        LogWriterConsole::~LogWriterConsole()
        {
        }

        //////////////////////////////////////////////////////////////////////////
        void LogWriterConsole::LogMessage(const LogData& logData)
        {
            // Change the color of the text on the screen according to the Logging Level
            switch (logData.logLevel)
            {
            case Logging::LogLevel::LOG_DEBUG:
                Console::ConsoleTextColor(Console::TXT_COLOR::BRIGHT_MAGENTA);
                break;

            case Logging::LogLevel::LOG_INFO:
                Console::ConsoleTextColor(Console::TXT_COLOR::BRIGHT_GREEN);
                break;

            case Logging::LogLevel::LOG_ERROR:
                Console::ConsoleTextColor(Console::TXT_COLOR::BRIGHT_RED);
                break;

            case Logging::LogLevel::LOG_WARNING:
                Console::ConsoleTextColor(Console::TXT_COLOR::BRIGHT_YELLOW);
                break;

            case Logging::LogLevel::LOG_ALWAYS:
                Console::ConsoleTextColor(Console::TXT_COLOR::DEFAULT);
                break;
            }

            

            // Print out the time, the message, the log level, then where it came from
            std::cerr << "[" << logData.time.ToString(trUtil::DateTime::TimeFormat::CLOCK_TIME_24_HOUR_FORMAT);

            if (logData.frameNumber > 0)
            {
                std::cerr << " Frm# " << logData.frameNumber;
            }

            std::cerr << " " << trUtil::Logging::Log::GetLogLevelString(logData.logLevel) << "] ";

            std::cerr << logData.msg << " [";

            if (!logData.logName.empty())
            {
                std::cerr << "'" << logData.logName << "' ";
            }

            if (!logData.method.empty())
            {
                std::cerr << logData.method << "()";
            }

            if (!logData.file.empty())
            {
                std::cerr << " " << logData.file;

                if (logData.line > 0)
                {
                    std::cerr << "(" << logData.line << ")";
                }
            }

            std::cerr << "]" << std::endl;

            //Change the color back to normal
            Console::ConsoleTextColor(Console::TXT_COLOR::DEFAULT);
        }
    }    
}
