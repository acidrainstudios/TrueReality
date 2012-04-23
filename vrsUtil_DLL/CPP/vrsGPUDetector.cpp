#ifndef vrsGPUDetector_CPP
#define vrsGPUDetector_CPP

#include "..\\Include\vrsGPUDetector.h"

#include <windows.h>

#include <iostream>

#include <osgViewer/CompositeViewer>

namespace vrsUtil
{
	vrsGPUDetector::vrsGPUDetector(void)
	{
		DetectGPUMonitorConfig();
	}

	void vrsGPUDetector::DetectGPUMonitorConfig(void)
	{
		#ifdef _DEBUG
		osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(new osg::GraphicsContext::Traits);

		std::cerr << "Number of screens:" << std::endl;
		std::cerr << gc->getWindowingSystemInterface()->getNumScreens() << std::endl;
		std::cerr << "******************" << std::endl;


		DISPLAY_DEVICE GCardDevice;
		GCardDevice.cb = sizeof(DISPLAY_DEVICE);

		DWORD deviceNum = 0;
		//Check all the devices with attached monitors. 
		//Attached monitors should be first in the list, so dont
		//check more devices then there are monitors
		while( EnumDisplayDevices(NULL, deviceNum, &GCardDevice, 0) && 
			(deviceNum < gc->getWindowingSystemInterface()->getNumScreens()) )
		{
			
			/*std::cout << "Device Name: " << GCardDevice.DeviceName << std::endl;
			std::cout << "Device String: " << GCardDevice.DeviceString << std::endl;
			std::cout << "State Flags: " << GCardDevice.StateFlags << std::endl;
			std::cout << "DeviceID: " << GCardDevice.DeviceID << std::endl;
			std::cout << "DeviceKey: " << GCardDevice.DeviceKey << std::endl;*/

			//Isolate the Graphics Card Device Key
			std::string CardDeviceKey(GCardDevice.DeviceKey);
			int KeyStart = CardDeviceKey.find("{");
			int KeyEnd = CardDeviceKey.find("}") - KeyStart + 1;
			std::cout << "DeviceKey: " << CardDeviceKey.substr(KeyStart, KeyEnd) << std::endl;

			DISPLAY_DEVICE MonitorDevice = {0};
			MonitorDevice.cb = sizeof(DISPLAY_DEVICE);
			DWORD monitorNum = 0;
			while ( EnumDisplayDevices(GCardDevice.DeviceName, monitorNum, &MonitorDevice, 0))
			{
				/*std::cout << "	Device Name: " << MonitorDevice.DeviceName << std::endl;
				std::cout << "	Device String: " << MonitorDevice.DeviceString << std::endl;
				std::cout << "	State Flags: " << MonitorDevice.StateFlags << std::endl;*/
				std::cout << "	DeviceID: " << MonitorDevice.DeviceID << std::endl;
				//std::cout << "	DeviceKey: " << MonitorDevice.DeviceKey << std::endl;
				monitorNum++;
			}
			puts("");
			deviceNum++;
		}

		#endif
	}
}

#endif // vrsGPUDetector_CPP