/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
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

#include <trUtil/Logging/Log.h>

#include <gtest/gtest.h>

#include <string>

/**
 * @class   LoggingTests
 *
 * @brief   Sets up test environment for Logging class tests.
 *
 * @author  Maxim Serebrennik
 */
class LoggingTests : public testing::Test
{

public:

    static const std::string LOG_FILE_NAME;

    /**
     * @fn  public::LoggingTests();
     *
     * @brief   Default constructor.
     */
    LoggingTests();

    /**
     * @fn  public::~LoggingTests();
     *
     * @brief   Destructor.
     */
    ~LoggingTests();

    trUtil::Logging::Log::LogTestData mTestData;
    const char *mTstChar;
    std::string mTstMsg = "Log String";
    int mNumInt = 5;
    double mDbNum = 6.69696969696969696969;
};