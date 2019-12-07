/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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

#include <trManager/TimingStructure.h>
#include <trManager/DirectorBase.h>
#include <trManager/MessageBase.h>
#include <trUtil/RefStr.h>
#include <trUtil/Timer.h>

namespace trCore
{

    /**
     * @class   SystemDirector
     *
     * @brief   A System director. This Director does all the timing for TR. It controls the frame loop and keeps track of real and sim time. 
     */
    class TR_CORE_EXPORT SystemDirector : public trManager::DirectorBase
    {
    public:
        using BaseClass = trManager::DirectorBase;      /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        const static double MAX_TIME_SCALE;             /// Hold the maximum time scale the system can use for positive and negaive time. 
        const static double MIN_TIME_SCALE;             /// Hold the minimum time scale the system can use for positive and negaive time. 

        /**
         * @fn  SystemDirector::SystemDirector(const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   name    (Optional) The instances name.
         */
        SystemDirector(const std::string name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& SystemDirector::GetType() const override;
         *
         * @brief   Gets the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

        /**
         * @fn  virtual void SystemDirector::OnMessage(const trManager::MessageBase& msg);
         *
         * @brief   This function receives messages coming from the System Manager
         *
         * @param   msg The message.
         */
        virtual void OnMessage(const trManager::MessageBase& msg);

        /**
         * @fn  virtual void SystemDirector::Run();
         *
         * @brief   Runs the systems game loop.
         */
        virtual void Run();

        /**
         * @fn  virtual void SystemDirector::RunOnce();
         *
         * @brief   Advanced the game loop by one frame. Used for testing. 
         */
        virtual void RunOnce();

        /**
         * @fn  virtual bool SystemDirector::IsRunning();
         *
         * @brief   Query if this object is running.
         *
         * @return  True if running, false if not.
         */
        virtual bool IsRunning();

        /**
        * @fn  virtual void SystemDirector::ShutDown();
        *
        * @brief   Shuts down this object and frees any resources it is using.
        */
        virtual void ShutDown();

        /**
         * @fn  trManager::TimingStructure SystemDirector::GetTimeStructure();
         *
         * @brief   Gets a copy of the internal time structure.
         *
         * @return  The time structure.
         */
        trManager::TimingStructure GetTimeStructure();

    protected:

        /**
         * @fn  SystemDirector::~SystemDirector();
         *
         * @brief   Destructor.
         */
        ~SystemDirector();
        
        /**
         * @fn  virtual void SystemDirector::UpdateTiming(trManager::TimingStructure& timeStruct, double dt);
         *
         * @brief   Updates the system timing incrementing it by dt.
         *
         * @param [in,out]  timeStruct  The time structure.
         * @param           dt          The delta time between frames.
         */
        virtual void UpdateTiming(trManager::TimingStructure& timeStruct, double dt);

        /**
         * @fn  virtual void SystemDirector::EventTraversal(const TimingStructure& timeStruct);
         *
         * @brief   Event traversal event function. Sends out an EventTraversalEvent Message.
         *
         * @param   timeStruct  The simulation time structure.
         */
        virtual void EventTraversal(const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual void SystemDirector::PostEventTraversal(const TimingStructure& timeStruct);
         *
         * @brief   Post event traversal event function. Sends out a PostEventTraversalEvent Message.
         *
         * @param   timeStruct  The simulation time structure.
         */
        virtual void PostEventTraversal(const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual void SystemDirector::PreFrame(const TimingStructure& timeStruct);
         *
         * @brief   Pre frame event function. Sends out a PreFrameEvent Message. Sends out a Tick()
         *          Message.
         *
         * @param   timeStruct  The simulation time structure.
         */
        virtual void PreFrame(const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual void SystemDirector::CameraSynch(const TimingStructure& timeStruct);
         *
         * @brief   Camera synchronization event function. Sends out a CameraSynchEvent Message.
         *
         * @param   timeStruct  The simulation time structure.
         */
        virtual void CameraSynch(const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual void SystemDirector::FrameSynch(const TimingStructure& timeStruct);
         *
         * @brief   Frame synchronization event function. Sends out a FrameSynchEvent Message.
         *
         * @param   timeStruct  The simulation time structure.
         */
        virtual void FrameSynch(const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual void SystemDirector::Frame(const TimingStructure& timeStruct);
         *
         * @brief   Frame event function. Sends out FrameEvent Message.
         *
         * @param   timeStruct  The simulation time structure.
         */
        virtual void Frame(const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual void SystemDirector::PostFrame(const TimingStructure& timeStruct);
         *
         * @brief   Post frame event function. Sends out PostFrameEvent Message.
         *
         * @param   timeStruct  The simulation time structure.
         */
        virtual void PostFrame(const trManager::TimingStructure& timeStruct);

        /**
         * @fn  virtual void SystemDirector::SetTimeScale(const double timeScale);
         *
         * @brief   Sets the system time scale.
         *
         * @param   timeScale   The time scale.
         */
        virtual void SetTimeScale(const double timeScale);

        /**
         * @fn  virtual void SystemDirector::IncrementTimeScale();
         *
         * @brief   Increment the system time scale.
         */
        virtual void IncrementTimeScale();

        /**
         * @fn  virtual void SystemDirector::DecrementTimeScale();
         *
         * @brief   Decrement the system time scale.
         */
        virtual void DecrementTimeScale();

        /**
         * @fn  virtual void SystemDirector::CheckForShutdown();
         *
         * @brief   Checks for a shutdown, and cleares the System Manager if in process.
         */
        virtual void CheckForShutdown();

    private:

        bool mIsRunning = false;
        bool mIsShuttingDown = false;
        bool mIsPaused = false;
        trUtil::Timer mSystemTimer;

        trManager::TimingStructure mTimeStruct;
    };
}

