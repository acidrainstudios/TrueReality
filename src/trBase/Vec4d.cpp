/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2021 Acid Rain Studios LLC
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

#include <trBase/Vec4d.h>

#include <trBase/Vec4f.h>

#include <osg/Vec4f>

// Specialize Vec4Impl to be Vec4d
#define Vec4Impl Vec4d

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    Vec4d::Vec4d(const osg::Vec4f &v)
        : mVec(static_cast<double>(v.x()), static_cast<double>(v.y()), static_cast<double>(v.z()), static_cast<double>(v.w()))
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec4d::operator = (const Vec4f& v)
    {
        mVec[0] = static_cast<double>(v.X());  mVec[1] = static_cast<double>(v.Y()); mVec[2] = static_cast<double>(v.Z()); mVec[2] = static_cast<double>(v.W());
    }
}

// Now compile up Vector via Vec4Impl
#include "Vec4Impl.cpp"