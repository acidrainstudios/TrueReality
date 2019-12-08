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

#include <trBase/Vec2d.h>

#include <trBase/Vec2f.h>

#include <osg/Vec2f>

// Specialize Vec2Impl to be Vec2d
#define Vec2Impl Vec2d

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    Vec2d::Vec2d(const osg::Vec2f &v)
        : mVec(static_cast<double>(v.x()), static_cast<double>(v.y()))
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec2d::operator = (const Vec2f& v)
    {
        mVec[0] = static_cast<double>(v.X());  mVec[1] = static_cast<double>(v.Y());
    }
}

// Now compile up Vector via Vec2Impl
#include "Vec2Impl.cpp"
