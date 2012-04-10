/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* WTRNOISE DLL Stevens University Collision Avoidance Project
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
* @author WTRNOISE Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRS_WTRNOISEDLLINIT_ACTOR_CPP
#define VRS_WTRNOISEDLLINIT_ACTOR_CPP

#include "../Include/ActorWTRNOISEDLLInit.h"

///////////////////////////////////////////////////////////////////////////////
const std::string WTRNOISEDLLInitActor::ACTOR_DEFAULT_NAME("WTRNOISE DLL Initialization Actor");
///////////////////////////////////////////////////////////////////////////////
WTRNOISEDLLInitActor::WTRNOISEDLLInitActor(dtGame::GameActorProxy& proxy)
:dtGame::GameActor(proxy)
,mSoundComp(0)
,mOceanHeight(0.0f)
,mOceanSndMaxHeight(1000.0f)
,mUnderWtrSound(0)
,mAboveWtrSound(0)
,mUpHighSound(0)
,mSplashSound(0)
,mEnablePhysics(false)
{
	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Adds the DLLs Components and Messages to the GM"); 
}
///////////////////////////////////////////////////////////////////////////////
void WTRNOISEDLLInitActor::OnEnteredWorld()
{
	if (mSuperSoundComponent)
	{
		mSoundComp = new SuperSoundComponent(SuperSoundComponent::COMPONENT_DEFAULT_NAME);
		mSoundComp->SetOceanHeight(mOceanHeight);
		mSoundComp->SetOceanSndMaxHeight(mOceanSndMaxHeight);
		mSoundComp->SetUnderWtrSnd(mUnderWtrSound);
		mSoundComp->SetAboveWtrSnd(mAboveWtrSound);
		mSoundComp->SetUpHighSnd(mUpHighSound);
		mSoundComp->SetSplashSnd(mSplashSound);
		mSoundComp->EnablePhysics(mEnablePhysics);
		/*std::cout << "disply name: " << mUnderWtrSound->GetDisplayName() << std::endl;
		std::cout << "extension: " << mUnderWtrSound->GetExtension() << std::endl;
		std::cout << "resource identifier: " << mUnderWtrSound->GetResourceIdentifier() << std::endl;
		std::cout << "resource name: " << mUnderWtrSound->GetResourceName() << std::endl;*/
		GetGameActorProxy().GetGameManager()->AddComponent(*mSoundComp, dtGame::GameManager::ComponentPriority::NORMAL);
	}
}
///////////////////////////////////////////////////////////////////////////////
void WTRNOISEDLLInitActor::SetActivateSuperSoundComponent(bool activate)
{
	mSuperSoundComponent = activate;
}
///////////////////////////////////////////////////////////////////////////////
void WTRNOISEDLLInitActor::SetOceanHeight(float height)
{
	mOceanHeight = height;
}
///////////////////////////////////////////////////////////////////////////////
void WTRNOISEDLLInitActor::SetOceanSndMaxHeight(float height)
{
	mOceanSndMaxHeight = height;
}
//////////////////////////////////////////////////////////////////////////////
//void WTRNOISEDLLInitActor::SetUndWtrSound(const dtDAL::ResourceDescriptor* undWtrSnd)
//{
//	mUnderWtrSound = new dtDAL::ResourceDescriptor(*undWtrSnd);
//}
void WTRNOISEDLLInitActor::SetUndWtrSound(const std::string undWtrSnd)
{
	//std::cout << "dllund: " << undWtrSnd << std::endl;
	mUnderWtrSound = new std::string(undWtrSnd);
	//std::cout << "dllund2: " << *mUnderWtrSound << std::endl;
}
//////////////////////////////////////////////////////////////////////////////
//void WTRNOISEDLLInitActor::SetAboveWtrSound(const dtDAL::ResourceDescriptor* aboveWtrSnd)
//{
//	mAboveWtrSound = new dtDAL::ResourceDescriptor(*aboveWtrSnd);
//}
void WTRNOISEDLLInitActor::SetAboveWtrSound(const std::string aboveWtrSnd)
{
	//std::cout << "dllabove: " << aboveWtrSnd << std::endl;
	mAboveWtrSound = new std::string(aboveWtrSnd);
	//std::cout << "dllabove2: " << mAboveWtrSound << std::endl;
}
//////////////////////////////////////////////////////////////////////////////
//void WTRNOISEDLLInitActor::SetUpHighSound(const dtDAL::ResourceDescriptor* upHighSnd)
//{
//	mUpHighSound = new dtDAL::ResourceDescriptor(*upHighSnd);
//}
void WTRNOISEDLLInitActor::SetUpHighSound(const std::string upHighSnd)
{
	mUpHighSound = new std::string(upHighSnd);
}
//////////////////////////////////////////////////////////////////////////////
//void WTRNOISEDLLInitActor::SetSplashSound(const dtDAL::ResourceDescriptor* splashSnd)
//{
//	mSplashSound = new dtDAL::ResourceDescriptor(*splashSnd);
//}
void WTRNOISEDLLInitActor::SetSplashSound(const std::string splashSnd)
{
	mSplashSound = new std::string(splashSnd);
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
WTRNOISEDLLInitActorProxy::WTRNOISEDLLInitActorProxy()
{
	SetClassName(WTRNOISEDLLInitActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
}
///////////////////////////////////////////////////////////////////////////////
void WTRNOISEDLLInitActorProxy::BuildPropertyMap()
{
	dtDAL::ActorProxy::BuildPropertyMap();

	WTRNOISEDLLInitActor* actor = static_cast<WTRNOISEDLLInitActor*>(GetActor());

	const std::string SuperSoundComponent_GROUP = "SuperSoundComponent Properties"; //Property group name
	
	// "ActivateSuperSoundComponent" property
	AddProperty(new dtDAL::BooleanActorProperty("ActivateSuperSoundComponent","Activate SuperSound Component",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetActivateSuperSoundComponent),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &WTRNOISEDLLInitActor::GetActivateSuperSoundComponent),
		"Enables/Disables SuperSound Component", SuperSoundComponent_GROUP));

	// "EnablePhysics" property
	AddProperty(new dtDAL::BooleanActorProperty("EnablePhysics","Enable Physics",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetEnablePhysics),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &WTRNOISEDLLInitActor::GetEnablePhysics),
		"Enables/Disables SuperSound Physics", SuperSoundComponent_GROUP));

	// "SetOceanHeight" property
	AddProperty(new dtDAL::FloatActorProperty("SetOceanHeight","Set Ocean Height",
		dtDAL::FloatActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetOceanHeight),
		dtDAL::FloatActorProperty::GetFuncType(actor, &WTRNOISEDLLInitActor::GetOceanHeight),
		"Set Height of Ocean", SuperSoundComponent_GROUP));

	// "OceanSoundMaxHeight" property
	AddProperty(new dtDAL::FloatActorProperty("OceanSoundMaxHeight","Ocean Sound Max Height",
		dtDAL::FloatActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetOceanSndMaxHeight),
		dtDAL::FloatActorProperty::GetFuncType(actor, &WTRNOISEDLLInitActor::GetOceanSndMaxHeight),
		"Set Max Height of Ocean Sound", SuperSoundComponent_GROUP));

	// "UnderWaterSound" property
	AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
				"UnderWaterSound", "Underwater Sound", 
				dtDAL::ResourceActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetUndWtrSound),
				//dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetUndWtrSound),
				"Set UnderWater Sound", SuperSoundComponent_GROUP));

	// "AboveWaterSound" property
	AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
				"AboveWaterSound", "Above Water Sound", 
				dtDAL::ResourceActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetAboveWtrSound),
				//dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetAboveWtrSound),
				"Set AboveWater Sound", SuperSoundComponent_GROUP));

	// "UpHighSound" property
	AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
				"UpHighSound", "Up High Sound", 
				dtDAL::ResourceActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetUpHighSound),
				//dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetUpHighSound),
				"Set Up High Sound", SuperSoundComponent_GROUP));

	// "SplashSound" property
	AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
				"SplashSound", "Splash Sound", 
				dtDAL::ResourceActorProperty::SetFuncType(actor, &WTRNOISEDLLInitActor::SetSplashSound),
				//dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetSplashSound),
				"Set Splash Sound", SuperSoundComponent_GROUP));

	//// "UnderWaterSound" property
	//AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
	//			"UnderWaterSound", "Underwater Sound", 
	//			dtDAL::ResourceActorProperty::SetDescFuncType(actor, &WTRNOISEDLLInitActor::SetUndWtrSound),
	//			dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetUndWtrSound),
	//			"Set UnderWater Sound", SuperSoundComponent_GROUP));

	//// "AboveWaterSound" property
	//AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
	//			"AboveWaterSound", "Above Water Sound", 
	//			dtDAL::ResourceActorProperty::SetDescFuncType(actor, &WTRNOISEDLLInitActor::SetAboveWtrSound),
	//			dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetAboveWtrSound),
	//			"Set AboveWater Sound", SuperSoundComponent_GROUP));

	//// "UpHighSound" property
	//AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
	//			"UpHighSound", "Up High Sound", 
	//			dtDAL::ResourceActorProperty::SetDescFuncType(actor, &WTRNOISEDLLInitActor::SetUpHighSound),
	//			dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetUpHighSound),
	//			"Set Up High Sound", SuperSoundComponent_GROUP));

	//// "SplashSound" property
	//AddProperty(new dtDAL::ResourceActorProperty(this->GetGameActor().GetGameActorProxy(), dtDAL::DataType::SOUND,
	//			"SplashSound", "Splash Sound", 
	//			dtDAL::ResourceActorProperty::SetDescFuncType(actor, &WTRNOISEDLLInitActor::SetSplashSound),
	//			dtDAL::ResourceActorProperty::GetDescFuncType(actor, &WTRNOISEDLLInitActor::GetSplashSound),
	//			"Set Splash Sound", SuperSoundComponent_GROUP));

	
}
///////////////////////////////////////////////////////////////////////////////
void WTRNOISEDLLInitActorProxy::CreateActor()
{
	SetActor(*new WTRNOISEDLLInitActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void WTRNOISEDLLInitActorProxy::OnEnteredWorld()
{
	dtGame::GameActorProxy::OnEnteredWorld();
}
///////////////////////////////////////////////////////////////////////////////

#endif //VRS_WTRNOISEDLLINIT_ACTOR_CPP