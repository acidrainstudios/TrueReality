/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2021 Acid Rain Studios LLC
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
*/
#pragma once

#if defined( _LIBCPP_VERSION ) || (defined(_MSC_VER) && _MSC_VER >= 1700) || defined(__GNUG__)
#  include <unordered_map>
#  define _UNORDERED_MAP
#elif defined(_MSC_VER)
#  include <hash_map>
#else
#  include <map>
#endif

#include <trUtil/Hash.h>

namespace trUtil
{

#if defined(_MSC_VER) && ! defined(_UNORDERED_MAP)
    template<class _Key, class _HashFcn, class _LessKey>
    struct HashCompare
    {
        size_t operator() (const _Key& k) const
        {
            _HashFcn h;
            return h(k);
        }
        bool operator() (const _Key& k1, const _Key& k2) const
        {
            _LessKey l;
            return l(k1, k2);
        }

        enum
        {    // parameters for hash table
            bucket_size = 4,    // 0 < bucket_size
            min_buckets = 8
        };    // min_buckets = 2 ^^ N, 0 < N

    };
#else
    template<class _Key, class _LessKey>
    struct HashEqual
    {
        bool operator() (const _Key& k1, const _Key& k2) const
        {
            _LessKey l;
            return !l(k1, k2) && !l(k2, k1);
        }
    };
#endif

    template<class _Key, class _Tp, class _HashFcn = trUtil::hash<_Key>, class _LessKey = std::less<_Key>, class _Alloc = std::allocator<std::pair<const _Key, _Tp> > >
    class HashMap : public
#if defined(_UNORDERED_MAP)
        std::unordered_map<_Key, _Tp, _HashFcn, trUtil::HashEqual<_Key, _LessKey>, _Alloc >
    {
    public:
        using BaseClass = std::unordered_map<_Key, _Tp, _HashFcn, trUtil::HashEqual<_Key, _LessKey>, _Alloc>;
#elif defined(_MSC_VER)
        stdext::hash_map<_Key, _Tp, trUtil::HashCompare<_Key, _HashFcn, _LessKey>, _Alloc >
    {
    public:
        using BaseClass = stdext::hash_map<_Key, _Tp, trUtil::HashCompare<_Key, _HashFcn, _LessKey>, _Alloc>;
#else
        std::map<_Key, _Tp, _LessKey, _Alloc >
    {
    public:
        using BaseClass = std::map<_Key, _Tp, _LessKey, _Alloc>;
#endif
        using typename BaseClass::iterator;
        using typename BaseClass::const_iterator;
        HashMap() {}
    };

    template<class _Key, class _Tp, class _HashFcn = trUtil::hash<_Key>, class _LessKey = std::less<_Key>, class _Alloc = std::allocator<std::pair<const _Key, _Tp> > >
    class HashMultiMap : public
#if defined(_UNORDERED_MAP)
        std::unordered_multimap<_Key, _Tp, _HashFcn, trUtil::HashEqual<_Key, _LessKey>, _Alloc >
    {
    public:
        using BaseClass = std::unordered_multimap<_Key, _Tp, _HashFcn, trUtil::HashEqual<_Key, _LessKey>, _Alloc>;
#elif defined(_MSC_VER)
        stdext::hash_multimap<_Key, _Tp, trUtil::HashCompare<_Key, _HashFcn, _LessKey>, _Alloc >
    {
    public:
        using BaseClass = stdext::hash_multimap<_Key, _Tp, trUtil::HashCompare<_Key, _HashFcn, _LessKey>, _Alloc>;
#else
        std::multimap<_Key, _Tp, _LessKey, _Alloc >
    {
    public:
        using BaseClass = std::multimap<_Key, _Tp, _LessKey, _Alloc>;
#endif
        using typename BaseClass::iterator;
        using typename BaseClass::const_iterator;
        HashMultiMap() {}
    };
}