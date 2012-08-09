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

#ifndef vrsConfigWriter_CPP
#define vrsConfigWriter_CPP 1

#include "..\\Include\vrsConfigWriter.h"
#include <xercesc/util/XMLString.hpp>

using namespace XERCES_CPP_NAMESPACE;

namespace vrsUtil
{
	void vrsConfigWriter::WriteCfg(const std::string &filename)
	{

	}

	vrsConfigWriter::SchemaModel::SchemaModel()
	{
		//WINDOW = XMLString::transcode( ApplicationConfigSchema::WINDOW.c_str() );
		
	}

	vrsConfigWriter::SchemaModel::~SchemaModel()
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


#endif // vrsConfigWriter_CPP