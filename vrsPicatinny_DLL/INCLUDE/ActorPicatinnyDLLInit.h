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


#ifndef VRS_PICATINNYDLLINIT_ACTOR_H
#define VRS_PICATINNYDLLINIT_ACTOR_H



#include "export.h"

#include "CameraComponent.h"

#include <iostream>
#include <string>

#include <dtCore/refptr.h>

#include <dtGame/gamemanager.h>
#include <dtGame/GameActor.h>

#include <dtDAL/functor.h>
#include <dtDAL/actorproperty.h>
#include <dtDAL/enginepropertytypes.h>

#include <dtUtil/functor.h>


class VRS_PICATINNY_EXPORT PICATINNYDLLInitActor : public dtGame::GameActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	// Constructor
	PICATINNYDLLInitActor(dtGame::GameActorProxy& proxy);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

	/**
	* Activate the CameraComponent
	*/
	void SetActivateCameraComponent(bool activate);

	/**
	* Find out if CameraComponent is active
	*/
	bool GetActivateCameraComponent(void) const { return mCameraComponent; }

	/**
	* Set the name of the camera to change to
	*/
	void SetCamToMon0ByName(std::string CamName);
	
	/**
	* Get the name of the camera to change to
	*/
	std::string GetCamToMon0ByName(void) const {return mCamName; }



protected:

	// Destructor
    virtual ~PICATINNYDLLInitActor() { } ;

private:
	
	// Camera Component Options
	bool mCameraComponent;
	std::string mCamName;

};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_PICATINNY_EXPORT PICATINNYDLLInitActorProxy : public dtGame::GameActorProxy
{
public:

	/**
    * Constructor
    */
    PICATINNYDLLInitActorProxy();

	// Creates the properties that are custom to the actor proxy.
      virtual void BuildPropertyMap();

protected:

	/**
    * Destructor
    */
    virtual ~PICATINNYDLLInitActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();
};


#endif //VRS_PICATINNYDLLINIT_ACTOR_H
