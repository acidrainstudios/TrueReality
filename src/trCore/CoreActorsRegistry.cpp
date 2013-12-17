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


#ifndef COREDLL_ACTORS_REGISTRY_CPP
#define COREDLL_ACTORS_REGISTRY_CPP

#include <trCore\CoreActorsRegistry.h>

namespace trCore
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
		mActorFactory->RegisterType<trCore::GenericActorProxy>(GENERIC_ACTOR_TYPE.get());

		mActorFactory->RegisterType<trCore::ObjectActorProxy>(OBJECT_ACTOR_TYPE.get());
		mActorFactory->RegisterType<trCore::GameStaticMeshActorProxy>(GAME_STATIC_MESH_ACTOR_TYPE.get());

		mActorFactory->RegisterType<trCore::PagedTerrainActorProxy>(PAGED_TERRAIN_ACTOR_TYPE.get());
		mActorFactory->RegisterType<trCore::SkyDomeActorProxy>(SKY_DOME_ACTOR_TYPE.get());
	}
}

#endif //CORE2DLL_ACTORS_REGISTRY_H