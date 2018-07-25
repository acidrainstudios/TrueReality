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

#include "TestActor2.h"
#include "TestActor1.h"
#include "MessageTest.h"

#include <trUtil/Console/TextColor.h>
#include <trManager/SystemManager.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Logging/Log.h>

#include <iomanip>

const trUtil::RefStr TestActor2::CLASS_TYPE("TestActor2");

const trUtil::RefStr TestActor2::ON_TEST_INVOKABLE("OnTest");

int TestActor2::mInstCount = 0;

//////////////////////////////////////////////////////////////////////////
TestActor2::TestActor2(const std::string name) : BaseClass(name)
{
    BuildInvokables();
    ++mInstCount;
}

//////////////////////////////////////////////////////////////////////////
TestActor2::~TestActor2()
{
    --mInstCount;
}

//////////////////////////////////////////////////////////////////////////
void TestActor2::BuildInvokables()
{
    AddInvokable(*new trManager::Invokable(TestActor2::ON_TEST_INVOKABLE, trUtil::MakeFunctor(&TestActor2::OnTest, this)));
}

//////////////////////////////////////////////////////////////////////////
void TestActor2::OnTick(const trManager::MessageBase& msg)
{}

//////////////////////////////////////////////////////////////////////////
void TestActor2::OnTest(const trManager::MessageBase & msg)
{
    ++mTestMsgCount;
}

//////////////////////////////////////////////////////////////////////////
void TestActor2::OnAddedToSysMan()
{
    RegisterForMessage(MessageTest::MESSAGE_TYPE, ON_TEST_INVOKABLE);
}

//////////////////////////////////////////////////////////////////////////
int TestActor2::GetInstCount()
{
    return mInstCount;
}

//////////////////////////////////////////////////////////////////////////
int TestActor2::GetTestMsgCount()
{
    return mTestMsgCount;
}
