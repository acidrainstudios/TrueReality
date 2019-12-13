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

#include <osg/observer_ptr>

#include <iostream>

namespace trBase
{
    /**
    * An Observer Pointer. It holds a pointer to an object but does not own it, and does not delete it when destroyed. 
    * If the owner destroys the referenced pointer, the Observer Pointer is set to NULL
    */
    template <class T>
    class ObsrvrPtr : public osg::observer_ptr<T>
    {
    public:
        ObsrvrPtr() : osg::observer_ptr<T>() 
        {}

        ObsrvrPtr(T* t) : osg::observer_ptr<T>(t) 
        {}

        ObsrvrPtr(const osg::observer_ptr<T>& rp) : osg::observer_ptr<T>(rp) 
        {}

        /**
        * Prints out the memory address of the held pointer
        */
        friend inline std::ostream& operator<<(std::ostream& os, const ObsrvrPtr& rp)
        {
            os << rp.get();
            return os;
        }
    };
}