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

#ifndef VRS_TRACKER_ACTORS_REGISTRY_CPP
#define VRS_TRACKER_ACTORS_REGISTRY_CPP

#include "..\\Include\vrsTrackerActorsRegistry.h"


dtCore::RefPtr<dtDAL::ActorType> TrackerActorsRegistry::TRACKERDLLINIT_ACTOR_TYPE(new dtDAL::ActorType(TrackerDLLInitActor::ACTOR_DEFAULT_NAME, "VR-Sim Lab.DLL Inits", "Initializes the DLLs Components and Msgs"));

dtCore::RefPtr<dtDAL::ActorType> TrackerActorsRegistry::TRACKER_ACTOR_TYPE(new dtDAL::ActorType(TrackerActor::ACTOR_DEFAULT_NAME, "VR-Sim Lab.Tracker", "Tracker Actor"));




///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_TRACKER_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
{
   return new TrackerActorsRegistry();
}

///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_TRACKER_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry *registry)
{
   if (registry != NULL)
   {
      delete registry;
   }
}

//////////////////////////////////////////////////////////////////////////
TrackerActorsRegistry::TrackerActorsRegistry() : dtDAL::ActorPluginRegistry("TrackerActors")
{
   SetDescription("This is a library of actors used by VR-Sim Camera Tracker Module");
}

//////////////////////////////////////////////////////////////////////////
void TrackerActorsRegistry::RegisterActorTypes()
{
	mActorFactory->RegisterType<TrackerDLLInitActorProxy>(TRACKERDLLINIT_ACTOR_TYPE.get());

	mActorFactory->RegisterType<TrackerActorProxy>(TRACKER_ACTOR_TYPE.get());

}


#endif //VRS_TRACKER_ACTORS_REGISTRY_CPP