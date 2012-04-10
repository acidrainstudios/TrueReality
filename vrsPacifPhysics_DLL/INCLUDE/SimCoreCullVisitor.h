/* -*-c++-*-
* Simulation Core
* Copyright 2007-2008, Alion Science and Technology
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
* This software was developed by Alion Science and Technology Corporation under
* circumstances in which the U. S. Government may have rights in the software.
* @author Allen Danklefsen
*/
#ifndef VRS_TERRAIN_CULL_VISITOR_H
#define VRS_TERRAIN_CULL_VISITOR_H

#include "export.h"
#include <dtCore/observerptr.h>
#include "../Include/PagedTerrainPhysicsActor.h"
#include <osgUtil/CullVisitor>
#include <osg/Transform>
#include <osg/Geode>
#include <osg/Vec3>
#include <osg/LOD>


///////////////////////////////////////////////////////////////////////////////
class VRS_PACIFPHYSICS_EXPORT SimCoreCullVisitor : public osgUtil::CullVisitor
{
  public:
     /// Constructor
     SimCoreCullVisitor();

     /// In Here we load objects within radius to physics
     virtual void apply(osg::Geode& node);

     /// In here we check the top lvl node and finalize the physics terrain
     virtual void apply(osg::Transform& node);

     /// In here we let tiles in our range pass through so we keep them in range
     virtual void apply(osg::LOD& node);

     /// Used for proxy node tests.
     virtual void apply(osg::Group& node);

     /// Set and Get For the land Actor
     void SetLandActor(PagedTerrainPhysicsActor* land) {mLandActor = land;}
     PagedTerrainPhysicsActor* GetLandActor() {return mLandActor.get();}

     /// Set and get for the terrain node
     void SetTerrainNode(osg::Transform* terrainNodeCheckAgainst){mTerrainNode = terrainNodeCheckAgainst;}
     osg::Node* GetTerrainNode() {return mTerrainNode.get();}

          /// Set and get for the camera transform
     void SetCameraTransform(const osg::Vec3& camTransform) {mCameraPosition = camTransform;}
     osg::Vec3 GetCameraTransform() const {return mCameraPosition;}

     ///this will enable cooking and sending the terrain vertex data to Ageia for collision detection
     void SetEnablePhysics(bool);
     bool GetEnablePhysics() const;

     ///this will set the radius at which tiles from the terrain will be sent to the physics engine for collision
     void SetCookingRadius(float);
     float GetCookingRadius() const;

     ///this controls the radius at which we will perform culling and marking terrain tiles
     void SetCullRadius(float);
     float GetCullRadius() const;

     ///this controls how often we update the scene with the frame stamps relative to our radius
     void SetFrameDelay(int);
     int GetFrameDelay() const;

	 void SetPagingRange(float range) { mPagingDistance = range; }


  protected:
     /// Destructor
     virtual ~SimCoreCullVisitor();

  private:
     /// we feed the terrain data through here, it loads the physics
     dtCore::ObserverPtr<PagedTerrainPhysicsActor>  mLandActor;

     /// this is the top level transform node of the terrain, for knowing when
     /// we are in the terrain
     dtCore::ObserverPtr<osg::Transform>             mTerrainNode;

     /// are we in the terrain currently? mNodeWeCheckAgainst passed, so work
     /// is being done this frame
     bool                                            mCurrentlyInTerrain;

     /// The camera position we test for distance for lod calculations
     osg::Vec3                                       mCameraPosition;

     /// radius check for loading tiles to physics
     float                                             mRadius;//  = 1250;

     /// radius check for paging in tiles
     float                                             mPagingDistance;// = 7500;

     /// How often we do terrain stuff....
     int                                             mCheckTerrainAmount;// = 30;

     /// iter used with mCheckTerrainAmount
     int                                             mTerrainStep;

     /// Set to true when mTerrainStep > mCheckTerrainAmount , and both
     /// observer nodes are valid, then set to true or false, if the loading
     /// of the mLandActor->FinalizeTerrain is complete.
     bool                                            mRunFinalizeTerrain;

     /// This is for proxy nodes that arent loaded into the basic geode structure
     /// of the terrain.
     bool                                            mHitProxyNode;

     ///setting this flag will enable the cull visitor to upload the terrain tiles to Ageia
     bool                                            mEnablePhysics;
};

#endif

