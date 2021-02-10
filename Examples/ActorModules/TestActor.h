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

#include <trManager/MessageBase.h>
#include <trManager/ActorBase.h>
#include <trUtil/RefStr.h>

#include <string>

class TestActor : public trManager::ActorBase
{
public:
    using BaseClass = trManager::ActorBase;                         /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr CLASS_TYPE;                         /// Holds the class type name for efficient comparisons

    /**
     * @fn  TestActor::TestActor(const std::string name = CLASS_TYPE);
     *
     * @brief   Constructor.
     *
     * @param   name    (Optional) The name.
     */
    TestActor(const std::string& name = CLASS_TYPE);

    /**
     * @fn  virtual const std::string& TestActor::GetType() const override
     *
     * @brief   Gets the class type.
     *
     * @return  The type.
     */
    virtual const std::string& GetType() const override { return CLASS_TYPE;}

    /**
     * @fn  virtual void TestActor::BuildInvokables();
     *
     * @brief   Registers the message invokables.
     */
    virtual void BuildInvokables() override;

    /**
     * @fn  virtual void TestActor::OnTick(const trManager::MessageBase& msg);
     *
     * @brief   Executes on Reception of the Tick Message.
     *
     * @param   msg The message.
     */
    virtual void OnTick(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestActor::OnAddedToSysMan() override;
     *
     * @brief   Runs when the director is added to system manager.
     */
    virtual void OnAddedToSysMan() override;

protected:

    /**
     * @fn  TestActor::~TestActor();
     *
     * @brief   Destructor.
     */
    ~TestActor();
};

