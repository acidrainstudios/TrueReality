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

#include "TestActorModule1.h"

#include <trUtil/Console/TextColor.h>
#include <trManager/SystemManager.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/RefStr.h>
#include <trUtil/Logging/Log.h>

#include <iomanip>

const trUtil::RefStr TestActorModule1::CLASS_TYPE("TestActorModule1");

//////////////////////////////////////////////////////////////////////////
TestActorModule1::TestActorModule1(const std::string& name) : BaseClass(name)
{
    BuildInvokables();
}

//////////////////////////////////////////////////////////////////////////
TestActorModule1::~TestActorModule1()
{
}

//////////////////////////////////////////////////////////////////////////
void TestActorModule1::BuildInvokables()
{
}

//////////////////////////////////////////////////////////////////////////
void TestActorModule1::OnTick(const trManager::MessageBase & /*msg*/)
{
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_CYAN);
    std::cout << GetName() << ": Received Tick Message " << std::endl;
}

//////////////////////////////////////////////////////////////////////////
void TestActorModule1::OnAddedToSysMan()
{
}