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


#ifndef COREDLL_ACTORS_REGISTRY_H
#define COREDLL_ACTORS_REGISTRY_H

#include "export.h"

#include "ActorGeneric.h"
#include "ActorObject.h"
#include "ActorGameStaticMesh.h"

#include "ActorPagedTerrain.h"
#include "ActorSkyDome.h"


#include <dtDAL/actorpluginregistry.h>

namespace vrsCore
{
	class CORE_EXPORT CoreActorsRegistry : public dtDAL::ActorPluginRegistry
	{
	   public:

			static dtCore::RefPtr<dtDAL::ActorType> GENERIC_ACTOR_TYPE;

			static dtCore::RefPtr<dtDAL::ActorType> OBJECT_ACTOR_TYPE;
			static dtCore::RefPtr<dtDAL::ActorType> GAME_STATIC_MESH_ACTOR_TYPE;

			static dtCore::RefPtr<dtDAL::ActorType> PAGED_TERRAIN_ACTOR_TYPE;
			static dtCore::RefPtr<dtDAL::ActorType> SKY_DOME_ACTOR_TYPE;
		  
	      

		  // Constructs our registry.  Creates the actor types easy access when needed.
		  CoreActorsRegistry();

		  // Registers actor types with the actor factory in the super class.
		  virtual void RegisterActorTypes();
	};
}

#endif //COREDLL_ACTORS_REGISTRY_H
