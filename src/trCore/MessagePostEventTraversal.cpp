/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2021 Acid Rain Studios LLC
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

#include <trCore/MessagePostEventTraversal.h>

namespace trCore
{
    const trUtil::RefStr MessagePostEventTraversal::MESSAGE_TYPE("trCore::MessagePostEventTraversal");

    //////////////////////////////////////////////////////////////////////////
    MessagePostEventTraversal::MessagePostEventTraversal(const trBase::UniqueId* fromActorID, const trManager::TimingStructure& timeStruct)
        : BaseClass(fromActorID, timeStruct)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    MessagePostEventTraversal::~MessagePostEventTraversal()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& MessagePostEventTraversal::GetMessageType() const
    {
        return MESSAGE_TYPE;
    }
}
