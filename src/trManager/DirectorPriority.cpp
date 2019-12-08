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

#include <trManager/DirectorPriority.h>

namespace trManager
{
    IMPLEMENT_ENUM(DirectorPriority)

    //////////////////////////////////////////////////////////////////////////
    DirectorPriority::DirectorPriority(const std::string& name, unsigned int id) : EnumerationNumeric(name, id)
    {
        AddInstance(this);
    }

    //////////////////////////////////////////////////////////////////////////
    DirectorPriority DirectorPriority::HIGHEST("HIGHEST", 1);
    DirectorPriority DirectorPriority::HIGHER("HIGHER", 2);
    DirectorPriority DirectorPriority::NORMAL("NORMAL", 3);
    DirectorPriority DirectorPriority::LOWER("LOWER", 4);
    DirectorPriority DirectorPriority::LOWEST("LOWEST", 5);
}