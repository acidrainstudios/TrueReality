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
* @author Maxim Serebrennik
* Based on Delta3D dtUtil::RefStr
*/

#include <trUtil/RefStr.h>

#include <ostream>

#if defined( _LIBCPP_VERSION ) || (defined(_MSC_VER) && _MSC_VER >= 1700)
#  include <unordered_set>
#  define _UNORDERED_MAP
#elif defined(__GNUG__)
#  include <ext/hash_set>
namespace __gnu_cxx
{
    template<>
    struct hash<std::string>
    {
        size_t operator()(const std::string& string) const
        {
            return trUtil::__hash_string(string.c_str());
        }
    };
}
#elif defined(_MSC_VER)
#  include <hash_set>
#else
#  include <set>
#endif

#define USE_TABLE 1

#define THREAD_SAFETY 1

#if THREAD_SAFETY
#include <OpenThreads/Mutex>
#endif


namespace trUtil
{
    static size_t StringCount = 0;
#if USE_TABLE

#if THREAD_SAFETY
    static OpenThreads::Mutex gStringSetMutex;
#endif

#ifdef _UNORDERED_MAP
    static std::unordered_set<std::string> StringSet(3000);
#elif defined(__GNUG__)
    static __gnu_cxx::hash_set<std::string> StringSet(3000);
#elif defined(_MSC_VER)
    static stdext::hash_set<std::string> StringSet;
#else
    static std::set<std::string> StringSet;
#endif
#endif
    size_t RefStr::GetSharedStringCount()
    {
        return StringCount;
    }

    /////////////////////////////////////////////////////////////
    RefStr::RefStr(const std::string& value) : mString(nullptr)
    {
        Intern(value);
    }

    /////////////////////////////////////////////////////////////
    RefStr::RefStr(const char* value) : mString(nullptr)
    {
        Intern(value);
    }

    /////////////////////////////////////////////////////////////
    RefStr::RefStr(const RefStr& toCopy) : mString(nullptr)
    {
#if USE_TABLE
        //If we are using the table, we'll get the same pointer anyway.
        mString = toCopy.mString;
#else
        Intern(*toCopy.mString);
#endif
    }

    /////////////////////////////////////////////////////////////
    RefStr::~RefStr()
    {
#if !USE_TABLE
        delete mString;
        --StringCount;
#endif
    }

    /////////////////////////////////////////////////////////////
    RefStr RefStr::operator+(const std::string& string) const
    {
        return RefStr(*mString + string);
    }

    /////////////////////////////////////////////////////////////
    RefStr RefStr::operator+(const RefStr& value) const
    {
        return RefStr(*mString + *value.mString);
    }

    /////////////////////////////////////////////////////////////
    RefStr RefStr::operator+(const char* str) const
    {
        return RefStr(*mString + str);
    }

    /////////////////////////////////////////////////////////////
    trUtil::RefStr& RefStr::operator=(const std::string& value)
    {
        Intern(value);
        return *this;
    }

    /////////////////////////////////////////////////////////////
    trUtil::RefStr& RefStr::operator=(const trUtil::RefStr& value)
    {
        if (this == &value)
            return *this;
#if USE_TABLE
        //If we are using the table, we'll get the same pointer anyway.
        mString = value.mString;
#else
        Intern(*value.mString);
#endif
        return *this;
    }

    /////////////////////////////////////////////////////////////
    void RefStr::Intern(const std::string& value)
    {
#if USE_TABLE

#if THREAD_SAFETY
        // for thread safety, lock this section
        gStringSetMutex.lock();
#endif

        //One can only insert a string once, but it will still return the iterator.
        mString = &(*StringSet.insert(value).first);
        StringCount = StringSet.size();

#if THREAD_SAFETY
        gStringSetMutex.unlock();
#endif

#else
        if (mString != nullptr)
        {
            delete mString;
            --StringCount;
        }
        mString = new std::string(value);
        ++StringCount;
#endif
    }

    /////////////////////////////////////////////////////////////
    std::ostream& operator<<(std::ostream& stream, const RefStr& rs)
    {
        stream << rs.Get();
        return stream;
    }

}
