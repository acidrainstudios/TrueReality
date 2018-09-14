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
    ApplicationUsage::~ApplicationUsage()
    {
    }
}