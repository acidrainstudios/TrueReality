/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/
#include <trUtil/DefaultSettings.h>

#include <trUtil/PathUtils.h>
#include <trUtil/Logging/Log.h>

#include <osg/ArgumentParser>


namespace trUtil
{
    namespace DefaultSettings
    {
        ////////////////////////////////////////////////////////////////////////////
        //void SetDefaultSettings(dtABC::BaseABC& app)
        //{
        //    //Turn off the use of the default scene light
        //    app.GetScene()->UseSceneLight(false);
        //    app.GetScene()->UnRegisterLight(app.GetScene()->GetLight(0));

        //    //Setting up camera options
        //    app.GetCamera()->SetNearFarCullingMode(dtCore::Camera::NO_AUTO_NEAR_FAR);

        //    //Set the window name. 
        //    app.GetWindow()->SetWindowTitle("The Construct");
        //}

        //////////////////////////////////////////////////////////////////////////
        void ParseMapNameArgument(int argc, char** argv, std::string &mapName)
        {
            osg::ArgumentParser arguments(&argc, argv);
            arguments.read("--map", mapName);
        }

        ////////////////////////////////////////////////////////////////////////////
        //void SetDefaultPaths()
        //{
        //    //Setup data and file paths. 
        //    std::string dataPath = trUtil::GetDataPathList();

        //    trUtil::SetDataFilePathList(dataPath + ";" + trUtil::GetRootPath() + ";../" + ";./" + ";./Data"); //kept arround from D3D

        //    //Setup data and file paths. 
        //    //dataPath = trUtil::PathUtils::GetDataPath();
        //    //trUtil::PathUtils::SetDataFilePathList(dataPath + ";" + trUtil::PathUtils::GetRootPath() + ";../" + ";./" + ";./Data" + trUtil::GetDataFilePathList());

        //    //Set the context path
        //    std::string context = "./Data";
        //    dtCore::Project::GetInstance().SetContext(context, true);
        //}

        //////////////////////////////////////////////////////////////////////////
        void SetupLoggingOptions(const std::string logFileName, const std::string& logLevel)
        {
            //Set the Log file name. 
            if (!logFileName.empty())
            {
                trUtil::Logging::LogFile::SetFileName(logFileName);
            }

            //Set the log level
            if (logLevel.empty())
            {
#ifdef _DEBUG
                trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_DEBUG);
#else
                trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_WARNING);
#endif
            }
            else
            {
                if (logLevel == trUtil::Logging::LOG_DEBUG_STR)
                {
                    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_DEBUG);
                }
                else if (logLevel == trUtil::Logging::LOG_INFO_STR)
                {
                    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_INFO);
                }
                else if (logLevel == trUtil::Logging::LOG_WARNING_STR)
                {
                    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_WARNING);
                }
                else if (logLevel == trUtil::Logging::LOG_ERROR_STR)
                {
                    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_ERROR);
                }
                else if (logLevel == trUtil::Logging::LOG_ALWAYS_STR)
                {
                    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_ALWAYS);
                }
                else
                {
                    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_WARNING);
                }
            }

            //Set Log file options
#ifdef _DEBUG
            trUtil::Logging::Log::GetInstance().SetAllOutputStreamBits(trUtil::Logging::Log::STANDARD);
#else
            trUtil::Logging::Log::GetInstance().SetAllOutputStreamBits(trUtil::Logging::Log::TO_FILE);

#endif
            LOG_A("\n*\n*\nLOG Level is set to: '" + trUtil::Logging::Log::GetInstance().GetLogLevelString(trUtil::Logging::Log::GetInstance().GetLogLevel()) + "'\n*\n*\n");
        }        
    }
}