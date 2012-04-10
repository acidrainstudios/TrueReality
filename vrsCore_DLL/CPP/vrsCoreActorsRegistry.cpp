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


#ifndef COREDLL_ACTORS_REGISTRY_CPP
#define COREDLL_ACTORS_REGISTRY_CPP

#include "..\\Include\vrsCoreActorsRegistry.h"

namespace vrsCore
{
	dtCore::RefPtr<dtDAL::ActorType> CoreActorsRegistry::GENERIC_ACTOR_TYPE(new dtDAL::ActorType("Generic Actor", "VR-Sim Lab", "Generic Actor with Key Controlls"));
	
	dtCore::RefPtr<dtDAL::ActorType> CoreActorsRegistry::OBJECT_ACTOR_TYPE(new dtDAL::ActorType("Static Mesh Object Actor", "VR-Sim Lab.Generic", "Static Mesh Object Actor"));
	dtCore::RefPtr<dtDAL::ActorType> CoreActorsRegistry::GAME_STATIC_MESH_ACTOR_TYPE(new dtDAL::ActorType("Game Static Mesh Actor", "VR-Sim Lab.Generic", "Static Mesh Actor that can get Game Messages"));

	dtCore::RefPtr<dtDAL::ActorType> CoreActorsRegistry::PAGED_TERRAIN_ACTOR_TYPE(new dtDAL::ActorType("Paged Terrain Actor", "VR-Sim Lab.Terrain", "Paged Terrain Actor for .IVE, .FLT and other geometry tiles"));
	dtCore::RefPtr<dtDAL::ActorType> CoreActorsRegistry::SKY_DOME_ACTOR_TYPE(new dtDAL::ActorType("SkyDome Actor", "VR-Sim Lab.Sky", "Sky Dome Actor"));


	///////////////////////////////////////////////////////////////////////////////
	extern "C" CORE_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
	{
	   return new CoreActorsRegistry();
	}

	///////////////////////////////////////////////////////////////////////////////
	extern "C" CORE_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry *registry)
	{
	   if (registry != NULL)
	   {
		  delete registry;
	   }
	}

	//////////////////////////////////////////////////////////////////////////
	CoreActorsRegistry::CoreActorsRegistry() : dtDAL::ActorPluginRegistry("CoreDLLActors")
	{
		SetDescription("This is a library of generic actors used by VR-Sim Lab");

	   //dtCore::ShaderManager::GetInstance().LoadShaderDefinitions("Shaders/TutorialShaderDefs.xml", false);
	}

	//////////////////////////////////////////////////////////////////////////
	void CoreActorsRegistry::RegisterActorTypes()
	{
		mActorFactory->RegisterType<vrsCore::GenericActorProxy>(GENERIC_ACTOR_TYPE.get());

		mActorFactory->RegisterType<vrsCore::ObjectActorProxy>(OBJECT_ACTOR_TYPE.get());
		mActorFactory->RegisterType<vrsCore::GameStaticMeshActorProxy>(GAME_STATIC_MESH_ACTOR_TYPE.get());

		mActorFactory->RegisterType<vrsCore::PagedTerrainActorProxy>(PAGED_TERRAIN_ACTOR_TYPE.get());
		mActorFactory->RegisterType<vrsCore::SkyDomeActorProxy>(SKY_DOME_ACTOR_TYPE.get());
	}
}

#endif //CORE2DLL_ACTORS_REGISTRY_H