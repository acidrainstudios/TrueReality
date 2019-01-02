/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
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
* @author Matthew W. Campbell
* @author Maxim Serebrennik
*/

#include <trUtil/Exception.h>

#include <sstream>
#include <iostream>
#include <osgDB/FileNameUtils>

namespace trUtil
{
    //////////////////////////////////////////////////////////////////////////
    Exception::Exception(const std::string& message, const std::string& filename,
        unsigned int lineNum)
        : mMessage(message)
        , mFileName(osgDB::getSimpleFileName(filename))
        , mLineNum(lineNum)
    {
        LogException(trUtil::Logging::LogLevel::LOG_DEBUG, trUtil::Logging::Log::GetInstance());
    }

    //////////////////////////////////////////////////////////////////////////
    void Exception::Print() const
    {
        std::cerr << "Exception: " << mMessage << std::endl <<
            "\tFile: " << mFileName << std::endl <<
            "\tLine: " << mLineNum << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////
    std::string Exception::ToString() const
    {
        std::ostringstream ss;
        ss << "Reason: " << mMessage << " | File: " << mFileName << " | Line: " << mLineNum;
        return ss.str();
    }

    //////////////////////////////////////////////////////////////////////////
    void Exception::LogException(trUtil::Logging::LogLevel level) const
    {
        LogException(level, trUtil::Logging::Log::GetInstance());
    }

    //////////////////////////////////////////////////////////////////////////
    void Exception::LogException(trUtil::Logging::LogLevel level, const std::string& loggerName) const
    {
        LogException(level, trUtil::Logging::Log::GetInstance(loggerName));
    }

    //////////////////////////////////////////////////////////////////////////
    void Exception::LogException(trUtil::Logging::LogLevel level, trUtil::Logging::Log& logger) const
    {
        if (logger.IsLevelEnabled(level))
        {
            logger.LogMessage(mFileName, mFileName, mLineNum,
                "Exception Thrown: " + mMessage, level);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    Exception::~Exception()
    {

    }

    ////////////////////////////////////////////////////////////////////////////////
    const std::string& Exception::What() const
    {
        return mMessage;
    }

    ////////////////////////////////////////////////////////////////////////////////
    const std::string& Exception::File() const
    {
        return mFileName;
    }

    ////////////////////////////////////////////////////////////////////////////////
    unsigned int Exception::Line() const
    {
        return mLineNum;
    }

    //////////////////////////////////////////////////////////////////////////
    TR_UTIL_EXPORT std::ostream& operator << (std::ostream& o, const Exception& ex)
    {
        o << ex.ToString();
        return o;
    }
}

