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
* @author David Guthrie
* @author John K. Grant
* @author William E. Johnson II
* @author Chris Osborn
* @author Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/UnaryFunction.h>
#include <trUtil/WarningUtils.h>

#include <string>
#include <sstream>
#include <locale>
#include <vector>
#include <algorithm>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::StringUtils
{
    class IsSpace;

    /** @brief   Constant value for a blank String. */
    static const std::string STR_BLANK("");

    /**
        * @class   StringTokenizer
        *
        * @brief   The predicate should evaluate to true when applied to a separator.
        */
    template <class Pred = IsSpace>
    class StringTokenizer
    {
    public:

        /**
            * @fn  static void StringTokenizer::tokenize(std::vector<std::string>& tokens, const std::string& stringToParse, const Pred& predFxn = Pred());
            *
            * @brief   The predicate should evaluate to true when applied to a separator.
            *
            * @param [in,out]  tokens          The tokens.
            * @param           stringToParse   The string to parse.
            * @param           predFxn         (Optional) The predicate fxn.
            */
        static void tokenize(std::vector<std::string>& tokens, const std::string& stringToParse, const Pred& predFxn = Pred());

        /**
            * @fn  static void StringTokenizer::tokenize(std::vector<std::string>& tokens, const std::string& stringToParse, const std::string& delimiter);
            *
            * @brief   The predicate should evaluate to true when applied to a separator.
            *
            * @param [in,out]  tokens          The tokens.
            * @param           stringToParse   The string to parse.
            * @param           delimiter       The predicate fxn.
            */
        static void tokenize(std::vector<std::string>& tokens, const std::string& stringToParse, const std::string& delimiter);
    };

    /**
        * @fn  inline void StringTokenizer<Pred>::tokenize(std::vector<std::string>& tokens, const std::string& stringToParse, const Pred& predFxn)
        *
        * @brief   The predicate should evaluate to true when applied to a separator.
        *
        * @tparam  Pred    Type of the predicate.
        * @param [in,out]  tokens          The tokens.
        * @param           stringToParse   The string to parse.
        * @param           predFxn         The predicate fxn.
        */
    template <class Pred>
    inline void StringTokenizer<Pred>::tokenize(std::vector<std::string>& tokens, const std::string& stringToParse, const Pred& predFxn)
    {
        //First clear the results std::vector
        tokens.clear();
        std::string::const_iterator it = stringToParse.begin();
        std::string::const_iterator itTokenEnd = stringToParse.begin();
        while (it != stringToParse.end())
        {
            //Eat separators
            if (predFxn(*it))
            {
                it++;
            }
            else
            {
                //Find next token
                itTokenEnd = std::find_if(it, stringToParse.end(), predFxn);
                //Append token to result
                if (it < itTokenEnd)
                {
                    tokens.push_back(std::string(it, itTokenEnd));
                }
                it = itTokenEnd;
            }
        }
    }        

    /**
        * @class   IsSpace
        *
        * @brief   A functor which tests if a character is whitespace. This "predicate" needed to
        *          have 'state', the locale member.
        */
    class TR_UTIL_EXPORT IsSpace : public trUtil::UnaryFunction<char, bool>
    {
        TR_DISABLE_WARNING_START_MSVC(4251)
    public:
        static const std::string DEFAULT_LOCALE_NAME;
        IsSpace(const std::locale& loc = std::locale(DEFAULT_LOCALE_NAME.c_str())) : mLocale(loc) {}

        const std::locale& GetLocale() const { return mLocale; }
        bool operator()(char c) const { return std::isspace(c, mLocale); }
        TR_DISABLE_WARNING_END
    private:
        std::locale mLocale;
    };

    /**
        * @class   IsSlash
        *
        * @brief   Determines if the current character is a forward slash.
        */
    class IsSlash : public trUtil::UnaryFunction<char, bool>
    {
    public:
        bool operator()(char c) const { return c == '/'; }
    };

    /**
        * @class   IsDelimeter
        *
        * @brief   Generic string delimeter check function class.  Based on the character passed to the
        *          constructor, this class will check for that character.
        */
    class IsDelimeter : public trUtil::UnaryFunction<char, bool>
    {
    public:
        IsDelimeter(char delim) : mDelimeter(delim) { }
        bool operator()(char c) const { return c == mDelimeter; }
    private:
        char mDelimeter;
    };

        /**
        * @fn const std::string& Trim(std::string& toTrim);
        *
        * @brief  Trims whitespace off the front and end of a string.
        *
        * @param [in,out] toTrim  the string to trim.
        *
        * @return A reference to a const std::string.
        */
    TR_UTIL_EXPORT const std::string& Trim(std::string& toTrim);

        /**
        * @fn int StrCompare(const std::string& one, const std::string& two, bool caseSensitive = true);
        *
        * @brief  Compares strings like strcmp or stricmp or strcasecmp.
        *
        * @param  one             the first string to compare.
        * @param  two             the string to compare one to.
        * @param  caseSensitive   (Optional) optional parameter to specify case sensitivity, which
        *                         defaults to on.
        *
        * @return 0 for equal, negative for one less that two, and positive for one > two.
        */
    TR_UTIL_EXPORT int StrCompare(const std::string& one, const std::string& two, bool caseSensitive = true);

        /**
        * @fn void ToLowerCase(std::string& str);
        *
        * @brief  Converts the whole string to lower case.
        *
        * @param [in,out] str The string.
        */
    TR_UTIL_EXPORT void ToLowerCase(std::string& str);

        /**
        * @fn std::string ToLowerCase(const std::string& str);
        *
        * @brief  Converts the whole string to lower case, slower version.
        *
        * @param  str The string.
        *
        * @return Str as a std::string.
        */
    TR_UTIL_EXPORT std::string ToLowerCase(const std::string& str);

        /**
        * @fn void ToUpperCase(std::string& str);
        *
        * @brief  Converts the whole string to upper case.
        *
        * @param [in,out] str The string.
        */
    TR_UTIL_EXPORT void ToUpperCase(std::string& str);

        /**
        * @fn std::string ToUpperCase(const std::string& str);
        *
        * @brief  Converts the whole string to upper case, slower version.
        *
        * @param  str The string.
        *
        * @return Str as a std::string.
        */
    TR_UTIL_EXPORT std::string ToUpperCase(const std::string& str);

    /**
        * @struct  StrCompareFunc
        *
        * @brief   A functor for using std::find or whatever that will compare two strings case
        *          sensitive or insensitive.
        */
    struct StrCompareFunc
    {
        /**
            * @fn  StrCompareFunc(const std::string& mainString, bool caseSensitive = true)
            *
            * @brief   Constructor.
            *
            * @param   mainString      The main string.
            * @param   caseSensitive   (Optional) True to case sensitive.
            */
        StrCompareFunc(const std::string& mainString, bool caseSensitive = true)
        : mString(mainString)
        , mCaseSensitive(caseSensitive)
        {
        }

        bool operator() (const std::string& toCompare)
        {
            return StrCompare(toCompare, mString, mCaseSensitive) == 0;
        }

        const std::string& mString;
        bool mCaseSensitive;
    };

    /**
        * @fn  bool ParseVec(const std::string& value, VecType& vec, unsigned size, unsigned numberPrecision = 16)
        *
        * @brief   A templated function for taking any of the osg vector types and reading the data from
        *          a string. If the string is empty or "NULL" it will set the vector to all 0s. It
        *          expects the data to be the proper number floating point values.  The function will
        *          fail if there are not enough values.
        *
        * @param           value           the string data.
        * @param [in,out]  vec             the vector to fill.
        * @param           size            the length of the vector since the osg types have no way to
        *                                  query that.
        * @param           numberPrecision (Optional) This value indicates how much precision the
        *                                  numbers will contain when read from the string.
        *                                  (setprecision on std::istream)
        *
        * @return  true if reading the data was successful or false if not.
        */
    template<class VecType>
    bool ParseVec(const std::string& value, VecType& vec, unsigned size, unsigned numberPrecision = 16)
    {
        bool result = true;
        unsigned int i;

        if (value.empty() || value == "NULL")
        {
            for (i = 0; i < size; ++i)
            {
                vec[i] = 0.0;
            }
        }
        else
        {
            std::istringstream iss(value);
            iss.precision(numberPrecision);
            for (i = 0; i < size && !iss.eof(); ++i)
            {
                iss >> vec[i];
            }

            //did we run out of data?
            if (i < size)
                result = false;
        }

        return result;
    }

    /**
        * @fn  std::string ToString(const T& t, int precision = -1)
        *
        * @brief   A utility function to convert a basic type into a string. Use template argument T for
        *          the type you'd like to convert.
        *
        * @param   t           the instance of the type to converted.
        *                      
        *                      Typical use:
        *                      @code
        *                      float num = 5.67f;
        *                      std::string mynum = StringUtils::ToString( num );
        *                      @endcode.
        * @param   precision   (Optional) The precision.
        *
        * @return  A std::string that represents this object.
        */
    template<typename T>
    std::string ToString(const T& t, int precision = -1)
    {
        std::ostringstream ss;
        if (precision > 0)
        {
            ss.precision(precision);
        }
        ss << t;
        return ss.str();
    }
        

    /**
        * @fn  T FromString(const std::string& u)
        *
        * @brief   Converts a string to a specified type.
        *
        * @param   u   string to be converted to the specified template argument type.
        *
        * @return  the type that you specify as the template argument.
        *          
        *          Typical use:
        *          @code
        *          std::string mystring("0");
        *          float myfloat = StringUtils::FromString&lt;float&gt;( mystring );
        *          @endcode.
        */
    template<typename T>
    T FromString(const std::string& u)
    {
        T result = T();
        std::istringstream is;
        is.str(u);
        is >> result;
        return result;
    }


    /**
        * @fn  bool FromString<bool>(const std::string& u);
        *
        * @brief   Special exception for bool where things like "True", "TRUE", and "true" should be
        *          accepted.
        *
        * @tparam  bool    Type of the bool.
        * @param   u   The std::string to process.
        *
        * @return  True if it succeeds, false if it fails.
        */
    template<>
    bool TR_UTIL_EXPORT FromString<bool>(const std::string& u);

    /**
        * @fn  bool Match(const char* wildCards, const char* str);
        *
        * @brief   Matches.
        *
        * @param   wildCards   The wild cards.
        * @param   str         The string.
        *
        * @return  True if it succeeds, false if it fails.
        */
    bool TR_UTIL_EXPORT Match(const char* wildCards, const char* str);

    /**
        * @fn  void MakeIndexString(unsigned index, std::string& toFill, unsigned paddedLength = 4);
        *
        * @brief   Makes index string.
        *
        * @return  a string with text as an int value padded to the size specified.
        *
        * @param           index           Zero-based index of the.
        * @param [in,out]  toFill          to fill.
        * @param           paddedLength    (Optional) Length of the padded.
        */
    void TR_UTIL_EXPORT MakeIndexString(unsigned index, std::string& toFill, unsigned paddedLength = 4);

    /**
        * @fn  bool TakeToken(std::string& data, std::string& outToken, char openChar, char closeChar);
        *
        * @brief   Reads the next token fromm the given string data. This will also remove the token
        *          from the data string and return you the token (with the open and close characters
        *          removed). The beginning of the data string must always begin with an opening
        *          character or this will cause problems.
        *
        * @param [in]  data        The string data.
        * @param [out] outToken    The first token from the string data.
        * @param [in]  openChar    The character that starts the token.
        * @param [in]  closeChar   The character that ends the token.
        *
        * @return  true if a token was found.
        */
    bool TR_UTIL_EXPORT TakeToken(std::string& data, std::string& outToken, char openChar, char closeChar);

    /**
        * @fn  void FindAndReplace(std::string& modifiedString, const std::string& findWhat, const std::string& replaceWith);
        *
        * @brief   Finds all instances of the findWhat string in the string modifiedString and replaces
        *          them with the replaceWith string.
        *
        * @param [out] modifiedString  The string we are modifying.
        * @param [in]  findWhat        The string we want to remove from modifiedString.
        * @param [in]  replaceWith     The string we want to put in modifiedString.
        */
    void TR_UTIL_EXPORT FindAndReplace(std::string& modifiedString, const std::string& findWhat, const std::string& replaceWith);
}