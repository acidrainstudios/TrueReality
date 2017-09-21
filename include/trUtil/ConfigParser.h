/*
* True Reality Open Source Game and Simulation Engine
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

#ifndef ConfigParser_H
#define ConfigParser_H 1

#include "export.h"

#include <string>

#include <osg/Referenced>



namespace trUtil
{
	///**
	//* This class parses all the config option from VRSimCfg.xml
	//* It uses other classes to pull in each individual section of the XML file
	//*/
	//class TR_UTIL_EXPORT ConfigParser: public osg::Referenced
	//{
	//public:

	//	/**
	//	* Constructor
	//	*/
	//	ConfigParser(const std::string& configFileName = "VRSimCfg.xml");

	//	/**
	//	* Sets a new Config File Name
	//	*/
	//	void SetConfigFileName(const std::string& configFileName);

	//	/**
	//	* Gets the Config File Name
	//	*/
	//	const std::string& GetConfigFileName(){return mConfigFileName;}

	//	/**
	//	* Sets a new Config File Path
	//	*/
	//	void SetConfigFilePath(const std::string& configFilePath);

	//	/**
	//	* Gets the Config File Path
	//	*/
	//	const std::string& GetConfigFilePath(){return mConfigFilePath;}

	//private:

	//	//Holds the Name of the Config File
	//	std::string mConfigFileName;

	//	//Holds the full Path and Name of the Config File
	//	std::string mConfigFilePath;
	//
	//};

}

#endif // ConfigParser_H