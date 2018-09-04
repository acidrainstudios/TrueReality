/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* @author Maxim Serebrennik
*/

#include <trCore\SceneObjects\SkyBoxNode.h>

#include <osg/Depth>
#include <osgUtil/CullVisitor>

namespace trCore
{
    namespace SceneObjects
    {
        //////////////////////////////////////////////////////////////////////////
        SkyBoxNode::SkyBoxNode()
        {
           setCullingActive(false);
           getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
           getStateSet()->setAttributeAndModes(new osg::Depth(osg::Depth::LEQUAL, 1.0f, 1.0f));
           getStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
           getStateSet()->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
           getStateSet()->setRenderBinDetails(INT_MAX, "RenderBin");
           getStateSet()->setRenderBinToInherit();
        }

        //////////////////////////////////////////////////////////////////////////
        bool SkyBoxNode::computeLocalToWorldMatrix(osg::Matrix & matrix, osg::NodeVisitor * nv) const
        {
            if (nv && nv->getVisitorType() == osg::NodeVisitor::CULL_VISITOR)
            {
                osgUtil::CullVisitor* cv = static_cast<osgUtil::CullVisitor*>(nv);
                matrix.preMult(osg::Matrix::translate(cv->getEyeLocal()));
                return true;
            }
            else
            {
                return BaseClass::computeLocalToWorldMatrix(matrix, nv);
            }
        }

        //////////////////////////////////////////////////////////////////////////
        bool SkyBoxNode::computeWorldToLocalMatrix(osg::Matrix & matrix, osg::NodeVisitor * nv) const
        {
            if (nv && nv->getVisitorType() == osg::NodeVisitor::CULL_VISITOR)
            {
                osgUtil::CullVisitor* cv = static_cast<osgUtil::CullVisitor*>(nv);
                matrix.preMult(osg::Matrix::translate(cv->getEyeLocal()));
                return true;
            }
            else
            {
                return BaseClass::computeWorldToLocalMatrix(matrix, nv);
            }
        }

        //////////////////////////////////////////////////////////////////////////
        bool SkyBoxNode::LoadFile(std::string fileName)
        {
            return false;
        }

        //////////////////////////////////////////////////////////////////////////
        SkyBoxNode::~SkyBoxNode()
        {
        }
    }
}