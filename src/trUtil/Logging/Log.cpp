/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
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

#include <trUtil/Logging/Log.h>

#include <trUtil/Bits.h>
#include <trUtil/Logging/LogManager.h>
#include <trUtil/Logging/LogWriterConsole.h>
#include <trUtil/StringUtils.h>


#include <osg/Referenced>
#include <osg/ref_ptr>
#include <osg/observer_ptr>
#include <osgDB/FileNameUtils>


#include <algorithm>
#include <stdarg.h>

namespace trUtil::Logging
{
    static osg::ref_ptr<LogManager> LOG_MANAGER(NULL);
    static LogLevel DEFAULT_LOG_LEVEL(LogLevel::LOG_WARNING);

    //////////////////////////////////////////////////////////////////////////
    class LogImpl //: std::stringbuf
    {
    public:
        explicit LogImpl(const std::string& name)
            : mOutputStreamBit(Log::STANDARD)
            , mName(name)
            , mLevel(DEFAULT_LOG_LEVEL)
            , mWriters()
        {
        }

        unsigned int mOutputStreamBit; ///<the current output stream option
        std::string mName;
        LogLevel mLevel;
        Log::LogWriterContainer mWriters;
    };

    //////////////////////////////////////////////////////////////////////////
    const std::string Log::LOG_DEFAULT_NAME("MainLog");

    //////////////////////////////////////////////////////////////////////////
    Log::Log(const std::string& name)
        :
        mImpl(new LogImpl(name))
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Log::~Log()
    {
        delete mImpl;
        mImpl = nullptr;
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::LogMessage(const std::string& cppFile, const std::string& method, int line, const std::string& msg, LogLevel logLevel) const
    {
        if (mImpl->mOutputStreamBit == Log::NO_OUTPUT)
        {
            return;
        }

        if (logLevel < mImpl->mLevel)
        {
            return;
        }

        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(LOG_MANAGER->GetMutex());
        bool hasLogTimeProvider = LOG_MANAGER->IsLogTimeProviderValid();

        LogWriter::LogData logData;
        if (hasLogTimeProvider)
        {
            logData.frameNumber = LOG_MANAGER->GetFrameNumber();
            logData.time = LOG_MANAGER->GetDateTime();
        }
        else
        {
            logData.time.SetToLocalTime();
        }

        logData.logLevel = logLevel;
        logData.logName = mImpl->mName;
        logData.file = osgDB::getSimpleFileName(cppFile);
        logData.method = method;
        logData.line = line;
        logData.msg = msg;


        if (trUtil::Bits::Has(mImpl->mOutputStreamBit, Log::TO_FILE))
        {
            LOG_MANAGER->LogMessageToFile(logData);
        }

        if (trUtil::Bits::Has(mImpl->mOutputStreamBit, Log::TO_CONSOLE))
        {
            LOG_MANAGER->LogMessageToConsole(logData);
        }

        if (trUtil::Bits::Has(mImpl->mOutputStreamBit, Log::TO_WRITER) && !mImpl->mWriters.empty())
        {
            Log::LogWriterContainer::iterator itr = mImpl->mWriters.begin();
            while (itr != mImpl->mWriters.end())
            {
                (*itr)->LogMessage(logData);
                ++itr;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::LogMessage(LogLevel logLevel, const std::string& source, int line, const char* msg, va_list list) const
    {
        char buffer[2049];

        vsnprintf(buffer, 2049, msg, list);

        LogMessage("", source, line, buffer, logLevel);
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::LogMessage(LogLevel logLevel, const std::string& source, const char* msg, ...) const
    {
        va_list list;

        va_start(list, msg);
        LogMessage(logLevel, source, -1, msg, list);
        va_end(list);
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::LogMessage(LogLevel logLevel, const std::string& source, int line, const char* msg, ...) const
    {
        va_list list;

        va_start(list, msg);
        LogMessage(logLevel, source, line, msg, list);
        va_end(list);
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::LogMessage(LogLevel logLevel, const std::string& source, int line, const std::string& msg) const
    {
        LogMessage("", source, line, msg, logLevel);
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::LogHorizRule()
    {
        if (mImpl->mOutputStreamBit == Log::NO_OUTPUT)
        {
            return;
        }

        if (trUtil::Bits::Has(mImpl->mOutputStreamBit, Log::TO_FILE))
        {
            LOG_MANAGER->LogHorizRule();
        }
    }

    //////////////////////////////////////////////////////////////////////////
    Log& Log::GetInstance(const std::string& name)
    {
        if (LOG_MANAGER == nullptr)
        {
            LOG_MANAGER = new LogManager;
        }

        Log* l = LOG_MANAGER->GetInstance(name);
        if (l == nullptr)
        {
            l = new Log(name);
            LOG_MANAGER->AddInstance(name, l);
        }

        return *l;
    }

    //////////////////////////////////////////////////////////////////////////
    LogManager& Log::GetLogManagerRef()
    {
        return *LOG_MANAGER;
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::SetTestMode(bool state)
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(LOG_MANAGER->GetMutex());
        mTestingMode = state;
    }

    //////////////////////////////////////////////////////////////////////////
    void Log::SetDefaultLogLevel(LogLevel newLevel)
    {
        DEFAULT_LOG_LEVEL = newLevel;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string Log::GetLogLevelString(LogLevel logLevel) //static
    {
        return LogLevelToString(logLevel);
    }

    //////////////////////////////////////////////////////////////////////////
    LogLevel Log::GetLogLevelForString(const std::string& levelString)  //static
    {
        return LogLevelFromString(levelString);
    }

    ///////////////////////////////////////////////////////////////////////////
    void Log::SetOutputStreamBit(unsigned int option)
    {
        mImpl->mOutputStreamBit = option;
    }

    ///////////////////////////////////////////////////////////////////////////
    void Log::SetAllOutputStreamBits(unsigned int option)
    {
        if (LOG_MANAGER.valid())
        {
            LOG_MANAGER->SetAllOutputStreamBits(option);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    unsigned int Log::GetOutputStreamBit() const
    {
        return mImpl->mOutputStreamBit;
    }

    ///////////////////////////////////////////////////////////////////////////
    const std::string& Log::GetName() const
    {
        return mImpl->mName;
    }

    ////////////////////////////////////////////////////////////////////////////////
    bool Log::IsLevelEnabled(LogLevel logLevel) const
    {
        return logLevel >= mImpl->mLevel;
    }

    ////////////////////////////////////////////////////////////////////////////////
    void Log::SetLogLevel(LogLevel logLevel)
    {
        mImpl->mLevel = logLevel;
    }

    ////////////////////////////////////////////////////////////////////////////////
    LogLevel Log::GetLogLevel() const
    {
        return mImpl->mLevel;
    }

    ////////////////////////////////////////////////////////////////////////////////
    void Log::SetAllLogLevels(LogLevel newLevel) //static
    {
        if (LOG_MANAGER.valid())
        {
            LOG_MANAGER->SetAllLogLevels(newLevel);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    void Log::SetLogTimeProvider(LogTimeProvider* ltp)
    {
        if (LOG_MANAGER.valid())
        {
            LOG_MANAGER->SetLogTimeProvider(ltp);

            if (ltp != NULL && !LOG_MANAGER->IsLogTimeProviderValid())
            {
                LOG_E("Unable to assign log time provider because it did not provide a referenced object as a key for deletion");
                LOG_MANAGER->SetLogTimeProvider(NULL);
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    void Log::AddWriter(LogWriter& writer)
    {
        mImpl->mWriters.push_back(&writer);
    }

    ////////////////////////////////////////////////////////////////////////////////
    const Log::LogWriterContainer& Log::GetWriters() const
    {
        return mImpl->mWriters;
    }

    //////////////////////////////////////////////////////////////////////////
    Log::LogWriterContainer& Log::GetWriters()
    {
        return mImpl->mWriters;
    }

    ////////////////////////////////////////////////////////////////////////////////
    void Log::RemoveWriter(LogWriter& writer)
    {
        LogWriterContainer::iterator found = std::find(mImpl->mWriters.begin(),
            mImpl->mWriters.end(), &writer);
        if (found != mImpl->mWriters.end())
        {
            mImpl->mWriters.erase(found);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    LoggingOff::LoggingOff(const std::string& name)
        : mLog(trUtil::Logging::Log::GetInstance(name))
    {
        mOldLevel = mLog.GetLogLevel();
        // Only ALWAYS log levels are on.
        mLog.SetLogLevel(trUtil::Logging::LogLevel::LOG_ALWAYS);
    }
    ////////////////////////////////////////////////////////////////////////////////
    LoggingOff::~LoggingOff()
    {
        mLog.SetLogLevel(mOldLevel);
    }
}