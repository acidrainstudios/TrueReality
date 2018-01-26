/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
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

#include <Examples/Json/Utils.h>

#include <trUtil/DefaultSettings.h>
#include <trUtil/Exception.h>
#include <trUtil/JSON/File.h>
#include <trUtil/JSON/Object.h>
#include <trUtil/JSON/Array.h>
#include <trUtil/PathUtils.h>
#include <trUtil/Console/Logo.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/Logging/Log.h>

#include <iostream>

/**
* Software's main function. 
*/
int main(int argc, char** argv)
{
    const static std::string CONFIG_FILE_NAME = "JsonExampleConf.json";
	std::string logFileName;
	std::string logLevel;
	
	//Parse command line arguments
	ParseCmdLineArgs(argc, argv, logFileName, logLevel);

	//Creates the default folders in the User Data folder. 
	trUtil::PathUtils::CreateUserDataPathTree();

	//Setup our Logging options
	trUtil::DefaultSettings::SetupLoggingOptions(logFileName, logLevel);
	
	try
	{
		//Show Logo
		trUtil::Console::Logo();

        //Start program
        std::cout << "Creating a JSON Document" << std::endl;

        trUtil::JSON::Object jsObject;
        trUtil::JSON::Array jsArray;

        trUtil::JSON::File configFile(CONFIG_FILE_NAME);

        std::cout << "Inputing Data into Document" << std::endl;

        jsArray.AddInt(55);
        jsArray.AddInt(3456);
        jsArray.AddInt64(63752);
        jsArray.AddNull();            //NULLs the value
        jsArray.AddBool(true);
        jsArray.AddString("StringValue");
        jsArray.AddDouble(45.6);
        jsArray.AddUInt(4567);
        jsArray.AddUInt64(12098);
        jsArray.AddFloat(567.54f);
        jsArray.SetComment("This is the Array Comment");

        std::cout << "JSON Array in RAM:\n" << std::endl;
        jsArray.PrintJSONRoot();
        std::cout << std::endl;

        jsObject.SetInt("MyInt", 55);
        jsObject.SetInt("MyInt2", 3456);
        jsObject.SetInt64("MyInt64", 63752);
        jsObject.SetNull("MyInt");            //NULLs the value
        jsObject.SetBool("MyBool", true);
        jsObject.SetString("MyString", "StringValue");
        jsObject.SetDouble("MyDouble", 45.6);
        jsObject.SetUInt("MyUint", 4567);
        jsObject.SetUInt64("MyUint64", 12098);
        jsObject.SetFloat("MyFloat", 567.54f);
        jsObject.SetArray("MyArray", jsArray);
        jsObject.SetComment("/This is the Object Comment");

        std::cout << "JSON jsObject in RAM:\n" << std::endl;
        jsObject.PrintJSONRoot();
        std::cout << std::endl;

        configFile.SetInt("MyInt", 55);
        configFile.SetInt("MyInt2", 3456);
        configFile.SetInt64("MyInt64", 63752);
        configFile.SetNull("MyInt");            //NULLs the value
        configFile.SetBool("MyBool", true);
        configFile.SetString("MyString", "StringValue");
        configFile.SetDouble("MyDouble", 45.6);
        configFile.SetUInt("MyUint", 4567);
        configFile.SetUInt64("MyUint64", 12098);
        configFile.SetFloat("MyFloat", 567.54f);
        configFile.SetObject("MyObject", jsObject);
        
        std::cout << "JSON File in RAM:\n" << std::endl;
        configFile.PrintJSONRoot();
        std::cout << std::endl;

        std::cout << "Writing out JSON File" << std::endl;
        configFile.WriteToFile();


        trUtil::JSON::File readFile(CONFIG_FILE_NAME);
        std::cout << "\n\nReading JSON File" << std::endl;
        readFile.ReadFromFile();

        std::cout << "JSON File in RAM:\n" << std::endl;
        readFile.PrintJSONRoot();

        trUtil::JSON::Array jsArr = configFile.GetObject("MyObject").GetArray("MyArray");
        
        std::cout << "\nJSON Array in RAM:\n" << std::endl;
        jsArr.PrintJSONRoot();

        std::cout << "\nJSON Array Size: " << jsArr.Size() << std::endl;
        std::cout << "\nIterating through JSON Array in RAM:\n" << std::endl;
        for (int i = 0; i < jsArr.Size(); i++)
        {
            std::cout << jsArr[i] << std::endl;
        }

        std::cout << "\nRemoving value 5 from the JSON Array:\n" << std::endl;
        jsArr.RemoveIndex(5, new trUtil::JSON::Value);

        std::cout << "\nJSON Array in RAM:\n" << std::endl;
        jsArr.PrintJSONRoot();

        std::cout << "\nJSON Array Size: " << jsArr.Size() << std::endl;

        //Ending program
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_RED);
		std::cerr << "The Construct is now shutting down ... " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
        LOG_A("The Construct is now shutting down ... ");
	}
    catch (const trUtil::Exception& ex)
	{
		LOG_E(EXE_NAME + " caught an unhandled exception:\n" + ex.ToString());
        ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
		return -1;
	}
	return 0;
}