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

#include <trUtil/JSON/ArrayBase.h>
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
        * @class   Array
        *
        * @brief   A JSON array.
        *          
        * @author Maxim Serebrennik
        */
    class TR_UTIL_EXPORT Array : ArrayBase
    {
    public:

        /**
            * @fn  Array::Array();
            *
            * @brief   ctor.
            */
        Array();

        /**
            * @fn  Array::Array(const Value &Array);
            *
            * @brief   ctor that takes a JSON Value of an Array type as input.
            *
            * @param   Array   The array.
            */
        Array(const Value &Array);

        /**
            * @fn  Array::~Array();
            *
            * @brief   dtor.
            */
        ~Array();

        /**
            * @fn  Value Array::operator[](int index);
            *
            * @brief   Access an array element (zero based index ). The return is by value, but the internal
            *          json object is stored by reference.
            *
            * @param   index   Zero-based index of the.
            *
            * @return  The indexed value.
            */
        Value operator[](int index);

        /*
        * Adds a comment to the internal value
        */

        /**
            * @fn  void Array::SetComment(const std::string& comment);
            *
            * @brief   Sets a comment.
            *
            * @param   comment The comment.
            */
        void SetComment(const std::string& comment);

        /**
            * @fn  bool Array::HasComment() const;
            *
            * @brief   Checks if the internal value has a comment.
            *
            * @return  True if comment, false if not.
            */
        bool HasComment() const;

        /**
            * @fn  std::string Array::GetComment() const;
            *
            * @brief   Returns the internal comment.
            *
            * @return  The comment.
            */
        std::string GetComment() const;

        /**
            * @fn  int Array::Size();
            *
            * @brief   Get the size of the array.
            *
            * @return  An int.
            */
        int Size();

        /**
            * @fn  void Array::Resize(int newSize);
            *
            * @brief   Change the size of the array to the new passed in size.
            *
            * @param   newSize Size of the new.
            */
        void Resize(int newSize);

        /**
            * @fn  void Array::Clear() override;
            *
            * @brief   Clears the internal JSON Root node.
            */
        void Clear() override;

        /**
            * @fn  bool Array::RemoveIndex(int index, Value *removedVal);
            *
            * @brief   Removes a given element of the array. Passes back the removed value though the
            *          pointer and sets the return to TRUE.
            *
            * @param           index       Zero-based index of the.
            * @param [in,out]  removedVal  If non-null, the removed value.
            *
            * @return  True if it succeeds, false if it fails.
            */
        bool RemoveIndex(int index, Value *removedVal);

        /**
            * @fn  virtual Value& Array::GetJSONRoot() override;
            *
            * @brief   Returns a reference to the internal JSON Root node.
            *
            * @return  The JSON root.
            */
        virtual Value& GetJSONRoot() override;

        /**
            * @fn  virtual void Array::PrintJSONRoot() override;
            *
            * @brief   Prints out to the screen the whole JSON Root content.
            */
        virtual void PrintJSONRoot() override;

        /**
            * @fn  virtual bool Array::IsNull(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a NULL.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if null, false if not.
            */
        virtual bool IsNull(int &index) const override;

        /**
            * @fn  virtual void Array::AddNull() override;
            *
            * @brief   Add a NULL Value to the Array.
            */
        virtual void AddNull() override;

        /**
            * @fn  virtual bool Array::IsBool(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a Boolean.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if bool, false if not.
            */
        virtual bool IsBool(int &index) const override;

        /**
            * @fn  virtual bool Array::GetBool(int &index) const override;
            *
            * @brief   Returns the Boolean value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool GetBool(int &index) const override;

        /**
            * @fn  virtual void Array::AddBool(const bool &value) override;
            *
            * @brief   Adds a Boolean to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddBool(const bool &value) override;

        /**
            * @fn  virtual bool Array::IsTrue(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is True.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if true, false if not.
            */
        virtual bool IsTrue(int &index) const override;

        /**
            * @fn  virtual bool Array::IsFalse(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is False.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if false, false if not.
            */
        virtual bool IsFalse(int &index) const override;

        /**
            * @fn  virtual bool Array::IsNumber(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a Number.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if number, false if not.
            */
        virtual bool IsNumber(int &index) const override;

        /**
            * @fn  virtual bool Array::IsInt(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is an Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if int, false if not.
            */
        virtual bool IsInt(int &index) const override;

        /**
            * @fn  virtual int Array::GetInt(int &index) const override;
            *
            * @brief   Returns the Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The int.
            */
        virtual int GetInt(int &index) const override;

        /**
            * @fn  virtual void Array::AddInt(const int &value) override;
            *
            * @brief   Adds the Integer value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddInt(const int &value) override;

        /**
            * @fn  virtual bool Array::IsDouble(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a Double.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if double, false if not.
            */
        virtual bool IsDouble(int &index) const override;

        /**
            * @fn  virtual double Array::GetDouble(int &index) const override;
            *
            * @brief   Returns the Double value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The double.
            */
        virtual double GetDouble(int &index) const override;

        /**
            * @fn  virtual void Array::AddDouble(const double &value) override;
            *
            * @brief   Adds the Double value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddDouble(const double &value) override;

        /**
            * @fn  virtual bool Array::IsUInt(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is an Unsigned Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if u int, false if not.
            */
        virtual bool IsUInt(int &index) const override;

        /**
            * @fn  virtual unsigned int Array::GetUInt(int &index) const override;
            *
            * @brief   Returns the Unsigned Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The u int.
            */
        virtual unsigned int GetUInt(int &index) const override;

        /**
            * @fn  virtual void Array::AddUInt(const unsigned int &value) override;
            *
            * @brief   Adds the Unsigned Integer value the Array.
            *
            * @param   value   The value.
            */
        virtual void AddUInt(const unsigned int &value) override;

        /**
            * @fn  virtual bool Array::IsInt64(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a 64bit Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if int 64, false if not.
            */
        virtual bool IsInt64(int &index) const override;

        /**
            * @fn  virtual Int64 Array::GetInt64(int &index) const override;
            *
            * @brief   Returns the 64bit Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The int 64.
            */
        virtual Int64 GetInt64(int &index) const override;

        /**
            * @fn  virtual void Array::AddInt64(const Int64 &value) override;
            *
            * @brief   Adds the 64bit Integer value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddInt64(const Int64 &value) override;

        /**
            * @fn  virtual bool Array::IsUInt64(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a 64bit Integer.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if u int 64, false if not.
            */
        virtual bool IsUInt64(int &index) const override;

        /**
            * @fn  virtual UInt64 Array::GetUInt64(int &index) const override;
            *
            * @brief   Returns the 64bit Integer value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The u int 64.
            */
        virtual UInt64 GetUInt64(int &index) const override;

        /**
            * @fn  virtual void Array::AddUInt64(const UInt64 &value) override;
            *
            * @brief   Adds the 64bit Integer value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddUInt64(const UInt64 &value) override;

        /**
            * @fn  virtual bool Array::IsFloat(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a float.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if float, false if not.
            */
        virtual bool IsFloat(int &index) const override;

        /**
            * @fn  virtual float Array::GetFloat(int &index) const override;
            *
            * @brief   Returns the float value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The float.
            */
        virtual float GetFloat(int &index) const override;

        /**
            * @fn  virtual void Array::AddFloat(const float &value) override;
            *
            * @brief   Adds the float value to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddFloat(const float &value) override;

        /**
            * @fn  virtual bool Array::IsString(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is a String.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if string, false if not.
            */
        virtual bool IsString(int &index) const override;

        /**
            * @fn  virtual const std::string Array::GetString(int &index) const override;
            *
            * @brief   Returns the String value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The string.
            */
        virtual const std::string GetString(int &index) const override;

        /**
            * @fn  virtual void Array::AddString(const std::string &value) override;
            *
            * @brief   Adds the String to the Array.
            *
            * @param   value   The value.
            */
        virtual void AddString(const std::string &value) override;

        /**
            * @fn  virtual bool Array::IsArray(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is an Array.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if array, false if not.
            */
        virtual bool IsArray(int &index) const override;

        /**
            * @fn  virtual Array Array::GetArray(int &index) const override;
            *
            * @brief   Returns the Array value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The array.
            */
        virtual Array GetArray(int &index) const override;

        /**
            * @fn  virtual void Array::AddArray(Array &Array) override;
            *
            * @brief   Adds the Array to the Array.
            *
            * @param [in,out]  Array   The array.
            */
        virtual void AddArray(Array &Array) override;

        /**
            * @fn  virtual bool Array::IsObject(int &index) const override;
            *
            * @brief   Checks if the value stored at the specific index is an Object.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  True if object, false if not.
            */
        virtual bool IsObject(int &index) const override;

        /**
            * @fn  virtual Object Array::GetObject(int &index) const override;
            *
            * @brief   Returns the Object value stored at the given index.
            *
            * @param [in,out]  index   Zero-based index of the.
            *
            * @return  The object.
            */
        virtual Object GetObject(int &index) const override;

        /**
            * @fn  virtual void Array::AddObject(Object &Object) override;
            *
            * @brief   Adds the Object to the Array.
            *
            * @param [in,out]  Object  The object.
            */
        virtual void AddObject(Object &Object) override;

    private:
        /** @brief   The root. */
        Value mRoot = Value(ValueType::ArrayValue);
    };
}