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

#ifndef VRS_PICATINNY_CAMERA_ACTOR_CPP
#define VRS_PICATINNY_CAMERA_ACTOR_CPP

#include "..\\Include\ActorPicaCamera.h"

///////////////////////////////////////////////////////////////////////////////
const std::string PicaCameraActor::ACTOR_DEFAULT_NAME("Picatinny Camera Actor");
///////////////////////////////////////////////////////////////////////////////

PicaCameraActor::PicaCameraActor(dtActors::GameMeshActorProxy& proxy)
:dtActors::GameMeshActor(proxy)
,mPropertiesUpdated(false)
,mCamera(0)
,mCamSize(100.0f, 100.0f)
,mCamScrPos(0, 0)
,mPower(true)
,mTracking(false)
{
	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Stevens Institute of Technology Picatinny Camera Actor"); 
}

///////////////////////////////////////////////////////////////////////////////
void PicaCameraActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
{
	mDeltaSimTime = tickMessage.GetDeltaSimTime();

	if (mPropertiesUpdated)
	{
		GetGameActorProxy().NotifyFullActorUpdate();
		mPropertiesUpdated = false;
	}

	if(mTracking)
	{
		TurnToTrackedActor();
	}
}

///////////////////////////////////////////////////////////////////////////////
void PicaCameraActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
{
	mDeltaSimTime = tickMessage.GetDeltaSimTime();
}

///////////////////////////////////////////////////////////////////////////////
void PicaCameraActor::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
	{
		/*
		const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

		// Note, we are using strings which aren't constants.  In a real application, these
		// event names should be stored in some sort of shared place and should be constants...
		
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
			
		}
		*/
	}
	//If the focus changed to a different actor, update who the focus is on now...
	//else if (message.GetMessageType() == vrsCoreMessageType::MSG_PLAYER_ACTOR_CHANGE)
	//{
		
	//}
}
///////////////////////////////////////////////////////////////////////////////
void PicaCameraActor::OnEnteredWorld()
{
	dtActors::GameMeshActor::OnEnteredWorld();
	
	GetOSGNode()->getStateSet()->setRenderBinDetails(50, "RenderBin");

	SetupCamera();
}
///////////////////////////////////////////////////////////////////////////////
inline void PicaCameraActor::SetCameraSize(osg::Vec2f size)
{
	mCamSize = size;
	if(mCamera.valid())
	{
		mCamera->GetOSGCamera()->setViewport(new osg::Viewport(mCamScrPos.x(), mCamScrPos.y(), mCamSize.x(), mCamSize.y()));
		mCamera->SetAspectRatio(mCamSize.x()/mCamSize.y());
	}
	mPropertiesUpdated = true;
}
///////////////////////////////////////////////////////////////////////////////
inline void PicaCameraActor::SetCameraScreenPosition(osg::Vec2f pos)
{
	mCamScrPos = pos;
	if(mCamera.valid())
	{
		mCamera->GetOSGCamera()->setViewport(new osg::Viewport(mCamScrPos.x(), mCamScrPos.y(), mCamSize.x(), mCamSize.y()));
	}
	mPropertiesUpdated = true;
}
///////////////////////////////////////////////////////////////////////////////
inline void PicaCameraActor::SetPowerOn(bool on)
{
	mPower = on;
	if(mCamera.valid())
	{
		GetDtCoreCamera()->SetEnabled(mPower);
	}
	mPropertiesUpdated = true;
}
///////////////////////////////////////////////////////////////////////////////
void PicaCameraActor::TrackActor(dtCore::UniqueId ActorsID)
{
	dtDAL::ActorProxy* proxie = GetGameActorProxy().GetGameManager()->FindActorById(ActorsID);
	mTrackedActor = dynamic_cast<dtGame::GameActor*>(proxie->GetActor());	
}
///////////////////////////////////////////////////////////////////////////////
void PicaCameraActor::TrackingOn(bool Tracking)
{
	mTracking = Tracking;
	//GetDtCoreCamera()->GetOSGCamera()->setProjectionMatrixAsPerspective(10, 1, 0.01, 5000);
}
///////////////////////////////////////////////////////////////////////////////
void PicaCameraActor::SetupCamera(void)
{
	//Setup a new Camera
	mCamera = new dtCore::Camera("CameraAct");
	mCamera->SetWindow(this->GetGameActorProxy().GetGameManager()->GetApplication().GetWindow());
	mCamera->GetOSGCamera()->setViewport(new osg::Viewport(mCamScrPos.x(), mCamScrPos.y(), mCamSize.x(), mCamSize.y()));
	mCamera->SetAspectRatio(mCamSize.x()/mCamSize.y());
	this->AddChild(mCamera.get());
}
///////////////////////////////////////////////////////////////////////////
void PicaCameraActor::TurnToTrackedActor(void)
{
	dtCore::Transform t;
	mTrackedActor->GetTransform(t);
	osg::Vec3f actPos, myPos;
	osg::Vec3f myHpr;
	t.GetTranslation(actPos);
	
	GetTransform(t);
	t.GetTranslation(myPos);
	
	float actAngle = (osg::RadiansToDegrees(atan2(actPos.y()-myPos.y(), actPos.x()-myPos.x()))-90.0f);

	t.GetRotation(myHpr);
	float myAngle = myHpr.x();

	if((myAngle < 0.0f) && (actAngle < 0.0f)) //if myAngle = west and actAngle = west
	{
		TurnLeftRight(myAngle - actAngle);
	} 
	else if ((myAngle >= 0.0f) && (actAngle >= 0.0f)) //if myAngle = east and actAngle = east
	{
		TurnLeftRight(myAngle - actAngle);
	}
	else if ((myAngle < 0.0f) && (actAngle >= 0.0f)) //if myAngle = west and actAngle = east
	{
		TurnLeftRight(360.0f + myAngle - actAngle);
	}
	else											//if myAngle = east and actAngle = west
	{
		TurnLeftRight(myAngle - actAngle);
	}

}
///////////////////////////////////////////////////////////////////////////
void PicaCameraActor::TurnLeftRight(float Degrees)
{
	dtCore::Transform t;
	osg::Vec3f hpr(0.0f,0.0f,0.0f);
	GetTransform(t);
	t.GetRotation(hpr);
	hpr.set(hpr.x()-Degrees, hpr.y(), hpr.z());
	t.SetRotation(hpr);
	SetTransform(t);
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
PicaCameraActorProxy::PicaCameraActorProxy()
{
   SetClassName(PicaCameraActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name 
}

///////////////////////////////////////////////////////////////////////////////
void PicaCameraActorProxy::BuildPropertyMap()
{
   const std::string Actor_GROUP = "Camera Properties"; //Property group name

   //dtDAL::ActorProxy::BuildPropertyMap();
   //TransformableActorProxy::BuildPropertyMap();
   //dtDAL::PhysicalActorProxy::BuildPropertyMap();
   //dtGame::GameActorProxy::BuildPropertyMap();
   dtActors::GameMeshActorProxy::BuildPropertyMap();

   PicaCameraActor* actor = static_cast<PicaCameraActor*>(GetActor());

  
	// "IsOn" property
	AddProperty(new dtDAL::BooleanActorProperty("IsOn","Power On",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &PicaCameraActor::SetPowerOn),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &PicaCameraActor::GetPowerOn),
		"Sets the camera of this actor on/off", Actor_GROUP));

	// "mCamSize" property
	AddProperty(new dtDAL::Vec2fActorProperty("mCamSize","Camera Screen Size",
		dtDAL::Vec2fActorProperty::SetFuncType(actor, &PicaCameraActor::SetCameraSize),
		dtDAL::Vec2fActorProperty::GetFuncType(actor, &PicaCameraActor::GetCameraSize),
		"Sets the cameras screen size", Actor_GROUP));

	// "mCamScrPos" property
	AddProperty(new dtDAL::Vec2fActorProperty("mCamScrPos","Camera Screen Position",
		dtDAL::Vec2fActorProperty::SetFuncType(actor, &PicaCameraActor::SetCameraScreenPosition),
		dtDAL::Vec2fActorProperty::GetFuncType(actor, &PicaCameraActor::GetCameraScreenPosition),
		"Sets the cameras position in the window", Actor_GROUP));
}

///////////////////////////////////////////////////////////////////////////////
void PicaCameraActorProxy::CreateActor()
{
   SetActor(*new PicaCameraActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void PicaCameraActorProxy::OnEnteredWorld()
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
   
   dtActors::GameMeshActorProxy::OnEnteredWorld();
}


#endif //VRS_PICATINNY_CAMERA_ACTOR_CPP