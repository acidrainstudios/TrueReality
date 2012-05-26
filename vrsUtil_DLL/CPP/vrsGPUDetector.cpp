#ifndef vrsGPUDetector_CPP
#define vrsGPUDetector_CPP 1

#include "..\\Include\vrsGPUDetector.h"

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
		//Create a temp Context
		osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(new osg::GraphicsContext::Traits);

		//Get number of screens
		mNumberOfScr = gc->getWindowingSystemInterface()->getNumScreens();

		//Make room for the detected screens
		mScrGPUConfig.reserve(mNumberOfScr);

	#ifdef _WIN32
		DetectGPUMonitorConfigWin32();
	#endif
		
	#ifndef _WIN32
		DetectGPUMonitorConfigX11();
	#endif
	}
}

#endif // vrsGPUDetector_CPP



