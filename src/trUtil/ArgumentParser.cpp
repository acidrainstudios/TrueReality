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

#include <trUtil/ArgumentParser.h>

namespace trUtil
{
    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(bool& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(float& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(double& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(int& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(unsigned int& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(std::string& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(const Parameter& param)
    {
        mParam = new osg::ArgumentParser::Parameter(param);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::~Parameter()
    {
        if (mParam != nullptr)
        {
            delete mParam;
            mParam = nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter& ArgumentParser::Parameter::operator = (const Parameter& param)
    {
        mParam = param.mParam;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    inline bool ArgumentParser::Parameter::Valid(const char* str) const
    {
        return mParam->valid(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Parameter::Assign(const char* str)
    {
        return mParam->assign(str);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator osg::ArgumentParser::Parameter() const
    {
        return *mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator osg::ArgumentParser::Parameter&()
    {
        return *mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator const osg::ArgumentParser::Parameter&() const
    {
        return *mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator osg::ArgumentParser::Parameter*()
    {
        return mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::ArgumentParser(int* argc, char **argv)
    {
        mArgParser = std::make_unique<osg::ArgumentParser>(argc, argv);
        mAppUsage = std::make_unique<ApplicationUsage>(mArgParser->getApplicationUsage());
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::~ArgumentParser()
    {       
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsOption(const char* str) const
    {
        return mArgParser->isOption(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsString(const char* str) const
    {
        return mArgParser->isString(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsNumber(const char* str) const
    {
        return mArgParser->isNumber(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsBool(const char* str) const
    {
        return mArgParser->isBool(str);
    }

    //////////////////////////////////////////////////////////////////////////
    void ArgumentParser::SetApplicationUsage(ApplicationUsage* usage)
    {
        mAppUsage.reset(usage);
        mArgParser->setApplicationUsage(mAppUsage.get()->operator osg::ApplicationUsage *());
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage* ArgumentParser::GetApplicationUsage()
    {
        return mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    const ApplicationUsage* ArgumentParser::GetApplicationUsage() const
    {
        return mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    int& ArgumentParser::GetArgc()
    {
        return mArgParser->argc();
    }

    //////////////////////////////////////////////////////////////////////////
    char** ArgumentParser::GetArgv()
    {
        return mArgParser->argv();
    }

    //////////////////////////////////////////////////////////////////////////
    std::string ArgumentParser::GetApplicationName() const
    {
        return mArgParser->getApplicationName();
    }

    //////////////////////////////////////////////////////////////////////////
    int ArgumentParser::Find(const std::string& str) const
    {
        return mArgParser->find(str);
    }
}