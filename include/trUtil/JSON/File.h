/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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

#pragma once

#include <trUtil/Export.h>

#include <trUtil/JSON/Base.h>
#include <trUtil/JSON/Value.h>

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
			* By default the it sill be saved in the PathUtils::GetUserDataPath() + PathUtils::CONFIG_PATH folder.
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
			* Clears the internal JSON Root node.
			*/
			void Clear() override;

			/**
			* Returns a reference to the internal JSON Root node.
			*/
			virtual Value& GetJSONRoot() override;

			/**
			* Prints out to the screen the whole JSON Root content.
			*/
			virtual void PrintJSONRoot() override;

			/**
			* Checks if the JSON Root Node has an entry with a given key present
			*/
			virtual bool KeyPresent(const std::string &key) const override;

			/**
			* Checks if the value stored at the specific key is a NULL
			*/
			virtual bool IsNull(const std::string &key) const override;

			/**
			* Sets the value stored at the specific key to NULL
			*/
			virtual void SetNull(const std::string &key) override;

			/**
			* Checks if the value stored at the specific key is a Boolean
			*/
			virtual bool IsBool(const std::string &key) const override;

			/**
			* Returns the Boolean value stored at the given key
			*/
			virtual bool GetBool(const std::string &key) const override;

			/**
			* Sets the Boolean value to be stored at the given key
			*/
			virtual void SetBool(const std::string &key, const bool &value) override;

			/**
			* Checks if the value stored at the specific key is True
			*/
			virtual bool IsTrue(const std::string &key) const override;

			/**
			* Checks if the value stored at the specific key is False
			*/
			virtual bool IsFalse(const std::string &key) const override;

			/**
			* Checks if the value stored at the specific key is a Number
			*/
			virtual bool IsNumber(const std::string &key) const override;

			/**
			* Checks if the value stored at the specific key is an Integer
			*/
			virtual bool IsInt(const std::string &key) const override;

			/**
			* Returns the Integer value stored at the given key
			*/
			virtual int GetInt(const std::string &key) const override;

			/**
			* Sets the Integer value to be stored at the given key
			*/
			virtual void SetInt(const std::string &key, const int &value) override;

			/**
			* Checks if the value stored at the specific key is a Double
			*/
			virtual bool IsDouble(const std::string &key) const override;

			/**
			* Returns the Double value stored at the given key
			*/
			virtual double GetDouble(const std::string &key) const override;

			/**
			* Sets the Double value to be stored at the given key
			*/
			virtual void SetDouble(const std::string &key, const double &value) override;

			/**
			* Checks if the value stored at the specific key is an Unsigned Integer
			*/
			virtual bool IsUInt(const std::string &key) const override;

			/**
			* Returns the Unsigned Integer value stored at the given key
			*/
			virtual unsigned int GetUInt(const std::string &key) const override;

			/**
			* Sets the Unsigned Integer value to be stored at the given key
			*/
			virtual void SetUInt(const std::string &key, const unsigned int &value) override;

			/**
			* Checks if the value stored at the specific key is a 64bit Integer
			*/
			virtual bool IsInt64(const std::string &key) const override;

			/**
			* Returns the 64bit Integer value stored at the given key
			*/
			virtual Int64 GetInt64(const std::string &key) const override;

			/**
			* Sets the 64bit Integer value to be stored at the given key
			*/
			virtual void SetInt64(const std::string &key, const Int64 &value) override;

			/**
			* Checks if the value stored at the specific key is a 64bit Integer
			*/
			virtual bool IsUInt64(const std::string &key) const override;

			/**
			* Returns the 64bit Integer value stored at the given key
			*/
			virtual UInt64 GetUInt64(const std::string &key) const override;

			/**
			* Sets the 64bit Integer value to be stored at the given key
			*/
			virtual void SetUInt64(const std::string &key, const UInt64 &value) override;

			/**
			* Checks if the value stored at the specific key is a float
			*/
			virtual bool IsFloat(const std::string &key) const override;

			/**
			* Returns the float value stored at the given key
			*/
			virtual float GetFloat(const std::string &key) const override;

			/**
			* Sets the float value to be stored at the given key
			*/
			virtual void SetFloat(const std::string &key, const float &value) override;

			/**
			* Checks if the value stored at the specific key is a String
			*/
			virtual bool IsString(const std::string &key) const override;

			/**
			* Returns the String value stored at the given key
			*/
			virtual const std::string GetString(const std::string &key) const override;

			/**
			* Sets the String to be stored at the given key
			*/
			virtual void SetString(const std::string &key, const std::string &value) override;

			/**
			* Checks if the value stored at the specific key is an Array
			*/
			virtual bool IsArray(const std::string &key) const override;

			/**
			* Returns the Array value stored at the given key
			*/
			virtual Array GetArray(const std::string &key) const override;

			/**
			* Sets the Array to be stored at the given key
			*/
			virtual void SetArray(const std::string &key, Array &value) override;

			/**
			* Checks if the value stored at the specific key is an Object
			*/
			virtual bool IsObject(const std::string &key) const override;

			/**
			* Returns the Object value stored at the given key
			*/
			virtual Object GetObject(const std::string &key) const override;

			/**
			* Sets the Array to be stored at the given key
			*/
			virtual void SetObject(const std::string &key, Object &value) override;

		private:
			std::string mFileName;
			std::string mFilePath;

            Value mRoot;
		};
	}
}