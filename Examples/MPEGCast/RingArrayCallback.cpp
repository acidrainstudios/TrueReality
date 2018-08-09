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

#include "RingArray.h"
#include "RingArrayCallback.h"

#include <trBase/SmrtPtr.h>
#include <trUtil/Logging/Log.h>

//////////////////////////////////////////////////////////////////////////
RingArrayCallback::RingArrayCallback()
{
}

//////////////////////////////////////////////////////////////////////////
RingArrayCallback::~RingArrayCallback()
{
}

//////////////////////////////////////////////////////////////////////////
void RingArrayCallback::operator()(osg::Node* nodePtr, osg::NodeVisitor* nvPtr)
{
    //Set the timer at 0 on the first run. 
    if (mFirstFrame)
    {
        mTimer.SetStartTick(0);
        mNewTicks = mTimer.Tick();
        mFirstFrame = false;
    }

    trBase::SmrtPtr<RingArray> ring = static_cast<RingArray*>(nodePtr);

    if (ring.Valid())
    {
        mOldTicks = mNewTicks;
        mNewTicks = mTimer.Tick();

        ring->Update(nodePtr, nvPtr, (double)(mNewTicks - mOldTicks)*mTimer.GetSecondsPerTick());
    }
    else
    {
        LOG_E ("Callback not connected to a RingArray")
    }
}