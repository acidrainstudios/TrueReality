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
* Author: Maxim Serebrennik
*/

#pragma once

#include "Export.h"

#include <trUtil/EnumerationNumeric.h>

namespace trCore
{
    /**
     * @class   SystemEvents
     *
     * @brief   Enum that specifies type of a system event
     */
    class TR_CORE_EXPORT SystemEvents : public trUtil::EnumerationNumeric
    {
        DECLARE_ENUM(SystemEvents)
    public:

        /** @brief   The event traversal event. */
        const static SystemEvents EVENT_TRAVERSAL;

        /** @brief   The post event traversal event. */
        const static SystemEvents POST_EVENT_TRAVERSAL;

        /** @brief   The pre frame event. */
        const static SystemEvents PRE_FRAME;
        
        /** @brief   The camera synchronization event. */
        const static SystemEvents CAMERA_SYNCH;
        
        /** @brief   The frame synchronization event. */
        const static SystemEvents FRAME_SYNCH;
        
        /** @brief   The frame event. */
        const static SystemEvents FRAME;
        
        /** @brief   The post frame event. */
        const static SystemEvents POST_FRAME;

        /** @brief   The paused event. */
        const static SystemEvents PAUSED;

        /** @brief   The unpaused event. */
        const static SystemEvents UNPAUSED;

        /** @brief   Indicates a change in the time scale. */
        const static SystemEvents TIME_SCALE_CHANGED;

        /** @brief   Gets sent out when the system is shutting down. */
        const static SystemEvents SHUTTING_DOWN;
    protected:

        /**
         * @fn  SystemEvents::SystemEvents(const std::string& name, unsigned int id);
         *
         * @brief   Constructor, protected to prevent creation of an instance.
         *
         * @param   name    The name.
         * @param   id      The identifier.
         */
        SystemEvents(const std::string& name, unsigned int id);
    };
}