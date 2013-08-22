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

#ifndef trConfigSchema_CPP
#define trConfigSchema_CPP 1

#include <trUtil\trConfigSchema.h>


namespace trUtil
{
	// --- config schema model implementation --- //
	const std::string trConfigSchema::SCREEN_CFG = "SCREEN_CFG";

	const std::string trConfigSchema::NUM_OF_SCR_CFGS = "NUM_OF_SCR_CFGS";

	const std::string trConfigSchema::SCR_CFG_NAME = "SCR_CFG_NAME";
	const std::string trConfigSchema::NUM_OF_SCREENS = "NUM_OF_SCREENS";
	const std::string trConfigSchema::WINDOW = "WINDOW";
	const std::string trConfigSchema::WIN_CAPTION = "WIN_CAPTION";
	const std::string trConfigSchema::SCR_NUMBER = "SCR_NUMBER";
	const std::string trConfigSchema::WINDOW_X = "WINDOW_X";
	const std::string trConfigSchema::WINDOW_Y = "WINDOW_Y";
	const std::string trConfigSchema::WINDOW_WIDTH = "WINDOW_WIDTH";
	const std::string trConfigSchema::WINDOW_HEIGHT = "WINDOW_HEIGHT";
	const std::string trConfigSchema::H_FOV = "H_FOV";
	const std::string trConfigSchema::V_FOV = "V_FOV";
	const std::string trConfigSchema::CAMERA_POS = "CAMERA_POS";

	const std::string trConfigSchema::SHARE_CONTEXT = "SHARE_CONTEXT";
	const std::string trConfigSchema::FULL_SCREEN = "FULL_SCREEN";
	const std::string trConfigSchema::PIXEL_DEPTH = "PIXEL_DEPTH";
	const std::string trConfigSchema::CHANGE_DISPLAY_RESOLUTION = "CHANGE_DISPLAY_RESOLUTION";
	const std::string trConfigSchema::VSYNC = "VSYNC";
	const std::string trConfigSchema::MULTI_SAMPLE = "MULTI_SAMPLE";

	const std::string trConfigSchema::STEREO_TYPE = "STEREO_TYPE";
	const std::string trConfigSchema::STEREO_ENABLED = "STEREO_ENABLED";

	const std::string trConfigSchema::APP_CFG = "APP_CFG";

	const std::string trConfigSchema::LOG_LEVEL = "LOG_LEVEL";

}

#endif // trConfigSchema_CPP