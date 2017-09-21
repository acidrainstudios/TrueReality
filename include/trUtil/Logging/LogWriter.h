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
* Author: Erik Johnson
* Author: Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/DateTime.h>
#include <trUtil/Logging/Log.h>

#include <osg/Referenced>

namespace trUtil
{
    namespace Logging
    {
        /** Interface class to receive messages from the Log.  Derive and implement
        *   the LogMessage() method to support custom handling of Log messages.
        *   @see trUtil::Logging::Log::AddWriter()
        */
        class TR_UTIL_EXPORT LogWriter : public osg::Referenced
        {
        public:
            struct LogData
            {
                LogData()
                : logLevel(trUtil::Logging::LogLevel::LOG_DEBUG)
                , frameNumber()
                , line(){};

                trUtil::Logging::LogLevel logLevel; ///<Log level
                trUtil::DateTime time;    ///<Time of message
                unsigned frameNumber;
                std::string logName;      ///<The name of the Log instance (could be empty)
                std::string file;         ///<The source file of the message
                std::string method;       ///<The callng method of the message
                int line;                 ///<The line number of the source code of the message
                std::string msg;          ///<The message itself
            };

            virtual void LogMessage(const LogData& logData) = 0;

        protected:
            virtual ~LogWriter() {}

        };
    }    
}


