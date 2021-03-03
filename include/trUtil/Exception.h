/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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
* @author Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/Logging/Log.h>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @class   Exception
     *
     * @brief   This is the exception class used throughout the engine.  Users should derive and
     *          create concrete instances.
     */
    class TR_UTIL_EXPORT Exception
    {
    public:

        /**
         * @fn  Exception::Exception(const std::string& message, const std::string& filename, unsigned int linenum);
         *
         * @brief   Constructor - Initializes the exception and logs it.
         *
         * @param   message     - Message to display about the exception.
         * @param   filename    - File the exception was thrown from.
         * @param   linenum     - Line number in the file from which the exception was thrown.
         */
        Exception(const std::string& message, const std::string& filename, unsigned int linenum);

        /**
         * @fn  virtual Exception::~Exception();
         *
         * @brief   Destructor.
         */
        virtual ~Exception();

        /**
         * @fn  const std::string& Exception::What() const;
         *
         * @brief   The message to be displayed when this exception is thrown.
         *
         * @return  A reference to a const std::string.
         */
        const std::string& What() const;

        /**
         * @fn  const std::string& Exception::File() const;
         *
         * @brief   The filename associated with this exception.
         *
         * @return  A reference to a const std::string.
         */
        const std::string& File() const;

        /**
         * @fn  unsigned int Exception::Line() const;
         *
         * @brief   The line number associated with this exception.
         *
         * @return  An int.
         */
        unsigned int Line() const;

        /**
         * @fn  std::string Exception::ToString() const;
         *
         * @brief   Converts this exception to a string.  The string contains the reason, line number and
         *          file the exception was thrown from.
         *
         * @return  The string version of this exception.
         */
        std::string ToString() const;

        /**
         * @fn  void Exception::Print() const;
         *
         * @brief   Prints the exception to the console.
         */
        void Print() const;

        /**
         * @fn  void Exception::LogException(trUtil::Logging::LogLevel level = trUtil::Logging::LogLevel::LOG_ERROR) const;
         *
         * @brief   Logs the exception to the default logger.
         *
         * @param   level   (Optional) The level/type of logging.
         */
        void LogException(trUtil::Logging::LogLevel level = trUtil::Logging::LogLevel::LOG_ERROR) const;

        /**
         * @fn  void Exception::LogException(trUtil::Logging::LogLevel level, const std::string& loggerName) const;
         *
         * @brief   Logs the exception to the following log level using the logger.
         *
         * @param   level       The level/type of logging.
         * @param   loggerName  the name passed to "getInstance" of the Logger.
         */
        void LogException(trUtil::Logging::LogLevel level, const std::string& loggerName) const;

        /**
         * @fn  void Exception::LogException(trUtil::Logging::LogLevel level, trUtil::Logging::Log& logger) const;
         *
         * @brief   Logs the exception to the following log level using the given logger.
         *
         * @param           level   The level/type of logging.
         * @param [in,out]  logger  the actual log instance used to log.
         */
        void LogException(trUtil::Logging::LogLevel level, trUtil::Logging::Log& logger) const;

    private:
        std::string mMessage, mFileName;
        unsigned int mLineNum;
    };

     /**
      * @fn std::ostream& operator<< (std::ostream& o, const Exception& ex);
      *
      * @brief  Stream insertion operator.
      *
      * @param [in,out] o   The std::ostream to process.
      * @param          ex  The ex.
      *
      * @return The shifted result.
      */
    TR_UTIL_EXPORT std::ostream& operator << (std::ostream& o, const Exception& ex);
}