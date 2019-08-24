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

#include "UniqueIdTests.h"

#include <trBase/UniqueId.h>
#include <trUtil/RefStr.h>

#include <iostream>
#include <string>

const trUtil::RefStr UniqueIdTests::NULL_ID = trUtil::RefStr("00000000-0000-0000-0000-000000000000");
const trUtil::RefStr UniqueIdTests::TEST_ID = trUtil::RefStr("1020ac56-6732-6969-ffd0-fdabc4376cca");

//////////////////////////////////////////////////////////////////////////
UniqueIdTests::UniqueIdTests()
{

}

//////////////////////////////////////////////////////////////////////////
UniqueIdTests::~UniqueIdTests()
{
}

/**
 * @fn  TEST_F(UniqueIdTests, NULL)
 *
 * @brief   Test NULL ID creation.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(UniqueIdTests, NULLTests)
{
    trBase::UniqueId nullID(false);
    trBase::UniqueId newID1(NULL_ID);
    trBase::UniqueId newID2(TEST_ID);
    trBase::UniqueId newID3;

    // Test equality to string
    EXPECT_EQ(nullID.ToString(), "00000000-0000-0000-0000-000000000000");

    // Test equality to RefString
    EXPECT_EQ(nullID.ToString(), NULL_ID);

    //Test equality to another null id
    EXPECT_EQ(nullID.ToString(), newID1.ToString());

}


//
///**
// * @fn  TEST_F(MatrixTests, GetPointer)
// *
// * @brief   Test the method for returning a Matrix pointer
// *
// * @param   parameter1  The first parameter.
// * @param   parameter2  The second parameter.
// */
//TEST_F(MatrixTests, GetPointer)
//{
//    // Test if the matrix is valid
//    EXPECT_EQ(mTestMatrixF1.Valid(), true);
//
//    // Test if the pointer is NULL
//    EXPECT_EQ(nullptr, mMatPtrF);
//
//    // Get the float pointer holding the float matrix
//    mMatPtrF = mTestMatrixF1.Ptr();
//
//    // Test if the pointer is NULL
//    EXPECT_NE(nullptr, mMatPtrF);
//
//    // Test if the matrix is valid
//    EXPECT_EQ(mTestMatrixD1.Valid(), true);
//
//    // Test if the pointer is NULL
//    EXPECT_EQ(nullptr, mMatPtrD);
//
//    // Get the double pointer holding the double matrix
//    mMatPtrD = mTestMatrixD1.Ptr();
//
//    // Test if the pointer is NULL
//    EXPECT_NE(nullptr, mMatPtrD);
//}