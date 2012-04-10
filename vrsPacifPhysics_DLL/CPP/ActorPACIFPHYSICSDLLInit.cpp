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


#ifndef VRS_PACIFPHYSICS_DLLINIT_ACTOR_CPP
#define VRS_PACIFPHYSICS_DLLINIT_ACTOR_CPP

#include "../Include/ActorPACIFPHYSICSDLLInit.h"

///////////////////////////////////////////////////////////////////////////////
const std::string PACIFPHYSICSDLLInitActor::ACTOR_DEFAULT_NAME("PACIFPHYSICS DLL Initialization Actor");
///////////////////////////////////////////////////////////////////////////////
PACIFPHYSICSDLLInitActor::PACIFPHYSICSDLLInitActor(dtGame::GameActorProxy& proxy)
:dtGame::GameActor(proxy)
,mPhysComp(0)
,mTerrainPageDist(7500.0)
,mTerrainPageDelay(15)
{
	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Adds the DLLs Components and Messages to the GM"); 
}
///////////////////////////////////////////////////////////////////////////////
void PACIFPHYSICSDLLInitActor::OnEnteredWorld()
{
	if (mPaciferousPhysicsComponent)
	{
		mPhysComp = new PaciferousPhysicsComponent(PaciferousPhysicsComponent::COMPONENT_DEFAULT_NAME);
		mPhysComp->SetTerrainPagingDist(mTerrainPageDist);
		mPhysComp->SetTerrainPagingDelay(mTerrainPageDelay);
		GetGameActorProxy().GetGameManager()->AddComponent(*mPhysComp, dtGame::GameManager::ComponentPriority::NORMAL);
	}
}
///////////////////////////////////////////////////////////////////////////////
void PACIFPHYSICSDLLInitActor::SetActivatePaciferousPhysicsComponent(bool activate)
{
	mPaciferousPhysicsComponent = activate;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
PACIFPHYSICSDLLInitActorProxy::PACIFPHYSICSDLLInitActorProxy()
{
	SetClassName(PACIFPHYSICSDLLInitActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
}
///////////////////////////////////////////////////////////////////////////////
void PACIFPHYSICSDLLInitActorProxy::BuildPropertyMap()
{
	dtDAL::ActorProxy::BuildPropertyMap();

	PACIFPHYSICSDLLInitActor* actor = static_cast<PACIFPHYSICSDLLInitActor*>(GetActor());

	const std::string PaciferousPhysicsComponent_GROUP = "PaciferousPhysicsComponent Properties"; //Property group name

	// "ActivatePaciferousPhysicsComponent" property
	AddProperty(new dtDAL::BooleanActorProperty("ActivatePaciferousPhysicsComponent","Activate PaciferousPhysics Component",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &PACIFPHYSICSDLLInitActor::SetActivatePaciferousPhysicsComponent),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &PACIFPHYSICSDLLInitActor::GetActivatePaciferousPhysicsComponent),
		"Enables/Disables PaciferousPhysics Component", PaciferousPhysicsComponent_GROUP));

	// Paging distance property
	AddProperty(new dtDAL::FloatActorProperty("Terrain_Paging_Dist", "Tile Paging Distance",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PACIFPHYSICSDLLInitActor::SetPagingDist),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PACIFPHYSICSDLLInitActor::GetPagingDist),
			"Sets terrain tile paging distance for physics", PaciferousPhysicsComponent_GROUP));

	// Terrain physics check delay
	AddProperty(new dtDAL::IntActorProperty("Terrain_Frame_Delay", "Terrain Physics Paging Delay",
			dtDAL::IntActorProperty::SetFuncType(actor, &PACIFPHYSICSDLLInitActor::SetTerrainPageDelay),
			dtDAL::IntActorProperty::GetFuncType(actor, &PACIFPHYSICSDLLInitActor::GetTerrainPageDelay),
			"Set the frame delay for paging terrain physics", PaciferousPhysicsComponent_GROUP));

}
///////////////////////////////////////////////////////////////////////////////
void PACIFPHYSICSDLLInitActorProxy::CreateActor()
{
	SetActor(*new PACIFPHYSICSDLLInitActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void PACIFPHYSICSDLLInitActorProxy::OnEnteredWorld()
{
	dtGame::GameActorProxy::OnEnteredWorld();
}
///////////////////////////////////////////////////////////////////////////////

#endif //VRS_PACIFPHYSICS_DLLINIT_ACTOR_CPP