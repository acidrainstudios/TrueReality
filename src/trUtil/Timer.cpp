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

#include <trUtil/Timer.h>

#include <OpenThreads/Thread>

namespace trUtil
{

    //////////////////////////////////////////////////////////////////////////
    void AppSleep(unsigned int milliseconds)
    {
       if (milliseconds == 0)
       {
          OpenThreads::Thread::YieldCurrentThread();
       }
       else
       {
          OpenThreads::Thread::microSleep((milliseconds) * 1000);
       }
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    Timer::Timer()
    {

    }

    //////////////////////////////////////////////////////////////////////////
    Timer::~Timer()
    {

    }

    //////////////////////////////////////////////////////////////////////////
    const Timer* Timer::Instance()
    {
       static Timer sTimer;
       return &sTimer;
    }

    //////////////////////////////////////////////////////////////////////////
    void Timer::SetStartTick(TimeTicks t) 
    { 
        mTimer.setStartTick(t); 
        mOldTicks = mNewTicks;
        mNewTicks = t;
        mCustomTicks = (mNewTicks - mTimer.tick());
    }
}

