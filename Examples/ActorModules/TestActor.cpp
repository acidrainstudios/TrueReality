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
* @author: Maxim Serebrennik
*/

#include "TestActor.h"
#include "TestActorModule1.h"

#include <trManager/MessageTick.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/Logging/Log.h>

const trUtil::RefStr TestActor::CLASS_TYPE("TestActor");

//////////////////////////////////////////////////////////////////////////
TestActor::TestActor(const std::string name) : BaseClass(name)
{
    //Add a new Actor Module to the Actor
    AddActorModule(*new TestActorModule1());

    BuildInvokables();
}

//////////////////////////////////////////////////////////////////////////
TestActor::~TestActor()
{
}

//////////////////////////////////////////////////////////////////////////
void TestActor::BuildInvokables()
{
}

//////////////////////////////////////////////////////////////////////////
void TestActor::OnTick(const trManager::MessageBase& msg)
{
    //Send the tick message to all actor Modules. 
    ActorModuleTick(msg);
}

//////////////////////////////////////////////////////////////////////////
void TestActor::OnAddedToSysMan()
{
    BaseClass::OnAddedToSysMan();

    //Register for messages
    RegisterForMessage(trManager::MessageTick::MESSAGE_TYPE, ON_TICK_INVOKABLE);
}