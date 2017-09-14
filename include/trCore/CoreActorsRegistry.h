/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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


#ifndef COREDLL_ACTORS_REGISTRY_H
#define COREDLL_ACTORS_REGISTRY_H

#include "export.h"

#include "ActorGeneric.h"
#include "ActorObject.h"
#include "ActorGameStaticMesh.h"

#include "ActorPagedTerrain.h"
#include "ActorSkyDome.h"


//#include <dtDAL/actorpluginregistry.h>

namespace trCore
{
	//class TR_CORE_EXPORT CoreActorsRegistry : public dtDAL::ActorPluginRegistry
	//{
	//   public:

	//		static dtCore::RefPtr<dtDAL::ActorType> GENERIC_ACTOR_TYPE;

	//		static dtCore::RefPtr<dtDAL::ActorType> OBJECT_ACTOR_TYPE;
	//		static dtCore::RefPtr<dtDAL::ActorType> GAME_STATIC_MESH_ACTOR_TYPE;

	//		static dtCore::RefPtr<dtDAL::ActorType> PAGED_TERRAIN_ACTOR_TYPE;
	//		static dtCore::RefPtr<dtDAL::ActorType> SKY_DOME_ACTOR_TYPE;
	//	  
	//      

	//	  // Constructs our registry.  Creates the actor types easy access when needed.
	//	  CoreActorsRegistry();

	//	  // Registers actor types with the actor factory in the super class.
	//	  virtual void RegisterActorTypes();
	//};
}

#endif //COREDLL_ACTORS_REGISTRY_H
