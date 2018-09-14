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

#include <osg/ApplicationUsage>
#include <osg/ref_ptr>

#include <string>
#include <map>


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

        /** @brief   The message to command usage map. */
        using UsageMap = std::map<std::string, std::string>;

        enum class Type
        {
            NO_HELP = osg::ApplicationUsage::NO_HELP,
            COMMAND_LINE_OPTION = osg::ApplicationUsage::COMMAND_LINE_OPTION,
            ENVIRONMENTAL_VARIABLE = osg::ApplicationUsage::ENVIRONMENTAL_VARIABLE,
            KEYBOARD_MOUSE_BINDING = osg::ApplicationUsage::KEYBOARD_MOUSE_BINDING,
            HELP_ALL = KEYBOARD_MOUSE_BINDING | ENVIRONMENTAL_VARIABLE | COMMAND_LINE_OPTION
        };

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

        /**
         * @fn  void ApplicationUsage::SetDescription(const std::string& desc);
         *
         * @brief   If non-empty, the Description is typically shown by the Help Handler as text on the
         *          Help display (which also lists keyboard abbreviations.)
         *
         * @param   desc    The description.
         */
        void SetDescription(const std::string& desc);

        /**
         * @fn  const std::string& ApplicationUsage::GetDescription() const;
         *
         * @brief   Gets the description.
         *
         * @return  The description.
         */
        const std::string& GetDescription() const;

        /**
         * @fn  void ApplicationUsage::AddUsageExplanation(Type type, const std::string& option, const std::string& explanation);
         *
         * @brief   Adds an usage explanation.
         *
         * @param   type        The type.
         * @param   option      The option.
         * @param   explanation The explanation.
         */
        void AddUsageExplanation(Type type, const std::string& option, const std::string& explanation);

        /**
         * @fn  void ApplicationUsage::SetCommandLineUsage(const std::string& explanation);
         *
         * @brief   Sets command line usage.
         *
         * @param   explanation The explanation.
         */
        void SetCommandLineUsage(const std::string& explanation);

        /**
         * @fn  const std::string& ApplicationUsage::GetCommandLineUsage() const;
         *
         * @brief   Gets command line usage.
         *
         * @return  The command line usage.
         */
        const std::string& GetCommandLineUsage() const;

        /**
         * @fn  void ApplicationUsage::AddCommandLineOption(const std::string& option, const std::string& explanation, const std::string &defaultValue = "");
         *
         * @brief   Adds a command line option.
         *
         * @param   option          The option.
         * @param   explanation     The explanation.
         * @param   defaultValue    (Optional) The default value.
         */
        void AddCommandLineOption(const std::string& option, const std::string& explanation, const std::string &defaultValue = "");

        /**
         * @fn  void ApplicationUsage::SetCommandLineOptions(const UsageMap& usageMap);
         *
         * @brief   Sets command line options.
         *
         * @param   usageMap    The usage map.
         */
        void SetCommandLineOptions(const UsageMap& usageMap);

        /**
         * @fn  const UsageMap& ApplicationUsage::GetCommandLineOptions() const;
         *
         * @brief   Gets command line options.
         *
         * @return  The command line options.
         */
        const UsageMap& GetCommandLineOptions() const;

        /**
         * @fn  void ApplicationUsage::SetCommandLineOptionsDefaults(const UsageMap& usageMap);
         *
         * @brief   Sets command line options defaults.
         *
         * @param   usageMap    The usage map.
         */
        void SetCommandLineOptionsDefaults(const UsageMap& usageMap);

        /**
         * @fn  const UsageMap& ApplicationUsage::GetCommandLineOptionsDefaults() const;
         *
         * @brief   Gets command line options defaults.
         *
         * @return  The command line options defaults.
         */
        const UsageMap& GetCommandLineOptionsDefaults() const;

        /**
         * @fn  void ApplicationUsage::AddEnvironmentalVariable(const std::string& option, const std::string& explanation, const std::string& defaultValue = "");
         *
         * @brief   Adds an environmental variable usage explanation.
         *
         * @param   option          The option.
         * @param   explanation     The explanation.
         * @param   defaultValue    (Optional) The default value.
         */
        void AddEnvironmentalVariable(const std::string& option, const std::string& explanation, const std::string& defaultValue = "");

        /**
         * @fn  void ApplicationUsage::SetEnvironmentalVariables(const UsageMap& usageMap);
         *
         * @brief   Sets environmental variables usage.
         *
         * @param   usageMap    The usage map.
         */
        void SetEnvironmentalVariables(const UsageMap& usageMap);

        /**
         * @fn  const UsageMap& ApplicationUsage::GetEnvironmentalVariables() const;
         *
         * @brief   Gets environmental variables usage.
         *
         * @return  The environmental variables.
         */
        const UsageMap& GetEnvironmentalVariables() const;

        /**
         * @fn  operator osg::ApplicationUsage& ();
         *
         * @brief   Implicit conversion operator to OSG ApplicationUsage.
         *
         * @return  The result of the operation.
         */
        operator osg::ApplicationUsage& ();

        /**
         * @fn  operator const osg::ApplicationUsage& () const;
         *
         * @brief   Implicit conversion operator to OSG ApplicationUsage.
         *
         * @return  A const.
         */
        operator const osg::ApplicationUsage& () const;

        /**
         * @fn  operator osg::ApplicationUsage* ();
         *
         * @brief   Implicit conversion operator to OSG ApplicationUsage.
         *
         * @return  The result of the operation.
         */
        operator osg::ApplicationUsage* ();

        /**
         * @fn  operator osg::ApplicationUsage* ();
         *
         * @brief   Implicit conversion operator to OSG ApplicationUsage.
         *
         * @return  The result of the operation.
         */
        operator const osg::ApplicationUsage* () const;

    protected:
        /**
         * @fn  ApplicationUsage::~ApplicationUsage();
         *
         * @brief   Destructor.
         */
        ~ApplicationUsage();

    private:

       osg::ref_ptr<osg::ApplicationUsage> mAppUsage = nullptr;
    };
}


