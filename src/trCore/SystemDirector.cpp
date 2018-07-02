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

#include <trCore/SystemDirector.h>

#include <trCore/MessagePostEventTraversal.h>
#include <trCore/MessageEventTraversal.h>
#include <trCore/MessageSystemControl.h>
#include <trCore/MessageCameraSynch.h>
#include <trCore/MessageFrameSynch.h>
#include <trCore/MessagePostFrame.h>
#include <trCore/MessageFrame.h>
#include <trCore/MessageSystemEvent.h>
#include <trCore/SystemControls.h>
#include <trCore/SystemEvents.h>
#include <trManager/SystemManager.h>
#include <trManager/MessageTick.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/Logging/Log.h>

namespace trCore
{
    const trUtil::RefStr SystemDirector::CLASS_TYPE = trUtil::RefStr("trCore::SystemDirector");

    const double SystemDirector::MAX_TIME_SCALE = 1048576;              /// Hold the maximum time scale the system can use for positive and negative time (2^20). 
    const double SystemDirector::MIN_TIME_SCALE = 0.03125;              /// Hold the minimum time scale the system can use for positive and negative time (1/32).

    //////////////////////////////////////////////////////////////////////////
    SystemDirector::SystemDirector(const std::string name) : BaseClass(name)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    SystemDirector::~SystemDirector()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& SystemDirector::GetType() const
    {
        return CLASS_TYPE;
    } 

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::OnMessage(const trManager::MessageBase& msg)
    {
        if (msg.GetMessageType() == MessageSystemControl::MESSAGE_TYPE)
        {
            const trCore::MessageSystemControl& message = static_cast<const trCore::MessageSystemControl&>(msg);

            if (message.GetSysControlType() == trCore::SystemControls::PAUSE)
            {
                mIsPaused = true;
            }
            else if (message.GetSysControlType() == trCore::SystemControls::UNPAUSE)
            {
                mIsPaused = false;
            }
            else if (message.GetSysControlType() == trCore::SystemControls::SPEED_UP)
            {
                IncrementTimeScale();
            }
            else if (message.GetSysControlType() == trCore::SystemControls::SPEED_DOWN)
            {
                DecrementTimeScale();
            }
            else if (message.GetSysControlType() == trCore::SystemControls::SET_TIME_SCALE)
            {
                SetTimeScale(message.GetSystemValue());
            }
            else if (message.GetSysControlType() == trCore::SystemControls::SHUT_DOWN)
            {
                ShutDown();
            }            
        }    
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::Run()
    {
        //Call the initial Tick to start the timer
        mSystemTimer.SetStartTick(0);

        //Enable the run loop
        mIsRunning = true;

        while (mIsRunning)
        {
            if (IsRegistered())
            {
                LOG_D("\n***************** Starting Frame #" + trUtil::StringUtils::ToString<int>(mTimeStruct.frameNumber))

                EventTraversal(mTimeStruct);
                PostEventTraversal(mTimeStruct);
                PreFrame(mTimeStruct);
                CameraSynch(mTimeStruct);
                FrameSynch(mTimeStruct);
                Frame(mTimeStruct);
                PostFrame(mTimeStruct);

                LOG_D("\n***************** Ending Frame #" + trUtil::StringUtils::ToString<int>(mTimeStruct.frameNumber))

                //Get the time between frames in seconds
                mSystemTimer.Tick();

                //Update System Timing
                UpdateTiming(mTimeStruct, mSystemTimer.GetSecondsPerTick());
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::RunOnce()
    {
        //Call the initial Tick to start the timer
        if (!mIsRunning)
        {
            mSystemTimer.SetStartTick(0);
        }        

        //Enable the run loop
        mIsRunning = true;

        if (mIsRunning)
        {
            if (IsRegistered())
            {
                LOG_D("\n***************** Starting Frame #" + trUtil::StringUtils::ToString<int>(mTimeStruct.frameNumber))

                EventTraversal(mTimeStruct);
                PostEventTraversal(mTimeStruct);
                PreFrame(mTimeStruct);
                CameraSynch(mTimeStruct);
                FrameSynch(mTimeStruct);
                Frame(mTimeStruct);
                PostFrame(mTimeStruct);

                LOG_D("\n***************** Ending Frame #" + trUtil::StringUtils::ToString<int>(mTimeStruct.frameNumber))

                    //Get the time between frames in seconds
                    mSystemTimer.Tick();

                //Update System Timing
                UpdateTiming(mTimeStruct, mSystemTimer.GetSecondsPerTick());
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemDirector::IsRunning()
    {
        return mIsRunning;
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::ShutDown()
    {
        LOG_D("Shutting down System")

        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::SHUTTING_DOWN);
        SendMessage(*msg);
        mIsRunning = false;
        mIsShuttingDown = true;
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::TimingStructure SystemDirector::GetTimeStructure()
    {
        return mTimeStruct;
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::UpdateTiming(trManager::TimingStructure& timeStruct, double dt)
    {
        //If the sim is paused, we should make dt = 0
        if (!mIsPaused)
        {
            timeStruct.deltaSimTime = dt * timeStruct.timeScale;
        }
        else
        {
            timeStruct.deltaSimTime = 0.;
        }
        
        timeStruct.deltaRealTime = dt;
        timeStruct.realTime += dt;
        timeStruct.simTime += timeStruct.deltaSimTime;
        timeStruct.frameNumber++;
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::EventTraversal(const trManager::TimingStructure& timeStruct)
    {
        LOG_D("Event Traversal")
        //Create and send out an Event Traversal System Event Message
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::EVENT_TRAVERSAL);
        SendMessage(*msg);
        //Create and send out an Event Traversal Message
        trBase::SmrtPtr<trCore::MessageEventTraversal> et = new trCore::MessageEventTraversal(&this->GetUUID(), timeStruct);
        SendMessage(*et);
        //Make the System Manager send out all its queued messages
        mSysMan->ProcessMessages();

        //Make the System Manager send out all its queued messages after the Event Traversal and System Event messages got processed. 
        mSysMan->ProcessMessages();
    }
    
    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::PostEventTraversal(const trManager::TimingStructure& timeStruct)
    {
        LOG_D("Post Event Traversal")
        //Create and send out an Post Event Traversal System Event Message
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::POST_EVENT_TRAVERSAL);
        mSysMan->ProcessMessage(*msg);
        //Create and queue the Post Event Traversal Message
        trBase::SmrtPtr<trCore::MessagePostEventTraversal> pet = new trCore::MessagePostEventTraversal(&this->GetUUID(), timeStruct);
        SendMessage(*pet);
        //Make the System Manager send out all its queued messages
        mSysMan->ProcessMessages();

        //Make the System Manager send out all its queued messages after the Post Event Traversal and System Event messages got processed.
        mSysMan->ProcessMessages();
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::PreFrame(const trManager::TimingStructure& timeStruct)
    {
        LOG_D("Pre Frame")
        //Create and queue out an Pre Frame System Event Message
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::PRE_FRAME);
        SendMessage(*msg);
        //Create and queue the Tick Message
        trBase::SmrtPtr<trManager::MessageTick> tick = new trManager::MessageTick(&this->GetUUID(), timeStruct);
        SendMessage(*tick);
        //Send out the two Queues messaged
        mSysMan->ProcessMessages();

        //Make the System Manager send out all its queued messages after the PreFrame and Tick messages got processed. 
        mSysMan->ProcessMessages();
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::CameraSynch(const trManager::TimingStructure& timeStruct)
    {
        LOG_D("Camera Synch")
        //Create and send out an Camera Synch System Event Message
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::CAMERA_SYNCH);
        mSysMan->ProcessMessage(*msg);
        //Create and queue the Camera Sync Message
        trBase::SmrtPtr<trCore::MessageCameraSynch> cs = new trCore::MessageCameraSynch(&this->GetUUID(), timeStruct);
        SendMessage(*cs);
        //Send out the two Queues messaged
        mSysMan->ProcessMessages();

        //Make the System Manager send out all its queued messages after the Camera Synch and System Event messages got processed.
        mSysMan->ProcessMessages();
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::FrameSynch(const trManager::TimingStructure& timeStruct)
    {
        LOG_D("Frame Synch")
        //Create and send out an Frame Synch System Event Message
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::FRAME_SYNCH);
        mSysMan->ProcessMessage(*msg);
        //Create and queue the Frame Sync Message
        trBase::SmrtPtr<trCore::MessageFrameSynch> fs = new trCore::MessageFrameSynch(&this->GetUUID(), timeStruct);
        SendMessage(*fs);
        //Send out the two Queues messaged
        mSysMan->ProcessMessages();

        //Make the System Manager send out all its queued messages after the Frame Synch and System Event messages got processed.
        mSysMan->ProcessMessages();
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::Frame(const trManager::TimingStructure& timeStruct)
    {
        LOG_D("Frame")
        //Create and send out a Frame System Event Message
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::FRAME);
        SendMessage(*msg);
        //Create and queue the Frame Message
        trBase::SmrtPtr<trCore::MessageFrame> frame = new trCore::MessageFrame(&this->GetUUID(), timeStruct);
        SendMessage(*frame);
        //Send out the two Queues messaged
        mSysMan->ProcessMessages();

        //Make the System Manager send out all its queued messages after the Frame and System Event messages got processed.
        mSysMan->ProcessMessages();
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::PostFrame(const trManager::TimingStructure& timeStruct)
    {
        LOG_D("Post Frame")
        //Create and send out an Post Frame System Event Message
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::POST_FRAME);
        SendMessage(*msg);
        //Create and queue the Frame Message
        trBase::SmrtPtr<trCore::MessagePostFrame> pf = new trCore::MessagePostFrame(&this->GetUUID(), timeStruct);
        SendMessage(*pf);
        //Send out the two Queues messaged
        mSysMan->ProcessMessages();

        //Make the System Manager send out all its queued messages after the Post Frame and System Event messages got processed.
        mSysMan->ProcessMessages();

        //Removes all entities that were unregistered during this frame. 
        mSysMan->RemoveMarkedEntities();

        //Check if we entered the shutdown phase.
        CheckForShutdown();
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::SetTimeScale(const double timeScale)
    {
        if (timeScale > MAX_TIME_SCALE)
        {
            mTimeStruct.timeScale = MAX_TIME_SCALE;
        }
        else if (timeScale < -MAX_TIME_SCALE)
        {
            mTimeStruct.timeScale = -MAX_TIME_SCALE;
        }
        else if (-MIN_TIME_SCALE < timeScale  && timeScale < MIN_TIME_SCALE)
        {
            mTimeStruct.timeScale = 0.;
        }
        else
        {
            mTimeStruct.timeScale = timeScale;
        }
        trBase::SmrtPtr<trCore::MessageSystemEvent> msg = new trCore::MessageSystemEvent(&this->GetUUID(), NULL, SystemEvents::TIME_SCALE_CHANGED);
        SendMessage(*msg);

        LOG_D("Time Scale Changed to: " + trUtil::StringUtils::ToString<double>(mTimeStruct.timeScale))
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::IncrementTimeScale()
    {
        double timeScale = mTimeStruct.timeScale;
        if (timeScale > 0)
        {
            SetTimeScale(timeScale * 2.);
        }
        else
        {
            timeScale /= 2.;
            if (timeScale > -MIN_TIME_SCALE)
            {
                SetTimeScale(MIN_TIME_SCALE);
            }
            else
            {
                SetTimeScale(timeScale);
            }
        }

        LOG_D("Time Scale Incremented to: " + trUtil::StringUtils::ToString<double>(mTimeStruct.timeScale))
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::DecrementTimeScale()
    {
        double timeScale = mTimeStruct.timeScale;
        if (timeScale > 0)
        {
            timeScale /= 2.;
            if (timeScale < MIN_TIME_SCALE)
            {
                SetTimeScale(-MIN_TIME_SCALE);
            }
            else
            {
                SetTimeScale(timeScale);
            }
        }
        else
        {
            SetTimeScale(timeScale * 2.);            
        }

        LOG_D("Time Scale Decremented to: " + trUtil::StringUtils::ToString<double>(mTimeStruct.timeScale))
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemDirector::CheckForShutdown()
    {
        if (mIsShuttingDown)
        {
            mSysMan->ShutDown();
        }
    }

}
