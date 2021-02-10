/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2021 Acid Rain Studios LLC
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

#include <trManager/DirectorBase.h>
#include <trUtil/RefStr.h>

#include <string>

class TestDirector2 : public trManager::DirectorBase
{
public:
    using BaseClass = trManager::DirectorBase;      /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

    /**
     * @fn  TestDirector2::TestDirector2(const std::string& name = CLASS_TYPE);
     *
     * @brief   Constructor.
     *
     * @param   name    (Optional) The name.
     */
    TestDirector2(const std::string& name = CLASS_TYPE);

    /**
     * @fn  virtual const std::string& TestDirector2::GetType() const override
     *
     * @brief   Gets the class type.
     *
     * @return  The type.
     */
    virtual const std::string& GetType() const override { return CLASS_TYPE;}

    /**
     * @fn  virtual bool TestDirector2::SendTestMessage();
     *
     * @brief   Sends the test message.
     *
     * @return  True if it succeeds, false if it fails.
     */
    virtual bool SendTestMessage();

    /**
     * @fn  static int TestDirector2::GetInstCount();
     *
     * @brief   Gets instance count for this class type. Used for error checking, and Unit Testing.
     *
     * @return  The instance count.
     */
    static int GetInstCount();

protected:

    static int mInstCount;

    /**
     * @fn  TestDirector2::~TestDirector2();
     *
     * @brief   Destructor.
     */
    ~TestDirector2();
};