/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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

#ifndef COREDLL_PAGED_TERRAIN_ACTOR_CPP
#define COREDLL_PAGED_TERRAIN_ACTOR_CPP


#include <trCore\ActorPagedTerrain.h>

namespace trCore
{
	///////////////////////////////////////////////////////////////////////////////
	const std::string PagedTerrainActor::ACTOR_DEFAULT_NAME("Paged Terrain Actor"); 
	const std::string PagedTerrainActor::ACTOR_CLASS_NAME("trCore::PagedTerrainActor"); 
	///////////////////////////////////////////////////////////////////////////////
	PagedTerrainActor::PagedTerrainActor(trCore::GameStaticMeshActorProxy &proxy) 
		:trCore::GameStaticMeshActor(proxy)
		,mGroupNodeForTerrain(NULL)
		,mNeedToLoad(true)
		,mPaging_Min_X(0.0f)      
		,mPaging_Min_Y(0.0f)      
		,mPaging_Max_X(31.0f)     
		,mPaging_Max_Y(31.0f)     
		,mPaging_Delta(2048.0f)   
		,mPaging_Range(5000.0f) // Changing these two values does NOT show more terrain
		,mPaging_BaseName("terrain%i_%i.ive")
		,mPaging_ExpiringDelay(60.0f)
		,mPaging_Frame_Rate_Targeted(60.0f)
		,mPaging_Precompile(true)
		,mMaximumObjectsToCompile(16) // used to be 1
		,mZOffsetForTerrain(0.0f)
		,mTerrainPath("/Content/Terrains/IVE")
	{
		SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
		SetDescription("Terrain Actor with paged geometry tiles"); //Set the Actor Description

		//Set the default options for the Coord Converter
		mCoord.SetIncomingCoordinateType(dtUtil::IncomingCoordinateType::GEODETIC);
		mCoord.SetLocalCoordinateType(dtUtil::LocalCoordinateType::CARTESIAN_UTM);
		mCoord.SetLocalOffset(osg::Vec3d(548000.000000, 4472340.000000, 0));
		mCoord.SetUTMHemisphere('N');
		mCoord.SetUTMZone(18);
		
		//SetMesh("StaticMeshes/Misc/Blank.ive");
	}

	///////////////////////////////////////////////////////////////////////////////
	PagedTerrainActor::~PagedTerrainActor()
	{
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::OnEnteredWorld()
	{
		trCore::GameStaticMeshActor::OnEnteredWorld();
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
	{
		mDeltaSimTime = tickMessage.GetDeltaSimTime();
	}

	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
	{
		mDeltaSimTime = tickMessage.GetDeltaSimTime();
	}	
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::AddedToScene(dtCore::Scene* scene)
	{
		#ifdef _DEBUG
		std::cout << "PagedTerrainActor::AddedToScene" << std::endl;
		#endif //_DEBUG

		trCore::GameStaticMeshActor::AddedToScene(scene);
		//dtActors::GameMeshActor::AddedToScene(scene);

		if (scene != NULL)
		{
			#ifdef _DEBUG
			std::cout << "PagedTerrainActor::AddedToScene:::scene != NULL" << std::endl;
			#endif //_DEBUG
			//Actually load the file, even if it's empty string so that if someone were to 
			//load a mesh, remove it from the scene, then try to clear the mesh, this actor will still
			//work.
			if (mNeedToLoad)
			{
				#ifdef _DEBUG
				std::cout << "PagedTerrainActor::AddedToScene:::LoadFile(mLoadedFile)" << std::endl;
				#endif //_DEBUG
			   
				LoadFile(mLoadedFile);
				//mNeedToLoad = false;
			}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::LoadFile(const std::string &fileName)
	{
		//Don't actually load the file unless
		if (GetSceneParent() != NULL)
		{
			//We should always clear the geometry.  If LoadFile fails, we should have no geometry.
			if (GetMatrixNode()->getNumChildren() != 0)
			{
				GetMatrixNode()->removeChild(0, GetMatrixNode()->getNumChildren());
			}

			if(!mTerrainPath.empty() && !mPaging_BaseName.empty())
			{
				/////////////////////////////////////////////////////////////////////
				// do loading here
				const std::string& currentTerrainPath = mTerrainPath;

				osgDB::ReaderWriter::Options* options = new osgDB::ReaderWriter::Options;
				options->setObjectCacheHint(osgDB::ReaderWriter::Options::CACHE_ALL);
				osgDB::Registry::instance()->setOptions(options);

				GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->setDoPreCompile(true);
				

				int tile_x =0 ,tile_y =0;

				int pagingMaxXInt = int(mPaging_Max_X);
				int pagingMaxYInt = int(mPaging_Max_Y);
		       
				mGroupNodeForTerrain = new osg::Group;
			   
				#ifdef _DEBUG
				std::cout << "PagedTerrainActor>Loading Terrain Files" << std::endl;
				#endif //_DEBUG

				for(tile_x = int(mPaging_Min_X);tile_x <= pagingMaxXInt;tile_x++)
				{
					for(tile_y = int(mPaging_Min_Y);tile_y <= pagingMaxYInt;tile_y++)
					{
						char name[512];
						sprintf(name,mPaging_BaseName.c_str(),tile_x,tile_y);

						osg::PagedLOD* pPage= new osg::PagedLOD();
						osg::Vec3 pagingOffset; // non declared variable from lm code, (wasnt in the ter file)

						pPage->setCenter(osg::Vec3((tile_x * mPaging_Delta + mPaging_Delta/2.0),
													(tile_y * mPaging_Delta + mPaging_Delta/2.0),
													mZOffsetForTerrain)); 

						pPage->setFileName(0,currentTerrainPath + "/" + name);
						
						pPage->setRange(0,0.0,mPaging_Range);
						//pPage->setRadius(mPaging_Radius);
						pPage->setRadius(mPaging_Range);
						//pPage->setDataVariance(osg::Object::STATIC);
		     
						mGroupNodeForTerrain->addChild(pPage);
						//this->GetOSGNode()->asGroup()->addChild(pPage);
						//std::cout << (currentTerrainPath + "/" + name) << std::endl;
						#ifdef _DEBUG
						std::cout << (currentTerrainPath + "/" + name) << std::endl;
						#endif //_DEBUG

						//std::cout << "getRequestsInProgress(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getRequestsInProgress() << std::endl;
						//std::cout << "getDataToCompileListSize(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getDataToCompileListSize() << std::endl;
						//std::cout << "getDataToMergeListSize(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getDataToMergeListSize() << std::endl;
						//std::cout << "getFileRequestListSize(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getFileRequestListSize() << std::endl;
						//std::cout << "requiresCompileGLObjects(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->requiresCompileGLObjects() << std::endl << std::endl;
						
					}
				}
				#ifdef _DEBUG
				std::cout << "PagedTerrainActor>Done Loading Terrain Files" << std::endl;
				#endif //_DEBUG

						
			}

			if (!GetShaderGroup().empty())
			{
				SetShaderGroup(GetShaderGroup());
			}

			GetMatrixNode()->addChild(mGroupNodeForTerrain.get());

			//We need this little hack to ensure that when a mesh is loaded, the collision
			//properties get updated properly.
			GetGameActorProxy().SetCollisionType(GetGameActorProxy().GetCollisionType());
			mNeedToLoad = false;

			//std::cout << "getRequestsInProgress(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getRequestsInProgress() << std::endl;
			//std::cout << "getDataToCompileListSize(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getDataToCompileListSize() << std::endl;
			//std::cout << "getDataToMergeListSize(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getDataToMergeListSize() << std::endl;
			//std::cout << "getFileRequestListSize(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->getFileRequestListSize() << std::endl;
			//std::cout << "requiresCompileGLObjects(): " << GetGameActorProxy().GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager()->requiresCompileGLObjects() << std::endl << std::endl;

		}
		else
		{
			mNeedToLoad = true;
		}
		mLoadedFile = fileName;

	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::SetTerrainPath(const std::string& value)
	{
		mTerrainPath = value;

		if (GetSceneParent() != NULL)
		{
			if (mNeedToLoad)
			{
				LoadFile(mLoadedFile);
				//mNeedToLoad = false;
			}
		}
		
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::SetIncomingCoordinateType(dtUtil::IncomingCoordinateType& Type)
	{
		mCoord.SetIncomingCoordinateType(Type);
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::SetLocalCoordinateType(dtUtil::LocalCoordinateType& Type)
	{
		mCoord.SetLocalCoordinateType(Type);
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::SetLocalUTMZone(int Zone)
	{
		mCoord.SetUTMZone(Zone);
	}
	void PagedTerrainActor::SetLocalUTMHemisphere(const std::string& Hem)
	{
		const char* H = Hem.c_str();
		mCoord.SetUTMHemisphere(H[0]);
	}
	std::string PagedTerrainActor::GetLocalUTMHemisphere(void)
	{
		std::string Hem;
		Hem.push_back(mCoord.GetUTMHemisphere());
		return Hem;
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::SetLocalOrigin(osg::Vec3d OriginOffset)
	{
		mCoord.SetLocalOffset(OriginOffset);
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::SetLocalGlobeRadius(float Radius)
	{
		mCoord.SetGlobeRadius(Radius);
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActor::SetLocalFlatEarthOrigin(osg::Vec2d LatLon)
	{
		mCoord.SetFlatEarthOrigin(LatLon);
	}
	///////////////////////////////////////////////////////////////////////////////
	inline osg::Vec2d PagedTerrainActor::GetLocalFlatEarthOrigin(void)
	{
		osg::Vec2d LatLon(0,0);
		mCoord.GetFlatEarthOrigin(LatLon);
		return LatLon;
	}
	///////////////////////////////////////////////////////////////////////////////
	inline osg::Vec3d PagedTerrainActor::GetLocalOrigin(void)
	{
		osg::Vec3d OriginOffset(0,0,0);
		mCoord.GetLocalOffset(OriginOffset);
		return OriginOffset;
	}
	///////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	PagedTerrainActorProxy::PagedTerrainActorProxy()
	{
		SetClassName(PagedTerrainActor::ACTOR_CLASS_NAME);
	}

	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActorProxy::BuildPropertyMap()
	{
		
		PagedTerrainActor* actor = static_cast<PagedTerrainActor*>(GetActor());

		GameStaticMeshActorProxy::BuildPropertyMap();
		
		//Remove Properties we dont want the user to change
		RemoveProperty("static mesh");
		RemoveProperty("use cache object");

		// Check if "static mesh" property exist.....
		//dtDAL::ResourceActorProperty* ActopMeshProperty;
		//GetProperty("static mesh", ActopMeshProperty);
		//assert(ActopMeshProperty);

		// Automatically default the mesh to the one we want
		//dtDAL::ResourceDescriptor meshDescriptor("StaticMeshes:Misc:Blank.ive");
		//ActopMeshProperty->SetValue(&meshDescriptor);

		const std::string TERRAIN_GROUP_NAME = "Paged Terrain Properties";

		AddProperty(new dtDAL::FloatActorProperty("mPaging_Min_X", "First X Tile to Load From",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingMinX),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingMinX),
			"", TERRAIN_GROUP_NAME));

		AddProperty(new dtDAL::FloatActorProperty("mPaging_Min_Y", "First Y Tile to Load From",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingMinY),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingMinY),
			"", TERRAIN_GROUP_NAME));

		AddProperty(new dtDAL::FloatActorProperty("mPaging_Max_X", "Last X Tile to Load To",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingMaxX),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingMaxX),
			"", TERRAIN_GROUP_NAME));
	 
		AddProperty(new dtDAL::FloatActorProperty("mPaging_Max_Y", "Last Y Tile to Load To",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingMaxY),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingMaxY),
			"", TERRAIN_GROUP_NAME));

		AddProperty(new dtDAL::FloatActorProperty("mPaging_Delta", "Tile Size",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingDelta),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingDelta),
			"", TERRAIN_GROUP_NAME));
	 
		AddProperty(new dtDAL::FloatActorProperty("mPaging_Range", "Tile Paging Distance",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingRange),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingRange),
			"", TERRAIN_GROUP_NAME));

		AddProperty(new dtDAL::StringActorProperty("mPaging_BaseName", "Tile Base Name",
			dtDAL::StringActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingBaseName),
			dtDAL::StringActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingBaseName),
			"", TERRAIN_GROUP_NAME));
		/*
		AddProperty(new dtDAL::FloatActorProperty("mPaging_ExpiringDelay", "mPaging_ExpiringDelay",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingExpiringDelay),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingExpiringDelay),
			"", TERRAIN_GROUP_NAME));

		AddProperty(new dtDAL::FloatActorProperty("mPaging_Frame_Rate_Targeted", "mPaging_Frame_Rate_Targeted",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingFPSTarget),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingFPSTarget),
			"", TERRAIN_GROUP_NAME));
		
		AddProperty(new dtDAL::BooleanActorProperty("mPaging_Precompile", "Precompile Loading Tiles",
			dtDAL::BooleanActorProperty::SetFuncType(actor, &PagedTerrainActor::SetPagingPrecompile),
			dtDAL::BooleanActorProperty::GetFuncType(actor, &PagedTerrainActor::GetPagingPrecompile),
			"", TERRAIN_GROUP_NAME));

		AddProperty(new dtDAL::IntActorProperty("mMaximumObjectsToCompile", "Maximum Tile To Compile At Once",
			dtDAL::IntActorProperty::SetFuncType(actor, &PagedTerrainActor::SetMaxObjectsToCompile),
			dtDAL::IntActorProperty::GetFuncType(actor, &PagedTerrainActor::GetMaxObjectsToCompile),
			"", TERRAIN_GROUP_NAME));
		*/
		AddProperty(new dtDAL::FloatActorProperty("mZOffsetForTerrain", "Terrain Z Offset",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetZOffsetforTerrain),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetZOffsetforTerrain),
			"", TERRAIN_GROUP_NAME));

		AddProperty(new dtDAL::StringActorProperty("mTerrainPath", "Terrain Tile Path",
			dtDAL::StringActorProperty::SetFuncType(actor, &PagedTerrainActor::SetTerrainPath),
			dtDAL::StringActorProperty::GetFuncType(actor, &PagedTerrainActor::GetTerrainPath),
			"", TERRAIN_GROUP_NAME));


		const std::string COORDINATE_CONFIG_GROUP_NAME = "Coordinate Settings";

		//IncomingCoordinateType
		AddProperty(new dtDAL::EnumActorProperty<dtUtil::IncomingCoordinateType>("IncomingCoordinateType", "Incoming Coordinate Type",
			dtDAL::EnumActorProperty<dtUtil::IncomingCoordinateType>::SetFuncType(actor, &PagedTerrainActor::SetIncomingCoordinateType),
			dtDAL::EnumActorProperty<dtUtil::IncomingCoordinateType>::GetFuncType(actor, &PagedTerrainActor::GetIncomingCoordinateType),
			"Sets the Coordinate type that will be passed to this actor", COORDINATE_CONFIG_GROUP_NAME));

		//LocalCoordinateType
		AddProperty(new dtDAL::EnumActorProperty<dtUtil::LocalCoordinateType>("LocalCoordinateType", "Local Coordinate Type",
			dtDAL::EnumActorProperty<dtUtil::LocalCoordinateType>::SetFuncType(actor, &PagedTerrainActor::SetLocalCoordinateType),
			dtDAL::EnumActorProperty<dtUtil::LocalCoordinateType>::GetFuncType(actor, &PagedTerrainActor::GetLocalCoordinateType),
			"Sets the Coordinate type that the terrains geometry was built with", COORDINATE_CONFIG_GROUP_NAME));
		
		//LocalUTMHemisphere
		AddProperty(new dtDAL::StringActorProperty("LocalUTMHemisphere", "UTM Hemisphere",
			dtDAL::StringActorProperty::SetFuncType(actor, &PagedTerrainActor::SetLocalUTMHemisphere),
			dtDAL::StringActorProperty::GetFuncType(actor, &PagedTerrainActor::GetLocalUTMHemisphere),
			"Set the Terrains Hemisphere  (H or S)", COORDINATE_CONFIG_GROUP_NAME));

		//LocalUTMZone
		AddProperty(new dtDAL::IntActorProperty("LocalUTMZone", "UTM Zone",
			dtDAL::IntActorProperty::SetFuncType(actor, &PagedTerrainActor::SetLocalUTMZone),
			dtDAL::IntActorProperty::GetFuncType(actor, &PagedTerrainActor::GetLocalUTMZone),
			"Set the Terrains UTM East-West Zone 1-60", COORDINATE_CONFIG_GROUP_NAME));

		//LocalOrigin
		AddProperty(new dtDAL::Vec3dActorProperty("LocalOrigin", "Local Terrain Origin",
			dtDAL::Vec3dActorProperty::SetFuncType(actor, &PagedTerrainActor::SetLocalOrigin),
			dtDAL::Vec3dActorProperty::GetFuncType(actor, &PagedTerrainActor::GetLocalOrigin),
			"Set the Terrains Origin OffSet in Local Coordinates", COORDINATE_CONFIG_GROUP_NAME));

		//LocalGlobeRadius
		AddProperty(new dtDAL::FloatActorProperty("LocalGlobeRadius", "GEO Globe Radius",
			dtDAL::FloatActorProperty::SetFuncType(actor, &PagedTerrainActor::SetLocalGlobeRadius),
			dtDAL::FloatActorProperty::GetFuncType(actor, &PagedTerrainActor::GetLocalGlobeRadius),
			"Set the Globes Radius for Geo Projections", COORDINATE_CONFIG_GROUP_NAME));

		//LocalFlatEarthOrigin
		AddProperty(new dtDAL::Vec2dActorProperty("LocalFlatEarthOrigin", "Local Flat Earth Origin",
			dtDAL::Vec2dActorProperty::SetFuncType(actor, &PagedTerrainActor::SetLocalFlatEarthOrigin),
			dtDAL::Vec2dActorProperty::GetFuncType(actor, &PagedTerrainActor::GetLocalFlatEarthOrigin),
			"Set the Terrains Origin OffSet for Flat Earth Projection", COORDINATE_CONFIG_GROUP_NAME));

		/*
		const std::string CURRENT_PROJECTION_GROUP_NAME = "Current Projection";
		
		//TerrainGeomCoordType
		AddProperty(new dtDAL::EnumActorProperty<dtUtil::LocalCoordinateType>("TerrainGeomCoordType", "Terrains Coordinate Type",
			dtDAL::EnumActorProperty<dtUtil::LocalCoordinateType>::SetFuncType(),//(actor, &PagedTerrainActor::SetLocalCoordinateType),
			dtDAL::EnumActorProperty<dtUtil::LocalCoordinateType>::GetFuncType(actor, &PagedTerrainActor::GetLocalCoordinateType),
			"This is the Projection with which the Terrain Geometry was built", CURRENT_PROJECTION_GROUP_NAME));
		GetProperty("TerrainGeomCoordType")->SetReadOnly(true);
		/*
		CoordConvertingToAndFrom
		TerrainOriginInLocal
		TerrainOriginInConverted
		*/
	}
	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActorProxy::CreateActor()
	{
			SetActor(*new PagedTerrainActor(*this)); 
			//GetActor()->AddedToScene(GetActor()->GetSceneParent());			
	}

	///////////////////////////////////////////////////////////////////////////////
	void PagedTerrainActorProxy::OnEnteredWorld()
	{
		#ifdef _DEBUG
		std::cout<< "PagedTerrainActorProxy::OnEnteredWorld" << std::endl;
		#endif //_DEBUG
		

		//dtGame::GameActorProxy::OnEnteredWorld();
		trCore::GameStaticMeshActorProxy::OnEnteredWorld();

		//Register an invokable for Game Events...
		//RegisterForMessages(dtGame::MessageType::INFO_GAME_EVENT);
		//RegisterForMessagesAboutSelf(dtGame::MessageType::INFO_GAME_EVENT);

		// Register an invokable for tick messages. Local or Remote only, not both!
		if (IsRemote())
		{
			RegisterForMessages(dtGame::MessageType::TICK_REMOTE,
			dtGame::GameActorProxy::TICK_REMOTE_INVOKABLE);
		}
		else
		{
			RegisterForMessages(dtGame::MessageType::TICK_LOCAL,
			dtGame::GameActorProxy::TICK_LOCAL_INVOKABLE);
		}
	}
}


#endif //COREDLL_PAGED_TERRAIN_ACTOR_CPP