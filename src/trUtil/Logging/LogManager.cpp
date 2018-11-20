/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* @author Erik Johnson
* @author David Guthrie
* @author Maxim Serebrennik
*/
#include <trUtil/Logging/LogManager.h>

#include <trUtil/Logging/LogWriterConsole.h>

#include <algorithm>

namespace trUtil::Logging
{
    ////////////////////////////////////////////////////////////////
    LogManager::LogManager()
        : mLogWriterConsole(new LogWriterConsole())
        , mLogWriterFile(new LogWriterFile())
        , mLogTimeProvider(nullptr)
    {
    }

    ////////////////////////////////////////////////////////////////
    LogManager::~LogManager()
    {
        mInstances.clear();
        mLogWriterConsole = nullptr;
        mLogWriterFile = nullptr;
    }

    ////////////////////////////////////////////////////////////////
    bool LogManager::AddInstance(const std::string& name, Log* log)
    {
        return mInstances.insert(std::make_pair(name, osg::ref_ptr<Log>(log))).second;
    }

    ////////////////////////////////////////////////////////////////
    Log* LogManager::GetInstance(const std::string& name)
    {
        trUtil::HashMap<std::string, osg::ref_ptr<Log> >::iterator i = mInstances.find(name);
        if (i == mInstances.end())
        {
            return nullptr;
        }
        return i->second.get();
    }

    ////////////////////////////////////////////////////////////////
    void LogManager::SetAllLogLevels(const LogLevel& newLevel)
    {
        std::for_each(mInstances.begin(), mInstances.end(), [this, &newLevel](trUtil::HashMap<std::string, osg::ref_ptr<Log> >::value_type& value)
        {
            Log* log = value.second.get();
            log->SetLogLevel(newLevel);
        });
    }

    ////////////////////////////////////////////////////////////////
    void LogManager::SetAllOutputStreamBits(unsigned int option)
    {
        std::for_each(mInstances.begin(), mInstances.end(), [this, option](trUtil::HashMap<std::string, osg::ref_ptr<Log> >::value_type& value)
        {
            Log* log = value.second.get();
            log->SetOutputStreamBit(option);
        });
    }

    ////////////////////////////////////////////////////////////////
    bool LogManager::IsLogTimeProviderValid() const
    {
        return mLogTimeProviderAsRef.valid() && mLogTimeProvider != nullptr;
    }

    ////////////////////////////////////////////////////////////////
    void LogManager::ReOpenFile()
    {
        mLogWriterFile->ResetOpenFail();
        mLogWriterFile->OpenFile();
    }

    ////////////////////////////////////////////////////////////////
    void LogManager::LogHorizRule()
    {
        mLogWriterFile->LogHorizRule();
    }

    ////////////////////////////////////////////////////////////////
    void LogManager::LogMessageToFile(const LogWriter::LogData& logData)
    {
        mLogWriterFile->LogMessage(logData);
    }

    ////////////////////////////////////////////////////////////////
    void LogManager::LogMessageToConsole(const LogWriter::LogData& logData)
    {
        mLogWriterConsole->LogMessage(logData);
    }

    ////////////////////////////////////////////////////////////////
    void LogManager::SetLogTimeProvider(LogTimeProvider* ltp)
    {
        mLogTimeProvider = ltp;
        if (ltp != nullptr)
        {
            mLogTimeProviderAsRef = ltp->AsReferenced();
        }
        else
        {
            mLogTimeProviderAsRef = nullptr;
        }
    }

    ////////////////////////////////////////////////////////////////
    unsigned int LogManager::GetFrameNumber()
    {
        return mLogTimeProvider->GetFrameNumber();
    }

    ////////////////////////////////////////////////////////////////
    const trUtil::DateTime& LogManager::GetDateTime()
    {
        return mLogTimeProvider->GetDateTime();
    }

    ////////////////////////////////////////////////////////////////
    OpenThreads::Mutex& LogManager::GetMutex()
    {
        return mMutex;
    }
}