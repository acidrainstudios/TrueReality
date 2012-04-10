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


#ifndef VRS_CS586DLLINIT_ACTOR_CPP
#define VRS_CS586DLLINIT_ACTOR_CPP

#include "../Include/ActorCS586DLLInit.h"

///////////////////////////////////////////////////////////////////////////////
const std::string CS586DLLInitActor::ACTOR_DEFAULT_NAME("CS586 DLL Initialization Actor");
///////////////////////////////////////////////////////////////////////////////
CS586DLLInitActor::CS586DLLInitActor(dtGame::GameActorProxy& proxy)
:dtGame::GameActor(proxy)
,mBabyComp(0)
,mBabyFactoryComponent(false)
,mMaxNumOfBabies(4)
,mBabyBirthDelay(0.25f)
,mJoyComp(0)
,mJoystickComponent(false)
{
	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Adds the DLLs Components and Messages to the GM"); 
}
///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActor::OnEnteredWorld()
{
	if(mBabyFactoryComponent)
	{
		// Add Component - BabyFactory Component
		mBabyComp = new BabyFactoryComponent(BabyFactoryComponent::COMPONENT_DEFAULT_NAME);	
		mBabyComp->SetMaxNumOfBabies(mMaxNumOfBabies);
		mBabyComp->SetBabyBirthDelay(mBabyBirthDelay);
		GetGameActorProxy().GetGameManager()->AddComponent(*mBabyComp, dtGame::GameManager::ComponentPriority::NORMAL);
	}

	if(mJoystickComponent)
	{
		// Add Component - Joystick Component
		mJoyComp = new JoystickComponent(JoystickComponent::COMPONENT_DEFAULT_NAME);
		GetGameActorProxy().GetGameManager()->AddComponent(*mJoyComp, dtGame::GameManager::ComponentPriority::NORMAL);
	}
}
///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActor::SetActivateBabyFactoryComponent(bool activate)
{
	mBabyFactoryComponent = activate;
}
///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActor::SetMaxBabiesNum(int NumOfBabies)
{
	mMaxNumOfBabies = NumOfBabies;
}
///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActor::SetBirthDelay(float DelayTime)
{
	mBabyBirthDelay = DelayTime;
}
///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActor::SetActivateJoystickComponent(bool activate)
{
	mJoystickComponent = activate;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
CS586DLLInitActorProxy::CS586DLLInitActorProxy()
{
	SetClassName(CS586DLLInitActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
}
///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActorProxy::BuildPropertyMap()
{
	dtDAL::ActorProxy::BuildPropertyMap();

	CS586DLLInitActor* actor = static_cast<CS586DLLInitActor*>(GetActor());

	const std::string BabyFactory_GROUP = "BabyFactoryComponent Properties"; //Property group name

	// "ActivateBabyFactoryComponent" property
	AddProperty(new dtDAL::BooleanActorProperty("ActivateBabyFactoryComponent","Activate BabyFactory Component",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &CS586DLLInitActor::SetActivateBabyFactoryComponent),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &CS586DLLInitActor::GetActivateBabyFactoryComponent),
		"Enables/Disables BabyFactory Component", BabyFactory_GROUP));

	// "SetMaxBabiesNum" property
	AddProperty(new dtDAL::IntActorProperty("SetMaxBabiesNum","Set Max Number of Babies",
		dtDAL::IntActorProperty::SetFuncType(actor, &CS586DLLInitActor::SetMaxBabiesNum),
		dtDAL::IntActorProperty::GetFuncType(actor, &CS586DLLInitActor::GetMaxBabiesNum),
		"Sets The Max Number of Babies", BabyFactory_GROUP));

	// "SetBirthDelay" property
	AddProperty(new dtDAL::FloatActorProperty("SetBirthDelay","Set Birth Delay",
		dtDAL::FloatActorProperty::SetFuncType(actor, &CS586DLLInitActor::SetBirthDelay),
		dtDAL::FloatActorProperty::GetFuncType(actor, &CS586DLLInitActor::GetBirthDelay),
		"Set Delay Between Baby Births (Sec)", BabyFactory_GROUP));

	const std::string JoystickComponent_GROUP = "JoystickComponent Properties"; //Property group name

	// "ActivateJoystickComponent" property
	AddProperty(new dtDAL::BooleanActorProperty("ActivateJoystickComponent","Activate Joystick Component",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &CS586DLLInitActor::SetActivateJoystickComponent),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &CS586DLLInitActor::GetActivateJoystickComponent),
		"Enables/Disables Joystick Component", JoystickComponent_GROUP));
}
///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActorProxy::CreateActor()
{
	SetActor(*new CS586DLLInitActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void CS586DLLInitActorProxy::OnEnteredWorld()
{
	dtGame::GameActorProxy::OnEnteredWorld();
}
///////////////////////////////////////////////////////////////////////////////

#endif //VRS_CS586DLLINIT_ACTOR_CPP