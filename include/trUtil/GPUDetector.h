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

#ifndef GPUDetector_H
#define GPUDetector_H 1

#include "export.h"

#include <dtCore/Base.h>

namespace trUtil
{
	/**
    * Detects which Monitor is connected to whihc GPU
    */
	class TR_UTIL_EXPORT GPUDetector: public dtCore::Base
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
		GPUDetector(void);

		/**
		* Destructor
		*/
		~GPUDetector(void){};

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

	

#endif // GPUDetector_H