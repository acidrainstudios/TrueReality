/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* PACIFPHYSICS DLL Stevens University Collision Avoidance Project
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
* @author PACIFPHYSICS Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_PACIFPHYSICS_ACTORS_REGISTRY_CPP
#define VRS_PACIFPHYSICS_ACTORS_REGISTRY_CPP

#include "../Include/VRSPACIFPHYSICSActorsRegistry.h"

dtCore::RefPtr<dtDAL::ActorType> PACIFPHYSICSActorsRegistry::PACIFPHYSICSDLLINIT_ACTOR_TYPE(new dtDAL::ActorType("PACIFPHYSICS DLL Initialization Actor", "VR-Sim Lab.DLL Inits", "Initializes the DLLs Components and Msgs"));
dtCore::RefPtr<dtDAL::ActorType> PACIFPHYSICSActorsRegistry::PAGED_TERRAIN_PHYSICS_TYPE(new dtDAL::ActorType("Paged Terrain Physics", "VR-Sim Lab.PacifPhysics", "Paged Terrain Physics Actor"));
dtCore::RefPtr<dtDAL::ActorType> PACIFPHYSICSActorsRegistry::PHYSICS_GENERIC_ACTOR_TYPE(new dtDAL::ActorType("Physics Generic Actor", "VR-Sim Lab.PacifPhysics", "Generic Actor with Physics"));
dtCore::RefPtr<dtDAL::ActorType> PACIFPHYSICSActorsRegistry::BOAT_ACTOR_TYPE(new dtDAL::ActorType("Boat Actor", "VR-Sim Lab.PacifPhysics", "Boat Actor with Physics"));

///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_PACIFPHYSICS_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
{
   return new PACIFPHYSICSActorsRegistry();
}

///////////////////////////////////////////////////////////////////////////////
extern "C" VRS_PACIFPHYSICS_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry *registry)
{
   if (registry != NULL)
   {
      delete registry;
   }
}

//////////////////////////////////////////////////////////////////////////
PACIFPHYSICSActorsRegistry::PACIFPHYSICSActorsRegistry() : dtDAL::ActorPluginRegistry("PACIFPHYSICSActors")
{
   SetDescription("This is a library of Physics stuff");
}

//////////////////////////////////////////////////////////////////////////
void PACIFPHYSICSActorsRegistry::RegisterActorTypes()
{
	mActorFactory->RegisterType<PACIFPHYSICSDLLInitActorProxy>(PACIFPHYSICSDLLINIT_ACTOR_TYPE.get());
	mActorFactory->RegisterType<PagedTerrainPhysicsActorProxy>(PAGED_TERRAIN_PHYSICS_TYPE.get());
	mActorFactory->RegisterType<PhysicsGenericActorProxy>(PHYSICS_GENERIC_ACTOR_TYPE.get());
	mActorFactory->RegisterType<ActorBoatProxy>(BOAT_ACTOR_TYPE.get());
}
#endif //VRS_PACIFPHYSICS_ACTORS_REGISTRY_CPP