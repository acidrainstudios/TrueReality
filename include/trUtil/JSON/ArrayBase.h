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

#include <trUtil/JSON/Units.h>

#include <osg/Referenced>

#include <stdint.h>
#include <string>

namespace trUtil
{
	namespace JSON
	{
		//Forward declaration
		class Object;
		class Array;

		class TR_UTIL_EXPORT ArrayBase : osg::Referenced
		{

		public:

			/**
			* Clears the internal JSON Root node.
			*/
			virtual void Clear() = 0;

			/**
			* Returns a reference to the internal JSON Root node.
			*/
			virtual Value& GetJSONRoot() = 0;

			/**
			* Prints out to the screen the whole JSON Root content.
			*/
			virtual void PrintJSONRoot() = 0;

			/**
			* Checks if the value stored at the specific index is a NULL
			*/
			virtual bool IsNull(int &index) const = 0;

			/**
			* Add a NULL Value to the Array
			*/
			virtual void AddNull() = 0;

			/**
			* Checks if the value stored at the specific index is a Boolean
			*/
			virtual bool IsBool(int &index) const = 0;

			/**
			* Returns the Boolean value stored at the given index
			*/
			virtual bool GetBool(int &index) const = 0;

			/**
			* Adds a Boolean to the Array
			*/
			virtual void AddBool(const bool &value) = 0;

			/**
			* Checks if the value stored at the specific index is True
			*/
			virtual bool IsTrue(int &index) const = 0;

			/**
			* Checks if the value stored at the specific index is False
			*/
			virtual bool IsFalse(int &index) const = 0;

			/**
			* Checks if the value stored at the specific index is a Number
			*/
			virtual bool IsNumber(int &index) const = 0;

			/**
			* Checks if the value stored at the specific index is an Integer
			*/
			virtual bool IsInt(int &index) const = 0;

			/**
			* Returns the Integer value stored at the given index
			*/
			virtual int GetInt(int &index) const = 0;

			/**
			* Adds the Integer value to the Array
			*/
			virtual void AddInt(const int &value) = 0;

			/**
			* Checks if the value stored at the specific index is a Double
			*/
			virtual bool IsDouble(int &index) const = 0;

			/**
			* Returns the Double value stored at the given index
			*/
			virtual double GetDouble(int &index) const = 0;

			/**
			* Adds the Double value to the Array
			*/
			virtual void AddDouble(const double &value) = 0;

			/**
			* Checks if the value stored at the specific index is an Unsigned Integer
			*/
			virtual bool IsUInt(int &index) const = 0;

			/**
			* Returns the Unsigned Integer value stored at the given index
			*/
			virtual unsigned int GetUInt(int &index) const = 0;

			/**
			* Adds the Unsigned Integer value the Array
			*/
			virtual void AddUInt(const unsigned int &value) = 0;

			/**
			* Checks if the value stored at the specific index is a 64bit Integer
			*/
			virtual bool IsInt64(int &index) const = 0;

			/**
			* Returns the 64bit Integer value stored at the given index
			*/
			virtual Int64 GetInt64(int &index) const = 0;

			/**
			* Adds the 64bit Integer value to the Array
			*/
			virtual void AddInt64(const Int64 &value) = 0;

			/**
			* Checks if the value stored at the specific index is a 64bit Integer
			*/
			virtual bool IsUInt64(int &index) const = 0;

			/**
			* Returns the 64bit Integer value stored at the given index
			*/
			virtual UInt64 GetUInt64(int &index) const = 0;

			/**
			* Adds the 64bit Integer value to the Array
			*/
			virtual void AddUInt64(const UInt64 &value) = 0;

			/**
			* Checks if the value stored at the specific index is a float
			*/
			virtual bool IsFloat(int &index) const = 0;

			/**
			* Returns the float value stored at the given index
			*/
			virtual float GetFloat(int &index) const = 0;

			/**
			* Adds the float value to the Array
			*/
			virtual void AddFloat(const float &value) = 0;

			/**
			* Checks if the value stored at the specific index is a String
			*/
			virtual bool IsString(int &index) const = 0;

			/**
			* Returns the String value stored at the given index
			*/
			virtual const std::string GetString(int &index) const = 0;

			/**
			* Adds the String to the Array
			*/
			virtual void AddString(const std::string &value) = 0;

			/**
			* Checks if the value stored at the specific index is an Array
			*/
			virtual bool IsArray(int &index) const = 0;

			/**
			* Returns the Array value stored at the given index
			*/
			virtual Array GetArray(int &index) const = 0;

			/**
			* Adds the Array to the Array
			*/
			virtual void AddArray(Array &Array) = 0;

			/**
			* Checks if the value stored at the specific index is an Object
			*/
			virtual bool IsObject(int &index) const = 0;

			/**
			* Returns the Object value stored at the given index
			*/
			virtual Object GetObject(int &index) const = 0;

			/**
			* Adds the Object to the Array
			*/
			virtual void AddObject(Object &Object) = 0;
		};
	}    
}