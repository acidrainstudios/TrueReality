/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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

#include "Utils.h"
#include "Application.h"

#include <trBase/SmrtPtr.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/DefaultSettings.h>
#include <trUtil/Console/Logo.h>
#include <trUtil/PathUtils.h>
#include <trUtil/Exception.h>
#include <trUtil/Logging/Log.h>

#include <iostream>

/**
* Software's main function. 
*/
int main(int argc, char** argv)
{
    std::string logFileName;
	std::string logLevel;
	
	//Parse command line arguments
	ParseCmdLineArgs(argc, argv, logFileName, logLevel);

	//Creates the default folders in the User Data folder. 
	trUtil::PathUtils::CreateUserDataPathTree();

	//Setup our Logging options
	trUtil::DefaultSettings::SetupLoggingOptions(logFileName, logLevel);
	
	try
	{
		//Show Logo
		trUtil::Console::Logo();

        //Create the App and System handlers
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
        std::cerr << "Creating The App. " << std::endl;
        trBase::SmrtPtr<Application> mApp = new Application();

        //Start the App Loop
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
        std::cerr << "Starting the Run Loop... " << std::endl;
        mApp->Run();
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
        std::cerr << "Ending the Run Loop... " << std::endl;

        //Ending program
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_RED);
		std::cerr << "True Reality is now shutting down ... " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
        LOG_A("True Reality is now shutting down ... ");

	}
    catch (const trUtil::Exception& ex)
	{
		LOG_E(EXE_NAME + " caught an unhandled exception:\n" + ex.ToString());
        ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
		return -1;
	}
	return 0;
}