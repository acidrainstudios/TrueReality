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


#ifndef VRS_TRACKERDLLINIT_ACTOR_H
#define VRS_TRACKERDLLINIT_ACTOR_H



#include "export.h"

#include "TrackerComponent.h"

#include <iostream>

#include <dtCore/refptr.h>

#include <dtGame/gamemanager.h>
#include <dtGame/GameActor.h>

#include <dtDAL/functor.h>
#include <dtDAL/actorproperty.h>
#include <dtDAL/enginepropertytypes.h>


class VRS_TRACKER_EXPORT TrackerDLLInitActor : public dtGame::GameActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	// Constructor
	TrackerDLLInitActor(dtGame::GameActorProxy& proxy);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

	/**
	* Activate the TrackerComponent
	*/
	void SetActivateTrackerComponent(bool activate);

	/**
	* Find out if TrackerComponent is active
	*/
	bool GetActivateTrackerComponent(void) const { return mTrackerComponent; }

protected:

	// Destructor
    virtual ~TrackerDLLInitActor() { } ;

private:
	
	bool mTrackerComponent;

};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_TRACKER_EXPORT TrackerDLLInitActorProxy : public dtGame::GameActorProxy
{
public:

	/**
    * Constructor
    */
    TrackerDLLInitActorProxy();

	// Creates the properties that are custom to the actor proxy.
      virtual void BuildPropertyMap();

protected:

	/**
    * Destructor
    */
    virtual ~TrackerDLLInitActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();
};


#endif //VRS_TRACKERDLLINIT_ACTOR_H
