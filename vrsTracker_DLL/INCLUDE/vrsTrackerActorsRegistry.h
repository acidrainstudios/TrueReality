/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Camera Tracker Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_TRACKER_ACTORS_REGISTRY_H
#define VRS_TRACKER_ACTORS_REGISTRY_H

#include "export.h"

#include "ActorTrackerDLLInit.h"

#include "ActorTracker.h"

#include <dtDAL/actorpluginregistry.h>

class VRS_TRACKER_EXPORT TrackerActorsRegistry : public dtDAL::ActorPluginRegistry
{
   public:
		
		static dtCore::RefPtr<dtDAL::ActorType> TRACKERDLLINIT_ACTOR_TYPE;

		static dtCore::RefPtr<dtDAL::ActorType> TRACKER_ACTOR_TYPE;

      // Constructs our registry.  Creates the actor types easy access when needed.
      TrackerActorsRegistry();

      // Registers actor types with the actor factory in the super class.
      virtual void RegisterActorTypes();
};
#endif //VRS_TRACKER_ACTORS_REGISTRY_H