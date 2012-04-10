/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////

#ifndef BOAT_ACTOR_CPP
#define BOAT_ACTOR_CPP

#include "../Include/ActorBoat.h"


///////////////////////////////////////////////////////////////////////////////
const std::string ActorBoat::ACTOR_DEFAULT_NAME("Boat Actor");
const std::string ActorBoat::ACTOR_CLASS_NAME("vrsPacifPhysics::ActorBoat");
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ActorBoat::ActorBoat(vrsCore::GameStaticMeshActorProxy& proxy)
	:vrsCore::GameStaticMeshActor(proxy)
	,mVelocity(0.0f)
	,mVelocityMax(100.0f)
	,mRLVelocity(0.0f)
	,mUDVelocity(0.0f)
	,mStrafeVelocityMax(30.0f)
	
	,mAccelDirection(0)
	
	,mPitchRate(0.0)
	,mPitchRateMax(50.0)
    
	,mTurnRate(0.0f)
	,mTurnRateMax(15.0f)
	,mTurnRateDirection(0.0f)
	
	,mRollRate(0.0f)
	,mRollRateMax(120.0f)
    
	,mIsEngineRunning(true)
	
	,mAutoLevelingStatus(false)
	,mAutoLevelingRate(10.0f)
	,mAutoLevelingSensitivity(0.1f)
  
	,mActorIsPlayer(false)
    
	,mPropertiesUpdated(false)

	,mDeg2RadVal(0)

	,mPhysicsHasStarted(false)
	,mRotateAround(0)
	,mSkyBoxSpin(false)
	,mOceanActor(NULL)
	,bFloating(false)
	,babiesMade(false)
	,mSplash(0)
{
   SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
   SetDescription(ACTOR_DEFAULT_NAME); //Set the Actor Description

   mDeg2RadVal = ((3.14159265358979323846f)/180.0f);
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::OnTickLocal(const dtGame::TickMessage& tickMessage)
{
   mDeltaSimTime = tickMessage.GetDeltaSimTime();

   ComputeVelocityAndTurn(mDeltaSimTime);
   if (mPropertiesUpdated)
   {
	  mPropertiesUpdated = false;
   }

   MoveTheActor(mDeltaSimTime);
   if (!mPhysicsHasStarted)
   {
		SetUpPhysics();
   }
   else
   {
	
	   // check for player physics
	   dtPhysics::PhysicsObject* phyObj = mPhysHelper->GetMainPhysicsObject();
	   if (phyObj == NULL)
	   {
		   std::cout << "Boat phyObj null" << std::endl;
	   }
	   else if (!(phyObj->IsActive()))
	   {
		   //std::cout << "Boat phyObj not active" << std::endl;
		   //SetUpPhysics();
		   phyObj->SetActive(true);
	   }
	   else
	   {
		   ApplyDampForces();
		   ApplyBuoyancy();
	   }
   }
	
   // to see skybox
   if (mSkyBoxSpin && mRotateAround < 420)
   {
	   if (mRotateAround < 60)
	   {
		   mRotateAround++;
		   return;
	   }
		dtCore::Transform transform;
		float h, p, r;

		GetTransform(transform);
		transform.GetRotation(h, p, r);

		transform.SetRotation(h + 20, p, r);
		SetTransform(transform);

		mRotateAround += 20;
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::ApplyDampForces()
{
	float dampening = 0.6;
	float lesserDampening = 0.995;
	dtCore::Transform xform;

	xform.MakeIdentity();
	GetGameActorProxy().GetGameManager()->GetApplication().GetCamera()->GetTransform(xform);
	dtPhysics::VectorType forward;
	xform.GetRow(1, forward);

	if (mVelocityMax < mPhysObj->GetLinearVelocity().length())
	{
		mPhysObj->SetLinearVelocity(mPhysObj->GetLinearVelocity() * dampening);
	}
	else if (mPhysObj->GetLinearVelocity().length() > 0)
	{
		mPhysObj->SetLinearVelocity(mPhysObj->GetLinearVelocity() * lesserDampening);
	}

}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::ApplyBuoyancy()
{
	float surfaceHeight;
	osg::Vec3 cornerPos1;
	float forceAmt = 8.0 * mPhysObj->GetMass();

	if (mOceanActor == NULL)
	{
		return;
	}

	cornerPos1 = mPhysObj->GetTranslation();
	surfaceHeight = mOceanActor->GetOceanSurfaceHeightAt(cornerPos1.x(),cornerPos1.y());

	//mPhysObj->AddForceAtPosition(cornerPos1, osg::Vec3(0, 0, forceAmt * (surfaceHeight - cornerPos1.z())));
	mPhysObj->AddForce(osg::Vec3(0, 0, forceAmt * (surfaceHeight - cornerPos1.z())));
	
	// for testing
	/*if (!babiesMade)
	{
		dtDAL::ActorProxy* actorProxy;
		GetGameActorProxy().GetGameManager()->FindPrototypeByName("HappySphereProt", actorProxy); 
		osg::ref_ptr<dtDAL::ActorProxy> actualActorProxy1 = GetGameActorProxy().GetGameManager()->CreateActorFromPrototype(actorProxy->GetId() );

		if( actualActorProxy1.valid())
		{
			cornerBaby1 = static_cast<PhysicsGenericActor*>(actualActorProxy1->GetActor());
			cornerBaby1->GetGameActorProxy().SetTranslation(cornerPos1);
			GetGameActorProxy().GetGameManager()->AddActor(cornerBaby1->GetGameActorProxy(), false, true);

			babiesMade = true;
		}
	}
	else
	{
		cornerBaby1->GetGameActorProxy().SetTranslation(cornerPos1);
	}*/

	if (mSplash)
	{
		dtCore::Transform splashXform;
		GetTransform(splashXform);

		/*float x = cos(GetGameActorProxy().GetRotation().x() * 0.0174532924);
		float y = sin(GetGameActorProxy().GetRotation().x() * 0.0174532924);

		splashXform.SetTranslation(splashXform.GetTranslation() + osg::Vec3(x, y, -2));*/
		mSplash->SetTransform(splashXform);

		if (surfaceHeight > cornerPos1.z())
		{
			//mSplash->SetEnabled(false);
		}
		else
		{
			mSplash->SetEnabled(true);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::OnTickRemote(const dtGame::TickMessage& tickMessage)
{
   mDeltaSimTime = tickMessage.GetDeltaSimTime();

   // do NOT recompute velocity and turn rate since we don't own this actor!
   MoveTheActor(mDeltaSimTime);
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
	{
		const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

		if (eventMsg.GetGameEvent() != NULL)
		{
			// Handle "ToggleEngine" Game Event
			if (eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_IGNITION)
			{
				mIsEngineRunning = !mIsEngineRunning;
				#ifdef _DEBUG
					printf("Toggling Engines to the [%s] state.\r\n", (mIsEngineRunning ? "ON" : "OFF"));
				#endif //_DEBUG

			}
			// Handle "ToggleAutoLevel" Game Event
			if (eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_AUTOLEVEL)
			{
				mAutoLevelingStatus = !mAutoLevelingStatus;
				#ifdef _DEBUG
					printf("Toggling AutoLeveling to the [%s] state.\r\n", (mAutoLevelingStatus ? "ON" : "OFF"));
				#endif //_DEBUG
			}
			// Handle 'reset'  *******outdated neeeds fixing or removal*****
			//else if (eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_RESETSTUFF)
			//{
			//	// put the actor bank
			//	SetTransform(mOriginalPosition);
			//	mIsEngineRunning = false;
			//	mTurnRate = 0.0f;
			//	mVelocity = 0.0f;
			//	//mDust->SetEnabled(false);

			//	// put our camera back - first to actor's position, and then offset it.
			//	dtCore::Transform tx(0.0f,20.0f,2.0f,0.0f,0.0f,0.0f);
			//	dtCore::Camera* camera = GetGameActorProxy().GetGameManager()->GetApplication().GetCamera();
			//	//camera->SetTransform(mOriginalPosition, dtCore::Transformable::ABS_CS);
			//	camera->SetTransform(tx, dtCore::Transformable::REL_CS);
			//}
			//move back/forward
			if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_MOVEFORWARD)
			{
				mAccelDirection = 1.0f;

				MoveForward();
			}
			else if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_MOVEBACK)
			{
				mAccelDirection = -1.0f;

				MoveBackward();
				
			}
			//strafe right/left
			if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_STRAFERIGHT)
			{
				mRLStrafeDirection = 1.0f;
				
			}
			else if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_STRAFELEFT)
			{
				mRLStrafeDirection = -1.0f;
				
			}
			//strafe up/down
			if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_STRAFEUP)
			{
				mUDStrafeDirection = 1.0f;
				
			}
			else if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_STRAFEDOWN)
			{
				mUDStrafeDirection = -1.0f;
				
			}
			//yaw right/left
			if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_YAWRIGHT)
			{
				mTurnRateDirection = -1.0f;
			}
			else if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_YAWLEFT)
			{
				mTurnRateDirection = 1.0f;
			}
			//pitch up/down
			if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_PITCHUP)
			{
				mPitchRateDirection = 1.0f;
			}
			else if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_PITCHDOWN)
			{
				mPitchRateDirection = -1.0f;
			}
			//roll right/left
			if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_ROLLRIGHT)
			{
				mRollRateDirection = -1.0f;
			}
			else if(eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_ROLLLEFT)
			{
				mRollRateDirection = 1.0f;
			}
		}
	}
}

void ActorBoat::SetUpPhysics()
{
	float collisionX;
	float collisionY;
	float collisionZ;

	dtPhysics::PhysicsComponent* physicsComponent = NULL;
	dtDAL::ActorProxy* proxy = NULL;

	GetGameActorProxy().GetGameManager()->GetComponentByName(dtPhysics::PhysicsComponent::DEFAULT_NAME, physicsComponent);
	GetGameActorProxy().GetGameManager()->FindActorByType(*OceanActorRegistry::OCEAN_ACTOR_TYPE, proxy);
	if (physicsComponent == NULL || proxy == NULL)
	{
		return;
	}

	mOceanActor = static_cast<dtOcean::OceanActor*>(proxy->GetActor());

	mPhysicsHasStarted = true;
	
	collisionX = GetBoundingBox().xMax() - GetBoundingBox().xMin();
	collisionY = GetBoundingBox().yMax() - GetBoundingBox().yMin();
	collisionZ = GetBoundingBox().zMax() - GetBoundingBox().zMin();

	dtCore::Transform xFormZero;
	dtCore::Transform xForm;

	xFormZero.SetRotation(osg::Matrix());
	GetTransform(xForm);
	SetTransform(xFormZero);

	dtUtil::BoundingBoxVisitor bbv;
	GetOSGNode()->accept(bbv);
	osg::Vec3 bound(bbv.mBoundingBox.xMax() - bbv.mBoundingBox.xMin(),
		bbv.mBoundingBox.yMax() - bbv.mBoundingBox.yMin(),
		(bbv.mBoundingBox.zMax() - bbv.mBoundingBox.zMin()) / 2);

	mPhysHelper = new dtPhysics::PhysicsHelper(GetGameActorProxy());
	mPhysObj = new dtPhysics::PhysicsObject();
	mPhysHelper->AddPhysicsObject(*mPhysObj);
	mPhysObj->SetPrimitiveType(dtPhysics::PrimitiveType::BOX);
	mPhysObj->SetExtents(bound);
	mPhysObj->SetMechanicsType(dtPhysics::MechanicsType::DYNAMIC);
	mPhysObj->SetCollisionGroup(7);
	mPhysObj->SetNotifyCollisions(true);
	mPhysObj->SetName("BoatPhysObj");
	mPhysObj->CreateFromProperties(GetOSGNode());
	mPhysObj->SetActive(true);
	mPhysObj->SetMass(50);

	physicsComponent->RegisterHelper(*mPhysHelper);

	mPhysHelper->SetPrePhysicsCallback(dtUtil::MakeFunctor(&ActorBoat::BeforePhys, this));
	mPhysHelper->SetPostPhysicsCallback(dtUtil::MakeFunctor(&ActorBoat::AfterPhys, this));

	SetTransform(xForm);
	mPhysObj->SetTransform(xForm);

	//mSplash = dtCore::ParticleSystem::GetInstance("Splash");
	if (mSplash)
	{
		mSplash->SetEnabled(true);
		dtCore::Transform xform2;
		GetTransform(xform2);
		mSplash->SetTransform(xform2);
	}
}

void ActorBoat::BeforePhys()
{
	dtCore::Transform xForm;
	GetTransform(xForm);
	mPhysObj->SetTransform(xForm);
}

void ActorBoat::AfterPhys()
{
	dtCore::Transform xForm;
	dtCore::Transform splashXform;
	mPhysObj->GetTransform(xForm);
	mPhysObj->GetTransform(splashXform);
	SetTransform(xForm);
	mPhysObj->SetAngularVelocity(osg::Vec3(0,0,0));

	/*if (mSplash)
	{
		splashXform.SetTranslation(splashXform.GetTranslation() + osg::Vec3(20, 0, -2));
		mSplash->SetTransform(splashXform);
	}*/
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::MoveForward()
{
	if (mPhysicsHasStarted)
	{
		dtCore::Transform xform;
		float forceVal = 100.0;
		int numReps = 60;

		xform.MakeIdentity();
		GetGameActorProxy().GetGameManager()->GetApplication().GetCamera()->GetTransform(xform);
		dtPhysics::VectorType forward;
		xform.GetRow(1, forward);
		dtPhysics::VectorType force(forward * forceVal);
		dtPhysics::VectorType dampForce(forward * (forceVal / numReps) * -1.0);
		mPhysObj->AddForce(force);
	}
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::MoveBackward()
{
	if (mPhysicsHasStarted)
	{
		dtCore::Transform xform;
		float forceVal = -100.0;

		xform.MakeIdentity();
		GetGameActorProxy().GetGameManager()->GetApplication().GetCamera()->GetTransform(xform);
		dtPhysics::VectorType forward;
		xform.GetRow(1, forward);
		dtPhysics::VectorType force(forward * forceVal);
		mPhysObj->AddForce(force);
	}
}
///////////////////////////////////////////////////////////////////////////////
//void PhysicsGenericActor::TakeInput(char input)
//{
//	if (mPhysicsHasStarted)
//	{
//		if (input == 'w')
//		{
//			//std::cout << "forward event" << std::endl;
//
//			dtCore::Transform xform;
//			float forceVal = 100.0;
//			int numReps = 60;
//
//			xform.MakeIdentity();
//			GetGameActorProxy().GetGameManager()->GetApplication().GetCamera()->GetTransform(xform);
//			dtPhysics::VectorType forward;
//			xform.GetRow(1, forward);
//			dtPhysics::VectorType force(forward * forceVal);
//			dtPhysics::VectorType dampForce(forward * (forceVal / numReps) * -1.0);
//			//std::cout << "forward force" << std::endl;
//			//mPhysObj->ApplyImpulse(force);
//			mPhysObj->AddForce(force);
//
//			//mDampForces.push_back(new PacifDampForce(dampForce, numReps));
//		}
//		else if (input == 's')
//		{
//			dtCore::Transform xform;
//			float forceVal = -100.0;
//
//			xform.MakeIdentity();
//			GetGameActorProxy().GetGameManager()->GetApplication().GetCamera()->GetTransform(xform);
//			dtPhysics::VectorType forward;
//			xform.GetRow(1, forward);
//			dtPhysics::VectorType force(forward * forceVal);
//			mPhysObj->AddForce(force);
//		}
//	}
//}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::ComputeVelocityAndTurn(float deltaSimTime)
{
	
   // calculate current velocity
   float decelDirection = (mVelocity >= 0.0) ? -1.0f : 1.0f;
   float acceleration = 0.0;

   // speed up based on user and current speed (ie, too fast)
   if (mIsEngineRunning && mAccelDirection != 0.0f)
   {
	   //  boosted too fast, slow down
	  if ((mAccelDirection > 0 && mVelocity > mVelocityMax) ||
			(mAccelDirection < 0 && mVelocity < -mVelocityMax))
	  {
		 acceleration = deltaSimTime*(mVelocityMax/3.0f)*decelDirection;
	  }
	  // hold speed
	  else if (mVelocity == mAccelDirection * mVelocityMax)
	  {
		 acceleration = 0;
	  }
	  // speed up normally - woot!
	  else
	  {
		 acceleration = mAccelDirection*deltaSimTime*(mVelocityMax/2.0f);
	  }

   }
   else if (mVelocity > -0.1 && mVelocity < 0.1)
   {
	  acceleration = -mVelocity; // close enough to 0, so just stop
   }
   else // coast to stop
   {
	  acceleration = deltaSimTime*(mVelocityMax/6.0f)*decelDirection;
   }

	if(!mIsEngineRunning)
	{
		mRLStrafeDirection = 0.0f;
		mUDStrafeDirection = 0.0f;   
	}
   
	//we update our velocities if the engine is on or off....
   SetVelocity(mVelocity + acceleration);
   SetStrafeRLVelocity(mStrafeVelocityMax * mRLStrafeDirection);
   SetStrafeUDVelocity(mStrafeVelocityMax * mUDStrafeDirection);
	

   if(mIsEngineRunning) 
   {
	   
	   SetTurnRate(mTurnRateMax * mTurnRateDirection);
	   SetPitchRate(mPitchRateMax * mPitchRateDirection);
	   SetRollRate(mRollRateMax * mRollRateDirection);
	   

	   if(mAutoLevelingStatus && !mPitchRateDirection && !mRollRateDirection)
	   {
 
	
			dtCore::Transform transform;
			float h, p, r;
			float temp_p_r;
			GetTransform(transform);

			mAutoLevelingRollRate  = mAutoLevelingRate;
			mAutoLevelingPitchRate  = mAutoLevelingRate;

			transform.GetRotation(h, p, r);
		
	
			//Auto level out the Roll angle
			temp_p_r = abs(r);
			while(temp_p_r<mAutoLevelingRollRate && temp_p_r >= mAutoLevelingSensitivity)
			{
				mAutoLevelingRollRate *= 0.5f;
			}

			
			if((r > (0+mAutoLevelingSensitivity)) && (r < (180.0)))
			{
				SetRollRate(mAutoLevelingRollRate * -1.0f);
			}
			else if((r > (-180.0)) && (r < (0-mAutoLevelingSensitivity))) 
			{
				SetRollRate(mAutoLevelingRollRate * 1.0f);
			}
			else
			{
				r = 0.0f;
				transform.SetRotation(h, p, r);
				SetTransform(transform);
			}


			
			//Auto level out the Pitch angle
			temp_p_r = abs(p);
			while(temp_p_r < mAutoLevelingPitchRate && temp_p_r >= mAutoLevelingSensitivity)
			{
				mAutoLevelingPitchRate *= 0.5;
			}
			
			if((p > (0+mAutoLevelingSensitivity)) && (p < (180.0)))
			{
				SetPitchRate(mAutoLevelingPitchRate * -1.0f);
			}
			else if((p > (-180.0)) && (p < (0-mAutoLevelingSensitivity))) 
			{
				SetPitchRate(mAutoLevelingPitchRate * 1.0f);
			}
			else
			{
				p = 0.0f;
				transform.SetRotation(h, p, r);
				SetTransform(transform);
			}


			#ifdef _DEBUG
				std::cerr << "AutoLeveling Vals: " << r << " " << p << std::endl;
			#endif //_DEBUG

			if((r > (0-mAutoLevelingSensitivity)) && r < (0+mAutoLevelingSensitivity) && 
				(p > (0-mAutoLevelingSensitivity)) && p < (0+mAutoLevelingSensitivity))
			{
				mAutoLevelingStatus = false;
				#ifdef _DEBUG
					std::cerr << "AutoLeveling is OFF" << std::endl;
				#endif //_DEBUG
			}
	   }
   }

   

   //reset our directions and rates to 
   //make sure we stop moving if we dont press anything
   
   mRLStrafeDirection = 0.0f;
   mUDStrafeDirection = 0.0f;
   mTurnRateDirection = 0.0f;
   mPitchRateDirection = 0.0f;
   mRollRateDirection = 0.0f;
   mAccelDirection = 0.0f;

}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::MoveTheActor(float deltaSimTime)
{
	osg::Vec3 pos;
	osg::Matrix rot;
	osg::Quat rotateX, rotateY, rotateZ, q;

	dtCore::Transform transform;
	GetTransform(transform);

	float DegCon = mDeg2RadVal * deltaSimTime;

	transform.GetRotation(rot);

	osg::Vec3f rightVector	= dtUtil::MatrixUtil::GetRow3(rot, 0);
	osg::Vec3f forwardVector= dtUtil::MatrixUtil::GetRow3(rot, 1);
	osg::Vec3f upVector		= dtUtil::MatrixUtil::GetRow3(rot, 2);

	rotateX.makeRotate((mPitchRate* DegCon), rightVector);    //rotate up/down
	upVector = rotateX * upVector;  //rotate axis up/down
	forwardVector = upVector ^ rightVector;

	rotateY.makeRotate((mRollRate * DegCon) , forwardVector);    //bank left/right
	rightVector = rotateY * rightVector;        //bank axis left/right
	upVector = rightVector ^ forwardVector;

	rotateZ.makeRotate((mTurnRate * DegCon), upVector);        //turn left/right
	forwardVector = rotateZ * forwardVector;    //turn axis left/right
	rightVector = forwardVector ^ upVector;

	rightVector.normalize();
	forwardVector.normalize();
	upVector.normalize();

	dtUtil::MatrixUtil::SetRow(rot, rightVector, 0);
	dtUtil::MatrixUtil::SetRow(rot, forwardVector, 1);
	dtUtil::MatrixUtil::SetRow(rot, upVector, 2);


	transform.GetTranslation(pos);

	//pos = pos + (rightVector*(mRLVelocity*deltaSimTime)) //update our position vector
	//			+ (forwardVector*(mVelocity*deltaSimTime))
	//			+ (upVector*(mUDVelocity*deltaSimTime));

	transform.SetTranslation(pos);
	transform.SetRotation(rot);

	SetTransform(transform);

}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetVelocity(float velocity)
{
   mVelocity = velocity;

   if (!IsRemote())
   {
	   // Notify the world that our turn rate changed. Only changes on keypress
	   mPropertiesUpdated = true;
   }
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetVelocityMax(float velocity)
{
	
	if (mVelocityMax != velocity)
	{
		mVelocityMax=velocity;
		if (!IsRemote())
		{
			// Notify the world that our turn rate changed. Only changes on keypress
			mPropertiesUpdated = true;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetStrafeRLVelocity(float velocity)
{
   mRLVelocity = velocity;

   if (!IsRemote())
   {
	   // Notify the world that our turn rate changed. Only changes on keypress
	   mPropertiesUpdated = true;
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetStrafeUDVelocity(float velocity)
{
   mUDVelocity = velocity;

   if (!IsRemote())
   {
	   // Notify the world that our turn rate changed. Only changes on keypress
	   mPropertiesUpdated = true;
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetStrafeVelocityMax(float velocity)
{
	
	if (mStrafeVelocityMax != velocity)
	{
		mStrafeVelocityMax=velocity;
		if (!IsRemote())
		{
			// Notify the world that our turn rate changed. Only changes on keypress
			mPropertiesUpdated = true;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetTurnDirection(int direction)
{
	mTurnRateDirection = direction;
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetTurnRate(float rate)
{
	if (mTurnRate != rate)
   {
	  mTurnRate = rate;
	  if (!IsRemote())
	  {
		 // Notify the world that our turn rate changed. Only changes on keypress
		 mPropertiesUpdated = true;
	  }
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetTurnRateMax(float rate)
{
	if (mTurnRateMax != rate)
   {
	  mTurnRateMax = rate;
	  if (!IsRemote())
	  {
		 // Notify the world that our turn rate changed. Only changes on keypress
		 mPropertiesUpdated = true;
	  }
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetPitchRate(float rate)
{
	if (mPitchRate != rate)
   {
	  mPitchRate = rate;
	  if (!IsRemote())
	  {
		 // Notify the world that our turn rate changed. Only changes on keypress
		 mPropertiesUpdated = true;
	  }
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetPitchRateMax(float rate)
{
	if (mPitchRateMax != rate)
   {
	  mPitchRateMax = rate;
	  if (!IsRemote())
	  {
		 // Notify the world that our turn rate changed. Only changes on keypress
		 mPropertiesUpdated = true;
	  }
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetRollRate(float rate)
{
	if (mRollRate != rate)
   {
	  mRollRate = rate;
	  if (!IsRemote())
	  {
		 // Notify the world that our turn rate changed. Only changes on keypress
		 mPropertiesUpdated = true;
	  }
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetRollRateMax(float rate)
{
	if (mRollRateMax != rate)
   {
	  mRollRateMax = rate;
	  if (!IsRemote())
	  {
		 // Notify the world that our turn rate changed. Only changes on keypress
		 mPropertiesUpdated = true;
	  }
   }
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetAutoLevelingRate(float rate)
{
	if (mAutoLevelingRate != rate)
	{
	  mAutoLevelingRate = rate;

	  if (!IsRemote())
	  {
		 // Notify the world that our turn rate changed. 
		 mPropertiesUpdated = true;
	  }
	}

}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetActorIsPlayer(bool Player)
{
	mActorIsPlayer = Player;
	if (!IsRemote())
	{
		// Notify the world that our property has changed
		mPropertiesUpdated = true;
	}
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::SetCameraOffset(osg::Vec3 offset)
{
	mCameraOffset = offset;
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::OnEnteredWorld()
{
	vrsCore::GameStaticMeshActor::OnEnteredWorld();

	if(mActorIsPlayer)
	{
		FireSetPlayerMessage();

		FireSetFocusMessage();
	}
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoat::FireSetPlayerMessage()
{
	dtCore::RefPtr<vrsCore::PlayerActorChangeMsg> playerActorChangeMsg;
   GetGameActorProxy().GetGameManager()->GetMessageFactory().CreateMessage(vrsCore::vrsCoreMessageType::MSG_PLAYER_ACTOR_CHANGE, playerActorChangeMsg);
   
   playerActorChangeMsg->SetAboutActorId(GetUniqueId());
   playerActorChangeMsg->SetNewPlayerActorUniqueId(GetUniqueId());

   GetGameActorProxy().GetGameManager()->SendMessage(*playerActorChangeMsg);
   
}
///////////////////////////////////////////////////////////////////////////////
void ActorBoat::FireSetFocusMessage()
{
   dtCore::RefPtr<vrsCore::FocusActorChangeMsg> focusActorChangeMsg;
   GetGameActorProxy().GetGameManager()->GetMessageFactory().CreateMessage(vrsCore::vrsCoreMessageType::MSG_FOCUS_ACTOR_CHANGE, focusActorChangeMsg);

   focusActorChangeMsg->SetAboutActorId(GetUniqueId());
   focusActorChangeMsg->SetNewFocusActorUniqueId(GetUniqueId());

   GetGameActorProxy().GetGameManager()->SendMessage(*focusActorChangeMsg);
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ActorBoatProxy::ActorBoatProxy()
{
	SetClassName(ActorBoat::ACTOR_CLASS_NAME); //Set the actors Class Name
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoatProxy::BuildPropertyMap()
{
	const std::string Actor_GROUP = "Actor Properties"; //Property group name

	//dtDAL::ActorProxy::BuildPropertyMap();
	//TransformableActorProxy::BuildPropertyMap();
	//dtDAL::PhysicalActorProxy::BuildPropertyMap();
	//dtGame::GameActorProxy::BuildPropertyMap();
	//dtActors::GameMeshActorProxy::BuildPropertyMap();
	vrsCore::GameStaticMeshActorProxy::BuildPropertyMap();

	ActorBoat* actor = static_cast<ActorBoat*>(GetActor());
   
	// "Is Player" property
	AddProperty(new dtDAL::BooleanActorProperty("IsPlayer","Is Player",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &ActorBoat::SetActorIsPlayer),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &ActorBoat::GetActorIsPlayer),
		"Sets this actor as the main human player", Actor_GROUP));

	// "Initial Spin" property
	AddProperty(new dtDAL::BooleanActorProperty("SkyBoxSpin","Sky Box Spin",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &ActorBoat::SetSkyBoxSpin),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &ActorBoat::GetSkyBoxSpin),
		"Enable/Disable Initial Spin for Sky Box viewing", Actor_GROUP));

	// "Camera Offset" property
	AddProperty(new dtDAL::Vec3ActorProperty("CameraOffset","Camera Offset",
		dtDAL::Vec3ActorProperty::SetFuncType(actor, &ActorBoat::SetCameraOffset),
		dtDAL::Vec3ActorProperty::GetFuncType(actor, &ActorBoat::GetCameraOffset),
		"Sets this actors Camera Offset", Actor_GROUP));

	// "Maximum Velocity" property
	AddProperty(new dtDAL::FloatActorProperty("MaxVelocity","Maximum Velocity (m/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetVelocityMax),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetVelocityMax),
		"Sets/gets the actors's maximum velocity in meeters per second.", Actor_GROUP));
   
	// "Velocity" property
	AddProperty(new dtDAL::FloatActorProperty("CurrentVelocity","Current Velocity (m/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetVelocity),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetVelocity),
		"Sets/gets the actors's current velocity in meeters per second.", Actor_GROUP));

	// "Maximum Strafing Velocity" property
	AddProperty(new dtDAL::FloatActorProperty("MaxStrafeVelocity","Maximum Strafing Velocity (m/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetStrafeVelocityMax),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetStrafeVelocityMax),
		"Sets/gets the actors's maximum strafing velocity in meeters per second.", Actor_GROUP));

	// "LR Strafing Velocity" property
	AddProperty(new dtDAL::FloatActorProperty("CurrentLRStrafeVelocity","Current Left/Right Strafing Velocity (m/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetStrafeRLVelocity),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetStrafeRLVelocity),
		"Sets/gets the actors's current right/left strafing velocity in meeters per second.", Actor_GROUP));

	// "UD Strafing Velocity" property
	AddProperty(new dtDAL::FloatActorProperty("CurrentUDStrafeVelocity","Current Up/Down Strafing Velocity (m/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetStrafeUDVelocity),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetStrafeUDVelocity),
		"Sets/gets the actors's current Up/Down strafing velocity in meeters per second.", Actor_GROUP));

	// "Maximum Turn Rate" property
	AddProperty(new dtDAL::FloatActorProperty("MaxTurnRate","Maximum Turn Rate (deg/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetTurnRateMax),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetTurnRateMax),
		"Sets/gets the actors's maximum turn rate in degrees per second.", Actor_GROUP));

	// "Turn Rate" property
	AddProperty(new dtDAL::FloatActorProperty("CurrentTurnRate","Current Turn Rate (deg/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetTurnRate),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetTurnRate),
		"Sets/gets the actors's current turn rate in degrees per second.", Actor_GROUP));

	// "Maximum Pitch Rate" property
	AddProperty(new dtDAL::FloatActorProperty("MaxPitchRate","Maximum Pitch Rate (deg/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetPitchRateMax),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetPitchRateMax),
		"Sets/gets the actors's maximum pitch rate in degrees per second.", Actor_GROUP));

	// "Pitch Rate" property
	AddProperty(new dtDAL::FloatActorProperty("CurrentPitchRate","Current Pitch Rate (deg/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetPitchRate),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetPitchRate),
		"Sets/gets the actors's current pitch rate in degrees per second.", Actor_GROUP));

	// "Maximum Roll Rate" property
	AddProperty(new dtDAL::FloatActorProperty("MaxRollRate","Maximum Roll Rate (deg/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetRollRateMax),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetRollRateMax),
		"Sets/gets the actors's maximum roll rate in degrees per second.", Actor_GROUP));

	// "Roll Rate" property
	AddProperty(new dtDAL::FloatActorProperty("CurrentRollRate","Current Roll Rate (deg/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetRollRate),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetRollRate),
		"Sets/gets the actors's current roll rate in degrees per second.", Actor_GROUP));

	// "Auto Leveling Rate" property
	AddProperty(new dtDAL::FloatActorProperty("AutoLevelingRate","Auto Leveling Rate (deg/sec)",
		dtDAL::FloatActorProperty::SetFuncType(actor, &ActorBoat::SetAutoLevelingRate),
		dtDAL::FloatActorProperty::GetFuncType(actor, &ActorBoat::GetAutoLevelingRate),
		"Sets/gets the actors's auto leveling rate in degrees per second.", Actor_GROUP));

	// Check if "static mesh" property exist.....
	dtDAL::ResourceActorProperty* ActopMeshProperty;
	GetProperty("static mesh", ActopMeshProperty);
	assert(ActopMeshProperty);

	// Automatically default the mesh to the one we want
	dtDAL::ResourceDescriptor meshDescriptor("StaticMeshes:Vehicle:Space:AWing:AWing.ive");
	ActopMeshProperty->SetValue(&meshDescriptor);
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoatProxy::CreateActor()
{
   SetActor(*new ActorBoat(*this));
}

///////////////////////////////////////////////////////////////////////////////
void ActorBoatProxy::OnEnteredWorld()
{
	vrsCore::GameStaticMeshActorProxy::OnEnteredWorld();
	// Note we did not create any of these Invokables.  ProcessMessage(), TickLocal(),
	// and TickRemote() are created for us in GameActorProxy::BuildInvokables().

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

	SetBoxCollision();
}

#endif //BOAT_ACTOR_CPP