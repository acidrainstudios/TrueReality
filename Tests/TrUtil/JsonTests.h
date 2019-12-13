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

#include <gtest/gtest.h>

/**
 * @class   JsonTests
 *
 * @brief   Sets up test environment for Json class tests.
 *
 * @author  Maxim Serebrennik
 */
class JsonTests : public ::testing::Test
{

public:

    const static std::string CONFIG_FILE_NAME;

    /**
     * @fn  public::JsonTests();
     *
     * @brief   Default constructor.
     */
    JsonTests();

    /**
     * @fn  public::~JsonTests();
     *
     * @brief   Destructor.
     */
    ~JsonTests();
};