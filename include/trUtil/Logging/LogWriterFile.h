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
* @author Erik Johnson
* @author Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/Logging/LogWriter.h>

#include <fstream>
#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::Logging
{
    /**
        * @class   LogWriterFile
        *
        * @brief   A specialized LogWriter class that outputs Log messages to a file.
        */
    class TR_UTIL_EXPORT LogWriterFile : public Logging::LogWriter
    {
    public:

        /**
            * @brief   The folder path that is appended to the User Data folder
            *          (PathUtil::GetUserTCDataFolder())
            */
        const static std::string DEFAULT_LOG_FOLDER;

        /**
            * @fn  LogWriterFile::LogWriterFile();
            *
            * @brief   Default constructor.
            */
        LogWriterFile();

        /**
            * @fn  void LogWriterFile::OpenFile();
            *
            * @brief   Opens the file.
            */
        void OpenFile();

        /**
            * @fn  virtual void LogWriterFile::LogMessage(const LogData& logData);
            *
            * @brief   Logs a message.
            *
            * @param   logData Information describing the log.
            */
        virtual void LogMessage(const LogData& logData);

        /**
            * @fn  void LogWriterFile::LogHorizRule();
            *
            * @brief   Logs horiz rule.
            */
        void LogHorizRule();

        /**
            * @fn  bool LogWriterFile::IsOpenFailed();
            *
            * @brief   Returns true if opening a file failed.
            *
            * @return  True if open failed, false if not.
            */
        bool IsOpenFailed();

        /**
            * @fn  void LogWriterFile::ResetOpenFail();
            *
            * @brief   A utility function to reset the OpenFailed flag after a file failure.
            */
        void ResetOpenFail();

    protected:

        /**
            * @fn  virtual LogWriterFile::~LogWriterFile();
            *
            * @brief   Destructor.
            */
        virtual ~LogWriterFile();

    private:
        std::ofstream mLogFile;
        bool mOpenFailed;
        void TimeTag(std::string prefix);
        void EndFile();
    };
}