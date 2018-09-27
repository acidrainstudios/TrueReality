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

#include <trUtil/ApplicationUsage.h>
#include <trUtil/ArgumentParser.h>

#include <osg/ArgumentParser>
#include <osg/ref_ptr>

#include <memory>
#include <map>

/**
 * @namespace   trUtil
 *
 * @brief   Namespace that holds various utility classes for the engine
 */
namespace trUtil
{
    /**
     * @class   ArgumentParser
     *
     * @brief   A a command line argument parser class that helps to create, manage, and pass commands to other systems
     */
    class TR_UTIL_EXPORT ArgumentParser
    {
    public:

        enum class ErrorSeverity
        {
            BENIGN = osg::ArgumentParser::ErrorSeverity::BENIGN,
            CRITICAL = osg::ArgumentParser::ErrorSeverity::CRITICAL
        };

        using ErrorMessageMap = std::map<std::string, ErrorSeverity>;

        class TR_UTIL_EXPORT Parameter
        {
        public:

            /**
             * @fn  Parameter::Parameter(bool& value);
             *
             * @brief   Constructor.
             *
             * @param [in,out]  value   The value.
             */
            Parameter(bool& value);

            /**
             * @fn  Parameter::Parameter(float& value);
             *
             * @brief   Constructor.
             *
             * @param [in,out]  value   The value.
             */
            Parameter(float& value);

            /**
             * @fn  Parameter::Parameter(double& value);
             *
             * @brief   Constructor.
             *
             * @param [in,out]  value   The value.
             */
            Parameter(double& value);

            /**
             * @fn  Parameter::Parameter(int& value);
             *
             * @brief   Constructor.
             *
             * @param [in,out]  value   The value.
             */
            Parameter(int& value);

            /**
             * @fn  Parameter::Parameter(unsigned int& value);
             *
             * @brief   Constructor.
             *
             * @param [in,out]  value   The value.
             */
            Parameter(unsigned int& value);

            /**
             * @fn  Parameter::Parameter(std::string& value);
             *
             * @brief   Constructor.
             *
             * @param [in,out]  value   The value.
             */
            Parameter(std::string& value);

            /**
             * @fn  Parameter::Parameter(const Parameter& param);
             *
             * @brief   Copy constructor.
             *
             * @param   param   The parameter.
             */
            Parameter(const Parameter& param);

            /**
             * @fn  Parameter::~Parameter();
             *
             * @brief   Destructor.
             */
            ~Parameter();

            /**
             * @fn  Parameter& Parameter::operator= (const Parameter& param);
             *
             * @brief   Assignment operator.
             *
             * @param   param   The parameter.
             *
             * @return  A shallow copy of this object.
             */
            Parameter& operator = (const Parameter& param);

            /**
             * @fn  bool Parameter::Valid(const char* str) const;
             *
             * @brief   Checks if this parameter is Valid.
             *
             * @param   str The string.
             *
             * @return  True if it succeeds, false if it fails.
             */
            bool Valid(const char* str) const;

            /**
             * @fn  bool Parameter::Assign(const char* str);
             *
             * @brief   Assigns the given string value to the parameter.
             *
             * @param   str The string.
             *
             * @return  True if it succeeds, false if it fails.
             */
            bool Assign(const char* str);

            /**
             * @fn  operator osg::ArgumentParser::Parameter () const;
             *
             * @brief   Cast that converts the given  to a Parameter.
             *
             * @return  The result of the operation.
             */
            operator osg::ArgumentParser::Parameter() const;

            /**
             * @fn  operator osg::ArgumentParser::Parameter& ();
             *
             * @brief   Cast that converts the given  to a Parameter&amp;
             *
             * @return  The result of the operation.
             */
            operator osg::ArgumentParser::Parameter& ();

            /**
             * @fn  operator const osg::ArgumentParser::Parameter& () const;
             *
             * @brief   Gets the parameter&amp;
             *
             * @return  A const.
             */
            operator const osg::ArgumentParser::Parameter& () const;

            /**
             * @fn  operator osg::ArgumentParser::Parameter* ();
             *
             * @brief   Parameter* casting operator.
             *
             * @return  The result of the operation.
             */
            operator osg::ArgumentParser::Parameter* ();


        protected:

            osg::ArgumentParser::Parameter* mParam;
        };

        /**
         * @fn  ArgumentParser::ArgumentParser(int* argc, char **argv);
         *
         * @brief   Default constructor that takes the argc and argv from the main function for command line parsing.
         *
         * @param [in,out]  argc    If non-null, the argc.
         * @param [in,out]  argv    If non-null, the argv.
         */
        ArgumentParser(int* argc, char **argv);

        /**
         * @fn  ArgumentParser::~ArgumentParser();
         *
         * @brief   Destructor.
         */
        ~ArgumentParser();

        /**
         * @fn  osg::ArgumentParser& ArgumentParser::GetOSGArgumentParser();
         *
         * @brief   Gets internal osg argument parser.
         *
         * @return  The osg argument parser.
         */
        osg::ArgumentParser& GetOSGArgumentParser();

        /**
         * @fn  const osg::ArgumentParser& ArgumentParser::GetOSGArgumentParser() const;
         *
         * @brief   Gets the internal osg argument parser.
         *
         * @return  The osg argument parser.
         */
        const osg::ArgumentParser& GetOSGArgumentParser() const;

        /**
         * @fn  bool ArgumentParser::IsOption(const char* str) const;
         *
         * @brief   Return true if the specified string is an option in the form
         *          -option or --option.
         *
         * @param   str The string.
         *
         * @return  True if option, false if not.
         */
        bool IsOption(const char* str) const;

        /**
         * @fn  bool ArgumentParser::IsString(const char* str) const;
         *
         * @brief   Return true if string is non-NULL and not an option in the form
         *          -option or --option.
         *
         * @param   str The string.
         *
         * @return  True if string, false if not.
         */
        bool IsString(const char* str) const;

        /**
         * @fn  bool ArgumentParser::IsNumber(const char* str) const;
         *
         * @brief   Return true if specified parameter is a number.
         *
         * @param   str The string.
         *
         * @return  True if number, false if not.
         */
        bool IsNumber(const char* str) const;

        /**
         * @fn  bool ArgumentParser::IsBool(const char* str) const;
         *
         * @brief   Return true if specified parameter is a bool.
         *
         * @param   str The string.
         *
         * @return  True if bool, false if not.
         */
        bool IsBool(const char* str) const;

        /**
         * @fn  void ArgumentParser::SetApplicationUsage(ApplicationUsage* usage);
         *
         * @brief   Sets application usage.
         *
         * @param [in,out]  usage   If non-null, the usage.
         */
        void SetApplicationUsage(ApplicationUsage* usage);

        /**
         * @fn  ApplicationUsage* ArgumentParser::GetApplicationUsage();
         *
         * @brief   Gets application usage.
         *
         * @return  Null if it fails, else a pointer to an ApplicationUsage.
         */
        ApplicationUsage* GetApplicationUsage();

        /**
         * @fn  const ApplicationUsage* ArgumentParser::GetApplicationUsage() const;
         *
         * @brief   Gets application usage.
         *
         * @return  Null if it fails, else the application usage.
         */
        const ApplicationUsage* GetApplicationUsage() const;

        /**
         * @fn  int& ArgumentParser::GetArgc();
         *
         * @brief   Return the argument count.
         *
         * @return  The argc.
         */
        int& GetArgc();

        /**
         * @fn  char** ArgumentParser::GetArgv();
         *
         * @brief   Return the argument array.
         *
         * @return  Null if it fails, else the argv.
         */
        char** GetArgv();

        /**
         * @fn  std::string ArgumentParser::GetApplicationName() const;
         *
         * @brief   Return the application name, as specified by argv[0].
         *
         * @return  The application name.
         */
        std::string GetApplicationName() const;

        /**
         * @fn  int ArgumentParser::Find(const std::string& str) const;
         *
         * @brief   Return the position of an occurrence of a string in the argument list. Return -1 if
         *          no string is found.
         *
         * @param   str The string.
         *
         * @return  An int.
         */
        int Find(const std::string& str) const;

        /**
         * @fn  bool ArgumentParser::IsOption(int pos) const;
         *
         * @brief   Return true if the specified parameter is an option in the form of
         *          -option or --option.
         *
         * @param   pos The position.
         *
         * @return  True if option, false if not.
         */
        bool IsOption(int pos) const;

        /**
         * @fn  bool ArgumentParser::IsString(int pos) const;
         *
         * @brief   Return true if the specified parameter is a string not in the form of an option.
         *
         * @param   pos The position.
         *
         * @return  True if string, false if not.
         */
        bool IsString(int pos) const;

        /**
         * @fn  bool ArgumentParser::IsNumber(int pos) const;
         *
         * @brief   Return true if the specified parameter is a number.
         *
         * @param   pos The position.
         *
         * @return  True if number, false if not.
         */
        bool IsNumber(int pos) const;

        /**
         * @fn  bool ArgumentParser::ContainsOptions() const;
         *
         * @brief   Query if this object contains options.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool ContainsOptions() const;

        /**
         * @fn  void ArgumentParser::Remove(int pos, int num = 1);
         *
         * @brief   Remove one or more arguments from the argv argument list, and decrement the argc
         *          respectively.
         *
         * @param   pos The position.
         * @param   num (Optional) Number of.
         */
        void Remove(int pos, int num = 1);

        /**
         * @fn  bool ArgumentParser::Match(int pos, const std::string& str) const;
         *
         * @brief   Return true if the specified argument matches the given string.
         *
         * @param   pos The position.
         * @param   str The string.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Match(int pos, const std::string& str) const;

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str The String to read.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         * @param   value2  The second value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1, Parameter value2);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         * @param   value6  The value 6.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         * @param   value6  The value 6.
         * @param   value7  The value 7.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7);

        /**
         * @fn  bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7, Parameter value8);
         *
         * @brief   Search for an occurrence of a string in the argument list. If found,
         *              remove that occurrence and return true. Otherwise, return false.
         *
         * @param   str     The String to read.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         * @param   value6  The value 6.
         * @param   value7  The value 7.
         * @param   value8  The value 8.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7, Parameter value8);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos The position.
         * @param   str The string.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         * @param   value2  The second value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1, Parameter value2);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         * @param   value6  The sixth value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         * @param   value6  The sixth value.
         * @param   value7  The seventh value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7);

        /**
         * @fn  bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7, Parameter value8);
         *
         * @brief   If the argument value at the specified position matches the given string, and
         *          subsequent parameters are also matched, then set the parameter values, remove the
         *          arguments from the list, and return true. Otherwise, return false.
         *
         * @param   pos     The position.
         * @param   str     The string.
         * @param   value1  The first value.
         * @param   value2  The second value.
         * @param   value3  The third value.
         * @param   value4  The fourth value.
         * @param   value5  The fifth value.
         * @param   value6  The sixth value.
         * @param   value7  The seventh value.
         * @param   value8  The eighth value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7, Parameter value8);

        /**
         * @fn  bool ArgumentParser::Errors(ErrorSeverity severity = BENIGN) const;
         *
         * @brief   Return the error flag, true if an error has occurred when reading arguments.
         *
         * @param   severity    (Optional) The severity.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Errors(ErrorSeverity severity = ErrorSeverity::BENIGN) const;

        /**
         * @fn  void ArgumentParser::ReportError(const std::string& message, ErrorSeverity severity = ErrorSeverity::CRITICAL);
         *
         * @brief   Report an error message by adding to the ErrorMessageMap.
         *
         * @param   message     The message.
         * @param   severity    (Optional) The severity.
         */
        void ReportError(const std::string& message, ErrorSeverity severity = ErrorSeverity::CRITICAL);

        /**
         * @fn  void ArgumentParser::ReportRemainingOptionsAsUnrecognized(ErrorSeverity severity = ErrorSeverity::BENIGN);
         *
         * @brief   For each remaining option, report it as unrecognized.
         *
         * @param   severity    (Optional) The severity.
         */
        void ReportRemainingOptionsAsUnrecognized(ErrorSeverity severity = ErrorSeverity::BENIGN);

        /**
         * @fn  void ArgumentParser::WriteErrorMessages(std::ostream& output, ErrorSeverity severity = ErrorSeverity::BENIGN);
         *
         * @brief   Write error messages to the given ostream, if at or above the given severity.
         *
         * @param [in,out]  output      The output.
         * @param           severity    (Optional) The severity.
         */
        void WriteErrorMessages(std::ostream& output, ErrorSeverity severity = ErrorSeverity::BENIGN);

        /**
         * @fn  ApplicationUsage::Type ArgumentParser::ReadHelpType();
         *
         * @brief   This convenience method handles help requests on the command line. Return the type(s)
         *          of help requested. The return value of this function is suitable for passing into
         *          getApplicationUsage()->write(). If ApplicationUsage::NO_HELP is returned then no help
         *          commandline option was found on the command line.
         *
         * @return  The help type.
         */
        ApplicationUsage::Type ReadHelpType();

        /**
         * @fn  void ArgumentParser::SetApplicationName(const std::string& name);
         *
         * @brief   Sets the Applications Name. It is used in Application description.
         *
         * @param   name    The name.
         */
        void SetApplicationName(const std::string& name);

        /**
         * @fn  void ArgumentParser::SetDescription(const std::string& desc);
         *
         * @brief   If non-empty, the Description is typically shown by the Help Handler as text on the
         *          Help display (which also lists keyboard abbreviations.)
         *
         * @param   desc    The description.
         */
        void SetDescription(const std::string& desc);

        /**
         * @fn  const std::string& ArgumentParser::GetDescription() const;
         *
         * @brief   Gets the description.
         *
         * @return  The description.
         */
        const std::string& GetDescription() const;

        /**
         * @fn  void ArgumentParser::AddUsageExplanation(ApplicationUsage::Type type, const std::string& option, const std::string& explanation);
         *
         * @brief   Adds an usage explanation.
         *
         * @param   type        The type.
         * @param   option      The option.
         * @param   explanation The explanation.
         */
        void AddUsageExplanation(ApplicationUsage::Type type, const std::string& option, const std::string& explanation);

        /**
         * @fn  void ArgumentParser::SetCommandLineUsage(const std::string& explanation);
         *
         * @brief   Sets command line usage.
         *
         * @param   explanation The explanation.
         */
        void SetCommandLineUsage(const std::string& explanation);

    protected:

        /** @brief   The argument parser. */
        std::unique_ptr<osg::ArgumentParser> mArgParser;
        std::unique_ptr<ApplicationUsage> mAppUsage;
    };
}