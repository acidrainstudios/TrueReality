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

////////////////////////////////////////////////////////////////////
const std::string PaciferousPhysicsComponent::COMPONENT_DEFAULT_NAME("PaciferousPhysicsComponent");
////////////////////////////////////////////////////////////////////
PaciferousPhysicsComponent::PaciferousPhysicsComponent(const std::string& name) 
:dtGame::GMComponent(name)
,mPlayerCamera(false)
,mHasStarted(false)
,mLilCam(0)
,mWaitSomeTime(0)
,mPrevTerraUpdate(0)
,mTerraUpdateInterval(5)
,mCullVisitor(new SimCoreCullVisitor())
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
	if (message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
	{
		if (!mPlayerCamera)
		{
			mLilCam = GetGameManager()->GetApplication().GetCamera();
			mPlayerCamera = true;
		}

		mWaitSomeTime++;
		if (mWaitSomeTime < 160)
		{
			return;
		}

		if (!mHasStarted)// && mWaitSomeTime >= 20)
		{
			mHasStarted = true;

			dtGame::GameManager& gm = *GetGameManager();
			
			dtCore::RefPtr<dtPhysics::PhysicsWorld> world = new dtPhysics::PhysicsWorld(dtPhysics::PhysicsWorld::BULLET_ENGINE, "../dtPhysicsSvn/ext/PalPlugins"); //(gm.GetConfiguration());
			world->Init();
			gm.AddComponent(*new dtPhysics::PhysicsComponent(*world, false), dtGame::GameManager::ComponentPriority::NORMAL);

			dtGame::GameActorProxy* terrain = NULL;
			GetGameManager()->FindActorByName("Terrain", terrain);

			if (terrain == NULL)
			{
				std::cout << "no terrain" << std::endl;
				return;
			}

			//mTerraPhysAttacher = new PagedTerrainPhysicsAttacher(terrain);

			dtGame::GameActorProxy* playerProx = NULL;
			PhysicsGenericActorProxy* physPlayerProx = NULL;
			GetGameManager()->FindActorByName("Player", playerProx);
			//GetGameManager()->FindActorByName("Player", physPlayerProx);

			//physPlayerProx->GetActor(mPhysPlayer);

			if (playerProx == NULL)
			//if (physPlayerProx == NULL)
			{
				std::cout << "no player" << std::endl;
				return;
			}

			dtPhysics::PhysicsComponent* physicsComponent = NULL;
			GetGameManager()->GetComponentByName(dtPhysics::PhysicsComponent::DEFAULT_NAME, physicsComponent);
			if (physicsComponent == NULL)
			{
				std::cout << "no physics component" << std::endl;
				return;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//mTerraPhysAttacher = new PagedTerrainPhysicsAttacher(terrain, playerProx, physicsComponent);
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			playerHelper = new dtPhysics::PhysicsHelper(*playerProx);
			//playerHelper = new dtPhysics::PhysicsHelper(*physPlayerProx);
			playerObject = new dtPhysics::PhysicsObject();
			playerHelper->AddPhysicsObject(*playerObject);
			playerObject->SetPrimitiveType(dtPhysics::PrimitiveType::SPHERE);
			playerObject->SetExtents(osg::Vec3(10, 10, 10));
			playerObject->SetMechanicsType(dtPhysics::MechanicsType::DYNAMIC);
			playerObject->SetCollisionGroup(1);
			playerObject->SetNotifyCollisions(true);
			playerObject->SetName("PlayerObj");
			//playerObject->SetGravityEnabled(false);
			playerObject->CreateFromProperties(playerProx->GetActor()->GetOSGNode());
			//playerObject->CreateFromProperties(physPlayerProx->GetActor()->GetOSGNode());
			playerObject->SetActive(true);
			playerObject->AddForce(osg::Vec3f(0,0,10));
			
			/*dtCore::Transform xform;
			xform.MakeIdentity();
			GetGameManager()->GetApplication().GetCamera()->GetTransform(xform);
			dtPhysics::VectorType forward;
			xform.GetRow(1, forward);
			dtPhysics::VectorType force(forward * 1000.0f);
			playerObject->ApplyImpulse(force);*/

			physicsComponent->RegisterHelper(*playerHelper);
			//playerHelper->SetPostPhysicsCallback(dtUtil::MakeFunctor(&PaciferousPhysicsComponent::GroundTouch, this));

			playerHelper->SetPrePhysicsCallback(dtUtil::MakeFunctor(&PaciferousPhysicsComponent::BeforePhys, this));
			playerHelper->SetPostPhysicsCallback(dtUtil::MakeFunctor(&PaciferousPhysicsComponent::AfterPhys, this));

			InitializeCullVisitor();
		}
		
		//std::cout << "DSTime: " << GetGameManager()->GetSimulationTime() << std::endl;
		if (GetGameManager()->GetSimulationTime() > mPrevTerraUpdate + mTerraUpdateInterval)
		{
			//mTerraPhysAttacher->UpdateTerrainPhysics();
			//UpdateCullVisitor();
			//std::cout << "updatecull" << std::endl;
			mPrevTerraUpdate = GetGameManager()->GetSimulationTime();
		}

		UpdateCullVisitor();
	
		//std::cout << "here1" << std::endl;
		playerObject->AddForce(osg::Vec3f(0,0,2.5));
		//std::cout << "here2" << std::endl;
		/*if (mPhysPlayer->ForceReady())
		{
			std::cout << "here2.2" << std::endl;
			playerObject->AddForce(mPhysPlayer->GetForceToAdd() * -1);
			mPhysPlayer->ResetForceReady();
		}*/
		//std::cout << "here3" << std::endl;
		
		//std::cout << "tick" << std::endl;
		dtPhysics::PhysicsHelper& helper = *playerHelper;
		dtPhysics::PhysicsObject* phyObj = helper.GetMainPhysicsObject();

		if (phyObj == NULL)
		{
			std::cout << "phyObj null" << std::endl;
		}
		else if (!(phyObj->IsActive()))
		{
			std::cout << "Player phyObj not active" << std::endl;
		}
		else
		{
			//std::cout << "goodness?" << std::endl;
		}
    }
}
//////////////////////////////////////////////////////////////////////////
void PaciferousPhysicsComponent::BeforePhys()
{
	dtPhysics::PhysicsHelper& helper = *playerHelper;
	dtPhysics::PhysicsObject* phyObj = helper.GetMainPhysicsObject();

	dtGame::GameActorProxy* playerProx2 = NULL;
	GetGameManager()->FindActorByName("Player", playerProx2);

	phyObj->SetTranslation(playerProx2->GetTranslation());

}
//////////////////////////////////////////////////////////////////////////
void PaciferousPhysicsComponent::AfterPhys()
{
	dtPhysics::PhysicsHelper& helper = *playerHelper;
	dtPhysics::PhysicsObject* phyObj = helper.GetMainPhysicsObject();

	dtGame::GameActorProxy* playerProx2 = NULL;
	GetGameManager()->FindActorByName("Player", playerProx2);

	playerProx2->SetTranslation(phyObj->GetTranslation());
}
//////////////////////////////////////////////////////////////////////////
void PaciferousPhysicsComponent::InitializeCullVisitor()//dtCore::Camera& pCamera)
{
	//osg::Camera* camera = pCamera.GetOSGCamera();
	osg::Camera* camera = GetGameManager()->GetApplication().GetCamera()->GetOSGCamera();
	osgViewer::Renderer* renderer = static_cast<osgViewer::Renderer*>(camera->getRenderer());
	osgUtil::SceneView* sceneView = renderer->getSceneView(0);

	mCullVisitor->setRenderStage(sceneView->getRenderStage());
	mCullVisitor->setStateGraph(sceneView->getStateGraph());

	int flags = osgUtil::CullVisitor::ENABLE_ALL_CULLING;

	// probably only need to set the scene veiw, and it
	// auto sets the cull visitor but havent checked yet.

	mCullVisitor->setCullingMode(flags);
	sceneView->setCullingMode(flags);
	sceneView->setCullVisitor(mCullVisitor.get());
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
		//std::cout << "landactor null" << std::endl;
		PagedTerrainPhysicsActorProxy* landActorProxy = NULL;
		GetGameManager()->FindActorByName(PagedTerrainPhysicsActor::DEFAULT_NAME, landActorProxy);

		if (landActorProxy != NULL)
		{
			//std::cout << "landactor proxy not null" << std::endl;
			PagedTerrainPhysicsActor* landActor = NULL;
			landActorProxy->GetActor(landActor);
			mCullVisitor->SetLandActor(landActor);
		}
	}

	if (mCullVisitor->GetTerrainNode() == NULL)
	{
		//std::cout << "terrainnode null" << std::endl;
		GetGameManager()->FindActorsByName("Terrain", toFill);
		if(!toFill.empty())
		{
			//std::cout << "tofill not empty" << std::endl;
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