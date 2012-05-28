#ifndef vrsGPUDetector_CPP
#define vrsGPUDetector_CPP 1

#include "..\\Include\vrsGPUDetector.h"

#include <sstream>

#include <osgViewer/CompositeViewer>

#include <dtUtil/log.h>

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
	#else
		DetectGPUMonitorConfigX11();
	#endif

	#ifdef _DEBUG
		//Debug Screen Info Printout
		std::stringstream LogPrintout;

		LogPrintout << "\nNumber of screens: ";
		LogPrintout << mNumberOfScr << std::endl;
		LogPrintout << "******************" << std::endl;

		for(unsigned int i=0; i<mScrGPUConfig.size(); i++)
		{
			LogPrintout << "WinNum: " << mScrGPUConfig[i].ScrNum << " GPU Num: " << mScrGPUConfig[i].GPUNum << " GCard ID: " << mScrGPUConfig[i].GCardID << std::endl;
		}
		LogPrintout << std::endl;
		LOG_INFO(LogPrintout.str());
	#endif
	}
}

#endif // vrsGPUDetector_CPP



