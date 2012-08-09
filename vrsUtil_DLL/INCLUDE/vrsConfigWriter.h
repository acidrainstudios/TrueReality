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

#ifndef vrsConfigWriter_H
#define vrsConfigWriter_H 1

#include "export.h"

#include <dtUtil/log.h>                     // to read the default log name.
#include <string>                           // for data members
#include <xercesc/util/XercesDefs.hpp>      // for XMLCh definition

namespace vrsUtil
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