/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
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

#include <trUtil/RefStr.h>
#include <trBase/UniqueId.h>
#include <trManager/MessageBase.h>

#include <string>

/**
    * @class   MessageTest
    *
    * @brief   This is an exmple of a simple message that is passed between actors. 
    */
class MessageTest : public trManager::MessageBase
{
public:
    using BaseClass = trManager::MessageBase;           /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

    /**
        * @fn  MessageTest::MessageTest(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID);
        *
        * @brief   Constructor.
        *
        * @param   fromActorID     Id of the actor that is sending the message.
        * @param   aboutActorID    Identifier for the about actor.
        */
    MessageTest(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID);

    /**
        * @fn  virtual const std::string& MessageTest::GetMessageType() const override;
        *
        * @brief   Returns the Message type.
        *
        * @return  The message type.
        */
    virtual const std::string& GetMessageType() const override;

protected:

    /**
    * @fn  MessageTest::~MessageTest();
    *
    * @brief   Destructor.
    */
    ~MessageTest();
};
