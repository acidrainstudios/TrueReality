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

#ifndef tcWindow_CPP
#define tcWindow_CPP

#include <trCore\tcWindowCtr.h>

#include <dtUtil/Exception.h>

tcWindowCtr::tcWindowCtr(void):
			//_Window(0), 
			Window0(0), Window1(0), Window2(0), Window3(0), Window4(0), Window5(0),
			//_tcCam(0), 
			tcCam0(0), tcCam1(0), tcCam2(0), tcCam3(0), tcCam4(0), tcCam5(0), 
            //_tcView(0), 
			tcView0(0), tcView1(0), tcView2(0), tcView3(0), tcView4(0), tcView5(0),
			//_tcScene(0), 
			tcScene0(0),
			traits(0),
			ds(0)
{
	_FullScreen			= true;
	_ScreenDecor		= false;
	_WindowsGenerated	= false;
	_numOfWindows		= -1;

	_StereoEnabled		= false;
	_StereoType			= osg::DisplaySettings::ANAGLYPHIC;

	for(int i = 0; i<MAX_WINDOWS_POSSIBLE; i++)\
	{
		_WinScrNums[i] = -1;
	}
	
}
///////////////////////////////////////////////////////////////////////////////
void tcWindowCtr::SetStereo(osg::DisplaySettings::StereoMode S_Mode, bool Active)
{
	if (Active)
	{
		_StereoEnabled = true;
		_StereoType	= S_Mode;
	}
	else
	{
		_StereoEnabled = false;
	}


	if(ds.get() == NULL)
	{
		ds = osg::DisplaySettings::instance();
	}

	ds->setStereo(_StereoEnabled);

}

///////////////////////////////////////////////////////////////////////////////
bool tcWindowCtr::MakeWin(int NumOfWindows, bool Overwrite)
{


	
	if(!_WindowsGenerated || Overwrite)
	{
		int WinMax = MAX_WINDOWS_POSSIBLE;
		if( NumOfWindows >= WinMax)
		{
			NumOfWindows = WinMax-1;
		}
		else if(NumOfWindows < 0)
		{
			NumOfWindows = 1;
		}
		
	
		if(ds.get() == NULL)
		{
			ds = osg::DisplaySettings::instance();
		}	
		
		if(traits.get() == NULL)
		{
			traits = new osg::GraphicsContext::Traits;
		}
		
		// Loop for creating the common Traits, Graphics Context and Graphics Window
		for(int i=0; i<NumOfWindows; i++)
		{
			// Setup the traits
			traits->screenNum = _WinScrNums[i];
			traits->displayNum = 0; //WinScrDspNums[i*2-1];
			traits->windowName = "The Core 2";
			traits->x = 100;
			traits->y = 100;
			traits->width = 400;
			traits->height = 300;
			traits->alpha = ds->getMinimumNumAlphaBits();
			traits->stencil = ds->getMinimumNumStencilBits();
			traits->windowDecoration = _ScreenDecor;
			traits->doubleBuffer = true;
			traits->sharedContext = 0;
			traits->sampleBuffers = ds->getMultiSamples();
			traits->samples = ds->getNumMultiSamples();
			//traits->inheritedWindowData = inheritedWindowData;
			traits->setInheritedWindowPixelFormat = true;
			//traits->vsync=false;
			
			
			
			//osg::DisplaySettings::ANAGLYPHIC
			ds->setStereoMode(_StereoType);
			ds->setStereo(_StereoEnabled);
	
			// Setup the Stereo Options
			if (ds->getStereo())
			{
				switch (ds->getStereoMode())
				{
					
					case (osg::DisplaySettings::QUAD_BUFFER):
						traits->quadBufferStereo = true;
						break;
					case (osg::DisplaySettings::VERTICAL_INTERLACE):
					case (osg::DisplaySettings::CHECKERBOARD):
					case (osg::DisplaySettings::HORIZONTAL_INTERLACE):
			            traits->stencil = 8;
						break;
					default:
			            break;
				}
			}
	
			
	
	
			// Create the Graphics Context
			osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
	
			
	   
			if (gc.valid() == false)
			{
				throw dtUtil::Exception("The graphics context could not be created.", __FILE__, __LINE__ );
			}
	   
			// Create the Graphics Window
			osgViewer::GraphicsWindow* gw = dynamic_cast<osgViewer::GraphicsWindow*>(gc.get());
			if (gw)
			{
			gw->getEventQueue()->getCurrentEventState()->setWindowRectangle(traits->x, traits->y, traits->width, traits->height );
			}
		
			//osgViewer::ViewerBase viewer;
			//setThreadingModel(osgViewer::ViewerBase::ThreadingModel::ThreadPerCamera);

			//GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::ThreadingModel::SingleThreaded);
		
			
			
			gw->realize();
			gw->makeCurrent();
	
			// Create a D3D Window
			Wind = new dtCore::DeltaWin(traits->windowName, *gw );
			Wind->SetFullScreenMode(_FullScreen);
		
	
			// Set the created window to one of the possible pointers
			if(i == 0)
			{
				Window0 = Wind;
			}
			else if(i == 1)
			{
				Window1 = Wind;
			}
			else if(i == 2)
			{
				Window2 = Wind;
			}
			else if(i == 3)
			{
				Window3 = Wind;
			}
			else if(i == 4)
			{
				Window4 = Wind;
			}
			else 
			{
				Window5 = Wind;
			}
	
		}

		return true;
	}

	return true;
		
	
}

///////////////////////////////////////////////////////////////////////////////
void tcWindowCtr::SetupWindow(dtCore::DeltaWin*	WindowVal,	const std::string& nameW, const std::string& titleW,
								dtCore::View*	ViewVal,	const std::string& nameV, 
								dtCore::Camera* CameraVal,	const std::string& nameC, 
								dtCore::Scene*	SceneVal,	
								float FOV_Y, float FOV_X, float NearPlane, float FarPlane)
{



	CameraVal->SetName(nameC);
	CameraVal->SetWindow(WindowVal);
	CameraVal->SetNearFarCullingMode(dtCore::Camera::NO_AUTO_NEAR_FAR);
	CameraVal->GetOSGCamera()->setProjectionMatrixAsFrustum(tan(trUtil::Deg2Rad(-1*(FOV_X/2)))*NearPlane, // Left
															tan(trUtil::Deg2Rad((FOV_X/2)))*NearPlane,	// Right
															tan(trUtil::Deg2Rad(-1*(FOV_Y/2)))*NearPlane, // Bottom
															tan(trUtil::Deg2Rad(FOV_Y/2))*NearPlane,		// Top
															NearPlane, FarPlane); 

	
	
	ViewVal->SetName(nameV);
	ViewVal->SetScene(SceneVal);
	ViewVal->SetCamera(CameraVal);

	
	//ViewVal->GetOsgViewerView()->
	//tcView0->SetCamera(CameraVal);

	WindowVal->SetName(nameW);
	WindowVal->SetWindowTitle(titleW);
	
	

}
///////////////////////////////////////////////////////////////////////////////
void tcWindowCtr::SetNumOfWindows(int NumOfWin, bool Overwrite)
{
	if(_numOfWindows == -1 || Overwrite)
	{
		_numOfWindows = NumOfWin;
	}
}

///////////////////////////////////////////////////////////////////////////////
void tcWindowCtr::CreateWin(SCR_TYPE SetUpType, dtCore::DeltaWin* DefWindow, dtCore::Camera* DefCamera, 
							dtCore::Scene* DefScene, dtCore::View* DefView)
{
	// Set default D3D objects to internal objects for contolls
	tcView0 =	DefView;
	tcCam0	=	DefCamera;
	tcScene0 =	DefScene;
	
	tcScene0->SetName("defaultScene");

	

	// Destroy the default OSG window
	DefWindow->GetOsgViewerGraphicsWindow()->close(true);  

	
	
							//------------General Setup-------------------------//	
	osg::Vec4 LightPos(0, 0, 0, 1);

	DefScene->GetLight(0)->SetAmbient(0.1, 0.1, 0.1, 1);
	DefScene->GetLight(0)->GetLightSource()->getLight()->setPosition(LightPos);

	// Get the current monitor resolution
	dtCore::DeltaWin::Resolution currRes = dtCore::DeltaWin::GetCurrentResolution();

	float ScreenRatio = float(currRes.height)/float(currRes.width);

	std::cout << currRes.width << " " << currRes.height << std::endl;
	std::cout << ScreenRatio << std::endl;
		
	
							//--------------------------------------------------//
	
	
	// Window Setup
	switch (SetUpType)
	{

	case SCR_6_90x90:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);
		SetWindowOnScreenNum(3, 3);
		SetWindowOnScreenNum(4, 4);
		SetWindowOnScreenNum(5, 5);

		// Generate windows
		_WindowsGenerated = MakeWin(6);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		tcCam3 = new dtCore::Camera("Camera3");
		tcCam4 = new dtCore::Camera("Camera4");
		tcCam5 = new dtCore::Camera("Camera5");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		tcView3 = new dtCore::View("View3");
		tcView4 = new dtCore::View("View4");
		tcView5 = new dtCore::View("View5");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		tcCam3->SetTransform(dtCore::Transform(0, 0, 0, 0, -90, 0));
		tcCam4->SetTransform(dtCore::Transform(0, 0, 0, 0, 90, 0));
		tcCam5->SetTransform(dtCore::Transform(0, 0, 0, 180, 0, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		tcCam0->AddChild(tcCam3.get());
		tcCam0->AddChild(tcCam4.get());
		tcCam0->AddChild(tcCam5.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window3.get(), "Window3", "TC2:Floor", tcView3.get(), "View3", 
					tcCam3.get(), "Camera3", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window4.get(), "Window4", "TC2:Ceiling", tcView4.get(), "View4", 
					tcCam4.get(), "Camera4", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window5.get(), "Window5", "TC2:Back", tcView5.get(), "View5", 
					tcCam5.get(), "Camera5", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		break;

	case SCR_6_90xR:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);
		SetWindowOnScreenNum(3, 3);
		SetWindowOnScreenNum(4, 4);
		SetWindowOnScreenNum(5, 5);

		// Generate windows
		_WindowsGenerated = MakeWin(6);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		tcCam3 = new dtCore::Camera("Camera3");
		tcCam4 = new dtCore::Camera("Camera4");
		tcCam5 = new dtCore::Camera("Camera5");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		tcView3 = new dtCore::View("View3");
		tcView4 = new dtCore::View("View4");
		tcView5 = new dtCore::View("View5");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		tcCam3->SetTransform(dtCore::Transform(0, 0, 0, 0, -90, 0));
		tcCam4->SetTransform(dtCore::Transform(0, 0, 0, 0, 90, 0));
		tcCam5->SetTransform(dtCore::Transform(0, 0, 0, 180, 0, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		tcCam0->AddChild(tcCam3.get());
		tcCam0->AddChild(tcCam4.get());
		tcCam0->AddChild(tcCam5.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window3.get(), "Window3", "TC2:Floor", tcView3.get(), "View3", 
					tcCam3.get(), "Camera3", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window4.get(), "Window4", "TC2:Ceiling", tcView4.get(), "View4", 
					tcCam4.get(), "Camera4", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window5.get(), "Window5", "TC2:Back", tcView5.get(), "View5", 
					tcCam5.get(), "Camera5", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		break;

	case SCR_5_90x90:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);
		SetWindowOnScreenNum(3, 3);
		SetWindowOnScreenNum(4, 4);

		// Generate windows
		_WindowsGenerated = MakeWin(5);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		tcCam3 = new dtCore::Camera("Camera3");
		tcCam4 = new dtCore::Camera("Camera4");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		tcView3 = new dtCore::View("View3");
		tcView4 = new dtCore::View("View4");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		tcCam3->SetTransform(dtCore::Transform(0, 0, 0, 0, -90, 0));
		tcCam4->SetTransform(dtCore::Transform(0, 0, 0, 0, 90, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		tcCam0->AddChild(tcCam3.get());
		tcCam0->AddChild(tcCam4.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window3.get(), "Window3", "TC2:Floor", tcView3.get(), "View3", 
					tcCam3.get(), "Camera3", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window4.get(), "Window4", "TC2:Ceiling", tcView4.get(), "View4", 
					tcCam4.get(), "Camera4", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		break;

	case SCR_5_90xR:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);
		SetWindowOnScreenNum(3, 3);
		SetWindowOnScreenNum(4, 4);

		// Generate windows
		_WindowsGenerated = MakeWin(5);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		tcCam3 = new dtCore::Camera("Camera3");
		tcCam4 = new dtCore::Camera("Camera4");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		tcView3 = new dtCore::View("View3");
		tcView4 = new dtCore::View("View4");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		tcCam3->SetTransform(dtCore::Transform(0, 0, 0, 0, -90, 0));
		tcCam4->SetTransform(dtCore::Transform(0, 0, 0, 0, 90, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		tcCam0->AddChild(tcCam3.get());
		tcCam0->AddChild(tcCam4.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window3.get(), "Window3", "TC2:Floor", tcView3.get(), "View3", 
					tcCam3.get(), "Camera3", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window4.get(), "Window4", "TC2:Celing", tcView4.get(), "View4", 
					tcCam4.get(), "Camera4", tcScene0.get(), 90, 90, 0.1f, 500000.0f);

		break;

	case SCR_4_90x90:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);
		SetWindowOnScreenNum(3, 3);

		// Generate windows
		_WindowsGenerated = MakeWin(4);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		tcCam3 = new dtCore::Camera("Camera3");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		tcView3 = new dtCore::View("View3");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		tcCam3->SetTransform(dtCore::Transform(0, 0, 0, 0, -90, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		tcCam0->AddChild(tcCam3.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window3.get(), "Window3", "TC2:Floor", tcView3.get(), "View3", 
					tcCam3.get(), "Camera3", tcScene0.get(), 90, 90, 0.1f, 500000.0f);

		break;

	case SCR_4_90xR:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);
		SetWindowOnScreenNum(3, 3);

		// Generate windows
		_WindowsGenerated = MakeWin(4);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		tcCam3 = new dtCore::Camera("Camera3");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		tcView3 = new dtCore::View("View3");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		tcCam3->SetTransform(dtCore::Transform(0, 0, 0, 0, -90, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		tcCam0->AddChild(tcCam3.get());
		

		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window3.get(), "Window3", "TC2:Floor", tcView3.get(), "View3", 
					tcCam3.get(), "Camera3", tcScene0.get(), 90, 90, 0.1f, 500000.0f);

		

		break;

	case SCR_3_90x90:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);

		// Generate windows
		_WindowsGenerated = MakeWin(3);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90, 90, 0.1f, 500000.0f);
		break;

	case SCR_3_90xR:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);

		// Generate windows
		_WindowsGenerated = MakeWin(3);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -90, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 90, 0, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "Window0", "The Core 2", tcView0.get(), "View0", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);

		break;

	case SCR_3_45xR:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);
		SetWindowOnScreenNum(2, 2);

		// Generate windows
		_WindowsGenerated = MakeWin(3);

		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		tcCam2 = new dtCore::Camera("Camera2");
		
		tcView1 = new dtCore::View("View1");
		tcView2 = new dtCore::View("View2");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -45, 0, 0));
		tcCam2->SetTransform(dtCore::Transform(0, 0, 0, 45, 0, 0));
		
		tcCam0->AddChild(tcCam1.get());
		tcCam0->AddChild(tcCam2.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "Window0", "The Core 2", tcView0.get(), "View0", 
					tcCam0.get(), "Camera0", tcScene0.get(), 45*ScreenRatio, 45, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 45*ScreenRatio, 45, 0.1f, 500000.0f);
		SetupWindow(Window2.get(), "Window2", "TC2:Left", tcView2.get(), "View2", 
					tcCam2.get(), "Camera2", tcScene0.get(), 45*ScreenRatio, 45, 0.1f, 500000.0f);

		break;

	case SCR_2_45xR:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);
		SetWindowOnScreenNum(1, 1);

		// Generate windows
		_WindowsGenerated = MakeWin(2);
		
		// Create additional objects
		tcCam1 = new dtCore::Camera("Camera1");
		
		tcView1 = new dtCore::View("View1");
		
		// Link and adjust all the cameras 
		tcCam1->SetTransform(dtCore::Transform(0, 0, 0, -45, 0, 0));
		
		tcCam0->AddChild(tcCam1.get());
		
		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "Window0", "The Core 2", tcView0.get(), "View0", 
					tcCam0.get(), "Camera0", tcScene0.get(), 45*ScreenRatio, 45, 0.1f, 500000.0f);
		SetupWindow(Window1.get(), "Window1", "TC2:Right", tcView1.get(), "View1", 
					tcCam1.get(), "Camera1", tcScene0.get(), 45*ScreenRatio, 45, 0.1f, 500000.0f);
		
		break;

	case SCR_1_90xR:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);

		// Generate windows
		_WindowsGenerated = MakeWin(1);

		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "Window0", "The Core 2", tcView0.get(), "View0", 
					tcCam0.get(), "Camera0", tcScene0.get(), 90*ScreenRatio, 90, 0.1f, 500000.0f);
		break;

	case SCR_1_45xR:
	default:
		// Setup Window Positions
		SetWindowOnScreenNum(0, 0);

		// Generate windows
		_WindowsGenerated = MakeWin(1);

		// Link the views, windows and cameras
		SetupWindow(Window0.get(), "defaultWin", "The Core 2", tcView0.get(), "defaultView", 
					tcCam0.get(), "defaultCam", tcScene0.get(), 45*ScreenRatio, 45, 0.1f, 500000.0f);
		
		break;

	}

	//Window0.get()->GetOsgViewerGraphicsWindow()->grabFocus();
}
///////////////////////////////////////////////////////////////////////////////
dtCore::RefPtr<dtCore::DeltaWin> tcWindowCtr::GetWin(int WinNum)
{
	switch(WinNum)
	{
	case 0:
		{
			return Window0;
			break;
		}
	case 1:
		{
			return Window1;
			break;
		}
	case 2:
		{
			return Window2;
			break;
		}
	case 3:
		{
			return Window3;
			break;
		}
	case 4:
		{
			return Window4;
			break;
		}
	case 5:
		{
			return Window5;
			break;
		}
	default:
		{
			return Window0;
			break;
		}
	}

/*
	if(WinNum == 0)
	{
		return Window0;
	}
	else if(WinNum == 1)
	{
		return Window1;
	}
	else if(WinNum == 2)
	{
		return Window2;
	}
	else if(WinNum == 3)
	{
		return Window3;
	}
	else if(WinNum == 4)
	{
		return Window4;
	}
	else
	{
		return Window5;
	}*/
	
}

///////////////////////////////////////////////////////////////////////////////
dtCore::RefPtr<dtCore::Camera> tcWindowCtr::GetCam(int CamNum)
{
	switch(CamNum)
	{
	case 0:
		{
			return tcCam0;
			break;
		}
	case 1:
		{
			return tcCam1;
			break;
		}
	case 2:
		{
			return tcCam2;
			break;
		}
	case 3:
		{
			return tcCam3;
			break;
		}
	case 4:
		{
			return tcCam4;
			break;
		}
	case 5:
		{
			return tcCam5;
			break;
		}
	default:
		{
			return tcCam0;
			break;
		}
	}
	/*
	if(CamNum == 0)
	{
		return tcCam0;
	}
	else if(CamNum == 1)
	{
		return tcCam1;
	}
	else if(CamNum == 2)
	{
		return tcCam2;
	}else if(CamNum == 3)
	{
		return tcCam3;
	}
	else if(CamNum == 4)
	{
		return tcCam4;
	}
	else
	{
		return tcCam5;
	}*/
	
}
///////////////////////////////////////////////////////////////////////////////
dtCore::RefPtr<dtCore::View> tcWindowCtr::GetView(int ViewNum)
{
	switch(ViewNum)
	{
	case 0:
		{
			return tcView0;
			break;
		}
	case 1:
		{
			return tcView1;
			break;
		}
	case 2:
		{
			return tcView2;
			break;
		}
	case 3:
		{
			return tcView3;
			break;
		}
	case 4:
		{
			return tcView4;
			break;
		}
	case 5:
		{
			return tcView5;
			break;
		}
	default:
		{
			return tcView0;
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
dtCore::RefPtr<dtCore::Scene> tcWindowCtr::GetScene(int SceneNum)
{
	return tcScene0;
}
///////////////////////////////////////////////////////////////////////////////
void tcWindowCtr::SetFullScreen(bool value)
{
	_FullScreen = value;
	_ScreenDecor = !value;
}

///////////////////////////////////////////////////////////////////////////////
void tcWindowCtr::SetWindowOnScreenNum(int WinNum, int ScrNum, bool Overwrite)
{
	if(WinNum >= 0 && WinNum <MAX_WINDOWS_POSSIBLE)
	{
		if(_WinScrNums[WinNum] == -1 || Overwrite)
		{
			_WinScrNums[WinNum] = ScrNum;
		}
	}

}
///////////////////////////////////////////////////////////////////////////////
tcWindowCtr::~tcWindowCtr(void)
{
	
}










#endif // tcWindow_CPP
