/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owner of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* This software was developed by Maxim Serebrennik for various projects he worked on. 
* For more information e-mail him at MaximSter@gmail.com
*
* @author Maxim Serebrennik
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_UFVG_ACTORS_REGISTRY_CPP
#define VRS_UFVG_ACTORS_REGISTRY_CPP

#include "..\\Include\vrsUFVGActorsRegistry.h"

namespace vrsUFVG
{
	dtCore::RefPtr<dtDAL::ActorType> UFVGActorsRegistry::UFVGDLLINIT_ACTOR_TYPE(new dtDAL::ActorType("UFVG DLL Initialization Actor", "VR-Sim Lab.DLL Inits", "Initializes the DLLs Components and Msgs"));

	dtCore::RefPtr<dtDAL::ActorType> UFVGActorsRegistry::UFVG_ACTOR_TYPE(new dtDAL::ActorType("UFVG Actor", "VR-Sim Lab.UFVG", "UFVG Actor to display Velocity Profiles"));
	dtCore::RefPtr<dtDAL::ActorType> UFVGActorsRegistry::UFVGNETCDF_ACTOR_TYPE(new dtDAL::ActorType("UFVG netCDF Actor", "VR-Sim Lab.UFVG", "UFVG netCDF Actor to display netCDF data"));



	///////////////////////////////////////////////////////////////////////////////
	extern "C" VRS_UFVG_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
	{
	   return new UFVGActorsRegistry();
	}

	///////////////////////////////////////////////////////////////////////////////
	extern "C" VRS_UFVG_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry *registry)
	{
	   if (registry != NULL)
	   {
		  delete registry;
	   }
	}

	//////////////////////////////////////////////////////////////////////////
	UFVGActorsRegistry::UFVGActorsRegistry() : dtDAL::ActorPluginRegistry("UFVGActors")
	{
	   SetDescription("This is a library of actors used by VR-Sim Underwater Flow Vector Generator Module");
	}

	//////////////////////////////////////////////////////////////////////////
	void UFVGActorsRegistry::RegisterActorTypes()
	{
		mActorFactory->RegisterType<UFVGDLLInitActorProxy>(UFVGDLLINIT_ACTOR_TYPE.get());

		mActorFactory->RegisterType<UFVGActorProxy>(UFVG_ACTOR_TYPE.get());
		mActorFactory->RegisterType<UFVGnetCDFActorProxy>(UFVGNETCDF_ACTOR_TYPE.get());
	   
	}
}

#endif //VRS_UFVG_ACTORS_REGISTRY_CPP