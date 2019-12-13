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

#pragma once

#include <trSG/Export.h>

#include <trBase/Base.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/RefStr.h>

namespace trBase
{
    class UserDataContainer;
}

namespace osg
{
    class Group;
    class Node;
    class NodeVisitor;
}

namespace trSG
{
    
    /**
    * Class for wrapping the osg node
    * Internally it contains an OSG Node, that can be accessed by user if additional functionality is required. 
    */
    class TR_SG_EXPORT Node : public trBase::Base
    {
    public:

        using BaseClass = trBase::Base;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
         * @brief   This is a set of bits (flags) that represent the Node. The default value is
         *          0xffffffff (all bits set).
         *          
         *          The most common use of these is during traversal of the scene graph.
         *          
         *          For example, if a Node has a NodeMask value of 0x02 (only 2nd bit set)
         *          and the Camera has a CullMask of 0x4 (2nd bit not set) then during cull traversal,
         *          which takes it's TraversalMask from the Camera's CullMask, the node and any children
         *          would be ignored and thereby treated as "culled" and thus not rendered. Conversely,
         *          if the Camera CullMask were 0x3 (2nd bit set) then the node would be processed and
         *          child Nodes would be examined.
         */
        using NodeMask = unsigned int;

        /**
         * @fn  Node::Node(const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   name    (Optional) The name.
         */
        Node(const std::string name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& Node::GetType() const override;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

        /**
         * @fn  virtual void Node::SetName(const std::string& name);
         *
         * @brief   Sets this instances name.
         *
         * @param   name    The name.
         */
        virtual void SetName(const std::string& name);

        /**
         * @fn  virtual osg::Node* Node::AsOSGNode();
         *
         * @brief   Returns a pointer to the internal OSG Node.
         *
         * @return  Null if it fails, else a pointer to an osg::Node.
         */
        virtual osg::Node* AsOSGNode();

        /**
         * @fn  virtual const osg::Node* Node::AsOSGNode() const;
         *
         * @brief   Returns a constant pointer to the internal OSG Node.
         *
         * @return  Null if it fails, else a pointer to a const osg::Node.
         */
        virtual const osg::Node* AsOSGNode() const;

        /** Visitor Pattern : calls the apply method of a NodeVisitor with this node's type.*/
        //virtual void accept(NodeVisitor& nv);
        
        /** Traverse upwards : calls parents' accept method with NodeVisitor.*/
        //virtual void ascend(NodeVisitor& nv);
        
        /** Traverse downwards : calls children's accept method with NodeVisitor.*/
        //virtual void traverse(NodeVisitor& /*nv*/) {}

    protected:

        trBase::SmrtPtr<osg::Node> mNode;

        /**
         * @fn  Node::~Node();
         *
         * @brief   dtor.
         */
        ~Node();
    };
}

