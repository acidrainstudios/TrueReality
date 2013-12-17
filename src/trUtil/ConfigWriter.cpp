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

#ifndef ConfigWriter_CPP
#define ConfigWriter_CPP 1

#include <trUtil\ConfigWriter.h>
#include <xercesc/util/XMLString.hpp>

using namespace XERCES_CPP_NAMESPACE;

namespace trUtil
{
	void ConfigWriter::WriteCfg(const std::string &filename)
	{

	}

	ConfigWriter::SchemaModel::SchemaModel()
	{
		//WINDOW = XMLString::transcode( ApplicationConfigSchema::WINDOW.c_str() );
		
	}

	ConfigWriter::SchemaModel::~SchemaModel()
	{
		XMLString::release( &SCREEN_CFG);

		XMLString::release( &NUM_OF_SCR_CFGS);

		XMLString::release( &SCR_CFG_NAME);
		XMLString::release( &NUM_OF_SCREENS);
		XMLString::release( &WINDOW);
		XMLString::release( &WIN_CAPTION);
		XMLString::release( &SCR_NUMBER);
		XMLString::release( &WINDOW_X);
		XMLString::release( &WINDOW_Y);
		XMLString::release( &WINDOW_WIDTH);
		XMLString::release( &WINDOW_HEIGHT);
		XMLString::release( &H_FOV);
		XMLString::release( &V_FOV);
		XMLString::release( &CAMERA_POS);
			
		XMLString::release( &SHARE_CONTEXT);
		XMLString::release( &FULL_SCREEN);
		XMLString::release( &PIXEL_DEPTH);
		XMLString::release( &CHANGE_DISPLAY_RESOLUTION);
		XMLString::release( &VSYNC);
		XMLString::release( &MULTI_SAMPLE);

		XMLString::release( &STEREO_TYPE);
		XMLString::release( &STEREO_ENABLED);
		
		XMLString::release( &APP_CFG);

		XMLString::release( &LOG_LEVEL);
		
	}
	
}


#endif // ConfigWriter_CPP