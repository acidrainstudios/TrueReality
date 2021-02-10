/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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

#include <trUtil/JSON/Array.h>
#include <trUtil/JSON/File.h>
#include <trUtil/JSON/Value.h>
#include <trUtil/JSON/Object.h>
#include <trUtil/PathUtils.h>
#include <trUtil/FileUtils.h>

#include <json/value.h>

#include <iostream>
#include <string>

//////////////////////////////////////////////////////////////////////////
const std::string JsonTests::CONFIG_FILE_NAME("JsonTest.gtest");

//////////////////////////////////////////////////////////////////////////
JsonTests::JsonTests()
{
    //Creates the default folders in the User Data folder.
    trUtil::PathUtils::CreateUserDataPathTree();
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

/**
 * @fn  TEST_F(JsonTests, JSONJsonValueType)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(JsonTests, JSONJsonValueType)
{
    EXPECT_EQ(trUtil::JSON::ValueType::NullValue, Json::ValueType::nullValue);
    EXPECT_EQ(trUtil::JSON::ValueType::IntValue, Json::ValueType::intValue);
    EXPECT_EQ(trUtil::JSON::ValueType::UintValue, Json::ValueType::uintValue);
    EXPECT_EQ(trUtil::JSON::ValueType::RealValue, Json::ValueType::realValue);
    EXPECT_EQ(trUtil::JSON::ValueType::StringValue, Json::ValueType::stringValue);
    EXPECT_EQ(trUtil::JSON::ValueType::BooleanValue, Json::ValueType::booleanValue);
    EXPECT_EQ(trUtil::JSON::ValueType::ArrayValue, Json::ValueType::arrayValue);
    EXPECT_EQ(trUtil::JSON::ValueType::ObjectValue, Json::ValueType::objectValue);
}

/**
 * @fn  TEST_F(JsonTests, SaveLoadFile)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(JsonTests, SaveLoadFile)
{
    trUtil::JSON::Object jsObject;
    trUtil::JSON::Array jsArray;

    trUtil::JSON::File configFile(CONFIG_FILE_NAME);

    //Inputing Data into Document
    jsArray.AddInt(55);
    jsArray.AddInt(3456);
    jsArray.AddInt64(63752);
    jsArray.AddNull();            //NULLs the value
    jsArray.AddBool(true);
    jsArray.AddString("StringValue");
    jsArray.AddDouble(45.6);
    jsArray.AddUInt(4567);
    jsArray.AddUInt64(12098);
    jsArray.AddFloat(567.54f);
    jsArray.SetComment("///This is the Array Comment");

    jsObject.SetInt("MyInt", 55);
    jsObject.SetInt("MyInt2", 3456);
    jsObject.SetInt64("MyInt64", 63752);
    jsObject.SetNull("MyInt");            //NULLs the value
    jsObject.SetBool("MyBool", true);
    jsObject.SetString("MyString", "StringValue");
    jsObject.SetDouble("MyDouble", 45.6);
    jsObject.SetUInt("MyUint", 4567);
    jsObject.SetUInt64("MyUint64", 12098);
    jsObject.SetFloat("MyFloat", 567.54f);
    jsObject.SetArray("MyArray", jsArray);
    jsObject.SetComment("This is the Object Comment");

    configFile.SetInt("MyInt_OnRoot", 55);
    configFile.SetInt("MyInt2_OnRoot", 3456);
    configFile.SetInt64("MyInt64_OnRoot", 63752);
    configFile.SetNull("MyInt_OnRoot");            //NULLs the value
    configFile.SetBool("MyBool_OnRoot", true);
    configFile.SetString("MyString_OnRoot", "StringValue");
    configFile.SetDouble("MyDouble_OnRoot", 45.6);
    configFile.SetUInt("MyUint_OnRoot", 4567);
    configFile.SetUInt64("MyUint64_OnRoot", 12098);
    configFile.SetFloat("MyFloat_OnRoot", 567.54f);
    configFile.SetObject("MyObject_OnRoot", jsObject);

    // Writing the file out to the user data config folder
    configFile.WriteToFile();

    //Test if the file was written out using system functions
    EXPECT_EQ(trUtil::FileUtils::GetInstance().FileExists(trUtil::PathUtils::GetUserConfigPath() + "/" + CONFIG_FILE_NAME), true);

    //Load the written out file
    trUtil::JSON::File readFile(CONFIG_FILE_NAME);

    //Test if the file was written out using json functions
    EXPECT_EQ(readFile.FileExists(), true);

    readFile.ReadFromFile();

    //Test if the written out array has 10 values
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray").Size(), 10);

    // Test all values in the root of the file
    EXPECT_EQ(readFile.GetInt("MyInt_OnRoot"), 0);  //In this case 0 = NULL
    EXPECT_EQ(readFile.GetInt("MyInt2_OnRoot"), 3456);
    EXPECT_EQ(readFile.GetInt64("MyInt64_OnRoot"), 63752);
    EXPECT_EQ(readFile.GetBool("MyBool_OnRoot"), true);
    EXPECT_EQ(readFile.GetString("MyString_OnRoot"), "StringValue");
    EXPECT_EQ(readFile.GetDouble("MyDouble_OnRoot"), 45.6);
    EXPECT_EQ(readFile.GetUInt("MyUint_OnRoot"), 4567);
    EXPECT_EQ(readFile.GetUInt64("MyUint64_OnRoot"), 12098);
    EXPECT_EQ(readFile.GetFloat("MyFloat_OnRoot"), 567.54f);

    // Test all the values in the Object of the file
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetInt("MyInt"), 0); //In this case 0 = NULL
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetInt("MyInt2"), 3456);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetInt64("MyInt64"), 63752);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetBool("MyBool"), true);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetString("MyString"), "StringValue");
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetDouble("MyDouble"), 45.6);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetUInt("MyUint"), 4567);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetUInt64("MyUint64"), 12098);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetFloat("MyFloat"), 567.54f);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetComment(), "This is the Object Comment");

    // Test all the values in the Array of the file
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[0].GetInt(), 55);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[1].GetInt(), 3456);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[2].GetInt64(), 63752);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[3].IsNull(), true);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[4].GetBool(), true);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[5].GetString(), "StringValue");
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[6].GetDouble(), 45.6);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[7].GetUInt(), 4567);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[8].GetUInt64(), 12098);
    EXPECT_EQ(readFile.GetObject("MyObject_OnRoot").GetArray("MyArray")[9].GetFloat(), 567.54f);
    EXPECT_EQ(jsArray.GetComment(), "///This is the Array Comment");
}
