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

#include <trCore/MessageSystemEvent.h>

#include <trUtil/RefStr.h>

namespace trCore
{
    const trUtil::RefStr MessageSystemEvent::MESSAGE_TYPE("trCore::MessageSystemEvent");

    //////////////////////////////////////////////////////////////////////////
    MessageSystemEvent::MessageSystemEvent(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID, const trCore::SystemEvents &systemEvent)
        : BaseClass(fromActorID, aboutActorID)
    {
        mSystemEvent = &systemEvent;
    }

    //////////////////////////////////////////////////////////////////////////
    MessageSystemEvent::~MessageSystemEvent()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& MessageSystemEvent::GetMessageType() const
    {
        return MESSAGE_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    const trCore::SystemEvents& MessageSystemEvent::GetSysEventType() const
    {
        return *mSystemEvent;
    }
}

