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

#ifndef VRS_TERRAIN_CULL_VISITOR_CPP
#define VRS_TERRAIN_CULL_VISITOR_CPP

#include "../Include/SimCoreCullVisitor.h"
#include <osg/Billboard>
#include <osg/ProxyNode>


///////////////////////////////////////////////////////////////////////////
SimCoreCullVisitor::SimCoreCullVisitor() : CullVisitor()
  , mCurrentlyInTerrain(false)
  , mCameraPosition()
  , mRadius(1250)
  , mPagingDistance(7500)
  , mCheckTerrainAmount(30)
  , mTerrainStep(0)
  , mRunFinalizeTerrain(false)
  , mHitProxyNode(false)
  , mEnablePhysics(true)
{
}

SimCoreCullVisitor::~SimCoreCullVisitor()
{

}

///////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::SetEnablePhysics(bool b)
{
  mEnablePhysics = b;
}

///////////////////////////////////////////////////////////////////////////
bool SimCoreCullVisitor::GetEnablePhysics() const
{
  return mEnablePhysics;
}

///////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::SetCookingRadius(float radius)
{
  mRadius = radius;
}

///////////////////////////////////////////////////////////////////////////
float SimCoreCullVisitor::GetCookingRadius() const
{
  return mRadius;
}

///////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::SetCullRadius(float radius)
{
  mPagingDistance = radius;
}

///////////////////////////////////////////////////////////////////////////
float SimCoreCullVisitor::GetCullRadius() const
{
  return mPagingDistance;
}

///////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::SetFrameDelay(int delay)
{
  mCheckTerrainAmount = delay;
}

///////////////////////////////////////////////////////////////////////////
int SimCoreCullVisitor::GetFrameDelay() const
{
  return mCheckTerrainAmount;
}

///////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::apply(osg::Transform& node)
{
  if(mTerrainNode.valid() 
     && ++mTerrainStep > mCheckTerrainAmount
     && mLandActor.valid())
  {
     if(&node == mTerrainNode.get())
     {
        mTerrainStep = 0;
        
        if(mEnablePhysics)
        {
           mLandActor->ResetTerrainIterator();
        }

        mCurrentlyInTerrain = true;
        mRunFinalizeTerrain = true;
     }
  }

  osgUtil::CullVisitor::apply(node);
  
  if(&node == mTerrainNode.get())
  {
     mCurrentlyInTerrain = false;
  }

  if(mEnablePhysics && mCurrentlyInTerrain == false && mRunFinalizeTerrain && mLandActor.valid())
  {
     mRunFinalizeTerrain = mLandActor->FinalizeTerrain(mCheckTerrainAmount - 1);
  }
}

///////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::apply(osg::Geode& node)
{
  // Terrex terrain for example
  if(mEnablePhysics)
  {
     if(mLandActor.valid() && mCurrentlyInTerrain && node.getBoundingBox().valid())
     {
        osg::Vec3 position = node.getBoundingBox().center() - GetCameraTransform();

        osg::Matrix absMatrix;
        if(mHitProxyNode)
        {
           osg::NodePath& nodePath = getNodePath();
           absMatrix.set( osg::computeLocalToWorld(nodePath) );
           position = (node.getBoundingBox().center() + absMatrix.getTrans()) - GetCameraTransform();
        }

        if( position.length() <= mRadius)
        {
           mLandActor->CheckGeode(node, mHitProxyNode, absMatrix);
        }
     }
     // ive terrain for example
     else if(mLandActor.valid() && mCurrentlyInTerrain && node.getBound().valid())
     {
        osg::Vec3 position = node.getBound().center() - GetCameraTransform();
        
        osg::Matrix absMatrix;
        if(mHitProxyNode)
        {
           osg::NodePath& nodePath = getNodePath();
           absMatrix.set( osg::computeLocalToWorld(nodePath) );
           position = (node.getBound().center() + absMatrix.getTrans()) - GetCameraTransform();
        }

        if( position.length() <= mRadius)
        {
           mLandActor->CheckGeode(node, mHitProxyNode, absMatrix);
        }
     }
  }

  osgUtil::CullVisitor::apply(node);
}

/////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::apply(osg::Group& node)
{
  bool hitframeDontCallOtherCull  = false;
  if(mCurrentlyInTerrain)
  {
     osg::ProxyNode* proxyNode = dynamic_cast<osg::ProxyNode*>(&node);
     if(proxyNode != NULL)
     {
        mHitProxyNode = true;
        osgUtil::CullVisitor::apply(node);
        hitframeDontCallOtherCull = true;
        mHitProxyNode = false;
     }
  }

  if(hitframeDontCallOtherCull == false)
     osgUtil::CullVisitor::apply(node);
}

/////////////////////////////////////////////////////////////////////////
void SimCoreCullVisitor::apply(osg::LOD& node)
{
  if(mLandActor.valid() && mCurrentlyInTerrain)
  {
     osg::Vec3 position = node.getCenter() - GetCameraTransform();

     if( position.length() > mPagingDistance)
     {
        osgUtil::CullVisitor::apply(node);
        return;
     }

     // push the culling mode.
     pushCurrentMask();

     // push the node's state.
     osg::StateSet* node_state = node.getStateSet();
     if (node_state) pushStateSet(node_state);

     handle_cull_callbacks_and_traverse(node);

     // pop the node's state off the render graph stack.    
     if (node_state) popStateSet();

     // pop the culling mode.
     popCurrentMask();
  }
  else
  {
     osgUtil::CullVisitor::apply(node);
  }
}


#endif

