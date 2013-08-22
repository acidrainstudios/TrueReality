/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2013
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Maxim Serebrennik
*/

#ifndef COREDLL_GAME_STATIC_MESH_ACTOR_CPP
#define COREDLL_GAME_STATIC_MESH_ACTOR_CPP

#include <trCore\ActorGameStaticMesh.h>

namespace trCore
{
	///////////////////////////////////////////////////////////////////////////////
	const std::string GameStaticMeshActor::ACTOR_DEFAULT_NAME("Game Static Mesh Actor");
	const std::string GameStaticMeshActor::ACTOR_CLASS_NAME("trCore::GameStaticMeshActor");
	///////////////////////////////////////////////////////////////////////////////
	GameStaticMeshActor::GameStaticMeshActor(dtActors::GameMeshActorProxy& proxy)
	:dtActors::GameMeshActor(proxy)
	,mRenderBinNum(trCore::DEFAULT_RENDER_BIN)
	,mBinSortType(&trCore::RENDER_BIN_TYPE::INHERIT_BIN)
	{
	   SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
	   SetDescription(ACTOR_DEFAULT_NAME); //Set the Actor Description
	}
	///////////////////////////////////////////////////////////////////////////////

	void GameStaticMeshActor::SetRenderBin(int BinNum)
	{
		mRenderBinNum = BinNum;

		ChangeRenderBinProp(mRenderBinNum, *mBinSortType);
	}
	///////////////////////////////////////////////////////////////////////////////
	void GameStaticMeshActor::SetRenderBinSortType(trCore::RENDER_BIN_TYPE &BinSortType)
	{
		mBinSortType = &BinSortType;

		ChangeRenderBinProp(mRenderBinNum, *mBinSortType);
	}
	///////////////////////////////////////////////////////////////////////////////
	void GameStaticMeshActor::OnEnteredWorld()
	{
		dtActors::GameMeshActor::OnEnteredWorld();
	}
	///////////////////////////////////////////////////////////////////////////////
	void GameStaticMeshActor::AddedToScene(dtCore::Scene* scene)
	{
		dtActors::GameMeshActor::AddedToScene(scene);
		#ifdef _DEBUG
		std::cout << GetName() << " GameStaticMeshActor::AddedToScene" << std::endl;
		#endif //_DEBUG
	}

	///////////////////////////////////////////////////////////////////////////////
	inline void GameStaticMeshActor::ChangeRenderBinProp(int BinNum, trCore::RENDER_BIN_TYPE& BinType)
	{
		if(&BinType == &trCore::RENDER_BIN_TYPE::INHERIT_BIN)
		{
			GetOSGNode()->getStateSet()->setRenderBinToInherit();
		}
		else if(&BinType == &trCore::RENDER_BIN_TYPE::STATE_SORTED_BIN)
		{
			GetOSGNode()->getStateSet()->setRenderBinDetails(BinNum, trCore::RENDER_BIN_TYPE::STATE_SORTED_BIN.GetName());
		}
		else
		{
			GetOSGNode()->getStateSet()->setRenderBinDetails(BinNum, trCore::RENDER_BIN_TYPE::DEPTH_SORTED_BIN.GetName());
		}		
	}
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	GameStaticMeshActorProxy::GameStaticMeshActorProxy()
	{
		SetClassName(GameStaticMeshActor::ACTOR_CLASS_NAME); //Set the actors Class Name
	}
	///////////////////////////////////////////////////////////////////////////////
	void GameStaticMeshActorProxy::BuildPropertyMap()
	{
		const std::string RenderBin_GROUP = "Render Bin Properties"; //Property group name

		//dtDAL::ActorProxy::BuildPropertyMap();
		//TransformableActorProxy::BuildPropertyMap();
		//dtDAL::PhysicalActorProxy::BuildPropertyMap();
		//dtGame::GameActorProxy::BuildPropertyMap();
		dtActors::GameMeshActorProxy::BuildPropertyMap();
		
		
		GameStaticMeshActor* actor = static_cast<GameStaticMeshActor*>(GetActor());
	   
		// "mBinSortType" property
		AddProperty(new dtDAL::EnumActorProperty<trCore::RENDER_BIN_TYPE>("BinSortType", "Render Bin Sort Type",
			dtDAL::EnumActorProperty<trCore::RENDER_BIN_TYPE>::SetFuncType(actor, &GameStaticMeshActor::SetRenderBinSortType),
			dtDAL::EnumActorProperty<trCore::RENDER_BIN_TYPE>::GetFuncType(actor, &GameStaticMeshActor::GetRenderBinSortType),
			"Sets this actors render bin sorting order", RenderBin_GROUP));

		// "mRenderBinNum" property
		AddProperty(new dtDAL::IntActorProperty("RenderBinNum","Render Bin Number",
			dtDAL::IntActorProperty::SetFuncType(actor, &GameStaticMeshActor::SetRenderBin),
			dtDAL::IntActorProperty::GetFuncType(actor, &GameStaticMeshActor::GetRenderBin),
			"Sets this actors render bin number, unless Bin Sort Type is Inherited", RenderBin_GROUP));

		/*
		AddProperty(new dtDAL::ActorActorProperty(*this, DistanceSensorActorProxy::PROPERTY_ATTACH_TO_ACTOR,
               DistanceSensorActorProxy::PROPERTY_ATTACH_TO_ACTOR,
               dtDAL::MakeFunctor(*this, &DistanceSensorActorProxy::SetAttachToProxy),
               dtDAL::MakeFunctorRet(*actor, &DistanceSensorActor::GetAttachToActor),
               "dtCore::DeltaDrawable", EMPTY, GROUP));

		*/
	}

	///////////////////////////////////////////////////////////////////////////////
	void GameStaticMeshActorProxy::CreateActor()
	{
	   SetActor(*new GameStaticMeshActor(*this));
	}

	///////////////////////////////////////////////////////////////////////////////
	void GameStaticMeshActorProxy::OnEnteredWorld()
	{
	   dtActors::GameMeshActorProxy::OnEnteredWorld();
	}

}


#endif //COREDLL_GAME_STATIC_MESH_ACTOR_CPP