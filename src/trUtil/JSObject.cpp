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

#include <trUtil/JSObject.h>

#include <trUtil/JSArray.h>

#include <json/json.h>

#include <iostream>



namespace trUtil
{

    //////////////////////////////////////////////////////////////////////////
    JSObject::JSObject()
    {}

    //////////////////////////////////////////////////////////////////////////
    JSObject::JSObject(const Json::Value &jsObject)
    {
        mRoot = jsObject;
    }

    //////////////////////////////////////////////////////////////////////////
    JSObject::~JSObject()
    {}

    //////////////////////////////////////////////////////////////////////////
    const Json::Value::Members JSObject::GetMemberNames() const 
    {
        return mRoot.getMemberNames();
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value& JSObject::GetJSONRoot()
    {
        return mRoot;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::PrintJSONRoot()
    {
        std::cout << mRoot << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::KeyPresent(const std::string &key) const
    {
        return mRoot.isMember(key);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsNull(const std::string &key) const
    {
        return mRoot[key].isNull();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetNull(const std::string &key)
    {
        mRoot[key] = Json::Value();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsBool(const std::string &key) const
    {
        return mRoot[key].isBool();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::GetBool(const std::string &key) const
    {
        return mRoot[key].asBool();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetBool(const std::string &key, const bool &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsTrue(const std::string &key) const
    {
        if (KeyPresent(key))
        {
            if (GetBool(key) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsFalse(const std::string &key) const
    {
        if (KeyPresent(key))
        {
            if (GetBool(key) == false)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsNumber(const std::string &key) const
    {
        return mRoot[key].isNumeric();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsInt(const std::string &key) const
    {
        return mRoot[key].isInt();
    }

    //////////////////////////////////////////////////////////////////////////
    int JSObject::GetInt(const std::string &key) const
    {
        return mRoot[key].asInt();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetInt(const std::string &key, const int &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsDouble(const std::string &key) const
    {
        return mRoot[key].isDouble();
    }

    //////////////////////////////////////////////////////////////////////////
    double JSObject::GetDouble(const std::string &key) const
    {
        return mRoot[key].asDouble();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetDouble(const std::string &key, const double &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsUInt(const std::string &key) const
    {
        return mRoot[key].isUInt();
    }

    //////////////////////////////////////////////////////////////////////////
    unsigned int JSObject::GetUInt(const std::string &key) const
    {
        return mRoot[key].asUInt();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetUInt(const std::string &key, const unsigned int &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsInt64(const std::string &key) const
    {
        return mRoot[key].isInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value::Int64 JSObject::GetInt64(const std::string &key) const
    {
        return mRoot[key].asInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetInt64(const std::string &key, const Json::Value::Int64 &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsUInt64(const std::string &key) const
    {
        return mRoot[key].isUInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value::UInt64 JSObject::GetUInt64(const std::string &key) const
    {
        return mRoot[key].asUInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetUInt64(const std::string &key, const Json::Value::UInt64 &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsFloat(const std::string &key) const
    {
        return mRoot[key].isNumeric();
    }

    //////////////////////////////////////////////////////////////////////////
    float JSObject::GetFloat(const std::string &key) const
    {
        return mRoot[key].asFloat();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetFloat(const std::string &key, const float &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsString(const std::string &key) const
    {
        return mRoot[key].isString();
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string JSObject::GetString(const std::string &key) const
    {
        return mRoot[key].asString();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetString(const std::string &key, const std::string &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsArray(const std::string &key) const
    {
        return mRoot[key].isArray();
    }

    //////////////////////////////////////////////////////////////////////////
    JSArray JSObject::GetArray(const std::string &key) const
    {
        JSArray tempArray(mRoot[key]);
        return tempArray;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetArray(const std::string &key, JSArray &jsArray)
    {
        mRoot[key] = jsArray.GetJSONRoot();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSObject::IsObject(const std::string &key) const
    {
        return mRoot[key].isObject();
    }

    //////////////////////////////////////////////////////////////////////////
    JSObject JSObject::GetObject(const std::string &key) const
    {
        JSObject tempObject(mRoot[key]);
        return tempObject;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSObject::SetObject(const std::string &key, JSObject &jsObject)
    {
        mRoot[key] = jsObject.GetJSONRoot();
    }
}
