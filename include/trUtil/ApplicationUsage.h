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

#pragma once

#include <trUtil/Export.h>

#include <trBase/SmrtPtr.h>

#include <osg/ApplicationUsage>

#include <string>


/**
 * @namespace   trUtil
 *
 * @brief   Namespace that holds various utility classes for the engine
 */
namespace trUtil
{
    /**
     * @class   ApplicationUsage
     *
     * @brief   An application usage class for the argument parser.
     */
    class TR_UTIL_EXPORT ApplicationUsage
    {
    public:

        /**
         * @fn  ApplicationUsage::ApplicationUsage();
         *
         * @brief   Default constructor.
         */
        ApplicationUsage();

        /**
         * @fn  ApplicationUsage::ApplicationUsage(const std::string& commandLineUsage);
         *
         * @brief   Default constructor.
         *
         * @param   commandLineUsage    The command line usage.
         */
        ApplicationUsage(const std::string& commandLineUsage);

        /**
         * @fn  void ApplicationUsage::SetApplicationName(const std::string& name);
         *
         * @brief   Sets the Applications Name. It is used in Application description
         *
         * @param   name    The name.
         */
        void SetApplicationName(const std::string& name);

        /**
         * @fn  const std::string& ApplicationUsage::GetApplicationName() const;
         *
         * @brief   Gets the stored application name.
         *
         * @return  The application name.
         */
        const std::string& GetApplicationName() const;

    protected:
        /**
         * @fn  ApplicationUsage::~ApplicationUsage();
         *
         * @brief   Destructor.
         */
        ~ApplicationUsage();

    private:

        trBase::SmrtPtr<osg::ApplicationUsage> mAppUsage = nullptr;
    };
}


