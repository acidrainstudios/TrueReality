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
		const Value::Members Object::GetMemberNames() const
		{
			return mRoot.GetMemberNames();
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::Clear()
		{
			mRoot.Clear();
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
			return mRoot.KeyPresent(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsNull(const std::string &key) const
		{
			return mRoot.IsNull(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetNull(const std::string &key)
		{
            mRoot.SetNull(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsBool(const std::string &key) const
		{
			return mRoot.IsBool(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::GetBool(const std::string &key) const
		{
			return mRoot.GetBool(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetBool(const std::string &key, const bool &value)
		{
			mRoot.SetBool(key, value);
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
			return mRoot.IsNumber(key);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsInt(const std::string &key) const
		{
			return mRoot.IsInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		int Object::GetInt(const std::string &key) const
		{
			return mRoot.GetInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetInt(const std::string &key, const int &value)
		{
			mRoot.SetInt(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsDouble(const std::string &key) const
		{
			return mRoot.IsDouble(key);
		}

		//////////////////////////////////////////////////////////////////////////
		double Object::GetDouble(const std::string &key) const
		{
			return mRoot.GetDouble(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetDouble(const std::string &key, const double &value)
		{
			mRoot.SetDouble(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsUInt(const std::string &key) const
		{
			return mRoot.IsUInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		unsigned int Object::GetUInt(const std::string &key) const
		{
			return mRoot.GetUInt(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetUInt(const std::string &key, const unsigned int &value)
		{
			mRoot.SetUInt(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsInt64(const std::string &key) const
		{
			return mRoot.IsInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		Int64 Object::GetInt64(const std::string &key) const
		{
			return mRoot.GetInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetInt64(const std::string &key, const Int64 &value)
		{
            mRoot.SetInt64(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsUInt64(const std::string &key) const
		{
			return mRoot.IsUInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		UInt64 Object::GetUInt64(const std::string &key) const
		{
			return mRoot.GetUInt64(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetUInt64(const std::string &key, const UInt64 &value)
		{
			mRoot.SetUInt64(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsFloat(const std::string &key) const
		{
			return mRoot.IsFloat(key);
		}

		//////////////////////////////////////////////////////////////////////////
		float Object::GetFloat(const std::string &key) const
		{
			return mRoot.GetFloat(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetFloat(const std::string &key, const float &value)
		{
			mRoot.SetFloat(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsString(const std::string &key) const
		{
			return mRoot.IsString(key);
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string Object::GetString(const std::string &key) const
		{
			return mRoot.GetString(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetString(const std::string &key, const std::string &value)
		{
			mRoot.SetString(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsArray(const std::string &key) const
		{
			return mRoot.IsArray(key);
		}

		//////////////////////////////////////////////////////////////////////////
		Array Object::GetArray(const std::string &key) const
		{
			return mRoot.GetArray(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetArray(const std::string &key, Array& value)
		{
			mRoot.SetArray(key, value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Object::IsObject(const std::string &key) const
		{
			return mRoot.IsObject(key);
		}

		//////////////////////////////////////////////////////////////////////////
		Object Object::GetObject(const std::string &key) const
		{
			return mRoot.GetObject(key);
		}

		//////////////////////////////////////////////////////////////////////////
		void Object::SetObject(const std::string &key, Object& value)
		{
			mRoot.SetObject(key, value);
		}
	}    
}