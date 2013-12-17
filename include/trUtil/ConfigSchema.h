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

#ifndef ConfigSchema_H
#define ConfigSchema_H 1

#include "export.h"

#include <string>

namespace trUtil
{
	// defines API used to model the XML schema for the config file.
	struct TR_UTIL_EXPORT ConfigSchema
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


#endif // ConfigSchema_H