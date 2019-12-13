/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
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
*/

#pragma once

namespace trUtil
{
    /*
    * This file contains small collection of generic programming templates etc
    * gathered from various sources (Loki library is the main one). Some of them
    * has been modified, others have remained intact.
    * Copyright Aleksei Trunov 2005
    * Use, copy, modify, distribute and sell it for free.
    */

    template <bool flag, typename T, typename U>
    struct Select
    {
        using Result = T;
    };
    template <typename T, typename U>
    struct Select<false, T, U>
    {
        using Result = U;
    };

    template <int v> struct Int2Type { enum { value = v }; };

    template<class T, int i> struct IsIntType { enum { value = false }; };
    template<int i> struct IsIntType<Int2Type<i>, i> { enum { value = true }; };
    template<class T, int i> struct NotIntType { enum { value = !IsIntType<T, i>::value }; };

    /**
     * @class   NullType
     *
     * @brief   A null type class.
     */
    class NullType {};
    struct EmptyType {};

    /**
     * @struct  TypeList
     *
     * @brief   List of types structure.
     *
     * @tparam  T   Generic type parameter.
     * @tparam  U   Generic type parameter.
     */
    template <class T, class U>
    struct TypeList
    {
        using Head = T;
        using Tail = U;
    };

    template <
        class T1 = NullType
            , class T2 = NullType
            , class T3 = NullType
            , class T4 = NullType
            , class T5 = NullType
            , class T6 = NullType
            , class T7 = NullType
            , class T8 = NullType
    > struct CreateTL
        {
            using Type = TypeList<T1, typename CreateTL<T2, T3, T4, T5, T6, T7, T8>::Type>;
        };
        template<> struct CreateTL<NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType>
        {
            using Type = NullType;
        };

        template <
            int i1 = -1
            , int i2 = -1
            , int i3 = -1
            , int i4 = -1
            , int i5 = -1
            , int i6 = -1
            , int i7 = -1
            , int i8 = -1
        > struct CreateIdsTL
        {
            using Type = TypeList<Int2Type<i1>, typename CreateIdsTL<i2, i3, i4, i5, i6, i7, i8, -1>::Type>;
        };
        template <> struct CreateIdsTL<-1, -1, -1, -1, -1, -1, -1, -1> { using Type = NullType; };

        template <class TL, int i = 0> struct IdsFromTL
        {
            using Type = TypeList<Int2Type<i>, typename IdsFromTL<typename TL::Tail, i + 1>::Type>;
        };
        template <int i> struct IdsFromTL<NullType, i> { using Type = NullType; };

        template <class TList, class T>
        struct AppendTL
        {
            using Type = TypeList<typename TList::Head, typename AppendTL<typename TList::Tail, T>::Type>;
        };
        template <class T>
        struct AppendTL<NullType, T>
        {
            using Type = TypeList<T, NullType>;
        };

/**
 * @brief   Macros that define various lists of Class types.
 */
#define TYPELIST_0() trUtil::NullType
#define TYPELIST_1(T1) trUtil::TypeList<T1, TYPELIST_0()>
#define TYPELIST_2(T1, T2) trUtil::TypeList<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) trUtil::TypeList<T1, TYPELIST_2(T2, T3)>
#define TYPELIST_4(T1, T2, T3, T4) trUtil::TypeList<T1, TYPELIST_3(T2, T3, T4)>
#define TYPELIST_5(T1, T2, T3, T4, T5) trUtil::TypeList<T1, TYPELIST_4(T2, T3, T4, T5)>
#define TYPELIST_6(T1, T2, T3, T4, T5, T6) trUtil::TypeList<T1, TYPELIST_5(T2, T3, T4, T5, T6)>
#define TYPELIST_7(T1, T2, T3, T4, T5, T6, T7) trUtil::TypeList<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7)>
#define TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8) trUtil::TypeList<T1, TYPELIST_7(T2, T3, T4, T5, T6, T7, T8)>

        template <class TList> struct Length;
        template <> struct Length<NullType>
        {
            enum { value = 0 };
        };
        template <class T, class U>
        struct Length< TypeList<T, U> >
        {
            enum { value = 1 + Length<U>::value };
        };

        template <class TList, unsigned int i> struct TypeAt;
        template <class T, class U>
        struct TypeAt< TypeList<T, U>, 0 >
        {
            using Result = T;
        };
        template <class T, class U, unsigned int i>
        struct TypeAt< TypeList<T, U>, i >
        {
            using Result = typename TypeAt<U, i - 1>::Result;
        };

        template <class TList, unsigned int i, typename DefType = NullType>
        struct TypeAtNonStrict
        {
            using Result = DefType;
        };
        template <class T, class U, typename DefType>
        struct TypeAtNonStrict< TypeList<T, U>, 0, DefType >
        {
            using Result = T;
        };
        template <class T, class U, unsigned int i, typename DefType>
        struct TypeAtNonStrict< TypeList<T, U>, i, DefType >
        {
            using Result = typename TypeAtNonStrict<U, i - 1, DefType>::Result;
        };

        // Tuples-related

        template <typename T, unsigned int i = 0> struct TupleHolder
        {
            using Type = T;
            using StoredType = T;
            StoredType value;
            TupleHolder() {}
            TupleHolder(Type t) : value(t) {}
            TupleHolder& operator=(TupleHolder const& v) { value = v.value; }
        };

        template <typename TList, template <class, unsigned int> class Holder, unsigned int i = 0> struct InstantiateH;
        template <typename T, typename U, template <class, unsigned int> class Holder, unsigned int i>
        struct InstantiateH<TypeList<T, U>, Holder, i>
            : public Holder<typename TypeList<T, U>::Head, i>
            , public InstantiateH<typename TypeList<T, U>::Tail, Holder, i + 1>
        {
            enum { ordern = i };
            using LeftBase = Holder<typename TypeList<T, U>::Head, i>;
            using RightBase = InstantiateH<typename TypeList<T, U>::Tail, Holder, i + 1>;
            InstantiateH(typename TypeList<T, U>::Head h, RightBase const& t) : LeftBase(h), RightBase(t) {}
            InstantiateH(typename TypeList<T, U>::Head h, NullType) : LeftBase(h) {}
            InstantiateH(typename TypeList<T, U>::Head h) : LeftBase(h) {}
            InstantiateH() {}
        };
        template <template <class, unsigned int> class Holder, unsigned int i>
        struct InstantiateH<NullType, Holder, i>
        {
            InstantiateH() {}
        };

        template <typename InstH, unsigned int j, unsigned int i = 0> struct TailAt;
        template <typename T, typename U, template <class, unsigned int> class Holder, unsigned int i>
        struct TailAt<InstantiateH<TypeList<T, U>, Holder, i>, 0, i>
        {
            using Result = InstantiateH<typename TypeList<T, U>::Tail, Holder, i + 1>;
        };
        template <typename T, typename U, template <class, unsigned int> class Holder, unsigned int j, unsigned int i>
        struct TailAt<InstantiateH<TypeList<T, U>, Holder, i>, j, i>
        {
            using Result = typename TailAt<InstantiateH<typename TypeList<T, U>::Tail, Holder, i + 1>, j - 1, i + 1>::Result;
        };

        template <unsigned int j, typename InstH, unsigned int i = 0> struct InstantiateHAccessor;
        template <typename T, typename U, template <class, unsigned int> class Holder, unsigned int i>
        struct InstantiateHAccessor<0, InstantiateH<TypeList<T, U>, Holder, i>, i>
        {
            using Instance = InstantiateH<TypeList<T, U>, Holder, i>;
            using TargetHolder = typename Instance::LeftBase;
            static inline TargetHolder& Get(Instance& h) { return static_cast<TargetHolder&>(h); }
            static inline TargetHolder const& Get(Instance const& h) { return static_cast<TargetHolder const&>(h); }
        };
        template <unsigned int j, typename T, typename U, template <class, unsigned int> class Holder, unsigned int i>
        struct InstantiateHAccessor<j, InstantiateH<TypeList<T, U>, Holder, i>, i>
        {
            using Instance = InstantiateH<TypeList<T, U>, Holder, i>;
            using TargetHolder = Holder<typename TypeAt<TypeList<T, U>, j>::Result, j + i>;
            using RightBase = typename Instance::RightBase;
            static inline TargetHolder& Get(Instance& h) { return InstantiateHAccessor<j - 1, RightBase, i + 1>::Get(static_cast<RightBase&>(h)); }
            static inline TargetHolder const& Get(Instance const& h) { return InstantiateHAccessor<j - 1, RightBase, i + 1>::Get(static_cast<RightBase const&>(h)); }
        };
        template <unsigned int j, class Instantiated> inline
            typename InstantiateHAccessor<j, Instantiated, Instantiated::ordern>::TargetHolder&
            GetH(Instantiated& h)
        {
            return InstantiateHAccessor<j, Instantiated, Instantiated::ordern>::Get(h);
        }
        template <unsigned int j, class Instantiated> inline
            typename InstantiateHAccessor<j, Instantiated, Instantiated::ordern>::TargetHolder const&
            GetH(Instantiated const& h)
        {
            return InstantiateHAccessor<j, Instantiated, Instantiated::ordern>::Get(h);
        }
}