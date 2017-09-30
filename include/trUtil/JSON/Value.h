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

#include <json/value.h>

#include <ostream>
#include <memory>

namespace trUtil
{
	namespace JSON
	{
        //Forward declaration
        class Array;
        class Object;

		typedef int Int;
		typedef unsigned int UInt;
#if defined(JSON_NO_INT64)
		typedef int LargestInt;
		typedef unsigned int LargestUInt;
#else   // if defined(JSON_NO_INT64)
		// For Microsoft Visual use specific types as long long is not supported
#if defined(_MSC_VER) // Microsoft Visual Studio
		typedef __int64 Int64;
		typedef unsigned __int64 UInt64;
#else   // if defined(_MSC_VER) // Other platforms, use long long
		typedef int64_t Int64;
		typedef uint64_t UInt64;
#endif // if defined(_MSC_VER)
		typedef Int64 LargestInt;
		typedef UInt64 LargestUInt;
#endif // if defined(JSON_NO_INT64)

		/** 
		* @brief Type of the value held by a Value object.
		*/
		enum ValueType 
		{
			NullValue = Json::ValueType::nullValue, ///'null' value
			IntValue = Json::ValueType::intValue,      ///signed integer value
			UintValue = Json::ValueType::uintValue,     ///unsigned integer value
			RealValue = Json::ValueType::realValue,     ///double value
			StringValue = Json::ValueType::stringValue,   ///UTF-8 string value
			BooleanValue = Json::ValueType::booleanValue,  ///bool value
			ArrayValue = Json::ValueType::arrayValue,    ///array value (ordered list)
			ObjectValue = Json::ValueType::objectValue    ///object value (collection of name/value pairs).
		};

		/** 
		* @brief Represents a JSON value.
		*
		* This class is a discriminated union wrapper that can represents a:
		* - signed integer [range: Value::MinInt - Value::MaxInt]
		* - unsigned integer (range: 0 - Value::MaxUInt)
		* - double
		* - UTF-8 string
		* - boolean
		* - 'null'
		* - an ordered list of Value
		* - collection of name/value pairs (javascript object)
		*
		* The type of the held value is represented by a #ValueType and
		* can be obtained using Type().
		*
		* Values of an #ObjectValue or #ArrayValue can be accessed using operator[]()
		* methods.
		* Non-const methods will automatically create the a #NullValue element
		* if it does not exist.
		* The sequence of an #ArrayValue will be automatically resized and initialized
		* with #nNllValue. Resize() can be used to enlarge or truncate an #ArrayValue.
		*
		* The Get() methods can be used to obtain default value in the case the
		* required element does not exist.
		*
		* It is possible to iterate over the list of a #ObjectValue values using
		* the GetMemberNames() method.
		*
		* @note #Value string-length fit in size_t, but keys must be < 2^30.
		* (The reason is an implementation detail.) A #CharReader will raise an
		* exception if a bound is exceeded to avoid security holes in your app,
		* but the Value API does *not* check bounds. That is the responsibility
		* of the caller.
		*/
		class TR_UTIL_EXPORT Value
		{
		public:

			typedef std::vector<std::string> Members;

			/**
			* ctor
			*/
			Value(Json::Value& value);

			/**
			* ctor
			*/
			Value(ValueType type = NullValue);
			
			/**
			* ctor
			*/
			Value(Int value);
			
			/**
			* ctor
			*/
			Value(UInt value);
			
			/**
			* ctor
			*/
			Value(Int64 value);
			
			/**
			* ctor
			*/
			Value(UInt64 value);

			/**
			* ctor
			*/
			Value(double value);

			/**
			* ctor
			*/
			Value(const char* value); ///< Copy til first 0. (NULL causes to seg-fault.)

			/**
			* ctor
			*/
			Value(const char* begin, const char* end); ///< Copy all, incl zeroes.

			/**
			* ctor
			*/
			Value(const std::string& value); ///< Copy data() til size(). Embedded zeroes too.

			/**
			* ctor
			*/
			Value(bool value);

			/**
			* ctor
			*/
			Value(const Value& other);

			/**
			* ctor
			*/
			Value(Value&& other);

            /**
            * dtor
            */
            ~Value();

			/**
			* Returns a reference to the internal Json::Value.
			*/
			Json::Value& GetJsonValue();

			/**
			* Returns a reference to the internal Json::Value.
			*/
			const Json::Value& GetJsonValue() const;

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
			* Clears the internal JSON Root node.
			*/
			virtual void Clear();

			/**
			* Returns the size of the array.
			*/
			int Size();

			/**
			* Change the size of the array. 
			*/
			void Resize(int newSize);

			/**
			* Return true if index < Size()
			*/
			bool IsValidIndex(int index) const;

			/**
			* Remove the given Index value
			*/
			bool RemoveIndex(int index, Value *removedVal);

			/**
			* Returns the value names contained in the object
			*/
			const Value::Members GetMemberNames() const;

			/**
			* Returns true if a member with the passed in key is present. 
			*/
			bool HasMember(const std::string& key) const;

			/**
			* Checks if the JSON Root Node has an entry with a given key present
			*/
			virtual bool KeyPresent(const std::string &key) const;

            /**
            * Checks if the value stored is a NULL
            */
            virtual bool IsNull() const;

			/**
			* Checks if the value stored is a NULL
			*/
			virtual bool IsNull(const int index) const;

            /**
            * Checks if the value stored is a NULL
            */
            virtual bool IsNull(const std::string& key) const;

			/**
			* Return true if empty array, empty object, or null, otherwise, false.
			*/
			virtual bool IsEmpty() const;

            /**
            * Return true if empty array, empty object, or null, otherwise, false.
            */
            virtual bool IsEmpty(const int index) const;

            /**
            * Return true if empty array, empty object, or null, otherwise, false.
            */
            virtual bool IsEmpty(const std::string& key) const;

			/**
			* Add a value at the end of the array. 
			*/
			virtual void Append(const Value& val);

			/**
			* Checks if the value stored is a Boolean
			*/
			virtual bool IsBool() const;

            /**
            * Checks if the value stored is a Boolean
            */
            virtual bool IsBool(const int index) const;

            /**
            * Checks if the value stored is a Boolean
            */
            virtual bool IsBool(const std::string& key) const;

			/**
			* Returns the Boolean value
			*/
			virtual bool GetBool() const;

            /**
            * Returns the Boolean value
            */
            virtual bool GetBool(const int index) const;

            /**
            * Returns the Boolean value
            */
            virtual bool GetBool(const std::string& key) const;

            /**
            * Sets the Boolean value in the Object
            */
            virtual void SetBool(const std::string& key, bool value);

			/**
			* Checks if the value stored is a Number
			*/
			virtual bool IsNumber() const;

            /**
            * Checks if the value stored is a Number
            */
            virtual bool IsNumber(const int index) const;

            /**
            * Checks if the value stored is a Number
            */
            virtual bool IsNumber(const std::string& key) const;


			/**
			* Checks if the value stored is an Integer
			*/
			virtual bool IsInt() const;

            /**
            * Checks if the value stored is an Integer
            */
            virtual bool IsInt(const int index) const;

            /**
            * Checks if the value stored is an Integer
            */
            virtual bool IsInt(const std::string& key) const;

			/**
			* Returns the Integer value
			*/
			virtual int GetInt() const;

            /**
            * Returns the Integer value
            */
            virtual int GetInt(const int index) const;

            /**
            * Returns the Integer value
            */
            virtual int GetInt(const std::string& key) const;

            /**
            * Sets the Integer value in the Object
            */
            virtual void SetInt(const std::string& key, int value);

			/**
			* Checks if the value stored is a Double
			*/
			virtual bool IsDouble() const;

            /**
            * Checks if the value stored is a Double
            */
            virtual bool IsDouble(const int index) const;

            /**
            * Checks if the value stored is a Double
            */
            virtual bool IsDouble(const std::string& key) const;

			/**
			* Returns the Double value
			*/
			virtual double GetDouble() const;

            /**
            * Returns the Double value
            */
            virtual double GetDouble(const int index) const;

            /**
            * Returns the Double value
            */
            virtual double GetDouble(const std::string& key) const;

            /**
            * Sets the Double value in the Object
            */
            virtual void SetDouble(const std::string& key, double value);

			/**
			* Checks if the value stored Unsigned Integer
			*/
			virtual bool IsUInt() const;

            /**
            * Checks if the value stored Unsigned Integer
            */
            virtual bool IsUInt(const int index) const;

            /**
            * Checks if the value stored Unsigned Integer
            */
            virtual bool IsUInt(const std::string& key) const;

			/**
			* Returns the Unsigned Integer value
			*/
			virtual unsigned int GetUInt() const;

            /**
            * Returns the Unsigned Integer value
            */
            virtual unsigned int GetUInt(const int index) const;

            /**
            * Returns the Unsigned Integer value
            */
            virtual unsigned int GetUInt(const std::string& key) const;

            /**
            * Sets the Unsigned Int value in the Object
            */
            virtual void SetUInt(const std::string& key, unsigned int value);

			/**
			* Checks if the value stored is a 64bit Integer
			*/
			virtual bool IsInt64() const;

            /**
            * Checks if the value stored is a 64bit Integer
            */
            virtual bool IsInt64(const int index) const;

            /**
            * Checks if the value stored is a 64bit Integer
            */
            virtual bool IsInt64(const std::string& key) const;

			/**
			* Returns the 64bit Integer value
			*/
			virtual Int64 GetInt64() const;

            /**
            * Returns the 64bit Integer value
            */
            virtual Int64 GetInt64(const int index) const;

            /**
            * Returns the 64bit Integer value
            */
            virtual Int64 GetInt64(const std::string& key) const;
			
            /**
			* Checks if the value stored is a 64bit Unsigned Integer
			*/
			virtual bool IsUInt64() const;

            /**
            * Checks if the value stored is a 64bit Unsigned Integer
            */
            virtual bool IsUInt64(const int index) const;

            /**
            * Checks if the value stored is a 64bit Unsigned Integer
            */
            virtual bool IsUInt64(const std::string& key) const;

			/**
			* Returns the Unsigned 64bit Integer value
			*/
			virtual UInt64 GetUInt64() const;

            /**
            * Returns the Unsigned 64bit Integer value
            */
            virtual UInt64 GetUInt64(const int index) const;

            /**
            * Returns the Unsigned 64bit Integer value
            */
            virtual UInt64 GetUInt64(const std::string& key) const;

			/**
			* Checks if the value stored is a float
			*/
			virtual bool IsFloat() const;

            /**
            * Checks if the value stored is a float
            */
            virtual bool IsFloat(const int index) const;

            /**
            * Checks if the value stored is a float
            */
            virtual bool IsFloat(const std::string& key) const;

			/**
			* Returns the float value stored
			*/
			virtual float GetFloat() const;

            /**
            * Returns the float value stored
            */
            virtual float GetFloat(const int index) const;

            /**
            * Returns the float value stored
            */
            virtual float GetFloat(const std::string& key) const;

			/**
			* Checks if the value stored is a String
			*/
			virtual bool IsString() const;

            /**
            * Checks if the value stored is a String
            */
            virtual bool IsString(const int index) const;

            /**
            * Checks if the value stored is a String
            */
            virtual bool IsString(const std::string& key) const;

			/**
			* Returns the String value stored
			*/
			virtual const std::string GetString() const;
            
            /**
            * Returns the String value stored
            */
            virtual const std::string GetString(const int index) const;

            /**
            * Returns the String value stored
            */
            virtual const std::string GetString(const std::string& key) const;

			/**
			* Checks if the value stored is an Array
			*/
			virtual bool IsArray() const;

            /**
            * Checks if the value stored is an Array
            */
            virtual bool IsArray(const int index) const;

            /**
            * Checks if the value stored is an Array
            */
            virtual bool IsArray(const std::string& key) const;

            /**
            * Returns the Array value stored
            */
            virtual const Array GetArray() const;

            /**
            * Returns the Array value stored
            */
            virtual const Array GetArray(const int index) const;

            /**
            * Returns the Array value stored
            */
            virtual const Array GetArray(const std::string& key) const;

			/**
			* Checks if the value stored is an Object
			*/
			virtual bool IsObject() const;

            /**
            * Checks if the value stored is an Object
            */
            virtual bool IsObject(const int index) const;

            /**
            * Checks if the value stored is an Object
            */
            virtual bool IsObject(const std::string& key) const;

            /**
            * Returns the Object value stored
            */
            virtual const Object GetObject() const;

            /**
            * Returns the Object value stored
            */
            virtual const Object GetObject(const int index) const;

            /**
            * Returns the Object value stored
            */
            virtual const Object GetObject(const std::string& key) const;

            /**
            * Converts JSON::ValueType to Json::ValueType
            */
            Json::ValueType ToValueType(ValueType val);

            /**
            * Converts Json::ValueType to JSON::ValueType
            */
            ValueType ToValueType(Json::ValueType val);

			/**
			* Implicit conversion operator to Json::Value
			*/
			operator Json::Value() const;

			/**
			* Implicit conversion operator to Json::Value
			*/
			operator Json::Value& ();

			/**
			* Implicit conversion operator to Json::Value
			*/
			operator const Json::Value& () const;

			/**
			* Implicit conversion operator to Json::Value
			*/
			operator Json::Value* ();

			/// Access an array element (zero based index ).
			/// If the array contains less than index element, then null value are
			/// inserted
			/// in the array so that its size is index+1.
			/// (You may need to say 'value[0u]' to get your compiler to distinguish
			///  this from the operator[] which takes a string.)
			Value operator[](int index);

			/// Access an array element (zero based index )
			/// (You may need to say 'value[0u]' to get your compiler to distinguish
			///  this from the operator[] which takes a string.)
			const Value operator[](int index) const;

			/// Access an object value by name, create a null member if it does not exist.
			/// \note Because of our implementation, keys are limited to 2^30 -1 chars.
			///  Exceeding that will cause an exception.
			Value operator[](const char* key);

			/// Access an object value by name, returns null if there is no member with
			/// that name.
			const Value operator[](const char* key) const;

			/// Access an object value by name, create a null member if it does not exist.
			/// \param key may contain embedded nulls.
			Value operator[](const std::string& key);

			/// Access an object value by name, returns null if there is no member with
			/// that name.
			/// \param key may contain embedded nulls.
			const Value operator[](const std::string& key) const;

			Value& operator=(Value other);

		protected:

            bool clearInternalVal = true;
            Json::Value* mValuePtr = nullptr;
		};

		/**
		* OStream operator
		*/
		TR_UTIL_EXPORT std::ostream& operator<<(std::ostream&, const Value& root);
	}
}