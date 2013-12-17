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


#ifndef COREDLL_MY_GAME_ENTRY_POINT_CPP
#define COREDLL_MY_GAME_ENTRY_POINT_CPP

#include <trCore\CoreDLLEntryPoint.h>

#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/scene.h>

#include <dtGame/gamemanager.h>
#include <dtGame/defaultmessageprocessor.h>

#include <dtUtil/datapathutils.h>

#include <dtDAL/project.h>

#include <osg/ArgumentParser>

#include <trCore\InputComponent.h>
#include <trCore\ControllerComponent.h>

namespace trCore
{
	//////////////////////////////////////////////////////////////////////////
	extern "C" CORE_EXPORT dtGame::GameEntryPoint* CreateGameEntryPoint()
	{
		return new CoreDLLEntryPoint;
	}

	//////////////////////////////////////////////////////////////////////////
	extern "C" CORE_EXPORT void DestroyGameEntryPoint(dtGame::GameEntryPoint* entryPoint)
	{
		delete entryPoint;
	}

	//////////////////////////////////////////////////////////////////////////
	void CoreDLLEntryPoint::Initialize(dtGame::GameApplication& app, int argc, char** argv)
	{
		
		osg::ArgumentParser parser(&argc, argv);
		
		mMapName.reserve(512);

		if (!parser.read("-MapName", mMapName))
		{
			mMapName = "intro";
		}
		
		mInPlaybackMode = false;

		mCustContext.reserve(512);
		if (parser.read("-Context", mCustContext))
		{
			dtDAL::Project::GetInstance().SetContext(mCustContext);
		}
		else
		{
			dtDAL::Project::GetInstance().SetContext(dtUtil::GetDeltaRootPath() + "/Bin/Content");

		}

		app.GetGameManager()->GetScene().UseSceneLight(true);
	}

	//////////////////////////////////////////////////////////////////////////
	void CoreDLLEntryPoint::OnStartup(dtGame::GameApplication& app)
	{		

		// Load the map we created in STAGE.
		app.GetGameManager()->ChangeMap(mMapName);

		// Add Component - DefaultMessageProcessor
		dtCore::RefPtr<dtGame::DefaultMessageProcessor> dmp = new dtGame::DefaultMessageProcessor(dtGame::DefaultMessageProcessor::DEFAULT_NAME);
		app.GetGameManager()->AddComponent(*dmp,dtGame::GameManager::ComponentPriority::HIGHEST);

		// Add Component - Controller Component
		dtCore::RefPtr<trCore::ControllerComponent> controllerComp = new trCore::ControllerComponent(trCore::ControllerComponent::COMPONENT_DEFAULT_NAME, mInPlaybackMode);
		app.GetGameManager()->AddComponent(*controllerComp, dtGame::GameManager::ComponentPriority::NORMAL);

		// Add Component - Input Component
		dtCore::RefPtr<trCore::InputComponent> inputComp = new trCore::InputComponent(trCore::InputComponent::COMPONENT_DEFAULT_NAME, mInPlaybackMode);
		app.GetGameManager()->AddComponent(*inputComp, dtGame::GameManager::ComponentPriority::NORMAL);

		// Register our messages with the Game Manager message factory
		trCoreMessageType::RegisterMessageTypes( app.GetGameManager()->GetMessageFactory() );

	#ifdef _DEBUG
		app.GetGameManager()->DebugStatisticsTurnOn(true, true, 30, true);
	#endif //_DEBUG
	}
}


#endif //CORE2DLL_MY_GAME_ENTRY_POINT_CPP