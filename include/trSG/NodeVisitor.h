/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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

#include <trBase/Base.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/RefStr.h>

namespace osg
{
    class NodeVisitor;
}

namespace trSG
{
    class NodeVisitor : public trBase::Base
    {
    public:
        using BaseClass = trBase::Base;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
         * @fn  NodeVisitor::NodeVisitor(const std::string name = CLASS_TYPE);
         *
         * @brief   Default constructor.
         *
         * @param   name    (Optional) The name.
         */
        NodeVisitor(const std::string name = CLASS_TYPE);

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

