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

#include <trUtil/JSON/Value.h>

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
			mValuePtr = new Json::Value(type);
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
			mValuePtr->setComment(comment, Json::CommentPlacement::commentAfterOnSameLine);
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
		bool Value::IsEmpty() const
		{
			return mValuePtr->empty();
		}

		//////////////////////////////////////////////////////////////////////////
		void Value::Append(const Value& val)
		{
			mValuePtr->append(val);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsBool() const
		{
			return mValuePtr->isBool();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::GetBool() const
		{
			return mValuePtr->asBool();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsNumber() const
		{
			return mValuePtr->isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsInt() const
		{
			return mValuePtr->isInt();
		}

		//////////////////////////////////////////////////////////////////////////
		int Value::GetInt() const
		{
			return mValuePtr->asInt();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsDouble() const
		{
			return mValuePtr->isDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		double Value::GetDouble() const
		{
			return mValuePtr->asDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsUInt() const
		{
			return mValuePtr->isUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		unsigned int Value::GetUInt() const
		{
			return mValuePtr->asUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsInt64() const
		{
			return mValuePtr->isInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		Int64 Value::GetInt64() const
		{
			return mValuePtr->asInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsUInt64() const
		{
			return mValuePtr->isUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		UInt64 Value::GetUInt64() const
		{
			return mValuePtr->asUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsFloat() const
		{
			return mValuePtr->isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		float Value::GetFloat() const
		{
			return mValuePtr->asFloat();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsString() const
		{
			return mValuePtr->isString();
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string Value::GetString() const
		{
			return mValuePtr->asString();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsArray() const
		{
			return mValuePtr->isArray();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Value::IsObject() const
		{
			return mValuePtr->isObject();
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

		//////////////////////////////////////////////////////////////////////////
		Value Value::operator[](int index)
		{
			return Value(mValuePtr->operator[](index));
		}

		//////////////////////////////////////////////////////////////////////////
		const Value Value::operator[](int index) const
		{
			return Value(mValuePtr->operator[](index));
		}

		//////////////////////////////////////////////////////////////////////////
		Value Value::operator[](const char* key)
		{
			return Value(mValuePtr->operator[](key));
		}

		//////////////////////////////////////////////////////////////////////////
		const Value Value::operator[](const char* key) const
		{
			return Value(mValuePtr->operator[](key));
		}

		//////////////////////////////////////////////////////////////////////////
		Value Value::operator[](const std::string& key)
		{
			return Value(mValuePtr->operator[](key));
		}

		//////////////////////////////////////////////////////////////////////////
		const Value Value::operator[](const std::string& key) const
		{
			return Value(mValuePtr->operator[](key));
		}

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