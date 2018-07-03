/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* @author Erik Johnson
* @author Maxim Serebrennik
*/
#include <trUtil/Logging/LogWriterFile.h>

#include <trUtil/PlatformMacros.h>
#include <trUtil/Exception.h>
#include <trUtil/FileUtils.h>
#include <trUtil/PathUtils.h>

#include <iostream>

namespace trUtil
{
    namespace Logging
    {
		const std::string LogWriterFile::DEFAULT_LOG_FOLDER = std::string("/Logs");

        ////////////////////////////////////////////////////////////////////////////////
        LogWriterFile::LogWriterFile()
            : mOpenFailed(false)
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        LogWriterFile::~LogWriterFile()
        {
            if (mLogFile.is_open())
            {
                EndFile();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void LogWriterFile::EndFile()
        {
            mLogFile << "</body></html>" << std::endl;
            mLogFile.flush();
        }

        ////////////////////////////////////////////////////////////////////////////////
        void LogWriterFile::OpenFile()
        {
            if (mOpenFailed)
            {
                return;
            }

            if (mLogFile.is_open())
            {
                mLogFile << "<p>Change to log file: " << Logging::LogFile::GetFileName() << std::endl;
                TimeTag("At ");
                EndFile();
                mLogFile.close();
            }

            std::string fullLogPath = Logging::LogFile::GetFileName();
            if (Logging::LogFile::GetFileName().find(trUtil::FileUtils::PATH_SEPARATOR) == std::string::npos)
            {
                //Store logs in a system dependent place.
                std::string userLogPath = trUtil::PathUtils::GetLogPath();
                if (!userLogPath.empty())
                {
                    std::string logDir = userLogPath + DEFAULT_LOG_FOLDER;

                    try
                    {
                        trUtil::FileUtils::GetInstance().MakeDirectoryEX(logDir);
                    }
                    catch (const trUtil::Exception&)
                    {
                        std::cerr << "Unable to create the log directory : \"" << logDir << "\".  The log file will be written to the current working directory if possible." << std::endl;
                        logDir.clear();
                    }

                    fullLogPath = logDir + "/" + Logging::LogFile::GetFileName();

                }
                //First attempt to create the log file.
            }
            mLogFile.open(fullLogPath.c_str());

            if (!mLogFile.is_open())
            {
                std::cerr << "Could not open the Log file \"" << fullLogPath << "\"" << std::endl;
                mOpenFailed = true;
                return;
            }

            //Write a decent header to the html file.
            mLogFile << "<html><title>" << Logging::LogFile::GetTitle() << "</title><body>" << std::endl;
            mLogFile << "<h1 align=\"center\">" << Logging::LogFile::GetTitle() << "</h1><hr>" << std::endl;
            mLogFile << "<pre><h3 align=\"center\""
                "<font color=#000000><b>  Always     </b></font>"
                "<font color=#A000A0><b>  Debug     </b></font>"
                "<font color=#00A000><b>  Information     </b></font>"
                "<font color=#CF6F00><b>  Warning  </b></font>"
                "<font color=#C00000><b>  Error   </b></font></h3></pre><hr>"
                << std::endl;

            TimeTag("Started at ");
            mLogFile << "<br><br>" << std::endl;

            mLogFile.flush();
        }

        ////////////////////////////////////////////////////////////////////////////////
        void LogWriterFile::TimeTag(std::string prefix)
        {
            trUtil::DateTime dt;
            dt.SetToLocalTime();
            mLogFile << prefix << dt.ToString(trUtil::DateTime::TimeFormat::CLOCK_TIME_24_HOUR_FORMAT) << std::endl;
            mLogFile.flush();
        }

        //////////////////////////////////////////////////////////////////////////
        void LogWriterFile::LogMessage(const LogData& logData)
        {
            if (!mLogFile.is_open())
            {
                OpenFile();

                if (!mLogFile.is_open())
                {
                    return;
                }
            }

            std::string color;
            switch (logData.logLevel)
            {
            case Logging::LogLevel::LOG_DEBUG:
                color = "<b><font color=#A000A0>";
                break;

            case Logging::LogLevel::LOG_INFO:
                color = "<b><font color=#00A000>";
                break;

            case Logging::LogLevel::LOG_ERROR:
                color = "<b><font color=#C00000>";
                break;

            case Logging::LogLevel::LOG_WARNING:
                color = "<b><font color=#CF6F00>";
                break;

            case Logging::LogLevel::LOG_ALWAYS:
                color = "<b><font color=#000000>";
                break;
            }

            static const std::string htmlNewline("<br>\n");
            std::string htmlMsg(logData.msg);

            for (size_t lineEnd = htmlMsg.find('\n');
                lineEnd != std::string::npos;
                lineEnd = htmlMsg.find('\n', lineEnd))
            {
                htmlMsg.replace(lineEnd, 1, htmlNewline);
                lineEnd += htmlNewline.size() + 1;
            }

            mLogFile << color << "[" << logData.time.ToString(trUtil::DateTime::TimeFormat::CLOCK_TIME_24_HOUR_FORMAT);

            if (logData.frameNumber > 0)
            {
                mLogFile << " Frm&#35; " << logData.frameNumber;
            }

            mLogFile << " " << Logging::Log::GetLogLevelString(logData.logLevel) << "] ";

            mLogFile << htmlMsg << " [";

            if (!logData.logName.empty())
            {
                mLogFile << "'" << logData.logName << "' ";
            }

            if (!logData.method.empty())
            {
                mLogFile << logData.method << "()";
            }

            if (!logData.file.empty())
            {
                mLogFile << " " << logData.file;

                if (logData.line > 0)
                {
                    mLogFile << "(" << logData.line << ")";
                }
            }

            mLogFile << "]" << "</font></b><br>" << std::endl;

            mLogFile.flush(); //Make sure everything is written, in case of a crash.
        }

        ////////////////////////////////////////////////////////////////////////////////
        void LogWriterFile::LogHorizRule()
        {
            if (!mLogFile.is_open())
            {
                return;
            }

            mLogFile << "<hr>" << std::endl;
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool LogWriterFile::IsOpenFailed()
        {
            if (mOpenFailed)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        
        ////////////////////////////////////////////////////////////////////////////////
        void LogWriterFile::ResetOpenFail()
        {
            mOpenFailed = false;
        }
    }
}
