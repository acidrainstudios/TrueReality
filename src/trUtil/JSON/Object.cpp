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

#include <trUtil/JSON/Object.h>

#include <trUtil/JSON/Array.h>

#include <iostream>

namespace trUtil
{
	namespace JSON
	{
		//////////////////////////////////////////////////////////////////////////
		Object::Object()
		{}

		//////////////////////////////////////////////////////////////////////////
		Object::Object(const Value &Object)
		{
			mRoot = Object;
		}

		//////////////////////////////////////////////////////////////////////////
		Object::~Object()
		{}

		//////////////////////////////////////////////////////////////////////////
		const Members Object::GetMemberNames() const
		{
			return mRoot.getMemberNames();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::Clear()
		{
			mRoot.clear();
		}

		//////////////////////////////////////////////////////////////////////////
		Value& Object::GetJSONRoot()
		{
			return mRoot;
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::PrintJSONRoot()
		{
			std::cout << mRoot << std::endl;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::KeyPresent(const std::string &key) const
		{
			return mRoot.isMember(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsNull(const std::string &key) const
		{
			return mRoot[key].isNull();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetNull(const std::string &key)
		{
			mRoot[key] = Json::Value();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsBool(const std::string &key) const
		{
			return mRoot[key].isBool();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::GetBool(const std::string &key) const
		{
			return mRoot[key].asBool();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetBool(const std::string &key, const bool &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsTrue(const std::string &key) const
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
		bool Object::IsFalse(const std::string &key) const
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
		bool Object::IsNumber(const std::string &key) const
		{
			return mRoot[key].isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsInt(const std::string &key) const
		{
			return mRoot[key].isInt();
		}

		//////////////////////////////////////////////////////////////////////////
		int Object::GetInt(const std::string &key) const
		{
			return mRoot[key].asInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetInt(const std::string &key, const int &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsDouble(const std::string &key) const
		{
			return mRoot[key].isDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		double Object::GetDouble(const std::string &key) const
		{
			return mRoot[key].asDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetDouble(const std::string &key, const double &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsUInt(const std::string &key) const
		{
			return mRoot[key].isUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		unsigned int Object::GetUInt(const std::string &key) const
		{
			return mRoot[key].asUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetUInt(const std::string &key, const unsigned int &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsInt64(const std::string &key) const
		{
			return mRoot[key].isInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		Int64 Object::GetInt64(const std::string &key) const
		{
			return mRoot[key].asInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetInt64(const std::string &key, const Int64 &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsUInt64(const std::string &key) const
		{
			return mRoot[key].isUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		UInt64 Object::GetUInt64(const std::string &key) const
		{
			return mRoot[key].asUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetUInt64(const std::string &key, const UInt64 &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsFloat(const std::string &key) const
		{
			return mRoot[key].isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		float Object::GetFloat(const std::string &key) const
		{
			return mRoot[key].asFloat();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetFloat(const std::string &key, const float &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsString(const std::string &key) const
		{
			return mRoot[key].isString();
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string Object::GetString(const std::string &key) const
		{
			return mRoot[key].asString();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetString(const std::string &key, const std::string &value)
		{
			mRoot[key] = value;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsArray(const std::string &key) const
		{
			return mRoot[key].isArray();
		}

		//////////////////////////////////////////////////////////////////////////
		Array Object::GetArray(const std::string &key) const
		{
			Array tempArray(mRoot[key]);
			return tempArray;
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetArray(const std::string &key, Array &Array)
		{
			mRoot[key] = Array.GetJSONRoot();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsObject(const std::string &key) const
		{
			return mRoot[key].isObject();
		}

		//////////////////////////////////////////////////////////////////////////
		Object Object::GetObject(const std::string &key) const
		{
			Object tempObject(mRoot[key]);
			return tempObject;
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetObject(const std::string &key, Object &Object)
		{
			mRoot[key] = Object.GetJSONRoot();
		}
	}    
}