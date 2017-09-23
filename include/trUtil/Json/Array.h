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
#include <trUtil/Json/ArrayBase.h>

#include <json/json.h>

#include <string>


namespace trUtil
{
	namespace JSON
	{
		class TR_UTIL_EXPORT Array : ArrayBase
		{
		public:
			/**
			* ctor
			*/
			Array();

			/**
			* ctor that takes a JSON Value of an Array type as input.
			*/
			Array(const Json::Value &Array);

			/**
			* dtor
			*/
			~Array();

			/**
			* Access an array element (zero based index ).
			*/
			Json::Value& operator[](int index);

			/**
			* Get the size of the array
			*/
			int Size();

			/**
			* Change the size of the array to the new passed in size.
			*/
			void Resize(int newSize);

			/**
			* Clears the internal JSON Root node.
			*/
			void Clear();

			/**
			* Removes a given element of the array.
			* Passes back the removed value though the pointer and sets
			* the return to TRUE
			*/
			bool RemoveIndex(int index, Json::Value *removedVal);

			/**
			* Returns a reference to the internal JSON Root node.
			*/
			virtual Json::Value& GetJSONRoot();

			/**
			* Prints out to the screen the whole JSON Root content.
			*/
			virtual void PrintJSONRoot();

			/**
			* Checks if the value stored at the specific index is a NULL
			*/
			virtual bool IsNull(int &index) const;

			/**
			* Add a NULL Value to the Array
			*/
			virtual void AddNull();

			/**
			* Checks if the value stored at the specific index is a Boolean
			*/
			virtual bool IsBool(int &index) const;

			/**
			* Returns the Boolean value stored at the given index
			*/
			virtual bool GetBool(int &index) const;

			/**
			* Adds a Boolean to the Array
			*/
			virtual void AddBool(const bool &value);

			/**
			* Checks if the value stored at the specific index is True
			*/
			virtual bool IsTrue(int &index) const;

			/**
			* Checks if the value stored at the specific index is False
			*/
			virtual bool IsFalse(int &index) const;

			/**
			* Checks if the value stored at the specific index is a Number
			*/
			virtual bool IsNumber(int &index) const;

			/**
			* Checks if the value stored at the specific index is an Integer
			*/
			virtual bool IsInt(int &index) const;

			/**
			* Returns the Integer value stored at the given index
			*/
			virtual int GetInt(int &index) const;

			/**
			* Adds the Integer value to the Array
			*/
			virtual void AddInt(const int &value);

			/**
			* Checks if the value stored at the specific index is a Double
			*/
			virtual bool IsDouble(int &index) const;

			/**
			* Returns the Double value stored at the given index
			*/
			virtual double GetDouble(int &index) const;

			/**
			* Adds the Double value to the Array
			*/
			virtual void AddDouble(const double &value);

			/**
			* Checks if the value stored at the specific index is an Unsigned Integer
			*/
			virtual bool IsUInt(int &index) const;

			/**
			* Returns the Unsigned Integer value stored at the given index
			*/
			virtual unsigned int GetUInt(int &index) const;

			/**
			* Adds the Unsigned Integer value the Array
			*/
			virtual void AddUInt(const unsigned int &value);

			/**
			* Checks if the value stored at the specific index is a 64bit Integer
			*/
			virtual bool IsInt64(int &index) const;

			/**
			* Returns the 64bit Integer value stored at the given index
			*/
			virtual Json::Value::Int64 GetInt64(int &index) const;

			/**
			* Adds the 64bit Integer value to the Array
			*/
			virtual void AddInt64(const Json::Value::Int64 &value);

			/**
			* Checks if the value stored at the specific index is a 64bit Integer
			*/
			virtual bool IsUInt64(int &index) const;

			/**
			* Returns the 64bit Integer value stored at the given index
			*/
			virtual Json::Value::UInt64 GetUInt64(int &index) const;

			/**
			* Adds the 64bit Integer value to the Array
			*/
			virtual void AddUInt64(const Json::Value::UInt64 &value);

			/**
			* Checks if the value stored at the specific index is a float
			*/
			virtual bool IsFloat(int &index) const;

			/**
			* Returns the float value stored at the given index
			*/
			virtual float GetFloat(int &index) const;

			/**
			* Adds the float value to the Array
			*/
			virtual void AddFloat(const float &value);

			/**
			* Checks if the value stored at the specific index is a String
			*/
			virtual bool IsString(int &index) const;

			/**
			* Returns the String value stored at the given index
			*/
			virtual const std::string GetString(int &index) const;

			/**
			* Adds the String to the Array
			*/
			virtual void AddString(const std::string &value);

			/**
			* Checks if the value stored at the specific index is an Array
			*/
			virtual bool IsArray(int &index) const;

			/**
			* Returns the Array value stored at the given index
			*/
			virtual Array GetArray(int &index) const;

			/**
			* Adds the Array to the Array
			*/
			virtual void AddArray(Array &Array);

			/**
			* Checks if the value stored at the specific index is an Object
			*/
			virtual bool IsObject(int &index) const;

			/**
			* Returns the Object value stored at the given index
			*/
			virtual Object GetObject(int &index) const;

			/**
			* Adds the Object to the Array
			*/
			virtual void AddObject(Object &Object);

		private:
			Json::Value mRoot = Json::Value(Json::arrayValue);
		};
	}    
}