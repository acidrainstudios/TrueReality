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
#define vrsGPUDetector_H

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
		* Constructor
		*/
		vrsGPUDetector(void);

		/**
		* Destructor
		*/
		~vrsGPUDetector(void){};
		

	private:

		/**
		* Detects the GPU configuration
		*/
		void DetectGPUMonitorConfig(void);
	};


}

	

#endif // vrsGPUDetector_H