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
* Author: Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/Logging/Log.h>

#include <string>

namespace trUtil
{
    /*
    * This is the exception class used throughout the engine.  Users should derive
    * and create concrete instances.
    */
    class TR_UTIL_EXPORT Exception
    {
    public:


        /**
        * Constructor - Initializes the exception and logs it.
        *  @param message - Message to display about the exception.
        *  @param filename - File the exception was thrown from.
        *  @param linenum - Line number in the file from which the
        *  exception was thrown.
        */
        Exception(const std::string& message, const std::string& filename, unsigned int linenum);

        /*
        * Destructor
        */
        virtual ~Exception();

        /*
        * @return the message to be displayed when this exception is thrown.
        */
        const std::string& What() const;

        /*
        * @return the filename associated with this exception.
        */
        const std::string& File() const;

        /**
        * @return the line number associated with this exception.
        */
        unsigned int Line() const;

        /**
        * Converts this exception to a string.  The string contains the reason,
        * line number and file the exception was thrown from.
        * @return The string version of this exception.
        */
        std::string ToString() const;

        /**
        * Prints the exception to the console.
        */
        void Print() const;

        /**
        * logs the exception to the default logger.
        * @param level  The level/type of logging
        */
        void LogException(trUtil::Logging::LogLevel level = trUtil::Logging::LogLevel::LOG_ERROR) const;

        /**
        * logs the exception to the following log level using the logger.
        * @param level  The level/type of logging
        * @param loggerName the name passed to "getInstance" of the Logger.
        */
        void LogException(trUtil::Logging::LogLevel level, const std::string& loggerName) const;

        /**
        * logs the exception to the following log level using the given logger.
        * @param level  The level/type of logging
        * @param logger the actual log instance used to log.
        */
        void LogException(trUtil::Logging::LogLevel level, trUtil::Logging::Log& logger) const;

    private:
        std::string mMessage, mFileName;
        unsigned int mLineNum;
    };

    TR_UTIL_EXPORT std::ostream& operator << (std::ostream& o, const Exception& ex);
}

