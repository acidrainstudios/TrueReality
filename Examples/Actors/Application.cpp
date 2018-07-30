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

#include "Application.h"
#include "TestActor1.h"
#include "TestDirector.h"

#include <trUtil/Console/TextColor.h>
#include <trManager/SystemManager.h>

const trUtil::RefStr Application::CLASS_TYPE = trUtil::RefStr("Application");

//////////////////////////////////////////////////////////////////////////
Application::Application(const std::string& name) : BaseClass(name)
{
    //Create Test Actor 1
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
    std::cerr << "Creating Test Actor 1. " << std::endl;
    mSysMan->RegisterActor(*new TestActor1()); 

    //Create Test Director
    trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_GREEN);
    std::cerr << "Creating a Test Director. " << std::endl;
    mSysMan->RegisterDirector(*new TestDirector(), trManager::DirectorPriority::NORMAL);
}

//////////////////////////////////////////////////////////////////////////
const std::string& Application::GetType() const
{
    return CLASS_TYPE;
}

//////////////////////////////////////////////////////////////////////////
Application::~Application()
{
}
