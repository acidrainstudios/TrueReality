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


#ifndef VRS_PICATINNY_CAMERA_ACTOR_H
#define VRS_PICATINNY_CAMERA_ACTOR_H

#include "export.h"

#include "..\\..\\vrsCore_DLL\include\vrsCoreMsgTypes.h"

#include <iostream>
#include <string.h>

#include <dtActors/gamemeshactor.h>

#include <dtABC/application.h>

#include <dtUtil/datapathutils.h>

#include <dtCore/refptr.h>
#include <dtCore/Camera.h>
#include <dtCore/DeltaWin.h>
//#include <dtCore/particlesystem.h>
#include <dtCore/transform.h>
//#include <dtCore/object.h>
#include <dtCore/UniqueID.h>

#include <dtGame/basemessages.h>
#include <dtGame/gamemanager.h>

#include <dtDAL/actorproxyicon.h>
#include <dtDAL/enginepropertytypes.h>


class VRS_PICATINNY_EXPORT PicaCameraActor : public dtActors::GameMeshActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	/// Constructor
	PicaCameraActor(dtActors::GameMeshActorProxy& proxy);

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

	//returns a pointer to the dtCore Camera
	dtCore::Camera* GetDtCoreCamera(void) const {return mCamera.get();}

	//Set the size of the camera window
	void SetCameraSize(osg::Vec2f size);

	//Get the size of the camera window
	osg::Vec2f GetCameraSize(void) const {return mCamSize;}

	//Set the cameras position on the screen
	void SetCameraScreenPosition(osg::Vec2f pos);

	//Get the cameras position on the screen
	osg::Vec2f GetCameraScreenPosition(void) const {return mCamScrPos;}

	//Set the Cameras (not the actors) Power (on/off)
	void SetPowerOn(bool on);

	//Get the Cameras (not the actors) Power (on/off)
	bool GetPowerOn(void) const { return mPower;}

	//Tell the Camera to follow this actor... 
	//Actor must be derived from dtGame::GameActor
	void TrackActor(dtCore::UniqueId ActorsID);

	//Turns the Cameras tracking On/Off
	void TrackingOn(bool Tracking);

	

	
protected:

	// Destructor
    virtual ~PicaCameraActor() { } ;

private:

	//PRIVATE Func
	void	SetupCamera(void);		//Sets up the camera and attaches it to the window
									//Turns the camera in the direction of the Tracked Actor
	void	TurnToTrackedActor(void);
									//Turns the camera 
	void	TurnLeftRight(float Degrees);

	//PRIVATE VARS

	float	mDeltaSimTime;			//sim time between frames
									//Pointer to our Camera
	osg::ref_ptr<dtCore::Camera>	mCamera;
									//Cameras size and positions on the screen
	osg::Vec2f						mCamSize;
	osg::Vec2f						mCamScrPos;
									//Camera Enabled/Disabled
	bool							mPower;

	bool							mTracking;

									//Actor we are tracking
	osg::ref_ptr<dtGame::GameActor> mTrackedActor;
	
	bool	mPropertiesUpdated;		//set to true if a property changed....
};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_PICATINNY_EXPORT PicaCameraActorProxy : public dtActors::GameMeshActorProxy
{
public:

	/**
    * Constructor
    */
    PicaCameraActorProxy();

	// Creates the properties that are custom to the actor proxy.
	virtual void BuildPropertyMap();



protected:

	/**
    * Destructor
    */
    virtual ~PicaCameraActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

private:


};


#endif //VRS_PICATINNY_CAMERA_ACTOR_H
