/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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
        * @class   File
        *
        * @brief   A file.
        *
        * @author Maxim Serebrennik
        */
    class TR_UTIL_EXPORT File : Base
    {
    public:

        /** @brief   The default JSON file name. */
        const static std::string DEFAULT_JSON_FILE_NAME;

        /**
            * @fn  File::File();
            *
            * @brief   ctor.
            */
        File();

        /**
            * @fn  File::File(std::string fileName);
            *
            * @brief   Constructor that takes in the file name. The user still needs to Open the file for
            *          reading or writing.
            *
            * @param   fileName    Filename of the file.
            */
        File(std::string fileName);

        /**
            * @fn  File::~File();
            *
            * @brief   dtor.
            */
        ~File();

        /**
            * @fn  virtual bool File::ReadFromFile(std::string fileName);
            *
            * @brief   Reads from a file and parses the JSON into a Root node.
            *
            * @param   fileName    Filename of the file.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool ReadFromFile(std::string fileName);

        /**
            * @fn  virtual bool File::ReadFromFile();
            *
            * @brief   Reads from a file and parses the JSON into a Root Node. Uses an internally set
            *          filename to determine what to open.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool ReadFromFile();

        /**
            * @fn  virtual bool File::WriteToFile(std::string fileName);
            *
            * @brief   Writes the internal Root Node to a JSON file.
            *
            * @param   fileName    Filename of the file.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool WriteToFile(std::string fileName);

        /**
            * @fn  virtual bool File::WriteToFile();
            *
            * @brief   Writes the Root Node to a JSON file. Uses an internally set filename to determine
            *          what to create.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool WriteToFile();

        /**
            * @fn  virtual void File::SetFileName(std::string fileName);
            *
            * @brief   Sets a new file name. If a file has been opened already, this will close it.
            *
            * @param   fileName    Filename of the file.
            */
        virtual void SetFileName(std::string fileName);

        /**
            * @fn  virtual std::string File::GetFileName() const;
            *
            * @brief   Returns the name of the current file.
            *
            * @return  The file name.
            */
        virtual std::string GetFileName() const;

        /**
            * @fn  virtual void File::SetFilePath(std::string newPath);
            *
            * @brief   Sets the path of where the file will be read from or written to. By default the it
            *          sill be saved in the PathUtils::GetUserDataPath() + PathUtils::CONFIG_PATH folder.
            *
            * @param   newPath Full pathname of the new file.
            */
        virtual void SetFilePath(std::string newPath);

        /**
            * @fn  virtual std::string File::GetFilePath() const;
            *
            * @brief   Returns the path of where the file is read or written to.
            *
            * @return  The file path.
            */
        virtual std::string GetFilePath() const;

        /**
            * @fn  virtual bool File::FileExists();
            *
            * @brief   Returns true if the file name and path exist on the HD.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool FileExists();

        /**
            * @fn  void File::Clear() override;
            *
            * @brief   Clears the internal JSON Root node.
            */
        void Clear() override;

        /**
            * @fn  virtual Value& File::GetJSONRoot() override;
            *
            * @brief   Returns a reference to the internal JSON Root node.
            *
            * @return  The JSON root.
            */
        virtual Value& GetJSONRoot() override;

        /**
            * @fn  virtual void File::PrintJSONRoot() override;
            *
            * @brief   Prints out to the screen the whole JSON Root content.
            */
        virtual void PrintJSONRoot() override;

        /**
            * @fn  virtual bool File::KeyPresent(const std::string &key) const override;
            *
            * @brief   Checks if the JSON Root Node has an entry with a given key present.
            *
            * @param   key The key.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool KeyPresent(const std::string &key) const override;

        /**
            * @fn  virtual bool File::IsNull(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a NULL.
            *
            * @param   key The key.
            *
            * @return  True if null, false if not.
            */
        virtual bool IsNull(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetNull(const std::string &key) override;
            *
            * @brief   Sets the value stored at the specific key to NULL.
            *
            * @param   key The key.
            */
        virtual void SetNull(const std::string &key) override;

        /**
            * @fn  virtual bool File::IsBool(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a Boolean.
            *
            * @param   key The key.
            *
            * @return  True if bool, false if not.
            */
        virtual bool IsBool(const std::string &key) const override;

        /**
            * @fn  virtual bool File::GetBool(const std::string &key) const override;
            *
            * @brief   Returns the Boolean value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  True if it succeeds, false if it fails.
            */
        virtual bool GetBool(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetBool(const std::string &key, const bool &value) override;
            *
            * @brief   Sets the Boolean value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetBool(const std::string &key, const bool &value) override;

        /**
            * @fn  virtual bool File::IsTrue(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is True.
            *
            * @param   key The key.
            *
            * @return  True if true, false if not.
            */
        virtual bool IsTrue(const std::string &key) const override;

        /**
            * @fn  virtual bool File::IsFalse(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is False.
            *
            * @param   key The key.
            *
            * @return  True if false, false if not.
            */
        virtual bool IsFalse(const std::string &key) const override;

        /**
            * @fn  virtual bool File::IsNumber(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a Number.
            *
            * @param   key The key.
            *
            * @return  True if number, false if not.
            */
        virtual bool IsNumber(const std::string &key) const override;

        /**
            * @fn  virtual bool File::IsInt(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Integer.
            *
            * @param   key The key.
            *
            * @return  True if int, false if not.
            */
        virtual bool IsInt(const std::string &key) const override;

        /**
            * @fn  virtual int File::GetInt(const std::string &key) const override;
            *
            * @brief   Returns the Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The int.
            */
        virtual int GetInt(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetInt(const std::string &key, const int &value) override;
            *
            * @brief   Sets the Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetInt(const std::string &key, const int &value) override;

        /**
            * @fn  virtual bool File::IsDouble(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a Double.
            *
            * @param   key The key.
            *
            * @return  True if double, false if not.
            */
        virtual bool IsDouble(const std::string &key) const override;

        /**
            * @fn  virtual double File::GetDouble(const std::string &key) const override;
            *
            * @brief   Returns the Double value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The double.
            */
        virtual double GetDouble(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetDouble(const std::string &key, const double &value) override;
            *
            * @brief   Sets the Double value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetDouble(const std::string &key, const double &value) override;

        /**
            * @fn  virtual bool File::IsUInt(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Unsigned Integer.
            *
            * @param   key The key.
            *
            * @return  True if u int, false if not.
            */
        virtual bool IsUInt(const std::string &key) const override;

        /**
            * @fn  virtual unsigned int File::GetUInt(const std::string &key) const override;
            *
            * @brief   Returns the Unsigned Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The u int.
            */
        virtual unsigned int GetUInt(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetUInt(const std::string &key, const unsigned int &value) override;
            *
            * @brief   Sets the Unsigned Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetUInt(const std::string &key, const unsigned int &value) override;

        /**
            * @fn  virtual bool File::IsInt64(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a 64bit Integer.
            *
            * @param   key The key.
            *
            * @return  True if int 64, false if not.
            */
        virtual bool IsInt64(const std::string &key) const override;

        /**
            * @fn  virtual Int64 File::GetInt64(const std::string &key) const override;
            *
            * @brief   Returns the 64bit Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The int 64.
            */
        virtual Int64 GetInt64(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetInt64(const std::string &key, const Int64 &value) override;
            *
            * @brief   Sets the 64bit Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetInt64(const std::string &key, const Int64 &value) override;

        /**
            * @fn  virtual bool File::IsUInt64(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a 64bit Integer.
            *
            * @param   key The key.
            *
            * @return  True if u int 64, false if not.
            */
        virtual bool IsUInt64(const std::string &key) const override;

        /**
            * @fn  virtual UInt64 File::GetUInt64(const std::string &key) const override;
            *
            * @brief   Returns the 64bit Integer value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The u int 64.
            */
        virtual UInt64 GetUInt64(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetUInt64(const std::string &key, const UInt64 &value) override;
            *
            * @brief   Sets the 64bit Integer value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetUInt64(const std::string &key, const UInt64 &value) override;

        /**
            * @fn  virtual bool File::IsFloat(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a float.
            *
            * @param   key The key.
            *
            * @return  True if float, false if not.
            */
        virtual bool IsFloat(const std::string &key) const override;

        /**
            * @fn  virtual float File::GetFloat(const std::string &key) const override;
            *
            * @brief   Returns the float value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The float.
            */
        virtual float GetFloat(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetFloat(const std::string &key, const float &value) override;
            *
            * @brief   Sets the float value to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetFloat(const std::string &key, const float &value) override;

        /**
            * @fn  virtual bool File::IsString(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is a String.
            *
            * @param   key The key.
            *
            * @return  True if string, false if not.
            */
        virtual bool IsString(const std::string &key) const override;

        /**
            * @fn  virtual const std::string File::GetString(const std::string &key) const override;
            *
            * @brief   Returns the String value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The string.
            */
        virtual const std::string GetString(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetString(const std::string &key, const std::string &value) override;
            *
            * @brief   Sets the String to be stored at the given key.
            *
            * @param   key     The key.
            * @param   value   The value.
            */
        virtual void SetString(const std::string &key, const std::string &value) override;

        /**
            * @fn  virtual bool File::IsArray(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Array.
            *
            * @param   key The key.
            *
            * @return  True if array, false if not.
            */
        virtual bool IsArray(const std::string &key) const override;

        /**
            * @fn  virtual Array File::GetArray(const std::string &key) const override;
            *
            * @brief   Returns the Array value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The array.
            */
        virtual Array GetArray(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetArray(const std::string &key, Array &value) override;
            *
            * @brief   Sets the Array to be stored at the given key.
            *
            * @param           key     The key.
            * @param [in,out]  value   The value.
            */
        virtual void SetArray(const std::string &key, Array &value) override;

        /**
            * @fn  virtual bool File::IsObject(const std::string &key) const override;
            *
            * @brief   Checks if the value stored at the specific key is an Object.
            *
            * @param   key The key.
            *
            * @return  True if object, false if not.
            */
        virtual bool IsObject(const std::string &key) const override;

        /**
            * @fn  virtual Object File::GetObject(const std::string &key) const override;
            *
            * @brief   Returns the Object value stored at the given key.
            *
            * @param   key The key.
            *
            * @return  The object.
            */
        virtual Object GetObject(const std::string &key) const override;

        /**
            * @fn  virtual void File::SetObject(const std::string &key, Object &value) override;
            *
            * @brief   Sets the Array to be stored at the given key.
            *
            * @param           key     The key.
            * @param [in,out]  value   The value.
            */
        virtual void SetObject(const std::string &key, Object &value) override;

    private:
        /** @brief   Filename of the file. */
        std::string mFileName;
        /** @brief   Full pathname of the file. */
        std::string mFilePath;

        /** @brief   The root. */
        Value mRoot;
    };
}