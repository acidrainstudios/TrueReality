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

#ifndef vrsConfigSchema_CPP
#define vrsConfigSchema_CPP 1

#include <vrsUtil\vrsConfigSchema.h>


namespace vrsUtil
{
	// --- config schema model implementation --- //
	const std::string vrsConfigSchema::SCREEN_CFG = "SCREEN_CFG";

	const std::string vrsConfigSchema::NUM_OF_SCR_CFGS = "NUM_OF_SCR_CFGS";

	const std::string vrsConfigSchema::SCR_CFG_NAME = "SCR_CFG_NAME";
	const std::string vrsConfigSchema::NUM_OF_SCREENS = "NUM_OF_SCREENS";
	const std::string vrsConfigSchema::WINDOW = "WINDOW";
	const std::string vrsConfigSchema::WIN_CAPTION = "WIN_CAPTION";
	const std::string vrsConfigSchema::SCR_NUMBER = "SCR_NUMBER";
	const std::string vrsConfigSchema::WINDOW_X = "WINDOW_X";
	const std::string vrsConfigSchema::WINDOW_Y = "WINDOW_Y";
	const std::string vrsConfigSchema::WINDOW_WIDTH = "WINDOW_WIDTH";
	const std::string vrsConfigSchema::WINDOW_HEIGHT = "WINDOW_HEIGHT";
	const std::string vrsConfigSchema::H_FOV = "H_FOV";
	const std::string vrsConfigSchema::V_FOV = "V_FOV";
	const std::string vrsConfigSchema::CAMERA_POS = "CAMERA_POS";

	const std::string vrsConfigSchema::SHARE_CONTEXT = "SHARE_CONTEXT";
	const std::string vrsConfigSchema::FULL_SCREEN = "FULL_SCREEN";
	const std::string vrsConfigSchema::PIXEL_DEPTH = "PIXEL_DEPTH";
	const std::string vrsConfigSchema::CHANGE_DISPLAY_RESOLUTION = "CHANGE_DISPLAY_RESOLUTION";
	const std::string vrsConfigSchema::VSYNC = "VSYNC";
	const std::string vrsConfigSchema::MULTI_SAMPLE = "MULTI_SAMPLE";

	const std::string vrsConfigSchema::STEREO_TYPE = "STEREO_TYPE";
	const std::string vrsConfigSchema::STEREO_ENABLED = "STEREO_ENABLED";

	const std::string vrsConfigSchema::APP_CFG = "APP_CFG";

	const std::string vrsConfigSchema::LOG_LEVEL = "LOG_LEVEL";

}

#endif // vrsConfigSchema_CPP