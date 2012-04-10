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

#ifndef VRS_PICATINNY_HUMAN_ACTOR_CPP
#define VRS_PICATINNY_HUMAN_ACTOR_CPP

#include "..\\Include\ActorHuman.h"

///////////////////////////////////////////////////////////////////////////////
const std::string HumanActor::ACTOR_DEFAULT_NAME("Human Actor");
///////////////////////////////////////////////////////////////////////////////

HumanActor::HumanActor(dtAnim::AnimationGameActorProxy& proxy)
:dtAnim::AnimationGameActor(proxy)
,mPropertiesUpdated(false)
,mBeingTracked(false)
,mCamIsDead(false)
{
	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Stevens Institute of Technology Picatinny Human Actor"); 

	dtAnim::AnimNodeBuilder& nodeBuilder = dtAnim::Cal3DDatabase::GetInstance().GetNodeBuilder();
	nodeBuilder.SetCreate(dtAnim::AnimNodeBuilder::CreateFunc(&nodeBuilder, &dtAnim::AnimNodeBuilder::CreateSoftware));

}

///////////////////////////////////////////////////////////////////////////////
void HumanActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
{
	mDeltaSimTime = tickMessage.GetDeltaSimTime();
	float runTime = tickMessage.GetSimulationTime();

	//std::cout << runTime << std::endl;

	if (GetName() == "ShooterHuman"/*GetMass() != 5.50f*/)
	{
		if (!mBeingTracked && runTime > 2.0f)
		{
			//std::cout << "should track now" << std::endl;
			dtDAL::ActorProxy* proxy;
			GetGameActorProxy().GetGameManager()->FindActorByName("CameraToDie", proxy);

			PicaCameraActor* actor = static_cast<PicaCameraActor*>(proxy->GetActor());
			actor->TrackActor(this->GetUniqueId());
			actor->TrackingOn(true);

			mBeingTracked = true;
		}

		if (runTime > 7.0f && runTime < 7.2f && !(GetHelper()->GetSequenceMixer().IsAnimationPlaying("stand to aim")))
		{
			GetHelper()->GetSequenceMixer().ClearActiveAnimations(0.5f);
			GetHelper()->PlayAnimation("stand to aim");
			GetHelper()->PlayAnimation("aim front up");
			GetHelper()->PlayAnimation("aim right up");
		}

		if (runTime > 7.2f && GetHelper()->GetSequenceMixer().IsAnimationPlaying("stand to aim"))
		{
			GetHelper()->ClearAnimation("stand to aim", 0.5f);
			//killCamera();
		}

		if (runTime > 8.9f && !mCamIsDead)
		{	
			killCamera();

			mCamIsDead = true;
		}

		if (runTime > 9.0f && !(GetHelper()->GetSequenceMixer().IsAnimationPlaying("run")))
		{
			GetHelper()->GetSequenceMixer().ClearActiveAnimations(0.5f);
			GetHelper()->PlayAnimation("run");
		}
	}

	GetHelper()->Update(mDeltaSimTime);

	if (mPropertiesUpdated)
	{
		GetGameActorProxy().NotifyFullActorUpdate();
		mPropertiesUpdated = false;
	}
}

///////////////////////////////////////////////////////////////////////////////
void HumanActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
{
	mDeltaSimTime = tickMessage.GetDeltaSimTime();
}

///////////////////////////////////////////////////////////////////////////////
void HumanActor::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
	{
		const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

		// Note, we are using strings which aren't constants.  In a real application, these
		// event names should be stored in some sort of shared place and should be constants...
		/*
		if (eventMsg.GetGameEvent() != NULL)
		{
			// Handle "ToggleEngine" Game Event
			if (eventMsg.GetGameEvent()->GetName() == "Ignition" && mIgnitionTimer > 1.0f)
			{
				mIsEngineRunning = !mIsEngineRunning;
				#ifdef _DEBUG
					printf("Toggling Engines to the [%s] state.\r\n", (mIsEngineRunning ? "ON" : "OFF"));
				#endif //_DEBUG

				mIgnitionTimer = 0.0f;
			}
			
		}*/
	}
}

void HumanActor::killCamera()
{
	//find actors by TYPE
	dtDAL::ActorProxy* proxy;
	GetGameActorProxy().GetGameManager()->FindActorByName("CameraToDie", proxy);

	PicaCameraActor* deadCamera = static_cast<PicaCameraActor*>(proxy->GetActor());
	deadCamera->SetPowerOn(false);

	//dtCore::Camera* myCamera = dtCore::Camera::GetInstance("My STAGE Camera Name");

	dtCore::ParticleSystem* BoomFire = dtCore::ParticleSystem::GetInstance("BoomFire");
	BoomFire->SetEnabled(true);

	/*GetGameActorProxy().GetGameManager()->FindActorByName("CameraToReplace", proxy);

	actor = static_cast<PicaCameraActor*>(proxy->GetActor());
	actor->TrackActor(this->GetUniqueId());
	actor->TrackingOn(true);*/

	//find actors by TYPE
	std::vector<dtDAL::ActorProxy*> proxies;
	GetGameActorProxy().GetGameManager()->FindActorsByType(*PicatinnyActorsRegistry::PICA_CAMERA_ACTOR_TYPE, proxies); 


	//Create a vector of actors so we can access them directly
	//And a vector of our views
	PicaCameraActor* actor;

	for(int i=0; i<(signed)proxies.size(); i++)
	{
		actor = static_cast<PicaCameraActor*>(proxies[i]->GetActor());

		actor->TrackActor(this->GetUniqueId());
		actor->TrackingOn(true);
	}

	deadCamera->TrackingOn(false);


	//Create a vector of actors so we can access them directly
	//And a vector of our views
	/*for(int i=0; i<(signed)proxies.size(); i++)
	{
		PicaCameraActor* actor = static_cast<PicaCameraActor*>(proxies[i]->GetActor());
		mCameraAct.push_back(actor);

		dtCore::View* CamView = new dtCore::View();
		CamView->SetScene(GetGameManager()->GetApplication().GetScene());
		CamView->SetCamera(actor->GetDtCoreCamera());
		CamView->SetRenderOrder(1);
		GetGameManager()->GetApplication().AddView(*CamView);
		mViews.push_back(CamView);
	}*/
}

///////////////////////////////////////////////////////////////////////////////
void HumanActor::OnEnteredWorld()
{
	dtAnim::AnimationGameActor::OnEnteredWorld();

	GetOSGNode()->getStateSet()->setRenderBinDetails(50, "RenderBin");

	GetHelper()->PlayAnimation("run");
	//GetHelper()->PlayAnimation("stand to aim");
	//GetHelper()->PlayAnimation("aim front up");
	//GetHelper()->PlayAnimation("aim right up");
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
HumanActorProxy::HumanActorProxy()
{
   SetClassName(HumanActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
}

///////////////////////////////////////////////////////////////////////////////
void HumanActorProxy::BuildPropertyMap()
{
   const std::string Actor_GROUP = "Actor Properties"; //Property group name

   //dtDAL::ActorProxy::BuildPropertyMap();
   //TransformableActorProxy::BuildPropertyMap();
   //dtDAL::PhysicalActorProxy::BuildPropertyMap();
   //dtGame::GameActorProxy::BuildPropertyMap();
   dtAnim::AnimationGameActorProxy::BuildPropertyMap();

   HumanActor* actor = static_cast<HumanActor*>(GetActor());

   // "Is Player" property
	/*AddProperty(new dtDAL::BooleanActorProperty("IsPlayer","Is Player",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &GenericActor::SetActorIsPlayer),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &GenericActor::GetActorIsPlayer),
		"Sets this actor as the main human player", Actor_GROUP));*/

}

///////////////////////////////////////////////////////////////////////////////
void HumanActorProxy::CreateActor()
{
   SetActor(*new HumanActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void HumanActorProxy::OnEnteredWorld()
{

   //Register an invokable for Game Events...
   //RegisterForMessages(dtGame::MessageType::INFO_GAME_EVENT);
	RegisterForMessagesAboutSelf(dtGame::MessageType::INFO_GAME_EVENT);

   // Register an invokable for tick messages. Local or Remote only, not both!
   if (IsRemote())
   {
      RegisterForMessages(dtGame::MessageType::TICK_REMOTE,
         dtGame::GameActorProxy::TICK_REMOTE_INVOKABLE);
   }
   else
   {
      RegisterForMessages(dtGame::MessageType::TICK_LOCAL,
         dtGame::GameActorProxy::TICK_LOCAL_INVOKABLE);
   }

   
   dtAnim::AnimationGameActorProxy::OnEnteredWorld();
}


#endif //VRS_PICATINNY_HUMAN_ACTOR_CPP