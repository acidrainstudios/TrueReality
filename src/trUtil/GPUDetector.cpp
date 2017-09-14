/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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

#ifndef GPUDetector_CPP
#define GPUDetector_CPP 1

#include <trUtil\GPUDetector.h>

#include <sstream>

#include <osgViewer/CompositeViewer>

//#include <dtUtil/log.h>

namespace trUtil
{
	//GPUDetector::GPUDetector(void)
	//{
	//	DetectGPUMonitorConfig();
	//}

	//void GPUDetector::DetectGPUMonitorConfig(void)
	//{
	//	//Create a temp Context
	//	osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(new osg::GraphicsContext::Traits);

	//	//Get number of screens
	//	mNumberOfScr = gc->getWindowingSystemInterface()->getNumScreens();

	//	//Make room for the detected screens
	//	mScrGPUConfig.reserve(mNumberOfScr);

	//#ifdef _WIN32
	//	DetectGPUMonitorConfigWin32();
	//#else
	//	DetectGPUMonitorConfigX11();
	//#endif

	//#ifdef _DEBUG
	//	//Debug Screen Info Printout
	//	std::stringstream LogPrintout;

	//	LogPrintout << "\nNumber of screens: ";
	//	LogPrintout << mNumberOfScr << std::endl;
	//	LogPrintout << "******************" << std::endl;

	//	for(unsigned int i=0; i<mScrGPUConfig.size(); i++)
	//	{
	//		LogPrintout << "WinNum: " << mScrGPUConfig[i].ScrNum << " GPU Num: " << mScrGPUConfig[i].GPUNum << " GCard ID: " << mScrGPUConfig[i].GCardID << std::endl;
	//	}
	//	LogPrintout << std::endl;
	//	LOG_INFO(LogPrintout.str());
	//#endif
	//}
}

#endif // GPUDetector_CPP



