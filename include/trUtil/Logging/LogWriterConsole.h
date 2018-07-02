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
* @author: Erik Johnson
* @author: Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/Logging/LogWriter.h>

namespace trUtil
{
    namespace Logging
    {
        /** Specialized LogWriter used to display Log messages in the console
        * window.
        * @see Log::AddObserver()
        */
        class TR_UTIL_EXPORT LogWriterConsole : public Logging::LogWriter
        {
        public:
            LogWriterConsole();

            virtual void LogMessage(const LogData& logData);

        protected:
            virtual ~LogWriterConsole();
        };
    }    
}


