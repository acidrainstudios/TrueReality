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


#ifndef VRS_UFVGDLLINIT_ACTOR_H
#define VRS_UFVGDLLINIT_ACTOR_H



#include "export.h"

#include "UFVGComponent.h"

#include <iostream>

#include <dtCore/refptr.h>

#include <dtGame/gamemanager.h>
#include <dtGame/GameActor.h>

#include <dtDAL/functor.h>
#include <dtDAL/actorproperty.h>
#include <dtDAL/enginepropertytypes.h>

namespace vrsUFVG
{
	class VRS_UFVG_EXPORT UFVGDLLInitActor : public dtGame::GameActor
	{
	public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;

		// Constructor
		UFVGDLLInitActor(dtGame::GameActorProxy& proxy);

		// Called when the actor has been added to the game manager.
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();

		/**
		* Activate the UFVGComponent
		*/
		void SetActivateUFVGComponent(bool activate);

		/**
		* Find out if UFVGComponent is active
		*/
		bool GetActivateUFVGComponent(void) const { return mUFVGComponent; }

	protected:

		// Destructor
		virtual ~UFVGDLLInitActor() { } ;

	private:
		
		bool mUFVGComponent;

	};


	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	class VRS_UFVG_EXPORT UFVGDLLInitActorProxy : public dtGame::GameActorProxy
	{
	public:

		/**
		* Constructor
		*/
		UFVGDLLInitActorProxy();

		// Creates the properties that are custom to the actor proxy.
		  virtual void BuildPropertyMap();

	protected:

		/**
		* Destructor
		*/
		virtual ~UFVGDLLInitActorProxy() { }

		// Creates an instance of our actor
		virtual void CreateActor();

		// Called when this proxy is added to the game manager (ie, the "world")
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();
	};
}

#endif //VRS_UFVGDLLINIT_ACTOR_H
