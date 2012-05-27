/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////

#ifndef Main_CPP
#define Main_CPP

//#include <osgViewer/GraphicsWindow>

#include <dtGame/gameapplication.h>
#include <dtUtil/datapathutils.h>
#include <dtUtil/log.h>

#include "..\\..\\vrsUtil_DLL\Include\vrsWindowCtr.h"

#include <iostream>

int main(int argc, char** argv)
{
	//Set Log File Options (need to have this 2x...there is a bug)
	dtUtil::LogFile::SetFileName("VRSimLog.html");

	dtUtil::LogFile::SetTitle("VR-Sim Lab Log File");
	
	//Set the Maximum level of Log msg outputs
	#ifdef _DEBUG
	dtUtil::Log::GetInstance().SetAllLogLevels(dtUtil::Log::LOG_DEBUG);
	#else
	dtUtil::Log::GetInstance().SetAllLogLevels(dtUtil::Log::LOG_ERROR);
	#endif
	
	
	// Setup the aplicatin search paths...
	std::string dataPath = dtUtil::GetDeltaDataPathList();
	std::string deltaPath = dtUtil::GetDeltaRootPath();

	dtUtil::SetDataFilePathList(dataPath + ";" +
								//dtCore::GetDeltaRootPath() + "/examples/data;" +
								//dtCore::GetDeltaRootPath() + "/examples/data/gui/imagesets;" +
								//dtCore::GetDeltaRootPath() + "/examples/data/gui/schemes;" +
								//dtCore::GetDeltaRootPath() + "/examples/data/gui/fonts;" +
								//dtCore::GetDeltaRootPath() + "/examples/data/gui/looknfeel;" +
								deltaPath + "./;" +
								deltaPath + "/Bin;" +
								deltaPath + "/Bin/Data;" +
								deltaPath + "/Bin/Content;" +
								deltaPath + "/Bin/Content/Data;" +
								deltaPath + "/Bin/Content/maps;" +
								deltaPath + "/Bin/Content/Particles;" +
								deltaPath + "/Bin/Content/Prefabs;" +
								deltaPath + "/Bin/Content/StaticMeshes;" +
								deltaPath + "/Bin/Content/Terrains;" +
								deltaPath + "/Bin/Content/Textures");

	LOG_INFO("Path list is: " + dtUtil::GetDataFilePathList() );

	//Set the Config File name
	std::string configFileName(deltaPath + "/Bin/config.xml");

   ///////////////-----New-----/////////////
   /*
   dtCore::DeltaWin::DeltaWinTraits deltaTraits;
   deltaTraits.name = "My Huuuuuuge Window";
   deltaTraits.x = 100;
   deltaTraits.y = 100;
   deltaTraits.width = 800;
   deltaTraits.height = 800;
   deltaTraits.showCursor = true;
   deltaTraits.fullScreen = false;
   deltaTraits.realizeUponCreate = false;
   deltaTraits.inheritedWindowData = NULL;
   deltaTraits.contextToShare = NULL;
   deltaTraits.vsync = false;


   dtCore::RefPtr<dtCore::DeltaWin> mWin = new dtCore::DeltaWin(deltaTraits);

   //wglSwapIntervalEXT(0); */
   ///////////////-----New-----/////////////
	try
	{
		//Create our Window Controller
		osg::ref_ptr<vrsUtil::vrsWindowCtr> WinCtr = vrsUtil::vrsWindowCtr::GetInstance();

		//Create our Application Class
		osg::ref_ptr <dtGame::GameApplication> app = WinCtr->CreateApp(argc, argv, configFileName);

		app->SetGameLibraryName("vrsCore");
		app->Config();
		app->Run();
		app = NULL;

		std::cerr << "\n\nVR-Sim Lab is now shutting down ... " << std::endl;
	}
	catch (const dtUtil::Exception& ex)
	{
		ex.LogException(dtUtil::Log::LOG_ERROR);

		#ifdef _DEBUG
			system("pause");
		#endif

		return -1;
	}

	#ifdef _DEBUG
		system("pause");
	#endif

	return 0;
}

#endif // Main_CPP