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

#ifndef VRS_UFVGDLLINIT_ACTOR_CPP
#define VRS_UFVGDLLINIT_ACTOR_CPP

#include "..\\Include\ActorUFVGDLLInit.h"
namespace vrsUFVG
{
	///////////////////////////////////////////////////////////////////////////////
	const std::string UFVGDLLInitActor::ACTOR_DEFAULT_NAME("UFVG DLL Initialization Actor");
	///////////////////////////////////////////////////////////////////////////////
	UFVGDLLInitActor::UFVGDLLInitActor(dtGame::GameActorProxy& proxy)
	:dtGame::GameActor(proxy)
	,mUFVGComponent(false)
	{
		SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
		//Set the Actor Description
		SetDescription("Adds the DLLs Components and Messages to the GM"); 
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGDLLInitActor::OnEnteredWorld()
	{
		if(mUFVGComponent)
		{
			// Add Component - UFVG Component
			dtCore::RefPtr<UFVGComponent> UFVGComp = new UFVGComponent(UFVGComponent::COMPONENT_DEFAULT_NAME);
			GetGameActorProxy().GetGameManager()->AddComponent(*UFVGComp, dtGame::GameManager::ComponentPriority::NORMAL);
		}
	}
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	UFVGDLLInitActorProxy::UFVGDLLInitActorProxy()
	{
	   SetClassName(UFVGDLLInitActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGDLLInitActorProxy::BuildPropertyMap()
	{
	   const std::string Actor_GROUP = "Actor Properties"; //Property group name

	   dtDAL::ActorProxy::BuildPropertyMap();


	   UFVGDLLInitActor& actor = dynamic_cast<UFVGDLLInitActor&>(GetGameActor());

	   // "ActivateUFVGComponent" property
	   AddProperty(new dtDAL::BooleanActorProperty("ActivateUFVGComponent","Activate UFVG Component",
		  dtDAL::MakeFunctor(actor, &UFVGDLLInitActor::SetActivateUFVGComponent),
		  dtDAL::MakeFunctorRet(actor, &UFVGDLLInitActor::GetActivateUFVGComponent),
		  "Enables/Disables UFVG Component", Actor_GROUP));
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGDLLInitActorProxy::CreateActor()
	{
	   SetActor(*new UFVGDLLInitActor(*this));
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGDLLInitActorProxy::OnEnteredWorld()
	{
		dtGame::GameActorProxy::OnEnteredWorld();
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGDLLInitActor::SetActivateUFVGComponent(bool activate)
	{
		mUFVGComponent = activate;
	}
	///////////////////////////////////////////////////////////////////////////////
}
#endif //VRS_UFVGDLLINIT_ACTOR_CPP