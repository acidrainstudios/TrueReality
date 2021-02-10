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

#include <trManager/DirectorBase.h>
#include <trUtil/RefStr.h>
#include <trBase/UniqueId.h>

#include <string>

class TestDirector : public trManager::DirectorBase
{
public:
    using BaseClass = trManager::DirectorBase;              /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr CLASS_TYPE;                 /// Holds the class type name for efficient comparisons

    const static int MAX_FRAME_NUMBER = 25;                 ///Number of frames for the loop to run.
    const static int NEW_ACTOR_MODULE_FRAME_NUMBER = 5;     ///Number of frames when a new actor module is created.
    const static int KILL_ACTOR_MODULE_FRAME_NUMBER = 20;   ///Number of frames when the created actor module is removed.

    /**
     * @fn  TestDirector::TestDirector(const std::string name = CLASS_TYPE);
     *
     * @brief   Constructor.
     *
     * @param   name    (Optional) The name.
     */
    TestDirector(const std::string& name = CLASS_TYPE);

    /**
     * @fn  virtual const std::string& TestDirector::GetType() const override
     *
     * @brief   Gets the class type.
     *
     * @return  The type.
     */
    virtual const std::string& GetType() const override { return CLASS_TYPE;}

    /**
     * @fn  virtual void TestDirector::OnMessage(const trManager::MessageBase& msg);
     *
     * @brief   This function receives messages coming from the System Manager.
     *
     * @param   msg The message.
     */
    virtual void OnMessage(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestDirector::OnTick(const trManager::MessageBase& msg);
     *
     * @brief   Executes on Reception of the Tick Message.
     *
     * @param   msg The message.
     */
    virtual void OnTick(const trManager::MessageBase& msg);

    /**
     * @fn  virtual void TestDirector::OnAddedToSysMan() override;
     *
     * @brief   Runs when the director is added to system manager.
     */
    virtual void OnAddedToSysMan() override;

protected:

    /**
     * @fn  TestDirector::~TestDirector();
     *
     * @brief   Destructor.
     */
    ~TestDirector();

    /**
     * @fn  virtual void TestDirector::HandleTickMessage(const trManager::MessageBase& msg);
     *
     * @brief   Handles the tick message.
     *
     * @param   msg The message.
     */
    virtual void HandleTickMessage(const trManager::MessageBase& msg);

private:

    trBase::UniqueId mActorsModuleId;
};

