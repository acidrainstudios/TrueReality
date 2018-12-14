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

#include <trCore/Export.h>

#include <trUtil/Timer.h>

#include <osg/NodeCallback>
#include <osg/NodeVisitor>

namespace trCore::SceneObjects
{
    /**
     * @class   RingArrayCallback
     *
     * @brief   A ring array callback that is used to rotate the ring array (RingArray.h)
     *
     * @author  Maxim Serebrennik
     */
    class TR_CORE_EXPORT RingArrayCallback : public osg::NodeCallback
    {
    public:

        /**
         * @fn  RingArrayCallback::RingArrayCallback();
         *
         * @brief   Default constructor.
         */
        RingArrayCallback();

        /**
         * @fn  RingArrayCallback::~RingArrayCallback();
         *
         * @brief   Destructor.
         */
        ~RingArrayCallback();

        /**
         * @fn  virtual void RingArrayCallback::operator()(osg::Node* nodePtr, osg::NodeVisitor* nvPtr) override;
         *
         * @brief   Callback method called by the NodeVisitor when visiting a node.
         *
         * @param [in,out]  nodePtr If non-null, the node.
         * @param [in,out]  nvPtr   If non-null, the nv.
         */
        virtual void operator()(osg::Node* nodePtr, osg::NodeVisitor* nvPtr) override;

    private:

        bool mFirstFrame = true;
        trUtil::Timer mTimer;
    };
}