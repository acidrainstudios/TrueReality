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

#include <trManager/MessageTick.h>
#include <trManager/TimingStructure.h>
#include <trBase/UniqueId.h>
#include <trUtil/RefStr.h>

#include <string>

namespace trCore
{
    /**
     * @class   MessageFrame
     *
     * @brief   A message that is sent out on Frame Event.
     */
    class  TR_CORE_EXPORT MessageFrame : public trManager::MessageTick
    {
    public:
        typedef trManager::MessageTick BaseClass;           /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

        /**
         * @fn  MessageFrame::MessageFrame(const trBase::UniqueId* fromActorID, const trManager::TimingStructure& timeStruct);
         *
         * @brief   Constructor.
         *
         * @param   fromActorID Id of the actor that is sending the message.
         * @param   timeStruct  The time structure.
         */
        MessageFrame(const trBase::UniqueId* fromActorID, const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual const std::string& MessageFrame::GetMessageType() const override;
         *
         * @brief   Returns the Message type.
         *
         * @return  The message type.
         */
        virtual const std::string& GetMessageType() const override;

    protected:

        /**
         * @fn  MessageFrame::~MessageFrame();
         *
         * @brief   Destructor.
         */
        ~MessageFrame();
    };
}


