/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Camera Tracker Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_TRACKERDLLINIT_ACTOR_CPP
#define VRS_TRACKERDLLINIT_ACTOR_CPP

#include "..\\Include\ActorTrackerDLLInit.h"

///////////////////////////////////////////////////////////////////////////////
const std::string TrackerDLLInitActor::ACTOR_DEFAULT_NAME("Tracker DLL Initialization Actor");
///////////////////////////////////////////////////////////////////////////////
TrackerDLLInitActor::TrackerDLLInitActor(dtGame::GameActorProxy& proxy)
:dtGame::GameActor(proxy)
,mTrackerComponent(false)
{
	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Adds the DLLs Components and Messages to the GM"); 
}
///////////////////////////////////////////////////////////////////////////////
void TrackerDLLInitActor::OnEnteredWorld()
{
	if(mTrackerComponent)
	{
		// Add Component - Tracker Component
		dtCore::RefPtr<TrackerComponent> TrackerComp = new TrackerComponent(TrackerComponent::COMPONENT_DEFAULT_NAME);
		GetGameActorProxy().GetGameManager()->AddComponent(*TrackerComp, dtGame::GameManager::ComponentPriority::NORMAL);
	}
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
TrackerDLLInitActorProxy::TrackerDLLInitActorProxy()
{
   SetClassName(TrackerDLLInitActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
}

///////////////////////////////////////////////////////////////////////////////
void TrackerDLLInitActorProxy::BuildPropertyMap()
{
   const std::string Actor_GROUP = "Actor Properties"; //Property group name

   dtDAL::ActorProxy::BuildPropertyMap();


   TrackerDLLInitActor& actor = dynamic_cast<TrackerDLLInitActor&>(GetGameActor());

   // "ActivateTrackerComponent" property
   AddProperty(new dtDAL::BooleanActorProperty("ActivateTrackerComponent","Activate Tracker Component",
      dtDAL::MakeFunctor(actor, &TrackerDLLInitActor::SetActivateTrackerComponent),
	  dtDAL::MakeFunctorRet(actor, &TrackerDLLInitActor::GetActivateTrackerComponent),
      "Enables/Disables Tracker Component", Actor_GROUP));
}

///////////////////////////////////////////////////////////////////////////////
void TrackerDLLInitActorProxy::CreateActor()
{
   SetActor(*new TrackerDLLInitActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void TrackerDLLInitActorProxy::OnEnteredWorld()
{
	dtGame::GameActorProxy::OnEnteredWorld();
}
///////////////////////////////////////////////////////////////////////////////
void TrackerDLLInitActor::SetActivateTrackerComponent(bool activate)
{
	mTrackerComponent = activate;
}
///////////////////////////////////////////////////////////////////////////////


#endif //VRS_TRACKERDLLINIT_ACTOR_CPP