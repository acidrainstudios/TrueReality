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

#include "TestActorModule2.h"
#include "TestDirector.h"
#include "MessageTest.h"
#include "TestActor.h"

#include <trUtil/Console/TextColor.h>
#include <trCore/MessagePostEventTraversal.h>
#include <trCore/MessageEventTraversal.h>
#include <trCore/MessageSystemControl.h>
#include <trCore/MessageCameraSynch.h>
#include <trCore/MessageFrameSynch.h>
#include <trCore/MessagePostFrame.h>
#include <trCore/SystemControls.h>
#include <trCore/MessageFrame.h>
#include <trManager/MessageEntityRegistered.h>
#include <trManager/SystemManager.h>
#include <trManager/MessageTick.h>
#include <trManager/ActorBase.h>
#include <trManager/EntityBase.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Logging/Log.h>

#include <iomanip>
#include <vector>

const trUtil::RefStr TestDirector::CLASS_TYPE = trUtil::RefStr("TestDirector");

//////////////////////////////////////////////////////////////////////////
TestDirector::TestDirector(const std::string& name) : BaseClass(name)
{
}

//////////////////////////////////////////////////////////////////////////
TestDirector::~TestDirector()
{
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::OnMessage(const trManager::MessageBase& msg)
{
    if (msg.GetMessageType() == trCore::MessageEventTraversal::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
        std::cout << GetName() << ": Received Event Traversal Message " << std::endl;
    }
    else if (msg.GetMessageType() == trCore::MessagePostEventTraversal::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
        std::cout << GetName() << ": Received Event Post Traversal Message " << std::endl;
    }
    else if (msg.GetMessageType() == trCore::MessageCameraSynch::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
        std::cout << GetName() << ": Received Camera Synch Message " << std::endl;
    }
    else if (msg.GetMessageType() == trCore::MessageFrameSynch::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
        std::cout << GetName() << ": Received Frame Synch Message " << std::endl;
    }
    else if (msg.GetMessageType() == trCore::MessageFrame::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
        std::cout << GetName() << ": Received Frame Message " << std::endl;
    }
    else if (msg.GetMessageType() == trCore::MessagePostFrame::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_YELLOW);
        std::cout << GetName() << ": Received Post Frame Message " << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::OnTick(const trManager::MessageBase & msg)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
    std::cout << GetName() << ": Received Tick Message " << std::endl;

    //Cast the message into what it is, and pass it to a handler
    HandleTickMessage(msg);
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::OnAddedToSysMan()
{
    RegisterForMessage(trManager::MessageTick::MESSAGE_TYPE, ON_TICK_INVOKABLE);
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::HandleTickMessage(const trManager::MessageBase& msg)
{
    const trManager::MessageTick* msgPtr = static_cast<const trManager::MessageTick*>(&msg);

    //Set the print out to be 10 decimal places long
    std::cout << std::fixed;
    std::cout << std::setprecision(10);

    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
    std::cout << GetName() << ": Frame #" << msgPtr->GetFrameNumber() << std::endl;
    std::cout << GetName() << ": Sim Time: " << msgPtr->GetSimTime() << std::endl;
    std::cout << GetName() << ": Delta Sim Time: " << msgPtr->GetDeltaSimTime() << std::endl;
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
    std::cout << GetName() << ": TestActorModule2 Instances: ";
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_RED);
    std::cout << TestActorModule2::GetInstCount() << std::endl;

    if (msgPtr->GetFrameNumber() == MAX_FRAME_NUMBER)
    {
        trBase::SmrtPtr<trCore::MessageSystemControl> msg = new trCore::MessageSystemControl(&this->GetUUID(), trCore::SystemControls::SHUT_DOWN);
        SendMessage(*msg);
    }
    else if (msgPtr->GetFrameNumber() == NEW_ACTOR_MODULE_FRAME_NUMBER)
    {
        //Find all actors of the TestActor type
        std::vector<trManager::EntityBase*> actor = mSysMan->FindActorsByType(TestActor::CLASS_TYPE);

        //Check if we found an actor
        if (actor.size() > 0)
        {
            trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
            std::cout << GetName() << ": Adding TestActorModule2 to TestActor" << std::endl;

            //In this case we know we can only have one of TestActor types, so we use the first one and add a Module to it. 
            trManager::EntityBase* module = new TestActorModule2;
            mActorsModuleId = module->GetUUID();
            mSysMan->RegisterActor(*static_cast<trManager::ActorModuleBase*>(module));

            //We know the vector is filled with classes of TestActor::CLASS_TYPE, so we can directly cast it without a check. 
            static_cast<trManager::ActorBase*>(actor[0])->AddActorModule(*module);
        }
    }
    else if (msgPtr->GetFrameNumber() == KILL_ACTOR_MODULE_FRAME_NUMBER)
    {
        //Find all actors of the TestActor type
        std::vector<trManager::EntityBase*> actor = mSysMan->FindActorsByType(TestActor::CLASS_TYPE);

        //Check if we found an actor
        if (actor.size() > 0)
        {
            trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
            std::cout << GetName() << ": Removing TestActorModule2 from TestActor" << std::endl;

            //In this case we know we can only have one of TestActor types, so we use the first one and Remove a Module from it
            mSysMan->UnregisterActor(mActorsModuleId);

            //We know the vector is filled with classes of TestActor::CLASS_TYPE, so we can directly cast it without a check. 
            static_cast<trManager::ActorBase*>(actor[0])->RemoveActorModule(mActorsModuleId);
        }
    }

    //Send out a Test Message
    trBase::SmrtPtr<MessageTest> msgTst = new MessageTest(&this->GetUUID(), &mActorsModuleId);
    mSysMan->SendMessage(*msgTst);    
}