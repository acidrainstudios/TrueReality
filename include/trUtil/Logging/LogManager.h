/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
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
* @author Matthew W. Campbell
* @author Erik Johnson
* @author David Guthrie
* @author Maxim Serebrennik
*/
#pragma once
#include <trUtil/Export.h>

#include <trUtil/HashMap.h>
#include <trUtil/Logging/Log.h>
#include <trUtil/Logging/LogWriter.h>
#include <trUtil/Logging/LogWriterFile.h>
#include <trUtil/Logging/LogTimeProvider.h>

#include <osg/Referenced>
#include <osg/ref_ptr>
#include <osg/observer_ptr>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::Logging
{
    /**
        * @class   LogManager
        *
        * @brief   Manager for logs.
        */
    class LogManager : public osg::Referenced
    {
    public:

        /**
            * @fn  LogManager::LogManager();
            *
            * @brief   Default constructor.
            */
        LogManager();

        /**
            * @fn  LogManager::~LogManager();
            *
            * @brief   Destructor.
            */
        ~LogManager();

        /**
            * @fn  bool LogManager::AddInstance(const std::string& name, Log* log);
            *
            * @brief   Stores a new Log instance in the manager.
            *
            * @param           name    The name.
            * @param [in,out]  log     If non-null, the log.
            *
            * @return  True if it succeeds, false if it fails.
            */
        bool AddInstance(const std::string& name, Log* log);

        /**
            * @fn  Log* LogManager::GetInstance(const std::string& name);
            *
            * @brief   Retrieves a stored Log instance.
            *
            * @param   name    - name of the Log to retrieve.
            *
            * @return  Null if it fails, else the instance.
            */
        Log* GetInstance(const std::string& name);

        /**
            * @fn  void LogManager::SetAllLogLevels(const LogLevel& newLevel);
            *
            * @brief   Set the Log Level for all active Loggers.
            *
            * @param   newLevel    The new level.
            */
        void SetAllLogLevels(const LogLevel& newLevel);

        /**
            * @fn  void LogManager::SetAllOutputStreamBits(unsigned int option);
            *
            * @brief   Set the OutputStreamOptions bits for all stored Loggers The bits correspond to:
            *          NO_OUTPUT = 0x00000000, /// Log messages don't get written to any device 
            *          TO_FILE = 0x00000001,   /// Log messages get sent to the output file 
            *          TO_CONSOLE = 0x00000002,/// Log messages get sent to the console 
            *          TO_WRITER = 0x00000004,/// Log messages get sent to all registered writers 
            *          STANDARD = TO_FILE | TO_CONSOLE | TO_WRITER /// The default setting.
            *
            * @param   option  The option.
            */
        void SetAllOutputStreamBits(unsigned int option);

        /**
            * @fn  bool LogManager::IsLogTimeProviderValid() const;
            *
            * @brief   Check if the Log Time Provider is currently valid in this manager.
            *
            * @return  True if the log time provider is valid, false if not.
            */
        bool IsLogTimeProviderValid() const;

        /**
            * @fn  void LogManager::ReOpenFile();
            *
            * @brief   Reopens the log file. This is used if a file failed to open, or file name has changed.
            */
        void ReOpenFile();

        /**
            * @fn  void LogManager::LogHorizRule();
            *
            * @brief   Writes out a horizontal line to the Log File.
            */
        void LogHorizRule();

        /**
            * @fn  void LogManager::LogMessageToFile(const LogWriter::LogData& logData);
            *
            * @brief   Write out a message to the Log file.
            *
            * @param   logData Information describing the log.
            */
        void LogMessageToFile(const LogWriter::LogData& logData);

        /**
            * @fn  void LogManager::LogMessageToConsole(const LogWriter::LogData& logData);
            *
            * @brief   Write out a message to the screen console.
            *
            * @param   logData Information describing the log.
            */
        void LogMessageToConsole(const LogWriter::LogData& logData);

        /**
            * @fn  void LogManager::SetLogTimeProvider(LogTimeProvider* ltp);
            *
            * @brief   This sets a Log time source.  This allows another part of the system to update and
            *          provide both a time and a frame number, as needed.  Otherwise, the time will be set
            *          on the log data every time log is called.
            *
            * @param [in,out]  ltp If non-null, the ltp.
            */
        void SetLogTimeProvider(LogTimeProvider* ltp);

        /**
            * @fn  unsigned int LogManager::GetFrameNumber();
            *
            * @brief   Returns the stored frame number.
            *
            * @return  The frame number.
            */
        unsigned int GetFrameNumber();

        /**
            * @fn  const trUtil::DateTime& LogManager::GetDateTime();
            *
            * @brief   Returns the reference to the stored DateTime object.
            *
            * @return  The date time.
            */
        const trUtil::DateTime& GetDateTime();

        /**
            * @fn  OpenThreads::Mutex& LogManager::GetMutex();
            *
            * @brief   Returns the reference to an internal OpenThreads Mutex.
            *
            * @return  The mutex.
            */
        OpenThreads::Mutex& GetMutex();

    private:
        trUtil::HashMap<std::string, osg::ref_ptr<Log> > mInstances;

        osg::ref_ptr<LogWriter> mLogWriterConsole; ///writes to console
        osg::ref_ptr<LogWriterFile> mLogWriterFile; ///writes to file
        osg::observer_ptr<osg::Referenced> mLogTimeProviderAsRef;
        LogTimeProvider* mLogTimeProvider;
        OpenThreads::Mutex mMutex;
    };
}