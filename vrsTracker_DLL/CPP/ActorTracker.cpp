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

#ifndef VRS_TRACKER_ACTOR_CPP
#define VRS_TRACKER_ACTOR_CPP

#include "..\\Include\ActorTracker.h"

///////////////////////////////////////////////////////////////////////////////
const std::string TrackerActor::ACTOR_DEFAULT_NAME("Tracker Actor");
///////////////////////////////////////////////////////////////////////////////

TrackerActor::TrackerActor(dtActors::GameMeshActorProxy& proxy)
:dtActors::GameMeshActor(proxy)
,mLastUpdate(-1)
,mEventId(-1)
,mActorId(GetUniqueId())
,mVelocity(0)
,mAvgWindowSize(0)
{

	SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//Set the Actor Description
	SetDescription("Stevens Institute of Technology Camera Tracker Actor"); 
}

///////////////////////////////////////////////////////////////////////////////
void TrackerActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
{
	//every tick update the position according to its current velocity and direction
	mDeltaSimTime = tickMessage.GetDeltaSimTime();
	dtCore::Transform tx;
	osg::Matrix mat;
	osg::Quat q;
	osg::Vec3 viewDir;

	GetTransform(tx);
	osg::Vec3 pos;
	tx.GetTranslation(pos);
	tx.GetRotation(mat);
	mat.get(q);
	viewDir = q * osg::Vec3(0,1,0);

	// translate the player along its current view direction based on current velocity
	tx.GetTranslation(pos);
	pos = pos + (viewDir*(mVelocity*mDeltaSimTime));


	tx.SetTranslation(pos);
	SetTransform(tx);
	
   

}

///////////////////////////////////////////////////////////////////////////////
void TrackerActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
{
	mDeltaSimTime = tickMessage.GetDeltaSimTime();
}

///////////////////////////////////////////////////////////////////////////////
void TrackerActor::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
	{
		const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

	}
}
///////////////////////////////////////////////////////////////////////////////
void TrackerActor::OnEnteredWorld()
{
	dtActors::GameMeshActor::OnEnteredWorld();
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
TrackerActorProxy::TrackerActorProxy()
{
   SetClassName(TrackerActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
}

///////////////////////////////////////////////////////////////////////////////
void TrackerActorProxy::BuildPropertyMap()
{
   const std::string Actor_GROUP = "Actor Properties"; //Property group name

   //dtDAL::ActorProxy::BuildPropertyMap();
   //TransformableActorProxy::BuildPropertyMap();
   //dtDAL::PhysicalActorProxy::BuildPropertyMap();
   //dtGame::GameActorProxy::BuildPropertyMap();
   dtActors::GameMeshActorProxy::BuildPropertyMap();

   TrackerActor* actor = static_cast<TrackerActor*>(GetActor());

   // "Is Player" property
	/*AddProperty(new dtDAL::BooleanActorProperty("IsPlayer","Is Player",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &GenericActor::SetActorIsPlayer),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &GenericActor::GetActorIsPlayer),
		"Sets this actor as the main human player", Actor_GROUP));*/

}

///////////////////////////////////////////////////////////////////////////////
void TrackerActorProxy::CreateActor()
{
   SetActor(*new TrackerActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void TrackerActorProxy::OnEnteredWorld()
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

//got a new position from the event_log, add it to history
//if it's time, computer the historical average, move the boat there, and update the
//velocity and rotation vectors
void TrackerActor::UpdatePosition(osg::Vec3f pos,float time){
	pos=TransformPosition(pos);		//move to world coordinates
	dtCore::Transform tx;

	//if this is the first event, move actor to this position and return
	if(mHistory.empty()){
		AddToHistory(pos);
		mLastPos=pos;
		GetTransform(tx);
		tx.SetTranslation(pos);	
		SetTransform(tx);
		mLastUpdate=time;
		return;
	}
	
	AddToHistory(pos);	//add point to the history	
	float timepass=time-mLastUpdate;	//find out in simulation time how long its been since the last averaged point

	if(timepass>=mAvgWindowSize){   //if enough time passed since last update, find the average position since last update
		osg::Vec3 npt=mHistory.back();
		int count=1;
		int hsize=mHistory.size();
		for(int i =hsize-2;i>=hsize-mAvgWindowSize;i--){
			if(i<0)
				break;
			else{
				npt+=mHistory[i];
				count++;
			}
		}
		
		npt/=count;		//computes average position

		GetTransform(tx);
		tx.SetTranslation(npt);	//update position to the averaged position

		
		osg::Vec3 viewDir;
		osg::Vec3f disp=npt-mLastPos;		//displacement vector from last avg position to this avg position
		mVelocity=disp.length()/timepass;	//compute velocity of that distance over time between avg positions

		//direction of displacement vector and use to set rotation
		tx.GetRotation(viewDir);
		if(mVelocity==0)
			viewDir[0]=viewDir[0];
		else
			viewDir[0]=atan2(disp[1],disp[0])*180.0f/3.14159265-90.0f;
		
		tx.SetRotation(viewDir);
		SetTransform(tx);

		mLastUpdate=time;	//change last updated time and last updated avg position
		mLastPos=npt;
		
	}

}


void TrackerActor::SetAvgWindowSize(int sz){
	mAvgWindowSize=sz;
}
void TrackerActor::AddToHistory(osg::Vec3f pos){
	mHistory.push_back(pos);
}

void TrackerActor::SetOrigin(osg::Vec3f pos){
	mOrigin[0]=pos[0];
	mOrigin[1]=pos[1];
}

osg::Vec3f TrackerActor::TransformPosition(osg::Vec3f pt){
	return (pt-mOrigin);
}


#endif //VRS_TRACKER_ACTOR_CPP