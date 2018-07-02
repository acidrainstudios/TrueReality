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
* @author: Maxim Serebrennik
*/

#pragma once

#include "Export.h"

#include <trManager/MessageBase.h>
#include <trManager/TimingStructure.h>
#include <trBase/UniqueId.h>
#include <trUtil/RefStr.h>

#include <string>

namespace trManager
{
    /**
     * @class   MessageEntityUnregistered
     *
     * @brief   A message that is sent out when an entity is unregistered from the System Manager.
     */
    class  TR_MANAGER_EXPORT MessageEntityUnregistered : public trManager::MessageBase
    {
    public:
        typedef trManager::MessageBase BaseClass;           /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

        /**
         * @fn  MessageEntityUnregistered::MessageEntityUnregistered(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID, const std::string* entityType, const std::string* entityName);
         *
         * @brief   Constructor.
         *
         * @param   fromActorID     Identifier of the entity that is sending this message (usually System
         *                          Manager)
         * @param   aboutActorID    Identifier for the Entity that just unregistered.
         * @param   entityType      Type of the registered entity.
         * @param   entityName      Name of the registered entity.
         */
        MessageEntityUnregistered(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID, const std::string* entityType, const std::string* entityName);

        /**
         * @fn  virtual const std::string& MessageEntityUnregistered::GetMessageType() const override;
         *
         * @brief   Returns the Message type.
         *
         * @return  The message type.
         */
        virtual const std::string& GetMessageType() const override;

        /**
         * @fn  virtual const std::string& MessageEntityUnregistered::GetEntityType() const;
         *
         * @brief   Gets entity type.
         *
         * @return  The entity type.
         */
        virtual const std::string& GetEntityType() const;

        /**
         * @fn  virtual const std::string& MessageEntityUnregistered::GetEntityName() const;
         *
         * @brief   Gets entity type.
         *
         * @return  The entity type.
         */
        virtual const std::string& GetEntityName() const;

    protected:

        /**
         * @fn  MessageEntityUnregistered::~MessageEntityUnregistered();
         *
         * @brief   Destructor.
         */
        ~MessageEntityUnregistered();

    private:

        const std::string* mEntityTypePtr;
        const std::string* mEntityNamePtr;
    };
}