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
* @author Maxim Serebrennik and Brent Cox
*////////////////////////////////////////////////////////////////////////////////

#ifndef PHYSICS_GENERIC_ACTOR_H
#define PHYSICS_GENERIC_ACTOR_H

#include "export.h"
#include "..\\..\\vrsUtil_DLL\Include\vrsMath.h"
#include "../../vrsCore_DLL/Include/vrsCoreMsgTypes.h"
#include "../../vrsCore_DLL/Include/vrsCoreGameEvents.h"
#include "../../vrsCore_DLL/Include/ActorGameStaticMesh.h"

#include <assert.h>
#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/particlesystem.h>
#include <dtCore/isector.h>
#include <dtCore/transform.h>
#include <dtCore/loadable.h>
#include <dtCore/isector.h>
#include <dtCore/camera.h>
#include <dtCore/keyboard.h>
#include <dtCore/particlesystem.h>
#include <dtCore/flymotionmodel.h>
#include <dtCore/object.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/actorproperty.h>
#include <dtDAL/actorproxyicon.h>
#include <dtDAL/plugin_export.h>
#include <dtDAL/actorproxy.h>
#include <dtDAL/exceptionenum.h>

#include <dtGame/gamemanager.h>
#include <dtGame/actorupdatemessage.h>
#include <dtGame/basemessages.h>

#include <dtABC/application.h>

#include <dtUtil/nodecollector.h>
#include <dtUtil/matrixutil.h>
#include <dtUtil/mathdefines.h>

#include <osg/Vec3>

#include <osg/MatrixTransform>

#include <osgSim/DOFTransform>
#include <osgSim/DOFTransform>

#include <dtPhysics/physicshelper.h>
#include <dtPhysics/physicscomponent.h>
#include <dtPhysics/physicsmaterialactor.h>
#include <dtPhysics/palutil.h>
#include <dtPhysics/palphysicsworld.h>

#include <pal/pal.h>
#include <pal/palFactory.h>


class VRS_PACIFPHYSICS_EXPORT PhysicsGenericActor : public vrsCore::GameStaticMeshActor
{
	public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;

		//Default Actors Class Name
		static const std::string ACTOR_CLASS_NAME;

		// Constructs the actor.
		PhysicsGenericActor(vrsCore::GameStaticMeshActorProxy& proxy);

		/**
		* This method is an invokable for when a local object receives a tick.
		* @param tickMessage A message containing tick related information.
		*/
		virtual void OnTickLocal(const dtGame::TickMessage& tickMessage);

		/**
		* This method is an invokable for when a remote object receives a tick.
		* @param tickMessage A message containing tick related information.
		*/
		virtual void OnTickRemote(const dtGame::TickMessage& tickMessage);

		/**
		* Generic handler (Invokable) for messages. Overridden from base class.
		* This is the default invokable on GameActorProxy.
		*/
		virtual void ProcessMessage(const dtGame::Message& message);
	
		/**
		* Sets the velocity of our actor.
		* @param velocity The new velocity.
		* @note This may cause an actor update message
		*/
		void SetVelocity(float velocity);

		// @return The actor's current velocity.
		float GetVelocity() const { return mVelocity; }

		// Sets the actors Maximum Velocity.
		void SetVelocityMax(float velocity);

		// return the actors Maximum Velocity.
		float GetVelocityMax() const { return mVelocityMax; }

		/**
		* Sets the strafing velocity of our actor.
		* @param velocity The new velocity.
		* @note This may cause an actor update message
		*/
		void SetStrafeRLVelocity(float velocity);

		// @return The actor's current velocity.
		float GetStrafeRLVelocity() const { return mRLVelocity; }

		void SetStrafeUDVelocity(float velocity);

		// @return The actor's current velocity.
		float GetStrafeUDVelocity() const { return mUDVelocity; }

		// Sets the actors Maximum Velocity.
		void SetStrafeVelocityMax(float velocity);

		// return the actors Maximum Velocity.
		float GetStrafeVelocityMax() const { return mStrafeVelocityMax; }

		/**
		* Sets the Turn/Yaw rate of actor.
		* @param rate The new turn rate in degrees per second.
		* @note This may cause an actor update message
		*/
		void SetTurnRate(float rate);

		// @return The actor's turn rate.
		float GetTurnRate() const { return mTurnRate; }

		/**
		* Sets the Maximum Turn/Yaw rate of actor.
		* @param rate The new turn rate in degrees per second.
		* @note This may cause an actor update message
		*/
		void SetTurnRateMax(float rate);

		// @return The actor's Maximum turn rate.
		float GetTurnRateMax() const { return mTurnRateMax; }
		
		/**
		* Sets the direction of the turn
		* (-1=Left, 0=Stop, 1=Right)
		*/
		void SetTurnDirection(int direction);

		/**
		* Sets the Pitch rate of actor.
		* @param rate The new pitch rate in degrees per second.
		* @note This may cause an actor update message
		*/
		void SetPitchRate(float rate);

		// @return The actor's turn rate.
		float GetPitchRate() const { return mPitchRate; }

		/**
		* Sets the Maximum Pitch rate of actor.
		* @param rate The new pitch rate in degrees per second.
		* @note This may cause an actor update message
		*/
		void SetPitchRateMax(float rate);

		// @return The actor's Maximum turn rate.
		float GetPitchRateMax() const { return mPitchRateMax; }

		/**
		* Sets the Roll rate of actor.
		* @param rate The new roll rate in degrees per second.
		* @note This may cause an actor update message
		*/
		void SetRollRate(float rate);

		// @return The actor's roll rate.
		float GetRollRate() const { return mRollRate; }

		/**
		* Sets the Maximum roll rate of actor.
		* @param rate The new roll rate in degrees per second.
		* @note This may cause an actor update message
		*/
		void SetRollRateMax(float rate);

		// @return The actor's Maximum roll rate.
		float GetRollRateMax() const { return mRollRateMax; }


		/**
		* Sets the Auto Leveling Rate of actor.
		* @param rate The new Auto Leveling Rate in degrees per second.
		* @note This may cause an actor update message
		*/
		void SetAutoLevelingRate(float rate);

		// @return The actor's Auto Leveling Rate.
		float GetAutoLevelingRate() const { return mAutoLevelingRate; }

		//Set this actor as the main human player
		void SetActorIsPlayer(bool Player);

		//Check if the actor is the main human player
		bool GetActorIsPlayer(void) const { return mActorIsPlayer; }

		//Set sky box spin
		void SetSkyBoxSpin(bool skyBoxSpin) {mSkyBoxSpin = skyBoxSpin;}

		//Check if sky box spin
		bool GetSkyBoxSpin(void) const { return mSkyBoxSpin; }

		//Set the cameras offset for the player
		void SetCameraOffset(osg::Vec3 offset);

		//Get the cameras offset
		osg::Vec3 GetCameraOffset(void) { return mCameraOffset;}

		// Physics Stuff
		void SetUpPhysics();
		void BeforePhys();
		void AfterPhys();

		void RayHitCall(bool b, dtPhysics::RayCast::Report rep);

		//void TakeInput(char input);
		void ApplyDampForces();
		void MoveForward();
		void MoveBackward();
		void AntiGravity();


	  /**
	   * This is a method called by the game event invokable when a game
	   * event message is passed through the game manager.
	   * @param msg The message containing the game event.
	   */
	  //void HandleGameEvent(const dtGame::Message& msg);

	  // Called when the actor has been added to the game manager.
	  // You can respond to OnEnteredWorld on either the proxy or actor or both.
	  virtual void OnEnteredWorld();

   //protected:
	  virtual ~PhysicsGenericActor() { } ;

   private:
	  // do our internal velocity/turn calculations based on keyboard status
	  // only relevant for Local mode (ie, not when remote)
	  void ComputeVelocityAndTurn(float deltaSimTime);

	  // calculate new position based on turn rate and velocity
	  // relevant in both local and remote
	  void MoveTheActor(float deltaSimTime);

	  //Set this actor is the main human player
	  void FireSetPlayerMessage();

	  //Get the games focus for this actor
	  void FireSetFocusMessage();

	  // private vars
	  float mDeltaSimTime;			//sim time between frames

	  float mVelocity;				//curent forward velocity right now 
	  float mVelocityMax;			//max possible speed
	  float mAccelDirection;		//direction of the accell....back or forward...

	  float mRLVelocity;			//current Right/Left Strafing Velocity
	  float mRLStrafeDirection;		//direction of the Right/Left Strafing
	  float mUDVelocity;			//current Up/Down Strafing Velocity
	  float mUDStrafeDirection;		//direction of the Up/Down Strafing
	  float mStrafeVelocityMax;		//max Strafing Velocity
	  
	  float mPitchRate;				//curent pitch velocity right now
	  float mPitchRateMax;			//max possible speed
	  float mPitchRateDirection;	//direction of the pitch
	  float mRollRate;				//curent roll velocity right now
	  float mRollRateMax;			//max possible speed
	  float mRollRateDirection;		//direction of the roll
	  float mTurnRate;				//curent turn velocity right now
	  float mTurnRateMax;			//max possible speed
	  float mTurnRateDirection;		//direction of the turn
	  
	  float mAutoLevelingRate;		//Auto leveling current speed
	  float mAutoLevelingSensitivity;		//Auto leveling current Sensitivity
	  float mAutoLevelingRollRate;	//Intermediate Auto leveling roll rate
	  float mAutoLevelingPitchRate;	//Intermediate Auto leveling pictch rate
      
	  bool  mIsEngineRunning;		//status of Ignition toggle
	  bool  mAutoLevelingStatus;	//status of AutoLeveling toggle
	  
	  bool	mActorIsPlayer;			//marks an actor as the local player

	  osg::Vec3 mCameraOffset;		//holds the offset for the attached camera...

	  dtCore::Transform mOriginalPosition;

	  float mDeg2RadVal;
	  bool mPropertiesUpdated;

	  osg::ref_ptr<osgSim::DOFTransform> mDOFTran;

	  // Physics
	  dtPhysics::PhysicsHelper* mPhysHelper;
	  dtPhysics::PhysicsObject* mPhysObj;

	  bool mPhysicsHasStarted; // physics world has started
	  float mRotateAround;
	  bool mSkyBoxSpin;
	  bool bAntiGravity;
	  dtPhysics::PhysicsObject* mBoatBeingDriven;
	  bool bDriving;
	  //dtCore::ParticleSystem* mSplash;

};

/**
 * Our proxy class for the actor.  The proxy contains properties,
 * invokables, and the actor.
 */
class VRS_PACIFPHYSICS_EXPORT PhysicsGenericActorProxy : public vrsCore::GameStaticMeshActorProxy
{
   public:
	  // Constructs the proxy.
	  PhysicsGenericActorProxy();

	  // Creates the properties that are custom to the actor proxy.
	  virtual void BuildPropertyMap();

	  //Build Invokables to hook the proxy into the GM
	  //In this actor we will only use the default ones...
	  //virtual void BuildInvokables();

	  virtual ~PhysicsGenericActorProxy() { };

   protected:
      

	  // Creates an instance of our actor
	  virtual void CreateActor();

	  // Called when this proxy is added to the game manager (ie, the "world")
	  // You can respond to OnEnteredWorld on either the proxy or actor or both.
	  virtual void OnEnteredWorld();
};

#endif //PHYSICS_GENERIC_ACTOR_H
