/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2013
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

#ifndef COREDLL_SKYDOME_ACTOR_H
#define COREDLL_SKYDOME_ACTOR_H

#include "export.h"
//#include "..\\..\\trUtil_DLL\Include\Math.h"
//#include "CoreActorsRegistry.h"
//#include "CoreMsgTypes.h"
#include "CoreGameEvents.h"
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

namespace trCore
{

	class TR_CORE_EXPORT SkyDomeActor : public trCore::GameStaticMeshActor
	{
	public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;
		static const std::string ACTOR_CLASS_NAME;
		
		// Constructs the actor.
		SkyDomeActor(trCore::GameStaticMeshActorProxy& proxy);

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
	class TR_CORE_EXPORT SkyDomeActorProxy : public trCore::GameStaticMeshActorProxy
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
