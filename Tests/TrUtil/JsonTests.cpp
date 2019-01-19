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

#include "JsonTests.h"

#include <trUtil/JSON/Value.h>

#include <json/value.h>

#include <iostream>

//////////////////////////////////////////////////////////////////////////
JsonTests::JsonTests()
{
}

//////////////////////////////////////////////////////////////////////////
JsonTests::~JsonTests()
{
}

/**
 * @fn  TEST_F(JsonTests, JsonValueType)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(JsonTests, JsonValueType)
{
    EXPECT_EQ(Json::ValueType::nullValue, 0);
    EXPECT_EQ(Json::ValueType::intValue, 1);
    EXPECT_EQ(Json::ValueType::uintValue, 2);
    EXPECT_EQ(Json::ValueType::realValue, 3);
    EXPECT_EQ(Json::ValueType::stringValue, 4);
    EXPECT_EQ(Json::ValueType::booleanValue, 5);
    EXPECT_EQ(Json::ValueType::arrayValue, 6);
    EXPECT_EQ(Json::ValueType::objectValue, 7);
}

/**
 * @fn  TEST_F(JsonTests, JSONValueType)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(JsonTests, JSONValueType)
{
    EXPECT_EQ(trUtil::JSON::ValueType::NullValue, 0);
    EXPECT_EQ(trUtil::JSON::ValueType::IntValue, 1);
    EXPECT_EQ(trUtil::JSON::ValueType::UintValue, 2);
    EXPECT_EQ(trUtil::JSON::ValueType::RealValue, 3);
    EXPECT_EQ(trUtil::JSON::ValueType::StringValue, 4);
    EXPECT_EQ(trUtil::JSON::ValueType::BooleanValue, 5);
    EXPECT_EQ(trUtil::JSON::ValueType::ArrayValue, 6);
    EXPECT_EQ(trUtil::JSON::ValueType::ObjectValue, 7);
}
