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

#include <trManager/MessageEntityUnregistered.h>

namespace trManager
{
    const trUtil::RefStr MessageEntityUnregistered::MESSAGE_TYPE("trManager::MessageEntityUnregistered");

    //////////////////////////////////////////////////////////////////////////
    MessageEntityUnregistered::MessageEntityUnregistered(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID, const std::string* entityType, const std::string* entityName)
        : BaseClass(fromActorID, aboutActorID)
    {
        mEntityTypePtr = entityType;
        mEntityNamePtr = entityName;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& MessageEntityUnregistered::GetEntityType() const
    {
        return *mEntityTypePtr;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& MessageEntityUnregistered::GetEntityName() const
    {
        return *mEntityNamePtr;
    }

    //////////////////////////////////////////////////////////////////////////
    MessageEntityUnregistered::~MessageEntityUnregistered()
    {

    }
    
    //////////////////////////////////////////////////////////////////////////
    const std::string& MessageEntityUnregistered::GetMessageType() const
    {
        return MESSAGE_TYPE;
    }
}
