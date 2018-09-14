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

#include <trUtil/ApplicationUsage.h>

/**
 * @namespace   trUtil
 *
 * @brief   Namespace that holds various utility classes for the engine
 */
namespace trUtil
{
    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::ApplicationUsage()
    {
        mAppUsage = new osg::ApplicationUsage();
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::ApplicationUsage(osg::ApplicationUsage* applicationUsage)
    {
        mAppUsage = applicationUsage;
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::ApplicationUsage(const std::string& commandLineUsage)
    {
        mAppUsage = new osg::ApplicationUsage(commandLineUsage);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetApplicationName(const std::string& name)
    {
        mAppUsage->setApplicationName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& ApplicationUsage::GetApplicationName() const
    {
        return mAppUsage->getApplicationName();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetDescription(const std::string& desc)
    {
        mAppUsage->setDescription(desc);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& ApplicationUsage::GetDescription() const
    {
        return mAppUsage->getDescription();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::AddUsageExplanation(Type type, const std::string & option, const std::string & explanation)
    {
        mAppUsage->addUsageExplanation(static_cast<osg::ApplicationUsage::Type>(type), option, explanation);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetCommandLineUsage(const std::string& explanation)
    {
        mAppUsage->setCommandLineUsage(explanation);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& ApplicationUsage::GetCommandLineUsage() const
    {
        return mAppUsage->getCommandLineUsage();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::AddCommandLineOption(const std::string& option, const std::string& explanation, const std::string& defaultValue)
    {
        mAppUsage->addCommandLineOption(option, explanation, defaultValue);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetCommandLineOptions(const UsageMap& usageMap)
    {
        mAppUsage->setCommandLineOptions(usageMap);
    }

    //////////////////////////////////////////////////////////////////////////
    const ApplicationUsage::UsageMap& ApplicationUsage::GetCommandLineOptions() const
    {
        return mAppUsage->getCommandLineOptions();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetCommandLineOptionsDefaults(const UsageMap& usageMap)
    {
        mAppUsage->setCommandLineOptionsDefaults(usageMap);
    }

    //////////////////////////////////////////////////////////////////////////
    const ApplicationUsage::UsageMap& ApplicationUsage::GetCommandLineOptionsDefaults() const
    {
        return mAppUsage->getCommandLineOptionsDefaults();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::AddEnvironmentalVariable(const std::string& option, const std::string& explanation, const std::string& defaultValue)
    {
        mAppUsage->addEnvironmentalVariable(option, explanation, defaultValue);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetEnvironmentalVariables(const UsageMap& usageMap)
    {
        mAppUsage->setEnvironmentalVariables(usageMap);
    }

    //////////////////////////////////////////////////////////////////////////
    const ApplicationUsage::UsageMap& ApplicationUsage::GetEnvironmentalVariables() const
    {
        return mAppUsage->getEnvironmentalVariables();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetEnvironmentalVariablesDefaults(const UsageMap& usageMap)
    {
        mAppUsage->setEnvironmentalVariablesDefaults(usageMap);
    }

    //////////////////////////////////////////////////////////////////////////
    const ApplicationUsage::UsageMap& ApplicationUsage::GetEnvironmentalVariablesDefaults() const
    {
        return mAppUsage->getEnvironmentalVariablesDefaults();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::AddKeyboardMouseBinding(const std::string& prefix, int key, const std::string& explanation)
    {
        mAppUsage->addKeyboardMouseBinding(prefix, key, explanation);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::AddKeyboardMouseBinding(int key, const std::string& explanation)
    {
        mAppUsage->addKeyboardMouseBinding(key, explanation);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::AddKeyboardMouseBinding(const std::string& option, const std::string& explanation)
    {
        mAppUsage->addKeyboardMouseBinding(option, explanation);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::SetKeyboardMouseBindings(const UsageMap& usageMap)
    {
        mAppUsage->setKeyboardMouseBindings(usageMap);
    }

    //////////////////////////////////////////////////////////////////////////
    const ApplicationUsage::UsageMap& ApplicationUsage::GetKeyboardMouseBindings() const
    {
        return mAppUsage->getKeyboardMouseBindings();
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::GetFormattedString(std::string& str, const UsageMap& um, unsigned int widthOfOutput, bool showDefaults, const UsageMap& ud)
    {
        mAppUsage->getFormattedString(str, um, widthOfOutput, showDefaults, ud);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::Write(std::ostream& output, const UsageMap& um, unsigned int widthOfOutput, bool showDefaults, const UsageMap& ud)
    {
        mAppUsage->write(output, um, widthOfOutput, showDefaults, ud);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::Write(std::ostream& output, Type type, unsigned int widthOfOutput, bool showDefaults)
    {
        mAppUsage->write(output, static_cast<unsigned int>(type), widthOfOutput, showDefaults);
    }

    //////////////////////////////////////////////////////////////////////////
    void ApplicationUsage::WriteEnvironmentSettings(std::ostream& output)
    {
        mAppUsage->writeEnvironmentSettings(output);
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::operator osg::ApplicationUsage&()
    {
        return *mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::operator const osg::ApplicationUsage&() const
    {
        return *mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::operator osg::ApplicationUsage*()
    {
        return mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::operator const osg::ApplicationUsage*() const
    {
        return mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage::~ApplicationUsage()
    {
    }
}