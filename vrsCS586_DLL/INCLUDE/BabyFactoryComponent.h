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

#ifndef VRS_CS586_BABY_FACTORY_H
#define VRS_CS586_BABY_FACTORY_H

#include <iostream>

#include "export.h"

#include "ActorHappySphere.h"
#include "CollisionConeActor.h"

#include <dtAI/waypointinterface.h>
#include <dtAI/astarwaypointutils.h>

#include <dtGame/baseinputcomponent.h>
 
#include <dtCore/system.h>
#include <dtCore/scene.h>
#include <dtCore/physical.h>
#include <dtCore/odecontroller.h>
#include <dtTerrain/terrain.h>
#include <dtTerrain/dtedterrainreader.h>
#include <dtTerrain/soarxterrainrenderer.h>
#include <dtTerrain/vegetationdecorator.h>
#include <ode/collision.h>
#include <ode/objects.h>
 
//This is the mass of the terrain hardcoded from stage.
static const float _TERRAIN_MASS = 5.5f;
static dtGame::GameManager * _GAME_MANAGER=NULL;
static dtCore::UniqueId * mSceneUniqueId;
static dtActors::GameMeshActor * _TERRAIN;
class VRS_CS586_EXPORT BabyFactoryComponent : public dtGame::GMComponent
{
	 
   public:
		//Default Component Name
		static const std::string COMPONENT_DEFAULT_NAME;
		
		// Constructor
		BabyFactoryComponent(const std::string& name);

		/**
		* Handle messages if we want to
		*/
		void ProcessMessage(const dtGame::Message& message);

		//Set the maximum number of babies to create
		void SetMaxNumOfBabies(int NumOfBabies);
		//Get the maximum number of babies to create
		int GetMaxNumOfBabies(void) const {return mMaxNumOfBabies;}

		//Setthe delay between each baby birth....
		void SetBabyBirthDelay(float DelayTime);
		//Get the delay between each baby birth....
		float GetBabyBirthDelay(void) const {return mBirthDelay;}

   protected:

		// Destructor
		virtual ~BabyFactoryComponent() { }

   private:
		

        //creates the babies
		void MakeBabies();
		//An overide for the phisics call back
		static void physicsCallback (void *data, dGeomID o1, dGeomID o2);

		//Holds a pointer to all created babies
		std::vector<HappySphereActor*> mBabyVector;

		//Number of Babies
		int mMaxNumOfBabies;
		int mNumOfBabies;

		float mBirthDelay;

		//Holds the waypoint nodes where the babies should start and end
		osg::ref_ptr<dtAI::Waypoint> mWayPointEnds[4];

		dtCore::RefPtr<HappySphereActorProxy> babeProxy;

		//Vars for calculating DeltaTime
		float mDeltaSimTime;		
		float mSimTime;
		float mLastSimTime;

		//which path to give to the baby....  (0-3)
		int mPathToSet;

		//timer for babie creation....
		float mTimer;
};
#endif //VRS_CS586_BABY_FACTORY_H