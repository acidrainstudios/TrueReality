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

#include <trUtil/Export.h>

#include <osg/Timer>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{    

#if defined(_MSC_VER)
    /** @brief   64bit Integer to hold the Timers time ticks. */
    using TimeTicks = unsigned __int64;
#else
    /** @brief   64bit Integer to hold the Timers time ticks. */
    using TimeTicks = unsigned long long;
#endif

    /**
     * @fn  void AppSleep(unsigned int milliseconds);
     *
     * @brief   Puts the current application thread to sleep for a given number of milliseconds.
     *
     * @return  A TR_UTIL_EXPORT.
     *
     * @param   milliseconds    The milliseconds.
     *                          
     * @author Maxim Serebrennik
     */
    void TR_UTIL_EXPORT AppSleep(unsigned int milliseconds);

    /**
     * @class   Timer
     *
     * @brief   Timer class is used for measuring elapsed time or time between two points.
     *          
     * @author Maxim Serebrennik
     */
    class TR_UTIL_EXPORT Timer
    {
    public:

        /**
         * @fn  Timer::Timer();
         *
         * @brief   Default constructor.
         */
        Timer();

        /**
         * @fn  Timer::~Timer();
         *
         * @brief   Destructor.
         */
        ~Timer();

        /**
         * @fn  static const Timer* Timer::Instance();
         *
         * @brief   Creates and returns a global timer. This allows the user to use the timer class as a
         *          singleton. It can still be declared locally though, without the use of Instance()
         *
         * @return  Null if it fails, else a pointer to a const Timer.
         */
        static const Timer* Instance();

        /**
         * @fn  TimeTicks Timer::Tick()
         *
         * @brief   Get the timers tick value.
         *
         * @return  The TimeTicks.
         */
        TimeTicks Tick() 
        {
            mOldTicks = mNewTicks;
            mNewTicks = (mTimer.tick() + mCustomTicks);
            return mNewTicks;
        }

        /**
         * @fn  void Timer::SetStartTick()
         *
         * @brief   Set the start tick.
         */
        void SetStartTick() { mTimer.setStartTick(); }

        /**
         * @fn  void Timer::SetStartTick(TimeTicks t);
         *
         * @brief   Set the start tick to a custom value.
         *
         * @param   t   The TimeTicks to process.
         */
        void SetStartTick(TimeTicks t);

        /**
         * @fn  TimeTicks Timer::GetStartTick() const
         *
         * @brief   Get the value of the start tick.
         *
         * @return  The start tick.
         */
        TimeTicks GetStartTick() const { return mTimer.getStartTick(); }

        /**
         * @fn  double Timer::DeltaSec(TimeTicks t1, TimeTicks t2) const
         *
         * @brief   Get the time in seconds between timer ticks t1 and t2.
         *
         * @param   t1  The first TimeTicks.
         * @param   t2  The second TimeTicks.
         *
         * @return  A double.
         */
        double DeltaSec(TimeTicks t1, TimeTicks t2) const { return mTimer.delta_s(t1, t2); }

        /**
         * @fn  double Timer::DeltaMil(TimeTicks t1, TimeTicks t2) const
         *
         * @brief   Get the time in milliseconds between timer ticks t1 and t2.
         *
         * @param   t1  The first TimeTicks.
         * @param   t2  The second TimeTicks.
         *
         * @return  A double.
         */
        double DeltaMil(TimeTicks t1, TimeTicks t2) const { return mTimer.delta_m(t1, t2); }

        /**
         * @fn  double Timer::DeltaMicro(TimeTicks t1, TimeTicks t2) const
         *
         * @brief   Get the time in microseconds between timer ticks t1 and t2.
         *
         * @param   t1  The first TimeTicks.
         * @param   t2  The second TimeTicks.
         *
         * @return  A double.
         */
        double DeltaMicro(TimeTicks t1, TimeTicks t2) const { return mTimer.delta_u(t1, t2); }

        /**
         * @fn  double Timer::DeltaNano(TimeTicks t1, TimeTicks t2) const
         *
         * @brief   Get the time in nanoseconds between timer ticks t1 and t2.
         *
         * @param   t1  The first TimeTicks.
         * @param   t2  The second TimeTicks.
         *
         * @return  A double.
         */
        double DeltaNano(TimeTicks t1, TimeTicks t2) const { return mTimer.delta_n(t1, t2); }

        /**
         * @fn  double Timer::ElapsedSeconds() const
         *
         * @brief   Get elapsed time in seconds.
         *
         * @return  A double.
         */
        double ElapsedSeconds() const { return mTimer.time_s(); }

        /**
         * @fn  double Timer::ElapsedMilliseconds() const
         *
         * @brief   Get elapsed time in milliseconds.
         *
         * @return  A double.
         */
        double ElapsedMilliseconds() const { return mTimer.time_m(); }

        /**
         * @fn  double Timer::ElapsedMicroseconds() const
         *
         * @brief   Get elapsed time in microseconds.
         *
         * @return  A double.
         */
        double ElapsedMicroseconds() const { return mTimer.time_u(); }

        /**
         * @fn  double Timer::ElapsedNanoseconds() const
         *
         * @brief   Get elapsed time in nanoseconds.
         *
         * @return  A double.
         */
        double ElapsedNanoseconds() const { return mTimer.time_n(); }

        /**
         * @fn  double Timer::GetSecondsPerCPUTick() const
         *
         * @brief   Get the number of seconds per CPU tick.
         *
         * @return  The seconds per CPU tick.
         */
        double GetSecondsPerCPUTick() const { return mTimer.getSecondsPerTick(); }

        /**
         * @fn  double Timer::GetSecondsPerTick() const
         *
         * @brief   Get the number of seconds per tick.
         *
         * @return  The seconds per tick.
         */
        double GetSecondsPerTick() const { return (double)(mNewTicks - mOldTicks)*GetSecondsPerCPUTick(); }

    private:
        osg::Timer mTimer;
        TimeTicks mOldTicks = 0;
        TimeTicks mNewTicks = 0;
        TimeTicks mCustomTicks = 0;
    };
}