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

#ifndef VRS_PICATINNY_ACTORS_REGISTRY_CPP
#define VRS_PICATINNY_ACTORS_REGISTRY_CPP

#include "..\\Include\vrsPicatinnyActorsRegistry.h"


dtCore::RefPtr<dtDAL::ActorType> PicatinnyActorsRegistry::PICATINNYDLLINIT_ACTOR_TYPE(new dtDAL::ActorType("Picatinny DLL Initialization Actor", "VR-Sim Lab.DLL Inits", "Initializes the DLLs Components and Msgs"));

dtCore::RefPtr<dtDAL::ActorType> PicatinnyActorsRegistry::HUMAN_ACTOR_TYPE(new dtDAL::ActorType("Human Actor", "VR-Sim Lab.Picatinny", "Human Actor"));
dtCore::RefPtr<dtDAL::ActorType> PicatinnyActorsRegistry::PICA_CAMERA_ACTOR_TYPE(new dtDAL::ActorType("Picatinny Camera Actor", "VR-Sim Lab.Picatinny", "Picatinny Camera Actor"));



///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_PICATINNY_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
{
   return new PicatinnyActorsRegistry();
}

///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_PICATINNY_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry *registry)
{
   if (registry != NULL)
   {
      delete registry;
   }
}

//////////////////////////////////////////////////////////////////////////
PicatinnyActorsRegistry::PicatinnyActorsRegistry() : dtDAL::ActorPluginRegistry("PicatinnyActors")
{
   SetDescription("This is a library of actors used by VR-Sim Picatinny Module");
}

//////////////////////////////////////////////////////////////////////////
void PicatinnyActorsRegistry::RegisterActorTypes()
{
	mActorFactory->RegisterType<PICATINNYDLLInitActorProxy>(PICATINNYDLLINIT_ACTOR_TYPE.get());

	mActorFactory->RegisterType<HumanActorProxy>(HUMAN_ACTOR_TYPE.get());
	mActorFactory->RegisterType<PicaCameraActorProxy>(PICA_CAMERA_ACTOR_TYPE.get());
}


#endif //VRS_PICATINNY_ACTORS_REGISTRY_CPP