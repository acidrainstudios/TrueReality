/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* WTRNOISE DLL Stevens University Collision Avoidance Project
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owners of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author WTRNOISE Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_WTRNOISE_ACTORS_REGISTRY_CPP
#define VRS_WTRNOISE_ACTORS_REGISTRY_CPP

#include "../Include/VRSWTRNOISEActorsRegistry.h"


dtCore::RefPtr<dtDAL::ActorType> WTRNOISEActorsRegistry::WTRNOISEDLLINIT_ACTOR_TYPE(new dtDAL::ActorType("WTRNOISE DLL Initialization Actor", "VR-Sim Lab.DLL Inits", "Initializes the DLLs Components and Msgs"));

///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_WTRNOISE_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
{
   return new WTRNOISEActorsRegistry();
}

///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_WTRNOISE_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry *registry)
{
   if (registry != NULL)
   {
      delete registry;
   }
}

//////////////////////////////////////////////////////////////////////////
WTRNOISEActorsRegistry::WTRNOISEActorsRegistry() : dtDAL::ActorPluginRegistry("WTRNOISEActors")
{
   SetDescription("This is a library of Sound stuff");
}

//////////////////////////////////////////////////////////////////////////
void WTRNOISEActorsRegistry::RegisterActorTypes()
{
	mActorFactory->RegisterType<WTRNOISEDLLInitActorProxy>(WTRNOISEDLLINIT_ACTOR_TYPE.get());
}
#endif //VRS_WTRNOISE_ACTORS_REGISTRY_CPP