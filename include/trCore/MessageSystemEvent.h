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
#include <trCore/SystemEvents.h>
#include <trBase/UniqueId.h>

namespace trCore
{
    class TR_CORE_EXPORT MessageSystemEvent : public trManager::MessageBase
    {
    public:
        typedef trManager::MessageBase BaseClass;           /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

        /**
         * @fn  MessageSystemEvent::MessageSystemEvent(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID, trCore::SystemEvents &systemEvent);
         *
         * @brief   Constructor.
         *
         * @param           fromActorID     Id of the actor this message is being sent from.
         * @param           aboutActorID    Id of the actor this message is being sent to, or is about.
         * @param [in,out]  systemEvent     The system event type.
         */
        MessageSystemEvent(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID, const trCore::SystemEvents &systemEvent);

        /**
         * @fn  virtual const std::string& MessageSystemEvent::GetMessageType() const override;
         *
         * @brief   Returns the Message type.
         *
         * @return  The message type.
         */
        virtual const std::string& GetMessageType() const override;

        /**
         * @fn  virtual const trCore::SystemEvents& MessageSystemEvent::GetSysEventType() const;
         *
         * @brief   Gets system event type.
         *
         * @return  The system event type.
         */
        virtual const trCore::SystemEvents& GetSysEventType() const;

    protected:

        /**
         * @fn  MessageSystemEvent::~MessageSystemEvent();
         *
         * @brief   Destructor.
         */
        ~MessageSystemEvent();

    private:

        const trCore::SystemEvents* mSystemEvent;
    };
}
