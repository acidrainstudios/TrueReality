/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/

#pragma once

#include <trBase/Export.h>

#include <osg/Referenced>

#include <string>

namespace trBase
{
    /**
    * This class is part of the internal garbage collection system. Anything that inherits it can also use the
    * smart pointer interface (trBase::SmrtPtr)
    *
    * It is a wrapper for osg::Referenced
    */
    class TR_BASE_EXPORT SmrtClass : public osg::Referenced
    {
    public:
        SmrtClass() : osg::Referenced()
        {}

        explicit SmrtClass(bool threadSafeRefUnref) : osg::Referenced(threadSafeRefUnref)
        {}

        SmrtClass(const SmrtClass& inst) : osg::Referenced(inst)
        {}

        /**
        * Returns the class type
        */
        virtual const std::string& GetType() const = 0;

    protected:
        ~SmrtClass()
        {}
    };
}


