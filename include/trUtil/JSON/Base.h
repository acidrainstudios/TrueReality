/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2021 Acid Rain Studios LLC
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

#include <trUtil/JSON/Value.h>

#include <osg/Referenced>

#include <stdint.h>
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
        * @brief   Forward declaration.
        */
    class Object;

    /**
        * @class   Array
        *
        * @brief   An array.
        */
    class Array;

    /**
        * @class   Base
        *
        * @brief   The Base class for all the JSON classes
        *
        * @author Maxim Serebrennik
        */
    class TR_UTIL_EXPORT Base : osg::Referenced
    {

    public:

        /**
            * @fn  virtual void Base::Clear() = 0;
            *
            * @brief   Clears the internal JSON Root node.
            */
        virtual void Clear() = 0;

        /**
            * @fn  virtual Value& Base::GetJSONRoot() = 0;
            *
            * @brief   Returns a reference to the internal JSON Root node.
            *
            * @return  The JSON root.
            */
        virtual Value& GetJSONRoot() = 0;

        /**
            * @fn  virtual void Base::PrintJSONRoot() = 0;
            *
            * @brief   Prints out to the screen the whole JSON Root content.
            */
        virtual void PrintJSONRoot() = 0;

        /**
            * @fn  virtual bool Base::KeyPresent(const std::string &key) const = 0;
            *
            * @brief   Checks if the JSON Root Node has an entry with a given key present.
            *
            * @param   key The key.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool KeyPresent(const std::string &key) const = 0;

        /**
            * @fn  virtual bool Base::IsNull(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a NULL.
            *
            * @param   key The key.
            *
            * @return  True if null, false if not.
            */
        virtual bool IsNull(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetNull(const std::string &key) = 0;
            *
            * @brief   Sets the value stored at the specific key to NULL.
            *
            * @param   key The key.
            */
        virtual void SetNull(const std::string &key) = 0;

        /**
            * @fn  virtual bool Base::IsBool(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a Boolean.
            *
            * @param   key The key.
            *
            * @return  True if bool, false if not.
            */
        virtual bool IsBool(const std::string &key) const = 0;

        /**
            * @fn  virtual bool Base::GetBool(const std::string &key) const = 0;
            *
            * @brief   Returns the Boolean value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool GetBool(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetBool(const std::string &key, const bool &value) = 0;
            *
            * @brief   Sets the Boolean value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetBool(const std::string &key, const bool &value) = 0;

        /**
            * @fn  virtual bool Base::IsTrue(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is True.
            *
            * @param   key The key.
            *
            * @return  True if true, false if not.
            */
        virtual bool IsTrue(const std::string &key) const = 0;

        /**
            * @fn  virtual bool Base::IsFalse(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is False.
            *
            * @param   key The key.
            *
            * @return  True if false, false if not.
            */
        virtual bool IsFalse(const std::string &key) const = 0;

        /**
            * @fn  virtual bool Base::IsNumber(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a Number.
            *
            * @param   key The key.
            *
            * @return  True if number, false if not.
            */
        virtual bool IsNumber(const std::string &key) const = 0;

        /**
            * @fn  virtual bool Base::IsInt(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is an Integer.
            *
            * @param   key The key.
            *
            * @return  True if int, false if not.
            */
        virtual bool IsInt(const std::string &key) const = 0;

        /**
            * @fn  virtual int Base::GetInt(const std::string &key) const = 0;
            *
            * @brief   Returns the Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The int.
            */
        virtual int GetInt(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetInt(const std::string &key, const int &value) = 0;
            *
            * @brief   Sets the Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetInt(const std::string &key, const int &value) = 0;

        /**
            * @fn  virtual bool Base::IsDouble(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a Double.
            *
            * @param   key The key.
            *
            * @return  True if double, false if not.
            */
        virtual bool IsDouble(const std::string &key) const = 0;

        /**
            * @fn  virtual double Base::GetDouble(const std::string &key) const = 0;
            *
            * @brief   Returns the Double value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The double.
            */
        virtual double GetDouble(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetDouble(const std::string &key, const double &value) = 0;
            *
            * @brief   Sets the Double value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetDouble(const std::string &key, const double &value) = 0;

        /**
            * @fn  virtual bool Base::IsUInt(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is an Unsigned Integer.
            *
            * @param   key The key.
            *
            * @return  True if u int, false if not.
            */
        virtual bool IsUInt(const std::string &key) const = 0;

        /**
            * @fn  virtual unsigned int Base::GetUInt(const std::string &key) const = 0;
            *
            * @brief   Returns the Unsigned Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The u int.
            */
        virtual unsigned int GetUInt(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetUInt(const std::string &key, const unsigned int &value) = 0;
            *
            * @brief   Sets the Unsigned Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetUInt(const std::string &key, const unsigned int &value) = 0;

        /**
            * @fn  virtual bool Base::IsInt64(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a 64bit Integer.
            *
            * @param   key The key.
            *
            * @return  True if int 64, false if not.
            */
        virtual bool IsInt64(const std::string &key) const = 0;

        /**
            * @fn  virtual Int64 Base::GetInt64(const std::string &key) const = 0;
            *
            * @brief   Returns the 64bit Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The int 64.
            */
        virtual Int64 GetInt64(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetInt64(const std::string &key, const Int64 &value) = 0;
            *
            * @brief   Sets the 64bit Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetInt64(const std::string &key, const Int64 &value) = 0;

        /**
            * @fn  virtual bool Base::IsUInt64(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a 64bit Integer.
            *
            * @param   key The key.
            *
            * @return  True if u int 64, false if not.
            */
        virtual bool IsUInt64(const std::string &key) const = 0;

        /**
            * @fn  virtual UInt64 Base::GetUInt64(const std::string &key) const = 0;
            *
            * @brief   Returns the 64bit Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The u int 64.
            */
        virtual UInt64 GetUInt64(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetUInt64(const std::string &key, const UInt64 &value) = 0;
            *
            * @brief   Sets the 64bit Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetUInt64(const std::string &key, const UInt64 &value) = 0;

        /**
            * @fn  virtual bool Base::IsFloat(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a float.
            *
            * @param   key The key.
            *
            * @return  True if float, false if not.
            */
        virtual bool IsFloat(const std::string &key) const = 0;

        /**
            * @fn  virtual float Base::GetFloat(const std::string &key) const = 0;
            *
            * @brief   Returns the float value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The float.
            */
        virtual float GetFloat(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetFloat(const std::string &key, const float &value) = 0;
            *
            * @brief   Sets the float value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetFloat(const std::string &key, const float &value) = 0;

        /**
            * @fn  virtual bool Base::IsString(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is a String.
            *
            * @param   key The key.
            *
            * @return  True if string, false if not.
            */
        virtual bool IsString(const std::string &key) const = 0;

        /**
            * @fn  virtual const std::string Base::GetString(const std::string &key) const = 0;
            *
            * @brief   Returns the String value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The string.
            */
        virtual const std::string GetString(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetString(const std::string &key, const std::string &value) = 0;
            *
            * @brief   Sets the String to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetString(const std::string &key, const std::string &value) = 0;

        /**
            * @fn  virtual bool Base::IsArray(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is an Array.
            *
            * @param   key The key.
            *
            * @return  True if array, false if not.
            */
        virtual bool IsArray(const std::string &key) const = 0;

        /**
            * @fn  virtual Array Base::GetArray(const std::string &key) const = 0;
            *
            * @brief   Returns the Array value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The array.
            */
        virtual Array GetArray(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetArray(const std::string &key, Array &Array) = 0;
            *
            * @brief   Sets the Array to be stored at the given key.
            *
            * @param           key     The key.
            * @param [in,out]  Array   The array.
            */
        virtual void SetArray(const std::string &key, Array &Array) = 0;

        /**
            * @fn  virtual bool Base::IsObject(const std::string &key) const = 0;
            *
            * @brief   Checks if the value stored at the specific key is an Object.
            *
            * @param   key The key.
            *
            * @return  True if object, false if not.
            */
        virtual bool IsObject(const std::string &key) const = 0;

        /**
            * @fn  virtual Object Base::GetObject(const std::string &key) const = 0;
            *
            * @brief   Returns the Object value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The object.
            */
        virtual Object GetObject(const std::string &key) const = 0;

        /**
            * @fn  virtual void Base::SetObject(const std::string &key, Object &Object) = 0;
            *
            * @brief   Sets the Array to be stored at the given key.
            *
            * @param           key     The key.
            * @param [in,out]  Object  The object.
            */
        virtual void SetObject(const std::string &key, Object &Object) = 0;
    };
}