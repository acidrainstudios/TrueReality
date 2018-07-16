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
* @author Maxim Serebrennik
*/

#pragma once

#include "Export.h"

#include <trBase/SmrtPtr.h>
#include <trManager/DirectorPriority.h>
#include <trManager/EntityBase.h>
#include <trManager/ActorBase.h>

namespace trManager
{
    /**
     * @class   DirectorBase
     *
     * @brief   A director base. Serves as the base class for all directors in the Entity System. A director should be used as 
     *          a general manager for an overarching subsystem in the software. 
     */
    class TR_MANAGER_EXPORT DirectorBase : public trManager::ActorBase
    {
    public:
        using BaseClass = trManager::ActorBase;             /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;             /// Holds the class type name for efficient comparisons

        /**
         * @fn  DirectorBase::DirectorBase(const std::string name = CLASS_TYPE);
         *
         * @brief   ctor.
         *
         * @param   name    (Optional) The name.
         */
        DirectorBase(const std::string name = CLASS_TYPE);

        /**
         * @fn  static bool DirectorBase::CompareComponentPriority(const trBase::SmrtPtr<trManager::EntityBase>& first, const trBase::SmrtPtr<trManager::EntityBase>& second);
         *
         * @brief   Local function used to compare priorities of Directors.
         *
         * @param   first   The first.
         * @param   second  The second.
         *
         * @return  True if it succeeds, false if it fails.
         */
        static bool CompareComponentPriority(const trBase::SmrtPtr<trManager::EntityBase>& first, const trBase::SmrtPtr<trManager::EntityBase>& second);

        /**
         * @fn  virtual const std::string& DirectorBase::GetType() const override = 0;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override = 0;

        /**
         * @fn  virtual void DirectorBase::OnTick(const trManager::MessageBase& msg);
         *
         * @brief   Function that will receive Tick Messages from the System Manager.
         *
         * @param   msg The message.
         */
        virtual void OnTick(const trManager::MessageBase& msg);

        /**
         * @fn  virtual void DirectorBase::OnMessage(const trManager::MessageBase& msg);
         *
         * @brief   Function that is used by the Systems Manager to deliver all messages to the Director.
         *
         * @param   msg The message.
         */
        virtual void OnMessage(const trManager::MessageBase& msg);

        /**
         * @fn  virtual void DirectorBase::BuildInvokables() override;
         *
         * @brief   Builds the default invokables for this class.
         */
        virtual void BuildInvokables() override;

        /**
         * @fn  virtual trManager::DirectorPriority& DirectorBase::GetDirectorPriority() const;
         *
         * @brief   Returns the Directors message priority.
         *
         * @return  The director priority.
         */
        virtual trManager::DirectorPriority& GetDirectorPriority() const;

        /**
         * @fn  virtual void DirectorBase::SetDirectorPriority(trUtil::EnumerationPointer<trManager::DirectorPriority> priority);
         *
         * @brief   Sets the Directors message priority. This should only be used by the System Manager.
         *
         * @param   priority    The priority.
         */
        virtual void SetDirectorPriority(trUtil::EnumerationPointer<trManager::DirectorPriority> priority);

    protected:

        /**
         * @fn  DirectorBase::~DirectorBase();
         *
         * @brief   dtor.
         */
        ~DirectorBase();

    private:

        trUtil::EnumerationPointer<trManager::DirectorPriority>  mDirectorPriority;
    };
}