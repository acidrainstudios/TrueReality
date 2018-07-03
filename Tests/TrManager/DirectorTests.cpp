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

#include "TestDirector1.h"
#include "TestDirector2.h"

#include <gtest/gtest.h>

#include <trBase/SmrtPtr.h>
#include <trCore/MessageSystemControl.h>
#include <trCore/SystemControls.h>
#include <trCore/SystemDirector.h>
#include <trManager/DirectorPriority.h>
#include <trManager/SystemManager.h>

#include <iostream>

/**
 * @class	DirectorTests
 *
 * @brief	Sets up the unit test environment.
 */
class DirectorTests : public ::testing::Test
{
public:

    trBase::SmrtPtr<trManager::SystemManager> mSysMan;
    
    trBase::SmrtPtr<trCore::SystemDirector> mSysDirector;

    //////////////////////////////////////////////////////////////////////////
    DirectorTests()
    {
        //Create an instance of the System Manager
        mSysMan = &trManager::SystemManager::GetInstance();

        //Create and register the System Director
        mSysDirector = new trCore::SystemDirector();

        //We want the System Director to get and handle all messages before any other Director. 
        mSysMan->RegisterDirector(*mSysDirector, trManager::DirectorPriority::HIGHEST);

    }

    //////////////////////////////////////////////////////////////////////////
    ~DirectorTests()
    {
        //Create a System Control Shutdown message
        trBase::SmrtPtr<trCore::MessageSystemControl> msg = new trCore::MessageSystemControl(NULL, trCore::SystemControls::SHUT_DOWN);

        //Send message
        mSysMan->SendMessage(*msg);

        //Remove all Directors from the system
        mSysMan->UnregisterAllDirectors();

        //Advance System Manager one frame
        mSysDirector->RunOnce();
    }
};

/**
 * @fn  TEST_F(DirectorTest, AddRemoveDirector)
 *
 * @brief   Tests the adding and removal of directors
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(DirectorTests, AddRemoveDirector)
{
    //Make sure we have no instances of this director
    EXPECT_EQ(TestDirector2::GetInstCount(), 0);  

    //Add a Director to the system
    trBase::SmrtPtr<TestDirector2> director = new TestDirector2();
    mSysMan->RegisterDirector(*director, trManager::DirectorPriority::NORMAL);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //We should have one director in the system of this type
    EXPECT_EQ(TestDirector2::GetInstCount(), 1);

    //Unregister the director. 
    EXPECT_EQ(mSysMan->UnregisterDirector(*director.Release()), true);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //We should have no director2 in the system of this type
    EXPECT_EQ(TestDirector2::GetInstCount(), 0);
}

/**
 * @fn  TEST_F(DirectorTest, TimeScale)
 *
 * @brief   Tests the change of time scale. 
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(DirectorTests, TimeScale)
{
    //Check that the time is running at normal rate
    EXPECT_EQ(mSysDirector->GetTimeStructure().timeScale, 1.0);

    //Send a message to change time scale
    trBase::SmrtPtr<trCore::MessageSystemControl> msg = new trCore::MessageSystemControl(new trBase::UniqueId(), trCore::SystemControls::SET_TIME_SCALE, 20.69);
    mSysMan->SendMessage(*msg);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check that the time scale has changed 
    EXPECT_EQ(mSysDirector->GetTimeStructure().timeScale, 20.69);    

    //Send a message to change time scale
    msg = new trCore::MessageSystemControl(new trBase::UniqueId(), trCore::SystemControls::SET_TIME_SCALE, 1.0);
    mSysMan->SendMessage(*msg);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check that the time is running at normal rate
    EXPECT_EQ(mSysDirector->GetTimeStructure().timeScale, 1.0);
}

/**
 * @fn  TEST_F(DirectorTest, TickMessage)
 *
 * @brief   Tests reception of the Tick message
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(DirectorTests, TickMessage)
{
    //Add a Director to the system
    trBase::SmrtPtr<TestDirector1> director = new TestDirector1();
    EXPECT_EQ(mSysMan->RegisterDirector(*director, trManager::DirectorPriority::NORMAL), true);

    //Check for the number of tick messages
    EXPECT_EQ(director->GetTickMsgNumber(), 0);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check for the number of tick messages
    EXPECT_EQ(director->GetTickMsgNumber(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check for the number of tick messages
    EXPECT_EQ(director->GetTickMsgNumber(), 2);

    //Unregister the director. 
    EXPECT_EQ(mSysMan->UnregisterDirector(*director.Release()), true);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();
}

/**
 * @fn  TEST_F(DirectorTest, SystemEventMsg)
 *
 * @brief   Tests the System Event Message and its content. 
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(DirectorTests, SystemEventMsg)
{
    //Add a Director to the system
    trBase::SmrtPtr<TestDirector1> director = new TestDirector1();
    EXPECT_EQ(mSysMan->RegisterDirector(*director, trManager::DirectorPriority::NORMAL), true);

    //Check the number of frame events received. 
    EXPECT_EQ(director->GetEventTraversalEventMsgNum(), 0);
    EXPECT_EQ(director->GetPostEventTraversalEventMsgNum(), 0);
    EXPECT_EQ(director->GetPreFrameEventMsgNum(), 0);
    EXPECT_EQ(director->GetCameraSynchEventMsgNum(), 0);
    EXPECT_EQ(director->GetFrameSynchEventMsgNum(), 0);
    EXPECT_EQ(director->GetFrameEventMsgNum(), 0);
    EXPECT_EQ(director->GetPostFrameEventMsgNum(), 0);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check the number of frame events received. 
    EXPECT_EQ(director->GetEventTraversalEventMsgNum(), 1);
    EXPECT_EQ(director->GetPostEventTraversalEventMsgNum(), 1);
    EXPECT_EQ(director->GetPreFrameEventMsgNum(), 1);
    EXPECT_EQ(director->GetCameraSynchEventMsgNum(), 1);
    EXPECT_EQ(director->GetFrameSynchEventMsgNum(), 1);
    EXPECT_EQ(director->GetFrameEventMsgNum(), 1);
    EXPECT_EQ(director->GetPostFrameEventMsgNum(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();
    mSysDirector->RunOnce();

    //Check the number of frame events received. 
    EXPECT_EQ(director->GetEventTraversalEventMsgNum(), 3);
    EXPECT_EQ(director->GetPostEventTraversalEventMsgNum(), 3);
    EXPECT_EQ(director->GetPreFrameEventMsgNum(), 3);
    EXPECT_EQ(director->GetCameraSynchEventMsgNum(), 3);
    EXPECT_EQ(director->GetFrameSynchEventMsgNum(), 3);
    EXPECT_EQ(director->GetFrameEventMsgNum(), 3);
    EXPECT_EQ(director->GetPostFrameEventMsgNum(), 3);

    //Unregister the director. 
    EXPECT_EQ(mSysMan->UnregisterDirector(*director.Release()), true);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();
}

/**
 * @fn  TEST_F(DirectorTest, FrameEventMsg)
 *
 * @brief   Tests the individual messages of the main frame loop
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(DirectorTests, FrameEventMsg)
{
    //Add a Director to the system
    trBase::SmrtPtr<TestDirector1> director = new TestDirector1();
    EXPECT_EQ(mSysMan->RegisterDirector(*director, trManager::DirectorPriority::NORMAL), true);

    //Check the number of frame events received. 
    EXPECT_EQ(director->GetEventTraversalMsgNum(), 0);
    EXPECT_EQ(director->GetPostEventTraversalMsgNum(), 0);
    EXPECT_EQ(director->GetCameraSynchMsgNum(), 0);
    EXPECT_EQ(director->GetFrameSynchMsgNum(), 0);
    EXPECT_EQ(director->GetFrameMsgNum(), 0);
    EXPECT_EQ(director->GetPostFrameMsgNum(), 0);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check the number of frame events received. 
    EXPECT_EQ(director->GetEventTraversalMsgNum(), 1);
    EXPECT_EQ(director->GetPostEventTraversalMsgNum(), 1);
    EXPECT_EQ(director->GetCameraSynchMsgNum(), 1);
    EXPECT_EQ(director->GetFrameSynchMsgNum(), 1);
    EXPECT_EQ(director->GetFrameMsgNum(), 1);
    EXPECT_EQ(director->GetPostFrameMsgNum(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();
    mSysDirector->RunOnce();

    //Check the number of frame events received. 
    EXPECT_EQ(director->GetEventTraversalMsgNum(), 3);
    EXPECT_EQ(director->GetPostEventTraversalMsgNum(), 3);
    EXPECT_EQ(director->GetCameraSynchMsgNum(), 3);
    EXPECT_EQ(director->GetFrameSynchMsgNum(), 3);
    EXPECT_EQ(director->GetFrameMsgNum(), 3);
    EXPECT_EQ(director->GetPostFrameMsgNum(), 3);

    //Unregister the director. 
    EXPECT_EQ(mSysMan->UnregisterDirector(*director.Release()), true);

    //Advance System Manager one frame at a time  
    mSysDirector->RunOnce();
}

/**
 * @fn  TEST_F(DirectorTest, SendReceiveMsg)
 *
 * @brief   Test the sending and receiving of messages
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(DirectorTests, SendReceiveMsg)
{
    //Add a Directors to the system
    trBase::SmrtPtr<TestDirector1> director = new TestDirector1();
    EXPECT_EQ(mSysMan->RegisterDirector(*director, trManager::DirectorPriority::NORMAL), true);
    trBase::SmrtPtr<TestDirector2> director2 = new TestDirector2();
    EXPECT_EQ(mSysMan->RegisterDirector(*director2, trManager::DirectorPriority::NORMAL), true);

    //Should have not received any messages yet
    EXPECT_EQ(director->GetTestMessageNum(), 0);

    //Sends a test message
    EXPECT_EQ(director2->SendTestMessage(), true);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //We should have one director in the system of this type
    EXPECT_EQ(TestDirector2::GetInstCount(), 1);

    //Check how many messages we have
    EXPECT_EQ(director->GetTestMessageNum(), 1);

    //Sends a test message
    EXPECT_EQ(director2->SendTestMessage(), true);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check how many messages we have
    EXPECT_EQ(director->GetTestMessageNum(), 2);

    //Sends a test message
    EXPECT_EQ(director2->SendTestMessage(), true);
    EXPECT_EQ(director2->SendTestMessage(), true);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check how many messages we have
    EXPECT_EQ(director->GetTestMessageNum(), 4);

    //Unregister the director. 
    EXPECT_EQ(mSysMan->UnregisterDirector(*director2.Release()), true);
    EXPECT_EQ(mSysMan->UnregisterDirector(*director.Release()), true);

    //Advance System Manager one frame at a time  
    mSysDirector->RunOnce();

    //We should have no director2 in the system of this type
    EXPECT_EQ(TestDirector2::GetInstCount(), 0);
}