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

#ifndef VRS_UFVG_ACTORS_REGISTRY_H
#define VRS_UFVG_ACTORS_REGISTRY_H

#include "export.h"

#include "ActorUFVGDLLInit.h"

#include "ActorUFVG.h"
#include "ActorUFVGnetCDF.h"

#include <dtDAL/actorpluginregistry.h>
namespace vrsUFVG
{
	class VRS_UFVG_EXPORT UFVGActorsRegistry : public dtDAL::ActorPluginRegistry
	{
	   public:
			
			static dtCore::RefPtr<dtDAL::ActorType> UFVGDLLINIT_ACTOR_TYPE;

			static dtCore::RefPtr<dtDAL::ActorType> UFVG_ACTOR_TYPE;
			static dtCore::RefPtr<dtDAL::ActorType> UFVGNETCDF_ACTOR_TYPE;
	     

		  // Constructs our registry.  Creates the actor types easy access when needed.
		  UFVGActorsRegistry();

		  // Registers actor types with the actor factory in the super class.
		  virtual void RegisterActorTypes();
	};
}
#endif //VRS_UFVG_ACTORS_REGISTRY_H