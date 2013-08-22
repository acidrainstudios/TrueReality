/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2013
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
* Author: Maxim Serebrennik
*/


#ifndef trWindowCtr_CPP
#define trWindowCtr_CPP 1

#include <trUtil\trWindowCtr.h>
#include <trUtil\trMath.h>
#include <trUtil\trTextColor.h>
#include <trUtil\trLogo.h>
#include <trUtil\trGPUDetector.h>

#include <osgViewer/GraphicsWindow>
#include <osg/LightSource>
#include <osgViewer/View>
#include <osg/ArgumentParser>
#include <osgViewer/CompositeViewer>

#include <dtUtil/log.h>

#include <dtCore/exceptionenum.h>
#include <dtCore/Transform.h>
#include <dtCore/Light.h>

#include <iostream>


namespace trUtil
{
	trWindowCtr::trWindowCtr(void)
	:mInitialised(false)
	,mFullScreenMode(true)
	,mApp(NULL)
	,mStereoMode(osg::DisplaySettings::ANAGLYPHIC)
	,mStereoActive(false)
	,mWindowMode(trUtil::SCR_1_45xR)
	,mWindowData(NULL)
	{
		//Set or load from input file the Default Wind Traits
		GenerateDefWinProps();
	}

	///////////////////////////////////////////////////////////////////////////////
	//Init out Static Var
	trWindowCtr* trWindowCtr::mInstance = NULL;

	///////////////////////////////////////////////////////////////////////////////
	//Create an Instance of Window Ctr
	trWindowCtr* trWindowCtr::GetInstance()
	{
		if(mInstance == NULL)
		{
			mInstance = new trWindowCtr;
		}
		return mInstance;
	}
	///////////////////////////////////////////////////////////////////////////////
	//Create our app, with custom windows
	dtGame::GameApplication* trWindowCtr::CreateApp(int argc, char** argv, const std::string& configFileName, SCR_TYPE SetUpType)
	{
		if (!mInitialised)
		{
			//See if the user included any Window Setup related Args
			ParseWinArgs(argc, argv);


			//Create our App
			mApp = new dtGame::GameApplication(argc, argv, configFileName);
		}
		return mApp;
	}

	///////////////////////////////////////////////////////////////////////////////
	WindowDataContainer* trWindowCtr::GetWindowData(unsigned int WindowNumber)
	{
		if (WindowNumber <= mWindowData.size())
		{
			return &mWindowData[WindowNumber];
		}
		else
		{
			return NULL;
		}	
	}

	///////////////////////////////////////////////////////////////////////////////
	void trWindowCtr::GenerateWindows(void)
	{
		dtCore::DeltaWin::DeltaWinTraits win2Traits;

		if (mWindowMode == trUtil::SCR_1_45xR)
		{
			mCreateWindow();
		}

	}
	
	///////////////////////////////////////////////////////////////////////////////
	void trWindowCtr::mCreateWindow(void)
	{

	}

	///////////////////////////////////////////////////////////////////////////////
	void trWindowCtr::GenerateDefWinProps(void)
	{
		//Create 6 WindowTraits that can be customised at will later
		for(int i = 0; i < MAX_WINDOWS_POSSIBLE; i++)
		{
			dtCore::DeltaWin::DeltaWinTraits WinProps;

			WinProps.name = "VRSimLab";
            //WinProps.x(0)
            //WinProps.y(0)
            WinProps.width = 1152;
            WinProps.height = 864;
            //WinProps.showCursor(true)
            //WinProps.fullScreen(false)
            //WinProps.windowDecoration(true)
            WinProps.supportResize = false;
            //WinProps.inheritedWindowData(NULL)
            //WinProps.contextToShare(NULL)
            //WinProps.hostName("")
            //WinProps.displayNum(0)
            WinProps.screenNum = i;
            WinProps.realizeUponCreate = true;
            //WinProps.vsync(true)

			mDefWinProps.push_back(WinProps);
		}
		
		//Grab an instance of Display Settings
		if(mDspSettings.get() == NULL)
		{
			mDspSettings = osg::DisplaySettings::instance();
		}				
	}

	///////////////////////////////////////////////////////////////////////////////
	void trWindowCtr::ParseWinArgs(int argc, char** argv)
	{
		try
		{
			//Display the VR-Sim Starting Text
			Logo();

			trGPUDetector GPUMon;

			//Create a parser instance
			osg::ArgumentParser parser(&argc, argv);

			//Set application command line help
			parser.getApplicationUsage()->setApplicationName(parser.getApplicationName());
			parser.getApplicationUsage()->setCommandLineUsage(parser.getApplicationName()+" [options] ...");
			parser.getApplicationUsage()->addCommandLineOption("/? or -h","Display command line options");
			parser.getApplicationUsage()->addCommandLineOption("-MapName <map>", "The name of the map to load in. This must be a map that is located within the project path specified");
			parser.getApplicationUsage()->addCommandLineOption("-Context <Path>","Set a custom content context"); 
			parser.getApplicationUsage()->addCommandLineOption("-StereoType <mode>", "Activates 3D Stereo.  Modes are: (ANAGLYPHIC, QUAD_BUFFER)");
			parser.getApplicationUsage()->addCommandLineOption("-DisplayMode <mode>", "Changes the diplay modes.  Modes are: (SCR_1_45xR, SCR_1_90xR, SCR_2_45xR, SCR_3_45xR, SCR_3_90xR, SCR_3_90x90, SCR_4_90xR, SCR_4_90x90, SCR_5_90xR, SCR_5_90x90, SCR_6_90xR, SCR_6_90x90)");
			parser.getApplicationUsage()->addCommandLineOption("-FullScreen <mode>", "Start in Window Mode. Modes are: (ON, OFF)");

			//Check to see if the user needs to see the command line args
			if (parser.read("-h") || parser.read("--help") || parser.read("-?") || parser.read("--?") || parser.read("/?"))// || parser.argc() <= 1)
			{
				parser.getApplicationUsage()->write(std::cerr);
				
				std::cout << "\n\nExample: VRSim.exe -FullScreen OFF -Context D:/Development/Delta3D/bin/Content -DisplayMode SCR_2_45xR -MapName Intro" << std::endl;

				#ifdef _DEBUG
					system("pause");
				#endif

				exit(0);
			}

			//Check to see if we have a FullScreen Flag
			std::string FullScreenString;
			if (parser.read("-FullScreen", FullScreenString))
			{
				if(FullScreenString == "OFF")
				{
					mFullScreenMode = false;
				}
			}

			//Check to see if we have a Stereo Mode Flag
			std::string StereoString;
			if (parser.read("-StereoType", StereoString))
			{
				if(StereoString == "ANAGLYPHIC")
				{		
					mStereoMode = osg::DisplaySettings::ANAGLYPHIC;
					mStereoActive = true;
				}
				else if(StereoString == "QUAD_BUFFER")
				{
					mStereoMode = osg::DisplaySettings::QUAD_BUFFER; 
					mStereoActive = true;
				}
			}

			//Check for Window Mode Flag
			std::string WindowModeString;
			if (parser.read("-DisplayMode", WindowModeString))
			{
				if(WindowModeString == "SCR_1_45xR")
				{		
					mWindowMode = trUtil::SCR_1_45xR;
				}
				if(WindowModeString == "SCR_1_90xR")
				{		
					mWindowMode = trUtil::SCR_1_90xR;
				}
				else if(WindowModeString == "SCR_2_45xR")
				{
					mWindowMode = trUtil::SCR_2_45xR;
				}
				else if(WindowModeString == "SCR_3_45xR")
				{
					mWindowMode = trUtil::SCR_3_45xR;
				}
				else if(WindowModeString == "SCR_3_90xR")
				{
					mWindowMode = trUtil::SCR_3_90xR;
				}
				else if(WindowModeString == "SCR_3_90x90")
				{
					mWindowMode = trUtil::SCR_3_90x90;
				}
				else if(WindowModeString == "SCR_4_90xR")
				{
					mWindowMode = trUtil::SCR_4_90xR;
				}
				else if(WindowModeString == "SCR_4_90x90")
				{
					mWindowMode = trUtil::SCR_4_90x90;
				}
				else if(WindowModeString == "SCR_5_90xR")
				{
					mWindowMode = trUtil::SCR_5_90xR;
				}
				else if(WindowModeString == "SCR_5_90x90")
				{
					mWindowMode = trUtil::SCR_5_90x90;
				}
				else if(WindowModeString == "SCR_6_90xR")
				{
					mWindowMode = trUtil::SCR_6_90xR;
				}
				else if(WindowModeString == "SCR_6_90x90")
				{
					mWindowMode = trUtil::SCR_6_90x90;
				}
				else
				{
					mWindowMode = trUtil::SCR_1_45xR;
				}
			}
		}
		catch (const dtUtil::Exception& ex)
		{
			ex.LogException(dtUtil::Log::LOG_ERROR);
		}
	}

	
	//Destructor
	trWindowCtr::~trWindowCtr(void)
	{
		try
		{
			if (mInstance)
			{
				mInstance = NULL;			
			}
		}
		catch(const dtUtil::Exception& ex)
		{
			LOG_ERROR("VR-Sim Lab caught exception: ");
			ex.LogException(dtUtil::Log::LOG_ERROR);
		}
				
	}

}

#endif // trWindowCtr_CPP