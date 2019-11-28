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
* @author David Guthrie
* @author Maxim Serebrennik
*/

#pragma once

#include <trManager/Export.h>

#include <trManager/MessageBase.h>
#include <trBase/SmrtClass.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Functor.h>
#include <trUtil/RefStr.h>

#include <string>

namespace trManager
{
    class TR_MANAGER_EXPORT InvokableFunctorCallerBase : public trBase::SmrtClass
    {
    public:
        const static trUtil::RefStr CLASS_TYPE;                 /// Holds the class type name for efficient comparisons

        /**
         * @fn  virtual const std::string& InvokableFunctorCallerBase::GetType() const override
         *
         * @brief   Gets the type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override { return CLASS_TYPE; }

        virtual void Call(const trManager::MessageBase& message) = 0;
    };

    template <typename Message_T = trManager::MessageBase>
    class TR_MANAGER_EXPORT InvokableFunctorCaller : public InvokableFunctorCallerBase
    {
    public:
        using InvokableFunc = trUtil::Functor<void, TYPELIST_1(const Message_T&)>;

        InvokableFunctorCaller(InvokableFunc func)
            : mFunctor(func)
        {
        }

        virtual void Call(const trManager::MessageBase& message)
        {
            mFunctor(static_cast<const Message_T&>(message));
        }
    private:
        InvokableFunc mFunctor;
    };

    /**
     * @class   Invokable
     *
     * @brief   An Invokable is a queriable method interface that can be added to a
     *          trManager::ActorBase 
     *          Invoking the invokable requires a trManager::MessageBase as a parameter.  The actual
     *          code is executed by calling a Functor that takes 1 parameter, the message, and
     *          returns nothing.  The method must take a const Method reference.
     *
     * @sa  trManager::MessageBase
     */
    class TR_MANAGER_EXPORT Invokable : public trBase::SmrtClass
    {
    public:

        const static trUtil::RefStr CLASS_TYPE;                 /// Holds the class type name for efficient comparisons

        /**
         * @fn  virtual const std::string& Invokable::GetType() const override
         *
         * @brief   Gets the type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override { return CLASS_TYPE;}

        using InvokableFunc = trUtil::Functor<void, TYPELIST_1(const trManager::MessageBase&)>;

        template<typename Message_T>
        Invokable(const std::string& name, trUtil::Functor<void, TYPELIST_1(const Message_T&)> toInvoke)
            : mName(name)
            , mCaller(new InvokableFunctorCaller<Message_T>(toInvoke))
        {
        }

        /**
         * @fn  Invokable(const Invokable&)
         *
         * @brief   Deleted copy constructor.
         */
        Invokable(const Invokable&) = delete;

        /**
        * @return the name of this invokable.
        */
        const std::string& GetName() const { return mName; }

        /**
        * Invoke this.
        * @param message the message to invoke.
        */
        void Invoke(const trManager::MessageBase& message);
    protected:
        ///referenced classes should always have protected destructor
        virtual ~Invokable();
    private:
        std::string mName;

        trBase::SmrtPtr<InvokableFunctorCallerBase> mCaller;

        Invokable& operator=(const Invokable&) { return *this; }
    };
}

