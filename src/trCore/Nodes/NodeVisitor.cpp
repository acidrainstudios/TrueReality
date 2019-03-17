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
#include <trCore/Nodes/NodeVisitor.h>

#include <osg/Group>
#include <osg/Node>
#include <osg/NodeVisitor>

namespace trCore::Nodes
{
    /**
     * @fn  osg::NodeVisitor::VisitorType ToVisitorType(VisitorType type);
     *
     * @brief   Converts a TR visitor type to an osg visitor type.
     *
     * @param   type    The visitor type.
     *
     * @return  Type as an osg::NodeVisitor::VisitorType.
     */
    osg::NodeVisitor::VisitorType ToVisitorType(NodeVisitor::VisitorType type)
    {
        switch (type)
        {
        case NodeVisitor::VisitorType::NODE_VISITOR:
            return osg::NodeVisitor::VisitorType::NODE_VISITOR;
            break;
        case NodeVisitor::VisitorType::UPDATE_VISITOR:
            return osg::NodeVisitor::VisitorType::UPDATE_VISITOR;
            break;
        case NodeVisitor::VisitorType::EVENT_VISITOR:
            return osg::NodeVisitor::VisitorType::EVENT_VISITOR;
            break;
        case NodeVisitor::VisitorType::COLLECT_OCCLUDER_VISITOR:
            return osg::NodeVisitor::VisitorType::COLLECT_OCCLUDER_VISITOR;
            break;
        case NodeVisitor::VisitorType::CULL_VISITOR:
            return osg::NodeVisitor::VisitorType::CULL_VISITOR;
            break;
        case NodeVisitor::VisitorType::INTERSECTION_VISITOR:
            return osg::NodeVisitor::VisitorType::INTERSECTION_VISITOR;
            break;
        default:
            return osg::NodeVisitor::VisitorType::NODE_VISITOR;
            break;
        }
    }

    /**
     * @fn  NodeVisitor::VisitorType ToVisitorType(osg::NodeVisitor::VisitorType type)
     *
     * @brief   Converts an osg visitor type to a TR visitor type.
     *
     * @param   type    The type.
     *
     * @return  Type as a NodeVisitor::VisitorType.
     */
    NodeVisitor::VisitorType ToVisitorType(osg::NodeVisitor::VisitorType type)
    {
        switch (type)
        {
        case osg::NodeVisitor::VisitorType::NODE_VISITOR:
            return NodeVisitor::VisitorType::NODE_VISITOR;
            break;
        case osg::NodeVisitor::VisitorType::UPDATE_VISITOR:
            return NodeVisitor::VisitorType::UPDATE_VISITOR;
            break;
        case osg::NodeVisitor::VisitorType::EVENT_VISITOR:
            return NodeVisitor::VisitorType::EVENT_VISITOR;
            break;
        case osg::NodeVisitor::VisitorType::COLLECT_OCCLUDER_VISITOR:
            return NodeVisitor::VisitorType::COLLECT_OCCLUDER_VISITOR;
            break;
        case osg::NodeVisitor::VisitorType::CULL_VISITOR:
            return NodeVisitor::VisitorType::CULL_VISITOR;
            break;
        case osg::NodeVisitor::VisitorType::INTERSECTION_VISITOR:
            return NodeVisitor::VisitorType::INTERSECTION_VISITOR;
            break;
        default:
            return NodeVisitor::VisitorType::NODE_VISITOR;
            break;
        }
    }

    /**
     * @fn  osg::NodeVisitor::TraversalMode ToTraversalMode(NodeVisitor::TraversalMode type)
     *
     * @brief   Converts TR traversal mode to a osg traversal mode.
     *
     * @param   type    The type.
     *
     * @return  Type as an osg::NodeVisitor::TraversalMode.
     */
    osg::NodeVisitor::TraversalMode ToTraversalMode(NodeVisitor::TraversalMode mode)
    {
        switch (mode)
        {
        case NodeVisitor::TraversalMode::TRAVERSE_NONE:
            return osg::NodeVisitor::TraversalMode::TRAVERSE_NONE;
            break;
        case NodeVisitor::TraversalMode::TRAVERSE_PARENTS:
            return osg::NodeVisitor::TraversalMode::TRAVERSE_PARENTS;
            break;
        case NodeVisitor::TraversalMode::TRAVERSE_ALL_CHILDREN:
            return osg::NodeVisitor::TraversalMode::TRAVERSE_ALL_CHILDREN;
            break;
        case NodeVisitor::TraversalMode::TRAVERSE_ACTIVE_CHILDREN:
            return osg::NodeVisitor::TraversalMode::TRAVERSE_ACTIVE_CHILDREN;
            break;
        default:
            return osg::NodeVisitor::TraversalMode::TRAVERSE_NONE;
            break;
        }
    }

    /**
     * @fn  NodeVisitor::TraversalMode ToTraversalMode(osg::NodeVisitor::TraversalMode type)
     *
     * @brief   Converts a osg TraversalMode to a TR TraversalMode.
     *
     * @param   type    The type.
     *
     * @return  Type as a NodeVisitor::TraversalMode.
     */
    NodeVisitor::TraversalMode ToTraversalMode(osg::NodeVisitor::TraversalMode mode)
    {
        switch (mode)
        {
        case osg::NodeVisitor::TraversalMode::TRAVERSE_NONE:
            return NodeVisitor::TraversalMode::TRAVERSE_NONE;
            break;
        case osg::NodeVisitor::TraversalMode::TRAVERSE_PARENTS:
            return NodeVisitor::TraversalMode::TRAVERSE_PARENTS;
            break;
        case osg::NodeVisitor::TraversalMode::TRAVERSE_ALL_CHILDREN:
            return NodeVisitor::TraversalMode::TRAVERSE_ALL_CHILDREN;
            break;
        case osg::NodeVisitor::TraversalMode::TRAVERSE_ACTIVE_CHILDREN:
            return NodeVisitor::TraversalMode::TRAVERSE_ACTIVE_CHILDREN;
            break;
        default:
            return NodeVisitor::TraversalMode::TRAVERSE_NONE;
            break;
        }
    }

    const trUtil::RefStr NodeVisitor::CLASS_TYPE = trUtil::RefStr("trCore::Nodes::NodeVisitor");

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::NodeVisitor(TraversalMode tm, const std::string name)
        : NodeVisitor(NODE_VISITOR, tm, name)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::NodeVisitor(VisitorType type, TraversalMode tm, const std::string name)
    {
        mNodeVisitor = new osg::NodeVisitor(ToVisitorType(type), tm);
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
    void NodeVisitor::Reset()
    {
        mNodeVisitor->reset();
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::SetVisitorType(VisitorType type)
    {
        mNodeVisitor->setVisitorType(ToVisitorType(type));
    }

    //////////////////////////////////////////////////////////////////////////
    inline NodeVisitor::VisitorType NodeVisitor::GetVisitorType() const
    {
        return ToVisitorType(mNodeVisitor->getVisitorType());
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::SetTraversalNumber(unsigned int fn)
    {
        mNodeVisitor->setTraversalNumber(fn);
    }

    //////////////////////////////////////////////////////////////////////////
    inline unsigned int NodeVisitor::GetTraversalNumber() const
    {
        return mNodeVisitor->getTraversalNumber();
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::SetFrameStamp(FrameStamp * fs)
    {
        mNodeVisitor->setFrameStamp(fs->AsOSGClass());
    }

    //////////////////////////////////////////////////////////////////////////
    inline const FrameStamp* NodeVisitor::GetFrameStamp() const
    {
        return new FrameStamp(*mNodeVisitor->getFrameStamp());
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::SetTraversalMask(Node::NodeMask mask)
    {
        mNodeVisitor->setTraversalMask(mask);
    }

    //////////////////////////////////////////////////////////////////////////
    inline Node::NodeMask NodeVisitor::GetTraversalMask() const
    {
        return mNodeVisitor->getTraversalMask();
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::SetNodeMaskOverride(Node::NodeMask mask)
    {
        mNodeVisitor->setNodeMaskOverride(mask);
    }

    //////////////////////////////////////////////////////////////////////////
    inline Node::NodeMask NodeVisitor::GetNodeMaskOverride() const
    {
        return mNodeVisitor->getNodeMaskOverride();
    }

    //////////////////////////////////////////////////////////////////////////
    inline bool NodeVisitor::ValidNodeMask(const Nodes::Node & node) const
    {
        return mNodeVisitor->validNodeMask(*node.AsOSGNode());
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::SetTraversalMode(NodeVisitor::TraversalMode mode)
    {
        mNodeVisitor->setTraversalMode(ToTraversalMode(mode));
    }

    //////////////////////////////////////////////////////////////////////////
    inline NodeVisitor::TraversalMode NodeVisitor::GetTraversalMode() const
    {
        return ToTraversalMode(mNodeVisitor->getTraversalMode());
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::Traverse(Node & node)
    {
        mNodeVisitor->traverse(*node.AsOSGNode());
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::PushOntoNodePath(Node * node)
    {
        mNodeVisitor->pushOntoNodePath(node->AsOSGNode());
    }

    //////////////////////////////////////////////////////////////////////////
    inline void NodeVisitor::PopFromNodePath()
    {
        mNodeVisitor->popFromNodePath();
    }

    //////////////////////////////////////////////////////////////////////////
    NodePath & NodeVisitor::GetNodePath()
    {
        osg::NodePath* osgNodes = &mNodeVisitor->getNodePath();
        NodePath* path = new NodePath;

        // Copy the node path from osg nodes to TR
        for (int i = 0; osgNodes->size() - 1; ++i)
        {
            trBase::SmrtPtr<trCore::Nodes::Node> newNode = new trCore::Nodes::Node(*osgNodes->at(i), osgNodes->at(i)->getName());
            path->push_back(newNode);
        }

        return *path;
    }

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::~NodeVisitor()
    {
    }
}
