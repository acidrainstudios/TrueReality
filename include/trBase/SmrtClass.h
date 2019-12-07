/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
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

#include <trBase/Export.h>

#include <osg/Referenced>

#include <string>

namespace trBase
{
    /**
    * This class is part of the internal garbage collection system. Anything that inherits it can also use the
    * smart pointer interface (trBase::SmrtPtr)
    *
    * It inherits osg::Referenced and uses the OSG garbage collection in its core
    */
    class TR_BASE_EXPORT SmrtClass : public osg::Referenced
    {
    public:

        using BaseClass = osg::Referenced;                 /// Adds an easy and swappable access to the base class        

        /**
         * @fn  SmrtClass::SmrtClass() : osg::Referenced()
         *
         * @brief   Default constructor.
         */
        SmrtClass() : osg::Referenced()
        {}

        /**
         * @fn  explicit SmrtClass::SmrtClass(bool threadSafeRefUnref) : osg::Referenced(threadSafeRefUnref)
         *
         * @brief   Constructor.
         *
         * @param   threadSafeRefUnref  True to thread safe reference unref.
         */
        explicit SmrtClass(bool threadSafeRefUnref) : osg::Referenced(threadSafeRefUnref)
        {}

        /**
         * @fn  SmrtClass::SmrtClass(const SmrtClass& inst) : osg::Referenced(inst)
         *
         * @brief   Copy constructor.
         *
         * @param   inst    The instance.
         */
        SmrtClass(const SmrtClass& inst) : osg::Referenced(inst)
        {}

        /**
         * @fn  virtual bool SmrtClass::GetThreadSafeRefUnref();
         *
         * @brief   Get whether a mutex is used to ensure Ref() and UnRef() are thread safe.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool GetThreadSafeRefUnref();

        /**
         * @fn  OpenThreads::Mutex* SmrtClass::GetRefMutex() const;
         *
         * @brief   Get the mutex used to ensure thread safety of Ref()/UnRef().
         *
         * @return  Null if it fails, else the reference mutex.
         */
        OpenThreads::Mutex* GetRefMutex() const;

        /**
         * @fn  static OpenThreads::Mutex* SmrtClass::GetGlobalReferencedMutex();
         *
         * @brief   Get the optional global Referenced mutex, this can be shared between all
         *          trBase::SmrtClass.
         *
         * @return  Null if it fails, else the global referenced mutex.
         */
        static OpenThreads::Mutex* GetGlobalReferencedMutex();

        /**
         * @fn  inline int SmrtClass::Ref() const;
         *
         * @brief   Increment the reference count by one, indicating that this object has another pointer
         *          which is referencing it.
         *
         * @return  An int.
         */
        inline int Ref() const;

        /**
         * @fn  inline int SmrtClass::Unref() const;
         *
         * @brief   Decrement the reference count by one, indicating that a pointer to this object is no
         *          longer referencing it.  If the reference count goes to zero, it is assumed that this
         *          object is no longer referenced and is automatically deleted.
         *
         * @return  An int.
         */
        inline int Unref() const;

        /**
         * @fn  int SmrtClass::UnRefNoDelete() const;
         *
         * @brief   Decrement the reference count by one, indicating that a pointer to this object is no
         *          longer referencing it.  However, do not delete it, even if ref count goes to 0.
         *          Warning, UnRefNoDelete() should only be called if the user knows exactly who will be
         *          responsible for it, one should prefer UnRef() over UnRefNoDelete() as the latter can
         *          lead to memory leaks.
         *
         * @return  An int.
         */
        int UnRefNoDelete() const;

        /**
         * @fn  inline int SmrtClass::ReferenceCount() const;
         *
         * @brief   Return the number of pointers currently referencing this object.
         *
         * @return  An int.
         */
        inline int ReferenceCount() const;

        /**
         * @fn  virtual const std::string& SmrtClass::GetType() const = 0;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const = 0;

    protected:
        ~SmrtClass()
        {}
    };
}


