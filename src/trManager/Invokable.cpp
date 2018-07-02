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
* @author: David Guthrie
* @author: Maxim Serebrennik
*/


#include <trManager/Invokable.h>


namespace trManager
{
    const trUtil::RefStr InvokableFunctorCallerBase::CLASS_TYPE = trUtil::RefStr("trManager::InvokableFunctorCallerBase");
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    
    const trUtil::RefStr Invokable::CLASS_TYPE = trUtil::RefStr("trManager::Invokable");

    //////////////////////////////////////////////////////////////////////////
    Invokable::~Invokable()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void Invokable::Invoke(const trManager::MessageBase& message)
    {
        mCaller->Call(message);
    }
}
