/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS586 DLL Stevens University Collision Avoidance Project
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
* @author CS586 Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_UFPGDLLINIT_ACTOR_H
#define VRS_UFPGDLLINIT_ACTOR_H

#include "export.h"
#include "BabyFactoryComponent.h"
#include "CS586JoystickComponent.h"

#include <iostream>

#include <dtCore/refptr.h>

#include <dtGame/gamemanager.h>
#include <dtGame/GameActor.h>

#include <dtDAL/actorproperty.h>
#include <dtDal/functor.h>
#include <dtDal/enginePropertyTypes.h>

#include <osg/ref_ptr>

class VRS_CS586_EXPORT CS586DLLInitActor : public dtGame::GameActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	// Constructor
	CS586DLLInitActor(dtGame::GameActorProxy& proxy);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

	/**
	* Activate the BabyFactoryComponent
	*/
	void SetActivateBabyFactoryComponent(bool activate);
	/**
	* Find out if BabyFactoryComponent is active
	*/
	bool GetActivateBabyFactoryComponent(void) const { return mBabyFactoryComponent; }

	/**
	* Set the maximum number of babies to create
	*/
	void SetMaxBabiesNum(int NumOfBabies);
	/**
	*Get the maximum number of babies to create
	*/
	int GetMaxBabiesNum(void) const {return mMaxNumOfBabies;}

	/**
	* Setthe delay between each baby birth....
	*/
	void SetBirthDelay(float DelayTime);
	/**
	* Get the delay between each baby birth....
	*/
	float GetBirthDelay(void) const {return mBabyBirthDelay;}


	/**
	* Activate the JoystickComponent
	*/
	void SetActivateJoystickComponent(bool activate);
	/**
	* Find out if JoystickComponent is active
	*/
	bool GetActivateJoystickComponent(void) const { return mJoystickComponent; }

protected:

	// Destructor
    virtual ~CS586DLLInitActor() { } ;

private:
	//Vars for BabyFactoryComponent
	osg::ref_ptr<BabyFactoryComponent> mBabyComp;
	bool	mBabyFactoryComponent;
	int		mMaxNumOfBabies;
	float	mBabyBirthDelay;

	//Vars for JoystickComponent
	osg::ref_ptr<JoystickComponent> mJoyComp;
	bool	mJoystickComponent;

};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_CS586_EXPORT CS586DLLInitActorProxy : public dtGame::GameActorProxy
{
public:

	/**
    * Constructor
    */
    CS586DLLInitActorProxy();

	// Creates the properties that are custom to the actor proxy.
      virtual void BuildPropertyMap();

protected:

	/**
    * Destructor
    */
    virtual ~CS586DLLInitActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();
};


#endif //VRS_UFPGDLLINIT_ACTOR_H