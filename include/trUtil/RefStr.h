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
* @author Maxim Serebrennik
* Based on Delta3D dtUtil::RefStr
*/
#pragma once
#include "Export.h"

#include <trUtil/Hash.h>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @class   RefStr
     *
     * @brief   A string wrapper that will make sure that all of the strings with the same value will
     *          point to the same memory.  The strings are only accessible as const, but a new string
     *          may be assigned to the reference string.
     *
     * @author Maxim Serebrennik
     */
    class TR_UTIL_EXPORT RefStr
    {
    public:

        /**
         * @fn  static size_t RefStr::GetSharedStringCount();
         *
         * @brief   Gets shared string count.
         *
         * @return  the number of shared strings.
         */
        static size_t GetSharedStringCount();

        /**
         * @fn  RefStr::RefStr(const std::string& value = "");
         *
         * @brief   Constructor.
         *
         * @param   value   (Optional) The value.
         */
        RefStr(const std::string& value = "");

        /**
         * @fn  RefStr::RefStr(const char* value);
         *
         * @brief   Constructor.
         *
         * @param   value   The value.
         */
        RefStr(const char* value);

        /**
         * @fn  RefStr::RefStr(const RefStr& toCopy);
         *
         * @brief   Copy constructor.
         *
         * @param   toCopy  to copy.
         */
        RefStr(const RefStr& toCopy);

        /**
         * @fn  RefStr::~RefStr();
         *
         * @brief   Destructor.
         */
        ~RefStr();

        /**
         * @fn  operator const std::string&() const
         *
         * @brief   Implicit conversion operator from RefStr to std::string;
         *
         * @return  A const.
         */
        operator const std::string&() const { return *mString; }

        /**
         * @fn  operator const RefStr::char*() const
         *
         * @brief   Implicit conversion operator from RefStr to const char*.
         *
         * @return  A const.
         */
        operator const char*() const { return mString->c_str(); }

        trUtil::RefStr& operator=(const std::string& value);

        /**
         * @fn  trUtil::RefStr& RefStr::operator=(const trUtil::RefStr& value) = delete;
         *
         * @brief   Deleting the default copy operator to avoid ambiguous conflicts
         *
         * @param   value   The value.
         *
         * @return  A shallow copy of this object.
         */
        trUtil::RefStr& operator=(const trUtil::RefStr& value) = delete;

        RefStr operator+(const std::string& string) const;
        RefStr operator+(const RefStr& RefStr) const;
        RefStr operator+(const char* str) const;
        const std::string* operator->() const { return mString; }
        std::string::value_type operator[](int index) const { return (*mString)[index]; }

        /**
         * @fn  const char* RefStr::c_str() const
         *
         * @brief   Gets the string.
         *
         * @return  Null if it fails, else a pointer to a const char.
         */
        const char* c_str() const { return mString->c_str(); }

        bool operator<(const trUtil::RefStr& toCompare) const
        {
            return this->Get() < toCompare.Get();
        }

        bool operator==(const trUtil::RefStr& toCompare) const
        {
            return this->Get() == toCompare.Get();
        }

        bool operator!=(const trUtil::RefStr& toCompare) const
        {
            return !(*this == toCompare);
        }

        bool operator==(const std::string& toCompare) const
        {
            return this->Get() == toCompare;
        }

        bool operator==(const char* toCompare) const
        {
            return this->Get() == toCompare;
        }

        bool operator!=(const char* toCompare) const
        {
            return this->Get() != toCompare;
        }

        bool operator!=(const std::string& toCompare) const
        {
            return !(*this == toCompare);
        }

        const std::string& Get() const { return *mString; }

    private:
        const std::string* mString;

        void Intern(const std::string& value);
    };

    /////////////////////////////////////////////////////////////
    inline bool operator==(const std::string& s1, const RefStr& s2)
    {
        return s2 == s1;
    }

    /////////////////////////////////////////////////////////////
    inline std::string operator+(const std::string& s1, const RefStr& s2)
    {
        return s1 + s2.Get();
    }

    /////////////////////////////////////////////////////////////
    inline bool operator!=(const std::string& s1, const RefStr& s2)
    {
        return s2 != s1;
    }

    /////////////////////////////////////////////////////////////
    TR_UTIL_EXPORT std::ostream& operator<<(std::ostream& stream, const RefStr& rs);

    /////////////////////////////////////////////////////////////
    template<> struct hash<const trUtil::RefStr>
    {
        size_t operator()(const trUtil::RefStr& string) const
        {
            return trUtil::__hash_string(string.c_str());
        }
    };

    /////////////////////////////////////////////////////////////
    template<> struct hash<trUtil::RefStr>
    {
        size_t operator()(const trUtil::RefStr& string) const
        {
            return trUtil::__hash_string(string.c_str());
        }
    };
}