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

#include <trBase/SmrtPtr.h>

#include <osg/Matrix>
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/Transform>

namespace trCore
{
    namespace SceneObjects
    {
        /**
         * @class   SkyBoxNode
         *
         * @brief   A sky box class that creates an object that is always positioned around the camera.
         *          This class can load any geometry, box or dome...
         */
        class TR_CORE_EXPORT SkyBoxNode : public osg::Transform
        {
        public:

            using BaseClass = osg::Transform;           /// Adds an easy and swappable access to the base class

            /**
             * @fn  SkyBoxNode::SkyBoxNode();
             *
             * @brief   Default constructor.
             */
            SkyBoxNode();

            /**
             * @fn  virtual bool SkyBoxNode::computeLocalToWorldMatrix(osg::Matrix& matrix, osg::NodeVisitor* nv) const override;
             *
             * @brief   Calculates the local to world matrix.
             *
             * @param [in,out]  matrix  The matrix.
             * @param [in,out]  nv      If non-null, the nv.
             *
             * @return  True if it succeeds, false if it fails.
             */
            virtual bool computeLocalToWorldMatrix(osg::Matrix& matrix, osg::NodeVisitor* nv) const override;

            /**
             * @fn  virtual bool SkyBoxNode::computeWorldToLocalMatrix(osg::Matrix& matrix, osg::NodeVisitor* nv) const override;
             *
             * @brief   Calculates the world to local matrix.
             *
             * @param [in,out]  matrix  The matrix.
             * @param [in,out]  nv      If non-null, the nv.
             *
             * @return  True if it succeeds, false if it fails.
             */
            virtual bool computeWorldToLocalMatrix(osg::Matrix& matrix, osg::NodeVisitor* nv) const override;

            /**
             * @fn  bool SkyBoxNode::LoadFile(std::string fileName);
             *
             * @brief   Loads a  geometry file. Path and file name should be passed in
             *
             * @param   fileName    Filename of the file.
             *
             * @return  True if it succeeds, false if it fails.
             */
            bool LoadFile(std::string fileName);

        protected:

            trBase::SmrtPtr<osg::Node> mNode = nullptr;

            /**
             * @fn  SkyBoxNode::~SkyBoxNode();
             *
             * @brief   Destructor.
             */
            ~SkyBoxNode();
        };
    }
}