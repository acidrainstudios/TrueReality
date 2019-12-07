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
*/

#pragma once

// Generalized functor implementation helpers.
// Copyright Aleksei Trunov 2005
// Use, copy, modify, distribute and sell it for free.


#include <trUtil/TypeList.h>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @struct  FunTraits
     *
     * @brief   Function traits.
     *
     * @tparam  T   Generic type parameter.
     */
    template <typename T> struct FunTraits;

#if (defined(_MSC_VER)) && (_MANAGED != 1) && (!defined (_WIN64))
    template <typename R>
    struct FunTraits<R(__cdecl *)()>
    {
        using ObjType = NullType;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <typename R>
    struct FunTraits<R(__stdcall *)()>
    {
        using ObjType = NullType;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <typename R>
    struct FunTraits<R(__fastcall *)()>
    {
        using ObjType = NullType;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <typename R, typename P1>
    struct FunTraits<R(__cdecl *)(P1)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <typename R, typename P1>
    struct FunTraits<R(__stdcall *)(P1)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <typename R, typename P1>
    struct FunTraits<R(__fastcall *)(P1)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <typename R, typename P1, typename P2>
    struct FunTraits<R(__cdecl *)(P1, P2)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <typename R, typename P1, typename P2>
    struct FunTraits<R(__stdcall *)(P1, P2)>
    {
        using ObjType = NullType;
        using ResultType  = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <typename R, typename P1, typename P2>
    struct FunTraits<R(__fastcall *)(P1, P2)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__cdecl *)(P1, P2, P3)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__stdcall *)(P1, P2, P3)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__fastcall *)(P1, P2, P3)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__cdecl *)(P1, P2, P3, P4)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__stdcall *)(P1, P2, P3, P4)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__fastcall *)(P1, P2, P3, P4)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__cdecl *)(P1, P2, P3, P4, P5)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__stdcall *)(P1, P2, P3, P4, P5)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__fastcall *)(P1, P2, P3, P4, P5)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__cdecl *)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__stdcall *)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__fastcall *)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__cdecl *)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__stdcall *)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__fastcall *)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <class O, typename R>
    struct FunTraits<R(__cdecl O::*)() const>
    {
        using ObjType =  O;
        using ResultType =  R;
        using TypeListType =  NullType;
    };
    template <class O, typename R>
    struct FunTraits<R(__stdcall O::*)() const>
    {
        using ObjType = O;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <class O, typename R>
    struct FunTraits<R(__fastcall O::*)() const>
    {
        using ObjType = O;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(__cdecl O::*)(P1) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(__stdcall O::*)(P1) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(__fastcall O::*)(P1) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(__cdecl O::*)(P1, P2) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(__stdcall O::*)(P1, P2) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(__fastcall O::*)(P1, P2) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4, P5) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4, P5) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4, P5) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4, P5, P6) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4, P5, P6) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4, P5, P6) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4, P5, P6, P7) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4, P5, P6, P7) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4, P5, P6, P7) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <class O, typename R>
    struct FunTraits<R(__cdecl O::*)()>
    {
        using ObjType = O;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <class O, typename R>
    struct FunTraits<R(__stdcall O::*)()>
    {
        using ObjType = O;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <class O, typename R>
    struct FunTraits<R(__fastcall O::*)()>
    {
        using ObjType = O;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(__cdecl O::*)(P1)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(__stdcall O::*)(P1)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(__fastcall O::*)(P1)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(__cdecl O::*)(P1, P2)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(__stdcall O::*)(P1, P2)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(__fastcall O::*)(P1, P2)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4, P5)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4, P5)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4, P5)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__cdecl O::*)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__stdcall O::*)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(__fastcall O::*)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
#else // #if (defined(_MSC_VER)) && (_MANAGED != 1) && (!defined (_WIN64))
    template <typename R>
    struct FunTraits<R(*)()>
    {
        using ObjType = NullType;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <typename R, typename P1>
    struct FunTraits<R(*)(P1)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <typename R, typename P1, typename P2>
    struct FunTraits<R(*)(P1, P2)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(*)(P1, P2, P3)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(*)(P1, P2, P3, P4)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(*)(P1, P2, P3, P4, P5)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(*)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(*)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = NullType;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P6);
    };
#endif //#if (defined(_MSC_VER)) && (_MANAGED != 1) && (!defined (_WIN64))

    template <class O, typename R>
    struct FunTraits<R(O::*)()>
    {
        using ObjType = O;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(O::*)(P1)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(O::*)(P1, P2)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(O::*)(P1, P2, P3)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(O::*)(P1, P2, P3, P4)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(O::*)(P1, P2, P3, P4, P5)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(O::*)(P1, P2, P3, P4, P5, P6)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(O::*)(P1, P2, P3, P4, P5, P6, P7)>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };
    template <class O, typename R>
    struct FunTraits<R(O::*)() const>
    {
        using ObjType = O;
        using ResultType = R;
        using TypeListType = NullType;
    };
    template <class O, typename R, typename P1>
    struct FunTraits<R(O::*)(P1) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using TypeListType = TYPELIST_1(P1);
    };
    template <class O, typename R, typename P1, typename P2>
    struct FunTraits<R(O::*)(P1, P2) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using TypeListType = TYPELIST_2(P1, P2);
    };
    template <class O, typename R, typename P1, typename P2, typename P3>
    struct FunTraits<R(O::*)(P1, P2, P3) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using TypeListType = TYPELIST_3(P1, P2, P3);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4>
    struct FunTraits<R(O::*)(P1, P2, P3, P4) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using TypeListType = TYPELIST_4(P1, P2, P3, P4);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct FunTraits<R(O::*)(P1, P2, P3, P4, P5) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using TypeListType = TYPELIST_5(P1, P2, P3, P4, P5);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct FunTraits<R(O::*)(P1, P2, P3, P4, P5, P6) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using TypeListType = TYPELIST_6(P1, P2, P3, P4, P5, P6);
    };
    template <class O, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    struct FunTraits<R(O::*)(P1, P2, P3, P4, P5, P6, P7) const>
    {
        using ObjType = O;
        using ResultType = R;
        using Parm1 = P1;
        using Parm2 = P2;
        using Parm3 = P3;
        using Parm4 = P4;
        using Parm5 = P5;
        using Parm6 = P6;
        using Parm7 = P7;
        using TypeListType = TYPELIST_7(P1, P2, P3, P4, P5, P6, P7);
    };

}