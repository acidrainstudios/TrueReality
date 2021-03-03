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

#include "TestActor1.h"
#include "TestActor2.h"
#include "TestMessage.h"

#include <trUtil/Console/TextColor.h>
#include <trManager/MessageEntityUnregistered.h>
#include <trManager/MessageEntityRegistered.h>
#include <trManager/MessageTick.h>
#include <trManager/SystemManager.h>
#include <trManager/Invokable.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Functor.h>
#include <trUtil/Logging/Log.h>

//#include <iomanip>

const trUtil::RefStr TestActor1::CLASS_TYPE("TestActor1");

const trUtil::RefStr TestActor1::ON_ENTITY_REGISTERED_INVOKABLE("OnEntityRegistered");
const trUtil::RefStr TestActor1::ON_ENTITY_UNREGISTERED_INVOKABLE("OnEntityUnregistered");

int TestActor1::mInstCount = 0;

//////////////////////////////////////////////////////////////////////////
TestActor1::TestActor1(const std::string& name) : BaseClass(name)
, mActor2Id(new trBase::UniqueId(false))	//NULL the actor ID
{
    ++mInstCount;

    BuildInvokables();
}

//////////////////////////////////////////////////////////////////////////
TestActor1::~TestActor1()
{
    --mInstCount;
}

//////////////////////////////////////////////////////////////////////////
void TestActor1::BuildInvokables()
{
    AddInvokable(*new trManager::Invokable(TestActor1::ON_ENTITY_REGISTERED_INVOKABLE, trUtil::MakeFunctor(&TestActor1::OnEntityRegistered, this)));
    AddInvokable(*new trManager::Invokable(TestActor1::ON_ENTITY_UNREGISTERED_INVOKABLE, trUtil::MakeFunctor(&TestActor1::OnEntityUnregistered, this)));
}

//////////////////////////////////////////////////////////////////////////
void TestActor1::OnTick(const trManager::MessageBase& /*msg*/)
{
    ++mTickMsgCount;
}

//////////////////////////////////////////////////////////////////////////
void TestActor1::OnEntityRegistered(const trManager::MessageBase& msg)
{
    const trManager::MessageEntityRegistered* entMsg = static_cast<const trManager::MessageEntityRegistered*>(&msg);

    if (entMsg->GetEntityType() == TestActor2::CLASS_TYPE)
    {
        //Save the actors ID for later use
        mActor2Id = entMsg->GetAboutActorID();
    }
}

//////////////////////////////////////////////////////////////////////////
void TestActor1::OnEntityUnregistered(const trManager::MessageBase& msg)
{
    const trManager::MessageEntityRegistered* msgPtr = static_cast<const trManager::MessageEntityRegistered*>(&msg);

    if (msgPtr->GetEntityType() == TestActor2::CLASS_TYPE)
    {
        //NULL the ID
        mActor2Id = new trBase::UniqueId(false);
    }
}

//////////////////////////////////////////////////////////////////////////
void TestActor1::OnAddedToSysMan()
{
    BaseClass::OnAddedToSysMan();

    //Register for messages
    RegisterForMessage(trManager::MessageTick::MESSAGE_TYPE, ON_TICK_INVOKABLE);
    RegisterForMessage(trManager::MessageEntityRegistered::MESSAGE_TYPE, ON_ENTITY_REGISTERED_INVOKABLE);
    RegisterForMessage(trManager::MessageEntityUnregistered::MESSAGE_TYPE, ON_ENTITY_UNREGISTERED_INVOKABLE);
}

//////////////////////////////////////////////////////////////////////////
int TestActor1::GetInstCount()
{
    return mInstCount;
}

//////////////////////////////////////////////////////////////////////////
bool TestActor1::SendTestMessage()
{
    if (!mActor2Id.IsNull())
    {
        return SendMessage(*new TestMessage(&GetUUID(), &mActor2Id));
    }
    else
    {
        return false;
    }
}

//////////////////////////////////////////////////////////////////////////
int TestActor1::GetTickMsgNum()
{
    return mTickMsgCount;
}
