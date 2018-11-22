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

#include <trUtil/JSON/Base.h>
#include <trUtil/JSON/Value.h>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::JSON
{
    /**
        * @class   Object
        *
        * @brief   A JSON object that is used to store 
        *          
        * @author Maxim Serebrennik
        */
    class TR_UTIL_EXPORT Object : Base
    {
    public:

        /**
            * @fn  Object::Object();
            *
            * @brief   ctor.
            */
        Object();

        /**
            * @fn  Object::Object(const Value &Object);
            *
            * @brief   ctor that takes a JSON Value of Object type as input.
            *
            * @param   Object  The object.
            */
        Object(const Value &Object);

        /**
            * @fn  Object::~Object();
            *
            * @brief   dtor.
            */
        ~Object();

        /**
            * @fn  const Value::Members Object::GetMemberNames() const;
            *
            * @brief   Returns the value names contained in the object.
            *
            * @return  The member names.
            */
        const Value::Members GetMemberNames() const;

        /*
        * Adds a comment to the internal value
        */

        /**
            * @fn  void Object::SetComment(const std::string& comment);
            *
            * @brief   Sets a comment.
            *
            * @param   comment The comment.
            */
        void SetComment(const std::string& comment);

        /**
            * @fn  bool Object::HasComment() const;
            *
            * @brief   Checks if the internal value has a comment.
            *
            * @return  True if comment, false if not.
            */
        bool HasComment() const;

        /**
            * @fn  std::string Object::GetComment() const;
            *
            * @brief   Returns the internal comment.
            *
            * @return  The comment.
            */
        std::string GetComment() const;

        /**
            * @fn  void Object::Clear() override;
            *
            * @brief   Clears the internal JSON Root node.
            */
        void Clear() override;

        /**
            * @fn  virtual Value& Object::GetJSONRoot() override;
            *
            * @brief   Returns a reference to the internal JSON Root node.
            *
            * @return  The JSON root.
            */
        virtual Value& GetJSONRoot() override;

        /**
            * @fn  virtual void Object::PrintJSONRoot() override;
            *
            * @brief   Prints out to the screen the whole JSON Root content.
            */
        virtual void PrintJSONRoot() override;

        /**
            * @fn  virtual bool Object::KeyPresent(const std::string &key) const override;
            *
            * @brief   Checks if the JSON Root Node has an entry with a given key present.
            *
            * @param   key The key.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool KeyPresent(const std::string &key) const override;

        /**
            * @fn  virtual bool Object::IsNull(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a NULL.
            *
            * @param   key The key.
            *
            * @return  True if null, false if not.
            */
        virtual bool IsNull(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetNull(const std::string &key) override;
            *
            * @brief   Sets the value stored at the specific key to NULL.
            *
            * @param   key The key.
            */
        virtual void SetNull(const std::string &key) override;

        /**
            * @fn  virtual bool Object::IsBool(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a Boolean.
            *
            * @param   key The key.
            *
            * @return  True if bool, false if not.
            */
        virtual bool IsBool(const std::string &key) const override;

        /**
            * @fn  virtual bool Object::GetBool(const std::string &key) const override;
            *
            * @brief   Returns the Boolean value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool GetBool(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetBool(const std::string &key, const bool &value) override;
            *
            * @brief   Sets the Boolean value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetBool(const std::string &key, const bool &value) override;

        /**
            * @fn  virtual bool Object::IsTrue(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is True.
            *
            * @param   key The key.
            *
            * @return  True if true, false if not.
            */
        virtual bool IsTrue(const std::string &key) const override;

        /**
            * @fn  virtual bool Object::IsFalse(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is False.
            *
            * @param   key The key.
            *
            * @return  True if false, false if not.
            */
        virtual bool IsFalse(const std::string &key) const override;

        /**
            * @fn  virtual bool Object::IsNumber(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a Number.
            *
            * @param   key The key.
            *
            * @return  True if number, false if not.
            */
        virtual bool IsNumber(const std::string &key) const override;

        /**
            * @fn  virtual bool Object::IsInt(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Integer.
            *
            * @param   key The key.
            *
            * @return  True if int, false if not.
            */
        virtual bool IsInt(const std::string &key) const override;

        /**
            * @fn  virtual int Object::GetInt(const std::string &key) const override;
            *
            * @brief   Returns the Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The int.
            */
        virtual int GetInt(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetInt(const std::string &key, const int &value) override;
            *
            * @brief   Sets the Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetInt(const std::string &key, const int &value) override;

        /**
            * @fn  virtual bool Object::IsDouble(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a Double.
            *
            * @param   key The key.
            *
            * @return  True if double, false if not.
            */
        virtual bool IsDouble(const std::string &key) const override;

        /**
            * @fn  virtual double Object::GetDouble(const std::string &key) const override;
            *
            * @brief   Returns the Double value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The double.
            */
        virtual double GetDouble(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetDouble(const std::string &key, const double &value) override;
            *
            * @brief   Sets the Double value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetDouble(const std::string &key, const double &value) override;

        /**
            * @fn  virtual bool Object::IsUInt(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Unsigned Integer.
            *
            * @param   key The key.
            *
            * @return  True if u int, false if not.
            */
        virtual bool IsUInt(const std::string &key) const override;

        /**
            * @fn  virtual unsigned int Object::GetUInt(const std::string &key) const override;
            *
            * @brief   Returns the Unsigned Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The u int.
            */
        virtual unsigned int GetUInt(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetUInt(const std::string &key, const unsigned int &value) override;
            *
            * @brief   Sets the Unsigned Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetUInt(const std::string &key, const unsigned int &value) override;

        /**
            * @fn  virtual bool Object::IsInt64(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a 64bit Integer.
            *
            * @param   key The key.
            *
            * @return  True if int 64, false if not.
            */
        virtual bool IsInt64(const std::string &key) const override;

        /**
            * @fn  virtual Int64 Object::GetInt64(const std::string &key) const override;
            *
            * @brief   Returns the 64bit Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The int 64.
            */
        virtual Int64 GetInt64(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetInt64(const std::string &key, const Int64 &value) override;
            *
            * @brief   Sets the 64bit Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetInt64(const std::string &key, const Int64 &value) override;

        /**
            * @fn  virtual bool Object::IsUInt64(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a 64bit Integer.
            *
            * @param   key The key.
            *
            * @return  True if u int 64, false if not.
            */
        virtual bool IsUInt64(const std::string &key) const override;

        /**
            * @fn  virtual UInt64 Object::GetUInt64(const std::string &key) const override;
            *
            * @brief   Returns the 64bit Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The u int 64.
            */
        virtual UInt64 GetUInt64(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetUInt64(const std::string &key, const UInt64 &value) override;
            *
            * @brief   Sets the 64bit Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetUInt64(const std::string &key, const UInt64 &value) override;

        /**
            * @fn  virtual bool Object::IsFloat(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a float.
            *
            * @param   key The key.
            *
            * @return  True if float, false if not.
            */
        virtual bool IsFloat(const std::string &key) const override;

        /**
            * @fn  virtual float Object::GetFloat(const std::string &key) const override;
            *
            * @brief   Returns the float value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The float.
            */
        virtual float GetFloat(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetFloat(const std::string &key, const float &value) override;
            *
            * @brief   Sets the float value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetFloat(const std::string &key, const float &value) override;

        /**
            * @fn  virtual bool Object::IsString(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a String.
            *
            * @param   key The key.
            *
            * @return  True if string, false if not.
            */
        virtual bool IsString(const std::string &key) const override;

        /**
            * @fn  virtual const std::string Object::GetString(const std::string &key) const override;
            *
            * @brief   Returns the String value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The string.
            */
        virtual const std::string GetString(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetString(const std::string &key, const std::string &value) override;
            *
            * @brief   Sets the String to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetString(const std::string &key, const std::string &value) override;

        /**
            * @fn  virtual bool Object::IsArray(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Array.
            *
            * @param   key The key.
            *
            * @return  True if array, false if not.
            */
        virtual bool IsArray(const std::string &key) const override;

        /**
            * @fn  virtual Array Object::GetArray(const std::string &key) const override;
            *
            * @brief   Returns the Array value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The array.
            */
        virtual Array GetArray(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetArray(const std::string &key, Array &value) override;
            *
            * @brief   Sets the Array to be stored at the given key.
            *
            * @param           key     The key.
            * @param [in,out]  value   The value.
            */
        virtual void SetArray(const std::string &key, Array &value) override;

        /**
            * @fn  virtual bool Object::IsObject(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Object.
            *
            * @param   key The key.
            *
            * @return  True if object, false if not.
            */
        virtual bool IsObject(const std::string &key) const override;

        /**
            * @fn  virtual Object Object::GetObject(const std::string &key) const override;
            *
            * @brief   Returns the Object value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The object.
            */
        virtual Object GetObject(const std::string &key) const override;

        /**
            * @fn  virtual void Object::SetObject(const std::string &key, Object &value) override;
            *
            * @brief   Sets the Array to be stored at the given key.
            *
            * @param           key     The key.
            * @param [in,out]  value   The value.
            */
        virtual void SetObject(const std::string &key, Object &value) override;

    private:
        /** @brief   The root. */
        Value mRoot = Value(ValueType::ObjectValue);
    };
}