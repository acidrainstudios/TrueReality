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
#pragma once

#include <trUtil/Export.h>

#include <trUtil/WarningUtils.h>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @brief   Disable warning for stl classes Needs to have dll-interface to be used by clients of
     *          class.
     */
    TR_DISABLE_WARNING_START_MSVC(4251)   

    /**
     * @class   EnvVariables
     *
     * @brief   An environment variables.
     *          
     * @author Maxim Serebrennik
     */
    class TR_UTIL_EXPORT EnvVariables
    {
    public:

        /** @brief   Environmental Variable that points to the Root folder of the engine. */
        const static std::string TR_ROOT;
        
        /** @brief   Environmental Variable that points to the Library folders of the engine. */
        const static std::string TR_LIB;

        /** @brief   Environmental Variable that points to the Binary folders of the engine. */
        const static std::string TR_BIN;

        /** @brief   Environmental Variable that points to the Include folders of the engine. */
        const static std::string TR_INC;

        /**
         * @brief   Environmental Variable that points to the Data folder of the engine The Data folder
         *          should have general art and system content If this variable is not present the engine
         *          will search for the Data Folder in TR_ROOT.
         */
        const static std::string TR_DATA;

        /**
         * @brief   Environmental Variable that points to the User Data folder of the engine The Data
         *          folder should have the log files and general art and user content If this variable is
         *          not present the engine will search for the User Data Folder in Users Home and
         *          MyDocuments directories.
         */
        const static std::string TR_USER_DATA;

        /**
         * @brief   Environmental Variable that should be upended to the PATH variable, to give the
         *          engine access to its resources.
         */
        const static std::string TR_PATH;

        /** @brief   Environmental Variable holds the path of the custom Log folder. */
        const static std::string TR_LOG_PATH;

    protected:

        /**
         * @fn  EnvVariables::EnvVariables()
         *
         * @brief   Default constructor.
         */
        EnvVariables(){};
    };
    TR_DISABLE_WARNING_END
}

