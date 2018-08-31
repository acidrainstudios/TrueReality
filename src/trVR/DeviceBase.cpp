/*
 * True Reality Open Source Game and Simulation Engine
 * Copyright � 2018 Acid Rain Studios LLC
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
 * @author Alexander Koufos <alexander.p.koufos@leidos.com>
 *
 * Created on August 28, 2018, 6:30 PM
 */
#include <trVR/DeviceBase.h>

namespace trVR
{
    const trUtil::RefStr DeviceBase::CLASS_TYPE = trUtil::RefStr("trVR::DeviceBase");
    
    //////////////////////////////////////////////////////////////////////////
    DeviceBase::DeviceBase(const trUtil::RefStr& name) : BaseClass(name)
    {
    }
    
    //////////////////////////////////////////////////////////////////////////
    const std::string& DeviceBase::GetType() const
    {
        return CLASS_TYPE;
    }
    
    //////////////////////////////////////////////////////////////////////////
    std::string DeviceBase::GetDeviceProperty(vr::TrackedDeviceIndex_t deviceIndex, vr::TrackedDeviceProperty property)
    {
        uint32_t bufferLen = mVrSystem.lock()->GetStringTrackedDeviceProperty(deviceIndex, property, nullptr, 0);
        
        if (bufferLen == 0)
        {
            return "EMPTY";
        }
        
        char* buffer = new char[bufferLen];
        bufferLen = mVrSystem.lock()->GetStringTrackedDeviceProperty(deviceIndex, property, buffer, bufferLen);
        std::string result = buffer;
        delete []buffer;
        return result;
    }
}