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


#ifndef COREDLL_trCore_DLL_ENTRYPOINT_H
#define COREDLL_trCore_DLL_ENTRYPOINT_H

#include "export.h"

#include <sstream>

//#include <dtGame/gameentrypoint.h>
//#include <dtGame/gameapplication.h>

namespace trCore
{
	///**
	// * Our entry point into the game.  The VRSim.exe application can load this like this:
	// * "VRSim.exe trCore"
	// */ 
	//class TR_CORE_EXPORT CoreDLLEntryPoint: public dtGame::GameEntryPoint
	//{
	//public:
	//	/**
	//	* Constructor
	//	*/
	//	CoreDLLEntryPoint(){};
	//	
	//	/**
	//	* Destructor
	//	*/
	//	virtual ~CoreDLLEntryPoint(){};
	//	  
	//	// Called to do early initializtion.  Grab your command line params here.
	//	virtual void Initialize(dtGame::GameApplication& app, int argc, char **argv);

	//	// Called just before your application's game loop starts.  This is your main 
	//	// opportunity to create components, load maps, create unique actors, etc...
	//	virtual void OnStartup(dtGame::GameApplication& app);

	//private:
	//	std::string mMapName;
	//	std::string mStereoType;
	//	std::string mDisplayMode;
	//	std::string mCustContext;

	//	//dtCore::RefPtr<dtGame::LogController> mLogController;
	//	//dtCore::RefPtr<dtGame::ServerLoggerComponent> mServerLogger;
	//	bool mInPlaybackMode; 
	//};
}
#endif //COREDLL_trCore_DLL_ENTRYPOINT_H
