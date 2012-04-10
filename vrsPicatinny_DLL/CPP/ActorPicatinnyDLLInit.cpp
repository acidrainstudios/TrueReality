/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Picatinny Arsenal Demo Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_PICATINNYDLLINIT_ACTOR_CPP
#define VRS_PICATINNYDLLINIT_ACTOR_CPP

#include "..\\Include\ActorPICATINNYDLLInit.h"

///////////////////////////////////////////////////////////////////////////////
const std::string PICATINNYDLLInitActor::ACTOR_DEFAULT_NAME("Picatinny DLL Initialization Actor");
///////////////////////////////////////////////////////////////////////////////
PICATINNYDLLInitActor::PICATINNYDLLInitActor(dtGame::GameActorProxy& proxy)
:dtGame::GameActor(proxy)
,mCameraComponent(false)
,mCamName("NONE")
{
	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Adds the DLLs Components and Messages to the GM"); 
}
///////////////////////////////////////////////////////////////////////////////
void PICATINNYDLLInitActor::OnEnteredWorld()
{
	if(mCameraComponent)
	{
		// Add Component - Tracker Component
		dtCore::RefPtr<CameraComponent> CameraComp = new CameraComponent(CameraComponent::COMPONENT_DEFAULT_NAME);
		GetGameActorProxy().GetGameManager()->AddComponent(*CameraComp, dtGame::GameManager::ComponentPriority::NORMAL);
		if(mCamName != "NONE")
		{
			CameraComp->SetCameraOnMonitor0ByName(mCamName);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void PICATINNYDLLInitActor::SetActivateCameraComponent(bool activate)
{
	mCameraComponent = activate;
}
///////////////////////////////////////////////////////////////////////////////
void PICATINNYDLLInitActor::SetCamToMon0ByName(std::string CamName)
{
	mCamName = CamName;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
PICATINNYDLLInitActorProxy::PICATINNYDLLInitActorProxy()
{
   SetClassName(PICATINNYDLLInitActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
}

///////////////////////////////////////////////////////////////////////////////
void PICATINNYDLLInitActorProxy::BuildPropertyMap()
{
	const std::string CameraComponent_GROUP = "CameraComponent Properties"; //Property group name

	dtDAL::ActorProxy::BuildPropertyMap();


	PICATINNYDLLInitActor* actor = dynamic_cast<PICATINNYDLLInitActor*>(GetActor());

	// "ActivateCameraComponent" property
	AddProperty(new dtDAL::BooleanActorProperty("ActivateCameraComponent","Activate Picatinny Camera Component",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &PICATINNYDLLInitActor::SetActivateCameraComponent),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &PICATINNYDLLInitActor::GetActivateCameraComponent),
		"Enables/Disables Picatinny Camera Component", CameraComponent_GROUP));
	
	
	// "CamToMon0ByName" property
	AddProperty(new dtDAL::StringActorProperty("CamToMon0ByName","Set Camera By Name to Monitor 0",
		dtDAL::StringActorProperty::SetFuncType(actor, &PICATINNYDLLInitActor::SetCamToMon0ByName),
		dtDAL::StringActorProperty::GetFuncType(actor, &PICATINNYDLLInitActor::GetCamToMon0ByName),
		"Set Camera By Name to Monitor 0", CameraComponent_GROUP));
	
}

///////////////////////////////////////////////////////////////////////////////
void PICATINNYDLLInitActorProxy::CreateActor()
{
   SetActor(*new PICATINNYDLLInitActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void PICATINNYDLLInitActorProxy::OnEnteredWorld()
{
	dtGame::GameActorProxy::OnEnteredWorld();
}
///////////////////////////////////////////////////////////////////////////////


#endif //VRS_PICATINNYDLLINIT_ACTOR_CPP