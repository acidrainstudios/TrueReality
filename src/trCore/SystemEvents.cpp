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
* @author Maxim Serebrennik
*/

#include <trCore/SystemEvents.h>

namespace trCore
{
    IMPLEMENT_ENUM(SystemEvents)

    //////////////////////////////////////////////////////////////////////////
    SystemEvents::SystemEvents(const std::string& name, unsigned int id) : EnumerationNumeric(name, id)
    {
        AddInstance(this);
    }
    //////////////////////////////////////////////////////////////////////////
    const SystemEvents SystemEvents::EVENT_TRAVERSAL("EVENT_TRAVERSAL", 0);
    const SystemEvents SystemEvents::POST_EVENT_TRAVERSAL("POST_EVENT_TRAVERSAL", 1);
    const SystemEvents SystemEvents::PRE_FRAME("PRE_FRAME", 2);
    const SystemEvents SystemEvents::CAMERA_SYNCH("CAMERA_SYNCH", 3);
    const SystemEvents SystemEvents::FRAME_SYNCH("FRAME_SYNCH", 4);
    const SystemEvents SystemEvents::FRAME("FRAME", 5);
    const SystemEvents SystemEvents::POST_FRAME("POST_FRAME", 6);
    const SystemEvents SystemEvents::PAUSED("PAUSED", 7);
    const SystemEvents SystemEvents::UNPAUSED("UNPAUSED", 8);
    const SystemEvents SystemEvents::TIME_SCALE_CHANGED("TIME_SCALE_CHANGED", 9);
    const SystemEvents SystemEvents::SHUTTING_DOWN("SHUTTING_DOWN", 10);
    //////////////////////////////////////////////////////////////////////////

}

