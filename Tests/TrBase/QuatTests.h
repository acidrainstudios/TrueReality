/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2018 Acid Rain Studios LLC
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

#include <gtest/gtest.h>

#include <trBase/Quat.h>
#include <trBase/Vec4d.h>
#include <trBase/Vec4f.h>
#include <trBase/Vec3d.h>
#include <trBase/Vec3f.h>

#include <osg/Quat>

/**
 * @class   QuatTests
 *
 * @brief   Sets up test environment for Quaternion class tests.
 */
class QuatTests : public ::testing::Test
{   

public:
    
    /** @brief   The test quaternion. */
    trBase::Quat mTestQuat;

    // Quaternion values in quat, degrees and radians
    trBase::Quat mQuat = trBase::Quat(0.635, 0.431, 0.390, 0.508);
    osg::Quat mOsgQuat = osg::Quat(0.635, 0.431, 0.390, 0.508);
    trBase::Vec4d mTestQuatVecD = trBase::Vec4d(0.635, 0.431, 0.390, 0.508);
    trBase::Vec4f mTestQuatVecF = trBase::Vec4d(0.635f, 0.431f, 0.390f, 0.508f);
    trBase::Vec3d mTestRadVec = trBase::Vec3d(-0.436, 1.204, 2.094);
    trBase::Vec3d mTestDegVec = trBase::Vec3d(-25.000, 69.000, 120.000);

    trBase::Vec3d mXVec = trBase::Vec3d(1.0, 0.0, 0.0);
    trBase::Vec3d mYVec = trBase::Vec3d(0.0, 1.0, 0.0);
    trBase::Vec3d mZVec = trBase::Vec3d(0.0, 0.0, 1.0);

    /**
     * @fn  public::QuatTests();
     *
     * @brief   Default constructor.
     */
    QuatTests();

    /**
     * @fn  public::~QuatTests();
     *
     * @brief   Destructor.
     */
    ~QuatTests();
};