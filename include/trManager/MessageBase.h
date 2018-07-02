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

#include <trManager/Export.h>

#include <trUtil/StringUtils.h>
#include <trUtil/RefStr.h>
#include <trBase/ObsrvrPtr.h>
#include <trBase/SmrtClass.h>
#include <trBase/UniqueId.h>

#include <string>

namespace trManager
{
    /**
    * This is the base class for all the messages in TR. It is immutable, 
    * and all messages derived from it should keep that tradition. 
    */
    class TR_MANAGER_EXPORT MessageBase : public trBase::SmrtClass
    {
    public:
        
        typedef trBase::SmrtClass BaseClass;                /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

        /**
         * @fn  MessageBase::MessageBase(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID = NULL, const bool isDirect = false, const std::string &messageFilter = trUtil::StringUtils::STR_BLANK);
         *
         * @brief   ctor.
         *
         * @param   fromActorID     Id of the actor this message is being sent from.
         * @param   aboutActorID    (Optional) Id of the actor this message is being sent to, or is about.
         * @param   isDirect        (Optional) If TRUE, this message will skip all the Directors.
         * @param   messageFilter   (Optional) A custom filter for developer use.
         */
        MessageBase(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID = NULL, const bool isDirect = false, const std::string &messageFilter = trUtil::StringUtils::STR_BLANK);

        bool operator==(const MessageBase& msg) const;
        bool operator!=(const MessageBase& msg) const { return !(*this == msg); }

        /**
         * @fn  virtual const std::string& MessageBase::GetMessageType() const = 0;
         *
         * @brief   Returns the Message type.
         *
         * @return  The message type.
         */
        virtual const std::string& GetMessageType() const = 0;

        /**
         * @fn  virtual const trBase::UniqueId* MessageBase::GetFromActorID() const;
         *
         * @brief   Returns the ID of the actor the message was sent from. The ID should never be empty.
         *
         * @return  Null if it fails, else the data that was read from the actor identifier.
         */
        virtual const trBase::UniqueId* GetFromActorID() const;

        /**
         * @fn  virtual const trBase::UniqueId* MessageBase::GetAboutActorID() const;
         *
         * @brief   Returns the ID of the actor this message is about, or sent to. This ID can be empty
         *          if the message is not directed toward a specific Actor.
         *
         * @return  Null if it fails, else the about actor identifier.
         */
        virtual const trBase::UniqueId* GetAboutActorID() const;

        /**
         * @fn  virtual const bool& MessageBase::GetIsDirect() const;
         *
         * @brief   Returns True if this message is a direct message and skips all Directors.
         *
         * @return  The is direct.
         */
        virtual const bool& GetIsDirect() const;

        /**
         * @fn  virtual const std::string& MessageBase::GetMessageFilter();
         *
         * @brief   Returns the custom Filter string.
         *
         * @return  The message filter.
         */
        virtual const std::string& GetMessageFilter();

    protected:

        /**
         * @fn  MessageBase::~MessageBase();
         *
         * @brief   dtor.
         */
        ~MessageBase();

        /**
         * @fn  virtual const std::string& MessageBase::GetType() const override;
         *
         * @brief   Returns the class type Made protected to hide it.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

    private:

        trBase::ObsrvrPtr<const trBase::UniqueId> mFromActorID, mAboutActorID;
        bool mIsDirect;
        const std::string *mMessageFilter;
        trBase::UniqueId mId;
    };
}



