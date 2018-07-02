/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* @author: Maxim Serebrennik
*/
#pragma once

#include <trManager/MessageBase.h>
#include <trManager/ActorBase.h>
#include <trUtil/RefStr.h>

#include <string>

class TestActor1 : public trManager::ActorBase
{
public:
    typedef trManager::ActorBase BaseClass;                         /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr CLASS_TYPE;                         /// Holds the class type name for efficient comparisons

    const static trUtil::RefStr ON_ENTITY_REGISTERED_INVOKABLE;     /// Invokable for Entity Registered messages
    const static trUtil::RefStr ON_ENTITY_UNREGISTERED_INVOKABLE;   /// Invokable for Entity Registered messages

    /**
     * @fn  TestActor1::TestActor1(const std::string name = CLASS_TYPE);
     *
     * @brief   Constructor.
     *
     * @param   name    (Optional) The name.
     */
    TestActor1(const std::string name = CLASS_TYPE);

    /**
     * @fn  virtual const std::string& TestActor1::GetType() const override
     *
     * @brief   Gets the class type.
     *
     * @return  The type.
     */
    virtual const std::string& GetType() const override { return CLASS_TYPE;}

    /**
     * @fn  virtual void TestActor1::BuildInvokables();
     *
     * @brief   Registers the message invokables.
     */
    virtual void BuildInvokables() override;

    /**
     * @fn  virtual void TestActor1::OnTick(const trManager::MessageBase& msg);
     *
     * @brief   Executes on Reception of the Tick Message.
     *
     * @param   msg The message.
     */
    virtual void OnTick(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestActor1::OnEntityRegistered(const trManager::MessageBase& msg);
     *
     * @brief   Executes the reception of the Entity Registered Message.
     *
     * @param   msg The message.
     */
    virtual void OnEntityRegistered(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestActor1::OnEntityUnregistered(const trManager::MessageBase& msg);
     *
     * @brief   Executes the reception of the Entity Unregistered Message.
     *
     * @param   msg The message.
     */
    virtual void OnEntityUnregistered(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestActor1::OnAddedToSysMan() override;
     *
     * @brief   Runs when the director is added to system manager.
     */
    virtual void OnAddedToSysMan() override;

protected:

    /**
     * @fn  TestActor1::~TestActor1();
     *
     * @brief   Destructor.
     */
    ~TestActor1();

    /**
     * @fn  virtual void TestActor1::HandleTickMessage(const trManager::MessageBase& msg);
     *
     * @brief   Handles the tick message.
     *
     * @param   msg The message.
     */
    virtual void HandleTickMessage(const trManager::MessageBase& msg);

private:

    trBase::UniqueId mActor2Id;
};

