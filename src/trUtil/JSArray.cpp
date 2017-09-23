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


#include <trUtil/JSArray.h>

#include <trUtil/JSObject.h>
#include <trUtil/Logging/Log.h>

#include <iostream>

namespace trUtil
{
    //////////////////////////////////////////////////////////////////////////
    JSArray::JSArray()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    JSArray::JSArray(const Json::Value &jsArray)
    {
        mRoot = jsArray;
    }

    //////////////////////////////////////////////////////////////////////////
    JSArray::~JSArray()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value& JSArray::operator[](int index)
    {
        if (index < 0)
        {
            LOG_E("Array Index cannot be negative!");
        }
        return mRoot[index];
    }
    //////////////////////////////////////////////////////////////////////////
    int JSArray::Size()
    {
        return mRoot.size();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::Resize(int newSize)
    {
        mRoot.resize(newSize);
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::Clear()
    {
        mRoot.clear();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::RemoveIndex(int index, Json::Value *removedVal)
    {
        return mRoot.removeIndex(index, removedVal);
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value& JSArray::GetJSONRoot()
    {
        return mRoot;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::PrintJSONRoot()
    {
        std::cout << mRoot << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsNull(int &index) const
    {
        return mRoot[index].isNull();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddNull()
    {
        mRoot.append(Json::Value());
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsBool(int &index) const
    {
        return mRoot[index].isBool();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::GetBool(int &index) const
    {
        return mRoot[index].asBool();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddBool(const bool &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsTrue(int &index) const
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
    bool JSArray::IsFalse(int &index) const
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
    bool JSArray::IsNumber(int &index) const
    {
        return mRoot[index].isNumeric();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsInt(int &index) const
    {
        return mRoot[index].isInt();
    }

    //////////////////////////////////////////////////////////////////////////
    int JSArray::GetInt(int &index) const
    {
        return mRoot[index].asInt();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddInt(const int &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsDouble(int &index) const
    {
        return mRoot[index].isDouble();
    }

    //////////////////////////////////////////////////////////////////////////
    double JSArray::GetDouble(int &index) const
    {
        return mRoot[index].asDouble();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddDouble(const double &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsUInt(int &index) const
    {
        return mRoot[index].isUInt();
    }

    //////////////////////////////////////////////////////////////////////////
    unsigned int JSArray::GetUInt(int &index) const
    {
        return mRoot[index].asUInt();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddUInt(const unsigned int &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsInt64(int &index) const
    {
        return mRoot[index].isInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value::Int64 JSArray::GetInt64(int &index) const
    {
        return mRoot[index].asInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddInt64(const Json::Value::Int64 &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsUInt64(int &index) const
    {
        return mRoot[index].isUInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value::UInt64 JSArray::GetUInt64(int &index) const
    {
        return mRoot[index].asUInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddUInt64(const Json::Value::UInt64 &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsFloat(int &index) const
    {
        return mRoot[index].isNumeric();
    }

    //////////////////////////////////////////////////////////////////////////
    float JSArray::GetFloat(int &index) const
    {
        return mRoot[index].asFloat();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddFloat(const float &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsString(int &index) const
    {
        return mRoot[index].isString();
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string JSArray::GetString(int &index) const
    {
        return mRoot[index].asString();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddString(const std::string &value)
    {
        mRoot.append(value);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsArray(int &index) const
    {
        return mRoot[index].isArray();
    }

    //////////////////////////////////////////////////////////////////////////
    JSArray JSArray::GetArray(int &index) const
    {
        JSArray tempArray(mRoot[index]);
        return tempArray;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddArray(JSArray &jsArray)
    {
        mRoot.append(jsArray.GetJSONRoot());
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSArray::IsObject(int &index) const
    {
        return mRoot[index].isObject();
    }

    //////////////////////////////////////////////////////////////////////////
    JSObject JSArray::GetObject(int &index) const
    {
        JSObject tempObject(mRoot[index]);
        return tempObject;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSArray::AddObject(JSObject &jsObject)
    {
        mRoot.append(jsObject.GetJSONRoot());
    }
}
