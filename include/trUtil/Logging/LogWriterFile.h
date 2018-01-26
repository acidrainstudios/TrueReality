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
* Author: Erik Johnson
* Author: Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/Logging/LogWriter.h>

#include <fstream>
#include <string>

namespace trUtil
{
    namespace Logging
    {
        /**
        * A specialized LogWriter class that outputs Log messages to a file
        */
        class TR_UTIL_EXPORT LogWriterFile : public Logging::LogWriter
        {
        public:
            /**
            * The folder path that is appended to the User Data folder (PathUtil::GetUserTCDataFolder())
            */
            const static std::string DEFAULT_LOG_FOLDER;

            LogWriterFile();

            void OpenFile();

            virtual void LogMessage(const LogData& logData);

            void LogHorizRule();

            /**
            * Returns true if opening a file failed
            */
            bool IsOpenFailed();

            /**
            * A utility function to reset the OpenFailed flag after a file failure 
            */
            void ResetOpenFail();

        protected:
            virtual ~LogWriterFile();

        private:
            std::ofstream mLogFile;
            bool mOpenFailed;
            void TimeTag(std::string prefix);
            void EndFile();
        };
    }
}


