/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
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
* Author: Maxim Serebrennik
* Based on Delta3D dtUtil::RefStr
*/
#pragma once
#include "Export.h"

#include <trUtil/Hash.h>

#include <string>

namespace trUtil
{
    /**
    * A string wrapper that will make sure that all of the strings with the same value
    * will point to the same memory.  The strings are only accessible as const, but
    * a new string may be assigned to the reference string. 
    */
    class TR_UTIL_EXPORT RefStr
    {
    public:
        /// @return the number of shared strings.
        static size_t GetSharedStringCount();

        RefStr(const std::string& value = "");
        RefStr(const char* value);
        RefStr(const RefStr& toCopy);
        ~RefStr();

        operator const std::string&() const { return *mString; }
        trUtil::RefStr& operator=(const std::string& value);
        trUtil::RefStr& operator=(const trUtil::RefStr& value);

        RefStr operator+(const std::string& string) const;
        RefStr operator+(const RefStr& RefStr) const;
        RefStr operator+(const char* str) const;
        const std::string* operator->() const { return mString; }
        std::string::value_type operator[](int index) const { return (*mString)[index]; }

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