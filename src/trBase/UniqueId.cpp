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

#include <trBase/UniqueId.h>

#include <trUtil/PlatformMacros.h>
#include <trUtil/Logging/Log.h>

#include <bID/uuid/random_generator.hpp>
#include <bID/uuid/string_generator.hpp>
#include <bID/uuid/nil_generator.hpp>
#include <bID/uuid/uuid_io.hpp>

#include <iostream>

namespace trBase
{
    const trUtil::RefStr UniqueId::CLASS_TYPE = trUtil::RefStr("trBase::UniqueId");

    UniqueId::UniqueId(bool createNewId)
    {
        if (createNewId)
        {
            //Create a random GUID
            mGUID = bID::uuids::random_generator()();

        }
        else
        {
            //Create a NULL GUID
            mGUID = bID::uuids::nil_uuid();
        }
    }

    ////////////////////////////////////////////////
    UniqueId::UniqueId(const UniqueId& toCopy)
    {
        mGUID = toCopy.mGUID;
    }

    ////////////////////////////////////////////////
    UniqueId::UniqueId(const std::string& toCopy)
    {
        mGUID = bID::uuids::string_generator()(toCopy);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& UniqueId::GetType() const
    {
        return CLASS_TYPE;
    }

    ////////////////////////////////////////////////
    const std::string UniqueId::ToString() const
    {
        return bID::uuids::to_string(mGUID);
    }

    ////////////////////////////////////////////////
    void UniqueId::FromString(std::string& idString)
    {
        mGUID = bID::uuids::string_generator()(idString);
    }

    ////////////////////////////////////////////////
    bool UniqueId::IsNull() const
    {
        return mGUID.is_nil();
    }

    ////////////////////////////////////////////////
    UniqueId& UniqueId::operator=(const UniqueId& id)
    {
        if (this == &id)
        {
            return *this;
        }

        mGUID = id.mGUID;
        return *this;
    }

    ////////////////////////////////////////////////
    UniqueId& UniqueId::operator=(const UniqueId* id)
    {
        if (this == id)
        {
            return *this;
        }

        mGUID = id->mGUID;
        return *this;
    }

    ////////////////////////////////////////////////
    UniqueId& UniqueId::operator=(const std::string& id)
    {
        mGUID = bID::uuids::string_generator()(id);
        return *this;
    }

    ////////////////////////////////////////////////
    std::ostream& operator << (std::ostream& o, const UniqueId& id)
    {
        o << id.ToString();
        return o;
    }

    ////////////////////////////////////////////////
    std::istream& operator >> (std::istream& i, UniqueId& id)
    {
        std::string value;
        i >> value;
        id = value;
        return i;
    }    
}