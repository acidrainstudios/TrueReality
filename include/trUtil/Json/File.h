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

#pragma once

#include <trUtil/Export.h>

#include <trUtil/JSON/Base.h>

#include <string>


namespace trUtil
{
	namespace JSON
	{
		class TR_UTIL_EXPORT File : Base
		{
		public:

			const static std::string DEFAULT_JSON_FILE_NAME;

			/**
			* ctor
			*/
			File();

			/**
			* Constructor that takes in the file name.
			* The user still needs to Open the file for reading or writing.
			*/
			File(std::string fileName);

			/**
			* dtor
			*/
			~File();

			/**
			* Reads from a file and parses the JSON into a Root node.
			*/
			virtual bool ReadFromFile(std::string fileName);

			/**
			* Reads from a file and parses the JSON into a Root Node.
			* Uses an internally set filename to determine what to open.
			*/
			virtual bool ReadFromFile();

			/**
			* Writes the internal Root Node to a JSON file.
			*/
			virtual bool WriteToFile(std::string fileName);

			/**
			* Writes the Root Node to a JSON file.
			* Uses an internally set filename to determine what to create.
			*/
			virtual bool WriteToFile();

			/**
			* Sets a new file name.
			* If a file has been opened already, this will close it.
			*/
			virtual void SetFileName(std::string fileName);

			/**
			* Returns the name of the current file.
			*/
			virtual std::string GetFileName() const;

			/**
			* Sets the path of where the file will be read from or written to.
			* By default the it sill be saved in the PathUtils::GetTCUserDataPath() + PathUtils::CONFIG_PATH folder.
			*/
			virtual void SetFilePath(std::string newPath);

			/**
			* Returns the path of where the file is read or written to.
			*/
			virtual std::string GetFilePath() const;

			/**
			* Returns true if the file name and path exist on the HD
			*/
			virtual bool FileExists();

			/**
			* Returns a reference to the internal JSON Root node.
			*/
			virtual Json::Value& GetJSONRoot();

			/**
			* Prints out to the screen the whole JSON Root content.
			*/
			virtual void PrintJSONRoot();

			/**
			* Checks if the JSON Root Node has an entry with a given key present
			*/
			virtual bool KeyPresent(const std::string &key) const;

			/**
			* Checks if the value stored at the specific key is a NULL
			*/
			virtual bool IsNull(const std::string &key) const;

			/**
			* Sets the value stored at the specific key to NULL
			*/
			virtual void SetNull(const std::string &key);

			/**
			* Checks if the value stored at the specific key is a Boolean
			*/
			virtual bool IsBool(const std::string &key) const;

			/**
			* Returns the Boolean value stored at the given key
			*/
			virtual bool GetBool(const std::string &key) const;

			/**
			* Sets the Boolean value to be stored at the given key
			*/
			virtual void SetBool(const std::string &key, const bool &value);

			/**
			* Checks if the value stored at the specific key is True
			*/
			virtual bool IsTrue(const std::string &key) const;

			/**
			* Checks if the value stored at the specific key is False
			*/
			virtual bool IsFalse(const std::string &key) const;

			/**
			* Checks if the value stored at the specific key is a Number
			*/
			virtual bool IsNumber(const std::string &key) const;

			/**
			* Checks if the value stored at the specific key is an Integer
			*/
			virtual bool IsInt(const std::string &key) const;

			/**
			* Returns the Integer value stored at the given key
			*/
			virtual int GetInt(const std::string &key) const;

			/**
			* Sets the Integer value to be stored at the given key
			*/
			virtual void SetInt(const std::string &key, const int &value);

			/**
			* Checks if the value stored at the specific key is a Double
			*/
			virtual bool IsDouble(const std::string &key) const;

			/**
			* Returns the Double value stored at the given key
			*/
			virtual double GetDouble(const std::string &key) const;

			/**
			* Sets the Double value to be stored at the given key
			*/
			virtual void SetDouble(const std::string &key, const double &value);

			/**
			* Checks if the value stored at the specific key is an Unsigned Integer
			*/
			virtual bool IsUInt(const std::string &key) const;

			/**
			* Returns the Unsigned Integer value stored at the given key
			*/
			virtual unsigned int GetUInt(const std::string &key) const;

			/**
			* Sets the Unsigned Integer value to be stored at the given key
			*/
			virtual void SetUInt(const std::string &key, const unsigned int &value);

			/**
			* Checks if the value stored at the specific key is a 64bit Integer
			*/
			virtual bool IsInt64(const std::string &key) const;

			/**
			* Returns the 64bit Integer value stored at the given key
			*/
			virtual Json::Value::Int64 GetInt64(const std::string &key) const;

			/**
			* Sets the 64bit Integer value to be stored at the given key
			*/
			virtual void SetInt64(const std::string &key, const Json::Value::Int64 &value);

			/**
			* Checks if the value stored at the specific key is a 64bit Integer
			*/
			virtual bool IsUInt64(const std::string &key) const;

			/**
			* Returns the 64bit Integer value stored at the given key
			*/
			virtual Json::Value::UInt64 GetUInt64(const std::string &key) const;

			/**
			* Sets the 64bit Integer value to be stored at the given key
			*/
			virtual void SetUInt64(const std::string &key, const Json::Value::UInt64 &value);

			/**
			* Checks if the value stored at the specific key is a float
			*/
			virtual bool IsFloat(const std::string &key) const;

			/**
			* Returns the float value stored at the given key
			*/
			virtual float GetFloat(const std::string &key) const;

			/**
			* Sets the float value to be stored at the given key
			*/
			virtual void SetFloat(const std::string &key, const float &value);

			/**
			* Checks if the value stored at the specific key is a String
			*/
			virtual bool IsString(const std::string &key) const;

			/**
			* Returns the String value stored at the given key
			*/
			virtual const std::string GetString(const std::string &key) const;

			/**
			* Sets the String to be stored at the given key
			*/
			virtual void SetString(const std::string &key, const std::string &value);

			/**
			* Checks if the value stored at the specific key is an Array
			*/
			virtual bool IsArray(const std::string &key) const;

			/**
			* Returns the Array value stored at the given key
			*/
			virtual Array GetArray(const std::string &key) const;

			/**
			* Sets the Array to be stored at the given key
			*/
			virtual void SetArray(const std::string &key, Array &Array);

			/**
			* Checks if the value stored at the specific key is an Object
			*/
			virtual bool IsObject(const std::string &key) const;

			/**
			* Returns the Object value stored at the given key
			*/
			virtual Object GetObject(const std::string &key) const;

			/**
			* Sets the Array to be stored at the given key
			*/
			virtual void SetObject(const std::string &key, Object &Object);

		protected:


		private:
			std::string mFileName;
			std::string mFilePath;

			Json::Value mRoot;
		};
	}
}