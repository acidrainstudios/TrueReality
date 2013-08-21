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


#ifndef COREDLL_VRSCORE_DLL_ENTRYPOINT_H
#define COREDLL_VRSCORE_DLL_ENTRYPOINT_H

#include "export.h"

#include <sstream>

#include <dtGame/gameentrypoint.h>
#include <dtGame/gameapplication.h>

namespace vrsCore
{
	/**
	 * Our entry point into the game.  The VRSim.exe application can load this like this:
	 * "VRSim.exe vrsCore"
	 */ 
	class CORE_EXPORT vrsCoreDLLEntryPoint: public dtGame::GameEntryPoint
	{
	public:
		/**
		* Constructor
		*/
		vrsCoreDLLEntryPoint(){};
		
		/**
		* Destructor
		*/
		virtual ~vrsCoreDLLEntryPoint(){};
		  
		// Called to do early initializtion.  Grab your command line params here.
		virtual void Initialize(dtGame::GameApplication& app, int argc, char **argv);

		// Called just before your application's game loop starts.  This is your main 
		// opportunity to create components, load maps, create unique actors, etc...
		virtual void OnStartup(dtGame::GameApplication& app);

	private:
		std::string mMapName;
		std::string mStereoType;
		std::string mDisplayMode;
		std::string mCustContext;

		//dtCore::RefPtr<dtGame::LogController> mLogController;
		//dtCore::RefPtr<dtGame::ServerLoggerComponent> mServerLogger;
		bool mInPlaybackMode; 
	};
}
#endif //COREDLL_VRSCORE_DLL_ENTRYPOINT_H
