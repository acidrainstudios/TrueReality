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

#ifndef COREDLL_PAGED_TERRAIN_ACTOR_H
#define COREDLL_PAGED_TERRAIN_ACTOR_H

#include "export.h"

#include "ActorGameStaticMesh.h"
#include <trUtil\vrsMath.h>
#include "vrsCoreActorsRegistry.h"

#include <iostream>
#include <string>
#include <assert.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/actorproxyicon.h>
#include <dtDAL/functor.h>

#include <dtDAL/plugin_export.h>

#include <dtCore/databasepager.h>
#include <dtCore/view.h>

#include <dtUtil/coordinates.h>

#include <dtGame/gamemanager.h>
#include <dtGame/basemessages.h>
#include <dtGame/messagetype.h>

#include <dtABC/application.h>

#include <osg/Group>
#include <osg/PagedLOD>

#include <osgDB/ReadFile>
#include <osgDB/FileUtils>



namespace vrsCore
{
	class CORE_EXPORT PagedTerrainActor : public vrsCore::GameStaticMeshActor
	{
    public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;

		//Default Actors Class Name
		static const std::string ACTOR_CLASS_NAME;

         // Constructor
		PagedTerrainActor(vrsCore::GameStaticMeshActorProxy &proxy);

		// Called when the actor has been added to the game manager.
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();

		/**
		* This method is an invokable for when a local object receives a tick.
		* @param tickMessage A message containing tick related information.
		*/
		virtual void OnTickLocal(const dtGame::TickMessage& tickMessage);

		/**
		* This method is an invokable for when a remote object receives a tick.
		* @param tickMessage A message containing tick related information.
		*/
		virtual void OnTickRemote(const dtGame::TickMessage& tickMessage);
		
		/**
		*Loads the terrain tiles
		*/
        virtual void LoadFile(const std::string &fileName);

		/**
		*Calls Load File if we entered the scene....
		*/
        virtual void AddedToScene(dtCore::Scene* scene);

		 
         
		//////////////////////////////////////////////////////////////////
        // General Properties
        
		void SetPagingMinX(float value){mPaging_Min_X = value;}
		float GetPagingMinX() const {return mPaging_Min_X;}

		void SetPagingMinY(float value){mPaging_Min_Y = value;}
        float GetPagingMinY() const {return mPaging_Min_Y;}
        
		void SetPagingMaxX(float value){mPaging_Max_X = value;}
		float GetPagingMaxX() const {return mPaging_Max_X;}
        
		void SetPagingMaxY(float value){mPaging_Max_Y = value;}
		float GetPagingMaxY() const {return mPaging_Max_Y;}
        
		void SetPagingDelta(float value){mPaging_Delta = value;}
		float GetPagingDelta() const {return mPaging_Delta;}
        
		void SetPagingRange(float value){mPaging_Range = value;}
		float GetPagingRange() const {return mPaging_Range;}
        
		void SetPagingBaseName(const std::string& value) {mPaging_BaseName = value;}
		std::string GetPagingBaseName() const {return mPaging_BaseName;}
        
		void SetPagingExpiringDelay(float value){mPaging_ExpiringDelay = value;}
		float GetPagingExpiringDelay() const {return mPaging_ExpiringDelay;}
        
		void SetPagingFPSTarget(float value){mPaging_Frame_Rate_Targeted = value;}
		float GetPagingFPSTarget() const {return mPaging_Frame_Rate_Targeted;}
        
		void SetPagingPrecompile(bool value) {mPaging_Precompile = value;}
		bool  GetPagingPrecompile() const {return mPaging_Precompile;}
        
		void SetMaxObjectsToCompile(int value){mMaximumObjectsToCompile = value;}
		int   GetMaxObjectsToCompile() const {return mMaximumObjectsToCompile;}
        
		void SetZOffsetforTerrain(float value){mZOffsetForTerrain = value;}
		float GetZOffsetforTerrain() const {return mZOffsetForTerrain;}
        
		void SetTerrainPath(const std::string& value);// {std::cout<< "Terrain SetTerrainPath" << std::endl; mTerrainPath = value;}
		std::string GetTerrainPath() const {return mTerrainPath;}
		
		//////////////////////////////////////////////////////////////////
		//Coordinate Properties
		
		//Sets the Coordinate Type to That we want to Convert from
		void SetIncomingCoordinateType(dtUtil::IncomingCoordinateType& Type);
		//Gets the Coordinate Type to That we want to Convert from
		dtUtil::IncomingCoordinateType& GetIncomingCoordinateType(void) {return const_cast<dtUtil::IncomingCoordinateType&>(mCoord.GetIncomingCoordinateType());}

		//Sets the Coordinate Type to That the Terrain Geometry was built with
		void SetLocalCoordinateType(dtUtil::LocalCoordinateType& Type);
		//Gets the Coordinate Type to That the Terrain Geometry was built with
		dtUtil::LocalCoordinateType& GetLocalCoordinateType(void) {return const_cast<dtUtil::LocalCoordinateType&>(mCoord.GetLocalCoordinateType());}

		//Sets the Terrains UTM Zone
		void SetLocalUTMZone(int Zone);
		//Gets the Terrains UTM Zone
		int GetLocalUTMZone(void) const {return mCoord.GetUTMZone();}

		//Sets the Terrains Hemisphere 'N' or 'S'
		void SetLocalUTMHemisphere(const std::string& Hem);
		//Gets the Terrains Hemisphere 'N' or 'S'
		std::string GetLocalUTMHemisphere(void); 
		//const {return mCoord.GetUTMHemisphere();}

		//Set the Terrain Geometry Origin Offset in Local Coordinate type,
		// x,y,z, phi,lambda,elevation,  lat,lon...etc
		void SetLocalOrigin(osg::Vec3d OriginOffset);
		//Get the Terrain Geometry Origin Offset in Local Coordinate type
		osg::Vec3d GetLocalOrigin(void);

		//Set Earths Radius in meters
		void SetLocalGlobeRadius(float Radius);
		//Get Earths Radius in meters
		float GetLocalGlobeRadius(void) const {return mCoord.GetGlobeRadius();}

		//Set the Local Flat Earth Terrain Origin in Lat, Lon
		void SetLocalFlatEarthOrigin(osg::Vec2d LatLon);
		//Get the Local Flat Earth Terrain Origin in Lat, Lon
		osg::Vec2d GetLocalFlatEarthOrigin(void);

		//Takes the 3 parts of the Translation/Position Vector from the Incoming Coordinate
		//Type and Converts it to 3 parts of the Translation/Position Vector in the Local
		//Coordinate Type (using local origin offset as 0,0,0)
		osg::Vec3 ConvertIncomingToLocalTranslation(osg::Vec3d& Incoming) {return mCoord.ConvertToLocalTranslation(Incoming);}
		
		//Takes the 3 parts of the Rotation Vector from the Incoming Coordinate
		//Type and Converts it to 3 parts of the Rotation Vector in the Local
		//Coordinate Type (takes in PsiThetaPhi in Radians and returns hpr in
		//Degrees)
		osg::Vec3 ConvertIncomingToLocalRotation(osg::Vec3d& PsiThetaPhi) {return mCoord.ConvertToLocalRotation(PsiThetaPhi);}

		//Takes the 3 parts of the Translation/Position Vector from the Local Coordinate
		//(using local origin offset as 0,0,0) Type and Converts it to 3 parts of the 
		//Translation/Position Vector in the Incoming Coordinate Type 
		osg::Vec3d ConvertLocalToIncomingTranslation(osg::Vec3& xyz) {return mCoord.ConvertToRemoteTranslation(xyz);}
		
		//Takes the 3 parts of the Rotation Vector from the Local Coordinate
		//Type and Converts it to 3 parts of the Rotation Vector in the Incoming
		//Coordinate Type (takes in hpr in Degrees, and returns PsiThetaPhi in
		//Radians)
		osg::Vec3d ConvertLocalToIncomingRotation(osg::Vec3& hpr) {return mCoord.ConvertToRemoteRotation(hpr);}
		
	  protected:

        /// Destructor
        virtual ~PagedTerrainActor();

	  private:
        //dtCore::RefPtr
		osg::ref_ptr<osg::Group> mGroupNodeForTerrain;

		std::string mLoadedFile;

        //This doesn't load the file unless it's in a scene, so this flag tells it to load
        bool mNeedToLoad;

		//osg::PagedLOD* pPage;

		float mDeltaSimTime;
		 
        //////////////////////////////////////
        /// Properties 
        float       mPaging_Min_X;
        float       mPaging_Min_Y;
        float       mPaging_Max_X;
        float       mPaging_Max_Y;
        float       mPaging_Delta;
        float       mPaging_Range;
        std::string mPaging_BaseName;
        float       mPaging_ExpiringDelay;
        float       mPaging_Frame_Rate_Targeted;
        bool        mPaging_Precompile;
        int         mMaximumObjectsToCompile;
        float       mZOffsetForTerrain;
        std::string mTerrainPath;
        //////////////////////////////////////

		//Our coordinates converter....
		dtUtil::Coordinates					mCoord;				//Coordinate converter
	};
	//////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	class CORE_EXPORT PagedTerrainActorProxy : public vrsCore::GameStaticMeshActorProxy
    {
	public:
		
		/**
        * Constructor
        */
        PagedTerrainActorProxy();

        /**
        * Adds the properties to the actor.
        */
        virtual void BuildPropertyMap();

        // Creates the actor we are encapsulating
        virtual void CreateActor(); 

     protected:

		// Called when this proxy is added to the game manager (ie, the "world")
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();
			

        /**
        * Destructor
        */
        virtual ~PagedTerrainActorProxy() { }
     };
}

#endif //COREDLL_PAGED_TERRAIN_ACTOR_H
