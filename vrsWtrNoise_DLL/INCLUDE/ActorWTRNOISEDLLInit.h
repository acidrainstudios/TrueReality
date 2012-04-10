/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* WTRNOISE DLL Stevens University Collision Avoidance Project
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
* @author WTRNOISE Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_UFPGDLLINIT_ACTOR_H
#define VRS_UFPGDLLINIT_ACTOR_H

#include "export.h"
#include "SuperSoundComponent.h"

#include <iostream>

#include <dtCore/refptr.h>

#include <dtGame/gamemanager.h>
#include <dtGame/GameActor.h>

#include <dtDAL/actorproperty.h>
#include <dtDal/functor.h>
#include <dtDal/enginePropertyTypes.h>
#include <dtDAL/datatype.h>

#include <osg/ref_ptr>

class VRS_WTRNOISE_EXPORT WTRNOISEDLLInitActor : public dtGame::GameActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	// Constructor
	WTRNOISEDLLInitActor(dtGame::GameActorProxy& proxy);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

	/**
	* Activate the SuperSoundComponent
	*/
	void SetActivateSuperSoundComponent(bool activate);
	/**
	* Find out if BabyFactoryComponent is active
	*/
	bool GetActivateSuperSoundComponent(void) const { return mSuperSoundComponent; }


	/**
	* Enable SuperSoundComponent Physics
	*/
	void SetEnablePhysics(bool enable) {mEnablePhysics = enable;}
	/**
	* Find out if SuperSoundComponent Physics is active
	*/
	bool GetEnablePhysics(void) const { return mEnablePhysics; }


	/**
	* Set height of ocean
	*/
	void SetOceanHeight(float height);
	/**
	* Get height of the ocean
	*/
	float GetOceanHeight(void) const {return mOceanHeight;}

	/**
	* Set max height of ocean sound
	*/
	void SetOceanSndMaxHeight(float height);
	/**
	* Get max height of the ocean sound
	*/
	float GetOceanSndMaxHeight(void) const {return mOceanSndMaxHeight;}

	/**
	* Set underwater sound
	*/
	//void SetUndWtrSound(const dtDAL::ResourceDescriptor* undWtrSnd);
	void SetUndWtrSound(const std::string undWtrSnd);
	/**
	* Get underwater sound
	*/
	//dtDAL::ResourceDescriptor* GetUndWtrSound(void) {return mUnderWtrSound;}

	/**
	* Set above water sound
	*/
	//void SetAboveWtrSound(const dtDAL::ResourceDescriptor* aboveWtrSnd);
	void SetAboveWtrSound(const std::string aboveWtrSnd);
	/**
	* Get above water sound
	*/
	//dtDAL::ResourceDescriptor* GetAboveWtrSound(void) {return mAboveWtrSound;}

	/**
	* Set up high sound
	*/
	//void SetUpHighSound(const dtDAL::ResourceDescriptor* upHighSnd);
	void SetUpHighSound(const std::string upHighSnd);
	/**
	* Get up high sound
	*/
	//dtDAL::ResourceDescriptor* GetUpHighSound(void) {return mUpHighSound;}

	/**
	* Set splash sound
	*/
	//void SetSplashSound(const dtDAL::ResourceDescriptor* splashSnd);
	void SetSplashSound(const std::string splashSnd);
	/**
	* Get splash sound
	*/
	//dtDAL::ResourceDescriptor* GetSplashSound(void) {return mSplashSound;}

protected:

	// Destructor
    virtual ~WTRNOISEDLLInitActor() { } ;

private:

	//Vars for SuperSoundComponent
	osg::ref_ptr<SuperSoundComponent> mSoundComp;
	float mOceanHeight;
	float mOceanSndMaxHeight;
	bool mSuperSoundComponent;
	bool mEnablePhysics;
	/*dtDAL::ResourceDescriptor* mUnderWtrSound;
	dtDAL::ResourceDescriptor* mAboveWtrSound;
	dtDAL::ResourceDescriptor* mUpHighSound;
	dtDAL::ResourceDescriptor* mSplashSound;*/
	std::string* mUnderWtrSound;
	std::string* mAboveWtrSound;
	std::string* mUpHighSound;
	std::string* mSplashSound;

};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_WTRNOISE_EXPORT WTRNOISEDLLInitActorProxy : public dtGame::GameActorProxy
{
public:

	/**
    * Constructor
    */
    WTRNOISEDLLInitActorProxy();

	// Creates the properties that are custom to the actor proxy.
      virtual void BuildPropertyMap();

protected:

	/**
    * Destructor
    */
    virtual ~WTRNOISEDLLInitActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();
};


#endif //VRS_UFPGDLLINIT_ACTOR_H