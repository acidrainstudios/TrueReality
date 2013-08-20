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

#ifndef vrsGPUDetector_H
#define vrsGPUDetector_H 1

#include "export.h"

#include <dtCore/Base.h>

namespace vrsUtil
{
	/**
    * Detects which Monitor is connected to whihc GPU
    */
	class VRS_UTIL_EXPORT vrsGPUDetector: public dtCore::Base
	{
	public:
		
		/**
		* Holds the Configuration of Win and GPUs
		*/
		struct ScrGPUCfg {
		int ScrNum;
		int GPUNum;
		std::string GCardID;
		};

		/**
		* Constructor
		*/
		vrsGPUDetector(void);

		/**
		* Destructor
		*/
		~vrsGPUDetector(void){};

		/**
		* Returns the Number of Screens Attached to the computer
		*/
		int GetNumOfScreens(void){return mNumberOfScr;}

		/**
		* Returns the GPU Number that should be used for the given screen
		*/
		int GetGPUOfScrNum(int ScreenNum){return mScrGPUConfig[ScreenNum].GPUNum;}

	private:

		/**
		* Detects the GPU configuration (General)
		*/
		void DetectGPUMonitorConfig(void);

		#ifdef _WIN32
		/**
		* Detects the GPU configuration (Winows Specific)
		*/
		void DetectGPUMonitorConfigWin32(void);
		#endif

		#ifndef _WIN32
		/**
		* Needs to be coded
		* Detects the GPU configuration (Linux Specific)
		*/
		void DetectGPUMonitorConfigX11(void);
		#endif

		//Number of screens attached to the computer
		unsigned int mNumberOfScr;

		//Holds the GPU - Window information
		std::vector<ScrGPUCfg> mScrGPUConfig;	
	};


}

	

#endif // vrsGPUDetector_H