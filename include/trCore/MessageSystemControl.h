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

#include <trManager/MessageBase.h>
#include <trCore/SystemControls.h>
#include <trBase/UniqueId.h>

namespace trCore
{
    /**
    * @class   MessageSystemControl
    *
    * @brief   A message that lets the system know what state to enable and setup.
    */
    class TR_CORE_EXPORT MessageSystemControl : public trManager::MessageBase
    {
    public:
        using BaseClass = trManager::MessageBase;           /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

        /**
         * @fn  MessageSystemControl::MessageSystemControl(const trBase::UniqueId* fromActorID, const trCore::SystemControls &systemControl, double systemValue = 0);
         *
         * @brief   Constructor.
         *
         * @param   fromActorID     Identifier for from actor.
         * @param   systemControl   The system control.
         * @param   systemValue     (Optional) The system value is used to pass data for specific
         *                          Controls. Not all Controls need one.
         */
        MessageSystemControl(const trBase::UniqueId* fromActorID, const trCore::SystemControls &systemControl, double systemValue = 0);

        /**
         * @fn  virtual const std::string& MessageSystemControl::GetMessageType() const override;
         *
         * @brief   Returns the Message type.
         *
         * @return  The message type.
         */
        virtual const std::string& GetMessageType() const override;

        /**
         * @fn  virtual trCore::SystemControls& MessageSystemControl::GetSysControlType();
         *
         * @brief   Gets system control type.
         *
         * @return  The system control type.
         */
        virtual const trCore::SystemControls& GetSysControlType() const;

        /**
         * @fn  virtual double MessageSystemControl::GetSystemValue() const;
         *
         * @brief   Gets system value.
         *
         * @return  The system value.
         */
        virtual double GetSystemValue() const;

    protected:

        /**
         * @fn  MessageSystemControl::~MessageSystemControl();
         *
         * @brief   Destructor.
         */
        ~MessageSystemControl();

    private:

        const trCore::SystemControls* mSystemControl;
        double mSystemValue;

    };
}

