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

#ifndef COREDLL_MY_GAME_ENTRY_POINT_CPP
#define COREDLL_MY_GAME_ENTRY_POINT_CPP

#include "..\\Include\vrsCoreDLLEntryPoint.h"

#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/scene.h>

#include <dtGame/gamemanager.h>
#include <dtGame/defaultmessageprocessor.h>

#include <dtUtil/datapathutils.h>

#include <dtDAL/project.h>

#include <osg/ArgumentParser>

#include "..\\Include\InputComponent.h"
#include "..\\Include\ControllerComponent.h"

namespace vrsCore
{
	//////////////////////////////////////////////////////////////////////////
	extern "C" CORE_EXPORT dtGame::GameEntryPoint* CreateGameEntryPoint()
	{
		return new vrsCoreDLLEntryPoint;
	}

	//////////////////////////////////////////////////////////////////////////
	extern "C" CORE_EXPORT void DestroyGameEntryPoint(dtGame::GameEntryPoint* entryPoint)
	{
		delete entryPoint;
	}

	//////////////////////////////////////////////////////////////////////////
	void vrsCoreDLLEntryPoint::Initialize(dtGame::GameApplication& app, int argc, char** argv)
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
	void vrsCoreDLLEntryPoint::OnStartup(dtGame::GameApplication& app)
	{		

		// Load the map we created in STAGE.
		app.GetGameManager()->ChangeMap(mMapName);

		// Add Component - DefaultMessageProcessor
		dtCore::RefPtr<dtGame::DefaultMessageProcessor> dmp = new dtGame::DefaultMessageProcessor(dtGame::DefaultMessageProcessor::DEFAULT_NAME);
		app.GetGameManager()->AddComponent(*dmp,dtGame::GameManager::ComponentPriority::HIGHEST);

		// Add Component - Controller Component
		dtCore::RefPtr<vrsCore::ControllerComponent> controllerComp = new vrsCore::ControllerComponent(vrsCore::ControllerComponent::COMPONENT_DEFAULT_NAME, mInPlaybackMode);
		app.GetGameManager()->AddComponent(*controllerComp, dtGame::GameManager::ComponentPriority::NORMAL);

		// Add Component - Input Component
		dtCore::RefPtr<vrsCore::InputComponent> inputComp = new vrsCore::InputComponent(vrsCore::InputComponent::COMPONENT_DEFAULT_NAME, mInPlaybackMode);
		app.GetGameManager()->AddComponent(*inputComp, dtGame::GameManager::ComponentPriority::NORMAL);

		// Register our messages with the Game Manager message factory
		vrsCoreMessageType::RegisterMessageTypes( app.GetGameManager()->GetMessageFactory() );

	#ifdef _DEBUG
		app.GetGameManager()->DebugStatisticsTurnOn(true, true, 30, true);
	#endif //_DEBUG
	}
}


#endif //CORE2DLL_MY_GAME_ENTRY_POINT_CPP