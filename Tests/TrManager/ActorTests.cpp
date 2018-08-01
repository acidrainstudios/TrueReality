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

#include "ActorTests.h"

#include "TestActor1.h"
#include "TestActor2.h"
#include "TestActor3.h"
#include "MessageTest.h"

#include <trCore/MessageSystemControl.h>
#include <trCore/SystemControls.h>
#include <trManager/DirectorPriority.h>

#include <iostream>


//////////////////////////////////////////////////////////////////////////
ActorTests::ActorTests()
{
    //Create an instance of the System Manager
    mSysMan = &trManager::SystemManager::GetInstance();

    //Create and register the System Director
    mSysDirector = new trCore::SystemDirector();

    //We want the System Director to get and handle all messages before any other Director. 
    mSysMan->RegisterDirector(*mSysDirector, trManager::DirectorPriority::HIGHEST);

}

//////////////////////////////////////////////////////////////////////////
ActorTests::~ActorTests()
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

/**
 * @fn    TEST_F(ActorTests, AddRemoveActors)
 *
 * @brief    Tests the adding and removal of directors.
 *
 * @param    parameter1    The first parameter.
 * @param    parameter2    The second parameter.
 */
TEST_F(ActorTests, AddRemoveActor)
{
    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor1::GetInstCount(), 0);

    //Add TestActor1 to the system
    trBase::SmrtPtr<TestActor1> actor = new TestActor1();
    EXPECT_EQ(mSysMan->RegisterActor(*actor), true);

    //We should have one instance of the actor
    EXPECT_EQ(TestActor1::GetInstCount(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //We should have one instance of the actor
    EXPECT_EQ(TestActor1::GetInstCount(), 1);

    EXPECT_EQ(mSysMan->UnregisterActor(actor->GetUUID()), true);

    //Release ownership of this pointer
    actor.Release();

    //We should have one instance of the actor
    EXPECT_EQ(TestActor1::GetInstCount(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor1::GetInstCount(), 0);
}

/**
 * @fn    TEST_F(ActorTests, SendMessage)
 *
 * @brief    Tests the sending of messages between actors. 
 *
 * @param    parameter1    The first parameter.
 * @param    parameter2    The second parameter.
 */
TEST_F(ActorTests, SendMessage)
{
    //Add TestActor1 to the system
    trBase::SmrtPtr<TestActor1> actor = new TestActor1();
    EXPECT_EQ(mSysMan->RegisterActor(*actor), true);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor2::GetInstCount(), 0);

    //Add TestActor2 to the system
    trBase::SmrtPtr<TestActor2> actor2 = new TestActor2();
    EXPECT_EQ(mSysMan->RegisterActor(*actor2), true);

    //Make sure we have one instance of the actor
    EXPECT_EQ(TestActor2::GetInstCount(), 1);
    
    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check if Actor1 has received two ticks by now
    EXPECT_EQ(actor->GetTickMsgNum(), 2);

    //No instances of the message should exist in the system yet
    EXPECT_EQ(MessageTest::GetInstCount(), 0);

    //Send a test message
    EXPECT_EQ(actor->SendTestMessage(), true);

    //We should have one message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 1);

    //Check that we have no messages yet
    EXPECT_EQ(actor2->GetTestMsgCount(), 0);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check that we have one message
    EXPECT_EQ(actor2->GetTestMsgCount(), 1);

    //We should have no message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 0);

    //Send a test message
    EXPECT_EQ(actor->SendTestMessage(), true);

    //We should have one message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();
    EXPECT_EQ(actor->SendTestMessage(), true);
    mSysDirector->RunOnce();
    EXPECT_EQ(actor->SendTestMessage(), true);
    mSysDirector->RunOnce();
    EXPECT_EQ(actor->SendTestMessage(), true);
    mSysDirector->RunOnce();

    //Check that we have one message
    EXPECT_EQ(actor2->GetTestMsgCount(), 5);

    //We should have no message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 0);

    EXPECT_EQ(mSysMan->UnregisterActor(actor2->GetUUID()), true);
    EXPECT_EQ(mSysMan->UnregisterActor(actor->GetUUID()), true);

    //Release ownership of this pointer
    actor2.Release();
    actor.Release();

    //We should have one instance of the actor
    EXPECT_EQ(TestActor2::GetInstCount(), 1);
    EXPECT_EQ(TestActor1::GetInstCount(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor2::GetInstCount(), 0);
    EXPECT_EQ(TestActor1::GetInstCount(), 0);
}

TEST_F(ActorTests, Listener)
{
    //Add TestActor1 to the system
    trBase::SmrtPtr<TestActor1> actor = new TestActor1();
    EXPECT_EQ(mSysMan->RegisterActor(*actor), true);
    
    //Add TestActor2 to the system
    trBase::SmrtPtr<TestActor2> actor2 = new TestActor2();
    EXPECT_EQ(mSysMan->RegisterActor(*actor2), true);
    
    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor3::GetInstCount(), 0);

    //Add TestActor3 to the system
    trBase::SmrtPtr<TestActor3> actor3 = new TestActor3();
    EXPECT_EQ(mSysMan->RegisterActor(*actor3), true);

    //Make the actor3 listen to messages about actor2
    mSysMan->RegisterForMessagesAboutEntity(*actor3, actor2->GetUUID(), TestActor3::ON_TEST_ACTOR_2_INVOKABLE);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor3::GetInstCount(), 1);

    //No instances of the message should exist in the system yet
    EXPECT_EQ(MessageTest::GetInstCount(), 0);

    //Send a test message
    EXPECT_EQ(actor->SendTestMessage(), true);

    //We should have one message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 1);

    //Check that we have no messages yet
    EXPECT_EQ(actor3->GetTestMsgCount(), 0);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Check that we have one message
    EXPECT_EQ(actor3->GetTestMsgCount(), 1);

    //We should have no message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 0);

    //Send a test message
    EXPECT_EQ(actor->SendTestMessage(), true);

    //We should have one message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();
    EXPECT_EQ(actor->SendTestMessage(), true);
    mSysDirector->RunOnce();
    EXPECT_EQ(actor->SendTestMessage(), true);
    mSysDirector->RunOnce();
    EXPECT_EQ(actor->SendTestMessage(), true);
    mSysDirector->RunOnce();

    //Check that we have one message
    EXPECT_EQ(actor3->GetTestMsgCount(), 5);

    //We should have no message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 0);

    //Unregister the actor
    EXPECT_EQ(mSysMan->UnregisterActor(actor3->GetUUID()), true);

    //Release ownership of this pointer
    actor3.Release();

    //We should have one instance of the actor
    EXPECT_EQ(TestActor3::GetInstCount(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor3::GetInstCount(), 0);

    //Unregister the rest of the actors
    EXPECT_EQ(mSysMan->UnregisterActor(actor2->GetUUID()), true);
    EXPECT_EQ(mSysMan->UnregisterActor(actor->GetUUID()), true);

    //Release ownership of this pointer
    actor2.Release();
    actor.Release();

    //We should have one instance of the actor
    EXPECT_EQ(TestActor2::GetInstCount(), 1);
    EXPECT_EQ(TestActor1::GetInstCount(), 1);

    //Advance System Manager one frame at a time
    mSysDirector->RunOnce();

    //Make sure we dont have any instances of the actor
    EXPECT_EQ(TestActor2::GetInstCount(), 0);
    EXPECT_EQ(TestActor1::GetInstCount(), 0);

    //We should have no message in the system
    EXPECT_EQ(MessageTest::GetInstCount(), 0);
}