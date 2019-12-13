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

#include <trBase/UniqueId.h>
#include <trUtil/RefStr.h>

/**
 * @class   UniqueIdTests
 *
 * @brief   Sets up test environment for UniqueId class tests.
 */
class UniqueIdTests : public ::testing::Test
{

public:

    const static trUtil::RefStr NULL_ID;
    const static trUtil::RefStr TEST_ID;
    const static trUtil::RefStr TEST_ID2;

    trBase::UniqueId mNullID;
    trBase::UniqueId mNewID1;
    trBase::UniqueId mNewID2;
    trBase::UniqueId mNewID3;
    trBase::UniqueId mNewID4;


    /**
     * @fn  public::MatrixTests();
     *
     * @brief   Default constructor.
     */
    UniqueIdTests();

    /**
     * @fn  public::~MatrixTests();
     *
     * @brief   Destructor.
     */
    ~UniqueIdTests();


};