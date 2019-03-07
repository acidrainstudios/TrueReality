/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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

#include <ostream>
#include <memory>
#include <vector>

// Forward declarations to avoid including Json/valu.h
namespace Json
{
    /**
     * @class   Value
     *
     * @brief   A value.
     */
    class Value;

    /**
     * @enum    ValueType
     *
     * @brief   Values that represent value types.
     */
    enum ValueType;
}

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::JSON
{
    /**
     * @brief   Forward declaration.
     */
    class Array;
    class Object;

    /** @brief   The int. */
    using Int = int;
    /** @brief   The int. */
    using UInt = unsigned int;
#if defined(JSON_NO_INT64)
    /** @brief   The largest int. */
    using LargestInt = int;
    /** @brief   The largest u int. */
    using LargestUInt = unsigned int;
#else   // if defined(JSON_NO_INT64)
    // For Microsoft Visual use specific types as long long is not supported
#if defined(_MSC_VER) // Microsoft Visual Studio
    /** @brief   The fourth int 6. */
    using Int64 = __int64;
    /** @brief   The fourth u int 6. */
    using UInt64 = unsigned __int64;
#else   // if defined(_MSC_VER) // Other platforms, use long long
    /** @brief   The fourth int 6. */
    using  Int64 = int64_t;
    /** @brief   The fourth u int 6. */
    using  UInt64 = uint64_t;
#endif // if defined(_MSC_VER)
    /** @brief   The largest int. */
    using LargestInt = Int64;
    /** @brief   The largest u int. */
    using LargestUInt = UInt64;
#endif // if defined(JSON_NO_INT64)

    /**
     * @enum    ValueType
     *
     * @brief   Type of the value held by a Value object.
     *          
     * @author Maxim Serebrennik
     */
    enum ValueType 
    {
        NullValue = 0,      ///'null' value
        IntValue = 1,       ///signed integer value
        UintValue = 2,      ///unsigned integer value
        RealValue = 3,      ///double value
        StringValue = 4,    ///UTF-8 string value
        BooleanValue = 5,   ///bool value
        ArrayValue = 6,     ///array value (ordered list)
        ObjectValue = 7     ///object value (collection of name/value pairs).
    };

    /**
     * @class   Value
     *
     * @brief   Represents a JSON value.
     *          
     *          This class is a discriminated union wrapper that can represents a:
     *          - signed integer [range: Value::MinInt - Value::MaxInt]
     *          - unsigned integer (range: 0 - Value::MaxUInt)
     *          - double
     *          - UTF-8 string
     *          - boolean
     *          - 'null'
     *          - an ordered list of Value
     *          - collection of name/value pairs (javascript object)
     *          
     *          The type of the held value is represented by a #ValueType and can be obtained using
     *          Type().
     *          
     *          Values of an #ObjectValue or #ArrayValue can be accessed using operator[]()
     *          methods. Non-const methods will automatically create the a #NullValue element if it
     *          does not exist. The sequence of an #ArrayValue will be automatically resized and
     *          initialized with
     *          #nNllValue. Resize() can be used to enlarge or truncate an #ArrayValue.
     *          
     *          The Get() methods can be used to obtain default value in the case the required
     *          element does not exist.
     *          
     *          It is possible to iterate over the list of a #ObjectValue values using the
     *          GetMemberNames()
     *          method.
     *          
     *          @note #Value string-length fit in size_t, but keys must be &lt; 2^30. (The reason is
     *          an implementation detail.) A #CharReader will raise an exception if a bound is
     *          exceeded to avoid security holes in your app, but the Value API does *not* check
     *          bounds. That is the responsibility of the caller.
     *
     * @author  Maxim Serebrennik
     */
    class TR_UTIL_EXPORT Value
    {
    public:

        /** @brief   The members. */
        using Members = std::vector<std::string>;

        /**
         * @fn  Value::Value(Json::Value& value);
         *
         * @brief   ctor.
         *
         * @param [in,out]  value   The value.
         */
        Value(Json::Value& value);

        /**
         * @fn  Value::Value(ValueType type = NullValue);
         *
         * @brief   ctor.
         *
         * @param   type    (Optional) The type.
         */
        Value(ValueType type = NullValue);

        /**
         * @fn  Value::Value(Int value);
         *
         * @brief   ctor.
         *
         * @param   value   The value.
         */
        Value(Int value);

        /**
         * @fn  Value::Value(UInt value);
         *
         * @brief   ctor.
         *
         * @param   value   The value.
         */
        Value(UInt value);

        /**
         * @fn  Value::Value(Int64 value);
         *
         * @brief   ctor.
         *
         * @param   value   The value.
         */
        Value(Int64 value);

        /**
         * @fn  Value::Value(UInt64 value);
         *
         * @brief   ctor.
         *
         * @param   value   The value.
         */
        Value(UInt64 value);

        /**
         * @fn  Value::Value(double value);
         *
         * @brief   ctor.
         *
         * @param   value   The value.
         */
        Value(double value);

        /**
         * @fn  Value::Value(const char* value);
         *
         * @brief   ctor.
         *
         * @param   value   The value.
         */
        Value(const char* value); ///< Copy til first 0. (NULL causes to seg-fault.)

        /**
         * @fn  Value::Value(const char* begin, const char* end);
         *
         * @brief   ctor.
         *
         * @param   begin   The begining value.
         * @param   end     The end.
         */
        Value(const char* begin, const char* end); ///< Copy all, incl zeroes.

        /**
         * @fn  Value::Value(const std::string& value);
         *
         * @brief   ctor.
         *
         * @param   value   The value.
         */
        Value(const std::string& value); ///< Copy data() til size(). Embedded zeroes too.

        /**
         * @fn  Value::Value(bool value);
         *
         * @brief   ctor.
         *
         * @param   value   True to value.
         */
        Value(bool value);

        /**
         * @fn  Value::Value(const Value& other);
         *
         * @brief   ctor.
         *
         * @param   other   The other.
         */
        Value(const Value& other);

        /**
         * @fn  Value::Value(Value&& other);
         *
         * @brief   ctor Note: Can't implement due to
         *             1. JsonCpp does not supply a move assignment operator. 2. JsonCpp does not have a
         *             move constructor that takes our JSON::Value type (obviously)
         *                and wrapping it to add one is not worth the effort.
         *
         * @param [in,out]  other   The other.
         */
        //Value(Value&& other);

        /**
         * @fn  Value::~Value();
         *
         * @brief   dtor.
         */
        ~Value();

        /**
         * @fn  Json::Value& Value::GetJsonValue();
         *
         * @brief   Returns a reference to the internal Json::Value.
         *
         * @return  The JSON value.
         */
        Json::Value& GetJsonValue();

        /**
         * @fn  const Json::Value& Value::GetJsonValue() const;
         *
         * @brief   Returns a reference to the internal Json::Value.
         *
         * @return  The JSON value.
         */
        const Json::Value& GetJsonValue() const;

        /**
         * @fn  void Value::SetComment(const std::string& comment);
         *
         * @brief   Adds a comment to the internal value.
         *
         * @param   comment The comment.
         */
        void SetComment(const std::string& comment);

        /**
         * @fn  bool Value::HasComment() const;
         *
         * @brief   Checks if the internal value has a comment.
         *
         * @return  True if comment, false if not.
         */
        bool HasComment() const;

        /**
         * @fn  std::string Value::GetComment() const;
         *
         * @brief   Returns the internal comment.
         *
         * @return  The comment.
         */
        std::string GetComment() const;

        /**
         * @fn  virtual void Value::Clear();
         *
         * @brief   Clears the internal JSON Root node.
         */
        virtual void Clear();

        /**
         * @fn  int Value::Size();
         *
         * @brief   Returns the size of the array.
         *
         * @return  An int.
         */
        int Size();

        /**
         * @fn  void Value::Resize(int newSize);
         *
         * @brief   Change the size of the array.
         *
         * @param   newSize Size of the new.
         */
        void Resize(int newSize);

        /**
         * @fn  bool Value::IsValidIndex(int index) const;
         *
         * @brief   Return true if index &lt; Size()
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if valid index, false if not.
         */
        bool IsValidIndex(int index) const;

        /**
         * @fn  bool Value::RemoveIndex(int index, Value *removedVal);
         *
         * @brief   Remove the given Index value.
         *
         * @param           index       Zero-based index of the values position.
         * @param [in,out]  removedVal  If non-null, the removed value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool RemoveIndex(int index, Value *removedVal);

        /**
         * @fn  Value Value::Index(int index);
         *
         * @brief   Returns the Value at the given index if this Value is an Array The return is by value,
         *          but the internal json object is stored by reference.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  A Value.
         */
        Value Index(int index);

        /**
         * @fn  const Value::Members Value::GetMemberNames() const;
         *
         * @brief   Returns the value names contained in the object.
         *
         * @return  The member names.
         */
        const Value::Members GetMemberNames() const;

        /**
         * @fn  bool Value::HasMember(const std::string& key) const;
         *
         * @brief   Returns true if a member with the passed in key is present.
         *
         * @param   key The key.
         *
         * @return  True if member, false if not.
         */
        bool HasMember(const std::string& key) const;

        /**
         * @fn  virtual bool Value::KeyPresent(const std::string &key) const;
         *
         * @brief   Checks if the JSON Root Node has an entry with a given key present.
         *
         * @param   key The key.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool KeyPresent(const std::string &key) const;

        /**
         * @fn  virtual bool Value::IsNull() const;
         *
         * @brief   Checks if the value stored is a NULL.
         *
         * @return  True if null, false if not.
         */
        virtual bool IsNull() const;

        /**
         * @fn  virtual bool Value::IsNull(const int index) const;
         *
         * @brief   Checks if the value stored is a NULL.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if null, false if not.
         */
        virtual bool IsNull(const int index) const;

        /**
         * @fn  virtual bool Value::IsNull(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a NULL.
         *
         * @param   key The key.
         *
         * @return  True if null, false if not.
         */
        virtual bool IsNull(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetNull(const std::string& key) const;
         *
         * @brief   Sets the NULL value in the Object.
         *
         * @param   key The key.
         */
        virtual void SetNull(const std::string& key) const;

        /**
         * @fn  virtual bool Value::IsEmpty() const;
         *
         * @brief   Return true if empty array, empty object, or null, otherwise, false.
         *
         * @return  True if empty, false if not.
         */
        virtual bool IsEmpty() const;

        /**
         * @fn  virtual bool Value::IsEmpty(const int index) const;
         *
         * @brief   Return true if empty array, empty object, or null, otherwise, false.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if empty, false if not.
         */
        virtual bool IsEmpty(const int index) const;

        /**
         * @fn  virtual bool Value::IsEmpty(const std::string& key) const;
         *
         * @brief   Return true if empty array, empty object, or null, otherwise, false.
         *
         * @param   key The key.
         *
         * @return  True if empty, false if not.
         */
        virtual bool IsEmpty(const std::string& key) const;

        /**
         * @fn  virtual void Value::Append(const Value& val);
         *
         * @brief   Add a value at the end of the array.
         *
         * @param   val The Value to append.
         */
        virtual void Append(const Value& val);

        /**
         * @fn  virtual bool Value::IsBool() const;
         *
         * @brief   Checks if the value stored is a Boolean.
         *
         * @return  True if bool, false if not.
         */
        virtual bool IsBool() const;

        /**
         * @fn  virtual bool Value::IsBool(const int index) const;
         *
         * @brief   Checks if the value stored is a Boolean.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if bool, false if not.
         */
        virtual bool IsBool(const int index) const;

        /**
         * @fn  virtual bool Value::IsBool(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a Boolean.
         *
         * @param   key The key.
         *
         * @return  True if bool, false if not.
         */
        virtual bool IsBool(const std::string& key) const;

        /**
         * @fn  virtual bool Value::GetBool() const;
         *
         * @brief   Returns the Boolean value.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool GetBool() const;

        /**
         * @fn  virtual bool Value::GetBool(const int index) const;
         *
         * @brief   Returns the Boolean value.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool GetBool(const int index) const;

        /**
         * @fn  virtual bool Value::GetBool(const std::string& key) const;
         *
         * @brief   Returns the Boolean value.
         *
         * @param   key The key.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool GetBool(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetBool(const std::string& key, bool value);
         *
         * @brief   Sets the Boolean value in the Object.
         *
         * @param   key     The key.
         * @param   value   True to value.
         */
        virtual void SetBool(const std::string& key, bool value);

        /**
         * @fn  virtual bool Value::IsNumber() const;
         *
         * @brief   Checks if the value stored is a Number.
         *
         * @return  True if number, false if not.
         */
        virtual bool IsNumber() const;

        /**
         * @fn  virtual bool Value::IsNumber(const int index) const;
         *
         * @brief   Checks if the value stored is a Number.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if number, false if not.
         */
        virtual bool IsNumber(const int index) const;

        /**
         * @fn  virtual bool Value::IsNumber(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a Number.
         *
         * @param   key The key.
         *
         * @return  True if number, false if not.
         */
        virtual bool IsNumber(const std::string& key) const;

        /**
         * @fn  virtual bool Value::IsInt() const;
         *
         * @brief   Checks if the value stored is an Integer.
         *
         * @return  True if int, false if not.
         */
        virtual bool IsInt() const;

        /**
         * @fn  virtual bool Value::IsInt(const int index) const;
         *
         * @brief   Checks if the value stored is an Integer.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if int, false if not.
         */
        virtual bool IsInt(const int index) const;

        /**
         * @fn  virtual bool Value::IsInt(const std::string& key) const;
         *
         * @brief   Checks if the value stored is an Integer.
         *
         * @param   key The key.
         *
         * @return  True if int, false if not.
         */
        virtual bool IsInt(const std::string& key) const;

        /**
         * @fn  virtual int Value::GetInt() const;
         *
         * @brief   Returns the Integer value.
         *
         * @return  The int.
         */
        virtual int GetInt() const;

        /**
         * @fn  virtual int Value::GetInt(const int index) const;
         *
         * @brief   Returns the Integer value.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The int.
         */
        virtual int GetInt(const int index) const;

        /**
         * @fn  virtual int Value::GetInt(const std::string& key) const;
         *
         * @brief   Returns the Integer value.
         *
         * @param   key The key.
         *
         * @return  The int.
         */
        virtual int GetInt(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetInt(const std::string& key, int value);
         *
         * @brief   Sets the Integer value in the Object.
         *
         * @param   key     The key.
         * @param   value   The value.
         */
        virtual void SetInt(const std::string& key, int value);

        /**
         * @fn  virtual bool Value::IsDouble() const;
         *
         * @brief   Checks if the value stored is a Double.
         *
         * @return  True if double, false if not.
         */
        virtual bool IsDouble() const;

        /**
         * @fn  virtual bool Value::IsDouble(const int index) const;
         *
         * @brief   Checks if the value stored is a Double.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if double, false if not.
         */
        virtual bool IsDouble(const int index) const;

        /**
         * @fn  virtual bool Value::IsDouble(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a Double.
         *
         * @param   key The key.
         *
         * @return  True if double, false if not.
         */
        virtual bool IsDouble(const std::string& key) const;

        /**
         * @fn  virtual double Value::GetDouble() const;
         *
         * @brief   Returns the Double value.
         *
         * @return  The double.
         */
        virtual double GetDouble() const;

        /**
         * @fn  virtual double Value::GetDouble(const int index) const;
         *
         * @brief   Returns the Double value.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The double.
         */
        virtual double GetDouble(const int index) const;

        /**
         * @fn  virtual double Value::GetDouble(const std::string& key) const;
         *
         * @brief   Returns the Double value.
         *
         * @param   key The key.
         *
         * @return  The double.
         */
        virtual double GetDouble(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetDouble(const std::string& key, double value);
         *
         * @brief   Sets the Double value in the Object.
         *
         * @param   key     The key.
         * @param   value   The value.
         */
        virtual void SetDouble(const std::string& key, double value);

        /**
         * @fn  virtual bool Value::IsUInt() const;
         *
         * @brief   Checks if the value stored Unsigned Integer.
         *
         * @return  True if u int, false if not.
         */
        virtual bool IsUInt() const;

        /**
         * @fn  virtual bool Value::IsUInt(const int index) const;
         *
         * @brief   Checks if the value stored Unsigned Integer.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if u int, false if not.
         */
        virtual bool IsUInt(const int index) const;

        /**
         * @fn  virtual bool Value::IsUInt(const std::string& key) const;
         *
         * @brief   Checks if the value stored Unsigned Integer.
         *
         * @param   key The key.
         *
         * @return  True if u int, false if not.
         */
        virtual bool IsUInt(const std::string& key) const;

        /**
         * @fn  virtual unsigned int Value::GetUInt() const;
         *
         * @brief   Returns the Unsigned Integer value.
         *
         * @return  The u int.
         */
        virtual unsigned int GetUInt() const;

        /**
         * @fn  virtual unsigned int Value::GetUInt(const int index) const;
         *
         * @brief   Returns the Unsigned Integer value.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The u int.
         */
        virtual unsigned int GetUInt(const int index) const;

        /**
         * @fn  virtual unsigned int Value::GetUInt(const std::string& key) const;
         *
         * @brief   Returns the Unsigned Integer value.
         *
         * @param   key The key.
         *
         * @return  The u int.
         */
        virtual unsigned int GetUInt(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetUInt(const std::string& key, unsigned int value);
         *
         * @brief   Sets the Unsigned Int value in the Object.
         *
         * @param   key     The key.
         * @param   value   The value.
         */
        virtual void SetUInt(const std::string& key, unsigned int value);

        /**
         * @fn  virtual bool Value::IsInt64() const;
         *
         * @brief   Checks if the value stored is a 64bit Integer.
         *
         * @return  True if int 64, false if not.
         */
        virtual bool IsInt64() const;

        /**
         * @fn  virtual bool Value::IsInt64(const int index) const;
         *
         * @brief   Checks if the value stored is a 64bit Integer.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if int 64, false if not.
         */
        virtual bool IsInt64(const int index) const;

        /**
         * @fn  virtual bool Value::IsInt64(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a 64bit Integer.
         *
         * @param   key The key.
         *
         * @return  True if int 64, false if not.
         */
        virtual bool IsInt64(const std::string& key) const;

        /**
         * @fn  virtual Int64 Value::GetInt64() const;
         *
         * @brief   Returns the 64bit Integer value.
         *
         * @return  The int 64.
         */
        virtual Int64 GetInt64() const;

        /**
         * @fn  virtual Int64 Value::GetInt64(const int index) const;
         *
         * @brief   Returns the 64bit Integer value.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The int 64.
         */
        virtual Int64 GetInt64(const int index) const;

        /**
         * @fn  virtual Int64 Value::GetInt64(const std::string& key) const;
         *
         * @brief   Returns the 64bit Integer value.
         *
         * @param   key The key.
         *
         * @return  The int 64.
         */
        virtual Int64 GetInt64(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetInt64(const std::string& key, Int64 value);
         *
         * @brief   Sets the Int64 value in the Object.
         *
         * @param   key     The key.
         * @param   value   The value.
         */
        virtual void SetInt64(const std::string& key, Int64 value);

        /**
         * @fn  virtual bool Value::IsUInt64() const;
         *
         * @brief   Checks if the value stored is a 64bit Unsigned Integer.
         *
         * @return  True if u int 64, false if not.
         */
        virtual bool IsUInt64() const;

        /**
         * @fn  virtual bool Value::IsUInt64(const int index) const;
         *
         * @brief   Checks if the value stored is a 64bit Unsigned Integer.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if u int 64, false if not.
         */
        virtual bool IsUInt64(const int index) const;

        /**
         * @fn  virtual bool Value::IsUInt64(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a 64bit Unsigned Integer.
         *
         * @param   key The key.
         *
         * @return  True if u int 64, false if not.
         */
        virtual bool IsUInt64(const std::string& key) const;

        /**
         * @fn  virtual UInt64 Value::GetUInt64() const;
         *
         * @brief   Returns the Unsigned 64bit Integer value.
         *
         * @return  The u int 64.
         */
        virtual UInt64 GetUInt64() const;

        /**
         * @fn  virtual UInt64 Value::GetUInt64(const int index) const;
         *
         * @brief   Returns the Unsigned 64bit Integer value.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The u int 64.
         */
        virtual UInt64 GetUInt64(const int index) const;

        /**
         * @fn  virtual UInt64 Value::GetUInt64(const std::string& key) const;
         *
         * @brief   Returns the Unsigned 64bit Integer value.
         *
         * @param   key The key.
         *
         * @return  The u int 64.
         */
        virtual UInt64 GetUInt64(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetUInt64(const std::string& key, UInt64 value);
         *
         * @brief   Sets the Unsigned Int64 value in the Object.
         *
         * @param   key     The key.
         * @param   value   The value.
         */
        virtual void SetUInt64(const std::string& key, UInt64 value);

        /**
         * @fn  virtual bool Value::IsFloat() const;
         *
         * @brief   Checks if the value stored is a float.
         *
         * @return  True if float, false if not.
         */
        virtual bool IsFloat() const;

        /**
         * @fn  virtual bool Value::IsFloat(const int index) const;
         *
         * @brief   Checks if the value stored is a float.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if float, false if not.
         */
        virtual bool IsFloat(const int index) const;

        /**
         * @fn  virtual bool Value::IsFloat(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a float.
         *
         * @param   key The key.
         *
         * @return  True if float, false if not.
         */
        virtual bool IsFloat(const std::string& key) const;

        /**
         * @fn  virtual float Value::GetFloat() const;
         *
         * @brief   Returns the float value stored.
         *
         * @return  The float.
         */
        virtual float GetFloat() const;

        /**
         * @fn  virtual float Value::GetFloat(const int index) const;
         *
         * @brief   Returns the float value stored.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The float.
         */
        virtual float GetFloat(const int index) const;

        /**
         * @fn  virtual float Value::GetFloat(const std::string& key) const;
         *
         * @brief   Returns the float value stored.
         *
         * @param   key The key.
         *
         * @return  The float.
         */
        virtual float GetFloat(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetFloat(const std::string& key, float value);
         *
         * @brief   Sets the Float value in the Object.
         *
         * @param   key     The key.
         * @param   value   The value.
         */
        virtual void SetFloat(const std::string& key, float value);

        /**
         * @fn  virtual bool Value::IsString() const;
         *
         * @brief   Checks if the value stored is a String.
         *
         * @return  True if string, false if not.
         */
        virtual bool IsString() const;

        /**
         * @fn  virtual bool Value::IsString(const int index) const;
         *
         * @brief   Checks if the value stored is a String.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if string, false if not.
         */
        virtual bool IsString(const int index) const;

        /**
         * @fn  virtual bool Value::IsString(const std::string& key) const;
         *
         * @brief   Checks if the value stored is a String.
         *
         * @param   key The key.
         *
         * @return  True if string, false if not.
         */
        virtual bool IsString(const std::string& key) const;

        /**
         * @fn  virtual const std::string Value::GetString() const;
         *
         * @brief   Returns the String value stored.
         *
         * @return  The string.
         */
        virtual const std::string GetString() const;

        /**
         * @fn  virtual const std::string Value::GetString(const int index) const;
         *
         * @brief   Returns the String value stored.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The string.
         */
        virtual const std::string GetString(const int index) const;

        /**
         * @fn  virtual const std::string Value::GetString(const std::string& key) const;
         *
         * @brief   Returns the String value stored.
         *
         * @param   key The key.
         *
         * @return  The string.
         */
        virtual const std::string GetString(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetString(const std::string& key, const std::string& value);
         *
         * @brief   Sets the String value in the Object.
         *
         * @param   key     The key.
         * @param   value   The value.
         */
        virtual void SetString(const std::string& key, const std::string& value);

        /**
         * @fn  virtual bool Value::IsArray() const;
         *
         * @brief   Checks if the value stored is an Array.
         *
         * @return  True if array, false if not.
         */
        virtual bool IsArray() const;

        /**
         * @fn  virtual bool Value::IsArray(const int index) const;
         *
         * @brief   Checks if the value stored is an Array.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if array, false if not.
         */
        virtual bool IsArray(const int index) const;

        /**
         * @fn  virtual bool Value::IsArray(const std::string& key) const;
         *
         * @brief   Checks if the value stored is an Array.
         *
         * @param   key The key.
         *
         * @return  True if array, false if not.
         */
        virtual bool IsArray(const std::string& key) const;

        /**
         * @fn  virtual const Array Value::GetArray() const;
         *
         * @brief   Returns the Array value stored.
         *
         * @return  The array.
         */
        virtual const Array GetArray() const;

        /**
         * @fn  virtual const Array Value::GetArray(const int index) const;
         *
         * @brief   Returns the Array value stored.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The array.
         */
        virtual const Array GetArray(const int index) const;

        /**
         * @fn  virtual const Array Value::GetArray(const std::string& key) const;
         *
         * @brief   Returns the Array value stored.
         *
         * @param   key The key.
         *
         * @return  The array.
         */
        virtual const Array GetArray(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetArray(const std::string& key, Array& value);
         *
         * @brief   Sets the Array value in the Object.
         *
         * @param           key     The key.
         * @param [in,out]  value   The value.
         */
        virtual void SetArray(const std::string& key, Array& value);

        /**
         * @fn  virtual bool Value::IsObject() const;
         *
         * @brief   Checks if the value stored is an Object.
         *
         * @return  True if object, false if not.
         */
        virtual bool IsObject() const;

        /**
         * @fn  virtual bool Value::IsObject(const int index) const;
         *
         * @brief   Checks if the value stored is an Object.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  True if object, false if not.
         */
        virtual bool IsObject(const int index) const;

        /**
         * @fn  virtual bool Value::IsObject(const std::string& key) const;
         *
         * @brief   Checks if the value stored is an Object.
         *
         * @param   key The key.
         *
         * @return  True if object, false if not.
         */
        virtual bool IsObject(const std::string& key) const;

        /**
         * @fn  virtual const Object Value::GetObject() const;
         *
         * @brief   Returns the Object value stored.
         *
         * @return  The object.
         */
        virtual const Object GetObject() const;

        /**
         * @fn  virtual const Object Value::GetObject(const int index) const;
         *
         * @brief   Returns the Object value stored.
         *
         * @param   index   Zero-based index of the values position.
         *
         * @return  The object.
         */
        virtual const Object GetObject(const int index) const;

        /**
         * @fn  virtual const Object Value::GetObject(const std::string& key) const;
         *
         * @brief   Returns the Object value stored.
         *
         * @param   key The key.
         *
         * @return  The object.
         */
        virtual const Object GetObject(const std::string& key) const;

        /**
         * @fn  virtual void Value::SetObject(const std::string& key, Object& value);
         *
         * @brief   Sets the Object value in the Object.
         *
         * @param           key     The key.
         * @param [in,out]  value   The value.
         */
        virtual void SetObject(const std::string& key, Object& value);
        
        /**
         * @fn  operator Json::Value() const;
         *
         * @brief   Implicit conversion operator to Json::Value.
         *
         * @return  The result of the operation.
         */
        operator Json::Value() const;

        /**
         * @fn  operator Json::Value& ();
         *
         * @brief   Implicit conversion operator to Json::Value.
         *
         * @return  The result of the operation.
         */
        operator Json::Value& ();

        /**
         * @fn  operator const Json::Value& () const;
         *
         * @brief   Implicit conversion operator to Json::Value.
         *
         * @return  A const.
         */
        operator const Json::Value& () const;

        /**
         * @fn  operator Json::Value* ();
         *
         * @brief   Implicit conversion operator to Json::Value.
         *
         * @return  The result of the operation.
         */
        operator Json::Value* ();

        ///// Access an array element (zero based index ).
        ///// If the array contains less than index element, then null value are
        ///// inserted
        ///// in the array so that its size is index+1.
        ///// (You may need to say 'value[0u]' to get your compiler to distinguish
        /////  this from the operator[] which takes a string.)
        //Value operator[](int index);

        ///// Access an array element (zero based index )
        ///// (You may need to say 'value[0u]' to get your compiler to distinguish
        /////  this from the operator[] which takes a string.)
        //const Value operator[](int index) const;

        ///// Access an object value by name, create a null member if it does not exist.
        ///// \note Because of our implementation, keys are limited to 2^30 -1 chars.
        /////  Exceeding that will cause an exception.
        //Value operator[](const char* key);

        ///// Access an object value by name, returns null if there is no member with
        ///// that name.
        //const Value operator[](const char* key) const;

        ///// Access an object value by name, create a null member if it does not exist.
        ///// \param key may contain embedded nulls.
        //Value operator[](const std::string& key);

        /**
         * @fn  Value& Value::operator=(Value other);
         *
         * @brief   // Access an object value by name, returns null if there is no member with // that
         *          name. //\param key may contain embedded nulls. //const Value operator[](const
         *          std::string&amp; key)
         *          const;
         *
         * @param   other   The other.
         *
         * @return  A shallow copy of this object.
         */
        Value& operator=(Value other);

    protected:

        /** @brief   True to clear internal value. */
        bool clearInternalVal = true;
        /** @brief   The value pointer. */
        Json::Value* mValuePtr = nullptr;
    };

    /**
     * @fn  TR_UTIL_EXPORT std::ostream& operator<<(std::ostream&, const Value& root);
     *
     * @brief   OStream operator.
     *          
     * @author Maxim Serebrennik
     *
     * @param [in,out]  parameter1  The first parameter.
     * @param           root        The root.
     *
     * @return  The shifted result.
     */
    TR_UTIL_EXPORT std::ostream& operator<<(std::ostream&, const Value& root);
}