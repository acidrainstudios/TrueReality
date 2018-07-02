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
* @author: Maxim Serebrennik
*/

#pragma once

#include "Export.h"

#include <trUtil/EnumerationNumeric.h>

namespace trCore
{
    /**
     * @class   SystemControls
     *
     * @brief   ENUM specifying various system control states.
     */
    class TR_CORE_EXPORT SystemControls : public trUtil::EnumerationNumeric
    {
        DECLARE_ENUM(SystemControls)
    public:

        /** @brief   Pauses the system. */
        const static SystemControls PAUSE;

        /** @brief   Unpauses the system. */
        const static SystemControls UNPAUSE;

        /** @brief   Speeds up the system. */
        const static SystemControls SPEED_UP;

        /** @brief   Slows down the system. */
        const static SystemControls SPEED_DOWN;

        /**
         * @brief   The set speed of the system.  
         *          Needs to have a systemValue passed in with the MessageSystemControl for actual speed.
         */
        const static SystemControls SET_TIME_SCALE;

        /** @brief   Shuts down the system loop and exits the program. */
        const static SystemControls SHUT_DOWN;
        
    protected:

        /**
         * @fn  SystemControls::SystemControls(const std::string& name, unsigned int id);
         *
         * @brief   Constructor. Protected to prevent creation of an instance.
         *
         * @param   name    The name.
         * @param   id      The identifier.
         */
        SystemControls(const std::string& name, unsigned int id);
    };
}