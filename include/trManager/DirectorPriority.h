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

#include <string>

namespace trManager
{
    /**
     * @class   DirectorPriority
     *
     * @brief   Sets the priority for a Director instance. The Directors with the higher priority
     *          will receive messages before the ones with the lower.
     */
    class TR_MANAGER_EXPORT DirectorPriority : public trUtil::EnumerationNumeric
    {
        DECLARE_ENUM(DirectorPriority)
    public:
        
        /** @brief   Highest possible priority.  Components with this priority will get messages first. */
        static DirectorPriority HIGHEST;

        /**
         * @brief   Higher priority.  Components with this priority will get messages after HIGHEST, but
         *          before any others.
         */
        static DirectorPriority HIGHER;

        /**
         * @brief   Normal priority.  Components with this priority will get messages after any HIGHER
         *          priority, but before LOWER.
         */
        static DirectorPriority NORMAL;

        /**
         * @brief   Lower priority.  Components with this priority will get messages after any NORMAL or
         *          HIGHER priority, but before LOWEST.
         */
        static DirectorPriority LOWER;

        /** @brief   Lowest priority.  Components with this priority will get messages after all others. */
        static DirectorPriority LOWEST;

    protected:
        /**
        * ctor
        * Protected to prevent creation of an instance. 
        */
        DirectorPriority(const std::string& name, unsigned int id);
    };   
}