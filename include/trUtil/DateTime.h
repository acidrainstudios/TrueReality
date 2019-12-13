/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
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
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* @author Bradley Anderegg
*/
#pragma once

#include "Export.h"

#include <trUtil/EnumerationString.h>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @class   TR_UTIL_EXPORT
     *
     * @brief   A class that represents date time utility.
     */
    class TR_UTIL_EXPORT DateTime
    {
    public:

        /**
         * @class   TR_UTIL_EXPORT
         *
         * @brief   The TimeOrigin enumeration determines how the instance of DateTime should be
         *          interpreted. When passing a TimeOrigin into the constructor of DateTime it will
         *          automatically set the clock to that specific time.
         */
        class TR_UTIL_EXPORT TimeOrigin : public trUtil::EnumerationString
        {
            DECLARE_ENUM(TimeOrigin)

        public:
            /** @brief   The local time. */
            static const TimeOrigin LOCAL_TIME;
            /** @brief   The GMT time. */
            static const TimeOrigin GMT_TIME;

        protected:

            /**
             * @fn  TimeOrigin::~TimeOrigin()
             *
             * @brief   Destructor.
             */
            /*virtual*/ ~TimeOrigin(){}

        private:

            /**
             * @fn  TimeOrigin::TimeOrigin(const std::string& name) : trUtil::EnumerationString(name)
             *
             * @brief   Constructor.
             *
             * @param   name    The name.
             */
            TimeOrigin(const std::string& name) : trUtil::EnumerationString(name)
            {
                AddInstance(this);
            }
        };

        /**
         * @class   TR_UTIL_EXPORT
         *
         * @brief   The TimeType enumeration is used to identify the purpose of a DateTime instance.
         */
        class TR_UTIL_EXPORT TimeType : public trUtil::EnumerationString
        {
            DECLARE_ENUM(TimeType)

        public:
            /** @brief   The clock time. */
            static const TimeType CLOCK_TIME;
            /** @brief   The simulation time. */
            static const TimeType SIMULATION_TIME;
            /** @brief   The scenario time. */
            static const TimeType SCENARIO_TIME;
            /** @brief   The trip time. */
            static const TimeType TRIP_TIME;
            /** @brief   The time stamp. */
            static const TimeType TIME_STAMP;
            /** @brief   The time type other. */
            static const TimeType TIME_TYPE_OTHER;

        protected:

            /**
             * @fn  TimeType::~TimeType()
             *
             * @brief   Destructor.
             */
            /*virtual*/ ~TimeType(){}

        private:

            /**
             * @fn  TimeType::TimeType(const std::string& name) : trUtil::EnumerationString(name)
             *
             * @brief   Constructor.
             *
             * @param   name    The name.
             */
            TimeType(const std::string& name) : trUtil::EnumerationString(name)
            {
                AddInstance(this);
            }
        };

        /**
         * @class   TR_UTIL_EXPORT
         *
         * @brief   The TimeFormat enumeration is used to specify how to map a DateTime object to a
         *          string.  This enumeration is used in conjunction with ToString().
         */
        class TR_UTIL_EXPORT TimeFormat : public trUtil::EnumerationString
        {
            DECLARE_ENUM(TimeFormat)

        public:

            /** @brief   LOCAL_DATE_AND_TIME_FORMAT: 04/18/08 13:22:50. */
            static const TimeFormat LOCAL_DATE_AND_TIME_FORMAT;

            /** @brief   LOCAL_DATE_FORMAT: 04/18/08. */
            static const TimeFormat LOCAL_DATE_FORMAT;

            /** @brief   CLOCK_TIME_12_HOUR_FORMAT: 01:22:50 PM. */
            static const TimeFormat CLOCK_TIME_12_HOUR_FORMAT;

            /** @brief   CLOCK_TIME_24_HOUR_FORMAT: 13:22:50. */
            static const TimeFormat CLOCK_TIME_24_HOUR_FORMAT;

            /** @brief   LEXICAL_DATE_FORMAT: April 18, 2008. */
            static const TimeFormat LEXICAL_DATE_FORMAT;

            /** @brief   CALENDAR_DATE_FORMAT: 2008-04-18. */
            static const TimeFormat CALENDAR_DATE_FORMAT;

            /** @brief   ORDINAL_DATE_FORMAT: 2008-109. */
            static const TimeFormat ORDINAL_DATE_FORMAT;

            /** @brief   WEEK_DATE_FORMAT: 2008-W15-5. */
            static const TimeFormat WEEK_DATE_FORMAT;

            /** @brief   CALENDAR_DATE_AND_TIME_FORMAT: 2008-04-18T13:22:50-05:00. */
            static const TimeFormat CALENDAR_DATE_AND_TIME_FORMAT;

        protected:

            /**
             * @fn  TimeFormat::~TimeFormat()
             *
             * @brief   Destructor.
             */
            /*virtual*/ ~TimeFormat(){}

        private:

            /**
             * @fn  TimeFormat::TimeFormat(const std::string& name) : trUtil::EnumerationString(name)
             *
             * @brief   Constructor.
             *
             * @param   name    The name.
             */
            TimeFormat(const std::string& name) : trUtil::EnumerationString(name)
            {
                AddInstance(this);
            }
        };

    public:

        /**
         * @fn  DateTime::DateTime();
         *
         * @brief   The default constructor just zeros.
         */
        DateTime();

        /**
         * @fn  DateTime::DateTime(const TimeOrigin& initAs);
         *
         * @brief   This constructor takes a TimeOrigin and sets the time accordingly.
         *
         * @param   initAs  The init as.
         */
        DateTime(const TimeOrigin& initAs);

        /**
         * @fn  DateTime::DateTime(time_t);
         *
         * @brief   Create a DateTime using the c standard time_t struct.
         *
         * @param   parameter1  The first parameter.
         */
        DateTime(time_t);

        /**
         * @fn  DateTime::DateTime(const struct tm&);
         *
         * @brief   Create a DateTime using the c standard struct tm.
         *
         * @param   parameter1  The first parameter.
         */
        DateTime(const struct tm&);

        /**
         * @fn  DateTime::DateTime(const DateTime&);
         *
         * @brief   Copy constructor.
         *
         * @param   parameter1  The first parameter.
         */
        DateTime(const DateTime&);

        /**
         * @fn  DateTime& DateTime::operator=(const DateTime&);
         *
         * @brief   Assignment operator.
         *
         * @param   parameter1  The first parameter.
         *
         * @return  A shallow copy of this object.
         */
        DateTime& operator=(const DateTime&);

        /**
         * @fn  virtual DateTime::~DateTime();
         *
         * @brief   Destructor.
         */
        virtual ~DateTime();

        /**
         * @fn  static float DateTime::GetLocalGMTOffset(bool accountForDST = false);
         *
         * @brief   Gets local GMT offset.
         *
         * @param   accountForDST   (Optional) True to account for destination.
         *
         * @return  The local GMT offset.
         */
        static float GetLocalGMTOffset(bool accountForDST = false);

        /**
         * @fn  void DateTime::SetToLocalTime();
         *
         * @brief   Changes time to be system local time.
         */
        void SetToLocalTime();

        /**
         * @fn  void DateTime::SetToGMTTime();
         *
         * @brief   Changes time to be GMT- or Greenwich Mean Time.
         */
        void SetToGMTTime();

        /**
         * @fn  void DateTime::IncrementClock(double seconds);
         *
         * @brief   Increments the clock time by the number of seconds specified.  The fractional part of
         *          the time is saved off and added in whole increments to support sub second times but
         *          getting time as a time_t or struct tm will not include fractional seconds.  To get
         *          the fractional seconds use GetTime with a float for seconds or GetSecond().
         *
         * @param   seconds number of seconds to increase the clock by.
         */
        void IncrementClock(double seconds);

        /**
         * @fn  void DateTime::AdjustTimeZone(float newGMTOffset);
         *
         * @brief   Every date time has a GMT offset.  This method allows one to set a new GMT offset,
         *          and then change the clock internally to match the newoffset.  For example if the
         *          clock is in 12:00 AM Eastern Time (-5) Jan 5, 2009, setting the offset to west coast
         *          time (-8) would make the date time be 9:00 PM, Jan 4, 2009.
         *
         * @param   newGMTOffset    the offset in hours from GMT to change this to.
         */
        void AdjustTimeZone(float newGMTOffset);

        /**
         * @fn  void DateTime::GetTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, float& sec) const;
         *
         * @brief   Gets the time internally stored using unsigned year, month, day, hour, minute, and
         *          seconds.  The float second version will include the sub second time if
         *          IncrementClock() or SetSecond() was not rounded off.  To get time modified by a
         *          GMTOffset use GetGMTTime().
         *
         * @param [in,out]  year    the full year, not just since 1900 epoch.
         * @param [in,out]  month   the month specified as 1-12.
         * @param [in,out]  day     the day specified as 1-31.
         * @param [in,out]  hour    hours since midnight 0-23.
         * @param [in,out]  min     minutes after the hour 0-60.
         * @param [in,out]  sec     seconds after the hour 0-61 (and extra second is added to support
         *                          leap seconds)
         */
        void GetTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, float& sec) const;

        /**
         * @fn  void DateTime::GetTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, unsigned& sec) const;
         *
         * @brief   Gets a time.
         *
         * @param [in,out]  year    The year.
         * @param [in,out]  month   The month.
         * @param [in,out]  day     The day.
         * @param [in,out]  hour    The hour.
         * @param [in,out]  min     The minimum.
         * @param [in,out]  sec     The security.
         */
        void GetTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, unsigned& sec) const;

        /**
         * @fn  void DateTime::GetGMTTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, float& sec) const;
         *
         * @brief   Gets the time internally stored using unsigned year, month, day, hour, minute, and
         *          seconds.  The float second version will include the sub second time if
         *          IncrementClock() or SetSecond() was not rounded off.  The GMTOffset will be added
         *          into the current time to obtain the GMT Time.
         *
         * @param [in,out]  year    the full year, not just since 1900 epoch.
         * @param [in,out]  month   the month specified as 1-12.
         * @param [in,out]  day     the day specified as 1-31.
         * @param [in,out]  hour    hours since midnight 0-23.
         * @param [in,out]  min     minutes after the hour 0-60.
         * @param [in,out]  sec     seconds after the hour 0-61 (and extra second is added to support
         *                          leap seconds)
         */
        void GetGMTTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, float& sec) const;

        /**
         * @fn  void DateTime::GetGMTTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, unsigned& sec) const;
         *
         * @brief   Gets GMT time.
         *
         * @param [in,out]  year    The year.
         * @param [in,out]  month   The month.
         * @param [in,out]  day     The day.
         * @param [in,out]  hour    The hour.
         * @param [in,out]  min     The minimum.
         * @param [in,out]  sec     The security.
         */
        void GetGMTTime(unsigned& year, unsigned& month, unsigned& day, unsigned& hour, unsigned& min, unsigned& sec) const;

        /**
         * @fn  void DateTime::SetTime(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned min, float sec);
         *
         * @brief   Sets the full time using year, month, day, hour, minute, and second.  A float version
         *          is provided to support sub second times.
         *
         * @param   year    the full year, not just since 1900 epoch.
         * @param   month   the month specified as 1-12.
         * @param   day     the day specified as 1-31.
         * @param   hour    hours since midnight 0-23.
         * @param   min     minutes after the hour 0-60.
         * @param   sec     seconds after the hour 0-61 (and extra second is added to support leap
         *                  seconds)
         */
        void SetTime(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned min, float sec);

        /**
         * @fn  void DateTime::SetTime(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned min, unsigned sec);
         *
         * @brief   Sets a time.
         *
         * @param   year    The year.
         * @param   month   The month.
         * @param   day     The day.
         * @param   hour    The hour.
         * @param   min     The minimum.
         * @param   sec     The security.
         */
        void SetTime(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned min, unsigned sec);

        /**
         * @fn  time_t DateTime::GetTime() const;
         *
         * @brief   Gets the time in the standard time_t format, specified as seconds elapsed since
         *          midnight, January 1, 1970
         *          @note this format only includes whole seconds.
         *
         * @return  The time.
         */
        time_t GetTime() const;

        /**
         * @fn  time_t DateTime::GetGMTTime() const;
         *
         * @brief   Gets the time in standard time_t format, the GMTOffset is added to the time before
         *          calculating time_t.
         *
         * @return  The GMT time.
         */
        time_t GetGMTTime() const;

        /**
         * @fn  void DateTime::SetTime(time_t);
         *
         * @brief   Sets time in standard time_t format, specified as seconds elapsed since midnight,
         *          January 1, 1970.
         *
         * @param   parameter1  The first parameter.
         */
        void SetTime(time_t);

        /**
         * @fn  double DateTime::GetTimeInSeconds() const;
         *
         * @brief   Returns the total clock time in seconds elapsed since midnight, January 1, 1970 This
         *          time includes fractional seconds.
         *
         * @return  The time in seconds.
         */
        double GetTimeInSeconds() const;

        /**
         * @fn  void DateTime::GetTime(tm&) const;
         *
         * @brief   Fills a standard c struct tm with the time.
         *
         * @param [in,out]  parameter1  The first parameter.
         */
        void GetTime(tm&) const;

        /**
         * @fn  void DateTime::GetGMTTime(tm&) const;
         *
         * @brief   Fills a standard c struct tm with the time but adds GMTOffset into time before struct
         *          tm is calculated.
         *
         * @param [in,out]  parameter1  The first parameter.
         */
        void GetGMTTime(tm&) const;

        /**
         * @fn  void DateTime::SetTime(const tm&);
         *
         * @brief   Sets the time using the standard c struct tm.
         *
         * @param   parameter1  The first parameter.
         */
        void SetTime(const tm&);

        /**
         * @fn  void DateTime::SetGMTOffset(float hourOffset, bool dayLightSavings);
         *
         * @brief   Sets the GMTOffset which is added to the time when getting GMT time,.
         *
         * @param   hourOffset      the number of hours to offset from GMT Time, the param is a float to
         *                          support half hour time zones.
         * @param   dayLightSavings this flag is used to specify whether or not daylight savings is in
         *                          effect setting this flag to true will add and extra hour to the
         *                          GMTOffset.
         */
        void SetGMTOffset(float hourOffset, bool dayLightSavings);

        /**
         * @fn  static float DateTime::CalcGMTOffset(tm& timeParts, bool factorLocalDayLightSavingsIntoGMTOffset);
         *
         * @brief   Sets the GMTOffset using the systems local time this offset is added to the time when
         *          getting GMT time,.
         *
         * @param [in,out]  timeParts                               the struct tm used to calculate the
         *                                                          local timezone.
         * @param           factorLocalDayLightSavingsIntoGMTOffset this flag is used to specify whether
         *                                                          or not daylight savings should be
         *                                                          obtained from the system clock,
         *                                                          setting true will increment the
         *                                                          GMTOffset by one hour if your system
         *                                                          is currently on daylight savings.
         *
         * @return  The calculated GMT offset.
         */
        static float CalcGMTOffset(tm& timeParts, bool factorLocalDayLightSavingsIntoGMTOffset);

        /**
         * @fn  void DateTime::SetGMTOffset(double lattitude, double longitude, bool dayLightSavings);
         *
         * @brief   Calculates the GMTOffset using a lattitude and longitude, not 100% correct due to
         *          regional time zone boundaries but it works ok as an approximation.
         *
         * @param   lattitude       the geographical lattitude of origin.
         * @param   longitude       the geographical longitude of origin.
         * @param   dayLightSavings this flag is used to specify whether or not daylight savings is in
         *                          effect setting this flag to true will add and extra hour to the
         *                          GMTOffset.
         */
        void SetGMTOffset(double lattitude, double longitude, bool dayLightSavings);

        /**
         * @fn  float DateTime::GetGMTOffset() const;
         *
         * @brief   Gets the GMTOffset, this will be 0 unless SetGMTOffset was called or SetToLocalTime()
         *          was called, or TimeOrigin::LOCAL_TIME was fed into the constructor.
         *
         * @return  the current offset from Greenwich mean time.
         */
        float GetGMTOffset() const;

        /**
         * @fn  float DateTime::GetTimeScale() const;
         *
         * @brief   The TimeScale can be used to scale the time when incrementing the clock. The default
         *          value for TimeScale is 1.0.
         *
         * @return  The time scale.
         */
        float GetTimeScale() const;

        /**
         * @fn  void DateTime::SetTimeScale(float percentScaleInSeconds);
         *
         * @brief   The TimeScale can be used to scale the time when incrementing the clock. The default
         *          value for TimeScale is 1.0.
         *
         * @param   percentScaleInSeconds   The percent scale in seconds.
         */
        void SetTimeScale(float percentScaleInSeconds);

        /**
         * @fn  const TimeType& DateTime::GetTimeType() const;
         *
         * @brief   The TimeType enumeration is used to identify the purpose of a DateTime instance.
         *
         * @return  The time type.
         */
        const TimeType& GetTimeType() const;

        /**
         * @fn  void DateTime::SetTimeType(const TimeType&);
         *
         * @brief   The TimeType enumeration is used to identify the purpose of a DateTime instance.
         *
         * @param   parameter1  The first parameter.
         */
        void SetTimeType(const TimeType&);

        /**
         * @fn  const TimeOrigin& DateTime::GetTimeOrigin() const;
         *
         * @brief   The TimeOrigin enumeration determines how the instance of DateTime should be
         *          interpreted.
         *
         * @return  The time origin.
         */
        const TimeOrigin& GetTimeOrigin() const;

        /**
         * @fn  void DateTime::SetTimeOrigin(const TimeOrigin&);
         *
         * @brief   The TimeOrigin enumeration determines how the instance of DateTime should be
         *          interpreted.
         *
         * @param   parameter1  The first parameter.
         */
        void SetTimeOrigin(const TimeOrigin&);

        /**
         * @fn  const TimeFormat& DateTime::GetTimeFormat() const;
         *
         * @brief   The TimeFormat enumeration is used to specify how to map a DateTime object to a
         *          string. Set the TimeFormat if you would like to use the ToString() without any
         *          arguments.
         *
         * @return  The time format.
         */
        const TimeFormat& GetTimeFormat() const;

        /**
         * @fn  void DateTime::SetTimeFormat(const TimeFormat&);
         *
         * @brief   The TimeFormat enumeration is used to specify how to map a DateTime object to a
         *          string. Set the TimeFormat if you would like to use the ToString() without any
         *          arguments.
         *
         * @param   parameter1  The first parameter.
         */
        void SetTimeFormat(const TimeFormat&);

        /**
         * @fn  float DateTime::GetSecond() const;
         *
         * @brief   Gets the second.
         *
         * @return  The second.
         */
        float GetSecond() const;

        /**
         * @fn  void DateTime::SetSecond(float sec);
         *
         * @brief   Sets a second.
         *
         * @param   sec The security.
         */
        void SetSecond(float sec);

        /**
         * @fn  unsigned DateTime::GetMinute() const;
         *
         * @brief   Gets the minute.
         *
         * @return  The minute.
         */
        unsigned GetMinute() const;

        /**
         * @fn  void DateTime::SetMinute(unsigned min);
         *
         * @brief   Sets a minute.
         *
         * @param   min The minimum.
         */
        void SetMinute(unsigned min);

        /**
         * @fn  unsigned DateTime::GetHour() const;
         *
         * @brief   Gets the hour.
         *
         * @return  The hour.
         */
        unsigned GetHour() const;

        /**
         * @fn  void DateTime::SetHour(unsigned hour);
         *
         * @brief   Sets a hour.
         *
         * @param   hour    The hour.
         */
        void SetHour(unsigned hour);

        /**
         * @fn  unsigned DateTime::GetDay() const;
         *
         * @brief   Gets the day.
         *
         * @return  The day.
         */
        unsigned GetDay() const;

        /**
         * @fn  void DateTime::SetDay(unsigned day);
         *
         * @brief   Sets a day.
         *
         * @param   day The day.
         */
        void SetDay(unsigned day);

        /**
         * @fn  unsigned DateTime::GetMonth() const;
         *
         * @brief   Gets the month.
         *
         * @return  The month.
         */
        unsigned GetMonth() const;

        /**
         * @fn  void DateTime::SetMonth(unsigned month);
         *
         * @brief   Sets a month.
         *
         * @param   month   The month.
         */
        void SetMonth(unsigned month);

        /**
         * @fn  unsigned DateTime::GetYear() const;
         *
         * @brief   Gets the year.
         *
         * @return  The year.
         */
        unsigned GetYear() const;

        /**
         * @fn  void DateTime::SetYear(unsigned year);
         *
         * @brief   Sets a year.
         *
         * @param   year    The year.
         */
        void SetYear(unsigned year);

        /**
         * @fn  std::string DateTime::ToString() const;
         *
         * @brief   The no parameter version of ToString uses the internal TimeFormat, see the TimeFormat
         *          enumeration above.
         *
         * @return  A std::string that represents this object.
         */
        std::string ToString() const;

        /**
         * @fn  std::string DateTime::ToString(const TimeFormat&) const;
         *
         * @brief   Converts the time to a string using a TimeFormat enumeration, see the TimeFormat
         *          enumeration above.
         *
         * @param   parameter1  The first parameter.
         *
         * @return  A std::string that represents this object.
         */
        std::string ToString(const TimeFormat&) const;

        /**
         * @fn  static std::string DateTime::ToString(const DateTime&, const TimeFormat&);
         *
         * @brief   A static version of ToString() for convenience, using the conversion operators a
         *          time_t or struct tm can be passed for the DateTime.
         *
         * @param   parameter1  The first parameter.
         * @param   parameter2  The second parameter.
         *
         * @return  A std::string that represents this object.
         */
        static std::string ToString(const DateTime&, const TimeFormat&);

        /**
         * @fn  operator DateTime::time_t() const;
         *
         * @brief   general purpose conversion operators.
         *
         * @return  The result of the operation.
         */
        operator time_t() const;

        /**
         * @fn  operator DateTime::tm() const;
         *
         * @brief   Cast that converts the given  to a tm.
         *
         * @return  The result of the operation.
         */
        operator tm() const;

        /**
         * @fn  operator std::string() const;
         *
         * @brief   Cast that converts the given  to a string.
         *
         * @return  The result of the operation.
         */
        operator std::string() const;

        //TODO- add operators
        //DateTime& operator +=(const DateTime&);
        //DateTime& operator -=(const DateTime&);

        //bool operator<(const DateTime&) const;
        //bool operator>(const DateTime&) const;

        //std::ostream& operator >>(std::ostream&);

    private:

        /**
         * @fn  void DateTime::ResetToDefaultValues();
         *
         * @brief   Resets to default values.
         */
        void ResetToDefaultValues();

        /**
         * @fn  static void DateTime::GetGMTTime(time_t* t, tm& timeParts);
         *
         * @brief   Gets GMT time.
         *
         * @param [in,out]  t           If non-null, the time_t to process.
         * @param [in,out]  timeParts   The time parts.
         */
        static void GetGMTTime(time_t* t, tm& timeParts);

        /**
         * @fn  static void DateTime::GetLocalTime(time_t* t, tm& timeParts);
         *
         * @brief   Gets local time.
         *
         * @param [in,out]  t           If non-null, the time_t to process.
         * @param [in,out]  timeParts   The time parts.
         */
        static void GetLocalTime(time_t* t, tm& timeParts);


        /** @brief   The GMT offset. */
        float mGMTOffset;
        /** @brief   The time scale. */
        float mTimeScale;
        /** @brief   The fractional in seconds. */
        double mFractionalSeconds;

        /**
         * @property    unsigned mSeconds, mMinutes, mHours, mDays, mMonths, mYears
         *
         * @brief   Store parts of time.
         *
         * @return  The m years.
         */
        unsigned mSeconds, mMinutes, mHours, mDays, mMonths, mYears;

        /** @brief   The time origin. */
        const TimeOrigin* mTimeOrigin;
        /** @brief   Type of the time. */
        const TimeType* mTimeType;
        /** @brief   The string format. */
        const TimeFormat* mStringFormat;
    };
}