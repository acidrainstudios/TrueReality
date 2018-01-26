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
* Author: Maxim Serebrennik
*/

#include <trBase/Base.h>

#include <trUtil/Logging/Log.h>

namespace trBase
{
    const trUtil::RefStr Base::CLASS_TYPE = trUtil::RefStr("trBase::Base");

    //////////////////////////////////////////////////////////////////////////
    Base::Base(const std::string name) : mName(name)
    {
        LOG_D("Creating class with the name: " + GetName())
    }

    //////////////////////////////////////////////////////////////////////////
    Base::~Base()
    {
        LOG_D("Destroying class with the name: " + GetName())
    }

    //////////////////////////////////////////////////////////////////////////
    void Base::SetName(const std::string& name)
    {
        mName = name;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& Base::GetName()
    {
        return mName;
    }

    //////////////////////////////////////////////////////////////////////////
    void Base::SetUUID(const trBase::UniqueId& id)
    {
        mId = id;
    }

    //////////////////////////////////////////////////////////////////////////
    const trBase::UniqueId& Base::GetUUID(void)
    {
        return mId;
    }
}
