/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* PHYSICS DLL Stevens University Collision Avoidance Project
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
* @author PHYSICS Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_PACIFEROUS_PHYSICS_COMPONENT_H
#define VRS_PACIFEROUS_PHYSICS_COMPONENT_H

#include <iostream>

#include "export.h"
#include "..\\..\\vrsCore_DLL\include\ActorPagedTerrain.h"
#include "PagedTerrainPhysicsActor.h"
#include "SimCoreCullVisitor.h"
#include "PhysicsActorGeneric.h"

#include <dtGame/baseinputcomponent.h>
#include <dtCore/system.h>
#include <dtCore/scene.h>
#include <dtCore/physical.h>
#include <dtCore/transform.h>
#include <dtABC/application.h>
#include <dtGame/messagetype.h>
#include <dtGame/message.h>

#include <dtActors/gamemeshactor.h>

#include <dtPhysics/physicshelper.h>
#include <dtPhysics/physicscomponent.h>
#include <dtPhysics/physicsmaterialactor.h>
#include <dtPhysics/bodywrapper.h>
#include <dtPhysics/palutil.h>
#include <dtPhysics/charactermotionmodel.h>
#include <dtPhysics/palphysicsworld.h>

#include <pal/pal.h>
#include <pal/palFactory.h>

#include <osgViewer/Renderer>
#include <osgUtil/CullVisitor>
#include <osgUtil/SceneView>
#include <osgUtil/StateGraph>
#include <osgUtil/RenderStage>


class VRS_PACIFPHYSICS_EXPORT PaciferousPhysicsComponent : public dtGame::GMComponent
{
	 
   public:
		//Default Component Name
		static const std::string COMPONENT_DEFAULT_NAME;
		
		// Constructor
		PaciferousPhysicsComponent(const std::string& name);

		/**
		* Handle messages if we want to
		*/
		void ProcessMessage(const dtGame::Message& message);

		void InitializeCullVisitor();

		bool UpdateCullVisitor();

		void SetTerrainPagingDist(float dist) {mTerrainPagingDist = dist;}

		void SetTerrainPagingDelay(int delay) {mTerrainPagingDelay = delay;}

		//virtual void OnMessage(MessageData* data);


   protected:

		// Destructor
		virtual ~PaciferousPhysicsComponent();


   private:

		dtCore::Camera* mLilCam;
		bool mPlayerCamera;
		bool mHasStarted;
		float mWaitSomeTime;

		dtCore::RefPtr<SimCoreCullVisitor> mCullVisitor;
		float mTerrainPagingDist;
		int mTerrainPagingDelay;
		//PhysicsGenericActor* mPhysPlayer;

		bool mBShouldLoad;

};
#endif //VRS_PACIFEROUS_PHYSICS_COMPONENT_H