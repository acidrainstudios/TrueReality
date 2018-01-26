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

#include "Export.h"

#include <trBase/SmrtPtr.h>
#include <trManager/ActorBase.h>

namespace trManager
{
    /**
     * @class   ActorModuleBase
     *
     * @brief   An actor module base class that will serve as a base for all actor modules. 
     *          This class is used to extend the functionality of actors. While you can register 
     *          this class for messages, that should be used sparingly, and all communication 
     *          most likely should be done through the parent actor. 
     */
    class TR_MANAGER_EXPORT ActorModuleBase : public trManager::ActorBase
    {
    public:
        typedef trManager::ActorBase BaseClass;             /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;             /// Holds the class type name for efficient comparisons

        /**
         * @fn  ActorModuleBase::ActorModuleBase(const std::string name = CLASS_TYPE);
         *
         * @brief   ctor.
         *
         * @param   name    (Optional) The name.
         */
        ActorModuleBase(const std::string name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& ActorModuleBase::GetType() const override = 0;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override = 0;

        /**
         * @fn  virtual void ActorModuleBase::OnTick(const trManager::MessageBase& msg);
         *
         * @brief   Function that will receive Tick Messages from the System Manager.
         *
         * @param   msg The message.
         */
        virtual void OnTick(const trManager::MessageBase& msg);

        /**
         * @fn  virtual void ActorModuleBase::OnMessage(const trManager::MessageBase& msg);
         *
         * @brief   Function that is used by the Systems Manager to deliver all messages to the Director.
         *
         * @param   msg The message.
         */
        virtual void OnMessage(const trManager::MessageBase& msg);

        /**
         * @fn  virtual void ActorModuleBase::BuildInvokables() override;
         *
         * @brief   Builds the default invokables for this class.
         */
        virtual void BuildInvokables() override;

    protected:

        /**
         * @fn  ActorModuleBase::~ActorModuleBase();
         *
         * @brief   dtor.
         */
        ~ActorModuleBase();        
    };
}