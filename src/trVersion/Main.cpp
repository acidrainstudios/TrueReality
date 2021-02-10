/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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
* @author Maxim Serebrennik
*/

#include <iostream>

#include <trVersion/Utils.h>

#include <trUtil/Console/TextColor.h>
#include <trUtil/DefaultSettings.h>
#include <trUtil/VersionUtil.h>
#include <trUtil/PathUtils.h>
#include <trUtil/Exception.h>
#include <trUtil/Logging/Log.h>

const static trUtil::RefStr TR_CURRENT_VERSION("True Reality Engine Current version: ");
const static trUtil::RefStr TR_NEW_VERSION("\nTrue Reality Engine New Version : ");
const static trUtil::RefStr TR_VERSION("True Reality v");

//Forward declaration
void UpdateVersion(trUtil::VersionUtil &ver);
void IncremenetVersion(trUtil::VersionUtil &ver);
void SetVersion(trUtil::VersionUtil &ver, int maj, int min, std::string yymm, int build);

/**
 * Software's main function.
 */
int main(int argc, char** argv)
{


    std::string logFileName;
    std::string logLevel;
    bool updateVer = false;
    bool incVer = false;
    int majVer = -1;
    int minVer = -1;
    std::string yymmVer = "";
    int buildVer = -1;

    //Parse command line arguments
    ParseCmdLineArgs(argc, argv, logFileName, logLevel, updateVer, incVer, majVer, minVer, yymmVer, buildVer);

    //Creates the default folders in the User Data folder.
    trUtil::PathUtils::CreateUserDataPathTree();

    //Setup our Logging options
    trUtil::DefaultSettings::SetupLoggingOptions(logFileName, logLevel);

    try
    {
        trUtil::VersionUtil ver;
        if (updateVer)
        {
            UpdateVersion(ver);
        }
        else if (incVer)
        {
            IncremenetVersion(ver);
        }
        else if (majVer != -1 && minVer != -1 && yymmVer != "" && buildVer != -1)
        {
            SetVersion(ver, majVer, minVer, yymmVer, buildVer);
        }
        else if (majVer != -1 || minVer != -1 || yymmVer != "" || buildVer != -1)
        {
            trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
            std::cerr << TR_CURRENT_VERSION << ver.GetVersionString() << std::endl;
            if (majVer != -1)
            {
                ver.SetMajorVersion(majVer);
            }

            if (minVer != -1)
            {
                ver.SetMinorVersion(minVer);
            }

            if (yymmVer != "")
            {
                ver.SetYYMMVersion(yymmVer);
            }

            if (buildVer != -1)
            {
                ver.SetBuildVersion(buildVer);
            }

            ver.SaveVersionFile();

            std::cerr << TR_NEW_VERSION << ver.GetVersionString() << std::endl;
            trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
        }
        else
        {
            trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
            std::cerr << TR_VERSION << ver.GetVersionString() << std::endl;
            trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
        }

    }
    catch (const trUtil::Exception& ex)
    {
        LOG_E(EXE_NAME + " caught an unhandled exception:\n" + ex.ToString());
        ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
        return -1;
    }
    return 0;
}

/**
 * Increments the version in the version file.
 * Build version gets incremented by 1
 * YYMM gets set to the current year and month
 */
void IncremenetVersion(trUtil::VersionUtil &ver)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
    std::cerr << TR_CURRENT_VERSION << ver.GetVersionString() << std::endl;

    ver.IncrementVersion();
    ver.SaveVersionFile();

    std::cerr << TR_NEW_VERSION << ver.GetVersionString() << std::endl;
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
}

/**
 * Sets all the version numbers
 */
void SetVersion(trUtil::VersionUtil &ver, int maj, int min, std::string yymm, int build)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
    std::cerr << TR_CURRENT_VERSION << ver.GetVersionString() << std::endl;

    ver.SetVersion(maj, min, yymm, build);
    ver.SaveVersionFile();

    std::cerr << TR_NEW_VERSION << ver.GetVersionString() << std::endl;
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
}

/**
 * Updates the version from the current .hg revision and YYMM
 */
void UpdateVersion(trUtil::VersionUtil &ver)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
    std::cerr << TR_CURRENT_VERSION << ver.GetVersionString() << std::endl;
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);

    ver.UpdateVersion();
    ver.SaveVersionFile();

    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
    std::cerr << TR_NEW_VERSION << ver.GetVersionString() << std::endl;
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
}