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

#include <trUtil/JSONFile.h>

#include <trUtil/JSArray.h>
#include <trUtil/JSObject.h>

#include <trUtil/Exception.h>
#include <trUtil/FileUtils.h>
#include <trUtil/PathUtils.h>
#include <trUtil/PlatformMacros.h>
#include <trUtil/StringUtils.h>
#include <trUtil/WarningUtils.h>
#include <trUtil/Logging/Log.h>

#include <json/json.h>
#include <osgDB/fstream>

#include <iostream>
#include <cstdio>

namespace trUtil
{
    const std::string JSONFile::DEFAULT_JSON_FILE_NAME = std::string("Default.json");

    //////////////////////////////////////////////////////////////////////////
    JSONFile::JSONFile() : JSONFile(DEFAULT_JSON_FILE_NAME)
    {}

    //////////////////////////////////////////////////////////////////////////
    JSONFile::JSONFile(std::string fileName)
    {
        mFileName = fileName;
        mFilePath = PathUtils::GetUserDataPath() + PathUtils::CONFIG_PATH;
    }

    //////////////////////////////////////////////////////////////////////////
    JSONFile::~JSONFile()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::ReadFromFile()
    {
        return ReadFromFile(mFileName);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::ReadFromFile(std::string fileName)
    {
        try
        {
            mFileName = fileName;
            std::string fullFilePath = mFilePath + "/" + mFileName;
            Json::Reader reader;

            //Open a file for reading. 
            LOG_D("Opening JSON File for Reading: " + fullFilePath);
  

            //Read the file into the input stream. 
            LOG_D("Reading JSON File: " + fullFilePath);
            osgDB::ifstream inputStream(fullFilePath.c_str(), std::ifstream::binary);

            if (inputStream)
            {
                //Clear the root node for new input
                mRoot.clear();

                //Parse the stream into the document
                LOG_D("Parsing JSON File");
                if (!reader.parse(inputStream, mRoot))
                {
                    LOG_E("JSON Parsing Error: " + reader.getFormattedErrorMessages());
                    return false;
                }

                //Close the input stream
                inputStream.close();
                return true;
            }
            else
            {
                LOG_E("Can't open: " + fullFilePath);
                return false;
            }           
        }
        catch (const trUtil::Exception& ex)
        {
            ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
            return false;
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::WriteToFile()
    {
        return WriteToFile(mFileName);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::WriteToFile(std::string fileName)
    {
        try
        {
            mFileName = fileName;
            std::string fullFilePath = mFilePath + "/" + mFileName;
            Json::StyledWriter writer;

            //Open a file for writing
            LOG_D("Opening JSON File for Writing: " + fullFilePath);
            osgDB::ofstream outputStream(fullFilePath.c_str());

            //Writing the file
            LOG_D("Writing file");
            outputStream << writer.write(mRoot);
            outputStream.close();

            return true;
        }
        catch (const trUtil::Exception& ex)
        {
            ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetFileName(std::string fileName)
    {
        mFileName = fileName;
    }

    //////////////////////////////////////////////////////////////////////////
    std::string JSONFile::GetFileName() const 
    {
        return mFileName;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetFilePath(std::string newPath)
    {
        mFilePath = newPath;
    }

    //////////////////////////////////////////////////////////////////////////
    std::string JSONFile::GetFilePath() const
    {
        return mFilePath;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::FileExists() 
    {        
        return trUtil::FileUtils::GetInstance().FileExists(mFilePath + "/" + mFileName);
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value& JSONFile::GetJSONRoot()
    {
        return mRoot;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::PrintJSONRoot()
    {
        std::cout << mRoot << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::KeyPresent(const std::string &key) const
    {
        return mRoot.isMember(key);
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsNull(const std::string &key) const
    {
        return mRoot[key].isNull();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetNull(const std::string &key)
    {
        mRoot[key] = Json::Value();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsBool(const std::string &key) const
    {
        return mRoot[key].isBool();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::GetBool(const std::string &key) const
    {
        return mRoot[key].asBool();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetBool(const std::string &key, const bool &value)
    {
        mRoot[key] = value;
    }
    
    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsTrue(const std::string &key) const
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
    bool JSONFile::IsFalse(const std::string &key) const
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
    bool JSONFile::IsNumber(const std::string &key) const
    {
        return mRoot[key].isNumeric();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsInt(const std::string &key) const
    {
        return mRoot[key].isInt();
    }

    //////////////////////////////////////////////////////////////////////////
    int JSONFile::GetInt(const std::string &key) const
    {
        return mRoot[key].asInt();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetInt(const std::string &key, const int &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsDouble(const std::string &key) const
    {
        return mRoot[key].isDouble();
    }

    //////////////////////////////////////////////////////////////////////////
    double JSONFile::GetDouble(const std::string &key) const
    {
        return mRoot[key].asDouble();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetDouble(const std::string &key, const double &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsUInt(const std::string &key) const
    {
        return mRoot[key].isUInt();
    }

    //////////////////////////////////////////////////////////////////////////
    unsigned int JSONFile::GetUInt(const std::string &key) const
    {
        return mRoot[key].asUInt();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetUInt(const std::string &key, const unsigned int &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsInt64(const std::string &key) const
    {
        return mRoot[key].isInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value::Int64 JSONFile::GetInt64(const std::string &key) const
    {
        return mRoot[key].asInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetInt64(const std::string &key, const Json::Value::Int64 &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsUInt64(const std::string &key) const
    {
        return mRoot[key].isUInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    Json::Value::UInt64 JSONFile::GetUInt64(const std::string &key) const
    {
        return mRoot[key].asUInt64();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetUInt64(const std::string &key, const Json::Value::UInt64 &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsFloat(const std::string &key) const
    {
        return mRoot[key].isNumeric();
    }

    //////////////////////////////////////////////////////////////////////////
    float JSONFile::GetFloat(const std::string &key) const
    {
        return mRoot[key].asFloat();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetFloat(const std::string &key, const float &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsString(const std::string &key) const
    {
        return mRoot[key].isString();
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string JSONFile::GetString(const std::string &key) const
    {
        return mRoot[key].asString();
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetString(const std::string &key, const std::string &value)
    {
        mRoot[key] = value;
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsArray(const std::string &key) const
    {
        return mRoot[key].isArray();
    }

    //////////////////////////////////////////////////////////////////////////
    JSArray JSONFile::GetArray(const std::string &key) const
    {
        JSArray tempArray(mRoot[key]);
        return tempArray;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetArray(const std::string &key, JSArray &jsArray)
    {
        mRoot[key] = jsArray.GetJSONRoot();
    }

    //////////////////////////////////////////////////////////////////////////
    bool JSONFile::IsObject(const std::string &key) const
    {
        return mRoot[key].isObject();
    }

    //////////////////////////////////////////////////////////////////////////
    JSObject JSONFile::GetObject(const std::string &key) const
    {
        JSObject tempObject(mRoot[key]);
        return tempObject;
    }

    //////////////////////////////////////////////////////////////////////////
    void JSONFile::SetObject(const std::string &key, JSObject &jsObject)
    {
        mRoot[key] = jsObject.GetJSONRoot();
    }
}
