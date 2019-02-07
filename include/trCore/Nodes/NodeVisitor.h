/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
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

#include <trCore/Export.h>

#include <trBase/Base.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/RefStr.h>

namespace osg
{
    class NodeVisitor;
}

namespace trCore::Nodes
{
    /**
     * @class   NodeVisitor
     *
     * @brief   Visitor for type safe operations on trCore::Nodes. Based on GOF's Visitor pattern. The
     *          NodeVisitor is useful for developing type safe operations to nodes in the scene graph
     *          (as per Visitor pattern), and adds to this support for optional scene graph traversal
     *          to allow operations to be applied to whole scenes at once. The Visitor pattern uses a
     *          technique of double dispatch as a mechanism to call the appropriate Apply(..) method
     *          of the NodeVisitor.  To use this feature one must use the Node::Accept(NodeVisitor)
     *          which is extended in each Node subclass, rather than the NodeVisitor apply directly.
     *          So use root->Accept(myVisitor); instead of myVisitor.Apply(*root).  The later method
     *          will bypass the double dispatch and the appropriate NodeVisitor::Apply(..) method
     *          will not be called.
     *
     * @author  Maxim Serebrennik
     */
    class TR_CORE_EXPORT NodeVisitor : public trBase::Base
    {
    public:

        enum TraversalMode
        {
            TRAVERSE_NONE = 0,
            TRAVERSE_PARENTS = 1,
            TRAVERSE_ALL_CHILDREN = 2,
            TRAVERSE_ACTIVE_CHILDREN = 3
        };

        enum VisitorType
        {
            NODE_VISITOR = 0,
            UPDATE_VISITOR = 1,
            EVENT_VISITOR = 2,
            COLLECT_OCCLUDER_VISITOR = 3,
            CULL_VISITOR = 4,
            INTERSECTION_VISITOR = 5
        };

        using BaseClass = trBase::Base;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
         * @fn  NodeVisitor::NodeVisitor(TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   tm      (Optional) The time.
         * @param   name    (Optional) The name.
         */
        NodeVisitor(TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);

        /**
         * @fn  NodeVisitor::NodeVisitor(VisitorType type, TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   type    The type.
         * @param   tm      (Optional) The time.
         * @param   name    (Optional) The name.
         */
        NodeVisitor(VisitorType type, TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& NodeVisitor::GetType() const override;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

        /**
         * @fn  virtual void NodeVisitor::SetName(const std::string& name);
         *
         * @brief   Sets this instances name.
         *
         * @param   name    The name.
         */
        virtual void SetName(const std::string& name);

        /**
         * @fn  virtual osg::NodeVisitor* NodeVisitor::AsOSGVisitor();
         *
         * @brief   Returns a pointer to the internal OSG Node.
         *
         * @return  Null if it fails, else a pointer to an osg::Node.
         */
        virtual osg::NodeVisitor* AsOSGVisitor();

        /**
         * @fn  virtual const osg::NodeVisitor* NodeVisitor::AsOSGVisitor() const;
         *
         * @brief   Returns a constant pointer to the internal OSG Node.
         *
         * @return  Null if it fails, else a pointer to a const osg::Node.
         */
        virtual const osg::NodeVisitor* AsOSGVisitor() const;

        /**
         * @fn  virtual void NodeVisitor::Reset();
         *
         * @brief   Method to call to reset visitor. Useful if your visitor accumulates state during a
         *          traversal, and you plan to reuse the visitor. To flush that state for the next
         *          traversal: call reset() prior to each traversal.
         */
        virtual void Reset();

        /**
         * @fn  inline void NodeVisitor::SetVisitorType(VisitorType type);
         *
         * @brief   Set the VisitorType, used to distinguish different visitors during traversal of the
         *          scene, typically used in the Node:Traverse() method to select which behavior to use
         *          for different types of traversal/visitors.
         *
         * @param   type    The type.
         */
        inline void SetVisitorType(VisitorType type);

        /**
         * @fn  inline VisitorType NodeVisitor::GetVisitorType() const;
         *
         * @brief   Get the VisitorType.
         *
         * @return  The visitor type.
         */
        inline VisitorType GetVisitorType() const;

    protected:

        trBase::SmrtPtr<osg::NodeVisitor> mNodeVisitor;

        /**
         * @fn  NodeVisitor::~NodeVisitor();
         *
         * @brief   Destructor.
         */
        ~NodeVisitor();
    };
}

