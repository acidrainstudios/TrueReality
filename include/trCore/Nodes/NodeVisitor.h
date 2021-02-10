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
#pragma once

#include <trCore/Export.h>

#include <trBase/Base.h>
#include <trBase/SmrtPtr.h>
#include <trBase/Vec3.h>
#include <trCore/Nodes/FrameStamp.h>
#include <trCore/Nodes/Node.h>
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

        /**
         * @fn  inline void NodeVisitor::SetTraversalNumber(unsigned int fn);
         *
         * @brief   Set the traversal number. Typically used to denote the frame count.
         *
         * @param   fn  The function.
         */
        inline void SetTraversalNumber(unsigned int fn);

        /**
         * @fn  inline unsigned int NodeVisitor::GetTraversalNumber() const;
         *
         * @brief   Get the traversal number. Typically used to denote the frame count.
         *
         * @return  The traversal number.
         */
        inline unsigned int GetTraversalNumber() const;

        /**
         * @fn  inline void NodeVisitor::SetFrameStamp(FrameStamp* fs);
         *
         * @brief   Set the FrameStamp that this traversal is associated with.
         *
         * @param [in,out]  fs  If non-null, the file system.
         */
        inline void SetFrameStamp(FrameStamp* fs);

        /**
         * @fn  inline const FrameStamp* NodeVisitor::GetFrameStamp() const;
         *
         * @brief   Get the FrameStamp that this traversal is associated with.
         *          NOTE: The user must handle the destruction of the returned pointer
         *
         * @return  Null if it fails, else the frame stamp.
         */
        inline const FrameStamp* GetFrameStamp() const;

        /**
         * @fn  inline void NodeVisitor::SetTraversalMask(Node::NodeMask mask);
         *
         * @brief   Set the TraversalMask of this NodeVisitor. The TraversalMask is used by the
         *          NodeVisitor::ValidNodeMask() method to determine whether to operate on a node and its
         *          subgraph. ValidNodeMask() is called automatically in the Node::Accept() method before
         *          any call to NodeVisitor::Apply(), Apply() is only ever called if ValidNodeMask
         *          returns true. Note, if NodeVisitor::_traversalMask is 0 then all operations will be
         *          switched off for all nodes.  Whereas setting both _traversalMask and
         *          _nodeMaskOverride to 0xffffffff will allow a visitor to work on all nodes regardless
         *          of their own Node::_nodeMask state.
         *
         * @param   mask    The mask.
         */
        inline void SetTraversalMask(Node::NodeMask mask);

        /**
         * @fn  inline Node::NodeMask NodeVisitor::GetTraversalMask() const;
         *
         * @brief   Get the TraversalMask.
         *
         * @return  The traversal mask.
         */
        inline Node::NodeMask GetTraversalMask() const;

        /**
         * @fn  inline void NodeVisitor::setNodeMaskOverride(Node::NodeMask mask);
         *
         * @brief   Set the NodeMaskOverride mask. Used in ValidNodeMask() to determine whether to
         *          operate on a node or its subgraph, by OR'ing NodeVisitor::_nodeMaskOverride with the
         *          Node's own Node::_nodeMask. Typically used to force on nodes which may have been
         *          switched off by their own Node::_nodeMask.
         *
         * @param   mask    The mask.
         */
        inline void SetNodeMaskOverride(Node::NodeMask mask);

        /**
         * @fn  inline Node::NodeMask NodeVisitor::getNodeMaskOverride() const;
         *
         * @brief   Get the NodeMaskOverride mask.
         *
         * @return  The node mask override.
         */
        inline Node::NodeMask GetNodeMaskOverride() const;

        /**
         * @fn  inline bool NodeVisitor::ValidNodeMask(const Nodes::Node& node) const;
         *
         * @brief   Method to called by Node and its subclass' Node::Accept() method, if the result is
         *          true it is used to cull operations of nodes and their subgraphs. Return true if the
         *          result of a bit wise and of the NodeVisitor::_traversalMask with the bit or between
         *          NodeVistor::_nodeMaskOverride and the Node::_nodeMask. Default values for
         *          _traversalMask is 0xffffffff, _nodeMaskOverride is 0x0, and osg::Node::_nodeMask is
         *          0xffffffff.
         *
         * @param   node    The node.
         *
         * @return  True if it succeeds, false if it fails.
         */
        inline bool ValidNodeMask(const Nodes::Node& node) const;

        /**
         * @fn  inline void NodeVisitor::SetTraversalMode(TraversalMode mode);
         *
         * @brief   Set the traversal mode for Node::Traverse() to use when deciding which children of a
         *          node to traverse. If a NodeVisitor has been attached via SetTraverseVisitor()
         *          and the new mode is not TRAVERSE_VISITOR then the attached visitor is detached.
         *          Default mode is TRAVERSE_NONE.
         *
         * @param   mode    The mode.
         */
        inline void SetTraversalMode(TraversalMode mode);

        /**
         * @fn  inline TraversalMode NodeVisitor::GetTraversalMode() const;
         *
         * @brief   Get the traversal mode.
         *
         * @return  The traversal mode.
         */
        inline TraversalMode GetTraversalMode() const;

        /**
         * @fn  inline void NodeVisitor::Traverse(Node& node);
         *
         * @brief   Method for handling traversal of a nodes. If you intend to use the visitor for
         *          actively traversing the scene graph then make sure the Accept() methods call this
         *          method unless they handle traversal directly.
         *
         * @param [in,out]  node    The node.
         */
        inline void Traverse(Node& node);

        /**
         * @fn  inline void NodeVisitor::PushOntoNodePath(Node* node);
         *
         * @brief   Method called by Node::Accept() method before a call to the NodeVisitor::Apply(..).
         *          The back of the list will, therefore, be the current node being visited inside the
         *          Apply(..), and the rest of the list will be the parental sequence of nodes from the
         *          top most node applied down the graph to the current node. Note, the user does not
         *          typically call PushNodeOnPath() as it will be called automatically by the
         *          Node::Accept() method.
         *
         * @param [in,out]  node    If non-null, the node.
         */
        inline void PushOntoNodePath(Node* node);

        /**
         * @fn  inline void NodeVisitor::PopFromNodePath();
         *
         * @brief   Method called by Node::Accept() method after a call to NodeVisitor::Apply(..). Note,
         *          the user does not typically call PopFromNodePath() as it will be called automatically
         *          by the Node::Accept() method.
         */
        inline void PopFromNodePath();

        /**
         * @fn  NodePath* NodeVisitor::GetNodePath();
         *
         * @brief   Get the non const NodePath from the top most node applied down to the current Node
         *          being visited.
         *
         * @return  The node path. It is up to the user to take control of the pointers life cycle to
         *          make sure there are no memory leaks.
         */
        NodePath* GetNodePath();

        /**
         * @fn  const NodePath* NodeVisitor::GetNodePath() const;
         *
         * @brief   Get the const NodePath from the top most node applied down to the current Node being
         *          visited.
         *
         * @return  The node path. It is up to the user to take control of the pointers life cycle to
         *          make sure there are no memory leaks.
         */
        const NodePath* GetNodePath() const;

        /**
         * @fn  virtual trBase::Vec3 NodeVisitor::GetEyePoint() const
         *
         * @brief   Get the eye point in local coordinates. Note, not all NodeVisitor implement this
         *          method, it is mainly cull visitors which will implement.
         *
         * @return  The eye point.
         */
        virtual trBase::Vec3 GetEyePoint() const { return trBase::Vec3(0.0f, 0.0f, 0.0f); }

        /**
         * @fn  virtual trBase::Vec3 NodeVisitor::GetViewPoint() const
         *
         * @brief   Get the view point in local coordinates. Note, not all NodeVisitor implement this
         *          method, it is mainly cull visitors which will implement.
         *
         * @return  The view point.
         */
        virtual trBase::Vec3 GetViewPoint() const { return GetEyePoint(); }

        /**
         * @fn  virtual float NodeVisitor::GetDistanceToEyePoint(const trBase::Vec3& , bool ) const
         *
         * @brief   Get the distance from a point to the eye point, distance value in local coordinate
         *          system. Note, not all NodeVisitor implement this method, it is mainly cull visitors
         *          which will implement. If the GetDistanceFromEyePoint(pos) is not implemented then a
         *          default value of 0.0 is returned.
         *
         * @param   parameter1  The first parameter.
         * @param   parameter2  True to parameter 2.
         *
         * @return  The distance to eye point.
         */
        virtual float GetDistanceToEyePoint(const trBase::Vec3& /*pos*/, bool /*useLODScale*/) const { return 0.0f; }

        /**
         * @fn  virtual float NodeVisitor::GetDistanceFromEyePoint(const trBase::Vec3& , bool ) const
         *
         * @brief   Get the distance of a point from the eye point, distance value in the eye coordinate
         *          system. Note, not all NodeVisitor implement this method, it is mainly cull visitors
         *          which will implement. If the GetDistanceFromEyePoint(pos) is not implemented than a
         *          default value of 0.0 is returned.*.
         *
         * @param   parameter1  The first parameter.
         * @param   parameter2  True to parameter 2.
         *
         * @return  The distance from eye point.
         */
        virtual float GetDistanceFromEyePoint(const trBase::Vec3& /*pos*/, bool /*useLODScale*/) const { return 0.0f; }

        /**
         * @fn  virtual float NodeVisitor::GetDistanceToViewPoint(const trBase::Vec3& , bool ) const
         *
         * @brief   Get the distance from a point to the view point, distance value in local coordinate
         *          system. Note, not all NodeVisitor implement this method, it is mainly cull visitors
         *          which will implement. If the GetDistanceToViewPoint(pos) is not implemented then a
         *          default value of 0.0 is returned.*.
         *
         * @param   parameter1  The first parameter.
         * @param   parameter2  True to parameter 2.
         *
         * @return  The distance to view point.
         */
        virtual float GetDistanceToViewPoint(const trBase::Vec3& /*pos*/, bool /*useLODScale*/) const { return 0.0f; }

    protected:

        /** @brief   The node visitor. */
        trBase::SmrtPtr<osg::NodeVisitor> mNodeVisitor;

        /**
         * @fn  NodeVisitor::~NodeVisitor();
         *
         * @brief   Destructor.
         */
        ~NodeVisitor();
    };
}