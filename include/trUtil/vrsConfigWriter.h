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

#ifndef vrsConfigWriter_H
#define vrsConfigWriter_H 1

#include "export.h"

#include <dtUtil/log.h>                     // to read the default log name.
#include <string>                           // for data members
#include <xercesc/util/XercesDefs.hpp>      // for XMLCh definition

namespace trUtil
{
	/// A class that writes VRSim config files
	class VRS_UTIL_EXPORT vrsConfigWriter
	{
	public:
	  void WriteCfg(const std::string& filename);

	private:

	  /// A utility class to create xerces character types for the XML schema.
	  /// Defines the API to obtain values used when parsing the config file.
	  /// Also generates the xerces character types needed for string operations.
	  struct SchemaModel
	  {
		 SchemaModel();
		 ~SchemaModel();

		XMLCh* SCREEN_CFG;

		XMLCh* NUM_OF_SCR_CFGS;

		XMLCh* SCR_CFG_NAME;
		XMLCh* NUM_OF_SCREENS;
		XMLCh* WINDOW;
		XMLCh* WIN_CAPTION;
		XMLCh* SCR_NUMBER;
		XMLCh* WINDOW_X;
		XMLCh* WINDOW_Y;
		XMLCh* WINDOW_WIDTH;
		XMLCh* WINDOW_HEIGHT;
		XMLCh* H_FOV;
		XMLCh* V_FOV;
		XMLCh* CAMERA_POS;
			
		XMLCh* SHARE_CONTEXT;
		XMLCh* FULL_SCREEN;
		XMLCh* PIXEL_DEPTH;
		XMLCh* CHANGE_DISPLAY_RESOLUTION;
		XMLCh* VSYNC;
		XMLCh* MULTI_SAMPLE;

		XMLCh* STEREO_TYPE;
		XMLCh* STEREO_ENABLED;
		
		XMLCh* APP_CFG;

		XMLCh* LOG_LEVEL;

		 
	  };
	};
}


#endif // vrsConfigWriter_H