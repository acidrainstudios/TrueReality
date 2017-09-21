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
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* Author: Matthew W. Campbell
* Author: Erik Johnson
* Author: David Guthrie
* Author: Maxim Serebrennik
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

namespace trUtil
{
    namespace Logging
    {
        //////////////////////////////////////////////////////////////////////////
        class LogManager : public osg::Referenced
        {
        public:

            LogManager();

            ~LogManager();

            /**
            * Stores a new Log instance in the manager
            */
            bool AddInstance(const std::string& name, Log* log);

            /**
            * Retrieves a stored Log instance.
            *
            * @param name - name of the Log to retrieve
            */
            Log* GetInstance(const std::string& name);

            /**
            * Set the Log Level for all active Loggers
            */
            void SetAllLogLevels(const LogLevel& newLevel);

            /**
            * Set the OutputStreamOptions bits for all stored Loggers
            * The bits correspond to:
            * NO_OUTPUT = 0x00000000, ///<Log messages don't get written to any device
            * TO_FILE = 0x00000001,   ///<Log messages get sent to the output file
            * TO_CONSOLE = 0x00000002,///<Log messages get sent to the console
            * TO_WRITER = 0x00000004,///<Log messages get sent to all registered writers
            * STANDARD = TO_FILE | TO_CONSOLE | TO_WRITER ///<The default setting
            */
            void SetAllOutputStreamBits(unsigned int option);

            /**
            * Check if the Log Time Provider is currently valid in this manager.
            */
            bool IsLogTimeProviderValid() const;

            /**
            * Reopens the log file. This is used if a file failed
            * to open, or file name has changed
            */
            void ReOpenFile();

            /**
            * Writes out a horizontal line to the Log File
            */
            void LogHorizRule();

            /**
            * Write out a message to the Log file
            */
            void LogMessageToFile(const LogWriter::LogData& logData);

            /**
            * Write out a message to the screen console
            */
            void LogMessageToConsole(const LogWriter::LogData& logData);

            /**
            * This sets a Log time source.  This allows another part of the system to update and provide
            * both a time and a frame number, as needed.  Otherwise, the time will be set on the log data every
            * time log is called.
            */
            void SetLogTimeProvider(LogTimeProvider* ltp);

            /**
            * Returns the stored frame number
            */
            unsigned int GetFrameNumber();

            /**
            * Returns the reference to the stored DateTime object
            */
            const trUtil::DateTime& GetDateTime();

            /**
            * Returns the reference to an internal OpenThreads Mutex
            */
            OpenThreads::Mutex& GetMutex();

        private:
            trUtil::HashMap<std::string, osg::ref_ptr<Log> > mInstances;

            osg::ref_ptr<LogWriterFile> mLogWriterFile; ///writes to file
            osg::ref_ptr<LogWriter> mLogWriterConsole; ///writes to console
            osg::observer_ptr<osg::Referenced> mLogTimeProviderAsRef;
            LogTimeProvider* mLogTimeProvider;
            OpenThreads::Mutex mMutex;

        };
    }
}

