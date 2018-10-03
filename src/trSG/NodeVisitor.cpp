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
#include <trSG/NodeVisitor.h>

#include <osg/NodeVisitor>

namespace trSG
{
    const trUtil::RefStr NodeVisitor::CLASS_TYPE = trUtil::RefStr("trSG::NodeVisitor");

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::NodeVisitor(const std::string name) : BaseClass(name)
    {
        mNodeVisitor = new osg::NodeVisitor(); //Creates our internal OSG class. 
        mNodeVisitor->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& NodeVisitor::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    void NodeVisitor::SetName(const std::string& name)
    {
        BaseClass::SetName(name);
        mNodeVisitor->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    osg::NodeVisitor* NodeVisitor::AsOSGVisitor()
    {
        return mNodeVisitor.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::NodeVisitor* NodeVisitor::AsOSGVisitor() const
    {
        return mNodeVisitor.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::~NodeVisitor()
    {
    }
}
