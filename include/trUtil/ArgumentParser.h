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

#include <trUtil/ArgumentParser.h>

#include <osg/ArgumentParser>
#include <osg/ref_ptr>

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
            operator osg::ArgumentParser::Parameter () const;

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

        protected:            
            osg::ArgumentParser* mArgParserPtr = nullptr;
    };
}