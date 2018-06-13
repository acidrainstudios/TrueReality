/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/

#pragma once

#include <trUtil/Hash.h>

#include <osg/ref_ptr>

#include <iostream>

namespace trBase
{
    /**
    * Smart pointer for handling referenced counted objects.
    */ 
    template<class T>
    class SmrtPtr
    {
    public:

        /**
         * @fn  SmrtPtr::SmrtPtr();
         *
         * @brief   Default constructor.
         */
        SmrtPtr() { mOSGSmartPtr = nullptr; }

        /**
         * @fn  SmrtPtr::SmrtPtr(T* t);
         *
         * @brief   Constructor.
         *
         * @param [in,out]  t   If non-null, the T to process.
         */
        SmrtPtr(T* t) { mOSGSmartPtr = t;}


        /**
         * @fn  SmrtPtr::SmrtPtr(const SmrtPtr& smPt);
         *
         * @brief   Copy constructor.
         *
         * @param   smPt    The sm point.
         */
        SmrtPtr(const SmrtPtr& smPt) { mOSGSmartPtr = smPt.Get(); }

        /**
         * @fn  T* SmrtPtr::Get() const;
         *
         * @brief   Returns the stored internal pointer
         *
         * @return  Null if it fails, else a pointer to a T.
         */
        T* Get() const { return mOSGSmartPtr.get(); }

        /**
         * @fn  T* SmrtPtr::Release();
         *
         * @brief   Release the pointer from ownership by this SmrtPtr&lt;&gt;, decrementing the objects
         *          refenced count to prevent the object from being deleted even if the reference count
         *          goes to zero. When using Release() you are implicitly expecting other code to take
         *          over management of the object, otherwise a memory leak will result.
         *
         * @return  Null if it fails, else a pointer to a T.
         */
        T* Release() { return mOSGSmartPtr.release(); }

        /**
         * @fn  void SmrtPtr::Swap(SmrtPtr& sp);
         *
         * @brief   Swaps the internal pointer of this and the passed in SmartPtr.
         *
         * @param [in,out]  sp  The smart ppointer.
         */
        void Swap(SmrtPtr& sp) { mOSGSmartPtr.swap(sp); }

        /**
         * @fn  bool SmrtPtr::Valid() const;
         *
         * @brief   Returns True if the smart pointer has a valid internal pointer set
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Valid() const { return mOSGSmartPtr.valid(); }

        /**
         * @fn  bool SmrtPtr::operator!() const;
         *
         * @brief   Logical negation operator.
         *
         * @return  The logical inverse of this value.
         */
        bool operator ! () const { return mOSGSmartPtr.operator!(); }

        /**
         * @fn  T& SmrtPtr::operator*() const;
         *
         * @brief   Dereferences the internal pointer
         *
         * @return  The result of the operation.
         */
        T& operator * () const { return mOSGSmartPtr.operator*(); }

        /**
         * @fn  T* SmrtPtr::operator->() const;
         *
         * @brief   Access to the internal pointer
         *
         * @return  The dereferenced object.
         */
        T* operator -> () const { return mOSGSmartPtr.get(); }

        /**
         * @fn  operator SmrtPtr::T*() const;
         *
         * @brief   Implicit conversion operator to a pointer.
         *
         * @return  The internal pointer
         */
        operator T* () const { return mOSGSmartPtr; }

        /**
         * @fn  operator osg::ref_ptr<T> () const
         *
         * @brief   Implicit conversion operator to OSG ref_ptr.
         *
         * @tparam  T   Generic type parameter.
         *
         * @return  The OSG smart pointer
         */
        operator osg::ref_ptr<T> () const { return mOSGSmartPtr;}

        /**
         * @fn  operator osg::ref_ptr<T>& ()
         *
         * @brief   Implicit conversion operator to OSG ref_ptr.
         *
         * @tparam  T   Generic type parameter.
         *
         * @return  The OSG smart pointer
         */
        operator osg::ref_ptr<T>& () { return mOSGSmartPtr; }

        /**
         * @fn  operator const osg::ref_ptr<T>& () const
         *
         * @brief   Implicit conversion operator to OSG ref_ptr.
         *
         * @tparam  T   Generic type parameter.
         *
         * @return  The OSG smart pointer
         */
        operator const osg::ref_ptr<T>& () const { return mOSGSmartPtr; }

        /**
         * @fn  operator osg::ref_ptr<T>* ()
         *
         * @brief   Implicit conversion operator to OSG ref_ptr.
         *
         * @tparam  T   Generic type parameter.
         *
         * @return  The OSG smart pointer
         */
        operator osg::ref_ptr<T>* () { return &mOSGSmartPtr; }

        /**
         * @fn  friend inline std::ostream& SmrtPtr::operator<<(std::ostream& ios, const SmrtPtr& smPt)
         *
         * @brief   Prints out the memory address of the held pointer.
         *
         * @param [in,out]  ios     The ios.
         * @param           smPt    The smart pointer.
         *
         * @return  A streamed output
         */
        friend inline std::ostream& operator<<(std::ostream& ios, const SmrtPtr& smPt)
        {
            ios << smPt.get();
            return ios;
        }

    private:

        osg::ref_ptr<T> mOSGSmartPtr;  //Pointer to the internal OSG smart pointer

    };    
}

namespace trUtil
{
    /**
     * @brief Hash function for hashing trBase::SmrtPtr
     */
    template<class _Key> struct hash<trBase::SmrtPtr<_Key> >
    {
        size_t operator()(const trBase::SmrtPtr<_Key>& keyPtr) const
        {
            return size_t(keyPtr.Get());
        }
    };

    /**
     * @brief Hash function for hashing osg::ref_ptr
     */
    template<class _Key> struct hash<osg::ref_ptr<_Key> >
    {
        size_t operator()(const trBase::SmrtPtr<_Key>& keyPtr) const
        {
            return size_t(keyPtr.Get());
        }
    };
}