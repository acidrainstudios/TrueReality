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

#include <trUtil/EnumerationNumeric.h>

namespace trUtil
{
    //////////////////////////////////////////////////////
    EnumerationNumeric::EnumerationNumeric(const std::string& name, unsigned int id) : BaseClass(name), mID(id)
    {
    }

    //////////////////////////////////////////////////////
    EnumerationNumeric& EnumerationNumeric::operator=(const EnumerationNumeric&)
    {
        return *this;
    }

    //////////////////////////////////////////////////////
    bool EnumerationNumeric::operator==(const std::string& rhs) const
    {
        return Compare(rhs) == 0;
    }

    //////////////////////////////////////////////////////
    bool EnumerationNumeric::operator!=(const std::string& rhs) const
    {
        return Compare(rhs) != 0;
    }

    //////////////////////////////////////////////////////
    bool EnumerationNumeric::operator<(const std::string& rhs) const
    {
        return Compare(rhs) < 0;
    }

    //////////////////////////////////////////////////////
    bool EnumerationNumeric::operator>(const std::string& rhs) const
    {
        return Compare(rhs) > 0;
    }

    //////////////////////////////////////////////////////
    EnumerationNumeric::~EnumerationNumeric()
    {
    }

    //////////////////////////////////////////////////////
    unsigned int EnumerationNumeric::GetID() const
    {
        return mID;
    }

    //////////////////////////////////////////////////////
    std::ostream& operator<<(std::ostream& os, const EnumerationNumeric& e)
    {
        os << e.GetName() << ":" << e.GetID();
        return os;
    }
}