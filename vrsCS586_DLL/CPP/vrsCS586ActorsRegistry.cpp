/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS586 DLL Stevens University Collision Avoidance Project
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
* @author CS586 Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_CS586_ACTORS_REGISTRY_CPP
#define VRS_CS586_ACTORS_REGISTRY_CPP

#include "../Include/vrsCS586ActorsRegistry.h"


dtCore::RefPtr<dtDAL::ActorType> CS586ActorsRegistry::CS586DLLINIT_ACTOR_TYPE(new dtDAL::ActorType("CS586 DLL Initialization Actor", "VR-Sim Lab.DLL Inits", "Initializes the DLLs Components and Msgs"));

dtCore::RefPtr<dtDAL::ActorType> CS586ActorsRegistry::HAPPYSPHERE_ACTOR_TYPE(new dtDAL::ActorType("Happy Sphere Actor", "VR-Sim Lab.CS586", "Happy Sphere Actor for Collision Avoidance"));


///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_CS586_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
{
   return new CS586ActorsRegistry();
}

///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_CS586_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry *registry)
{
   if (registry != NULL)
   {
      delete registry;
   }
}

//////////////////////////////////////////////////////////////////////////
CS586ActorsRegistry::CS586ActorsRegistry() : dtDAL::ActorPluginRegistry("CS586Actors")
{
   SetDescription("This is a library of actors used by VR-Sim for CS586 Stevens University Class");
}

//////////////////////////////////////////////////////////////////////////
void CS586ActorsRegistry::RegisterActorTypes()
{
	mActorFactory->RegisterType<CS586DLLInitActorProxy>(CS586DLLINIT_ACTOR_TYPE.get());

	mActorFactory->RegisterType<HappySphereActorProxy>(HAPPYSPHERE_ACTOR_TYPE.get());
}
#endif //VRS_CS586_ACTORS_REGISTRY_CPP