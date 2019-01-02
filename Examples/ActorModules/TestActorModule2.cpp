/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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
#include "MessageTest.h"


#include <trUtil/Console/TextColor.h>
#include <trUtil/Functor.h>
#include <trManager/SystemManager.h>
#include <trManager/Invokable.h>
#include <trBase/SmrtPtr.h>

const trUtil::RefStr TestActorModule2::CLASS_TYPE("TestActorModule2");
int TestActorModule2::mInstCount = 0;

//////////////////////////////////////////////////////////////////////////
TestActorModule2::TestActorModule2(const std::string& name) : BaseClass(name)
{
    ++mInstCount;
    BuildInvokables();
}

//////////////////////////////////////////////////////////////////////////
TestActorModule2::~TestActorModule2()
{
    --mInstCount;
}

//////////////////////////////////////////////////////////////////////////
void TestActorModule2::BuildInvokables()
{
    AddInvokable(*new trManager::Invokable(TestActorModule2::ON_MESSAGE_INVOKABLE, trUtil::MakeFunctor(&TestActorModule2::OnMessage, this)));
}

//////////////////////////////////////////////////////////////////////////
void TestActorModule2::OnTick(const trManager::MessageBase& msg)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
    std::cout << GetName() << ": Received Tick Message " << std::endl;
}

//////////////////////////////////////////////////////////////////////////
void TestActorModule2::OnMessage(const trManager::MessageBase& msg)
{
    if (msg.GetMessageType() == MessageTest::MESSAGE_TYPE)
    {
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
        std::cout << GetName() << ": Received MessageTest " << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////
void TestActorModule2::OnAddedToSysMan()
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
    std::cout << GetName() << ": Registering for MessageTest Message " << std::endl;
    RegisterForMessage(MessageTest::MESSAGE_TYPE, TestActorModule2::ON_MESSAGE_INVOKABLE);
}

//////////////////////////////////////////////////////////////////////////
int TestActorModule2::GetInstCount()
{
    return mInstCount;
}