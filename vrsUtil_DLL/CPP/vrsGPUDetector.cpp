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

		DISPLAY_DEVICE dd;

		dd.cb = sizeof(DISPLAY_DEVICE);

		DWORD deviceNum = 0;
		while( EnumDisplayDevices(NULL, deviceNum, &dd, 0) ){
			
			std::cout << "Device Name: " << dd.DeviceName << std::endl;
			std::cout << "Device String: " << dd.DeviceString << std::endl;
			std::cout << "State Flags: " << dd.StateFlags << std::endl;
			std::cout << "DeviceID: " << dd.DeviceID << std::endl;
			std::cout << "DeviceKey: " << dd.DeviceKey+42 << std::endl;

			DISPLAY_DEVICE newdd = {0};
			newdd.cb = sizeof(DISPLAY_DEVICE);
			DWORD monitorNum = 0;
			while ( EnumDisplayDevices(dd.DeviceName, monitorNum, &newdd, 0))
			{
				std::cout << "	Device Name: " << newdd.DeviceName << std::endl;
				std::cout << "	Device String: " << newdd.DeviceString << std::endl;
				std::cout << "	State Flags: " << newdd.StateFlags << std::endl;
				std::cout << "	DeviceID: " << newdd.DeviceID << std::endl;
				std::cout << "	DeviceKey: " << newdd.DeviceKey+42 << std::endl;
				monitorNum++;
			}
			puts("");
			deviceNum++;
		}
		#endif
	}
}

#endif // vrsGPUDetector_CPP