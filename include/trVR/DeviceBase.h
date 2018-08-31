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
#pragma once

#include <trVR/Export.h>

#include <trBase/Base.h>
#include <trUtil/RefStr.h>

#include <openvr/openvr.h>

#include <iostream>
#include <memory>

namespace trVR
{
    class DeviceBase : public trBase::Base
    {
    public:
        using BaseClass = trBase::Base; /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE; /// Holds the class type name for efficient comparisons

        DeviceBase(const trUtil::RefStr& name = CLASS_TYPE);

        DeviceBase(const DeviceBase& orig) = delete;

        DeviceBase& operator=(const DeviceBase& orig) = delete;

        virtual const std::string& GetType() const override;
        
        std::string GetDeviceProperty(vr::TrackedDeviceIndex_t deviceIndex, vr::TrackedDeviceProperty property);

    protected:
        virtual ~DeviceBase() = default;

    private:
        std::weak_ptr<vr::IVRSystem> mVrSystem;
    };
}