/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////
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

	}
	
}
#endif

#endif // vrsGPUDetectorX11_CPP