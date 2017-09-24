/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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

#include <trUtil/JSON/File.h>

#include <trUtil/JSON/Array.h>
#include <trUtil/JSON/Object.h>

#include <trUtil/Exception.h>
#include <trUtil/FileUtils.h>
#include <trUtil/PathUtils.h>
#include <trUtil/PlatformMacros.h>
#include <trUtil/StringUtils.h>
#include <trUtil/WarningUtils.h>
#include <trUtil/Logging/Log.h>

#include <json/reader.h>
#include <json/writer.h>
#include <osgDB/fstream>

#include <iostream>
#include <cstdio>

namespace trUtil
{
	namespace JSON
	{
		const std::string File::DEFAULT_JSON_FILE_NAME = std::string("Default.json");

		//////////////////////////////////////////////////////////////////////////
		File::File() : File(DEFAULT_JSON_FILE_NAME)
		{}

		//////////////////////////////////////////////////////////////////////////
		File::File(std::string fileName)
		{
			mFileName = fileName;
			mFilePath = PathUtils::GetUserDataPath() + PathUtils::CONFIG_PATH;
		}

		//////////////////////////////////////////////////////////////////////////
		File::~File()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::ReadFromFile()
		{
			return ReadFromFile(mFileName);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::ReadFromFile(std::string fileName)
		{
			try
			{
				mFileName = fileName;
				std::string fullFilePath = mFilePath + "/" + mFileName;
				Json::Reader reader;

				//Open a file for reading. 
				LOG_D("Opening JSON File for Reading: " + fullFilePath);


				//Read the file into the input stream. 
				LOG_D("Reading JSON File: " + fullFilePath);
				osgDB::ifstream inputStream(fullFilePath.c_str(), std::ifstream::binary);

				if (inputStream)
				{
					//Clear the root node for new input
					mRoot.clear();

					//Parse the stream into the document
					LOG_D("Parsing JSON File");
					if (!reader.parse(inputStream, mRoot))
					{
						LOG_E("JSON Parsing Error: " + reader.getFormattedErrorMessages());
						return false;
					}

					//Close the input stream
					inputStream.close();
					return true;
				}
				else
				{
					LOG_E("Can't open: " + fullFilePath);
					return false;
				}
			}
			catch (const trUtil::Exception& ex)
			{
				ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
				return false;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::WriteToFile()
		{
			return WriteToFile(mFileName);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::WriteToFile(std::string fileName)
		{
			try
			{
				mFileName = fileName;
				std::string fullFilePath = mFilePath + "/" + mFileName;
				Json::StyledWriter writer;

				//Open a file for writing
				LOG_D("Opening JSON File for Writing: " + fullFilePath);
				osgDB::ofstream outputStream(fullFilePath.c_str());

				//Writing the file
				LOG_D("Writing file");
				outputStream << writer.write(mRoot);
				outputStream.close();

				return true;
			}
			catch (const trUtil::Exception& ex)
			{
				ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
				return false;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetFileName(std::string fileName)
		{
			mFileName = fileName;
		}

		//////////////////////////////////////////////////////////////////////////
		std::string File::GetFileName() const
		{
			return mFileName;
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetFilePath(std::string newPath)
		{
			mFilePath = newPath;
		}

		//////////////////////////////////////////////////////////////////////////
		std::string File::GetFilePath() const
		{
			return mFilePath;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::FileExists()
		{
			return trUtil::FileUtils::GetInstance().FileExists(mFilePath + "/" + mFileName);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::Clear()
		{
			mRoot.clear();
		}

		//////////////////////////////////////////////////////////////////////////
		Value& File::GetJSONRoot()
		{
			return mRoot;
		}

		//////////////////////////////////////////////////////////////////////////
		void File::PrintJSONRoot()
		{
			std::cout << mRoot << std::endl;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::KeyPresent(const std::string &key) const
		{
			return mRoot.isMember(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsNull(const std::string &key) const
		{
			return mRoot[key].isNull();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetNull(const std::string &key)
		{
			mRoot[key] = Value();
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsBool(const std::string &key) const
		{
			return mRoot[key].isBool();
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::GetBool(const std::string &key) const
		{
			return mRoot[key].asBool();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetBool(const std::string &key, const bool &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsTrue(const std::string &key) const
		{
			if (KeyPresent(key))
			{
				if (GetBool(key) == true)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsFalse(const std::string &key) const
		{
			if (KeyPresent(key))
			{
				if (GetBool(key) == false)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsNumber(const std::string &key) const
		{
			return mRoot[key].isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsInt(const std::string &key) const
		{
			return mRoot[key].isInt();
		}

		//////////////////////////////////////////////////////////////////////////
		int File::GetInt(const std::string &key) const
		{
			return mRoot[key].asInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetInt(const std::string &key, const int &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsDouble(const std::string &key) const
		{
			return mRoot[key].isDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		double File::GetDouble(const std::string &key) const
		{
			return mRoot[key].asDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetDouble(const std::string &key, const double &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsUInt(const std::string &key) const
		{
			return mRoot[key].isUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		unsigned int File::GetUInt(const std::string &key) const
		{
			return mRoot[key].asUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetUInt(const std::string &key, const unsigned int &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsInt64(const std::string &key) const
		{
			return mRoot[key].isInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		Int64 File::GetInt64(const std::string &key) const
		{
			return mRoot[key].asInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetInt64(const std::string &key, const Int64 &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsUInt64(const std::string &key) const
		{
			return mRoot[key].isUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		UInt64 File::GetUInt64(const std::string &key) const
		{
			return mRoot[key].asUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetUInt64(const std::string &key, const UInt64 &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsFloat(const std::string &key) const
		{
			return mRoot[key].isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		float File::GetFloat(const std::string &key) const
		{
			return mRoot[key].asFloat();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetFloat(const std::string &key, const float &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsString(const std::string &key) const
		{
			return mRoot[key].isString();
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string File::GetString(const std::string &key) const
		{
			return mRoot[key].asString();
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetString(const std::string &key, const std::string &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsArray(const std::string &key) const
		{
			return mRoot[key].isArray();
		}

		//////////////////////////////////////////////////////////////////////////
		Array File::GetArray(const std::string &key) const
		{
			Array tempArray(mRoot[key]);
			return tempArray;
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetArray(const std::string &key, Array &Array)
		{
			mRoot[key] = Array.GetJSONRoot();
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsObject(const std::string &key) const
		{
			return mRoot[key].isObject();
		}

		//////////////////////////////////////////////////////////////////////////
		Object File::GetObject(const std::string &key) const
		{
			Object tempObject(mRoot[key]);
			return tempObject;
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetObject(const std::string &key, Object &Object)
		{
			mRoot[key] = Object.GetJSONRoot();
		}
	}    
}