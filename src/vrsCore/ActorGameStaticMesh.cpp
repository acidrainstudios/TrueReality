/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////

#ifndef COREDLL_GAME_STATIC_MESH_ACTOR_CPP
#define COREDLL_GAME_STATIC_MESH_ACTOR_CPP

#include <vrsCore\ActorGameStaticMesh.h>

namespace vrsCore
{
	///////////////////////////////////////////////////////////////////////////////
	const std::string GameStaticMeshActor::ACTOR_DEFAULT_NAME("Game Static Mesh Actor");
	const std::string GameStaticMeshActor::ACTOR_CLASS_NAME("vrsCore::GameStaticMeshActor");
	///////////////////////////////////////////////////////////////////////////////
	GameStaticMeshActor::GameStaticMeshActor(dtActors::GameMeshActorProxy& proxy)
	:dtActors::GameMeshActor(proxy)
	,mRenderBinNum(vrsCore::DEFAULT_RENDER_BIN)
	,mBinSortType(&vrsCore::RENDER_BIN_TYPE::INHERIT_BIN)
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
	void GameStaticMeshActor::SetRenderBinSortType(vrsCore::RENDER_BIN_TYPE &BinSortType)
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
	inline void GameStaticMeshActor::ChangeRenderBinProp(int BinNum, vrsCore::RENDER_BIN_TYPE& BinType)
	{
		if(&BinType == &vrsCore::RENDER_BIN_TYPE::INHERIT_BIN)
		{
			GetOSGNode()->getStateSet()->setRenderBinToInherit();
		}
		else if(&BinType == &vrsCore::RENDER_BIN_TYPE::STATE_SORTED_BIN)
		{
			GetOSGNode()->getStateSet()->setRenderBinDetails(BinNum, vrsCore::RENDER_BIN_TYPE::STATE_SORTED_BIN.GetName());
		}
		else
		{
			GetOSGNode()->getStateSet()->setRenderBinDetails(BinNum, vrsCore::RENDER_BIN_TYPE::DEPTH_SORTED_BIN.GetName());
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
		AddProperty(new dtDAL::EnumActorProperty<vrsCore::RENDER_BIN_TYPE>("BinSortType", "Render Bin Sort Type",
			dtDAL::EnumActorProperty<vrsCore::RENDER_BIN_TYPE>::SetFuncType(actor, &GameStaticMeshActor::SetRenderBinSortType),
			dtDAL::EnumActorProperty<vrsCore::RENDER_BIN_TYPE>::GetFuncType(actor, &GameStaticMeshActor::GetRenderBinSortType),
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