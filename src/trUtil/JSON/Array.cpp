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


#include <trUtil/JSON/Array.h>

#include <trUtil/JSON/Object.h>
#include <trUtil/Logging/Log.h>

#include <iostream>

namespace trUtil::JSON
{
    //////////////////////////////////////////////////////////////////////////
    Array::Array()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Array::Array(const Value &Array)
    {
        mRoot = Array;
    }

    //////////////////////////////////////////////////////////////////////////
    Array::~Array()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Value Array::operator[](int index)
    {
        if (index < 0)
        {
            LOG_E("Array Index cannot be negative!");
        }
        return mRoot.Index(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::SetComment(const std::string& comment)
    {
        mRoot.SetComment(comment);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::HasComment() const
    {
        return mRoot.HasComment();
    }

    //////////////////////////////////////////////////////////////////////////
    std::string Array::GetComment() const
    {
        return mRoot.GetComment();
    }
    //////////////////////////////////////////////////////////////////////////
    int Array::Size()
    {
        return mRoot.Size();
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::Resize(int newSize)
    {
        mRoot.Resize(newSize);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::Clear()
    {
        mRoot.Clear();
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::RemoveIndex(int index, Value *removedVal)
    {
        return mRoot.RemoveIndex(index, removedVal);
    }

    //////////////////////////////////////////////////////////////////////////
    Value& Array::GetJSONRoot()
    {
        return mRoot;
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::PrintJSONRoot()
    {
        std::cout << mRoot << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsNull(int &index) const
    {
        return mRoot.IsNull(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddNull()
    {
        mRoot.Append(Value());
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsBool(int &index) const
    {
        return mRoot.IsBool(index);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::GetBool(int &index) const
    {
        return mRoot.GetBool(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddBool(const bool &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsTrue(int &index) const
    {
        if (GetBool(index) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsFalse(int &index) const
    {
        if (GetBool(index) == false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsNumber(int &index) const
    {
        return mRoot.IsNumber(index);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsInt(int &index) const
    {
        return mRoot.IsInt(index);
    }

    //////////////////////////////////////////////////////////////////////////
    int Array::GetInt(int &index) const
    {
        return mRoot.GetInt(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddInt(const int &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsDouble(int &index) const
    {
        return mRoot.IsDouble(index);
    }

    //////////////////////////////////////////////////////////////////////////
    double Array::GetDouble(int &index) const
    {
        return mRoot.GetDouble(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddDouble(const double &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsUInt(int &index) const
    {
        return mRoot.IsUInt(index);
    }

    //////////////////////////////////////////////////////////////////////////
    unsigned int Array::GetUInt(int &index) const
    {
        return mRoot.GetUInt(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddUInt(const unsigned int &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsInt64(int &index) const
    {
        return mRoot.IsInt64(index);
    }

    //////////////////////////////////////////////////////////////////////////
    Int64 Array::GetInt64(int &index) const
    {
        return mRoot.GetInt64(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddInt64(const Int64 &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsUInt64(int &index) const
    {
        return mRoot.IsUInt64(index);
    }

    //////////////////////////////////////////////////////////////////////////
    UInt64 Array::GetUInt64(int &index) const
    {
        return mRoot.GetUInt64(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddUInt64(const UInt64 &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsFloat(int &index) const
    {
        return mRoot.IsFloat(index);
    }

    //////////////////////////////////////////////////////////////////////////
    float Array::GetFloat(int &index) const
    {
        return mRoot.GetFloat(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddFloat(const float &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsString(int &index) const
    {
        return mRoot.IsString(index);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string Array::GetString(int &index) const
    {
        return mRoot.GetString(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddString(const std::string &value)
    {
        mRoot.Append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsArray(int &index) const
    {
        return mRoot.IsArray(index);
    }

    //////////////////////////////////////////////////////////////////////////
    Array Array::GetArray(int &index) const
    {
        return mRoot.GetArray(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddArray(Array &Array)
    {
        mRoot.Append(Array.GetJSONRoot());
    }

    //////////////////////////////////////////////////////////////////////////
    bool Array::IsObject(int &index) const
    {
        return mRoot.IsObject(index);
    }

    //////////////////////////////////////////////////////////////////////////
    Object Array::GetObject(int &index) const
    {
        return mRoot.GetObject(index);
    }

    //////////////////////////////////////////////////////////////////////////
    void Array::AddObject(Object &Object)
    {
        mRoot.Append(Object.GetJSONRoot());
    }
}