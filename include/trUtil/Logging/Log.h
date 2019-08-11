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
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* @author Matthew W. Campbell
* @author Erik Johnson
* @author David Guthrie
* @author Maxim Serebrennik
*/
#pragma once
#include <trUtil/Export.h>

#include <trUtil/DateTime.h>
#include <trUtil/Logging/LogFile.h>
#include <trUtil/Logging/LogLevel.h>

#include <string>
#include <cstdarg>
#include <vector>
#include <sstream>

#include <osg/Referenced>
#include <osg/ref_ptr>


namespace trUtil::Logging
{
    // Fwd declaration
    class LogWriter;
    class LogTimeProvider;
    class LogManager;
    class LogImpl;

/**
* @def TR_LOG_SOURCE
*
* @brief   Helps making logging a little easier.  However, if printf style
*            logging is desired, you cannot use this macro.
*/
#define TR_LOG_SOURCE __FILE__, __FUNCTION__, __LINE__

/**
* @def LOG_FULL(level, name, msg)
*
* @brief   Logging macro to make error recording esier.
*
* @param   level   - Level of Logging (ERROR, WARNING, etc)
* @param   name    - Name of the Log file.
* @param   msg     - Message to log.
*/
#define LOG_FULL(level, name, msg) \
    {\
        trUtil::Logging::Log& logger = trUtil::Logging::Log::GetInstance(name); \
        if (logger.IsLevelEnabled(level)) \
        {\
            std::ostringstream st;\
            st << msg;\
            logger.LogMessage(TR_LOG_SOURCE, st.str(), level); \
        }\
    }\

/**
* @def LOGN_D(name, msg)
*
* @brief   Log a DEBUG message.
*
* @param   name    - Log File Name.
* @param   msg     - Message to log.
*/
#define LOGN_D(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_DEBUG, name, msg)

/**
* @def LOGN_I(name, msg)
*
* @brief   Log an INFO message.
*
* @param   name    - Log File Name.
* @param   msg     - Message to log.
*/
#define LOGN_I(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_INFO, name, msg)

/**
* @def LOGN_W(name, msg)
*
* @brief   Log a WARNING message.
*
* @param   name    - Log File Name.
* @param   msg     - Message to log.
*/
#define LOGN_W(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_WARNING, name, msg)

/**
* @def LOGN_E(name, msg)
*
* @brief   Log an ERROR message.
*
* @param   name    - Log File Name.
* @param   msg     - Message to log.
*/
#define LOGN_E(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_ERROR, name, msg)

/**
* @def LOGN_A(name, msg)
*
* @brief   Log an ALWAYS message.
*
* @param   name    - Log File Name.
* @param   msg     - Message to log.
*/
#define LOGN_A(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_ALWAYS, name, msg)

/**
* @def LOG_D(msg)
*
* @brief   Log a DEBUG message.
*
* @param   msg - Message to log.
*/
#define LOG_D(msg) LOGN_D(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

/**
* @def LOG_I(msg)
*
* @brief   Log an INFO message.
*
* @param   msg - Message to log.
*/
#define LOG_I(msg) LOGN_I(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

/**
* @def LOG_W(msg)
*
* @brief   Log a WARNING message.
*
* @param   msg - Message to log.
*/
#define LOG_W(msg) LOGN_W(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

/**
* @def LOG_E(msg)
*
* @brief   Log an ERROR message.
*
* @param   msg - Message to log.
*/
#define LOG_E(msg) LOGN_E(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

/**
* @def LOG_A(msg)
*
* @brief   Log an ALWAYS message.
*
* @param   msg - Message to log.
*/
#define LOG_A(msg) LOGN_A(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

/**
* @def LOG_PRINT_TEST
*
* @brief   Prints out a message to the Logger with a test string for every log level Only the
*          currently enabled log levels will be visible The Log messages will only go to the
*          enabled Log Writers This would be used for testing and development.
*/
#define LOG_PRINT_TEST \
    LOG_D("Test Message") \
    LOG_I("Test Message") \
    LOG_W("Test Message") \
    LOG_E("Test Message") \
    LOG_A("Test Message")

    /**
        * @class   Log
        *
        * @brief   Log class which the engine uses for all of its logging needs.  The log file is
        *          formatted using html tags, therefore, any browser should display the log without
        *           any problems.
        */
    class TR_UTIL_EXPORT Log : public osg::Referenced
    {
    public:

        /**
         * @struct  LogTestData
         *
         * @brief   A data structure that is used for Unit Tests
         */
        struct LogTestData
        {            
            trUtil::Logging::LogLevel logLevel; /** @brief   Log level. */
            trUtil::DateTime time;              /** @brief   Time of message. */
            unsigned frameNumber;               /** @brief   The frame number. */
            std::string logName;                /** @brief   The name of the Log instance (could be empty) */
            std::string file;                   /** @brief   The source file of the message. */
            std::string method;                 /** @brief   The calling method of the message. */
            int line;                           /** @brief   The line number of the source code of the message. */
            std::string msg;                    /** @brief   The message itself. */
        };

        static const std::string LOG_DEFAULT_NAME;

        /**
            * @fn  void Log::LogMessage(const std::string& cppFile, const std::string& method, int line, const std::string& msg, LogLevel logLevel) const;
            *
            * @brief   Logs a time-stamped message.
            *
            * @param   cppFile     The source file name which generated this message.
            * @param   method      The calling method which generated this message.
            * @param   line        The source code line number.
            * @param   msg         The message to display.
            * @param   logLevel    Level of message being displayed. (error,warning,info, etc)
            */
        void LogMessage(const std::string& cppFile, const std::string& method, int line, const std::string& msg, LogLevel logLevel) const;

        /**
            * @fn  void Log::LogMessage(LogLevel logLevel, const std::string& source, int line, const char* msg, ...) const;
            *
            * @brief   Little more sophisticated method for logging messages.  Allows for
            *           an unlimited number of parameters in a C-style printf syntax.
            *
            * @param   logLevel    - Type of message being displayed. (error,warning,info)
            * @param   source      - String identifier of the source of the message.
            * @param   line        - the line number.
            * @param   msg         - Printf - style format string.
            *                      @note
            *                      Max length of the string to be printed is 2048 characters.
            * @param   ...         Variable arguments providing additional information.
            */
        void LogMessage(LogLevel logLevel, const std::string& source, int line, const char* msg, ...) const;

        /**
            * @fn  void Log::LogMessage(LogLevel logLevel, const std::string& source, int line, const std::string& msg) const;
            *
            * @brief   Little more sophisticated method for logging messages.  Allows for
            *           an unlimited number of parameters in a C-style printf syntax.
            *
            * @param   logLevel    - Type of message being displayed. (error,warning,info)
            * @param   source      - String identifier of the source of the message.
            * @param   line        - the line number.
            * @param   msg         - std::string that has been formatted.
            *                      @note
            *                      Max length of the string to be printed is 2048 characters.
            */
        void LogMessage(LogLevel logLevel, const std::string& source, int line, const std::string& msg) const;

        /**
            * @fn  void Log::LogMessage(LogLevel logLevel, const std::string& source, int line, const char* msg, va_list list) const;
            *
            * @brief   Logs a time-stamped message.  Takes a variable-argument list
            *           (va_list) that was created with va_start.
            *
            * @param   logLevel    - Type of message being displayed. (error,warning,info)
            * @param   source      - String identifier of the source of the message.
            * @param   line        - line number or negative for unknown.
            * @param   msg         - Printf - style format string.
            * @param   list        - va_list created with va_start.
            *                      @note
            *                      Max length of the string to be printed is 2048 characters.
            */
        void LogMessage(LogLevel logLevel, const std::string& source, int line, const char* msg, va_list list) const;

        /**
            * @fn  void Log::LogMessage(LogLevel logLevel, const std::string &source, const char *msg, ...) const;
            *
            * @brief   Little more sophisticated method for logging messages.  Allows for
            *           an unlimited number of parameters in a C-style printf syntax.
            *
            * @param   logLevel    - Type of message being displayed. (error,warning,info)
            * @param   source      - String identifier of the source of the message.
            * @param   msg         - Printf - style format string.
            *                      @note
            *                      Max length of the string to be printed is 2048 characters.
            * @param   ...         Variable arguments providing additional information.
            */
        void LogMessage(LogLevel logLevel, const std::string &source, const char *msg, ...) const;

        /**
            * @fn  void Log::LogHorizRule();
            *
            * @brief   Inserts a horizontal rule into the log file.
            */
        void LogHorizRule();

        /**
            * @fn  bool Log::IsLevelEnabled(LogLevel logLevel) const;
            *
            * @brief   Queries if a level is enabled.
            *
            * @param   logLevel    the type of message to query about.
            *
            * @return  true if log messages of the given level will be sent to the log output.
            */
        bool IsLevelEnabled(LogLevel logLevel) const;

        /**
            * @fn  void Log::SetLogLevel(LogLevel logLevel);
            *
            * @brief   Sets the lowest level of logging that will be logged. If the level in set to Debug,
            *          all messages will be sent. If the level is set error, only errors will be sent.
            *
            * @param   logLevel    the new logging level.
            */
        void SetLogLevel(LogLevel logLevel);

        /**
            * @fn  LogLevel Log::GetLogLevel() const;
            *
            * @brief   Gets log level.
            *
            * @return  the lowest level of logging that will be logged.
            */
        LogLevel GetLogLevel() const;

        /**
            * @fn  static const std::string Log::GetLogLevelString(LogLevel logLevel);
            *
            * @brief   Gets log level string.
            *
            * @param   logLevel    The log level.
            *
            * @return  a string version of a LogLevel.
            */
        static const std::string GetLogLevelString(LogLevel logLevel);

        /**
            * @fn  static LogLevel Log::GetLogLevelForString(const std::string& levelString);
            *
            * @brief   Gets log level for string.
            *
            * @param   levelString The level string.
            *
            * @return  the LogLevel matching a string or WARNING if there is no match.
            */
        static LogLevel GetLogLevelForString(const std::string& levelString);

        /**
            * @fn  static Log& Log::GetInstance(const std::string& name = Log::LOG_DEFAULT_NAME);
            *
            * @brief   Retrieve singleton instance of the log class for a give string name. WARNING:  If the
            *          log instance does not exist yet, it will be created, but the creation is not thread
            *          safe. If you intend to use a log instance in multithreaded code, which I hope you do,
            *          make sure to create the instance ahead of time by calling get instance.
            *
            * @param   name    (Optional) The logger name.
            *
            * @return  The instance.
            */
        static Log& GetInstance(const std::string& name = Log::LOG_DEFAULT_NAME);

        /**
            * @fn  static void Log::SetDefaultLogLevel(LogLevel newLevel);
            *
            * @brief   Sets the default LogLevel for new logs.
            *
            * @param   newLevel    The new level.
            */
        static void SetDefaultLogLevel(LogLevel newLevel);

        /**
            * @fn  static void Log::SetAllLogLevels(LogLevel newLevel);
            *
            * @brief   Set the LogLevel for all existing Log instances.
            *
            * @param   newLevel    The new level.
            *
            * @sa  SetLogLevel()
            */
        static void SetAllLogLevels(LogLevel newLevel);

        /**
            * @fn  static void Log::SetLogTimeProvider(LogTimeProvider* ltp);
            *
            * @brief   This sets a Log time source.  This allows another part of the system to update and
            *          provide both a time and a frame number, as needed.  Otherwise, the time will be set
            *          on the log data every time log is called.
            *
            * @param [in,out]  ltp If non-null, the ltp.
            */
        static void SetLogTimeProvider(LogTimeProvider* ltp);

        /**
            * @fn  void Log::AddWriter(LogWriter& writer);
            *
            * @brief   Add an writer that receives all log messages via callback.  The TO_WRITER
            *          OutputStreamOptions bit must be set in order for LogWriters to get triggered.
            *
            * @sa  RemoveWriter()
            *
            * @param [in,out]  writer  The LogWriter to register.
            *
            * @sa  SetOutputStreamBit()
            */
        void AddWriter(LogWriter& writer);

        /**
            * @fn  void Log::RemoveWriter(LogWriter& writer);
            *
            * @brief   Remove an existing LogWriter from the container.
            *
            * @param [in,out]  writer  The LogWriter to remove.
            *
            * @sa  AddWriter()
            */
        void RemoveWriter(LogWriter& writer);

        /** @brief   The log writer container. */
        using LogWriterContainer = std::vector<osg::ref_ptr<LogWriter>>;

        /**
            * @fn  const LogWriterContainer& Log::GetWriters() const;
            *
            * @brief   Get all registered LogWriters that are registered to receive log messages.
            *
            * @return  The container of LogWriters (could be empty)
            */
        const LogWriterContainer& GetWriters() const;

        /**
            * @fn  LogWriterContainer& Log::GetWriters();
            *
            * @brief   Get all registered LogWriters that are registered to receive log messages.
            *
            * @return  The container of LogWriters (could be empty)
            */
        LogWriterContainer& GetWriters();

        /**
            * @enum    OutputStreamOptions
            *
            * @brief   Values that represent output stream options.
            */
        enum OutputStreamOptions
        {
            NO_OUTPUT = 0x00000000, /* Log messages don't get written to any device*/
            TO_FILE = 0x00000001,   /* Log messages get sent to the output file*/
            TO_CONSOLE = 0x00000002,/* Log messages get sent to the console*/
            TO_WRITER = 0x00000004,/* Log messages get sent to all registered writers*/
            STANDARD = TO_FILE | TO_CONSOLE | TO_WRITER /* The default setting*/
        };

        /**
            * @fn  void Log::SetOutputStreamBit(unsigned int option);
            *
            * @brief   Tell the Log where to send output messages.  The supplied parameter is a
            *           bitwise combination of OutputStreamOptions.  The default is STANDARD, which directs
            *           messages to both the console and the output file. For example, to tell the Log to
            *           output to the file and console: \code
            *            trUtil::Logging::Log::GetInstance().SetOutputStreamBit(trUtil::Logging::Log::TO_FILE
            *            | trUtil::Logging::Log::TO_CONSOLE);
            *           \endcode \param option A bitwise combination of options.
            *
            * @param   option  The option.
            */
        void SetOutputStreamBit(unsigned int option);

        /**
            * @fn  static void Log::SetAllOutputStreamBits(unsigned int option);
            *
            * @brief   The same as above, but it sets the bits on ALL active log instances.
            *
            * @param   option  The option.
            */
        static void SetAllOutputStreamBits(unsigned int option);

        /**
            * @fn  unsigned int Log::GetOutputStreamBit() const;
            *
            * @brief   Get the currently defined output stream options.
            *
            * @return  The output stream bit.
            */
        unsigned int GetOutputStreamBit() const;

        /**
            * @fn  const std::string& Log::GetName() const;
            *
            * @brief   Returns the name of this logger.
            *
            * @return  The name.
            */
        const std::string& GetName() const;

        /**
            * @fn  LogManager& Log::GetLogManagerRef();
            *
            * @brief   Returns a reference to the internal Log Manager.
            *
            * @return  The log manager reference.
            */
        LogManager& GetLogManagerRef();

        /**
         * @fn  void Log::SetTestMode(bool state);
         *
         * @brief   Enables the use of unit test mode which enables capturing of certain data.
         *
         * @param   state   True to state.
         */
        void SetTestMode(bool state);

        /**
         * @fn  const LogTestData* Log::GetLastLogData() const;
         *
         * @brief   Gets the last log data that was in the queue for testing.
         *
         * @return  Null if it fails, else the last log data.
         */
        const LogTestData* GetLastLogData() const;

    protected:

        /**
            * @fn  Log::Log(const std::string& name);
            *
            * @brief   Opens the log file and writes the html header information. All new logs are created
            *          with the global default log level.
            *
            * @param   name    The name.
            */
        Log(const std::string& name);

        /**
            * @fn  Log::~Log();
            *
            * @brief   Writes any closing html tags and closes the log file.
            */
        ~Log();

    private:
        LogImpl* mImpl;

        bool mTestingMode = false;
        mutable LogTestData mLogTestData;
    };

    /**
        * @class   LoggingOff
        *
        * @brief   Scoped variable to turn off logging (except for always) for a block of code. This is
        *          useful for testing, and for temporary disabling of logging in certain areas.
        */
    class TR_UTIL_EXPORT LoggingOff
    {
    public:

        /**
            * @fn  LoggingOff::LoggingOff(const std::string& name = Log::LOG_DEFAULT_NAME);
            *
            * @brief   Constructor.
            *
            * @param   name    (Optional) The name.
            */
        LoggingOff(const std::string& name = Log::LOG_DEFAULT_NAME);

        /**
            * @fn  LoggingOff::~LoggingOff();
            *
            * @brief   Destructor.
            */
        ~LoggingOff();
    private:
        trUtil::Logging::Log& mLog;
        LogLevel mOldLevel;
    };
}