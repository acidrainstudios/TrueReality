/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
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

#ifndef COREDLL_OBJECT_ACTOR_CPP
#define COREDLL_OBJECT_ACTOR_CPP

#include <trCore\ActorObject.h>

//namespace trCore
//{
//	///////////////////////////////////////////////////////////////////////////////
//	const std::string ObjectActor::ACTOR_DEFAULT_NAME("Static Mesh Actor");
//	const std::string ObjectActor::ACTOR_CLASS_NAME("trCore::ObjectActor");
//	///////////////////////////////////////////////////////////////////////////////
//	ObjectActor::ObjectActor()
//	:dtCore::Object()
//	,mRenderBinNum(trCore::DEFAULT_RENDER_BIN)
//	,mBinSortType(&trCore::RENDER_BIN_TYPE::INHERIT_BIN)
//	{
//	   SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
//	   SetDescription(ACTOR_DEFAULT_NAME); //Set the Actor Description
//	}
//	///////////////////////////////////////////////////////////////////////////////
//	void ObjectActor::SetRenderBin(int BinNum)
//	{
//		mRenderBinNum = BinNum;
//
//		ChangeRenderBinProp(mRenderBinNum, *mBinSortType);
//	}
//	///////////////////////////////////////////////////////////////////////////////
//	void ObjectActor::SetRenderBinSortType(trCore::RENDER_BIN_TYPE &BinSortType)
//	{
//		mBinSortType = &BinSortType;
//
//		ChangeRenderBinProp(mRenderBinNum, *mBinSortType);
//	}
//	///////////////////////////////////////////////////////////////////////////////
//	void ObjectActor::AddedToScene(dtCore::Scene* scene)
//	{
//		dtCore::Object::AddedToScene(scene);
//	}
//	///////////////////////////////////////////////////////////////////////////////
//	inline void ObjectActor::ChangeRenderBinProp(int BinNum, trCore::RENDER_BIN_TYPE& BinType)
//	{
//		if(&BinType == &trCore::RENDER_BIN_TYPE::INHERIT_BIN)
//		{
//			GetOSGNode()->getStateSet()->setRenderBinToInherit();
//		}
//		else if(&BinType == &trCore::RENDER_BIN_TYPE::STATE_SORTED_BIN)
//		{
//			GetOSGNode()->getStateSet()->setRenderBinDetails(BinNum, trCore::RENDER_BIN_TYPE::STATE_SORTED_BIN.GetName());
//		}
//		else
//		{
//			GetOSGNode()->getStateSet()->setRenderBinDetails(BinNum, trCore::RENDER_BIN_TYPE::DEPTH_SORTED_BIN.GetName());
//		}		
//	}
//	///////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////
//	ObjectActorProxy::ObjectActorProxy()
//	{
//		SetClassName(trCore::ObjectActor::ACTOR_CLASS_NAME); //Set the actors Class Name
//	}
//	///////////////////////////////////////////////////////////////////////////////
//	void ObjectActorProxy::BuildPropertyMap()
//	{
//		const std::string RenderBin_GROUP = "Render Bin Properties"; //Property group name
//
//		//dtDAL::ActorProxy::BuildPropertyMap();
//		//TransformableActorProxy::BuildPropertyMap();
//		//dtDAL::PhysicalActorProxy::BuildPropertyMap();
//		dtActors::StaticMeshActorProxy::BuildPropertyMap();
//
//		
//		ObjectActor* actor = static_cast<ObjectActor*>(GetActor());
//
//		// "mBinSortType" property
//		AddProperty(new dtDAL::EnumActorProperty<trCore::RENDER_BIN_TYPE>("BinSortType", "Render Bin Sort Type",
//			dtDAL::EnumActorProperty<trCore::RENDER_BIN_TYPE>::SetFuncType(actor, &ObjectActor::SetRenderBinSortType),
//			dtDAL::EnumActorProperty<trCore::RENDER_BIN_TYPE>::GetFuncType(actor, &ObjectActor::GetRenderBinSortType),
//			"Sets this actors render bin sorting order", RenderBin_GROUP));
//
//		// "mRenderBinNum" property
//		AddProperty(new dtDAL::IntActorProperty("RenderBinNum","Render Bin Number",
//			dtDAL::IntActorProperty::SetFuncType(actor, &ObjectActor::SetRenderBin),
//			dtDAL::IntActorProperty::GetFuncType(actor, &ObjectActor::GetRenderBin),
//			"Sets this actors render bin number, unless Bin Sort Type is Inherited", RenderBin_GROUP));
//
//
//		/*
//		AddProperty(new dtDAL::ActorActorProperty(*this, DistanceSensorActorProxy::PROPERTY_ATTACH_TO_ACTOR,
//               DistanceSensorActorProxy::PROPERTY_ATTACH_TO_ACTOR,
//               dtDAL::MakeFunctor(*this, &DistanceSensorActorProxy::SetAttachToProxy),
//               dtDAL::MakeFunctorRet(*actor, &DistanceSensorActor::GetAttachToActor),
//               "dtCore::DeltaDrawable", EMPTY, GROUP));
//
//		*/	
//	}
//	///////////////////////////////////////////////////////////////////////////////
//	void ObjectActorProxy::CreateActor()
//	{
//		SetActor(*new ObjectActor);
//	}
//
//	///////////////////////////////////////////////////////////////////////////////
//	void ObjectActorProxy::OnMapLoadEnd()
//	{
//		dtActors::StaticMeshActorProxy::OnMapLoadEnd();
//
//		//GetActor()->GetOSGNode()->getStateSet()->setRenderBinDetails(mRenderBinNum, "RenderBin");
//		//GetActor()->GetOSGNode()->getStateSet()->setRenderingHint( osg::StateSet::OPAQUE_BIN);		
//	}
//	
//}


#endif //COREDLL_OBJECT_ACTOR_CPP