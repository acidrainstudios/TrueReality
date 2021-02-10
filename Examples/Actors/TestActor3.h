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
#pragma once

#include <trManager/MessageTick.h>
#include <trManager/ActorBase.h>
#include <trUtil/RefStr.h>

#include <string>

class TestActor3 : public trManager::ActorBase
{
public:
    using BaseClass = trManager::ActorBase;                 /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr CLASS_TYPE;                 /// Holds the class type name for efficient comparisons

    const static trUtil::RefStr ON_TEST_ACTOR_2_INVOKABLE;  /// Invokable for messages going to TestActor2

    /**
     * @fn  TestActor3::TestActor3(const std::string& name = CLASS_TYPE);
     *
     * @brief   Constructor.
     *
     * @param   name    (Optional) The name.
     */
    TestActor3(const std::string& name = CLASS_TYPE);

    /**
    * @fn  virtual const std::string& TestActor3::GetType() const override
    *
    * @brief   Gets the class type.
    *
    * @return  The type.
    */
    virtual const std::string& GetType() const override { return CLASS_TYPE; }

    /**
    * @fn  virtual void TestActor3::BuildInvokables();
    *
    * @brief   Builds the default invokables for this class.
    */
    virtual void BuildInvokables();

    /**
    * @fn  virtual void TestActor3::OnTick(const trManager::MessageBase& msg);
    *
    * @brief   Executes on Reception of the Tick Message.
    *
    * @param   msg The message.
    */
    virtual void OnTick(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestActor3::AboutTestActor2(const trManager::MessageBase& msg);
     *
     * @brief   Handles intercepted messages that are going to TestActor2.
     *
     * @param   msg The message.
     */
    virtual void AboutTestActor2(const trManager::MessageBase& msg);

    /**
    * @fn  virtual void TestActor3::OnAddedToSysMan() override;
    *
    * @brief   Runs when the director is added to system manager.
    */
    virtual void OnAddedToSysMan() override;

    /**
     * @fn  static int TestActor3::GetInstCount();
     *
     * @brief   Gets instance count for this class type. Used for error checking, and Unit Testing.
     *
     * @return  The instance count.
     */
    static int GetInstCount();
protected:

    /**
    * @fn  TestActor3::~TestActor3();
    *
    * @brief   Destructor.
    */
    ~TestActor3();

    static int mInstCount;
};

