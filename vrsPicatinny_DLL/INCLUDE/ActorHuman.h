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


#ifndef VRS_PICATINNY_HUMAN_ACTOR_H
#define VRS_PICATINNY_HUMAN_ACTOR_H

#include "export.h"
#include "ActorPicaCamera.h"
#include "vrsPicatinnyActorsRegistry.h"

#include <iostream>

#include <dtUtil/datapathutils.h>

#include <dtAnim/AnimationGameActor.h>
#include <dtAnim/Cal3DDatabase.h>
#include <dtAnim/AnimNodeBuilder.h>

#include <dtCore/refptr.h>
#include <dtCore/particlesystem.h>
#include <dtCore/transform.h>
#include <dtCore/object.h>

#include <dtGame/basemessages.h>
#include <dtGame/gamemanager.h>

#include <dtDAL/actorproxyicon.h>
#include <dtDAL/enginepropertytypes.h>


class VRS_PICATINNY_EXPORT HumanActor : public dtAnim::AnimationGameActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	/// Constructor
	HumanActor(dtAnim::AnimationGameActorProxy& proxy);

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
    * This is a method called by the game event invokable when a game
    * event message is passed through the game manager.
    * @param msg The message containing the game event.
    */
    void HandleGameEvent(const dtGame::Message& msg);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

	virtual void killCamera();

	
protected:

	// Destructor
    virtual ~HumanActor() { } ;

private:

	float	mDeltaSimTime;			//sim time between frames
	
	bool	mPropertiesUpdated;		//set to true if a property changed....

	bool	mBeingTracked;

	bool	mCamIsDead;				//togle if the cam is dead
};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_PICATINNY_EXPORT HumanActorProxy : public dtAnim::AnimationGameActorProxy
{
public:

	/**
    * Constructor
    */
    HumanActorProxy();

	// Creates the properties that are custom to the actor proxy.
	virtual void BuildPropertyMap();



protected:

	/**
    * Destructor
    */
    virtual ~HumanActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

private:


};


#endif //VRS_PICATINNY_HUMAN_ACTOR_H
