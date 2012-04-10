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

#ifndef VRS_CS586_BABY_FACTORY_CPP
#define VRS_CS586_BABY_FACTORY_CPP

#include "../Include/BabyFactoryComponent.h"

////////////////////////////////////////////////////////////////////
const std::string BabyFactoryComponent::COMPONENT_DEFAULT_NAME("BabyFactoryComponent");
////////////////////////////////////////////////////////////////////
BabyFactoryComponent::BabyFactoryComponent(const std::string& name) 
:dtGame::GMComponent(name)
,mDeltaSimTime(0.0f)
,mLastSimTime(0)
,mSimTime(0)
,mTimer(0)
,mMaxNumOfBabies(8)
,mNumOfBabies(0)
,mBirthDelay(0.25f)
,mPathToSet(0)
{	
	AddSender(&dtCore::System::GetInstance());
}
//////////////////////////////////////////////////////////////////////////
void BabyFactoryComponent::ProcessMessage(const dtGame::Message& message)
{
	if( _GAME_MANAGER== NULL)
	{
		_GAME_MANAGER = GetGameManager( );
	}
	if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
	{
 
		//Setting the physics call back to BabyFactory
		GetGameManager( )->GetScene( ).GetPhysicsController( )->SetUserCollisionCallback( physicsCallback );
		
		//*********ODE physics mess up its calculation if fps drops below 30*********
		//Setting a fixed size physics step to 20x/sec...saving 32fps
		GetGameManager( )->GetScene( ).SetPhysicsStepSize(0.05);

		//get an instacne of the WaypointManage and make waypoints visible 
		GetGameManager()->GetApplication().GetScene()->AddDrawable(&(dtAI::WaypointManager::GetInstance()));
		dtAI::WaypointManager::GetInstance().SetDeleteOnClear(false);
		dtAI::WaypointManager::GetInstance().SetDrawWaypoints(true);
		dtAI::WaypointManager::GetInstance().SetDrawNavMesh(true, false);

		//get the 4 endpoints of our paths...
		mWayPointEnds[0]= dtAI::WaypointManager::GetInstance().GetWaypoint(1);
		mWayPointEnds[1]= dtAI::WaypointManager::GetInstance().GetWaypoint(10);
		mWayPointEnds[2]= dtAI::WaypointManager::GetInstance().GetWaypoint(16);
		mWayPointEnds[3]= dtAI::WaypointManager::GetInstance().GetWaypoint(6);

		//paint the path endpoints red
		for(int i =0; i<4; i++)
		{
			mWayPointEnds[i]->SetRenderFlag(dtAI::Waypoint::RENDER_RED);
		}	   
	}
	else if (message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
	{

		mSimTime = GetGameManager()->GetSimulationTime();
		mDeltaSimTime = mSimTime - mLastSimTime;
		
		if(mSimTime>5.0f)
		{
		//Create the Happy Spheres(Babies)....
		if(((int)mBabyVector.size() < mMaxNumOfBabies) && (mTimer>mBirthDelay))
		{
			MakeBabies();
			mNumOfBabies++;
			
			mTimer=0;
		}
		mTimer += mDeltaSimTime;
		}
		
		//Call the TickLocal for all the HappySpheres to avoid them
		//regestering for msgs thus saving lots of fps....
		osg::ref_ptr<dtGame::TickMessage> myTickLocal = new dtGame::TickMessage();
		myTickLocal->SetDeltaSimTime(mDeltaSimTime);
		for(int i=0; i<(int)mBabyVector.size(); i++)
		{
			mBabyVector[i]->OnTickLocal(*myTickLocal.get());
		}

		mLastSimTime = mSimTime;
   }
}

//////////////////////////////////////////////////////////////////////////
void BabyFactoryComponent::SetMaxNumOfBabies(int NumOfBabies)
{
	mMaxNumOfBabies = NumOfBabies;
}
//////////////////////////////////////////////////////////////////////////
void BabyFactoryComponent::SetBabyBirthDelay(float DelayTime)
{
	mBirthDelay = DelayTime;
}
//////////////////////////////////////////////////////////////////////////
void BabyFactoryComponent::MakeBabies()
{
	
	
	dtDAL::ActorProxy* actorProxy;
	dtDAL::ActorProxy* actorProxy_terrain;									//find prototype actor by name
	GetGameManager()->FindPrototypeByName("ProtAct", actorProxy); 
	GetGameManager()->FindActorByName("Terrain" , actorProxy_terrain);
	//create a new actor and get its actual proxy
	osg::ref_ptr<dtDAL::ActorProxy> actualActorProxy = GetGameManager()->CreateActorFromPrototype(actorProxy->GetId() );
 
	//std::cout << "Terrain UNIQUE ID " << actorProxy_terrain->GetActor()->GetUniqueId() << ":" << actorProxy_terrain->GetActor()->GetName() << std::endl ;
	_TERRAIN= static_cast<dtActors::GameMeshActor*>(actorProxy_terrain->GetActor());
	mSceneUniqueId =  new dtCore::UniqueId( actorProxy_terrain->GetActor()->GetUniqueId() );
	// printf("MScene Id (%s)\n" , mSceneUniqueId->ToString() );
	if( actualActorProxy.valid() )
	{
											//get a pointer to the actual actor
		HappySphereActor* actor = static_cast<HappySphereActor*>(actualActorProxy->GetActor());
		

		
		//Set the newly created actors properties
		//actor->SetSpeed(20);
		actor->TurnRight(20, -1);
		actor->SetUseCache(true);
		if(mPathToSet == 0)
		{
			actor->SetPath(mWayPointEnds[0], mWayPointEnds[1]);
			mPathToSet = 1;
			
		}
		else if(mPathToSet == 1)
		{
			actor->SetPath(mWayPointEnds[1], mWayPointEnds[0]);
			mPathToSet = 2;
		}
		else if(mPathToSet == 2)
		{
			actor->SetPath(mWayPointEnds[2], mWayPointEnds[3]);
			mPathToSet = 3;
		}
		else
		{
			actor->SetPath(mWayPointEnds[3], mWayPointEnds[2]);
			mPathToSet = 0;
		}
		actor->SetName(HappySphereActor::ACTOR_DEFAULT_NAME);
		actor->JumpToPathStart();
											//add the actor to the GM
		GetGameManager()->AddActor(actor->GetGameActorProxy(), false, true);

		mBabyVector.push_back(actor);

	}


}
//////////////////////////////////////////////////////////////////////////
void BabyFactoryComponent::physicsCallback (void *data, dGeomID o1, dGeomID o2)
{
	dtCore::Physical* obj1 = static_cast<dtCore::Physical*>(dGeomGetData( o1 ) );
	dtCore::Physical* obj2 = static_cast<dtCore::Physical*>(dGeomGetData( o2 ) );
	 
	//printf("O1(%f), O2(%f) (%s,%s) (%s,%s)  \n", obj1->GetMass() , obj2->GetMass(), obj1->GetUniqueId().ToString(), obj2->GetUniqueId().ToString() , obj1->GetName() , obj2->GetName() );
	if( obj1->GetMass( ) == CollisionConeActor::COLLISION_VOLUME_MASS && obj2->GetMass( ) > CollisionConeActor::COLLISION_VOLUME_MASS )
	{
		static_cast<CollisionConeActor*>( static_cast<dtCore::Object*>( obj1 ) )->addAgentInRange( obj2 );
	}
	else if( obj2->GetMass( ) == CollisionConeActor::COLLISION_VOLUME_MASS && obj1->GetMass( ) > CollisionConeActor::COLLISION_VOLUME_MASS )
	{
		static_cast<CollisionConeActor*>( static_cast<dtCore::Object*>( obj2 ) )->addAgentInRange(obj1 );
	}
	else if( obj2->GetMass( ) == CollisionConeActor::COLLISION_VOLUME_MASS && obj1->GetMass( ) )
	{ 
		dContactGeom contactGeoms[10];
		int numContacts = dCollide(o1, o2, 10, contactGeoms, sizeof(dContactGeom));
 		if(numContacts>0)
 		{
 			contactGeoms[0].pos[0];
			static_cast<CollisionConeActor*>( static_cast<dtCore::Object*>( obj2 ) )->addContactGeometryPoints( numContacts ,  contactGeoms  );
 		}
		
	}
	else if( obj1->GetMass( ) == CollisionConeActor::COLLISION_VOLUME_MASS && obj1->GetMass( ) )
	{
		dContactGeom contactGeoms[10];
		 int numContacts = dCollide(o1, o2, 10, contactGeoms, sizeof(dContactGeom));

 		if(numContacts>0)
 		{
 			contactGeoms[0].pos[0];
			static_cast<CollisionConeActor*>( static_cast<dtCore::Object*>( obj2 ) )->addContactGeometryPoints( numContacts , contactGeoms );
 		}
		
	}

		//dContactGeom contactGeoms[10];
		//int numContacts = dCollide(o1, o2, 10, contactGeoms, sizeof(dContactGeom));

//		if(numContacts>0)
//		{
//			contactGeoms[0].pos[0];
//		}
//	if(numContacts > 0 )
//	{
//		if( obj2->GetMass( ) == CollisionConeActor::COLLISION_VOLUME_MASS  )
//		{
//			static_cast<CollisionConeActor*>( static_cast<dtCore::Object*>( obj2 ) )
//		}
//		else if( obj1->GetMass( ) == CollisionConeActor::COLLISION_VOLUME_MASS  )
//		{
//		}
//	}
//	




//			_GAME_MANAGER->FindPrototypeByName("ProtAct", actorProxy); 
//			osg::ref_ptr<dtDAL::ActorProxy> actualActorProxy = GetGameManager()->CreateActorFromPrototype(actorProxy->GetId() ); 
//			if( actualActorProxy.valid() )
//			{
//				 //get a pointer to the actual act
//				HappySphereActor* actor = static_cast<HappySphereActor*>(actualActorProxy->GetActor());
//				
//			}
//	}
//
//
//	std::cout	<< obj1->GetUniqueId() << ";" << obj1->GetName() 
//				<< "\n" << obj2->GetUniqueId() << ";" << obj2->GetName()
///				<< "\n" << std::endl;
//	
}

#endif //VRS_CS586_BABY_FACTORY_CPP