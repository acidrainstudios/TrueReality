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

#include <trBase/SmrtPtr.h>
#include <trBase/Matrix.h>
#include <trBase/Matrixf.h>
#include <trBase/Matrixd.h>
#include <trBase/Quat.h>

/**
 * @class   MatrixTests
 *
 * @brief   Sets up test environment for Matrix class tests
 */
class MatrixTests : public ::testing::Test
{   

public:
    
    /** @brief   The test matrix. */
    trBase::Matrix mTestMatrix;
    trBase::Matrixd mTestMatrixD1;
    trBase::Matrixd mTestMatrixD2;
    trBase::Matrixf mTestMatrixF1;
    trBase::Matrixf mTestMatrixF2;

    /** @brief   The test quaternion. */
    trBase::Quat mTestQuat;

    /**
     * @fn  public::MatrixTests();
     *
     * @brief   Default constructor.
     */
    MatrixTests();

    /**
     * @fn  public::~MatrixTests();
     *
     * @brief   Destructor.
     */
    ~MatrixTests();
};

