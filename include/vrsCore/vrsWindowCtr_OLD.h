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

//Old Controller
#ifndef vrsWindow_H
#define vrsWindow_H

#include <trUtil\vrsMath.h>

#include <dtCore/deltawin.h>
#include <dtCore/camera.h>
#include <dtCore/view.h>
#include <dtCore/scene.h>
#include <dtCore/Light.h>
#include <dtCore/Transform.h>
//#include <dtABC/dtabc.h>
//#include <dtCore/dt.h>

#include <osg/LightSource>

#include <osgDB/FileUtils>
#include <osg/Depth>
#include <osg/BlendFunc>
#include <osgViewer/CompositeViewer>
#include <osgViewer/GraphicsWindow>

//#include <prefix/dtcoreprefix-src.h>
#include <dtUtil/log.h>
#include <dtCore/exceptionenum.h>

#include <dtUtil/exception.h>


#include <cassert>
#include <math.h>
#include <iostream>
#include <string>

//#include "TheCore.h"
//#include "tcUtil.h"



//#define		MAX_WINDOWS_POSSIBLE 	6;

enum SCR_TYPE {
		SCR_1_45xR	=	0,
		SCR_1_90xR	=	1,
		SCR_2_45xR	=	2,
		SCR_3_45xR	=	3,
		SCR_3_90xR	=	4,
		SCR_3_90x90	=	5,
		SCR_4_90xR	=	6,
		SCR_4_90x90	=	7,
		SCR_5_90xR	=	8,
		SCR_5_90x90	=	9,
		SCR_6_90xR	=	10,
		SCR_6_90x90	=	11
	};

class vrsWindowCtr
{
public:
	// Screen setup type
	
/*
	enum STEREO_MODE {
		OFF						=	0,
		ANAGLYPHIC				=	1,
		QUAD_BUFFER				=	2,
		VERTICAL_SPLIT			=	3,
		HORIZONTAL_SPLIT		=	4,
		LEFT_EYE				=	5,
		RIGHT_EYE				=	6,
		HORIZONTAL_INTERLACE	=	7,
		VERTICAL_INTERLACE		=	8,
		CHECKERBOARD			=	9
	};*/


	vrsWindowCtr(void);

	
	//Set Stereo Mode
	void SetStereo(osg::DisplaySettings::StereoMode S_Mode = osg::DisplaySettings::ANAGLYPHIC, bool Active = false);
	
	// Creates the window setup depending on the Setup Type, destroing the original window and recreating it to its needs
	void CreateWin(SCR_TYPE SetUpType, dtCore::DeltaWin* DefWindow, dtCore::Camera* DefCamera, 
		dtCore::Scene* DefScene, dtCore::View* DefView);
	
	// Returns a pointer from the given Window var
	dtCore::RefPtr<dtCore::DeltaWin> GetWin(int WinNum);

	// Returns a pointer from the given Camera var
	dtCore::RefPtr<dtCore::Camera> GetCam(int CamNum);
	
	// Returns a pointer from the given View var
	dtCore::RefPtr<dtCore::View> GetView(int ViewNum);

	// Returns a pointer from the given Camera var
	dtCore::RefPtr<dtCore::Scene> GetScene(int SceneNum);
	
	// Set the given Window to the given Screen. Use Overwrite = true if a value is already present
	void SetWindowOnScreenNum(int ProgramWindowNumber, int MonitoreScreenNumber, bool Overwrite = false); 

	// Set all windows to full screen
	void SetFullScreen(bool);

	~vrsWindowCtr(void);
	

private:
	
	// Generates the windows for the sim. Use Overwrite = true if the function was already run once
	bool MakeWin(int NumOfWindows, bool Overwrite = false);
	// Link the Window with the given view, scene, camera and setup the viewport
	void SetupWindow(dtCore::DeltaWin*	Window,	const std::string& nameW, const std::string& titleW,
						dtCore::View*	View,	const std::string& nameV, 
						dtCore::Camera* Cam,	const std::string& nameC, 
						dtCore::Scene*	Sce,	
						float FOV_Y = 45, float FOV_X = 45, 
						float NearPlane = 0.1, float FarPlane = 500000.0);
	// Sets the total number of windows used in the curent program run. Use Overwrite = true if a value is already present
	void SetNumOfWindows(int NumOfWin, bool Overwrite = false);
						
	
protected:
	
	


public:
	
private:

	const static int MAX_WINDOWS_POSSIBLE = 6;


	
	//RefPtr<DeltaWin> _Window;
	dtCore::RefPtr<dtCore::DeltaWin> Window0;
	dtCore::RefPtr<dtCore::DeltaWin> Window1;
	dtCore::RefPtr<dtCore::DeltaWin> Window2;
	dtCore::RefPtr<dtCore::DeltaWin> Window3;
	dtCore::RefPtr<dtCore::DeltaWin> Window4;
	dtCore::RefPtr<dtCore::DeltaWin> Window5;

	//RefPtr<Camera> _tcCam;
	dtCore::RefPtr<dtCore::Camera> tcCam0;
	dtCore::RefPtr<dtCore::Camera> tcCam1;
	dtCore::RefPtr<dtCore::Camera> tcCam2;
	dtCore::RefPtr<dtCore::Camera> tcCam3;
	dtCore::RefPtr<dtCore::Camera> tcCam4;
	dtCore::RefPtr<dtCore::Camera> tcCam5;

	//RefPtr<View> _tcView;
	dtCore::RefPtr<dtCore::View> tcView0;
	dtCore::RefPtr<dtCore::View> tcView1;
	dtCore::RefPtr<dtCore::View> tcView2;
	dtCore::RefPtr<dtCore::View> tcView3;
	dtCore::RefPtr<dtCore::View> tcView4;
	dtCore::RefPtr<dtCore::View> tcView5;

	//RefPtr<Scene> _tcScene;
	dtCore::RefPtr<dtCore::Scene> tcScene0;

	
	
	

	


	dtCore::DeltaWin* Wind;
	
	osg::ref_ptr<osg::DisplaySettings> ds;					//Display Settings
	osg::ref_ptr<osg::GraphicsContext::Traits> traits;		//Traits
	
	osg::DisplaySettings::StereoMode _StereoType;
	
	bool	_StereoEnabled;						// Is Stereo Enabled?
	bool	_FullScreen;						// Are the windows in fullscreen?
	bool	_ScreenDecor;						// Is windows decor on/off?
	bool	_WindowsGenerated;					// Have the windows been generated already?

	int		_numOfWindows;						// Number of windows that where created
	int		_WinScrNums[MAX_WINDOWS_POSSIBLE];	// Holds the window on screen relationships



	




	

};


#endif // vrsWindow_H