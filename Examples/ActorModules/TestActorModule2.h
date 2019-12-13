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

#include <trManager/ActorModuleBase.h>

#include <string>

class TestActorModule2 : public trManager::ActorModuleBase
{
public:
    using BaseClass = trManager::ActorModuleBase;                 /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr CLASS_TYPE;                 /// Holds the class type name for efficient comparisons

    const static trUtil::RefStr ON_TEST_ACTOR_2_INVOKABLE;  /// Invokable for messages going to TestActor2

    /**
     * @fn  TestActorModule2::TestActorModule2(const std::string& name = CLASS_TYPE);
     *
     * @brief   Constructor.
     *
     * @param   name    (Optional) The name.
     */
    TestActorModule2(const std::string& name = CLASS_TYPE);

    /**
    * @fn  virtual const std::string& TestActorModule2::GetType() const override
    *
    * @brief   Gets the class type.
    *
    * @return  The type.
    */
    virtual const std::string& GetType() const override { return CLASS_TYPE; }

    /**
    * @fn  virtual void TestActorModule2::BuildInvokables();
    *
    * @brief   Builds the default invokables for this class.
    */
    virtual void BuildInvokables();

    /**
    * @fn  virtual void TestActorModule2::OnTick(const trManager::MessageBase& msg);
    *
    * @brief   Executes on Reception of the Tick Message.
    *
    * @param   msg The message.
    */
    virtual void OnTick(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestActorModule2::OnMessage(const trManager::MessageBase& msg);
     *
     * @brief   Function that is used by the Systems Manager to deliver all messages to the Director.
     *
     * @param   msg The message.
     */
    virtual void OnMessage(const trManager::MessageBase& msg) override;

    /**
    * @fn  virtual void TestActorModule2::OnAddedToSysMan() override;
    *
    * @brief   Runs when the director is added to system manager.
    */
    virtual void OnAddedToSysMan() override;

    /**
     * @fn  static int TestActorModule2::GetInstCount();
     *
     * @brief   Gets instance count for this class type. Used for error checking, and Unit Testing.
     *
     * @return  The instance count.
     */
    static int GetInstCount();

protected:

    /**
    * @fn  TestActorModule2::~TestActorModule2();
    *
    * @brief   Destructor.
    */
    ~TestActorModule2();

private:

    static int mInstCount;
};

