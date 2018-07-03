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
* @author Maxim Serebrennik
*/

#pragma once


#include <trUtil/Export.h>

#include <trUtil/JSON/ArrayBase.h>
#include <trUtil/JSON/Value.h>

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
			Array(const Value &Array);

			/**
			* dtor
			*/
			~Array();

			/**
			* Access an array element (zero based index ).
            * The return is by value, but the internal json object is stored by
            * reference. 
			*/
			Value operator[](int index);

            /*
            * Adds a comment to the internal value
            */
            void SetComment(const std::string& comment);

            /**
            * Checks if the internal value has a comment
            */
            bool HasComment() const;

            /**
            * Returns the internal comment
            */
            std::string GetComment() const;

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
			void Clear() override;

			/**
			* Removes a given element of the array.
			* Passes back the removed value though the pointer and sets
			* the return to TRUE
			*/
			bool RemoveIndex(int index, Value *removedVal);

			/**
			* Returns a reference to the internal JSON Root node.
			*/
			virtual Value& GetJSONRoot() override;

			/**
			* Prints out to the screen the whole JSON Root content.
			*/
			virtual void PrintJSONRoot() override;

			/**
			* Checks if the value stored at the specific index is a NULL
			*/
			virtual bool IsNull(int &index) const override;

			/**
			* Add a NULL Value to the Array
			*/
			virtual void AddNull() override;

			/**
			* Checks if the value stored at the specific index is a Boolean
			*/
			virtual bool IsBool(int &index) const override;

			/**
			* Returns the Boolean value stored at the given index
			*/
			virtual bool GetBool(int &index) const override;

			/**
			* Adds a Boolean to the Array
			*/
			virtual void AddBool(const bool &value) override;

			/**
			* Checks if the value stored at the specific index is True
			*/
			virtual bool IsTrue(int &index) const override;

			/**
			* Checks if the value stored at the specific index is False
			*/
			virtual bool IsFalse(int &index) const override;

			/**
			* Checks if the value stored at the specific index is a Number
			*/
			virtual bool IsNumber(int &index) const override;

			/**
			* Checks if the value stored at the specific index is an Integer
			*/
			virtual bool IsInt(int &index) const override;

			/**
			* Returns the Integer value stored at the given index
			*/
			virtual int GetInt(int &index) const override;

			/**
			* Adds the Integer value to the Array
			*/
			virtual void AddInt(const int &value) override;

			/**
			* Checks if the value stored at the specific index is a Double
			*/
			virtual bool IsDouble(int &index) const override;

			/**
			* Returns the Double value stored at the given index
			*/
			virtual double GetDouble(int &index) const override;

			/**
			* Adds the Double value to the Array
			*/
			virtual void AddDouble(const double &value) override;

			/**
			* Checks if the value stored at the specific index is an Unsigned Integer
			*/
			virtual bool IsUInt(int &index) const override;

			/**
			* Returns the Unsigned Integer value stored at the given index
			*/
			virtual unsigned int GetUInt(int &index) const override;

			/**
			* Adds the Unsigned Integer value the Array
			*/
			virtual void AddUInt(const unsigned int &value) override;

			/**
			* Checks if the value stored at the specific index is a 64bit Integer
			*/
			virtual bool IsInt64(int &index) const override;

			/**
			* Returns the 64bit Integer value stored at the given index
			*/
			virtual Int64 GetInt64(int &index) const override;

			/**
			* Adds the 64bit Integer value to the Array
			*/
			virtual void AddInt64(const Int64 &value) override;

			/**
			* Checks if the value stored at the specific index is a 64bit Integer
			*/
			virtual bool IsUInt64(int &index) const override;

			/**
			* Returns the 64bit Integer value stored at the given index
			*/
			virtual UInt64 GetUInt64(int &index) const override;

			/**
			* Adds the 64bit Integer value to the Array
			*/
			virtual void AddUInt64(const UInt64 &value) override;

			/**
			* Checks if the value stored at the specific index is a float
			*/
			virtual bool IsFloat(int &index) const override;

			/**
			* Returns the float value stored at the given index
			*/
			virtual float GetFloat(int &index) const override;

			/**
			* Adds the float value to the Array
			*/
			virtual void AddFloat(const float &value) override;

			/**
			* Checks if the value stored at the specific index is a String
			*/
			virtual bool IsString(int &index) const override;

			/**
			* Returns the String value stored at the given index
			*/
			virtual const std::string GetString(int &index) const override;

			/**
			* Adds the String to the Array
			*/
			virtual void AddString(const std::string &value) override;

			/**
			* Checks if the value stored at the specific index is an Array
			*/
			virtual bool IsArray(int &index) const override;

			/**
			* Returns the Array value stored at the given index
			*/
			virtual Array GetArray(int &index) const override;

			/**
			* Adds the Array to the Array
			*/
			virtual void AddArray(Array &Array) override;

			/**
			* Checks if the value stored at the specific index is an Object
			*/
			virtual bool IsObject(int &index) const override;

			/**
			* Returns the Object value stored at the given index
			*/
			virtual Object GetObject(int &index) const override;

			/**
			* Adds the Object to the Array
			*/
			virtual void AddObject(Object &Object) override;

		private:
			Value mRoot = Value(ValueType::ArrayValue);
		};
	}    
}