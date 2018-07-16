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

#include <trUtil/RefStr.h>
#include <trBase/UniqueId.h>
#include <trManager/MessageBase.h>
#include <trManager/TimingStructure.h>

#include <string>

namespace trManager
{
    /**
    * @class   MessageTick
    *
    * @brief   This message carries all the inter-frame timing information. Register for this message to receive frame times.
    */
    class TR_MANAGER_EXPORT MessageTick : public trManager::MessageBase
    {
    public:
        using BaseClass = trManager::MessageBase;           /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

        /**
         * @fn  MessageTick::MessageTick(const trBase::UniqueId* fromActorID, const trManager::TimingStructure& timeStruct);
         *
         * @brief   Constructor.
         *
         * @param   fromActorID Id of the actor that is sending the message.
         * @param   timeStruct  The time structure.
         */
        MessageTick(const trBase::UniqueId* fromActorID, const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual const std::string& MessageTick::GetMessageType() const override;
         *
         * @brief   Returns the Message type.
         *
         * @return  The message type.
         */
        virtual const std::string& GetMessageType() const override;

        /**
         * @fn  const int& MessageTick::GetFrameNumber(void) const
         *
         * @brief   Gets frame number.
         *
         * @return  The frame number.
         */
        const int& GetFrameNumber(void) const       { return(*mFrameNumber); }

        /**
         * @fn  const double& MessageTick::GetDeltaSimTime(void) const
         *
         * @brief   Access the DeltaSimTime.
         *
         * @return  The delta simulation time.
         */
        const double& GetDeltaSimTime(void) const           { return(*mDeltaSimTime); }

        /**
         * @fn  const double& MessageTick::GetDeltaRealTime(void) const
         *
         * @brief   Access the DeltaRealTime.
         *
         * @return  The delta real time.
         */
        const double& GetDeltaRealTime(void) const          { return(*mDeltaRealTime); }

        /**
         * @fn  const double& MessageTick::GetSimTime(void) const
         *
         * @brief   Access the SimTime.
         *
         * @return  The simulation time.
         */
        const double& GetSimTime(void) const    { return(*mSimTime); }

        /**
         * @fn  const double& MessageTick::GetRealTime(void) const
         *
         * @brief   Access the RealTime.
         *
         * @return  The real time.
         */
        const double& GetRealTime(void) const       { return(*mRealTime); }

        /**
         * @fn  const double& MessageTick::GetTimeScale(void) const
         *
         * @brief   Access the TimeScale.
         *
         * @return  The time scale.
         */
        const double& GetTimeScale(void) const      { return(*mTimeScale); }

    protected:

        /**
         * @fn  MessageTick::~MessageTick();
         *
         * @brief   Destructor.
         */
        ~MessageTick();

    private:

        const int* mFrameNumber;       //Holds the current frame number. 
        const double* mDeltaSimTime;   //Scaled Time between frames in seconds. 
        const double* mDeltaRealTime;  //Non-scaled Time between frames.
        const double* mSimTime;        //Scaled time of the current simulation run.
        const double* mRealTime;       //Non-scaled time of the current simulation run.
        const double* mTimeScale;      //Time scaler

    };
}