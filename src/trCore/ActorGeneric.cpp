/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Maxim Serebrennik
*/

#ifndef COREDLL_GENERIC_ACTOR_CPP
#define COREDLL_GENERIC_ACTOR_CPP

#include <trCore\ActorGeneric.h>

namespace trCore
{
	/////////////////////////////////////////////////////////////////////////////////
	//const std::string GenericActor::ACTOR_DEFAULT_NAME("Generic Actor");
	//const std::string GenericActor::ACTOR_CLASS_NAME("trCore::GenericActor");
	/////////////////////////////////////////////////////////////////////////////////
	//GenericActor::GenericActor(trCore::GameStaticMeshActorProxy& proxy)
	//	:trCore::GameStaticMeshActor(proxy)
	//	,mVelocity(0.0f)
	//	,mVelocityMax(100.0f)
	//	,mRLVelocity(0.0f)
	//	,mUDVelocity(0.0f)
	//	,mStrafeVelocityMax(30.0f)
	//	
	//	,mAccelDirection(0)
	//	
	//	,mPitchRate(0.0)
	//	,mPitchRateMax(50.0)
	//    
	//	,mTurnRate(0.0f)
	//	,mTurnRateMax(15.0f)
	//	,mTurnRateDirection(0.0f)
	//	
	//	,mRollRate(0.0f)
	//	,mRollRateMax(120.0f)
	//    
	//	,mIsEngineRunning(true)
	//	
	//	,mAutoLevelingStatus(false)
	//	,mAutoLevelingRate(10.0f)
	//	,mAutoLevelingSensitivity(0.1f)
	//  
	//	,mActorIsPlayer(false)
	//    
	//	,mPropertiesUpdated(false)

	//	,mDeg2RadVal(0)
	//	
	//{
	//   SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	//   SetDescription(ACTOR_DEFAULT_NAME); //Set the Actor Description

	//   mDeg2RadVal = ((3.14159265358979323846f)/180.0f);
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
	//{
	//   mDeltaSimTime = tickMessage.GetDeltaSimTime();

	//   ComputeVelocityAndTurn(mDeltaSimTime);
	//   
	//   if (mPropertiesUpdated)
	//   {
	//	  //GetGameActorProxy().NotifyFullActorUpdate();
	//	  mPropertiesUpdated = false;
	//   }

	//   MoveTheActor(mDeltaSimTime);
	//   

	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
	//{
	//   mDeltaSimTime = tickMessage.GetDeltaSimTime();

	//   // do NOT recompute velocity and turn rate since we don't own this actor!
	//   MoveTheActor(mDeltaSimTime);
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::ProcessMessage(const dtGame::Message& message)
	//{
	//	if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
	//	{
	//		const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

	//		if (eventMsg.GetGameEvent() != NULL)
	//		{
	//			// Handle "ToggleEngine" Game Event
	//			if (eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_IGNITION)
	//			{
	//				mIsEngineRunning = !mIsEngineRunning;
	//				#ifdef _DEBUG
	//					printf("Toggling Engines to the [%s] state.\r\n", (mIsEngineRunning ? "ON" : "OFF"));
	//				#endif //_DEBUG

	//			}
	//			// Handle "ToggleAutoLevel" Game Event
	//			if (eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_AUTOLEVEL)
	//			{
	//				mAutoLevelingStatus = !mAutoLevelingStatus;
	//				#ifdef _DEBUG
	//					printf("Toggling AutoLeveling to the [%s] state.\r\n", (mAutoLevelingStatus ? "ON" : "OFF"));
	//				#endif //_DEBUG
	//			}
	//			// Handle 'reset'  *******outdated neeeds fixing or removal*****
	//			//else if (eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_RESETSTUFF)
	//			//{
	//			//	// put the actor bank
	//			//	SetTransform(mOriginalPosition);
	//			//	mIsEngineRunning = false;
	//			//	mTurnRate = 0.0f;
	//			//	mVelocity = 0.0f;
	//			//	//mDust->SetEnabled(false);

	//			//	// put our camera back - first to actor's position, and then offset it.
	//			//	dtCore::Transform tx(0.0f,20.0f,2.0f,0.0f,0.0f,0.0f);
	//			//	dtCore::Camera* camera = GetGameActorProxy().GetGameManager()->GetApplication().GetCamera();
	//			//	//camera->SetTransform(mOriginalPosition, dtCore::Transformable::ABS_CS);
	//			//	camera->SetTransform(tx, dtCore::Transformable::REL_CS);
	//			//}
	//			//move back/forward
	//			if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_MOVEFORWARD)
	//			{
	//				mAccelDirection = 1.0f;
	//				
	//			}
	//			else if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_MOVEBACK)
	//			{
	//				mAccelDirection = -1.0f;
	//				
	//			}
	//			//strafe right/left
	//			if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_STRAFERIGHT)
	//			{
	//				mRLStrafeDirection = 1.0f;
	//				
	//			}
	//			else if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_STRAFELEFT)
	//			{
	//				mRLStrafeDirection = -1.0f;
	//				
	//			}
	//			//strafe up/down
	//			if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_STRAFEUP)
	//			{
	//				mUDStrafeDirection = 1.0f;
	//				
	//			}
	//			else if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_STRAFEDOWN)
	//			{
	//				mUDStrafeDirection = -1.0f;
	//				
	//			}
	//			//yaw right/left
	//			if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_YAWRIGHT)
	//			{
	//				mTurnRateDirection = -1.0f;
	//			}
	//			else if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_YAWLEFT)
	//			{
	//				mTurnRateDirection = 1.0f;
	//			}
	//			//pitch up/down
	//			if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_PITCHUP)
	//			{
	//				mPitchRateDirection = 1.0f;
	//			}
	//			else if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_PITCHDOWN)
	//			{
	//				mPitchRateDirection = -1.0f;
	//			}
	//			//roll right/left
	//			if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_ROLLRIGHT)
	//			{
	//				mRollRateDirection = -1.0f;
	//			}
	//			else if(eventMsg.GetGameEvent()->GetName() == trCore::GAME_EVENT_ROLLLEFT)
	//			{
	//				mRollRateDirection = 1.0f;
	//			}
	//		}
	//	}
	//	
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::ComputeVelocityAndTurn(float deltaSimTime)
	//{
	//	
	//   // calculate current velocity
	//   float decelDirection = (mVelocity >= 0.0) ? -1.0f : 1.0f;
	//   float acceleration = 0.0;

	//   // speed up based on user and current speed (ie, too fast)
	//   if (mIsEngineRunning && mAccelDirection != 0.0f)
	//   {
	//	   //  boosted too fast, slow down
	//	  if ((mAccelDirection > 0 && mVelocity > mVelocityMax) ||
	//			(mAccelDirection < 0 && mVelocity < -mVelocityMax))
	//	  {
	//		 acceleration = deltaSimTime*(mVelocityMax/3.0f)*decelDirection;
	//	  }
	//	  // hold speed
	//	  else if (mVelocity == mAccelDirection * mVelocityMax)
	//	  {
	//		 acceleration = 0;
	//	  }
	//	  // speed up normally - woot!
	//	  else
	//	  {
	//		 acceleration = mAccelDirection*deltaSimTime*(mVelocityMax/2.0f);
	//	  }

	//   }
	//   else if (mVelocity > -0.1 && mVelocity < 0.1)
	//   {
	//	  acceleration = -mVelocity; // close enough to 0, so just stop
	//   }
	//   else // coast to stop
	//   {
	//	  acceleration = deltaSimTime*(mVelocityMax/6.0f)*decelDirection;
	//   }

	//	if(!mIsEngineRunning)
	//	{
	//		mRLStrafeDirection = 0.0f;
	//		mUDStrafeDirection = 0.0f;   
	//	}
	//   
	//	//we update our velocities if the engine is on or off....
	//   SetVelocity(mVelocity + acceleration);
	//   SetStrafeRLVelocity(mStrafeVelocityMax * mRLStrafeDirection);
	//   SetStrafeUDVelocity(mStrafeVelocityMax * mUDStrafeDirection);
	//	

	//   if(mIsEngineRunning) 
	//   {
	//	   
	//	   SetTurnRate(mTurnRateMax * mTurnRateDirection);
	//	   SetPitchRate(mPitchRateMax * mPitchRateDirection);
	//	   SetRollRate(mRollRateMax * mRollRateDirection);
	//	   

	//	   if(mAutoLevelingStatus && !mPitchRateDirection && !mRollRateDirection)
	//	   {
	// 
	//	
	//			dtCore::Transform transform;
	//			float h, p, r;
	//			float temp_p_r;
	//			GetTransform(transform);

	//			mAutoLevelingRollRate  = mAutoLevelingRate;
	//			mAutoLevelingPitchRate  = mAutoLevelingRate;

	//			transform.GetRotation(h, p, r);
	//		
	//	
	//			//Auto level out the Roll angle
	//			temp_p_r = abs(r);
	//			while(temp_p_r<mAutoLevelingRollRate && temp_p_r >= mAutoLevelingSensitivity)
	//			{
	//				mAutoLevelingRollRate *= 0.5f;
	//			}

	//			
	//			if((r > (0+mAutoLevelingSensitivity)) && (r < (180.0)))
	//			{
	//				SetRollRate(mAutoLevelingRollRate * -1.0f);
	//			}
	//			else if((r > (-180.0)) && (r < (0-mAutoLevelingSensitivity))) 
	//			{
	//				SetRollRate(mAutoLevelingRollRate * 1.0f);
	//			}
	//			else
	//			{
	//				r = 0.0f;
	//				transform.SetRotation(h, p, r);
	//				SetTransform(transform);
	//			}


	//			
	//			//Auto level out the Pitch angle
	//			temp_p_r = abs(p);
	//			while(temp_p_r < mAutoLevelingPitchRate && temp_p_r >= mAutoLevelingSensitivity)
	//			{
	//				mAutoLevelingPitchRate *= 0.5;
	//			}
	//			
	//			if((p > (0+mAutoLevelingSensitivity)) && (p < (180.0)))
	//			{
	//				SetPitchRate(mAutoLevelingPitchRate * -1.0f);
	//			}
	//			else if((p > (-180.0)) && (p < (0-mAutoLevelingSensitivity))) 
	//			{
	//				SetPitchRate(mAutoLevelingPitchRate * 1.0f);
	//			}
	//			else
	//			{
	//				p = 0.0f;
	//				transform.SetRotation(h, p, r);
	//				SetTransform(transform);
	//			}


	//			#ifdef _DEBUG
	//				std::cerr << "AutoLeveling Vals: " << r << " " << p << std::endl;
	//			#endif //_DEBUG

	//			if((r > (0-mAutoLevelingSensitivity)) && r < (0+mAutoLevelingSensitivity) && 
	//				(p > (0-mAutoLevelingSensitivity)) && p < (0+mAutoLevelingSensitivity))
	//			{
	//				mAutoLevelingStatus = false;
	//				#ifdef _DEBUG
	//					std::cerr << "AutoLeveling is OFF" << std::endl;
	//				#endif //_DEBUG
	//			}
	//	   }
	//   }

	//   

	//   //reset our directions and rates to 
	//   //make sure we stop moving if we dont press anything
	//   
	//   mRLStrafeDirection = 0.0f;
	//   mUDStrafeDirection = 0.0f;
	//   mTurnRateDirection = 0.0f;
	//   mPitchRateDirection = 0.0f;
	//   mRollRateDirection = 0.0f;
	//   mAccelDirection = 0.0f;

	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::MoveTheActor(float deltaSimTime)
	//{
	//	osg::Vec3 pos;
	//	osg::Matrix rot;
	//	osg::Quat rotateX, rotateY, rotateZ, q;

	//	dtCore::Transform transform;
	//	GetTransform(transform);

	//	float DegCon = mDeg2RadVal * deltaSimTime;

	//	transform.GetRotation(rot);

	//	osg::Vec3f rightVector	= dtUtil::MatrixUtil::GetRow3(rot, 0);
	//	osg::Vec3f forwardVector= dtUtil::MatrixUtil::GetRow3(rot, 1);
	//	osg::Vec3f upVector		= dtUtil::MatrixUtil::GetRow3(rot, 2);

	//	rotateX.makeRotate((mPitchRate* DegCon), rightVector);    //rotate up/down
	//	upVector = rotateX * upVector;  //rotate axis up/down
	//	forwardVector = upVector ^ rightVector;

	//	rotateY.makeRotate((mRollRate * DegCon) , forwardVector);    //bank left/right
	//	rightVector = rotateY * rightVector;        //bank axis left/right
	//	upVector = rightVector ^ forwardVector;

	//	rotateZ.makeRotate((mTurnRate * DegCon), upVector);        //turn left/right
	//	forwardVector = rotateZ * forwardVector;    //turn axis left/right
	//	rightVector = forwardVector ^ upVector;

	//	rightVector.normalize();
	//	forwardVector.normalize();
	//	upVector.normalize();

	//	dtUtil::MatrixUtil::SetRow(rot, rightVector, 0);
	//	dtUtil::MatrixUtil::SetRow(rot, forwardVector, 1);
	//	dtUtil::MatrixUtil::SetRow(rot, upVector, 2);


	//	transform.GetTranslation(pos);

	//	pos = pos + (rightVector*(mRLVelocity*deltaSimTime)) //update our position vector
	//				+ (forwardVector*(mVelocity*deltaSimTime))
	//				+ (upVector*(mUDVelocity*deltaSimTime));

	//	transform.SetTranslation(pos);
	//	transform.SetRotation(rot);

	//	SetTransform(transform);

	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetVelocity(float velocity)
	//{
	//   mVelocity = velocity;

	//   if (!IsRemote())
	//   {
	//	   // Notify the world that our turn rate changed. Only changes on keypress
	//	   mPropertiesUpdated = true;
	//   }
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetVelocityMax(float velocity)
	//{
	//	
	//	if (mVelocityMax != velocity)
	//	{
	//		mVelocityMax=velocity;
	//		if (!IsRemote())
	//		{
	//			// Notify the world that our turn rate changed. Only changes on keypress
	//			mPropertiesUpdated = true;
	//		}
	//	}
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetStrafeRLVelocity(float velocity)
	//{
	//   mRLVelocity = velocity;

	//   if (!IsRemote())
	//   {
	//	   // Notify the world that our turn rate changed. Only changes on keypress
	//	   mPropertiesUpdated = true;
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetStrafeUDVelocity(float velocity)
	//{
	//   mUDVelocity = velocity;

	//   if (!IsRemote())
	//   {
	//	   // Notify the world that our turn rate changed. Only changes on keypress
	//	   mPropertiesUpdated = true;
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetStrafeVelocityMax(float velocity)
	//{
	//	
	//	if (mStrafeVelocityMax != velocity)
	//	{
	//		mStrafeVelocityMax=velocity;
	//		if (!IsRemote())
	//		{
	//			// Notify the world that our turn rate changed. Only changes on keypress
	//			mPropertiesUpdated = true;
	//		}
	//	}
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetTurnDirection(int direction)
	//{
	//	mTurnRateDirection = direction;
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetTurnRate(float rate)
	//{
	//	if (mTurnRate != rate)
	//   {
	//	  mTurnRate = rate;
	//	  if (!IsRemote())
	//	  {
	//		 // Notify the world that our turn rate changed. Only changes on keypress
	//		 mPropertiesUpdated = true;
	//	  }
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetTurnRateMax(float rate)
	//{
	//	if (mTurnRateMax != rate)
	//   {
	//	  mTurnRateMax = rate;
	//	  if (!IsRemote())
	//	  {
	//		 // Notify the world that our turn rate changed. Only changes on keypress
	//		 mPropertiesUpdated = true;
	//	  }
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetPitchRate(float rate)
	//{
	//	if (mPitchRate != rate)
	//   {
	//	  mPitchRate = rate;
	//	  if (!IsRemote())
	//	  {
	//		 // Notify the world that our turn rate changed. Only changes on keypress
	//		 mPropertiesUpdated = true;
	//	  }
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetPitchRateMax(float rate)
	//{
	//	if (mPitchRateMax != rate)
	//   {
	//	  mPitchRateMax = rate;
	//	  if (!IsRemote())
	//	  {
	//		 // Notify the world that our turn rate changed. Only changes on keypress
	//		 mPropertiesUpdated = true;
	//	  }
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetRollRate(float rate)
	//{
	//	if (mRollRate != rate)
	//   {
	//	  mRollRate = rate;
	//	  if (!IsRemote())
	//	  {
	//		 // Notify the world that our turn rate changed. Only changes on keypress
	//		 mPropertiesUpdated = true;
	//	  }
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetRollRateMax(float rate)
	//{
	//	if (mRollRateMax != rate)
	//   {
	//	  mRollRateMax = rate;
	//	  if (!IsRemote())
	//	  {
	//		 // Notify the world that our turn rate changed. Only changes on keypress
	//		 mPropertiesUpdated = true;
	//	  }
	//   }
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetAutoLevelingRate(float rate)
	//{
	//	if (mAutoLevelingRate != rate)
	//	{
	//	  mAutoLevelingRate = rate;

	//	  if (!IsRemote())
	//	  {
	//		 // Notify the world that our turn rate changed. 
	//		 mPropertiesUpdated = true;
	//	  }
	//	}

	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetActorIsPlayer(bool Player)
	//{
	//	mActorIsPlayer = Player;
	//	if (!IsRemote())
	//	{
	//		// Notify the world that our property has changed
	//		mPropertiesUpdated = true;
	//	}
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::SetCameraOffset(osg::Vec3 offset)
	//{
	//	mCameraOffset = offset;
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::OnEnteredWorld()
	//{
	//	trCore::GameStaticMeshActor::OnEnteredWorld();

	//	if(mActorIsPlayer)
	//	{
	//		FireSetPlayerMessage();

	//		FireSetFocusMessage();
	//	}
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::AddedToScene(dtCore::Scene* scene)
	//{
	//	#ifdef _DEBUG
	//	std::cout << "GenericActor::AddedToScene" << std::endl;
	//	#endif //_DEBUG

	//	trCore::GameStaticMeshActor::AddedToScene(scene);
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::FireSetPlayerMessage()
	//{
	//	dtCore::RefPtr<PlayerActorChangeMsg> playerActorChangeMsg;
	//   GetGameActorProxy().GetGameManager()->GetMessageFactory().CreateMessage(trCoreMessageType::MSG_PLAYER_ACTOR_CHANGE, playerActorChangeMsg);
	//   
	//   playerActorChangeMsg->SetAboutActorId(GetUniqueId());
	//   playerActorChangeMsg->SetNewPlayerActorUniqueId(GetUniqueId());

	//   GetGameActorProxy().GetGameManager()->SendMessage(*playerActorChangeMsg);
	//   
	//}
	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActor::FireSetFocusMessage()
	//{
	//   dtCore::RefPtr<FocusActorChangeMsg> focusActorChangeMsg;
	//   GetGameActorProxy().GetGameManager()->GetMessageFactory().CreateMessage(trCoreMessageType::MSG_FOCUS_ACTOR_CHANGE, focusActorChangeMsg);

	//   focusActorChangeMsg->SetAboutActorId(GetUniqueId());
	//   focusActorChangeMsg->SetNewFocusActorUniqueId(GetUniqueId());

	//   GetGameActorProxy().GetGameManager()->SendMessage(*focusActorChangeMsg);
	//}
	/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	//GenericActorProxy::GenericActorProxy()
	//{
	//	SetClassName(GenericActor::ACTOR_CLASS_NAME); //Set the actors Class Name
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActorProxy::BuildPropertyMap()
	//{
	//	const std::string Actor_GROUP = "Actor Properties"; //Property group name

	//	//dtDAL::ActorProxy::BuildPropertyMap();
	//	//TransformableActorProxy::BuildPropertyMap();
	//	//dtDAL::PhysicalActorProxy::BuildPropertyMap();
	//	//dtGame::GameActorProxy::BuildPropertyMap();
	//	//dtActors::GameMeshActorProxy::BuildPropertyMap();
	//	trCore::GameStaticMeshActorProxy::BuildPropertyMap();

	//	GenericActor* actor = static_cast<GenericActor*>(GetActor());
	//   
	//	// "Is Player" property
	//	AddProperty(new dtDAL::BooleanActorProperty("IsPlayer","Is Player",
	//		dtDAL::BooleanActorProperty::SetFuncType(actor, &GenericActor::SetActorIsPlayer),
	//		dtDAL::BooleanActorProperty::GetFuncType(actor, &GenericActor::GetActorIsPlayer),
	//		"Sets this actor as the main human player", Actor_GROUP));

	//	// "Camera Offset" property
	//	AddProperty(new dtDAL::Vec3ActorProperty("CameraOffset","Camera Offset",
	//		dtDAL::Vec3ActorProperty::SetFuncType(actor, &GenericActor::SetCameraOffset),
	//		dtDAL::Vec3ActorProperty::GetFuncType(actor, &GenericActor::GetCameraOffset),
	//		"Sets this actors Camera Offset", Actor_GROUP));

	//	// "Maximum Velocity" property
	//	AddProperty(new dtDAL::FloatActorProperty("MaxVelocity","Maximum Velocity (m/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetVelocityMax),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetVelocityMax),
	//		"Sets/gets the actors's maximum velocity in meeters per second.", Actor_GROUP));
	//   
	//	// "Velocity" property
	//	AddProperty(new dtDAL::FloatActorProperty("CurrentVelocity","Current Velocity (m/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetVelocity),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetVelocity),
	//		"Sets/gets the actors's current velocity in meeters per second.", Actor_GROUP));

	//	// "Maximum Strafing Velocity" property
	//	AddProperty(new dtDAL::FloatActorProperty("MaxStrafeVelocity","Maximum Strafing Velocity (m/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetStrafeVelocityMax),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetStrafeVelocityMax),
	//		"Sets/gets the actors's maximum strafing velocity in meeters per second.", Actor_GROUP));

	//	// "LR Strafing Velocity" property
	//	AddProperty(new dtDAL::FloatActorProperty("CurrentLRStrafeVelocity","Current Left/Right Strafing Velocity (m/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetStrafeRLVelocity),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetStrafeRLVelocity),
	//		"Sets/gets the actors's current right/left strafing velocity in meeters per second.", Actor_GROUP));

	//	// "UD Strafing Velocity" property
	//	AddProperty(new dtDAL::FloatActorProperty("CurrentUDStrafeVelocity","Current Up/Down Strafing Velocity (m/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetStrafeUDVelocity),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetStrafeUDVelocity),
	//		"Sets/gets the actors's current Up/Down strafing velocity in meeters per second.", Actor_GROUP));

	//	// "Maximum Turn Rate" property
	//	AddProperty(new dtDAL::FloatActorProperty("MaxTurnRate","Maximum Turn Rate (deg/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetTurnRateMax),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetTurnRateMax),
	//		"Sets/gets the actors's maximum turn rate in degrees per second.", Actor_GROUP));

	//	// "Turn Rate" property
	//	AddProperty(new dtDAL::FloatActorProperty("CurrentTurnRate","Current Turn Rate (deg/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetTurnRate),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetTurnRate),
	//		"Sets/gets the actors's current turn rate in degrees per second.", Actor_GROUP));

	//	// "Maximum Pitch Rate" property
	//	AddProperty(new dtDAL::FloatActorProperty("MaxPitchRate","Maximum Pitch Rate (deg/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetPitchRateMax),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetPitchRateMax),
	//		"Sets/gets the actors's maximum pitch rate in degrees per second.", Actor_GROUP));

	//	// "Pitch Rate" property
	//	AddProperty(new dtDAL::FloatActorProperty("CurrentPitchRate","Current Pitch Rate (deg/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetPitchRate),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetPitchRate),
	//		"Sets/gets the actors's current pitch rate in degrees per second.", Actor_GROUP));

	//	// "Maximum Roll Rate" property
	//	AddProperty(new dtDAL::FloatActorProperty("MaxRollRate","Maximum Roll Rate (deg/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetRollRateMax),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetRollRateMax),
	//		"Sets/gets the actors's maximum roll rate in degrees per second.", Actor_GROUP));

	//	// "Roll Rate" property
	//	AddProperty(new dtDAL::FloatActorProperty("CurrentRollRate","Current Roll Rate (deg/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetRollRate),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetRollRate),
	//		"Sets/gets the actors's current roll rate in degrees per second.", Actor_GROUP));

	//	// "Auto Leveling Rate" property
	//	AddProperty(new dtDAL::FloatActorProperty("AutoLevelingRate","Auto Leveling Rate (deg/sec)",
	//		dtDAL::FloatActorProperty::SetFuncType(actor, &GenericActor::SetAutoLevelingRate),
	//		dtDAL::FloatActorProperty::GetFuncType(actor, &GenericActor::GetAutoLevelingRate),
	//		"Sets/gets the actors's auto leveling rate in degrees per second.", Actor_GROUP));

	//	// Check if "static mesh" property exist.....
	//	dtDAL::ResourceActorProperty* ActopMeshProperty;
	//	GetProperty("static mesh", ActopMeshProperty);
	//	assert(ActopMeshProperty);

	//	// Automatically default the mesh to the one we want
	//	const dtDAL::ResourceDescriptor meshDescriptor("StaticMeshes:Vehicle:Space:AWing:AWing.ive");
	//	ActopMeshProperty->SetValue(meshDescriptor);
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActorProxy::CreateActor()
	//{
	//   SetActor(*new GenericActor(*this));
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void GenericActorProxy::OnEnteredWorld()
	//{
	//	#ifdef _DEBUG
	//	std::cout<< "GenericActorProxy::OnEnteredWorld" << std::endl;
	//	#endif //_DEBUG

	//	trCore::GameStaticMeshActorProxy::OnEnteredWorld();
	//	// Note we did not create any of these Invokables.  ProcessMessage(), TickLocal(),
	//	// and TickRemote() are created for us in GameActorProxy::BuildInvokables().

	//	//Register an invokable for Game Events...
	//	//RegisterForMessages(dtGame::MessageType::INFO_GAME_EVENT);
	//	RegisterForMessagesAboutSelf(dtGame::MessageType::INFO_GAME_EVENT);

	//	// Register an invokable for tick messages. Local or Remote only, not both!
	//	if (IsRemote())
	//	{
	//		RegisterForMessages(dtGame::MessageType::TICK_REMOTE,
	//		dtGame::GameActorProxy::TICK_REMOTE_INVOKABLE);
	//	}
	//	else
	//	{
	//		RegisterForMessages(dtGame::MessageType::TICK_LOCAL,
	//		dtGame::GameActorProxy::TICK_LOCAL_INVOKABLE);
	//	}
	//}
}


#endif //COREDLL_GENERIC_ACTOR_CPP