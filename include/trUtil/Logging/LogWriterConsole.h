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
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* @author Erik Johnson
* @author Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/Logging/LogWriter.h>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
/**
 * @namespace   Logging
 *
 * @brief   .
 */
    namespace Logging
    {
        /**
         * @class   LogWriterConsole
         *
         * @brief   Specialized LogWriter used to display Log messages in the console window.
         *
         * @sa  Log::AddObserver()
         */
        class TR_UTIL_EXPORT LogWriterConsole : public Logging::LogWriter
        {
        public:

            /**
             * @fn  LogWriterConsole::LogWriterConsole();
             *
             * @brief   Default constructor.
             */
            LogWriterConsole();

            /**
             * @fn  virtual void LogWriterConsole::LogMessage(const LogData& logData);
             *
             * @brief   Logs a message.
             *
             * @param   logData Information describing the log.
             */
            virtual void LogMessage(const LogData& logData);

        protected:

            /**
             * @fn  virtual LogWriterConsole::~LogWriterConsole();
             *
             * @brief   Destructor.
             */
            virtual ~LogWriterConsole();
        };
    }    
}


