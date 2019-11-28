/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
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

#include "TestActor3.h"
#include "TestActor2.h"
#include "MessageTest.h"

#include <trUtil/Console/TextColor.h>
#include <trManager/SystemManager.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Logging/Log.h>

#include <iomanip>

const trUtil::RefStr TestActor3::CLASS_TYPE("TestActor3");

const trUtil::RefStr TestActor3::ON_TEST_ACTOR_2_INVOKABLE("OnTestActor2");

int TestActor3::mInstCount = 0;

//////////////////////////////////////////////////////////////////////////
TestActor3::TestActor3(const std::string& name) : BaseClass(name)
{
    ++mInstCount;
    BuildInvokables();
}

//////////////////////////////////////////////////////////////////////////
TestActor3::~TestActor3()
{
    --mInstCount;
}

//////////////////////////////////////////////////////////////////////////
void TestActor3::BuildInvokables()
{
    AddInvokable(*new trManager::Invokable(TestActor3::ON_TEST_ACTOR_2_INVOKABLE, trUtil::MakeFunctor(&TestActor3::AboutTestActor2, this)));
}

//////////////////////////////////////////////////////////////////////////
void TestActor3::OnTick(const trManager::MessageBase& /*msg*/)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
    std::cout << GetName() << ": Received Tick Message " << std::endl;
}

//////////////////////////////////////////////////////////////////////////
void TestActor3::AboutTestActor2(const trManager::MessageBase& msg)
{
    std::cout << GetName() << ": Received Message Type " << msg.GetMessageType() << " about TestActor2"<< std::endl;
}

//////////////////////////////////////////////////////////////////////////
void TestActor3::OnAddedToSysMan()
{
    //Register for Tick Message
    RegisterForMessage(trManager::MessageTick::MESSAGE_TYPE, ON_TICK_INVOKABLE);  
}

//////////////////////////////////////////////////////////////////////////
int TestActor3::GetInstCount()
{
    return mInstCount;
}