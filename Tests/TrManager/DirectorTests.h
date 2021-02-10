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

#include <gtest/gtest.h>

#include <trBase/SmrtPtr.h>
#include <trCore/SystemDirector.h>
#include <trManager/SystemManager.h>

/**
 * @class    DirectorTests
 *
 * @brief    Sets up the unit test environment for Director classes.
 */
class DirectorTests : public ::testing::Test
{
public:

    /** @brief   Manager pointer for system. */
    trBase::SmrtPtr<trManager::SystemManager> mSysMan;

    /** @brief   The system director pointer. */
    trBase::SmrtPtr<trCore::SystemDirector> mSysDirector;

    /**
     * @fn  public::DirectorTests();
     *
     * @brief   Default constructor.
     */
    DirectorTests();

    /**
     * @fn  public::~DirectorTests();
     *
     * @brief   Destructor.
     */
    ~DirectorTests();
};