/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* PACIFPHYSICS DLL Stevens University Collision Avoidance Project
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owners of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author PACIFPHYSICS Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_PACIFPHYSICS_DLLINIT_ACTOR_H
#define VRS_PACIFPHYSICS_DLLINIT_ACTOR_H

#include "export.h"

#include "PaciferousPhysicsComponent.h"

#include <iostream>

#include <dtCore/refptr.h>

#include <dtGame/gamemanager.h>
#include <dtGame/GameActor.h>

#include <dtDAL/actorproperty.h>
#include <dtDal/functor.h>
#include <dtDal/enginePropertyTypes.h>
#include <dtDAL/datatype.h>

#include <osg/ref_ptr>

class VRS_PACIFPHYSICS_EXPORT PACIFPHYSICSDLLInitActor : public dtGame::GameActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	// Constructor
	PACIFPHYSICSDLLInitActor(dtGame::GameActorProxy& proxy);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();


	/**
	* Activate the PaciferousPhysicsComponent
	*/
	void SetActivatePaciferousPhysicsComponent(bool activate);
	/**
	* Find out if PaciferousPhysicsComponent is active
	*/
	bool GetActivatePaciferousPhysicsComponent(void) const { return mPaciferousPhysicsComponent; }


	/**
	* Set terrain paging dist for physics
	*/
	void SetPagingDist(float dist) { mTerrainPageDist = dist; }
	/**
	* get terrain paging dist for physics
	*/
	float GetPagingDist(void) const { return mTerrainPageDist; }


	/**
	* Set terrain paging frame delay for physics
	*/
	void SetTerrainPageDelay(int delay) { mTerrainPageDelay = delay; }
	/**
	* get terrain paging frame delay for physics
	*/
	int GetTerrainPageDelay(void) const { return mTerrainPageDelay; }


protected:

	// Destructor
    virtual ~PACIFPHYSICSDLLInitActor() { } ;

private:

	//Paciferous Physics Component
	osg::ref_ptr<PaciferousPhysicsComponent> mPhysComp;
	bool mPaciferousPhysicsComponent;
	float mTerrainPageDist;
	int mTerrainPageDelay;
	
};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_PACIFPHYSICS_EXPORT PACIFPHYSICSDLLInitActorProxy : public dtGame::GameActorProxy
{
public:

	/**
    * Constructor
    */
    PACIFPHYSICSDLLInitActorProxy();

	// Creates the properties that are custom to the actor proxy.
      virtual void BuildPropertyMap();

protected:

	/**
    * Destructor
    */
    virtual ~PACIFPHYSICSDLLInitActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();
};


#endif //VRS_PACIFPHYSICS_DLLINIT_ACTOR_H