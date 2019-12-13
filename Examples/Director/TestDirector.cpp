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

#include "TestDirector.h"
#include "TestDirector2.h"

#include <trCore/MessagePostEventTraversal.h>
#include <trCore/MessageEventTraversal.h>
#include <trCore/MessageSystemControl.h>
#include <trCore/MessageSystemEvent.h>
#include <trCore/MessageCameraSynch.h>
#include <trCore/MessageFrameSynch.h>
#include <trCore/MessagePostFrame.h>
#include <trCore/SystemControls.h>
#include <trCore/MessageFrame.h>
#include <trManager/SystemManager.h>
#include <trManager/MessageTick.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/Logging/Log.h>

#include <iomanip>

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
    else if (msg.GetMessageType() == trCore::MessageSystemEvent::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << GetName() << ": Received System Event Message: ";

        HandleSystemEvent(msg);
    }
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::OnTick(const trManager::MessageBase& msg)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
    std::cout << GetName() << ": Received Tick Message " << std::endl;

    HandleTickMessage(msg);
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::OnAddedToSysMan()
{
    RegisterForMessage(trManager::MessageTick::MESSAGE_TYPE, ON_TICK_INVOKABLE);
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::HandleSystemEvent(const trManager::MessageBase& msg)
{
    //Cast the message into its real type
    const trCore::MessageSystemEvent* msgPtr = static_cast<const trCore::MessageSystemEvent*>(&msg);

    if (msgPtr->GetSysEventType() == trCore::SystemEvents::EVENT_TRAVERSAL)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::EVENT_TRAVERSAL << std::endl;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::POST_EVENT_TRAVERSAL)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::POST_EVENT_TRAVERSAL << std::endl;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::PRE_FRAME)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::PRE_FRAME << std::endl;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::CAMERA_SYNCH)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::CAMERA_SYNCH << std::endl;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::FRAME_SYNCH)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::FRAME_SYNCH << std::endl;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::FRAME)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::FRAME << std::endl;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::POST_FRAME)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::POST_FRAME << std::endl;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::SHUTTING_DOWN)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_RED);
        std::cout << "Event Type " << trCore::SystemEvents::SHUTTING_DOWN << std::endl;
    }  
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::TIME_SCALE_CHANGED)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_BLUE);
        std::cout << "Event Type " << trCore::SystemEvents::TIME_SCALE_CHANGED << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////
void TestDirector::HandleTickMessage(const trManager::MessageBase& msg)
{
    //Cast the message into its real type
    const trManager::MessageTick* msgPtr = static_cast<const trManager::MessageTick*>(&msg);


    //Set the print out to be 10 decimal places long
    std::cout << std::fixed;
    std::cout << std::setprecision(10);

    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
    std::cout << GetName() << ": Frame #" << msgPtr->GetFrameNumber() << std::endl;
    std::cout << GetName() << ": Time Scale: " << msgPtr->GetTimeScale() << std::endl;
    std::cout << GetName() << ": Sim Time: " << msgPtr->GetSimTime() << std::endl;
    std::cout << GetName() << ": Delta Sim Time: " << msgPtr->GetDeltaSimTime() << std::endl;
    std::cout << GetName() << ": Real Time: " << msgPtr->GetRealTime() << std::endl;
    std::cout << GetName() << ": Delta Real Time: " << msgPtr->GetDeltaRealTime() << std::endl;

    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::WHITE);
    std::cout << GetName() << ": TestDirector2 Instances: ";
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_RED);
    std::cout << TestDirector2::GetInstCount() << std::endl;

    if (msgPtr->GetFrameNumber() == MAX_FRAME_NUMBER)
    {
        trBase::SmrtPtr<trCore::MessageSystemControl> msg = new trCore::MessageSystemControl(&this->GetUUID(), trCore::SystemControls::SHUT_DOWN);
        SendMessage(*msg);
    }
    else if (msgPtr->GetFrameNumber() == SPEED_FRAME_NUMBER)
    {
        trBase::SmrtPtr<trCore::MessageSystemControl> msg = new trCore::MessageSystemControl(&this->GetUUID(), trCore::SystemControls::SET_TIME_SCALE, 20.69);
        SendMessage(*msg);
    }
}