/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
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

#include <trCore/Nodes/Node.h>

#include <trBase/Base.h>

#include <osg/Group>
#include <osg/Node>

namespace trCore::Nodes
{
    const trUtil::RefStr Node::CLASS_TYPE = trUtil::RefStr("trCore::Nodes::Node");

    //////////////////////////////////////////////////////////////////////////
    Node::Node(const std::string name) : BaseClass(name)
    {
        mNode = new osg::Group(); //Creates our internal OSG node. 
        mNode->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    Node::Node(osg::Node& node, const std::string name) : Node(name)
    {
        mNode = &node;
    }

    //////////////////////////////////////////////////////////////////////////
    Node::~Node()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& Node::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    void Node::SetName(const std::string& name)
    {
        BaseClass::SetName(name);
        mNode->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    osg::Node* Node::AsOSGNode()
    {
        return mNode.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::Node* Node::AsOSGNode() const
    {
        return mNode.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    void Node::Accept(osg::NodeVisitor& nv)
    {
        mNode->accept(nv);
    }

    //////////////////////////////////////////////////////////////////////////
    void Node::Ascend(osg::NodeVisitor& nv)
    {
        mNode->ascend(nv);
    }

    //////////////////////////////////////////////////////////////////////////
    void Node::Traverse(osg::NodeVisitor& nv)
    {
        mNode->traverse(nv);
    }
}