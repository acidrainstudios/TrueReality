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

#include "TestDirector2.h"

#include <trManager/MessageTick.h>
#include <trUtil/Console/TextColor.h>

const trUtil::RefStr TestDirector2::CLASS_TYPE = trUtil::RefStr("TestDirector2");

int TestDirector2::mInstCount = 0;

//////////////////////////////////////////////////////////////////////////
TestDirector2::TestDirector2(const std::string& name) : BaseClass(name)
{
    ++mInstCount;
}

//////////////////////////////////////////////////////////////////////////
TestDirector2::~TestDirector2()
{
    --mInstCount;
}

//////////////////////////////////////////////////////////////////////////
void TestDirector2::OnMessage(const trManager::MessageBase& /*msg*/)
{
}

//////////////////////////////////////////////////////////////////////////
void TestDirector2::OnTick(const trManager::MessageBase & msg)
{
    //Cast the message into what it is, and pass it to a handler
    HandleTickMessage(static_cast<const trManager::MessageTick&>(msg));
}

//////////////////////////////////////////////////////////////////////////
void TestDirector2::OnAddedToSysMan()
{
    RegisterForMessage(trManager::MessageTick::MESSAGE_TYPE, ON_TICK_INVOKABLE);
}

//////////////////////////////////////////////////////////////////////////
void TestDirector2::HandleTickMessage(const trManager::MessageBase& /*msg*/)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::WHITE);
    std::cout << GetName() << ": Got Tick Message" << std::endl;
}

//////////////////////////////////////////////////////////////////////////
int TestDirector2::GetInstCount()
{
    return mInstCount;
}

