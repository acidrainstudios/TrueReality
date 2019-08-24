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
    mNullID = trBase::UniqueId(false);
    mNewID1 = trBase::UniqueId(NULL_ID);
    mNewID2 = trBase::UniqueId(TEST_ID);
    mNewID3 = trBase::UniqueId();
}

//////////////////////////////////////////////////////////////////////////
UniqueIdTests::~UniqueIdTests()
{
}

/**
 * @fn  TEST_F(UniqueIdTests, ClassTypeTests)
 *
 * @brief   Testing of the class type definition
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(UniqueIdTests, ClassTypeTests)
{
    EXPECT_EQ(mNullID.GetType(), trBase::UniqueId::CLASS_TYPE);
    EXPECT_EQ(mNewID1.GetType(), trBase::UniqueId::CLASS_TYPE);
    EXPECT_EQ(mNewID2.GetType(), trBase::UniqueId::CLASS_TYPE);
    EXPECT_EQ(mNewID3.GetType(), trBase::UniqueId::CLASS_TYPE);
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
    // Test equality to string
    EXPECT_EQ(mNullID.ToString(), "00000000-0000-0000-0000-000000000000");

    // Test equality to RefString
    EXPECT_EQ(mNullID.ToString(), NULL_ID);

    //Test equality to another null id
    EXPECT_EQ(mNullID.ToString(), mNewID1.ToString());

    // Test equality to string
    EXPECT_NE(mNewID3.ToString(), "00000000-0000-0000-0000-000000000000");

    // Test equality to RefString
    EXPECT_NE(mNewID3.ToString(), NULL_ID);
}

/**
 * @fn  TEST_F(UniqueIdTests, ComparisonTests)
 *
 * @brief   Comparison tests.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(UniqueIdTests, ComparisonTests)
{
    //Test inequality to another null id
    EXPECT_NE(mNewID3.ToString(), mNewID1.ToString());

    //Test inequality operator to another null id
    EXPECT_EQ(mNewID3 != mNewID1, true);

    //Test equality operator to another null id
    EXPECT_EQ(mNewID3 == mNewID1, false);

    //Test inequality operator to another null id
    EXPECT_EQ(mNewID3 != mNewID1, true);

    //Test equality operator to another null id
    EXPECT_EQ(mNewID3 == mNewID2, false);

    // Test the equality operator
    EXPECT_EQ(mNullID != mNewID2, true);

    // Test the equality operator
    EXPECT_EQ(mNullID == mNewID1, true);
}