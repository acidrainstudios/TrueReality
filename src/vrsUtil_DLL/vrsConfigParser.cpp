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

#ifndef vrsConfigParser_CPP
#define vrsConfigParser_CPP 1

#include "..\\Include\vrsConfigParser.h"

#include <iostream>

#include <dtUtil/datapathutils.h>
#include <dtUtil/log.h>

namespace vrsUtil
{
	// Ctor
	vrsConfigParser::vrsConfigParser(const std::string& configFileName)
	{
		SetConfigFileName(configFileName);	
	}

	// Sets the Config File Name
	void vrsConfigParser::SetConfigFileName(const std::string& configFileName)
	{
		mConfigFileName = configFileName;
		SetConfigFilePath(dtUtil::GetDeltaRootPath() + "/Bin/" + mConfigFileName);	
	}

	// Sets the Full Config File Name and Path
	void vrsConfigParser::SetConfigFilePath(const std::string &configFilePath)
	{
		mConfigFilePath = configFilePath;
		#ifdef _DEBUG
			LOG_INFO("VRSim Config File: " + mConfigFilePath + '\n');
		#endif
	}

}

#endif // vrsConfigParser_CPP