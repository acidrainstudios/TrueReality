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

#include <trCore/Export.h>

#include <trBase/Base.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/RefStr.h>

#if defined(__sgi) || (defined(WIN32) && !defined(__MWERKS__))
#include <time.h>
#else
#include <ctime>
using std::tm;
#endif

namespace osg
{
    class FrameStamp;
}

namespace trCore::Nodes
{
    /**
     * @class   FrameStamp
     *
     * @brief   Class which encapsulates the frame number, reference time and calendar time of
     *          specific frame, used to synchronize operations on the scene graph and other machines
     *          when using a graphics cluster.  Note the calendar time can be an artificial
     *          simulation time or capture the real time of day etc.
     *
     * @author  Maxim Serebrennik
     */
    class TR_CORE_EXPORT FrameStamp : public trBase::Base
    {
    public:

        using BaseClass = trBase::Base;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
         * @fn  FrameStamp::FrameStamp(const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   name    (Optional) The name.
         */
        FrameStamp(const std::string name = CLASS_TYPE);

        /**
         * @fn  FrameStamp::FrameStamp(const osg::FrameStamp fs, const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   fs      The file system.
         * @param   name    (Optional) The name.
         */
        FrameStamp(const osg::FrameStamp fs, const std::string name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& FrameStamp::GetType() const override;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

        /**
         * @fn  virtual void FrameStamp::SetName(const std::string& name);
         *
         * @brief   Sets this instances name.
         *
         * @param   name    The name.
         */
        virtual void SetName(const std::string& name);

        /**
         * @fn  virtual osg::FrameStamp* FrameStamp::AsOSGClass();
         *
         * @brief   Returns a pointer to the internal OSG FrameStamp.
         *
         * @return  Null if it fails, else a pointer to an osg::FrameStamp.
         */
        virtual osg::FrameStamp* AsOSGClass();

        /**
         * @fn  virtual const osg::FrameStamp* FrameStamp::AsOSGClass() const;
         *
         * @brief   Returns a constant pointer to the internal OSG FrameStamp.
         *
         * @return  Null if it fails, else a pointer to a const osg::FrameStamp.
         */
        virtual const osg::FrameStamp* AsOSGClass() const;

        /**
         * @fn  void FrameStamp::SetFrameNumber(unsigned int fnum);
         *
         * @brief   Sets frame number.
         *
         * @param   fnum    The fnum.
         */
        void SetFrameNumber(unsigned int fnum);

        /**
         * @fn  unsigned int FrameStamp::GetFrameNumber() const;
         *
         * @brief   Gets frame number.
         *
         * @return  The frame number.
         */
        unsigned int GetFrameNumber() const;

        /**
         * @fn  void FrameStamp::SetReferenceTime(double refTime);
         *
         * @brief   Sets reference time.
         *
         * @param   refTime The reference time.
         */
        void SetReferenceTime(double refTime);

        /**
         * @fn  double FrameStamp::GetReferenceTime() const;
         *
         * @brief   Gets reference time.
         *
         * @return  The reference time.
         */
        double GetReferenceTime() const;

        /**
         * @fn  void FrameStamp::SetSimulationTime(double refTime);
         *
         * @brief   Sets simulation time.
         *
         * @param   refTime The reference time.
         */
        void SetSimulationTime(double refTime);

        /**
         * @fn  double FrameStamp::GetSimulationTime() const;
         *
         * @brief   Gets simulation time.
         *
         * @return  The simulation time.
         */
        double GetSimulationTime() const;

        /**
         * @fn  void FrameStamp::SetCalendarTime(const tm& calendarTime);
         *
         * @brief   Sets calendar time.
         *
         * @param   calendarTime    The calendar time.
         */
        void SetCalendarTime(const tm& calendarTime);

        /**
         * @fn  void FrameStamp::GetCalendarTime(tm& calendarTime) const;
         *
         * @brief   Gets calendar time.
         *
         * @param [in,out]  calendarTime    The calendar time.
         */
        void GetCalendarTime(tm& calendarTime) const;

        /**
         * @fn  FrameStamp& FrameStamp::operator= (const FrameStamp& fs);
         *
         * @brief   Assignment operator.
         *
         * @param   fs  The file system.
         *
         * @return  A shallow copy of this object.
         */
        FrameStamp& operator = (const FrameStamp& fs);

    protected:

        /** @brief   The frame stamp. */
        trBase::SmrtPtr<osg::FrameStamp> mFrameStamp;

        /**
         * @fn  FrameStamp::~FrameStamp();
         *
         * @brief   dtor.
         */
        ~FrameStamp();
    };
}