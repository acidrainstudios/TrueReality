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
 * @fn  TEST_F(MatrixTests, Matrix)
 *
 * @brief   Test of Matrix class definition, between Matrixf and Matrixd
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, Matrix)
{
#ifdef TR_USE_DOUBLE_MATRIX
    EXPECT_EQ(typeid(trBase::Matrix), typeid(trBase::Matrixd));
    EXPECT_NE(typeid(trBase::Matrix), typeid(trBase::Matrixf));
#else
    EXPECT_EQ(typeid(trBase::Matrix), typeid(trBase::Matrixf));
    EXPECT_NE(typeid(trBase::Matrix), typeid(trBase::Matrixd));
#endif
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
 * @fn  TEST_F(MatrixTests, CreateMatrixFromNum)
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
    mTestMatrixF2 = trBase::Matrixf(mTestMatrixF1);
    
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
    mTestMatrixF2 = trBase::Matrixf(mTestMatrixD1);

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
    mTestMatrixD2 = trBase::Matrixd(mTestMatrixF1);
    
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
    mTestMatrixD2 = trBase::Matrixd(mTestMatrixD1);

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
 * @fn  TEST_F(MatrixTests, CreateMatrixFromArray)
 *
 * @brief   Test the creation of a Matrix from an array
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrixFromArray)
{
    // Create a new matrix
    mTestMatrixF1 = trBase::Matrixf(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixF1(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixF1(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixF1(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrixF1(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 3), 0.1, 1e-6);
    
    // Create a new matrix
    mTestMatrixF1 = trBase::Matrixf(mArrayD);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixF1(0, 0), 2.1, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 2), 5.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 3), 4.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixF1(1, 0), 7.8, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 2), 8.9, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 3), 0.5, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixF1(2, 0), 5.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 1), 6.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 2), 7.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 3), 2.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrixF1(3, 0), 4.5, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 1), 3.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 2), 2.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 3), 8.3, 1e-6);
    
    // Create a new matrix
    mTestMatrixD1 = trBase::Matrixd(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixD1(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixD1(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixD1(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrixD1(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(3, 3), 0.1, 1e-6);
    
    // Create a new matrix
    mTestMatrixD1 = trBase::Matrixd(mArrayD);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixD1(0, 0), 2.1);
    EXPECT_EQ(mTestMatrixD1(0, 1), 4.3);
    EXPECT_EQ(mTestMatrixD1(0, 2), 5.6);
    EXPECT_EQ(mTestMatrixD1(0, 3), 4.5);

    // Test the second row values
    EXPECT_EQ(mTestMatrixD1(1, 0), 7.8);
    EXPECT_EQ(mTestMatrixD1(1, 1), 8.7);
    EXPECT_EQ(mTestMatrixD1(1, 2), 8.9);
    EXPECT_EQ(mTestMatrixD1(1, 3), 0.5);

    // Test the third row values
    EXPECT_EQ(mTestMatrixD1(2, 0), 5.6);
    EXPECT_EQ(mTestMatrixD1(2, 1), 6.6);
    EXPECT_EQ(mTestMatrixD1(2, 2), 7.3);
    EXPECT_EQ(mTestMatrixD1(2, 3), 2.5);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixD1(3, 0), 4.5);
    EXPECT_EQ(mTestMatrixD1(3, 1), 3.3);
    EXPECT_EQ(mTestMatrixD1(3, 2), 2.6);
    EXPECT_EQ(mTestMatrixD1(3, 3), 8.3);
    
    // Create a new matrix
    mTestMatrix = trBase::Matrix(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrix(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatrix(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrix(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatrix(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrix(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatrix(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrix(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatrix(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrix(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatrix(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatrix(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatrix(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrix(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatrix(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatrix(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatrix(3, 3), 0.1, 1e-6);
    
    // Create a new matrix
    mTestMatrix = trBase::Matrix(mArrayD);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 2.1);
    EXPECT_EQ(mTestMatrix(0, 1), 4.3);
    EXPECT_EQ(mTestMatrix(0, 2), 5.6);
    EXPECT_EQ(mTestMatrix(0, 3), 4.5);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 7.8);
    EXPECT_EQ(mTestMatrix(1, 1), 8.7);
    EXPECT_EQ(mTestMatrix(1, 2), 8.9);
    EXPECT_EQ(mTestMatrix(1, 3), 0.5);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 5.6);
    EXPECT_EQ(mTestMatrix(2, 1), 6.6);
    EXPECT_EQ(mTestMatrix(2, 2), 7.3);
    EXPECT_EQ(mTestMatrix(2, 3), 2.5);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 4.5);
    EXPECT_EQ(mTestMatrix(3, 1), 3.3);
    EXPECT_EQ(mTestMatrix(3, 2), 2.6);
    EXPECT_EQ(mTestMatrix(3, 3), 8.3);
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
    
    // Create a matrix 
    mTestMatrixF1 = trBase::Matrixf(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixF1(0, 0), 0.212838148, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 1), 0.944520862, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 2), -0.250160477, 1e-6);
    EXPECT_EQ(mTestMatrixF1(0, 3), 0);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixF1(1, 0), -0.657679963, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 1), 0.32783127, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 2), 0.678221, 1e-6);
    EXPECT_EQ(mTestMatrixF1(1, 3), 0);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixF1(2, 0), 0.72260431, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 1), 0.020174232, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 2), 0.690967446, 1e-6);
    EXPECT_EQ(mTestMatrixF1(2, 3), 0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixF1(3, 0), 0);
    EXPECT_EQ(mTestMatrixF1(3, 1), 0);
    EXPECT_EQ(mTestMatrixF1(3, 2), 0);
    EXPECT_EQ(mTestMatrixF1(3, 3), 1.0);
    
    // Create a matrix 
    mTestMatrixD1 = trBase::Matrixd(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixD1(0, 0), 0.212838148, 1e-8);
    EXPECT_NEAR(mTestMatrixD1(0, 1), 0.944520862, 1e-8);
    EXPECT_NEAR(mTestMatrixD1(0, 2), -0.250160477, 1e-8);
    EXPECT_EQ(mTestMatrixD1(0, 3), 0);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixD1(1, 0), -0.657679963, 1e-8);
    EXPECT_NEAR(mTestMatrixD1(1, 1), 0.32783127, 1e-8);
    EXPECT_NEAR(mTestMatrixD1(1, 2), 0.678221, 1e-8);
    EXPECT_EQ(mTestMatrixD1(1, 3), 0);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixD1(2, 0), 0.72260431, 1e-8);
    EXPECT_NEAR(mTestMatrixD1(2, 1), 0.020174232, 1e-8);
    EXPECT_NEAR(mTestMatrixD1(2, 2), 0.690967446, 1e-8);
    EXPECT_EQ(mTestMatrixD1(2, 3), 0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixD1(3, 0), 0);
    EXPECT_EQ(mTestMatrixD1(3, 1), 0);
    EXPECT_EQ(mTestMatrixD1(3, 2), 0);
    EXPECT_EQ(mTestMatrixD1(3, 3), 1.0);
}

/**
 * @fn  TEST_F(MatrixTests, GetOSGMatrix)
 *
 * @brief   Test the method for returning an OSG matrix
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, GetOSGMatrix)
{
    // Create a new matrix
    mTestMatrixF1 = trBase::Matrixf(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);
    
    // Get the OSG matrix
    mTestMatOsgF = mTestMatrixF1.GetOSGMatrix();

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatOsgF.valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatOsgF(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatOsgF(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatOsgF(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatOsgF(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatOsgF(3, 3), 0.1, 1e-6);
    
    // Create a new matrix
    mTestMatrixD1 = trBase::Matrixd(mArrayD);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);
    
    // Get the OSG matrix
    mTestMatOsgD = mTestMatrixD1.GetOSGMatrix();

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatOsgD.valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatOsgD(0, 0), 2.1);
    EXPECT_EQ(mTestMatOsgD(0, 1), 4.3);
    EXPECT_EQ(mTestMatOsgD(0, 2), 5.6);
    EXPECT_EQ(mTestMatOsgD(0, 3), 4.5);

    // Test the second row values
    EXPECT_EQ(mTestMatOsgD(1, 0), 7.8);
    EXPECT_EQ(mTestMatOsgD(1, 1), 8.7);
    EXPECT_EQ(mTestMatOsgD(1, 2), 8.9);
    EXPECT_EQ(mTestMatOsgD(1, 3), 0.5);

    // Test the third row values
    EXPECT_EQ(mTestMatOsgD(2, 0), 5.6);
    EXPECT_EQ(mTestMatOsgD(2, 1), 6.6);
    EXPECT_EQ(mTestMatOsgD(2, 2), 7.3);
    EXPECT_EQ(mTestMatOsgD(2, 3), 2.5);

    // Test the fourth row values
    EXPECT_EQ(mTestMatOsgD(3, 0), 4.5);
    EXPECT_EQ(mTestMatOsgD(3, 1), 3.3);
    EXPECT_EQ(mTestMatOsgD(3, 2), 2.6);
    EXPECT_EQ(mTestMatOsgD(3, 3), 8.3);
    
    // Create a new matrix
    mTestMatrix = trBase::Matrix(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);
    
    // Get the OSG matrix
    mTestMatOsg = mTestMatrix.GetOSGMatrix();

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatOsg.valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatOsg(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatOsg(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatOsg(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatOsg(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatOsg(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatOsg(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatOsg(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatOsg(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatOsg(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatOsg(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatOsg(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatOsg(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatOsg(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatOsg(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatOsg(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatOsg(3, 3), 0.1, 1e-6);
}

/**
 * @fn  TEST_F(MatrixTests, CompareMatrix)
 *
 * @brief   Test the method for comparing two matrices
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CompareMatrix)
{
    // Test if the matrices are valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);
    EXPECT_EQ(mTestMatrixF2.Valid(), true);
    
    // Compare the matrices
    EXPECT_EQ(mTestMatrixF1.Compare(mTestMatrixF2), 0);
    
    // Create a new matrix
    mTestMatrixF1 = trBase::Matrixf(mArrayF);
    
    // Compare the matrices
    EXPECT_EQ(mTestMatrixF1.Compare(mTestMatrixF2), 1);
    EXPECT_EQ(mTestMatrixF2.Compare(mTestMatrixF1), -1);

    // Test if the matrices are valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);
    EXPECT_EQ(mTestMatrixD2.Valid(), true);
    
    // Compare the matrices
    EXPECT_EQ(mTestMatrixD1.Compare(mTestMatrixD2), 0);
    
    // Create a new matrix
    mTestMatrixD1 = trBase::Matrixd(mArrayD);
    
    // Compare the matrices
    EXPECT_EQ(mTestMatrixD1.Compare(mTestMatrixD2), 1);
    EXPECT_EQ(mTestMatrixD2.Compare(mTestMatrixD1), -1);
    
    // Test if the matrices are valid
    EXPECT_EQ(mTestMatrix.Valid(), true);
    EXPECT_EQ(mTestMatrix2.Valid(), true);
    
    // Compare the matrices
    EXPECT_EQ(mTestMatrix.Compare(mTestMatrix2), 0);
    
    // Create a new matrix
    mTestMatrix2 = trBase::Matrix(mArrayD);
    
    // Compare the matrices
    EXPECT_EQ(mTestMatrix.Compare(mTestMatrix2), -1);
    EXPECT_EQ(mTestMatrix2.Compare(mTestMatrix), 1);
}

/**
 * @fn  TEST_F(MatrixTests, SetMatrixFromNum)
 *
 * @brief   Test the setting of a Matrix from raw input
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, SetMatrixFromNum)
{
    // Set the matrix from input
    mTestMatrix.Set(1.2, 1.3, 1.4, 0.5,
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

    // Set the double matrix
    mTestMatrixD1.Set(1.0, 2.0, 3.0, 4.0,
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
    
    // Set the float matrix
    mTestMatrixF1.Set(9.0, 8.0, 7.0, 6.0,
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
 * @fn  TEST_F(MatrixTests, SetMatrixFromMatrix)
 *
 * @brief   Test the setting of a Matrix from another Matrix
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, SetMatrixFromMatrix)
{
    // Set a float matrix
    mTestMatrixF1.Set(9.0, 8.0, 7.0, 6.0,
                      5.0, 4.0, 3.0, 2.0,
                      1.0, 2.0, 3.0, 4.0,
                      5.0, 6.0, 7.0, 8.0);
    
    // Set a double matrix
    mTestMatrixD1.Set(1.0, 2.0, 3.0, 4.0,
                      5.0, 6.0, 7.0, 8.0,
                      9.0, 8.0, 7.0, 6.0,
                      5.0, 4.0, 3.0, 2.0);

    // Set a float matrix from float matrix
    mTestMatrixF2.Set(mTestMatrixF1);
    
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
    
    // Set a float matrix from double matrix
    mTestMatrixF2.Set(mTestMatrixD1);

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

    // Set a double matrix from float matrix
    mTestMatrixD2.Set(mTestMatrixF1);
    
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
    
    // Set a double matrix from double matrix
    mTestMatrixD2.Set(mTestMatrixD1);

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

    // Set a matrix from float matrix
    mTestMatrix.Set(mTestMatrixF1);
    
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
    
    // Set a matrix from double matrix
    mTestMatrix.Set(mTestMatrixD1);

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
 * @fn  TEST_F(MatrixTests, SetMatrixFromArray)
 *
 * @brief   Test the setting of a Matrix from an array
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, SetMatrixFromArray)
{
    // Create a new matrix
    mTestMatrixF1.Set(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixF1(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixF1(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixF1(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrixF1(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 3), 0.1, 1e-6);
    
    // Create a new matrix
    mTestMatrixF1.Set(mArrayD);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixF1(0, 0), 2.1, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 2), 5.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(0, 3), 4.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixF1(1, 0), 7.8, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 2), 8.9, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(1, 3), 0.5, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixF1(2, 0), 5.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 1), 6.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 2), 7.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(2, 3), 2.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrixF1(3, 0), 4.5, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 1), 3.3, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 2), 2.6, 1e-6);
    EXPECT_NEAR(mTestMatrixF1(3, 3), 8.3, 1e-6);
    
    // Create a new matrix
    mTestMatrixD1.Set(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrixD1(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrixD1(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrixD1(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrixD1(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatrixD1(3, 3), 0.1, 1e-6);
    
    // Create a new matrix
    mTestMatrixD1.Set(mArrayD);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrixD1(0, 0), 2.1);
    EXPECT_EQ(mTestMatrixD1(0, 1), 4.3);
    EXPECT_EQ(mTestMatrixD1(0, 2), 5.6);
    EXPECT_EQ(mTestMatrixD1(0, 3), 4.5);

    // Test the second row values
    EXPECT_EQ(mTestMatrixD1(1, 0), 7.8);
    EXPECT_EQ(mTestMatrixD1(1, 1), 8.7);
    EXPECT_EQ(mTestMatrixD1(1, 2), 8.9);
    EXPECT_EQ(mTestMatrixD1(1, 3), 0.5);

    // Test the third row values
    EXPECT_EQ(mTestMatrixD1(2, 0), 5.6);
    EXPECT_EQ(mTestMatrixD1(2, 1), 6.6);
    EXPECT_EQ(mTestMatrixD1(2, 2), 7.3);
    EXPECT_EQ(mTestMatrixD1(2, 3), 2.5);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrixD1(3, 0), 4.5);
    EXPECT_EQ(mTestMatrixD1(3, 1), 3.3);
    EXPECT_EQ(mTestMatrixD1(3, 2), 2.6);
    EXPECT_EQ(mTestMatrixD1(3, 3), 8.3);
    
    // Create a new matrix
    mTestMatrix.Set(mArrayF);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_NEAR(mTestMatrix(0, 0), 3.2, 1e-6);
    EXPECT_NEAR(mTestMatrix(0, 1), 4.3, 1e-6);
    EXPECT_NEAR(mTestMatrix(0, 2), 5.4, 1e-6);
    EXPECT_NEAR(mTestMatrix(0, 3), 6.5, 1e-6);

    // Test the second row values
    EXPECT_NEAR(mTestMatrix(1, 0), 7.6, 1e-6);
    EXPECT_NEAR(mTestMatrix(1, 1), 8.7, 1e-6);
    EXPECT_NEAR(mTestMatrix(1, 2), 9.8, 1e-6);
    EXPECT_NEAR(mTestMatrix(1, 3), 0.9, 1e-6);

    // Test the third row values
    EXPECT_NEAR(mTestMatrix(2, 0), 0.8, 1e-6);
    EXPECT_NEAR(mTestMatrix(2, 1), 0.7, 1e-6);
    EXPECT_NEAR(mTestMatrix(2, 2), 0.6, 1e-6);
    EXPECT_NEAR(mTestMatrix(2, 3), 0.5, 1e-6);

    // Test the fourth row values
    EXPECT_NEAR(mTestMatrix(3, 0), 0.4, 1e-6);
    EXPECT_NEAR(mTestMatrix(3, 1), 0.3, 1e-6);
    EXPECT_NEAR(mTestMatrix(3, 2), 0.2, 1e-6);
    EXPECT_NEAR(mTestMatrix(3, 3), 0.1, 1e-6);
    
    // Create a new matrix
    mTestMatrix.Set(mArrayD);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 2.1);
    EXPECT_EQ(mTestMatrix(0, 1), 4.3);
    EXPECT_EQ(mTestMatrix(0, 2), 5.6);
    EXPECT_EQ(mTestMatrix(0, 3), 4.5);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 7.8);
    EXPECT_EQ(mTestMatrix(1, 1), 8.7);
    EXPECT_EQ(mTestMatrix(1, 2), 8.9);
    EXPECT_EQ(mTestMatrix(1, 3), 0.5);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 5.6);
    EXPECT_EQ(mTestMatrix(2, 1), 6.6);
    EXPECT_EQ(mTestMatrix(2, 2), 7.3);
    EXPECT_EQ(mTestMatrix(2, 3), 2.5);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 4.5);
    EXPECT_EQ(mTestMatrix(3, 1), 3.3);
    EXPECT_EQ(mTestMatrix(3, 2), 2.6);
    EXPECT_EQ(mTestMatrix(3, 3), 8.3);
}

/**
 * @fn  TEST_F(MatrixTests, GetPointer)
 *
 * @brief   Test the method for returning a Matrix pointer
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, GetPointer)
{
    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixF1.Valid(), true);
    
    // Test if the pointer is NULL
    EXPECT_EQ(nullptr, mMatPtrF);
    
    // Get the float pointer holding the float matrix
    mMatPtrF = mTestMatrixF1.Ptr();
    
    // Test if the pointer is NULL
    EXPECT_NE(nullptr, mMatPtrF);
    
    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrixD1.Valid(), true);
    
    // Test if the pointer is NULL
    EXPECT_EQ(nullptr, mMatPtrD);
    
    // Get the double pointer holding the double matrix
    mMatPtrD = mTestMatrixD1.Ptr();
    
    // Test if the pointer is NULL
    EXPECT_NE(nullptr, mMatPtrD);
}