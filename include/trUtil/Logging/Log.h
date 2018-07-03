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

#include <trUtil/Logging/LogFile.h>
#include <trUtil/Logging/LogLevel.h>

#include <string>
#include <cstdarg>
#include <vector>
#include <ostream>

#include <osg/Referenced>
#include <osg/ref_ptr>


namespace trUtil
{
    namespace Logging
    {
        // Fwd declaration
        class LogWriter;
        class LogTimeProvider;
        class LogManager;
        class LogImpl;

        /**
        * Helps making logging a little easier.  However, if printf style
        *   logging is desired, you cannot use this macro.
        */
#define TR_LOG_SOURCE __FILE__, __FUNCTION__, __LINE__

        /**
        * Logging macro to make error recording esier.
        *
        * @param level - Level of Logging (ERROR, WARNING, etc)
        * @param name - Name of the Log file
        * @param msg - Message to log
        */
#define LOG_FULL(level, name, msg) \
        {\
        trUtil::Logging::Log& _logger = trUtil::Logging::Log::GetInstance(name); \
        if (_logger.IsLevelEnabled(level)) \
        _logger.LogMessage(TR_LOG_SOURCE, msg, level); \
        }\

        /**
        * Log a DEBUG message
        *
        * @param name - Log File Name
        * @param msg - Message to log
        */
#define LOGN_D(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_DEBUG, name, msg)

        /**
        * Log an INFO message
        *
        * @param name - Log File Name
        * @param msg - Message to log
        */
#define LOGN_I(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_INFO, name, msg)

        /**
        * Log a WARNING message
        *
        * @param name - Log File Name
        * @param msg - Message to log
        */
#define LOGN_W(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_WARNING, name, msg)

        /**
        * Log an ERROR message
        *
        * @param name - Log File Name
        * @param msg - Message to log
        */
#define LOGN_E(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_ERROR, name, msg)

        /**
        * Log an ALWAYS message
        *
        * @param name - Log File Name
        * @param msg - Message to log
        */
#define LOGN_A(name, msg) LOG_FULL(trUtil::Logging::LogLevel::LOG_ALWAYS, name, msg)

        /**
        * Log a DEBUG message
        *
        * @param msg - Message to log
        */
#define LOG_D(msg) LOGN_D(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

        /**
        * Log an INFO message
        *
        * @param msg - Message to log
        */
#define LOG_I(msg) LOGN_I(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

        /**
        * Log a WARNING message
        *
        * @param msg - Message to log
        */
#define LOG_W(msg) LOGN_W(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

        /**
        * Log an ERROR message
        *
        * @param msg - Message to log
        */
#define LOG_E(msg) LOGN_E(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

        /**
        * Log an ALWAYS message
        *
        * @param msg - Message to log
        */
#define LOG_A(msg) LOGN_A(trUtil::Logging::Log::LOG_DEFAULT_NAME, msg)

        /**
        * Prints out a message to the Logger with a test string for every log level
        * Only the currently enabled log levels will be visible
        * The Log messages will only go to the enabled Log Writers
        * This would be used for testing and development.
        */
#define LOG_PRINT_TEST \
        LOG_D("Test Message") \
        LOG_I("Test Message") \
        LOG_W("Test Message") \
        LOG_E("Test Message") \
        LOG_A("Test Message")

        /**
        * Log class which the engine uses for all of its logging
        * needs.  The log file is formatted using html tags,
        * therefore, any browser should display the log without
        *  any problems.
        */
        class TR_UTIL_EXPORT Log : public osg::Referenced
        {
        public:
            static const std::string LOG_DEFAULT_NAME;

            /**
            * Logs a time-stamped message.
            * @param file - The source file name which generated this message
            * @param method The calling method which generated this message
            * @param line The source code line number.
            * @param msg The message to display.
            * @param logLevel Level of message being displayed. (error,warning,info, etc)
            */
            void LogMessage(const std::string& file, const std::string& method,
                int line, const std::string& msg,
                LogLevel logLevel) const;

            /**
            * Little more sophisticated method for logging messages.  Allows for
            *  an unlimited number of parameters in a C-style printf syntax.
            *  @param logLevel - Type of message being displayed. (error,warning,info)
            *  @param source - String identifier of the source of the message.
            *  @param line - the line number.
            *  @param msg - Printf - style format string.
            *  @note
            *      Max length of the string to be printed is 2048 characters.
            */
            void LogMessage(LogLevel logLevel, const std::string& source, int line,
                const char* msg, ...) const;

            /**
            * Little more sophisticated method for logging messages.  Allows for
            *  an unlimited number of parameters in a C-style printf syntax.
            *  @param logLevel - Type of message being displayed. (error,warning,info)
            *  @param source - String identifier of the source of the message.
            *  @param line - the line number.
            *  @param msg - std::string that has been formatted.
            *  @note
            *      Max length of the string to be printed is 2048 characters.
            */
            void LogMessage(LogLevel logLevel, const std::string& source, int line,
                const std::string& msg) const;

            /**
            * Logs a time-stamped message.  Takes a variable-argument list
            *  (va_list) that was created with va_start.
            *  @param logLevel - Type of message being displayed. (error,warning,info)
            *  @param source - String identifier of the source of the message.
            *  @param line  - line number or negative for unknown.
            *  @param msg - Printf - style format string.
            *  @param list - va_list created with va_start.
            *  @note
            *      Max length of the string to be printed is 2048 characters.
            */
            void LogMessage(LogLevel logLevel, const std::string& source, int line,
                const char* msg, va_list list) const;

            /**
            * Little more sophisticated method for logging messages.  Allows for
            *  an unlimited number of parameters in a C-style printf syntax.
            *  @param logLevel - Type of message being displayed. (error,warning,info)
            *  @param source - String identifier of the source of the message.
            *  @param msg - Printf - style format string.
            *  @note
            *      Max length of the string to be printed is 2048 characters.
            */
            void LogMessage(LogLevel logLevel, const std::string &source,
                const char *msg, ...) const;
            /**
            * Inserts a horizontal rule into the log file.
            */
            void LogHorizRule();

            /**
            * @return true if log messages of the given level will be sent to the log
            * output
            * @param logLevel the type of message to query about.
            */
            bool IsLevelEnabled(LogLevel logLevel) const;

            /**
            * Sets the lowest level of logging that will be logged.
            * If the level in set to Debug, all messages will be sent. If the level is set error, only
            * errors will be sent.
            * @param logLevel the new logging level
            */
            void SetLogLevel(LogLevel logLevel);

            /**
            * @return the lowest level of logging that will be logged.
            */
            LogLevel GetLogLevel() const;

            ///@return a string version of a LogLevel.
            static const std::string GetLogLevelString(LogLevel logLevel);

            ///@return the LogLevel matching a string or WARNING if there is no match.
            static LogLevel GetLogLevelForString(const std::string& levelString);

            /*
            * Retrieve singleton instance of the log class for a give string name.
            *
            * WARNING:  If the log instance does not exist yet, it will be created, but the creation is not thread safe.
            *           If you intend to use a log instance in multithreaded code, which I hope you do, make sure to create
            *           the instance ahead of time by calling get instance.
            *
            * @param name logger name
            */
            static Log& GetInstance(const std::string& name = Log::LOG_DEFAULT_NAME);

            /**
            * Sets the default LogLevel for new logs
            */
            static void SetDefaultLogLevel(LogLevel newLevel);

            /**
            *  Set the LogLevel for all existing Log instances.
            *  @see SetLogLevel()
            */
            static void SetAllLogLevels(LogLevel newLevel);

            /**
            * This sets a Log time source.  This allows another part of the system to update and provide
            * both a time and a frame number, as needed.  Otherwise, the time will be set on the log data every
            * time log is called.
            */
            static void SetLogTimeProvider(LogTimeProvider* ltp);

            /**
            *  Add an writer that receives all log messages via callback.  The
            *  TO_WRITER OutputStreamOptions bit must be set in order for LogWriters
            *  to get triggered.
            *  @see SetOutputStreamBit()
            *  @see RemoveWriter()
            *  @param writer The LogWriter to register
            */
            void AddWriter(LogWriter& writer);

            /**
            * Remove an existing LogWriter from the container.
            * @see AddWriter()
            * @param writer The LogWriter to remove
            */
            void RemoveWriter(LogWriter& writer);

            typedef std::vector<osg::ref_ptr<LogWriter> > LogWriterContainer;

            /**
            *  Get all registered LogWriters that are registered to receive log messages.
            *  @return The container of LogWriters (could be empty)
            */
            const LogWriterContainer& GetWriters() const;

            /**
            *  Get all registered LogWriters that are registered to receive log messages.
            *  @return The container of LogWriters (could be empty)
            */
            LogWriterContainer& GetWriters();

            enum OutputStreamOptions
            {
                NO_OUTPUT = 0x00000000, ///<Log messages don't get written to any device
                TO_FILE = 0x00000001,   ///<Log messages get sent to the output file
                TO_CONSOLE = 0x00000002,///<Log messages get sent to the console
                TO_WRITER = 0x00000004,///<Log messages get sent to all registered writers
                STANDARD = TO_FILE | TO_CONSOLE | TO_WRITER ///<The default setting
            };

            /** Tell the Log where to send output messages.  The supplied parameter is a
            *  bitwise combination of OutputStreamOptions.  The default is STANDARD, which
            *  directs messages to both the console and the output file.
            *  For example, to tell the Log to output to the file and console:
            *  \code
            *   trUtil::Logging::Log::GetInstance().SetOutputStreamBit(trUtil::Logging::Log::TO_FILE | trUtil::Logging::Log::TO_CONSOLE);
            *  \endcode
            *  \param option A bitwise combination of options.
            */
            void SetOutputStreamBit(unsigned int option);

            /**
            * The same as above, but it sets the bits on ALL active log instances.
            */
            static void SetAllOutputStreamBits(unsigned int option);

            ///Get the currently defined output stream options
            unsigned int GetOutputStreamBit() const;

            ///Returns the name of this logger.
            const std::string& GetName() const;

            /**
            * Returns a reference to the internal Log Manager
            */
            LogManager& GetLogManagerRef();

            //std::ostream& operator()(const std::string& file, const std::string& method, int line, LogLevel logLevel);

            //Constructor and destructor are both protected since this is a singleton.
        protected:
            /**
            * Opens the log file and writes the html header information.
            * All new logs are created with the global default log level.
            */
            Log(const std::string& name);

            /**
            * Writes any closing html tags and closes the log file.
            */
            ~Log();

        private:
            LogImpl* mImpl;
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
            LoggingOff(const std::string& name = Log::LOG_DEFAULT_NAME);
            ~LoggingOff();
        private:
            trUtil::Logging::Log& mLog;
            LogLevel mOldLevel;
        };
    }
}
