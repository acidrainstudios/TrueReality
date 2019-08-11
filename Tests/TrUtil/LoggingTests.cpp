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

#include "LoggingTests.h"

#include <trUtil/PathUtils.h>
#include <trUtil/StringUtils.h>
#include <trUtil/Logging/Log.h>

#include <iostream>
#include <string>

const std::string LoggingTests::LOG_FILE_NAME("LoggingTests.html");

//////////////////////////////////////////////////////////////////////////
LoggingTests::LoggingTests()
{
    mTstChar = "Log Char";

    // Creates the default folders in the User Data folder. 
    trUtil::PathUtils::CreateUserDataPathTree();

    // Sets the log filename
    trUtil::Logging::LogFile::SetFileName(LOG_FILE_NAME);

    // Turn on Unit Test Data collection
    trUtil::Logging::Log::GetInstance().SetTestMode(true);

    // Set Logging output to file only
    trUtil::Logging::Log::GetInstance().SetAllOutputStreamBits(trUtil::Logging::Log::TO_FILE);

    // Set the log level to DEBUG
    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_DEBUG);
}

//////////////////////////////////////////////////////////////////////////
LoggingTests::~LoggingTests()
{
}

/**
 * @fn  TEST_F(LoggingTests, LoggingStringTests)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(LoggingTests, LoggingStringTests)
{
    LOG_D("Message" << " " << mTstMsg << " " << mTstChar << " " << mNumInt++ << " " << mDbNum)
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.msg, "Message Log String Log Char 5 6.69697");

    LOG_I("Message" << " " + mTstMsg + " " << mTstChar << " " << mNumInt++ << " " << mDbNum);
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.msg, "Message Log String Log Char 6 6.69697");

    LOG_W(mTstMsg + " Message " + mTstChar + " " << ++mNumInt << " " << mDbNum)
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.msg, "Log String Message Log Char 8 6.69697");

    LOG_E("Message" << " " + mTstMsg + " " + mTstChar + " " << mNumInt++ << " " + trUtil::StringUtils::ToString<double>(mDbNum, 10));
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.msg, "Message Log String Log Char 8 6.696969697");

    LOG_A("Message" << " " << mTstMsg << " " << mTstChar << " " << ++mNumInt << " " << trUtil::StringUtils::ToString<double>(mDbNum, 2))
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.msg, "Message Log String Log Char 10 6.7");
}

/**
 * @fn  TEST_F(LoggingTests, LoggingFileTests)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(LoggingTests, LoggingFileTests)
{
    LOG_D("Test Message")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.file, "LoggingTests.cpp");
}

/**
 * @fn  TEST_F(LoggingTests, LoggingLineTests)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(LoggingTests, LoggingLineTests)
{
    LOG_D("Test Message")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    
    // This Test is specific to the Line the LOG_D is located on in this file. 
    // If the line changes due to code being added or removed, this test needs to be adjusted
    EXPECT_EQ(mTestData.line, 115);
}

/**
 * @fn  TEST_F(LoggingTests, LoggingLineLevel)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(LoggingTests, LoggingLevelTests)
{
    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_ALWAYS);
    LOG_A("Test Message")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.logLevel, trUtil::Logging::LogLevel::LOG_ALWAYS);

    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_ERROR);
    LOG_E("Test Message2")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.logLevel, trUtil::Logging::LogLevel::LOG_ERROR);

    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_INFO);
    LOG_I("Test Message3")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.logLevel, trUtil::Logging::LogLevel::LOG_INFO);

    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_WARNING);
    LOG_W("Test Message4")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.logLevel, trUtil::Logging::LogLevel::LOG_WARNING);

    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_DEBUG);
    LOG_D("Test Message5")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.logLevel, trUtil::Logging::LogLevel::LOG_DEBUG);    
}

/**
 * @fn  TEST_F(LoggingTests, LoggingNameTests)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(LoggingTests, LoggingNameTests)
{
    LOG_A("Test Message")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.logName, trUtil::Logging::Log::LOG_DEFAULT_NAME);
}

/**
 * @fn  TEST_F(LoggingTests, LoggingMethodTests)
 *
 * @brief   Constructor.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(LoggingTests, LoggingMethodTests)
{
    LOG_A("Test Message")
    mTestData = *trUtil::Logging::Log::GetInstance().GetLastLogData();
    EXPECT_EQ(mTestData.method, "LoggingTests_LoggingMethodTests_Test::TestBody");
}
