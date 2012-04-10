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
#ifndef _VRS_PAGED_TERRA_ACTOR_H
#define _VRS_PAGED_TERRA_ACTOR_H


#include "export.h"

#include <dtPhysics/physicshelper.h>

#include <osgDB/Registry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/TriangleFunctor>

#include <map>

#include <dtGame/gameactor.h>


////////////////////////////////////////////////////
// Export symbol not needed, this should not be used
// by external libraries
class TerrainNode : public osg::Referenced
{
 public:
    TerrainNode(osg::Geode* toSet);

 protected:
    ~TerrainNode();

 public:
    ///////////////////////////////////
    enum TILE_TODO
    {
       TILE_TODO_DISABLE = 0,
       TILE_TODO_KEEP,
       TILE_TODO_LOAD
    };

    /////////////////////////////////////////////////////////////////////////
    bool  IsFilled() const {return mFilledBL;}
    void  SetFilled(bool value) {mFilledBL = value;}

    /////////////////////////////////////////////////////////////////////////
    osg::Geode* GetGeodePointer()
    {
       if(mGeodePTR.valid())
          return mGeodePTR.get();
       return NULL;
    }

    /////////////////////////////////////////////////////////////////////////
    void SetFlags(char value)  {mFlags = value;}
    char GetFlags() const {return mFlags;}

    /////////////////////////////////////////////////////////////////////////
    void SetFlagsToKeep()    {mFlags = TILE_TODO_KEEP;}
    void SetFlagsToLoad()    {mFlags = TILE_TODO_LOAD;}
    void SetFlagsToDisable() {mFlags = TILE_TODO_DISABLE;}

    /////////////////////////////////////////////////////////////////////////
    const dtCore::UniqueId& GetUniqueID() const {return mUniqueID;}

    /////////////////////////////////////////////////////////////////////////
    void SetPhysicsObject(dtPhysics::PhysicsObject* object) {mPhysicsObject = object;}

    dtPhysics::PhysicsObject* GetPhysicsObject() {return mPhysicsObject.get();}
 private:
    dtCore::RefPtr<dtPhysics::PhysicsObject> mPhysicsObject;

    osg::observer_ptr<osg::Geode>    mGeodePTR;
    bool                             mFilledBL;
    char                             mFlags;
    dtCore::UniqueId                 mUniqueID;
};

////////////////////////////////////////////////////////////////////
//class NxAgeiaTerraPageListener;
class VRS_PACIFPHYSICS_EXPORT PagedTerrainPhysicsActor : public dtGame::GameActor
{
 public:
    static const std::string DEFAULT_NAME;
    /// Constructor
    PagedTerrainPhysicsActor(dtGame::GameActorProxy &proxy);

 protected:
    /// Destructor
    virtual ~PagedTerrainPhysicsActor(void);


 public:

    // internally called functions when a terrain tile is loaded into the system
    // Used to be called ParseTerrainNode
    dtPhysics::PhysicsObject* BuildTerrainAsStaticMesh(osg::Node* nodeToParse, const std::string& nameOfNode, bool buildGeodesSeparately);
    // Add a single node, as opposed to a soup. Usually done at the geode level.
    dtPhysics::PhysicsObject* AddTerrainNode(osg::Node* node, const std::string& nameOfNode);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

    /// determine if we want to use these hard coded materials and load to physics
    bool PassThisGeometry(int fid, int smc, int soilTemperatureAndPressure,
             int soilWaterContent);

    /// should this be a group or just heightfield.
    void DetermineHowToLoadGeometry(int fid, int smc,
             int soilTemperatureAndPressure, int soilWaterContent, osg::Node* nodeToLoad);

    /// should we load the geom as a group (buildings)
    bool LoadGeomAsGroup(int fid);

    /// for the Hmmwv ground sim actor
    bool HasSomethingBeenLoaded() {return mLoadedTerrainYet;}

    /// geode - loads a single geode into the physics engine. Usually called from the Cull Visitor when it decides to physics something
    void CheckGeode(osg::Geode& node, bool loadNow, const osg::Matrix& matrixForTransform);

    /// Clears all of the geodes and/or the static meshes physics objects - call on map reload or similar
    void ClearAllTerrainPhysics();

    // reset terrain iterator so we can start at the beginning
    // and subdivide the work being done.
    void ResetTerrainIterator();

    /// called to act on the flags.
    bool FinalizeTerrain(int amountOfFrames);

    // public accessor to get the variable
    dtPhysics::PhysicsHelper* GetPhysicsHelper() const {return mPhysicsHelper.get();}

 private:
    // our physics helper
    dtCore::RefPtr<dtPhysics::PhysicsHelper> mPhysicsHelper;
    // shouldnt be called, only for debugging purposes.
    // reloads all terrain to physics during runtimne
    void ReloadTerrainPhysics();

    // for the hmmwv sim
    bool mLoadedTerrainYet;

    int mNumNodesLoaded;
    int mNumVertsLoaded;

    // our map nodes
    std::map<osg::Geode*, dtCore::RefPtr<TerrainNode> > mTerrainMap;

    std::map<osg::Geode*, dtCore::RefPtr<TerrainNode> >::iterator mFinalizeTerrainIter;
};


///////////////////////////////////////////////////////////////////////////
// Proxy
///////////////////////////////////////////////////////////////////////////
class VRS_PACIFPHYSICS_EXPORT PagedTerrainPhysicsActorProxy : public dtGame::GameActorProxy
{
 public:
    PagedTerrainPhysicsActorProxy();
    virtual void BuildPropertyMap();

 protected:
    virtual ~PagedTerrainPhysicsActorProxy();
    void CreateActor();
    virtual void OnEnteredWorld();
};

#endif

