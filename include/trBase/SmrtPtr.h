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

#include <trUtil/Hash.h>

#include <osg/ref_ptr>

#include <iostream>

namespace trBase
{
    /**
    * Smart pointer for handling referenced counted objects.
    */ 
    template<class T>
    class SmrtPtr : public osg::ref_ptr<T>
    {
    public:
        SmrtPtr() : osg::ref_ptr<T>() 
        {}
        
        SmrtPtr(T* t) : osg::ref_ptr<T>(t) 
        {}
        
        SmrtPtr(const SmrtPtr& smPt) : osg::ref_ptr<T>(smPt)
        {}

       /**
        * Prints out the memory address of the held pointer
        */
        friend inline std::ostream& operator<<(std::ostream& ios, const SmrtPtr& smPt)
        {
            ios << smPt.get();
            return ios;
        }
    };    
}

namespace trUtil
{
    /**
     * Hash function for hashing trBase::SmrtPtr
     */
    template<class _Key> struct hash<trBase::SmrtPtr<_Key> >
    {
        size_t operator()(const trBase::SmrtPtr<_Key>& keyPtr) const
        {
            return size_t(keyPtr.get());
        }
    };

    /**
     * Hash function for hashing osg::ref_ptr
     */
    template<class _Key> struct hash<osg::ref_ptr<_Key> >
    {
        size_t operator()(const trBase::SmrtPtr<_Key>& keyPtr) const
        {
            return size_t(keyPtr.get());
        }
    };
}