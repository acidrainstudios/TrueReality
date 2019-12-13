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
#include <trApp/AppBase.h>

#include <trCore/MessageSystemControl.h>
#include <trCore/SystemControls.h>

namespace trApp
{
    const trUtil::RefStr AppBase::CLASS_TYPE = trUtil::RefStr("trApp::AppBase");

    //////////////////////////////////////////////////////////////////////////
    AppBase::AppBase(const std::string& name) : BaseClass(name)
    {
        //Create an instance of the System Manager
        mSysMan = &trManager::SystemManager::GetInstance();

        //Create and register the System Director
        mSysDirector = new trCore::SystemDirector();

        //We want the System Director to get and handle all messages before any other Director. 
        mSysMan->RegisterDirector(*mSysDirector, trManager::DirectorPriority::HIGHEST);
    }

    //////////////////////////////////////////////////////////////////////////
    AppBase::~AppBase()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& AppBase::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    void AppBase::Run()
    {
        mSysDirector->Run();
    }

    //////////////////////////////////////////////////////////////////////////
    void AppBase::Quit()
    {
        //Create a System Control Shutdown message
        trBase::SmrtPtr<trCore::MessageSystemControl> msg = new trCore::MessageSystemControl(NULL, trCore::SystemControls::SHUT_DOWN);

        //Send message
        mSysMan->SendMessage(*msg);
    }
}
