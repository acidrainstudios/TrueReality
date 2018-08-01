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
#include "MessageTest.h"

#include <trCore/MessagePostEventTraversal.h>
#include <trCore/MessageEventTraversal.h>
#include <trCore/MessageSystemControl.h>
#include <trCore/MessageSystemEvent.h>
#include <trCore/MessageCameraSynch.h>
#include <trCore/MessageFrameSynch.h>
#include <trCore/MessagePostFrame.h>
#include <trCore/SystemControls.h>
#include <trCore/MessageFrame.h>
#include <trManager/Invokable.h>
#include <trManager/MessageTick.h>
#include <trManager/SystemManager.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/Functor.h>
#include <trUtil/Logging/Log.h>

#include <iomanip>

const trUtil::RefStr TestDirector1::CLASS_TYPE("TestDirector1");

const trUtil::RefStr TestDirector1::ON_TEST_MESSAGE_INVOKABLE = trUtil::RefStr("OnTestMessageInvokable");

//////////////////////////////////////////////////////////////////////////
TestDirector1::TestDirector1(const std::string& name) : BaseClass(name)
{
    BuildInvokables();
}

//////////////////////////////////////////////////////////////////////////
TestDirector1::~TestDirector1()
{
}

//////////////////////////////////////////////////////////////////////////
void TestDirector1::BuildInvokables()
{
    AddInvokable(*new trManager::Invokable(TestDirector1::ON_TEST_MESSAGE_INVOKABLE, trUtil::MakeFunctor(&TestDirector1::OnTestMessage, this)));
}

//////////////////////////////////////////////////////////////////////////
void TestDirector1::OnMessage(const trManager::MessageBase& msg)
{
    if (msg.GetMessageType() == trCore::MessageEventTraversal::MESSAGE_TYPE)
    {
        ++mEventTraversal;
    }
    else if (msg.GetMessageType() == trCore::MessagePostEventTraversal::MESSAGE_TYPE)
    {
        ++mPostEventTraversal;
    }
    else if (msg.GetMessageType() == trCore::MessageCameraSynch::MESSAGE_TYPE)
    {
        ++mCameraSynch;
    }
    else if (msg.GetMessageType() == trCore::MessageFrameSynch::MESSAGE_TYPE)
    {
        ++mFrameSynch;
    }
    else if (msg.GetMessageType() == trCore::MessageFrame::MESSAGE_TYPE)
    {
        ++mFrame;
    }
    else if (msg.GetMessageType() == trCore::MessagePostFrame::MESSAGE_TYPE)
    {
        ++mPostFrame;
    }
    else if (msg.GetMessageType() == trCore::MessageSystemEvent::MESSAGE_TYPE)
    {
        HandleSystemEvent(msg);
    }
}

//////////////////////////////////////////////////////////////////////////
void TestDirector1::OnTick(const trManager::MessageBase &msg)
{
    ++mTickMsg;
}

//////////////////////////////////////////////////////////////////////////
void TestDirector1::OnAddedToSysMan()
{
    RegisterForMessage(trManager::MessageTick::MESSAGE_TYPE, ON_TICK_INVOKABLE);
    RegisterForMessage(TestMessage::MESSAGE_TYPE, ON_TEST_MESSAGE_INVOKABLE);
}

//////////////////////////////////////////////////////////////////////////
void TestDirector1::OnTestMessage(const trManager::MessageBase &msg)
{
    ++mTestMessage;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetTestMessageNum()
{
    return mTestMessage;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetTickMsgNumber()
{
    return mTickMsg;
}

//////////////////////////////////////////////////////////////////////////
void TestDirector1::HandleSystemEvent(const trManager::MessageBase& msg)
{
    //Cast the message into its real type
    const trCore::MessageSystemEvent* msgPtr = static_cast<const trCore::MessageSystemEvent*>(&msg);

    if (msgPtr->GetSysEventType() == trCore::SystemEvents::EVENT_TRAVERSAL)
    {
        ++mEventTraversalEvent;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::POST_EVENT_TRAVERSAL)
    {
        ++mPostEventTraversalEvent;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::PRE_FRAME)
    {
        ++mPreFrameEvent;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::CAMERA_SYNCH)
    {
        ++mCameraSynchEvent;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::FRAME_SYNCH)
    {
        ++mFrameSynchEvent;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::FRAME)
    {
        ++mFrameEvent;
    }
    else if (msgPtr->GetSysEventType() == trCore::SystemEvents::POST_FRAME)
    {
        ++mPostFrameEvent;
    }  
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetEventTraversalEventMsgNum()
{
    return mEventTraversalEvent;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetPostEventTraversalEventMsgNum()
{
    return mPostEventTraversalEvent;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetPreFrameEventMsgNum()
{
    return mPreFrameEvent;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetCameraSynchEventMsgNum()
{
    return mCameraSynchEvent;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetFrameSynchEventMsgNum()
{
    return mFrameSynchEvent;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetFrameEventMsgNum()
{
    return mFrameEvent;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetPostFrameEventMsgNum()
{
    return mPostFrameEvent;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetEventTraversalMsgNum()
{
    return mEventTraversal;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetPostEventTraversalMsgNum()
{
    return mPostEventTraversal;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetCameraSynchMsgNum()
{
    return mCameraSynch;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetFrameSynchMsgNum()
{
    return mFrameSynch;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetFrameMsgNum()
{
    return mFrame;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector1::GetPostFrameMsgNum()
{
    return mPostFrame;
}