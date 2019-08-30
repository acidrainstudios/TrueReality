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

#include <trBase/SmrtPtr.h>
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
    mNewID1 = trBase::UniqueId(static_cast<std::string>(NULL_ID));
    mNewID2 = trBase::UniqueId(static_cast<std::string>(TEST_ID));
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
 * @fn  TEST_F(UniqueIdTests, ClassTypeTests)
 *
 * @brief   Constructor Tests
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(UniqueIdTests, ConstructorTests)
{
    trBase::UniqueId newID1(static_cast<std::string>(NULL_ID));
    trBase::UniqueId newID2(static_cast<std::string>(TEST_ID));
    trBase::UniqueId newID3(true);
    trBase::UniqueId newID4(false);
    trBase::UniqueId newID5(mNewID2);

    EXPECT_EQ(newID1.ToString(), "00000000-0000-0000-0000-000000000000");
    EXPECT_EQ(newID2.ToString(), "1020ac56-6732-6969-ffd0-fdabc4376cca");
    EXPECT_NE(newID3.ToString(), "1020ac56-6732-6969-ffd0-fdabc4376cca");
    EXPECT_NE(newID3.ToString(), "00000000-0000-0000-0000-000000000000");
    EXPECT_EQ(newID3 != mNullID, true);
    EXPECT_EQ(newID3 != mNewID1, true);
    EXPECT_EQ(newID3 != mNewID2, true);
    EXPECT_EQ(newID3 != mNewID3, true);
    EXPECT_EQ(newID4.ToString(), "00000000-0000-0000-0000-000000000000");
    EXPECT_EQ(newID4 == mNullID, true);
    EXPECT_EQ(newID5 == mNewID2, true);
    EXPECT_EQ(newID5.ToString(), "1020ac56-6732-6969-ffd0-fdabc4376cca");
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

/**
 * @fn  TEST_F(UniqueIdTests, FromStringTests)
 *
 * @brief   From String function tests.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(UniqueIdTests, FromStringTests)
{
    trBase::UniqueId newID1;
    trBase::UniqueId newID2;

    newID1.FromString("00000000-0000-0000-0000-000000000000");
    newID2.FromString("1020ac56-6732-6969-ffd0-fdabc4376cca");

    EXPECT_EQ(newID1 == mNewID1, true);
    EXPECT_EQ(newID2 == mNewID2, true);
    EXPECT_EQ(newID1 != newID2, true);
}

/**
 * @fn  TEST_F(UniqueIdTests, IsNullTests)
 *
 * @brief   IsNull function tests.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(UniqueIdTests, IsNullTests)
{
    trBase::UniqueId newID1;
    trBase::UniqueId newID2;
    trBase::UniqueId newID3(false);

    newID1.FromString("00000000-0000-0000-0000-000000000000");
    newID2.FromString("1020ac56-6732-6969-ffd0-fdabc4376cca");

    EXPECT_EQ(newID1.IsNull(), true);
    EXPECT_EQ(!newID2.IsNull(), true);
    EXPECT_EQ(newID3.IsNull(), true);
    EXPECT_EQ(newID1 == newID3, true);
}

/**
 * @fn  TEST_F(UniqueIdTests, AssignmentTests)
 *
 * @brief   IsNull function tests.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(UniqueIdTests, AssignmentTests)
{
    trBase::SmrtPtr<trBase::UniqueId> newID1 = new trBase::UniqueId();
    trBase::UniqueId newID2;
    trBase::UniqueId newID3(false);
    trBase::UniqueId testID;

    newID1->FromString("1020ac56-0000-0000-0000-fdabc4376cca");
    newID2.FromString("1020ac56-6732-6969-ffd0-fdabc4376cca");

    // Tests the = *
    testID = newID1.Get();
    EXPECT_EQ(testID == *newID1, true);
    EXPECT_EQ(testID != newID2, true);
    EXPECT_EQ(testID != newID3, true);
    EXPECT_EQ(testID.IsNull(), false);

    // Tests the = &
    testID = newID2;
    EXPECT_EQ(testID != *newID1, true);
    EXPECT_EQ(testID == newID2, true);
    EXPECT_EQ(testID != newID3, true);
    EXPECT_EQ(testID.IsNull(), false);

    // Tests the = std::string
    trBase::UniqueId testID4(static_cast<std::string>("00696000-6732-6969-ffd0-000006960000"));
    testID = static_cast<std::string>("00696000-6732-6969-ffd0-000006960000");
    EXPECT_EQ(testID != *newID1, true);
    EXPECT_EQ(testID != newID2, true);
    EXPECT_EQ(testID != newID3, true);
    EXPECT_EQ(testID == testID4, true);
    EXPECT_EQ(testID.IsNull(), false);
}