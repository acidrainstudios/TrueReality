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

#include <trCore/Nodes/FrameStamp.h>

#include <trBase/Base.h>

#include <osg/FrameStamp>

namespace trCore::Nodes
{
    const trUtil::RefStr FrameStamp::CLASS_TYPE = trUtil::RefStr("trCore::Nodes::FrameStamp");

    //////////////////////////////////////////////////////////////////////////
    FrameStamp::FrameStamp(const std::string name)
    {
        mFrameStamp = new osg::FrameStamp();
    }

    //////////////////////////////////////////////////////////////////////////
    FrameStamp::FrameStamp(const osg::FrameStamp fs, const std::string name)
    {
        mFrameStamp = new osg::FrameStamp(fs);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& FrameStamp::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    void FrameStamp::SetName(const std::string& name)
    {
        BaseClass::SetName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    osg::FrameStamp* FrameStamp::AsOSGClass()
    {
        return mFrameStamp.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::FrameStamp* FrameStamp::AsOSGClass() const
    {
        return mFrameStamp.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    void FrameStamp::SetFrameNumber(unsigned int fnum)
    {
        mFrameStamp->setFrameNumber(fnum);
    }

    //////////////////////////////////////////////////////////////////////////
    unsigned int FrameStamp::GetFrameNumber() const
    {
        return mFrameStamp->getFrameNumber();
    }

    //////////////////////////////////////////////////////////////////////////
    void FrameStamp::SetReferenceTime(double refTime)
    {
        mFrameStamp->setReferenceTime(refTime);
    }

    //////////////////////////////////////////////////////////////////////////
    double FrameStamp::GetReferenceTime() const
    {
        return mFrameStamp->getReferenceTime();
    }

    //////////////////////////////////////////////////////////////////////////
    void FrameStamp::SetSimulationTime(double refTime)
    {
        mFrameStamp->setSimulationTime(refTime);
    }

    //////////////////////////////////////////////////////////////////////////
    double FrameStamp::GetSimulationTime() const
    {
        return mFrameStamp->getSimulationTime();
    }

    //////////////////////////////////////////////////////////////////////////
    void FrameStamp::SetCalendarTime(const tm & calendarTime)
    {
        mFrameStamp->setCalendarTime(calendarTime);
    }

    //////////////////////////////////////////////////////////////////////////
    void FrameStamp::GetCalendarTime(tm & calendarTime) const
    {
        mFrameStamp->getCalendarTime(calendarTime);
    }

    //////////////////////////////////////////////////////////////////////////
    FrameStamp& FrameStamp::operator=(const FrameStamp & fs)
    {
        mFrameStamp = fs.mFrameStamp;
        SetName(fs.GetName());
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    FrameStamp::~FrameStamp()
    {
    }
}

