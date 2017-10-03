/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
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
* Author: Matthew W. Campbell
* Author: David Guthrie
* Author: Maxim Serebrennik
*/
#include <trUtil/EnumerationString.h>

namespace trUtil
{
    //////////////////////////////////////////////////////
    bool EnumerationString::operator==(const std::string& rhs) const
    {
        return Compare(rhs) == 0;
    }

    //////////////////////////////////////////////////////
    bool EnumerationString::operator!=(const std::string& rhs) const
    {
        return Compare(rhs) != 0;
    }

    //////////////////////////////////////////////////////
    bool EnumerationString::operator<(const std::string& rhs) const
    {
        return Compare(rhs) < 0;
    }

    //////////////////////////////////////////////////////
    bool EnumerationString::operator>(const std::string& rhs) const
    {
        return Compare(rhs) > 0;
    }

    //////////////////////////////////////////////////////
    int EnumerationString::Compare(const std::string& nameString) const
    {
        return mName.compare(nameString);
    }

    //////////////////////////////////////////////////////
    EnumerationString::~EnumerationString()
    {
    }

    //////////////////////////////////////////////////////
    EnumerationString::EnumerationString(const std::string& name)
    : mName(name)
    {
    }

    //////////////////////////////////////////////////////
    EnumerationString& EnumerationString::operator=(const EnumerationString&)
    {
        return *this;
    }

    //////////////////////////////////////////////////////
    EnumerationString::EnumerationString(const EnumerationString&)
    {
    }

    //////////////////////////////////////////////////////
    std::ostream& operator<<(std::ostream& os, const EnumerationString& e)
    {
        os << e.GetName();
        return os;
    }
}