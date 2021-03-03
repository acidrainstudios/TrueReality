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
#pragma once

#include <trUtil/PlatformMacros.h>
#include <trBase/Vec3f.h>
#include <trBase/Vec3d.h>

namespace trBase
{
#ifdef TR_USE_DOUBLE_VECTOR
    /**
    * General purpose 3D Vector
    */
    using Vec3 = Vec3d;
#else
    /**
    * General purpose 3D Vector
    */
    using Vec3 = Vec3f;
#endif


    const Vec3 X_AXIS(1.0, 0.0, 0.0);
    const Vec3 Y_AXIS(0.0, 1.0, 0.0);
    const Vec3 Z_AXIS(0.0, 0.0, 1.0);
}