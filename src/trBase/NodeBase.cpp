/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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

#include <trBase/NodeBase.h>

namespace trBase
{
    const trUtil::RefStr NodeBase::CLASS_TYPE = trUtil::RefStr("trBase::NodeBase");

    //////////////////////////////////////////////////////////////////////////
    NodeBase::NodeBase(const std::string name) : BaseClass(name)
    {
        mNode = new osg::Node(); //Creates our internal OSG node.
        mNode->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    NodeBase::~NodeBase()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& NodeBase::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    void NodeBase::SetName(const std::string& name)
    {
        BaseClass::SetName(name);
        mNode->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    osg::Node* NodeBase::AsOSGNode()
    {
        return mNode.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::Node* NodeBase::AsOSGNode() const
    {
        return mNode.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    trBase::UserDataContainer* NodeBase::GetUserData()
    {
        return mUserData;
    }

    //////////////////////////////////////////////////////////////////////////
    const trBase::UserDataContainer* NodeBase::GetUserData() const
    {
        return mUserData;
    }

    //////////////////////////////////////////////////////////////////////////
    void NodeBase::SetUserData(trBase::UserDataContainer* data)
    {
        mUserData = data;
    }

    //////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
}
