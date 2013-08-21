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

#ifndef COREDLL_SKYDOME_ACTOR_H
#define COREDLL_SKYDOME_ACTOR_H

#include "export.h"
//#include "..\\..\\vrsUtil_DLL\Include\vrsMath.h"
//#include "vrsCoreActorsRegistry.h"
//#include "vrsCoreMsgTypes.h"
#include "vrsCoreGameEvents.h"
#include "ActorGameStaticMesh.h"

#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/transform.h>
#include <dtCore/camera.h>
#include <dtCore/Scene.h>
#include <dtCore/system.h>

//#include <dtActors/gamemeshactor.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/actorproperty.h>
#include <dtDAL/actorproxyicon.h>
#include <dtDAL/actorproxy.h>

#include <dtGame/gamemanager.h>
#include <dtGame/actorupdatemessage.h>
#include <dtGame/basemessages.h>
#include <dtGame/messagetype.h>
#include <dtGame/message.h>

#include <dtABC/application.h>

#include <osg/Depth>
#include <osg/Fog>

namespace vrsCore
{

	class CORE_EXPORT SkyDomeActor : public vrsCore::GameStaticMeshActor
	{
	public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;
		static const std::string ACTOR_CLASS_NAME;
		
		// Constructs the actor.
		SkyDomeActor(vrsCore::GameStaticMeshActorProxy& proxy);

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
		
		// Called when the actor has been added to the game manager.
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();

		virtual void AddedToScene(dtCore::Scene* scene);

		//protected:
		virtual ~SkyDomeActor() { } ;

	private:

		// private vars
		float						mDeltaSimTime;		//sim time between frames

		dtCore::Transform			mCameraTransform;	//mTransform of the main Camera
		dtCore::Transform			mDomeTransform;		//mTransform of this Dome

		osg::Vec3f					mPos;				//Position vector

		bool						mPropertiesUpdated;
	};






	/**
	 * Our proxy class for the actor.  The proxy contains properties,
	 * invokables, and the actor.
	 */
	class CORE_EXPORT SkyDomeActorProxy : public vrsCore::GameStaticMeshActorProxy
	{
	   public:
		  // Constructs the proxy.
		  SkyDomeActorProxy();

		  // Creates the properties that are custom to the actor proxy.
		  virtual void BuildPropertyMap();

		  //Build Invokables to hook the proxy into the GM
		  //In this actor we will only use the default ones...
		  //virtual void BuildInvokables();

		  virtual ~SkyDomeActorProxy() { };

	   protected:
	      

		  // Creates an instance of our actor
		  virtual void CreateActor();

		  // Called when this proxy is added to the game manager (ie, the "world")
		  // You can respond to OnEnteredWorld on either the proxy or actor or both.
		  virtual void OnEnteredWorld();
	};
}

#endif //COREDLL_SKYDOME_ACTOR_H
