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
* @author Matthew W. Campbell
* @author Erik Johnson
* @author David Guthrie
* @author Maxim Serebrennik
*/

#include <trUtil/Logging/LogFile.h>

#include <trUtil/Logging/Log.h>
#include <trUtil/Logging/LogManager.h>

namespace trUtil
{
    namespace Logging
    {
        

#ifdef _DEBUG
        std::string LogFile::mTitle("True Reality SDK Log File (<font color=#A000A0>DEBUG LIBs)</font>");
#else
        std::string LogFile::mTitle("True Reality SDK Log File");
#endif

        const std::string LogFile::LOG_FILE_DEFAULT_NAME("TrueRealityLog.html");
        std::string LogFile::mLogFileName = LOG_FILE_DEFAULT_NAME;

        //////////////////////////////////////////////////////////////////////////
        void LogFile::SetFileName(const std::string& name)
        {
            bool sameName = name == mLogFileName;

            mLogFileName = name;
            if (!sameName)
            {
                //Reset open failed if the file name changes.
                Log::GetInstance().GetLogManagerRef().ReOpenFile();
            }
        }

        //////////////////////////////////////////////////////////////////////////
        const std::string LogFile::GetFileName()
        {
            return mLogFileName;
        }

        //////////////////////////////////////////////////////////////////////////
        void LogFile::SetTitle(const std::string& title)
        {
            mTitle = title;
        }

        //////////////////////////////////////////////////////////////////////////
        const std::string& LogFile::GetTitle()
        {
            return mTitle;
        }
    }
}
