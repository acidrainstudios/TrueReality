/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2013
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
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
* Author: Maxim Serebrennik
*/
#ifndef vrsGPUDetectorWin32_CPP
#define vrsGPUDetectorWin32_CPP 1

#ifdef _WIN32
#include <trUtil\vrsGPUDetector.h>

#include <windows.h>
#include <iostream>

#include <osgViewer/CompositeViewer>

namespace trUtil
{
	void vrsGPUDetector::DetectGPUMonitorConfigWin32(void)
	{
		DISPLAY_DEVICE GCardDevice;
		GCardDevice.cb = sizeof(DISPLAY_DEVICE);
		
		//Check all the devices with attached monitors. 
		DWORD deviceNum = 0;
		int KeyStart = 0;
		int KeyEnd = 0;
		while( EnumDisplayDevices(NULL, deviceNum, &GCardDevice, 0))
		{	

			//Isolate the Graphics Card Device Key
			std::string CardDeviceKey(GCardDevice.DeviceKey);
			KeyStart = CardDeviceKey.find("{");
			KeyEnd = CardDeviceKey.find("}") - KeyStart + 1;
			
			DISPLAY_DEVICE MonitorDevice = {0};
			MonitorDevice.cb = sizeof(DISPLAY_DEVICE);
			DWORD monitorNum = 0;
			while ( EnumDisplayDevices(GCardDevice.DeviceName, monitorNum, &MonitorDevice, 0))
			{
				//Fill out Screen Data (Set all GPU IDs to 0)				
				ScrGPUCfg ScrCfg;
				ScrCfg.GPUNum = 0;
				ScrCfg.ScrNum = mScrGPUConfig.size();
				ScrCfg.GCardID = CardDeviceKey.substr(KeyStart, KeyEnd);
				mScrGPUConfig.push_back(ScrCfg);

				monitorNum++;
			}
			deviceNum++;
		}

		//Compare the GCard IDs, and label the corect GPU IDs
		for (unsigned int i=0; i<mScrGPUConfig.size(); i++)
		{
			for (unsigned int j=i+1; j<mScrGPUConfig.size(); j++)
			{
				if (mScrGPUConfig[j].GCardID == mScrGPUConfig[i].GCardID)
				{
					mScrGPUConfig[j].GPUNum = mScrGPUConfig[i].GPUNum;
				}	
				else
				{
					mScrGPUConfig[j].GPUNum = (mScrGPUConfig[i].GPUNum + 1);
				}
			}
		}
	}
	#endif
}

#endif // vrsGPUDetectorWin32_CPP