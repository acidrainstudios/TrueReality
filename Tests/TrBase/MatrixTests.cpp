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

#include "MatrixTests.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////////
MatrixTests::MatrixTests()
{
}

//////////////////////////////////////////////////////////////////////////
MatrixTests::~MatrixTests()
{
}

/**
 * @fn  TEST_F(MatrixTests, CreateMatrix)
 *
 * @brief   Test the creation of a default Matrix.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrix)
{
    // Create a new matrix using the default constructor
    mTestMatrix = trBase::Matrix();

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), 1.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), 1.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);
    
    // Create a new matrix using the default constructor
    mTestMatrixF1 = trBase::Matrixf();

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixF1(0, 0), 1.0);
    EXPECT_EQ(mTestMatrixF1(0, 1), 0.0);
    EXPECT_EQ(mTestMatrixF1(0, 2), 0.0);
    EXPECT_EQ(mTestMatrixF1(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixF1(1, 0), 0.0);
    EXPECT_EQ(mTestMatrixF1(1, 1), 1.0);
    EXPECT_EQ(mTestMatrixF1(1, 2), 0.0);
    EXPECT_EQ(mTestMatrixF1(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixF1(2, 0), 0.0);
    EXPECT_EQ(mTestMatrixF1(2, 1), 0.0);
    EXPECT_EQ(mTestMatrixF1(2, 2), 1.0);
    EXPECT_EQ(mTestMatrixF1(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixF1(3, 0), 0.0);
    EXPECT_EQ(mTestMatrixF1(3, 1), 0.0);
    EXPECT_EQ(mTestMatrixF1(3, 2), 0.0);
    EXPECT_EQ(mTestMatrixF1(3, 3), 1.0);
    
    // Create a new matrix using the default constructor
    mTestMatrixD1 = trBase::Matrixd();

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixD1(0, 0), 1.0);
    EXPECT_EQ(mTestMatrixD1(0, 1), 0.0);
    EXPECT_EQ(mTestMatrixD1(0, 2), 0.0);
    EXPECT_EQ(mTestMatrixD1(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixD1(1, 0), 0.0);
    EXPECT_EQ(mTestMatrixD1(1, 1), 1.0);
    EXPECT_EQ(mTestMatrixD1(1, 2), 0.0);
    EXPECT_EQ(mTestMatrixD1(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixD1(2, 0), 0.0);
    EXPECT_EQ(mTestMatrixD1(2, 1), 0.0);
    EXPECT_EQ(mTestMatrixD1(2, 2), 1.0);
    EXPECT_EQ(mTestMatrixD1(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixD1(3, 0), 0.0);
    EXPECT_EQ(mTestMatrixD1(3, 1), 0.0);
    EXPECT_EQ(mTestMatrixD1(3, 2), 0.0);
    EXPECT_EQ(mTestMatrixD1(3, 3), 1.0);
}

/**
 * @fn  TEST_F(MatrixTests, CreateMatrix)
 *
 * @brief   Test the creation of a Matrix from raw input
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrixFromNum)
{
    // Create a matrix 
    mTestMatrix = trBase::Matrix(   1.2, 1.3, 1.4, 0.5,
                                    1.6, 1.7, 1.8, 0.6,
                                    2.0, 2.1, 2.2, 0.7,
                                    2.4, 2.5, 2.6, 0.8);
    
    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.2);
    EXPECT_EQ(mTestMatrix(0, 1), 1.3);
    EXPECT_EQ(mTestMatrix(0, 2), 1.4);
    EXPECT_EQ(mTestMatrix(0, 3), 0.5);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 1.6);
    EXPECT_EQ(mTestMatrix(1, 1), 1.7);
    EXPECT_EQ(mTestMatrix(1, 2), 1.8);
    EXPECT_EQ(mTestMatrix(1, 3), 0.6);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 2.0);
    EXPECT_EQ(mTestMatrix(2, 1), 2.1);
    EXPECT_EQ(mTestMatrix(2, 2), 2.2);
    EXPECT_EQ(mTestMatrix(2, 3), 0.7);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 2.4);
    EXPECT_EQ(mTestMatrix(3, 1), 2.5);
    EXPECT_EQ(mTestMatrix(3, 2), 2.6);
    EXPECT_EQ(mTestMatrix(3, 3), 0.8);

    // Create a double matrix
    mTestMatrixD1 = trBase::Matrixd(1.0, 2.0, 3.0, 4.0,
                                    5.0, 6.0, 7.0, 8.0,
                                    9.0, 8.0, 7.0, 6.0,
                                    5.0, 4.0, 3.0, 2.0);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixD1(0, 0), 1.0);
    EXPECT_EQ(mTestMatrixD1(0, 1), 2.0);
    EXPECT_EQ(mTestMatrixD1(0, 2), 3.0);
    EXPECT_EQ(mTestMatrixD1(0, 3), 4.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixD1(1, 0), 5.0);
    EXPECT_EQ(mTestMatrixD1(1, 1), 6.0);
    EXPECT_EQ(mTestMatrixD1(1, 2), 7.0);
    EXPECT_EQ(mTestMatrixD1(1, 3), 8.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixD1(2, 0), 9.0);
    EXPECT_EQ(mTestMatrixD1(2, 1), 8.0);
    EXPECT_EQ(mTestMatrixD1(2, 2), 7.0);
    EXPECT_EQ(mTestMatrixD1(2, 3), 6.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixD1(3, 0), 5.0);
    EXPECT_EQ(mTestMatrixD1(3, 1), 4.0);
    EXPECT_EQ(mTestMatrixD1(3, 2), 3.0);
    EXPECT_EQ(mTestMatrixD1(3, 3), 2.0);
    
    // Create a float matrix
    mTestMatrixF1 = trBase::Matrixf(9.0, 8.0, 7.0, 6.0,
                                    5.0, 4.0, 3.0, 2.0,
                                    1.0, 2.0, 3.0, 4.0,
                                    5.0, 6.0, 7.0, 8.0);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixF1(0, 0), 9.0);
    EXPECT_EQ(mTestMatrixF1(0, 1), 8.0);
    EXPECT_EQ(mTestMatrixF1(0, 2), 7.0);
    EXPECT_EQ(mTestMatrixF1(0, 3), 6.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixF1(1, 0), 5.0);
    EXPECT_EQ(mTestMatrixF1(1, 1), 4.0);
    EXPECT_EQ(mTestMatrixF1(1, 2), 3.0);
    EXPECT_EQ(mTestMatrixF1(1, 3), 2.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixF1(2, 0), 1.0);
    EXPECT_EQ(mTestMatrixF1(2, 1), 2.0);
    EXPECT_EQ(mTestMatrixF1(2, 2), 3.0);
    EXPECT_EQ(mTestMatrixF1(2, 3), 4.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixF1(3, 0), 5.0);
    EXPECT_EQ(mTestMatrixF1(3, 1), 6.0);
    EXPECT_EQ(mTestMatrixF1(3, 2), 7.0);
    EXPECT_EQ(mTestMatrixF1(3, 3), 8.0);
}

/**
 * @fn  TEST_F(MatrixTests, CreateMatrixFromMatrix)
 *
 * @brief   Test the creation of a Matrix from another Matrix
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrixFromMatrix)
{
    // Create a float matrix
    mTestMatrixF1 = trBase::Matrixf(9.0, 8.0, 7.0, 6.0,
                                    5.0, 4.0, 3.0, 2.0,
                                    1.0, 2.0, 3.0, 4.0,
                                    5.0, 6.0, 7.0, 8.0);
    
    // Create a double matrix
    mTestMatrixD1 = trBase::Matrixd(1.0, 2.0, 3.0, 4.0,
                                    5.0, 6.0, 7.0, 8.0,
                                    9.0, 8.0, 7.0, 6.0,
                                    5.0, 4.0, 3.0, 2.0);

    // Create a float matrix from float matrix
    mTestMatrixF2 = trBase::Matrix(mTestMatrixF1);
    
    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF2.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixF2(0, 0), 9.0);
    EXPECT_EQ(mTestMatrixF2(0, 1), 8.0);
    EXPECT_EQ(mTestMatrixF2(0, 2), 7.0);
    EXPECT_EQ(mTestMatrixF2(0, 3), 6.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixF2(1, 0), 5.0);
    EXPECT_EQ(mTestMatrixF2(1, 1), 4.0);
    EXPECT_EQ(mTestMatrixF2(1, 2), 3.0);
    EXPECT_EQ(mTestMatrixF2(1, 3), 2.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixF2(2, 0), 1.0);
    EXPECT_EQ(mTestMatrixF2(2, 1), 2.0);
    EXPECT_EQ(mTestMatrixF2(2, 2), 3.0);
    EXPECT_EQ(mTestMatrixF2(2, 3), 4.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixF2(3, 0), 5.0);
    EXPECT_EQ(mTestMatrixF2(3, 1), 6.0);
    EXPECT_EQ(mTestMatrixF2(3, 2), 7.0);
    EXPECT_EQ(mTestMatrixF2(3, 3), 8.0);
    
    // Create a float matrix from double matrix
    mTestMatrixF2 = trBase::Matrix(mTestMatrixD1);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF2.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixF2(0, 0), 1.0);
    EXPECT_EQ(mTestMatrixF2(0, 1), 2.0);
    EXPECT_EQ(mTestMatrixF2(0, 2), 3.0);
    EXPECT_EQ(mTestMatrixF2(0, 3), 4.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixF2(1, 0), 5.0);
    EXPECT_EQ(mTestMatrixF2(1, 1), 6.0);
    EXPECT_EQ(mTestMatrixF2(1, 2), 7.0);
    EXPECT_EQ(mTestMatrixF2(1, 3), 8.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixF2(2, 0), 9.0);
    EXPECT_EQ(mTestMatrixF2(2, 1), 8.0);
    EXPECT_EQ(mTestMatrixF2(2, 2), 7.0);
    EXPECT_EQ(mTestMatrixF2(2, 3), 6.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixF2(3, 0), 5.0);
    EXPECT_EQ(mTestMatrixF2(3, 1), 4.0);
    EXPECT_EQ(mTestMatrixF2(3, 2), 3.0);
    EXPECT_EQ(mTestMatrixF2(3, 3), 2.0);

    // Create a double matrix from float matrix
    mTestMatrixD2 = trBase::Matrix(mTestMatrixF1);
    
    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD2.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixD2(0, 0), 9.0);
    EXPECT_EQ(mTestMatrixD2(0, 1), 8.0);
    EXPECT_EQ(mTestMatrixD2(0, 2), 7.0);
    EXPECT_EQ(mTestMatrixD2(0, 3), 6.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixD2(1, 0), 5.0);
    EXPECT_EQ(mTestMatrixD2(1, 1), 4.0);
    EXPECT_EQ(mTestMatrixD2(1, 2), 3.0);
    EXPECT_EQ(mTestMatrixD2(1, 3), 2.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixD2(2, 0), 1.0);
    EXPECT_EQ(mTestMatrixD2(2, 1), 2.0);
    EXPECT_EQ(mTestMatrixD2(2, 2), 3.0);
    EXPECT_EQ(mTestMatrixD2(2, 3), 4.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixD2(3, 0), 5.0);
    EXPECT_EQ(mTestMatrixD2(3, 1), 6.0);
    EXPECT_EQ(mTestMatrixD2(3, 2), 7.0);
    EXPECT_EQ(mTestMatrixD2(3, 3), 8.0);
    
    // Create a double matrix from double matrix
    mTestMatrixD2 = trBase::Matrix(mTestMatrixD1);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD2.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixD2(0, 0), 1.0);
    EXPECT_EQ(mTestMatrixD2(0, 1), 2.0);
    EXPECT_EQ(mTestMatrixD2(0, 2), 3.0);
    EXPECT_EQ(mTestMatrixD2(0, 3), 4.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrixD2(1, 0), 5.0);
    EXPECT_EQ(mTestMatrixD2(1, 1), 6.0);
    EXPECT_EQ(mTestMatrixD2(1, 2), 7.0);
    EXPECT_EQ(mTestMatrixD2(1, 3), 8.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrixD2(2, 0), 9.0);
    EXPECT_EQ(mTestMatrixD2(2, 1), 8.0);
    EXPECT_EQ(mTestMatrixD2(2, 2), 7.0);
    EXPECT_EQ(mTestMatrixD2(2, 3), 6.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixD2(3, 0), 5.0);
    EXPECT_EQ(mTestMatrixD2(3, 1), 4.0);
    EXPECT_EQ(mTestMatrixD2(3, 2), 3.0);
    EXPECT_EQ(mTestMatrixD2(3, 3), 2.0);

    // Create a matrix from float matrix
    mTestMatrix = trBase::Matrix(mTestMatrixF1);
    
    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 9.0);
    EXPECT_EQ(mTestMatrix(0, 1), 8.0);
    EXPECT_EQ(mTestMatrix(0, 2), 7.0);
    EXPECT_EQ(mTestMatrix(0, 3), 6.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 5.0);
    EXPECT_EQ(mTestMatrix(1, 1), 4.0);
    EXPECT_EQ(mTestMatrix(1, 2), 3.0);
    EXPECT_EQ(mTestMatrix(1, 3), 2.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 1.0);
    EXPECT_EQ(mTestMatrix(2, 1), 2.0);
    EXPECT_EQ(mTestMatrix(2, 2), 3.0);
    EXPECT_EQ(mTestMatrix(2, 3), 4.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 5.0);
    EXPECT_EQ(mTestMatrix(3, 1), 6.0);
    EXPECT_EQ(mTestMatrix(3, 2), 7.0);
    EXPECT_EQ(mTestMatrix(3, 3), 8.0);
    
    // Create a matrix from double matrix
    mTestMatrix = trBase::Matrix(mTestMatrixD1);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 2.0);
    EXPECT_EQ(mTestMatrix(0, 2), 3.0);
    EXPECT_EQ(mTestMatrix(0, 3), 4.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 5.0);
    EXPECT_EQ(mTestMatrix(1, 1), 6.0);
    EXPECT_EQ(mTestMatrix(1, 2), 7.0);
    EXPECT_EQ(mTestMatrix(1, 3), 8.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 9.0);
    EXPECT_EQ(mTestMatrix(2, 1), 8.0);
    EXPECT_EQ(mTestMatrix(2, 2), 7.0);
    EXPECT_EQ(mTestMatrix(2, 3), 6.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 5.0);
    EXPECT_EQ(mTestMatrix(3, 1), 4.0);
    EXPECT_EQ(mTestMatrix(3, 2), 3.0);
    EXPECT_EQ(mTestMatrix(3, 3), 2.0);
}

/**
 * @fn  TEST_F(MatrixTests, CreateMatrixFromQuat)
 *
 * @brief   Test the creation of a Matrix from a quaternion.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrixFromQuat)
{
    /*
    q = (x, y, z, w) --->
    M =
    (w*w + x*x - y*y - z*z)      (2*x*y - 2*w*z)          (2*x*z + 2*w*y)      0
        (2*x*y + 2*w*z)      (w*w - x*x + y*y - z*z)      (2*y*z - 2*w*x)      0
        (2*x*z - 2*w*y)          (2*y*z + 2*w*x)      (w*w - x*x - y*y + z*z)  0
               0                        0                        0             1
    
    L = length(q)^2
    True Reality & Open Scene Graph use normalized matrices for the conversion, therefore
     all values in the matrix above (except M(4,4)) needs to be divided by L
    https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
    http://www.mrelusive.com/publications/papers/SIMD-From-Quaternion-to-Matrix-and-Back.pdf
    */

    // Create a test quaternion
    mTestQuat.Set(1.0, 0.0, 0.0, 0.0);

    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), -1.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), -1.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);
    
    // Create a test quaternion
    mTestQuat.Set(0.0, 1.0, 0.0, 0.0);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), -1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), 1.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), -1.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);

    // Create a test quaternion 
    mTestQuat.Set(0.0, 0.0, 1.0, 0.0);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), -1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), -1.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), 1.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);


    // Create a test quaternion
    mTestQuat.Set(0.0, 0.0, 0.0, 1.0);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), 1.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), 1.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);


    // Create a test quaternion
    mTestQuat.Set(2.3, 3.4, 5.6, 7.8);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrix(0, 0), 0.212838148, 1e-8);
    EXPECT_NEAR(mTestMatrix(0, 1), 0.944520862, 1e-8);
    EXPECT_NEAR(mTestMatrix(0, 2), -0.250160477, 1e-8);
    EXPECT_EQ(mTestMatrix(0, 3), 0);

    // Test the second row values
    EXPECT_NEAR(mTestMatrix(1, 0), -0.657679963, 1e-8);
    EXPECT_NEAR(mTestMatrix(1, 1), 0.32783127, 1e-8);
    EXPECT_NEAR(mTestMatrix(1, 2), 0.678221, 1e-8);
    EXPECT_EQ(mTestMatrix(1, 3), 0);

    // Test the third row values
    EXPECT_NEAR(mTestMatrix(2, 0), 0.72260431, 1e-8);
    EXPECT_NEAR(mTestMatrix(2, 1), 0.020174232, 1e-8);
    EXPECT_NEAR(mTestMatrix(2, 2), 0.690967446, 1e-8);
    EXPECT_EQ(mTestMatrix(2, 3), 0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0);
    EXPECT_EQ(mTestMatrix(3, 1), 0);
    EXPECT_EQ(mTestMatrix(3, 2), 0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);
}