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

#pragma once

#include "Export.h"

#include <trBase/UserDataContainer.h>
#include <trBase/SmrtPtr.h>
#include <trBase/Base.h>
#include <trUtil/RefStr.h>

#include <osg/Node>

namespace trBase
{
    
    /**
    * Base class for creating all the scenegraphs nodes.
    * Internally it contains an OSG Node, that can be accessed by user if additional functionality is required. 
    */
    class TR_BASE_EXPORT NodeBase : public trBase::Base
    {
    public:

        typedef trBase::Base BaseClass;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
        * This is a set of bits (flags) that represent the Node.
        * The default value is 0xffffffff (all bits set).
        *
        * The most common use of these is during traversal of the scene graph.
        *
        * For example, if a Node has a NodeMask value of 0x02 (only 2nd bit set)
        * and the Camera has a CullMask of 0x4 (2nd bit not set) then during cull traversal,
        * which takes it's TraversalMask from the Camera's CullMask, the node and any children
        * would be ignored and thereby treated as "culled" and thus not rendered.
        * Conversely, if the Camera CullMask were 0x3 (2nd bit set) then the node
        * would be processed and child Nodes would be examined.
        */
        typedef osg::Node::NodeMask NodeMask;           

        /**
        * ctor
        */
        NodeBase(const std::string name = CLASS_TYPE);

        /**
        * Returns the class type
        */
        virtual const std::string& GetType() const override;

        /**
        * Sets this instances name
        */
        virtual void SetName(const std::string& name);

        /**
        * Returns a pointer to the internal OSG Node
        */
        virtual osg::Node* AsOSGNode();
        
        /**
        * Returns a constant pointer to the internal OSG Node
        */
        virtual const osg::Node* AsOSGNode() const;

        /**
        * Returns the custom user data that could be stored in the class instance
        * Note, that if the user did not set any data, a NULL will be returned
        */
        virtual trBase::UserDataContainer* GetUserData();

        /**
        * Returns the custom user data that could be stored in the class instance
        * Note, that if the user did not set any data, a NULL will be returned
        */
        virtual const trBase::UserDataContainer* GetUserData() const;

        /**
        * Sets the user data for the current instance 
        */
        virtual void SetUserData(trBase::UserDataContainer* data);

    protected:

        trBase::SmrtPtr<osg::Node> mNode;

        /**
        * dtor
        */
        ~NodeBase();

    private:

        trBase::SmrtPtr<trBase::UserDataContainer> mUserData;
    };
}

