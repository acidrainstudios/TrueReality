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


#ifndef vrsWindowCtr_H
#define vrsWindowCtr_H 1

#include "export.h"

#include <vector>

#include <osg/Referenced>

#include <dtGame/gameapplication.h>
#include <dtCore/DeltaWin.h>
#include <dtCore/Camera.h>
#include <dtCore/Scene.h>
#include <dtCore/View.h>

#include "vrsConfigParser.h"


namespace trUtil
{
	// Screen setup type
	enum VRS_UTIL_EXPORT SCR_TYPE 
	{
		SCR_1_45xR	=	0,
		SCR_1_90xR,
		SCR_2_45xR,
		SCR_3_45xR,
		SCR_3_90xR,
		SCR_3_90x90,
		SCR_4_90xR,
		SCR_4_90x90,
		SCR_5_90xR,
		SCR_5_90x90,
		SCR_6_90xR,
		SCR_6_90x90
	};

	typedef struct VRS_UTIL_EXPORT 
	{
		osg::ref_ptr<dtCore::DeltaWin> Win;
		osg::ref_ptr<dtCore::Camera> Camera;
		osg::ref_ptr<dtCore::Scene> Scene;
		osg::ref_ptr<dtCore::View> View;

		osg::ref_ptr<osg::GraphicsContext> GContext;
		osg::ref_ptr<osg::GraphicsContext::Traits> Traits;
		
		int WinScrNum;
	}WindowDataContainer;

	/**
    * Creates and Controls multi-window setups for VR-Sim Lab
	* and handles Visual Stereo Setup
    */
	class VRS_UTIL_EXPORT vrsWindowCtr: public osg::Referenced
	{
	protected:
		
		/**
		* Protected Constructor
		*/
		vrsWindowCtr(void);

	public:
	
		/**
		* Grabs a pointer to the instance of the class
		*/
		static vrsWindowCtr* GetInstance();
		

		/**
		* Initializes the Window Module, Creates an App instance and returns it with the attached windows
		*/
		dtGame::GameApplication* CreateApp(int argc, char** argv, const std::string& configFileName = "config.xml", SCR_TYPE SetUpType = SCR_1_45xR);

		/**
		* Grabs a pointer to the instance of a given Window Data Container
		*/
		WindowDataContainer* GetWindowData(unsigned int WindowNumber = 0);

		/**
		* Initialises the Window Controller, needs to be called before any other Controller function
		*/
		/*void Init(dtGame::GameApplication* app);*/

		/**
		* Sets the Visual Stereo Mode and activates it, if needed
		*/
		//void SetStereoMode(osg::DisplaySettings::StereoMode S_Mode = osg::DisplaySettings::ANAGLYPHIC, bool Active = false);

		/**
		* Creates the window setup depending on the Setup Type, 
		* destroing the original window and recreating it to its needs
		*/
		/*void CreateWin(SCR_TYPE SetUpType = SCR_1_45xR, bool FullScreen = false);*/

		/**
		* Returns the Windows, Cameras, Views, Scenes, 
		* Contexts and Traits used and created by the Window Controller
		*/  
		//this function is needed but was never tested....
		//std::vector<WindowDataContainer> GetWindowContainers(void) const {return mWindowData; }

		/**
		* Destructor
		*/
		~vrsWindowCtr(void);

	private:

		/**
		* Creates Windows according to the loaded settings
		*/
		void GenerateWindows(void);

		/**
		* Creates one Window according to the loaded settings,
		* and adds it to the window list
		*/
		void mCreateWindow(void);

		/**
		* Generates default window properties
		*/
		void GenerateDefWinProps(void);

		/**
		* Parses Command Line Args
		*/
		void ParseWinArgs(int argc, char** argv);

		/**
		* Hold the instance of this class
		*/
		static vrsWindowCtr* mInstance;

		/**
		* Total maximum number of windows possible
		*/
		const static int MAX_WINDOWS_POSSIBLE = 6;

		/**
		* Holds the default window properties
		*/
		std::vector<dtCore::DeltaWin::DeltaWinTraits> mDefWinProps;

		/**
		* Display Settings
		*/
		osg::ref_ptr<osg::DisplaySettings> mDspSettings;	

		/**
		* XML Config Settings Parser
		*/
		vrsConfigParser mVRSimConfig;

		/**
		* Hold the instance of the aplication class
		*/
		osg::ref_ptr<dtGame::GameApplication> mApp;

		/**
		* Lets us know if the module was initialised
		*/
		bool mInitialised;

		/**
		* Lets us know if we are in full screen mode
		*/
		bool mFullScreenMode;
		
		/**
		* Holds the type of Stereo mode, and if it't ON/OFF
		*/
		osg::DisplaySettings::StereoMode mStereoMode;
		bool mStereoActive;

		/**
		* Holds the Window Configuration Type VR-Sim is running with
		*/
		trUtil::SCR_TYPE mWindowMode;

		/**
		* Holds all the data for all the created Windows, Cameras, Vews, and related data....
		*/
		std::vector<WindowDataContainer> mWindowData;
	};
}

#endif // vrsWindowCtr_H