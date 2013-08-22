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

#ifndef vrsGPUDetectorX11_CPP
#define vrsGPUDetectorX11_CPP 1

#ifndef _WIN32
#include "..\\Include\vrsGPUDetector.h"

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

namespace vrsUtil
{
	void vrsGPUDetector::DetectGPUMonitorConfigX11(void)
	{

		//For X11 this might be a way to do the same:

		/* screenno - returns the number of screens connected to the current display
		 */
		
		//
		//int main(int argc, char *argv[]) 
		//{
		//        Display * display;
		//        char * displayName;
		//        int screenNo = 0;
		//
		//        displayName = getenv("DISPLAY");
		//        display = XOpenDisplay(displayName);
		//        
		//		screenNo = ScreenCount(display);
		//        
		//		printf("%d", screenNo);
		//        
		//		XCloseDisplay(display);
		//        return 0;
		//}

		//Temp result until a true x11 GPU detector is made
		for(unsigned int i = 0; i < mNumberOfScr; i++)
		{
			//Fill out Screen Data Set each screen to a different GPU
			//This will force each window create its own context (Not the best case)
			ScrGPUCfg ScrCfg;
			ScrCfg.GPUNum = i;
			ScrCfg.ScrNum = i;
			ScrCfg.GCardID = i;
			mScrGPUConfig.push_back(ScrCfg);
		}

	}
	
}
#endif

#endif // vrsGPUDetectorX11_CPP