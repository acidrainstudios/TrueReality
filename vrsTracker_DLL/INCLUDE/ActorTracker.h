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


#ifndef VRS_TRACKER_ACTOR_H
#define VRS_TRACKER_ACTOR_H


#include "export.h"

#include <iostream>

#include <dtActors/gamemeshactor.h>

#include <dtUtil/datapathutils.h>

#include <dtCore/refptr.h>
#include <dtCore/particlesystem.h>
#include <dtCore/transform.h>
#include <dtCore/object.h>

#include <dtGame/basemessages.h>
#include <dtGame/gamemanager.h>
#include <dtGame/messagetype.h>
#include <dtGame/message.h>

#include <dtDAL/actorproxyicon.h>
#include <dtDAL/enginepropertytypes.h>


class VRS_TRACKER_EXPORT TrackerActor : public dtActors::GameMeshActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	/// Constructor
	TrackerActor(dtActors::GameMeshActorProxy& proxy);

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

	
	dtCore::UniqueId GetActorId(){return mActorId;}	//get actor's unique id (internal to delta3g)
	int GetEventId(){return mEventId;}				//get/set id as obtained from event log
	void SetEventId(int id){mEventId=id;}
	float GetLastUpdate(){return mLastUpdate;}			//get/set last time the data was updated with value from event log
	void SetLastUpdate(float lu){mLastUpdate=lu;}
	void AddToHistory(osg::Vec3f pos);					//add a position value to the history
	void SetOrigin(osg::Vec3f pos);						//set world origin so boat positions are relative to it
	void UpdatePosition(osg::Vec3f pos,float time);		//compute new real location based on event history
	void SetAvgWindowSize(int);							//set amount of data to be used in computing average

	typedef std::vector<osg::Vec3f>historyVector;
	
		
protected:

	// Destructor
    virtual ~TrackerActor() { } ;

private:

	float	mDeltaSimTime;			//sim time between frames
	
	float mLastUpdate;				//last time the position was updated via events

	int mEventId;					//the id of this actor in correspondence with the event log

	dtCore::UniqueId mActorId;		//internal unique delta3d id

	osg::Vec3f mOrigin;				//world origin

	osg::Vec3f TransformPosition(osg::Vec3f pt);	//transform from UTM to world

	float mVelocity;				//current velocity

	historyVector mHistory;			//history of events as parsed from event log

	int mAvgWindowSize;				//how often to average new position

	osg::Vec3f mLastPos;			//last averaged position
};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_TRACKER_EXPORT TrackerActorProxy : public dtActors::GameMeshActorProxy
{
public:

	/**
    * Constructor
    */
    TrackerActorProxy();

	// Creates the properties that are custom to the actor proxy.
	virtual void BuildPropertyMap();



protected:

	/**
    * Destructor
    */
    virtual ~TrackerActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

private:


};


#endif //VRS_TRACKER_ACTOR_H
