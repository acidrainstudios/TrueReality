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
					mRoot.Clear();

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
			mRoot.Clear();
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
			return mRoot.HasMember(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsNull(const std::string &key) const
		{
			return mRoot.IsNull(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetNull(const std::string &key)
		{
			mRoot.SetNull(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsBool(const std::string &key) const
		{
			return mRoot.IsBool(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::GetBool(const std::string &key) const
		{
			return mRoot.GetBool(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetBool(const std::string &key, const bool &value)
		{
			mRoot.SetBool(key, value);
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
			return mRoot.IsNumber(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsInt(const std::string &key) const
		{
			return mRoot.IsInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		int File::GetInt(const std::string &key) const
		{
			return mRoot.GetInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetInt(const std::string &key, const int &value)
		{
			mRoot.SetInt(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsDouble(const std::string &key) const
		{
			return mRoot.IsDouble(key);
		}

		//////////////////////////////////////////////////////////////////////////
		double File::GetDouble(const std::string &key) const
		{
			return mRoot.GetDouble(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetDouble(const std::string &key, const double &value)
		{
			mRoot.SetDouble(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsUInt(const std::string &key) const
		{
			return mRoot.IsUInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		unsigned int File::GetUInt(const std::string &key) const
		{
			return mRoot.GetUInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetUInt(const std::string &key, const unsigned int &value)
		{
			mRoot.SetUInt(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsInt64(const std::string &key) const
		{
			return mRoot.IsInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		Int64 File::GetInt64(const std::string &key) const
		{
			return mRoot.GetInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetInt64(const std::string &key, const Int64 &value)
		{
			mRoot.SetInt64(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsUInt64(const std::string &key) const
		{
			return mRoot.IsUInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		UInt64 File::GetUInt64(const std::string &key) const
		{
			return mRoot.GetUInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetUInt64(const std::string &key, const UInt64 &value)
		{
			mRoot.SetUInt64(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsFloat(const std::string &key) const
		{
			return mRoot.IsFloat(key);
		}

		//////////////////////////////////////////////////////////////////////////
		float File::GetFloat(const std::string &key) const
		{
			return mRoot.GetFloat(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetFloat(const std::string &key, const float &value)
		{
			mRoot.SetFloat(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsString(const std::string &key) const
		{
			return mRoot.IsString(key);
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string File::GetString(const std::string &key) const
		{
			return mRoot.GetString(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetString(const std::string &key, const std::string &value)
		{
			mRoot.SetString(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsArray(const std::string &key) const
		{
			return mRoot.IsArray(key);
		}

		//////////////////////////////////////////////////////////////////////////
		Array File::GetArray(const std::string &key) const
		{
			return mRoot.GetArray(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetArray(const std::string &key, Array &value)
		{
			mRoot.SetArray(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool File::IsObject(const std::string &key) const
		{
			return mRoot.IsObject(key);
		}

		//////////////////////////////////////////////////////////////////////////
		Object File::GetObject(const std::string &key) const
		{
			return mRoot.GetObject(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void File::SetObject(const std::string &key, Object &value)
		{
			mRoot.SetObject(key, value);
		}
	}    
}