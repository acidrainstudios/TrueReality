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
* @author: Maxim Serebrennik
*/

#pragma once

#include <trUtil/TypeList.h>

namespace trUtil
{
    /**
     * Generalized functor implementation. Concept inspired by Andrei Alexandrescu.
     * Copyright Aleksei Trunov 2005
     * Use, copy, modify, distribute and sell it for free.
     */

    // Functor calls helpers

    template <class TList> struct CallParms;
    template <>
    struct CallParms<TYPELIST_0()>
    {
        typedef trUtil::InstantiateH<trUtil::NullType, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make() { return ParmsListType(); }
    };
    template <typename P1>
    struct CallParms<TYPELIST_1(P1)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1>::Type, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make(P1 p1)
        {
            return ParmsListType(p1);
        }
    };
    template <typename P1, typename P2>
    struct CallParms<TYPELIST_2(P1, P2)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2>::Type, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make(P1 p1, P2 p2)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2));
        }
    };
    template <typename P1, typename P2, typename P3>
    struct CallParms<TYPELIST_3(P1, P2, P3)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3>::Type, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3)));
        }
    };
    template <typename P1, typename P2, typename P3, typename P4>
    struct CallParms<TYPELIST_4(P1, P2, P3, P4)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4>::Type, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3,
                typename trUtil::TailAt<ParmsListType, 2>::Result(p4))));
        }
    };
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    struct CallParms<TYPELIST_5(P1, P2, P3, P4, P5)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5>::Type, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3,
                typename trUtil::TailAt<ParmsListType, 2>::Result(p4,
                typename trUtil::TailAt<ParmsListType, 3>::Result(p5)))));
        }
    };
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct CallParms<TYPELIST_6(P1, P2, P3, P4, P5, P6)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6>::Type, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3,
                typename trUtil::TailAt<ParmsListType, 2>::Result(p4,
                typename trUtil::TailAt<ParmsListType, 3>::Result(p5,
                typename trUtil::TailAt<ParmsListType, 4>::Result(p6))))));
        }
    };
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct CallParms<TYPELIST_7(P1, P2, P3, P4, P5, P6, P7)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6, P7>::Type, trUtil::TupleHolder> ParmsListType;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3,
                typename trUtil::TailAt<ParmsListType, 2>::Result(p4,
                typename trUtil::TailAt<ParmsListType, 3>::Result(p5,
                typename trUtil::TailAt<ParmsListType, 4>::Result(p6,
                typename trUtil::TailAt<ParmsListType, 5>::Result(p7)))))));
        }
    };

    template <typename CallType, typename R, class TList> struct FunctorCall;
    template <typename CallType, typename R>
    struct FunctorCall<CallType, R, TYPELIST_0()>
    {
        typedef trUtil::InstantiateH<trUtil::NullType, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& /*parms*/)
        {
            return fun();
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& /*parms*/)
        {
            return ((*pobj).*memfun)();
        }
    };
    template <typename CallType, typename R, typename P1>
    struct FunctorCall<CallType, R, TYPELIST_1(P1)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1>::Type, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(trUtil::GetH<0>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(trUtil::GetH<0>(parms).value);
        }
    };
    template <typename CallType, typename R, typename P1, typename P2>
    struct FunctorCall<CallType, R, TYPELIST_2(P1, P2)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2>::Type, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value);
        }
    };
    template <typename CallType, typename R, typename P1, typename P2, typename P3>
    struct FunctorCall<CallType, R, TYPELIST_3(P1, P2, P3)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3>::Type, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value);
        }
    };
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunctorCall<CallType, R, TYPELIST_4(P1, P2, P3, P4)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4>::Type, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value);
        }
    };
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunctorCall<CallType, R, TYPELIST_5(P1, P2, P3, P4, P5)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5>::Type, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value,
                trUtil::GetH<4>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value,
                trUtil::GetH<4>(parms).value);
        }
    };
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunctorCall<CallType, R, TYPELIST_6(P1, P2, P3, P4, P5, P6)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6>::Type, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value,
                trUtil::GetH<4>(parms).value,
                trUtil::GetH<5>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value,
                trUtil::GetH<4>(parms).value,
                trUtil::GetH<5>(parms).value);
        }
    };
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunctorCall<CallType, R, TYPELIST_7(P1, P2, P3, P4, P5, P6, P7)>
    {
        typedef trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6, P7>::Type, trUtil::TupleHolder> ParmsListType;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value,
                trUtil::GetH<4>(parms).value,
                trUtil::GetH<5>(parms).value,
                trUtil::GetH<6>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(
                trUtil::GetH<0>(parms).value,
                trUtil::GetH<1>(parms).value,
                trUtil::GetH<2>(parms).value,
                trUtil::GetH<3>(parms).value,
                trUtil::GetH<4>(parms).value,
                trUtil::GetH<5>(parms).value,
                trUtil::GetH<6>(parms).value);
        }
    };
}
