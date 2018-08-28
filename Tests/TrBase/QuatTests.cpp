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

#include "QuatTests.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////////
QuatTests::QuatTests()
{
}

//////////////////////////////////////////////////////////////////////////
QuatTests::~QuatTests()
{
}


/**
 * @fn  TEST_F(MatrixTests, CreateMatrix)
 *
 * @brief   Test the creation of a default Quaternion.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(QuatTests, CreateQuaternion)
{
    mTestQuat = trBase::Quat();

    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);
}

/**
 * @fn  TEST_F(QuatTests, CreateQuatFromQuat)
 *
 * @brief   Test the creation of a Quaternion from a Quaternion
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(QuatTests, CreateQuatFromQuat)
{
    EXPECT_EQ(mQuat.X(), 0.635);
    EXPECT_EQ(mQuat.Y(), 0.431);
    EXPECT_EQ(mQuat.Z(), 0.390);
    EXPECT_EQ(mQuat.W(), 0.508);

    mTestQuat = trBase::Quat(mQuat);
    EXPECT_EQ(mTestQuat.X(), 0.635);
    EXPECT_EQ(mTestQuat.Y(), 0.431);
    EXPECT_EQ(mTestQuat.Z(), 0.390);
    EXPECT_EQ(mTestQuat.W(), 0.508);

    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);
}

/**
 * @fn  TEST_F(QuatTests, CreateQuatFromOSGQuat)
 *
 * @brief   Test the creation of a Quaternion from an OSG Quaternion
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(QuatTests, CreateQuatFromOSGQuat)
{
    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);

    EXPECT_EQ(mOsgQuat.x(), 0.635);
    EXPECT_EQ(mOsgQuat.y(), 0.431);
    EXPECT_EQ(mOsgQuat.z(), 0.390);
    EXPECT_EQ(mOsgQuat.w(), 0.508);

    mTestQuat = trBase::Quat(mOsgQuat);
    EXPECT_EQ(mTestQuat.X(), 0.635);
    EXPECT_EQ(mTestQuat.Y(), 0.431);
    EXPECT_EQ(mTestQuat.Z(), 0.390);
    EXPECT_EQ(mTestQuat.W(), 0.508);

    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);
}

/**
 * @fn  TEST_F(QuatTests, CreateQuatFromDoubles)
 *
 * @brief   Test the creation of a Quaternion from Doubles
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(QuatTests, CreateQuatFromDoubles)
{
    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);

    mTestQuat = trBase::Quat(0.635, 0.431, 0.390, 0.508);
    EXPECT_EQ(mTestQuat.X(), 0.635);
    EXPECT_EQ(mTestQuat.Y(), 0.431);
    EXPECT_EQ(mTestQuat.Z(), 0.390);
    EXPECT_EQ(mTestQuat.W(), 0.508);

    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);
}

/**
 * @fn  TEST_F(QuatTests, CreateQuatFromFloats)
 *
 * @brief   Test the creation of a Quaternion from Floats.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(QuatTests, CreateQuatFromFloats)
{
    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);

    mTestQuat = trBase::Quat(0.635f, 0.431f, 0.390f, 0.508f);
    EXPECT_NEAR(mTestQuat.X(), 0.635, 1e-6);
    EXPECT_NEAR(mTestQuat.Y(), 0.431, 1e-6);
    EXPECT_NEAR(mTestQuat.Z(), 0.390, 1e-6);
    EXPECT_NEAR(mTestQuat.W(), 0.508, 1e-6);

    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);
}

/**
 * @fn  TEST_F(QuatTests, CreateQuatFromVec4f)
 *
 * @brief   Test the creation of a Quaternion from a Float Vector.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(QuatTests, CreateQuatFromVec4f)
{
    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);

    mTestQuat = trBase::Quat(mTestQuatVecF);
    EXPECT_NEAR(mTestQuat.X(), 0.635, 1e-6);
    EXPECT_NEAR(mTestQuat.Y(), 0.431, 1e-6);
    EXPECT_NEAR(mTestQuat.Z(), 0.390, 1e-6);
    EXPECT_NEAR(mTestQuat.W(), 0.508, 1e-6);

    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);
}

/**
 * @fn  TEST_F(QuatTests, CreateQuatFromVec4d)
 *
 * @brief   Test the creation of a Quaternion from a Double Vector.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(QuatTests, CreateQuatFromVec4d)
{
    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);

    mTestQuat = trBase::Quat(mTestQuatVecD);
    EXPECT_EQ(mTestQuat.X(), 0.635);
    EXPECT_EQ(mTestQuat.Y(), 0.431);
    EXPECT_EQ(mTestQuat.Z(), 0.390);
    EXPECT_EQ(mTestQuat.W(), 0.508);

    mTestQuat.Clear();
    EXPECT_EQ(mTestQuat.X(), 0.0);
    EXPECT_EQ(mTestQuat.Y(), 0.0);
    EXPECT_EQ(mTestQuat.Z(), 0.0);
    EXPECT_EQ(mTestQuat.W(), 1.0);
}


    /**
        trBase::Vec4d mTestQuatVec = trBase::Vec4d(0.635, 0.431, 0.390, 0.508);
        trBase::Vec3d mTestRadVec = trBase::Vec3d(-0.436, 1.204, 2.094);
        trBase::Vec3d mTestDegVec = trBase::Vec3d(-25.000, 69.000, 120.000); 

        EXPECT_NEAR(mTestMatrixF1(3, 0), 4.5, 1e-6);
    */
