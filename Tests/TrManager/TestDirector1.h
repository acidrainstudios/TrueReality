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
* @author Maxim Serebrennik
*/
#pragma once

#include <trManager/DirectorBase.h>
#include <trManager/MessageBase.h>
#include <trUtil/RefStr.h>

#include <string>

class TestDirector1 : public trManager::DirectorBase
{
public:
    using BaseClass = trManager::DirectorBase;      /// Adds an easy and swappable access to the base class.

    const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons.

    const static trUtil::RefStr ON_TEST_MESSAGE_INVOKABLE;

    /**
     * @fn  TestDirector1::TestDirector1(const std::string name = CLASS_TYPE);
     *
     * @brief   Constructor.
     *
     * @param   name    (Optional) The name.
     */
    TestDirector1(const std::string name = CLASS_TYPE);

    /**
     * @fn  virtual const std::string& TestDirector1::GetType() const override
     *
     * @brief   Gets the class type.
     *
     * @return  The type.
     */
    virtual const std::string& GetType() const override { return CLASS_TYPE;}

    /**
     * @fn  virtual void TestDirector1::BuildInvokables() override;
     *
     * @brief   Builds the invokables.
     */
    virtual void BuildInvokables() override;

    /**
     * @fn  virtual void TestDirector1::OnMessage(const trManager::MessageBase& msg);
     *
     * @brief   This function receives messages coming from the System Manager.
     *
     * @param   msg The message.
     */
    virtual void OnMessage(const trManager::MessageBase &msg);

    /**
     * @fn  virtual void TestDirector1::OnTick(const trManager::MessageBase& msg);
     *
     * @brief   Executes on Reception of the Tick Message.
     *
     * @param   msg The message.
     */
    virtual void OnTick(const trManager::MessageBase &msg);

    /**
     * @fn  virtual void TestDirector1::OnAddedToSysMan() override;
     *
     * @brief   Runs when the director is added to system manager.
     */
    virtual void OnAddedToSysMan() override;

    /**
     * @fn  virtual void TestDirector1::OnTestMessage(const trManager::MessageBase& msg);
     *
     * @brief   Executes the test message action.
     *
     * @param   msg The message.
     */
    virtual void OnTestMessage(const trManager::MessageBase &msg);

    /**
     * @fn  virtual int TestDirector1::GetTestMessageNum();
     *
     * @brief   Gets the number of received test messages.
     *
     * @return  The test message number.
     */
    virtual int GetTestMessageNum();

    /**
     * @fn  virtual int TestDirector1::GetTickMsgNumber();
     *
     * @brief   Gets the number of messages this class received. 
     *          
     *
     * @return  The tick message number.
     */
    virtual int GetTickMsgNumber();

    /**
     * @fn  virtual int TestDirector1::GetEventTraversalEventMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The event traversal message number.
     */
    virtual int GetEventTraversalEventMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetPostEventTraversalEventMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The post event traversal message number.
     */
    virtual int GetPostEventTraversalEventMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetPreFrameEventMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The pre frame message number.
     */
    virtual int GetPreFrameEventMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetCameraSynchEventMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The camera synchronise message number.
     */
    virtual int GetCameraSynchEventMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetFrameSynchEventMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The frame synchronise message number.
     */
    virtual int GetFrameSynchEventMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetFrameEventMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The frame message number.
     */
    virtual int GetFrameEventMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetPostFrameEventMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The post frame message number.
     */
    virtual int GetPostFrameEventMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetEventTraversalMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The event traversal message number.
     */
    virtual int GetEventTraversalMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetPostEventTraversalMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The post event traversal message number.
     */
    virtual int GetPostEventTraversalMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetCameraSynchMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The camera synchronise message number.
     */
    virtual int GetCameraSynchMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetFrameSynchMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The frame synchronise message number.
     */
    virtual int GetFrameSynchMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetFrameMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The frame message number.
     */
    virtual int GetFrameMsgNum();

    /**
     * @fn  virtual int TestDirector1::GetPostFrameMsgNum();
     *
     * @brief   Gets the number of messages this class received.
     *
     * @return  The post frame message number.
     */
    virtual int GetPostFrameMsgNum();

protected:

    /**
     * @fn  TestDirector1::~TestDirector1();
     *
     * @brief   Destructor.
     */
    ~TestDirector1();

    /**
     * @fn  virtual void TestDirector1::HandleSystemEvent(const trManager::MessageBase& msg);
     *
     * @brief   Handles the system event described by msg.
     *
     * @param   msg The message.
     */
    virtual void HandleSystemEvent(const trManager::MessageBase& msg);

private:

    int mTickMsg = 0;

    int mEventTraversalEvent = 0;
    int mPostEventTraversalEvent = 0;
    int mPreFrameEvent = 0;
    int mCameraSynchEvent = 0;
    int mFrameSynchEvent = 0;
    int mFrameEvent = 0;
    int mPostFrameEvent = 0;

    int mEventTraversal = 0;
    int mPostEventTraversal = 0;
    int mCameraSynch = 0;
    int mFrameSynch = 0;
    int mFrame = 0;
    int mPostFrame = 0;

    int mTestMessage = 0;
};

