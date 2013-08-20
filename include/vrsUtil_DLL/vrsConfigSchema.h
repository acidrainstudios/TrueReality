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

#ifndef vrsConfigSchema_H
#define vrsConfigSchema_H 1

#include "export.h"

#include <string>

namespace vrsUtil
{
	// defines API used to model the XML schema for the config file.
	struct VRS_UTIL_EXPORT vrsConfigSchema
	{
	public:
		static const std::string SCREEN_CFG;

		static const std::string NUM_OF_SCR_CFGS;

		static const std::string SCR_CFG_NAME;
		static const std::string NUM_OF_SCREENS;
		static const std::string WINDOW;
		static const std::string WIN_CAPTION;
		static const std::string SCR_NUMBER;
		static const std::string WINDOW_X;
		static const std::string WINDOW_Y;
		static const std::string WINDOW_WIDTH;
		static const std::string WINDOW_HEIGHT;
		static const std::string H_FOV;
		static const std::string V_FOV;
		static const std::string CAMERA_POS;
			
		static const std::string SHARE_CONTEXT;
		static const std::string FULL_SCREEN;
		static const std::string PIXEL_DEPTH;
		static const std::string CHANGE_DISPLAY_RESOLUTION;
		static const std::string VSYNC;
		static const std::string MULTI_SAMPLE;

		static const std::string STEREO_TYPE;
		static const std::string STEREO_ENABLED;
		
		static const std::string APP_CFG;

		static const std::string LOG_LEVEL;
	};
}


#endif // vrsConfigSchema_H