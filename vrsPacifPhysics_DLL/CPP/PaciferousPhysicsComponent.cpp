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

#ifndef VRS_PACIFEROUS_PHYSICS_COMPONENT_CPP
#define VRS_PACIFEROUS_PHYSICS_COMPONENT_CPP

#include "../Include/PaciferousPhysicsComponent.h"
#include "../Include/vrsPACIFPHYSICSActorsRegistry.h"
#include <osg/Camera>

////////////////////////////////////////////////////////////////////
const std::string PaciferousPhysicsComponent::COMPONENT_DEFAULT_NAME("PaciferousPhysicsComponent");
////////////////////////////////////////////////////////////////////
PaciferousPhysicsComponent::PaciferousPhysicsComponent(const std::string& name) 
:dtGame::GMComponent(name)
,mPlayerCamera(false)
,mHasStarted(false)
,mLilCam(0)
,mWaitSomeTime(0)
//,mPrevTerraUpdate(0)
//,mTerraUpdateInterval(5)
,mCullVisitor(new SimCoreCullVisitor())
//,mPhysPlayer(NULL)
,mTerrainPagingDist(7500.0)
,mTerrainPagingDelay(15)
,mBShouldLoad(false)
{	
	AddSender(&dtCore::System::GetInstance());
}


//////////////////////////////////////////////////////////////////////////
PaciferousPhysicsComponent::~PaciferousPhysicsComponent()
{

}
//////////////////////////////////////////////////////////////////////////
void PaciferousPhysicsComponent::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
	{
		mBShouldLoad = true;
	}
	else if (message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
	{
		if (!mPlayerCamera)
		{
			mPlayerCamera = true;
		}

		if (mBShouldLoad)
		{
			if (mWaitSomeTime < 100)
			{
				mWaitSomeTime++;
				return;
			}
			std::cout << "wait time over" << std::endl;
			mBShouldLoad = false;

			dtGame::GameManager& gm = *GetGameManager();

			dtCore::RefPtr<dtPhysics::PhysicsWorld> world = new dtPhysics::PhysicsWorld(dtPhysics::PhysicsWorld::BULLET_ENGINE, "../dtPhysics2010_06_11_A/ext/PalPlugins"); //(gm.GetConfiguration());
			//dtCore::RefPtr<dtPhysics::PhysicsWorld> world = new dtPhysics::PhysicsWorld(GetGameManager()->GetApplication());
			
			world->Init();
			gm.AddComponent(*new dtPhysics::PhysicsComponent(*world, false), dtGame::GameManager::ComponentPriority::NORMAL);

			dtGame::GameActorProxy* terrain = NULL;
			//GetGameManager()->FindActorByName("Terrain", terrain);
			GetGameManager()->FindActorByType(*vrsCore::CoreActorsRegistry::PAGED_TERRAIN_ACTOR_TYPE, terrain);

			if (terrain == NULL)
			{
				std::cout << "no terrain" << std::endl;
				return;
			}
			
			dtPhysics::PhysicsComponent* physicsComponent = NULL;
			GetGameManager()->GetComponentByName(dtPhysics::PhysicsComponent::DEFAULT_NAME, physicsComponent);

			if (physicsComponent == NULL)
			{
				std::cout << "no physics component" << std::endl;
				return;
			}

			InitializeCullVisitor();
		}

		UpdateCullVisitor();
    }
}
////////////////////////////////////////////////////////////////////////////////
void PaciferousPhysicsComponent::InitializeCullVisitor()
{
	osg::Camera* camera = GetGameManager()->GetApplication().GetCamera()->GetOSGCamera();
	osgViewer::Renderer* renderer = static_cast<osgViewer::Renderer*>(camera->getRenderer());
	osgUtil::SceneView* sceneView = renderer->getSceneView(0);

	mCullVisitor->setRenderStage(sceneView->getRenderStage());
	mCullVisitor->setStateGraph(sceneView->getStateGraph());

	int flags = osgUtil::CullVisitor::ENABLE_ALL_CULLING;

	// probably only need to set the scene veiw, and it
	// auto sets the cull visitor but havent checked yet. -- MAKES OCEAN FLICKER!!

	//mCullVisitor->setCullingMode(flags);
	//sceneView->setCullingMode(flags);
	sceneView->setCullVisitor(mCullVisitor.get());

	mCullVisitor->SetFrameDelay(mTerrainPagingDelay);
	mCullVisitor->SetPagingRange(mTerrainPagingDist);
}
//////////////////////////////////////////////////////////////////////////
bool PaciferousPhysicsComponent::UpdateCullVisitor()
{
	if(!mCullVisitor.valid())
	{
		std::cout << "mCullVisitor Is not valid, which means \
					 it wasnt initialized in OnAddedToGM. " << std::endl;
		return false;
	}

	std::vector<dtDAL::ActorProxy*> toFill;

	if (mCullVisitor->GetLandActor() == NULL)
	{
		PagedTerrainPhysicsActorProxy* landActorProxy = NULL;
		//GetGameManager()->FindActorByName(PagedTerrainPhysicsActor::DEFAULT_NAME, landActorProxy);
		GetGameManager()->FindActorByType(*PACIFPHYSICSActorsRegistry::PAGED_TERRAIN_PHYSICS_TYPE, landActorProxy);

		if (landActorProxy != NULL)
		{
			PagedTerrainPhysicsActor* landActor = NULL;
			landActorProxy->GetActor(landActor);
			mCullVisitor->SetLandActor(landActor);
		}
	}

	if (mCullVisitor->GetTerrainNode() == NULL)
	{
		//GetGameManager()->FindActorsByName("Terrain", toFill);
		GetGameManager()->FindActorsByType(*vrsCore::CoreActorsRegistry::PAGED_TERRAIN_ACTOR_TYPE, toFill);
		if(!toFill.empty())
		{
			mCullVisitor->SetTerrainNode(toFill[0]->GetActor()->GetOSGNode()->asTransform());
		}
	}

	dtCore::Transform cameraTransform;
	GetGameManager()->GetApplication().GetCamera()->GetTransform(cameraTransform);
	osg::Vec3 pos;
	cameraTransform.GetTranslation(pos);
	mCullVisitor->SetCameraTransform(pos);
	return true;
}

#endif //VRS_PACIFEROUS_PHYSICS_COMPONENT_CPP