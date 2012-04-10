/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Picatinny Arsenal Demo Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_PICATINNY_ACTORS_REGISTRY_H
#define VRS_PICATINNY_ACTORS_REGISTRY_H

#include "export.h"

#include "ActorPICATINNYDLLInit.h"

#include "ActorHuman.h"
#include "ActorPicaCamera.h"

#include <dtDAL/actorpluginregistry.h>

class VRS_PICATINNY_EXPORT PicatinnyActorsRegistry : public dtDAL::ActorPluginRegistry
{
   public:
		
		static dtCore::RefPtr<dtDAL::ActorType> PICATINNYDLLINIT_ACTOR_TYPE;

		static dtCore::RefPtr<dtDAL::ActorType> HUMAN_ACTOR_TYPE;
		static dtCore::RefPtr<dtDAL::ActorType> PICA_CAMERA_ACTOR_TYPE;

      // Constructs our registry.  Creates the actor types easy access when needed.
      PicatinnyActorsRegistry();

      // Registers actor types with the actor factory in the super class.
      virtual void RegisterActorTypes();
};
#endif //VRS_PICATINNY_ACTORS_REGISTRY_H