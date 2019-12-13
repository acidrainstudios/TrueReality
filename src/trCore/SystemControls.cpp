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

#include <trCore/SystemControls.h>

namespace trCore
{
    IMPLEMENT_ENUM(SystemControls)

    //////////////////////////////////////////////////////////////////////////
    SystemControls::SystemControls(const std::string& name, unsigned int id) : EnumerationNumeric(name, id)
    {
        AddInstance(this);
    }

    //////////////////////////////////////////////////////////////////////////
    const SystemControls SystemControls::PAUSE("PAUSE", 1);
    const SystemControls SystemControls::UNPAUSE("UNPAUSE", 2);
    const SystemControls SystemControls::SPEED_UP("SPEED_UP", 3);
    const SystemControls SystemControls::SPEED_DOWN("SPEED_DOWN", 4);
    const SystemControls SystemControls::SET_TIME_SCALE("SET_TIME_SCALE", 5);
    const SystemControls SystemControls::SHUT_DOWN("SHUT_DOWN", 6);
    //////////////////////////////////////////////////////////////////////////
}