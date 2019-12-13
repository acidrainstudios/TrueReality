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

#include <trUtil/TypeList.h>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * Generalized functor implementation. Concept inspired by Andrei Alexandrescu.
     * Copyright Aleksei Trunov 2005
     * Use, copy, modify, distribute and sell it for free.
     */

    // Functor calls helpers


    /**
     * @struct  CallParms<TYPELIST_0()>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_0()    Type of the typelist 0()
     */
    template <class TList> struct CallParms;
    template <>
    struct CallParms<TYPELIST_0()>
    {
        using ParmsListType = trUtil::InstantiateH<trUtil::NullType, trUtil::TupleHolder>;
        static inline ParmsListType Make() { return ParmsListType(); }
    };

    /**
     * @struct  CallParms<TYPELIST_1(P1)>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_1(P1)  Type of the typelist 1( p 1)
     */
    template <typename P1>
    struct CallParms<TYPELIST_1(P1)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1>::Type, trUtil::TupleHolder>;
        static inline ParmsListType Make(P1 p1)
        {
            return ParmsListType(p1);
        }
    };

    /**
     * @struct  CallParms<TYPELIST_2(P1,P2)>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_2(P1   Type of the typelist 2( p 1.
     * @tparam  P2)             Type of the 2)
     */
    template <typename P1, typename P2>
    struct CallParms<TYPELIST_2(P1, P2)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2>::Type, trUtil::TupleHolder>;
        static inline ParmsListType Make(P1 p1, P2 p2)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2));
        }
    };

    /**
     * @struct  CallParms<TYPELIST_3(P1,P2,P3)>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_3(P1   Type of the typelist 3( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3)             Type of the 3)
     */
    template <typename P1, typename P2, typename P3>
    struct CallParms<TYPELIST_3(P1, P2, P3)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3>::Type, trUtil::TupleHolder>;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3)));
        }
    };

    /**
     * @struct  CallParms<TYPELIST_4(P1,P2,P3,P4)>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_4(P1   Type of the typelist 4( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4)             Type of the 4)
     */
    template <typename P1, typename P2, typename P3, typename P4>
    struct CallParms<TYPELIST_4(P1, P2, P3, P4)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4>::Type, trUtil::TupleHolder>;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3,
                typename trUtil::TailAt<ParmsListType, 2>::Result(p4))));
        }
    };

    /**
     * @struct  CallParms<TYPELIST_5(P1,P2,P3,P4,P5)>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_5(P1   Type of the typelist 5( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4              Type of the p 4.
     * @tparam  P5)             Type of the 5)
     */
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    struct CallParms<TYPELIST_5(P1, P2, P3, P4, P5)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5>::Type, trUtil::TupleHolder>;
        static inline ParmsListType Make(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            return ParmsListType(p1,
                typename trUtil::TailAt<ParmsListType, 0>::Result(p2,
                typename trUtil::TailAt<ParmsListType, 1>::Result(p3,
                typename trUtil::TailAt<ParmsListType, 2>::Result(p4,
                typename trUtil::TailAt<ParmsListType, 3>::Result(p5)))));
        }
    };

    /**
     * @struct  CallParms<TYPELIST_6(P1,P2,P3,P4,P5,P6)>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_6(P1   Type of the typelist 6( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4              Type of the p 4.
     * @tparam  P5              Type of the p 5.
     * @tparam  P6)             Type of the 6)
     */
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct CallParms<TYPELIST_6(P1, P2, P3, P4, P5, P6)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6>::Type, trUtil::TupleHolder>;
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

    /**
     * @struct  CallParms<TYPELIST_7(P1,P2,P3,P4,P5,P6,P7)>
     *
     * @brief   A call parameters.
     *
     * @tparam  TYPELIST_7(P1   Type of the typelist 7( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4              Type of the p 4.
     * @tparam  P5              Type of the p 5.
     * @tparam  P6              Type of the p 6.
     * @tparam  P7)             Type of the 7)
     */
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct CallParms<TYPELIST_7(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6, P7>::Type, trUtil::TupleHolder>;
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

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_0()>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_0()    Type of the typelist 0()
     */
    template <typename CallType, typename R, class TList> struct FunctorCall;
    template <typename CallType, typename R>
    struct FunctorCall<CallType, R, TYPELIST_0()>
    {
        using ParmsListType = trUtil::InstantiateH<trUtil::NullType, trUtil::TupleHolder>;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& /*parms*/)
        {
            return fun();
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& /*parms*/)
        {
            return ((*pobj).*memfun)();
        }
    };

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_1(P1)>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_1(P1)  Type of the typelist 1( p 1)
     */
    template <typename CallType, typename R, typename P1>
    struct FunctorCall<CallType, R, TYPELIST_1(P1)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1>::Type, trUtil::TupleHolder>;
        template <class Fun> static inline R Call(Fun const& fun, ParmsListType& parms)
        {
            return fun(trUtil::GetH<0>(parms).value);
        }
        template <class PObj> static inline R Call(PObj const& pobj, CallType memfun, ParmsListType& parms)
        {
            return ((*pobj).*memfun)(trUtil::GetH<0>(parms).value);
        }
    };

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_2(P1,P2)>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_2(P1   Type of the typelist 2( p 1.
     * @tparam  P2)             Type of the 2)
     */
    template <typename CallType, typename R, typename P1, typename P2>
    struct FunctorCall<CallType, R, TYPELIST_2(P1, P2)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2>::Type, trUtil::TupleHolder>;
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

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_3(P1,P2,P3)>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_3(P1   Type of the typelist 3( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3)             Type of the 3)
     */
    template <typename CallType, typename R, typename P1, typename P2, typename P3>
    struct FunctorCall<CallType, R, TYPELIST_3(P1, P2, P3)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3>::Type, trUtil::TupleHolder> ;
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

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_4(P1,P2,P3,P4)>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_4(P1   Type of the typelist 4( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4)             Type of the 4)
     */
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunctorCall<CallType, R, TYPELIST_4(P1, P2, P3, P4)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4>::Type, trUtil::TupleHolder>;
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

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_5(P1,P2,P3,P4,P5)>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_5(P1   Type of the typelist 5( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4              Type of the p 4.
     * @tparam  P5)             Type of the 5)
     */
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunctorCall<CallType, R, TYPELIST_5(P1, P2, P3, P4, P5)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5>::Type, trUtil::TupleHolder>;
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

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_6(P1,P2,P3,P4,P5,P6)>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_6(P1   Type of the typelist 6( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4              Type of the p 4.
     * @tparam  P5              Type of the p 5.
     * @tparam  P6)             Type of the 6)
     */
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunctorCall<CallType, R, TYPELIST_6(P1, P2, P3, P4, P5, P6)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6>::Type, trUtil::TupleHolder>;
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

    /**
     * @struct  FunctorCall<CallType,R,TYPELIST_7(P1,P2,P3,P4,P5,P6,P7)>
     *
     * @brief   A functor call.
     *
     * @tparam  CallType        Type of the call type.
     * @tparam  R               Type of the r.
     * @tparam  TYPELIST_7(P1   Type of the typelist 7( p 1.
     * @tparam  P2              Type of the p 2.
     * @tparam  P3              Type of the p 3.
     * @tparam  P4              Type of the p 4.
     * @tparam  P5              Type of the p 5.
     * @tparam  P6              Type of the p 6.
     * @tparam  P7)             Type of the 7)
     */
    template <typename CallType, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunctorCall<CallType, R, TYPELIST_7(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ParmsListType = trUtil::InstantiateH<typename trUtil::CreateTL<P1, P2, P3, P4, P5, P6, P7>::Type, trUtil::TupleHolder> ;
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