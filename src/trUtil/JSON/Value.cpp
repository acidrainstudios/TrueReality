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

#include <trUtil/JSON/Value.h>

#include <trUtil/JSON/Array.h>
#include <trUtil/JSON/Object.h>

#include <json/writer.h>

namespace trUtil
{
	namespace JSON
	{

		//////////////////////////////////////////////////////////////////////////
		Value::Value(Json::Value& value)
		{
            clearInternalVal = false;
			mValuePtr = &value;
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(ValueType type)
		{
			mValuePtr = new Json::Value(ToValueType(type));
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(Int value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(UInt value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(Int64 value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(UInt64 value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(double value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(const char* value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(const char* begin, const char* end)
		{
			mValuePtr = new Json::Value(begin, end);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(const std::string& value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(bool value)
		{
			mValuePtr = new Json::Value(value);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(const Value& other)
		{
			mValuePtr = new Json::Value(other);
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value(Value&& other)
		{
			mValuePtr = new Json::Value(other);
		}

        //////////////////////////////////////////////////////////////////////////
        Value::~Value()
        {
            if (mValuePtr && clearInternalVal)
            {
                delete mValuePtr;
                mValuePtr = nullptr;
            }            
        }

		//////////////////////////////////////////////////////////////////////////
		Json::Value& Value::GetJsonValue()
		{
			return *mValuePtr;
		}

		//////////////////////////////////////////////////////////////////////////
		const Json::Value& Value::GetJsonValue() const
		{
			return *mValuePtr;
		}

		//////////////////////////////////////////////////////////////////////////
		void Value::SetComment(const std::string & comment)
		{
            std::string finalComment;
            if (comment[0] != '/')
            {
                //in Json::Value::setComment(): Comments must start with /
                finalComment = "/" + comment;
            }
            else
            {
                finalComment = comment;
            }
			mValuePtr->setComment(finalComment, Json::CommentPlacement::commentAfterOnSameLine);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::HasComment() const
		{
			return mValuePtr->hasComment(Json::CommentPlacement::commentAfterOnSameLine);
		}

		//////////////////////////////////////////////////////////////////////////
		std::string Value::GetComment() const
		{
			return mValuePtr->getComment(Json::CommentPlacement::commentAfterOnSameLine);
		}

		//////////////////////////////////////////////////////////////////////////
		void Value::Clear()
		{
			mValuePtr->clear();
		}

		//////////////////////////////////////////////////////////////////////////
		int Value::Size()
		{
			return mValuePtr->size();
		}

		//////////////////////////////////////////////////////////////////////////
		void Value::Resize(int newSize)
		{
			mValuePtr->resize(newSize);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsValidIndex(int index) const
		{
			return mValuePtr->isValidIndex(index);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::RemoveIndex(int index, Value* removedVal)
		{
			return mValuePtr->removeIndex(index, &removedVal->GetJsonValue());
		}

        //////////////////////////////////////////////////////////////////////////
        Value Value::Index(int index)
        {
            return Value((*mValuePtr)[index]);
        }

		//////////////////////////////////////////////////////////////////////////
		const Value::Members Value::GetMemberNames() const
		{
			return mValuePtr->getMemberNames();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::HasMember(const std::string& key) const
		{
			return mValuePtr->isMember(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::KeyPresent(const std::string& key) const
		{
			return mValuePtr->isMember(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsNull() const
		{
			return mValuePtr->isNull();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsNull(const int index) const
        {
            return (*mValuePtr)[index].isNull();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsNull(const std::string& key) const
        {
            return (*mValuePtr)[key].isNull();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetNull(const std::string & key) const
        {
            (*mValuePtr)[key] = Json::Value();
        }

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsEmpty() const
		{
			return mValuePtr->empty();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsEmpty(const int index) const
        {
            return (*mValuePtr)[index].empty();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsEmpty(const std::string& key) const
        {
            return (*mValuePtr)[key].empty();
        }

        //////////////////////////////////////////////////////////////////////////
		void Value::Append(const Value& val)
		{
            mValuePtr->append(*new Json::Value(val));
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsBool() const
		{
			return mValuePtr->isBool();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsBool(const int index) const
        {
            return (*mValuePtr)[index].isBool();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsBool(const std::string& key) const
        {
            return (*mValuePtr)[key].isBool();
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::GetBool() const
		{
			return mValuePtr->asBool();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::GetBool(const int index) const
        {
            return (*mValuePtr)[index].asBool();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::GetBool(const std::string& key) const
        {
            return (*mValuePtr)[key].asBool();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetBool(const std::string& key, bool value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsNumber() const
		{
			return mValuePtr->isNumeric();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsNumber(const int index) const
        {
            return (*mValuePtr)[index].isNumeric();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsNumber(const std::string& key) const
        {
            return (*mValuePtr)[key].isNumeric();
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsInt() const
		{
			return mValuePtr->isInt();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsInt(const int index) const
        {
            return (*mValuePtr)[index].isInt();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsInt(const std::string& key) const
        {
            return (*mValuePtr)[key].isInt();
        }

        //////////////////////////////////////////////////////////////////////////
		int Value::GetInt() const
		{
			return mValuePtr->asInt();
		}

        //////////////////////////////////////////////////////////////////////////
        int Value::GetInt(const int index) const
        {
            return (*mValuePtr)[index].asInt();
        }

        //////////////////////////////////////////////////////////////////////////
        int Value::GetInt(const std::string& key) const
        {
            return (*mValuePtr)[key].asInt();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetInt(const std::string& key, int value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsDouble() const
		{
			return mValuePtr->isDouble();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsDouble(const int index) const
        {
            return (*mValuePtr)[index].isDouble();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsDouble(const std::string & key) const
        {
            return (*mValuePtr)[key].isDouble();
        }

        //////////////////////////////////////////////////////////////////////////
		double Value::GetDouble() const
		{
			return mValuePtr->asDouble();
		}

        //////////////////////////////////////////////////////////////////////////
        double Value::GetDouble(const int index) const
        {
            return (*mValuePtr)[index].asDouble();
        }

        //////////////////////////////////////////////////////////////////////////
        double Value::GetDouble(const std::string& key) const
        {
            return (*mValuePtr)[key].asDouble();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetDouble(const std::string& key, double value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsUInt() const
		{
			return mValuePtr->isUInt();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsUInt(const int index) const
        {
            return (*mValuePtr)[index].isUInt();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsUInt(const std::string & key) const
        {
            return (*mValuePtr)[key].isUInt();
        }

        //////////////////////////////////////////////////////////////////////////
		unsigned int Value::GetUInt() const
		{
			return mValuePtr->asUInt();
		}

        //////////////////////////////////////////////////////////////////////////
        unsigned int Value::GetUInt(const int index) const
        {
            return (*mValuePtr)[index].asUInt();
        }

        //////////////////////////////////////////////////////////////////////////
        unsigned int Value::GetUInt(const std::string& key) const
        {
            return (*mValuePtr)[key].asUInt();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetUInt(const std::string& key, unsigned int value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsInt64() const
		{
			return mValuePtr->isInt64();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsInt64(const int index) const
        {
            return (*mValuePtr)[index].isInt64();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsInt64(const std::string& key) const
        {
            return (*mValuePtr)[key].isInt64();
        }

        //////////////////////////////////////////////////////////////////////////
		Int64 Value::GetInt64() const
		{
			return mValuePtr->asInt64();
		}

        //////////////////////////////////////////////////////////////////////////
        Int64 Value::GetInt64(const int index) const
        {
            return (*mValuePtr)[index].asInt64();
        }

        //////////////////////////////////////////////////////////////////////////
        Int64 Value::GetInt64(const std::string& key) const
        {
            return (*mValuePtr)[key].asInt64();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetInt64(const std::string & key, Int64 value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsUInt64() const
		{
			return mValuePtr->isUInt64();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsUInt64(const int index) const
        {
            return (*mValuePtr)[index].isUInt64();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsUInt64(const std::string& key) const
        {
            return (*mValuePtr)[key].isUInt64();
        }

        //////////////////////////////////////////////////////////////////////////
		UInt64 Value::GetUInt64() const
		{
			return mValuePtr->asUInt64();
		}

        //////////////////////////////////////////////////////////////////////////
        UInt64 Value::GetUInt64(const int index) const
        {
            return (*mValuePtr)[index].asUInt64();
        }

        //////////////////////////////////////////////////////////////////////////
        UInt64 Value::GetUInt64(const std::string& key) const
        {
            return (*mValuePtr)[key].asUInt64();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetUInt64(const std::string& key, UInt64 value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsFloat() const
		{
			return mValuePtr->isNumeric();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsFloat(const int index) const
        {
            return (*mValuePtr)[index].isNumeric();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsFloat(const std::string& key) const
        {
            return (*mValuePtr)[key].isNumeric();
        }

        //////////////////////////////////////////////////////////////////////////
		float Value::GetFloat() const
		{
			return mValuePtr->asFloat();
		}

        //////////////////////////////////////////////////////////////////////////
        float Value::GetFloat(const int index) const
        {
            return (*mValuePtr)[index].asFloat();
        }

        //////////////////////////////////////////////////////////////////////////
        float Value::GetFloat(const std::string& key) const
        {
            return (*mValuePtr)[key].asFloat();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetFloat(const std::string& key, float value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsString() const
		{
			return mValuePtr->isString();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsString(const int index) const
        {
            return (*mValuePtr)[index].isString();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsString(const std::string& key) const
        {
            return (*mValuePtr)[key].isString();
        }

        //////////////////////////////////////////////////////////////////////////
		const std::string Value::GetString() const
		{
			return mValuePtr->asString();
		}

        //////////////////////////////////////////////////////////////////////////
        const std::string Value::GetString(const int index) const
        {
            return (*mValuePtr)[index].asString();
        }

        //////////////////////////////////////////////////////////////////////////
        const std::string Value::GetString(const std::string& key) const
        {
            return (*mValuePtr)[key].asString();
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetString(const std::string& key, const std::string& value)
        {
            (*mValuePtr)[key] = value;
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsArray() const
		{
			return mValuePtr->isArray();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsArray(const int index) const
        {
            return (*mValuePtr)[index].isArray();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsArray(const std::string& key) const
        {
            return (*mValuePtr)[key].isArray();
        }

        //////////////////////////////////////////////////////////////////////////
        const Array Value::GetArray() const
        {
            Array tempArray(*mValuePtr);
            return tempArray;
        }

        //////////////////////////////////////////////////////////////////////////
        const Array Value::GetArray(const int index) const
        {
            Array tempArray((*mValuePtr)[index]);
            return tempArray;
        }

        //////////////////////////////////////////////////////////////////////////
        const Array Value::GetArray(const std::string& key) const
        {
            Array tempArray((*mValuePtr)[key]);
            return tempArray;
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetArray(const std::string& key, Array& value)
        {
            (*mValuePtr)[key] = value.GetJSONRoot();
        }

        //////////////////////////////////////////////////////////////////////////
		bool Value::IsObject() const
		{
			return mValuePtr->isObject();
		}

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsObject(const int index) const
        {
            return (*mValuePtr)[index].isObject();
        }

        //////////////////////////////////////////////////////////////////////////
        bool Value::IsObject(const std::string& key) const
        {
            return (*mValuePtr)[key].isObject();
        }

        //////////////////////////////////////////////////////////////////////////
        const Object Value::GetObject() const
        {
            Object tempObject(*mValuePtr);
            return tempObject;
        }

        //////////////////////////////////////////////////////////////////////////
        const Object Value::GetObject(const int index) const
        {
            Object tempObject((*mValuePtr)[index]);
            return tempObject;
        }

        //////////////////////////////////////////////////////////////////////////
        const Object Value::GetObject(const std::string& key) const
        {
            Object tempObject((*mValuePtr)[key]);
            return tempObject;
        }

        //////////////////////////////////////////////////////////////////////////
        void Value::SetObject(const std::string& key, Object& value)
        {
            (*mValuePtr)[key] = value.GetJSONRoot();
        }

        //////////////////////////////////////////////////////////////////////////
        Json::ValueType Value::ToValueType(ValueType val)
        {
            switch (val)
            {
            case ValueType::NullValue:
                return Json::ValueType::nullValue;
                break;
            case ValueType::IntValue:
                return Json::ValueType::intValue;
                break;
            case ValueType::UintValue:
                return Json::ValueType::uintValue;
                break;
            case ValueType::RealValue:
                return Json::ValueType::realValue;
                break;
            case ValueType::StringValue:
                return Json::ValueType::stringValue;
                break;
            case ValueType::BooleanValue:
                return Json::ValueType::booleanValue;
                break;
            case ValueType::ArrayValue:
                return Json::ValueType::arrayValue;
                break;
            case ValueType::ObjectValue:
                return Json::ValueType::objectValue;
                break;
            default:
                return Json::ValueType::nullValue;
                break;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        ValueType Value::ToValueType(Json::ValueType val)
        {
            switch (val)
            {
            case Json::ValueType::nullValue:
                return ValueType::NullValue;
                break;
            case Json::ValueType::intValue:
                return ValueType::IntValue;
                break;
            case Json::ValueType::uintValue:
                return ValueType::UintValue;
                break;
            case Json::ValueType::realValue:
                return ValueType::RealValue;
                break;
            case Json::ValueType::stringValue:
                return ValueType::StringValue;
                break;
            case Json::ValueType::booleanValue:
                return ValueType::BooleanValue;
                break;
            case Json::ValueType::arrayValue:
                return ValueType::ArrayValue;
                break;
            case Json::ValueType::objectValue:
                return ValueType::ObjectValue;
                break;
            default:
                return ValueType::NullValue;
                break;
            }
        }

        //////////////////////////////////////////////////////////////////////////
		Value::operator Json::Value() const
		{
			return *mValuePtr;
		}

		//////////////////////////////////////////////////////////////////////////
		Value::operator Json::Value&()
		{
			return *mValuePtr;
		}

		//////////////////////////////////////////////////////////////////////////
		Value::operator const Json::Value&() const
		{
			return *mValuePtr;
		}

		//////////////////////////////////////////////////////////////////////////
		Value::operator Json::Value*()
		{
			return mValuePtr;
		}

		////////////////////////////////////////////////////////////////////////////
		//Value Value::operator[](int index)
		//{
		//	return Value((*mValuePtr)[index]);
		//}

		////////////////////////////////////////////////////////////////////////////
		//const Value Value::operator[](int index) const
		//{
		//	return Value((*mValuePtr)[index]);
		//}

		////////////////////////////////////////////////////////////////////////////
		//Value Value::operator[](const char* key)
		//{
		//	return Value((*mValuePtr)[key]);
		//}

		////////////////////////////////////////////////////////////////////////////
		//const Value Value::operator[](const char* key) const
		//{
		//	return Value((*mValuePtr)[key]);
		//}

		////////////////////////////////////////////////////////////////////////////
		//Value Value::operator[](const std::string& key)
		//{
		//	//return Value(mValuePtr->operator[](key));
  //          Json::Value val = (*mValuePtr)[key];
  //          Value newVal(val);
  //          return newVal;
		//}

		////////////////////////////////////////////////////////////////////////////
		//const Value Value::operator[](const std::string& key) const
		//{
		//	return Value((*mValuePtr)[key]);
		//}

		//////////////////////////////////////////////////////////////////////////
		Value& Value::operator=(Value other)
		{
			mValuePtr->operator=(other);
			return *this;
		}

		//////////////////////////////////////////////////////////////////////////
		std::ostream& operator<<(std::ostream& out, const Value& root)
		{
			return Json::operator<<(out, root);
		}
	}
}