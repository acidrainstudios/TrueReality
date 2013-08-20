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

#ifndef vrsConfigParser_H
#define vrsConfigParser_H 1

#include "export.h"

#include <string>

#include <osg/Referenced>



namespace vrsUtil
{
	/**
	* This class parses all the config option from VRSimCfg.xml
	* It uses other classes to pull in each individual section of the XML file
	*/
	class VRS_UTIL_EXPORT vrsConfigParser: public osg::Referenced
	{
	public:

		/**
		* Constructor
		*/
		vrsConfigParser(const std::string& configFileName = "VRSimCfg.xml");

		/**
		* Sets a new Config File Name
		*/
		void SetConfigFileName(const std::string& configFileName);

		/**
		* Gets the Config File Name
		*/
		const std::string& GetConfigFileName(){return mConfigFileName;}

		/**
		* Sets a new Config File Path
		*/
		void SetConfigFilePath(const std::string& configFilePath);

		/**
		* Gets the Config File Path
		*/
		const std::string& GetConfigFilePath(){return mConfigFilePath;}

	private:

		//Holds the Name of the Config File
		std::string mConfigFileName;

		//Holds the full Path and Name of the Config File
		std::string mConfigFilePath;
	
	};

}

#endif // vrsConfigParser_H