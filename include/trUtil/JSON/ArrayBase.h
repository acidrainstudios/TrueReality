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
        * @class   ArrayBase
        *
        * @brief   An array base.
        *          
        * @author Maxim Serebrennik
        */
    class TR_UTIL_EXPORT ArrayBase : osg::Referenced
    {

    public:

        /**
            * @fn  virtual void ArrayBase::Clear() = 0;
            *
            * @brief   Clears the internal JSON Root node.
            */
        virtual void Clear() = 0;

        /**
            * @fn  virtual Value& ArrayBase::GetJSONRoot() = 0;
            *
            * @brief   Returns a reference to the internal JSON Root node.
            *
            * @return  The JSON root.
            */
        virtual Value& GetJSONRoot() = 0;

        /**
            * @fn  virtual void ArrayBase::PrintJSONRoot() = 0;
            *
            * @brief   Prints out to the screen the whole JSON Root content.
            */
        virtual void PrintJSONRoot() = 0;

        /**
            * @fn  virtual bool ArrayBase::IsNull(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a NULL.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if null, false if not.
            */
        virtual bool IsNull(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddNull() = 0;
            *
            * @brief   Add a NULL Value to the Array.
            */
        virtual void AddNull() = 0;

        /**
            * @fn  virtual bool ArrayBase::IsBool(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a Boolean.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if bool, false if not.
            */
        virtual bool IsBool(int &index) const = 0;

        /**
            * @fn  virtual bool ArrayBase::GetBool(int &index) const = 0;
            *
            * @brief   Returns the Boolean value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool GetBool(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddBool(const bool &value) = 0;
            *
            * @brief   Adds a Boolean to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddBool(const bool &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsTrue(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is True.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if true, false if not.
            */
        virtual bool IsTrue(int &index) const = 0;

        /**
            * @fn  virtual bool ArrayBase::IsFalse(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is False.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if false, false if not.
            */
        virtual bool IsFalse(int &index) const = 0;

        /**
            * @fn  virtual bool ArrayBase::IsNumber(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a Number.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if number, false if not.
            */
        virtual bool IsNumber(int &index) const = 0;

        /**
            * @fn  virtual bool ArrayBase::IsInt(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is an Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if int, false if not.
            */
        virtual bool IsInt(int &index) const = 0;

        /**
            * @fn  virtual int ArrayBase::GetInt(int &index) const = 0;
            *
            * @brief   Returns the Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The int.
            */
        virtual int GetInt(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddInt(const int &value) = 0;
            *
            * @brief   Adds the Integer value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddInt(const int &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsDouble(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a Double.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if double, false if not.
            */
        virtual bool IsDouble(int &index) const = 0;

        /**
            * @fn  virtual double ArrayBase::GetDouble(int &index) const = 0;
            *
            * @brief   Returns the Double value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The double.
            */
        virtual double GetDouble(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddDouble(const double &value) = 0;
            *
            * @brief   Adds the Double value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddDouble(const double &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsUInt(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is an Unsigned Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if u int, false if not.
            */
        virtual bool IsUInt(int &index) const = 0;

        /**
            * @fn  virtual unsigned int ArrayBase::GetUInt(int &index) const = 0;
            *
            * @brief   Returns the Unsigned Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The u int.
            */
        virtual unsigned int GetUInt(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddUInt(const unsigned int &value) = 0;
            *
            * @brief   Adds the Unsigned Integer value the Array.
            *
            * @param   value   The value.
            */
        virtual void AddUInt(const unsigned int &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsInt64(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a 64bit Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if int 64, false if not.
            */
        virtual bool IsInt64(int &index) const = 0;

        /**
            * @fn  virtual Int64 ArrayBase::GetInt64(int &index) const = 0;
            *
            * @brief   Returns the 64bit Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The int 64.
            */
        virtual Int64 GetInt64(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddInt64(const Int64 &value) = 0;
            *
            * @brief   Adds the 64bit Integer value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddInt64(const Int64 &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsUInt64(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a 64bit Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if u int 64, false if not.
            */
        virtual bool IsUInt64(int &index) const = 0;

        /**
            * @fn  virtual UInt64 ArrayBase::GetUInt64(int &index) const = 0;
            *
            * @brief   Returns the 64bit Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The u int 64.
            */
        virtual UInt64 GetUInt64(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddUInt64(const UInt64 &value) = 0;
            *
            * @brief   Adds the 64bit Integer value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddUInt64(const UInt64 &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsFloat(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a float.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if float, false if not.
            */
        virtual bool IsFloat(int &index) const = 0;

        /**
            * @fn  virtual float ArrayBase::GetFloat(int &index) const = 0;
            *
            * @brief   Returns the float value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The float.
            */
        virtual float GetFloat(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddFloat(const float &value) = 0;
            *
            * @brief   Adds the float value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddFloat(const float &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsString(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is a String.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if string, false if not.
            */
        virtual bool IsString(int &index) const = 0;

        /**
            * @fn  virtual const std::string ArrayBase::GetString(int &index) const = 0;
            *
            * @brief   Returns the String value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The string.
            */
        virtual const std::string GetString(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddString(const std::string &value) = 0;
            *
            * @brief   Adds the String to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddString(const std::string &value) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsArray(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is an Array.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if array, false if not.
            */
        virtual bool IsArray(int &index) const = 0;

        /**
            * @fn  virtual Array ArrayBase::GetArray(int &index) const = 0;
            *
            * @brief   Returns the Array value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The array.
            */
        virtual Array GetArray(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddArray(Array &Array) = 0;
            *
            * @brief   Adds the Array to the Array.
            *
            * @param [in,out]  Array   The array.
            */
        virtual void AddArray(Array &Array) = 0;

        /**
            * @fn  virtual bool ArrayBase::IsObject(int &index) const = 0;
            *
            * @brief   Checks if the value stored at the specific index is an Object.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if object, false if not.
            */
        virtual bool IsObject(int &index) const = 0;

        /**
            * @fn  virtual Object ArrayBase::GetObject(int &index) const = 0;
            *
            * @brief   Returns the Object value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The object.
            */
        virtual Object GetObject(int &index) const = 0;

        /**
            * @fn  virtual void ArrayBase::AddObject(Object &Object) = 0;
            *
            * @brief   Adds the Object to the Array.
            *
            * @param [in,out]  Object  The object.
            */
        virtual void AddObject(Object &Object) = 0;
    };
}