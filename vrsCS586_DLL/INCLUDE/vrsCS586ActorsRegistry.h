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

#ifndef VRS_CS586_ACTORS_REGISTRY_H
#define VRS_CS586_ACTORS_REGISTRY_H

#include "export.h"

#include "ActorCS586DLLInit.h"
#include "ActorHappySphere.h"

#include <dtDAL/actorpluginregistry.h>

class VRS_CS586_EXPORT CS586ActorsRegistry : public dtDAL::ActorPluginRegistry
{
   public:
		
		static dtCore::RefPtr<dtDAL::ActorType> CS586DLLINIT_ACTOR_TYPE;

		static dtCore::RefPtr<dtDAL::ActorType> HAPPYSPHERE_ACTOR_TYPE;
     

      // Constructs our registry.  Creates the actor types easy access when needed.
      CS586ActorsRegistry();

      // Registers actor types with the actor factory in the super class.
      virtual void RegisterActorTypes();
};
#endif //VRS_CS586_ACTORS_REGISTRY_H