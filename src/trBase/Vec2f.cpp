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

#include <trBase/Vec2f.h>

#include <trBase/Vec2d.h>

#include <osg/Vec2d>

// Specialize Vec2Impl to be Vec2f
#define Vec2Impl Vec2f

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    Vec2f::Vec2f(const osg::Vec2d &v)
    {
        mVec.set(static_cast<float>(v.x()), static_cast<float>(v.y()));
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec2f::operator = (const Vec2d& v)
    {
        mVec[0] = static_cast<float>(v.X());  mVec[1] = static_cast<float>(v.Y());
    }
}

// Now compile up Vector via Vec2Impl
#include "Vec2Impl.cpp"
