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
* @author Maxim Serebrennik
*/

#pragma once

#include <trUtil/FunCall.h>
#include <trUtil/FunTraits.h>
#include <trUtil/TypeList.h>

#include <stdlib.h>
#include <utility>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    // Generalized functor implementation. Concept inspired by Andrei Alexandrescu.
    // Copyright Aleksei Trunov 2005
    // Use, copy, modify, distribute and sell it for free.
    //
    // Generalized functor class template


    /**
     * @class   Functor
     *
     * @brief   A functor.
     */
    template <typename R, class TList, unsigned int size = 4 * sizeof(void*)>
    class Functor
    {
    public:
        using ResultType = R ;
        using TypeListType = TList;
        using ParmsListType = typename CallParms<TList>::ParmsListType;

        /**
         * @fn  Functor::Functor()
         *
         * @brief   default construction, assignment and destruction.
         */
        Functor() : vptr_(0) {}

        /**
         * @fn  Functor::~Functor()
         *
         * @brief   Destructor.
         */
        ~Functor()
        {
            if (vptr_) vptr_->destroy_(*this);
        }

        /**
         * @fn  Functor::Functor(Functor const& src)
         *
         * @brief   Copy constructor.
         *
         * @param   src Source for the.
         */
        Functor(Functor const& src)
        {
            vptr_ = src.vptr_ ? src.vptr_->clone_(src, *this) : NULL;
        }

        /**
         * @fn  Functor& Functor::operator=(Functor const& src)
         *
         * @brief   Assignment operator.
         *
         * @param   src Source for the.
         *
         * @return  A shallow copy of this object.
         */
        Functor& operator=(Functor const& src)
        {
            if (this != &src) {
                if (vptr_) vptr_->destroy_(*this);
                vptr_ = src.vptr_ ? src.vptr_->clone_(src, *this) : NULL;
            }
            return *this;
        }

        /**
         * @fn  bool Functor::operator!() const
         *
         * @brief   is-empty selector.
         *
         * @return  The logical inverse of this value.
         */
        bool operator!() const { return vptr_ == NULL; }

        /**
         * @fn  bool Functor::valid() const
         *
         * @brief   Valids this object.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool valid() const { return vptr_ != NULL; }

        /**
         * @fn  template <typename F> explicit Functor::Functor(F const& fun)
         *
         * @brief   ctor for static fns and arbitrary functors.
         *
         * @tparam  F   Type of the f.
         * @param   fun The fun.
         */
        template <typename F> explicit Functor(F const& fun)
        {
            using StoredType = FunctorImpl<F>;
            vptr_ = _init<StoredType>(fun);
        }

        /**
         * @fn  template <class P, typename MF> explicit Functor::Functor(P const& pobj, MF memfun)
         *
         * @brief   ctor for member fns (note: raw ptrs and smart ptrs are equally welcome in pobj)
         *
         * @tparam  P   Type of the p.
         * @tparam  MF  Type of the mf.
         * @param   pobj    The pobj.
         * @param   memfun  The memfun.
         */
        template <class P, typename MF> explicit Functor(P const& pobj, MF memfun)
        {
            using StoredType = MemberFnImpl<P, MF>;
            vptr_ = _init<StoredType>(std::pair<P, MF>(pobj, memfun));
        }
        // calls
        using Parm1 = typename trUtil::TypeAtNonStrict<TList, 0, trUtil::NullType>::Result;
        using Parm2 = typename trUtil::TypeAtNonStrict<TList, 1, trUtil::NullType>::Result;
        using Parm3 = typename trUtil::TypeAtNonStrict<TList, 2, trUtil::NullType>::Result;
        using Parm4 = typename trUtil::TypeAtNonStrict<TList, 3, trUtil::NullType>::Result;
        using Parm5 = typename trUtil::TypeAtNonStrict<TList, 4, trUtil::NullType>::Result;
        using Parm6 = typename trUtil::TypeAtNonStrict<TList, 5, trUtil::NullType>::Result;
        using Parm7 = typename trUtil::TypeAtNonStrict<TList, 6, trUtil::NullType>::Result;
#define DoCall(parms) return vptr_->call_(*this, parms);
        inline R operator()(ParmsListType const& parms) const { DoCall(parms) }
        inline R operator()() const { DoCall(CallParms<TList>::Make()) }
        inline R operator()(Parm1 p1) const { DoCall(CallParms<TList>::Make(p1)) }
        inline R operator()(Parm1 p1, Parm2 p2) const { DoCall(CallParms<TList>::Make(p1, p2)) }
        inline R operator()(Parm1 p1, Parm2 p2, Parm3 p3) const { DoCall(CallParms<TList>::Make(p1, p2, p3)) }
        inline R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4) const { DoCall(CallParms<TList>::Make(p1, p2, p3, p4)) }
        inline R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5) const { DoCall(CallParms<TList>::Make(p1, p2, p3, p4, p5)) }
        inline R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6) const { DoCall(CallParms<TList>::Make(p1, p2, p3, p4, p5, p6)) }
        inline R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7) const { DoCall(CallParms<TList>::Make(p1, p2, p3, p4, p5, p6, p7)) }
    private:
        // copying/destruction and calls implementation
        struct FunImplBase
        {
            struct VTable;
            struct VTable
            {
                void(*destroy_)(Functor const&);
                VTable* (*clone_)(Functor const&, Functor&);
                R(*call_)(Functor const&, ParmsListType);
            };
            // VTable vtbl_;   // not needed here and actually wastes space!
        };
        template <typename V, class Derived>
        struct FunStorageImpl : public FunImplBase
        {
            V val_;
            FunStorageImpl(V const& val) : val_(val) {}
            static void Destroy(Functor const& src) { src.val_.template destroy<Derived>(); }
            static typename FunImplBase::VTable* Clone(Functor const& src, Functor& dest)
            {
                Derived const& this_ = src.val_.template get<Derived const>();
                return dest._init<Derived>(this_.val_);
            }
        };
        template <typename T>
        struct FunctorImpl : public FunStorageImpl<T, FunctorImpl<T> >
        {
            FunctorImpl(T const& val) : FunStorageImpl<T, FunctorImpl>(val) {}
            static R Call(Functor const& src, ParmsListType parms)
            {
                FunctorImpl const& this_ = src.val_.template get<FunctorImpl const>();
                return FunctorCall<T, R, TList>::Call(this_.val_, parms);
            }
        };
        template <class P, typename T>
        struct MemberFnImpl : public FunStorageImpl<std::pair<P, T>, MemberFnImpl<P, T> >
        {
            MemberFnImpl(std::pair<P, T> const& val) : FunStorageImpl<std::pair<P, T>, MemberFnImpl>(val) {}
            static R Call(Functor const& src, ParmsListType parms)
            {
                MemberFnImpl const& this_ = src.val_.template get<MemberFnImpl const>();
                return FunctorCall<T, R, TList>::Call(this_.val_.first, this_.val_.second, parms);
            }
        };
        // initialization helper
        template <class T, class V>
        typename FunImplBase::VTable* _init(V const& v)
        {
            val_.template init<T>(v);
            static typename FunImplBase::VTable vtbl =
            {
                &T::Destroy,
                &T::Clone,
                &T::Call,
            };
            return &vtbl;
        }
        // typeless storage support
        struct Typeless
        {
            template <typename T> inline T* init1(T* v) { return new(getbuf()) T(v); }
            template <typename T, typename V> inline T* init(V const& v) { return new(getbuf()) T(v); }
            template <typename T> inline void destroy() const { (*reinterpret_cast<T const*>(getbuf())).~T(); }
            template <typename T> inline T const& get() const { return *reinterpret_cast<T const*>(getbuf()); }
            template <typename T> inline T& get() { return *reinterpret_cast<T*>(getbuf()); }
            void* getbuf() { return &buffer_[0]; }
            void const* getbuf() const { return &buffer_[0]; }
            unsigned char buffer_[size];
        };
        template <typename T>
        struct ByValue
        {
            template <typename V> inline static T* init(Typeless& val, V const& v) { return val.template init<T>(v); }
            inline static void destroy(Typeless const& val) { val.template destroy<T>(); }
            inline static T const& get(Typeless const& val) { return val.template get<T>(); }
            inline static T& get(Typeless& val) { return val.template get<T>(); }
        };
        template <typename T>
        struct NewAlloc
        {
            template <typename V> inline static T* init(Typeless& val, V const& v) { return *val.template init<T*>(new T(v)); }
            inline static void destroy(Typeless const& val) { delete val.template get<T*>(); }
            inline static T const& get(Typeless const& val) { return *val.template get<T const*>(); }
            inline static T& get(Typeless& val) { return *val.template get<T*>(); }
        };
        template <typename T>
        struct SelectStored
        {
            // TODO: it seems this is a good place to add alignment calculations
            using Type = typename trUtil::Select<sizeof(T) <= sizeof(Typeless), ByValue<T>, NewAlloc<T>>::Result ;
        };
        struct Stored
        {
            template <typename T, typename V> inline T* init(V const& v) { return SelectStored<T>::Type::init(val_, v); }
            template <typename T> inline void destroy() const { SelectStored<T>::Type::destroy(val_); }
            template <typename T> inline T const& get() const { return SelectStored<T>::Type::get(val_); }
            template <typename T> inline T& get() { return SelectStored<T>::Type::get(val_); }
            Typeless val_;
        };
        Stored val_;
        typename FunImplBase::VTable* vptr_;
    };

    // Helper functor creation functions


        /**
         * @fn  MakeFunctor(CallType fun)
         *
         * @brief   Constructor.
         *
         * @param   fun The fun.
         */
    template <typename CallType> inline
        Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>
        MakeFunctor(CallType fun)
    {
        return trUtil::Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>(fun);
    }

        /**
         * @fn  MakeFunctor(CallType memfun, PObj* const pobj)
         *
         * @brief   Constructor.
         *
         * @param           memfun  The memfun.
         * @param [in,out]  pobj    If non-null, the pobj.
         */
    template <typename CallType, class PObj> inline
        Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>
        MakeFunctor(CallType memfun, PObj* const pobj)
    {
        return trUtil::Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>(pobj, memfun);
    }

        /**
         * @fn  MakeFunctor(Fun const& fun)
         *
         * @brief   Constructor.
         *
         * @param   fun The fun.
         */
    template <typename CallType, class Fun> inline
        Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>
        MakeFunctor(Fun const& fun)
    {
        return trUtil::Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>(fun);
    }

        /**
         * @fn  MakeFunctor(CallType memfun, PObj& pobj)
         *
         * @brief   Constructor.
         *
         * @param           memfun  The memfun.
         * @param [in,out]  pobj    The pobj.
         */
    template <typename CallType, class PObj> inline
        Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>
        MakeFunctor(CallType memfun, PObj& pobj)
    {
        return trUtil::Functor<typename trUtil::FunTraits<CallType>::ResultType, typename trUtil::FunTraits<CallType>::TypeListType>(&pobj, memfun);
    }
}

