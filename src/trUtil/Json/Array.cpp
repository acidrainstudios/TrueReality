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


#include <trUtil/Json/Array.h>

#include <trUtil/Json/Object.h>
#include <trUtil/Logging/Log.h>

#include <iostream>

namespace trUtil
{
	namespace JSON
	{
		//////////////////////////////////////////////////////////////////////////
		Array::Array()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Array::Array(const Json::Value &Array)
		{
			mRoot = Array;
		}

		//////////////////////////////////////////////////////////////////////////
		Array::~Array()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Json::Value& Array::operator[](int index)
		{
			if (index < 0)
			{
				LOG_E("Array Index cannot be negative!");
			}
			return mRoot[index];
		}
		//////////////////////////////////////////////////////////////////////////
		int Array::Size()
		{
			return mRoot.size();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::Resize(int newSize)
		{
			mRoot.resize(newSize);
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::Clear()
		{
			mRoot.clear();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::RemoveIndex(int index, Json::Value *removedVal)
		{
			return mRoot.removeIndex(index, removedVal);
		}

		//////////////////////////////////////////////////////////////////////////
		Json::Value& Array::GetJSONRoot()
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
			return mRoot[index].isNull();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddNull()
		{
			mRoot.append(Json::Value());
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsBool(int &index) const
		{
			return mRoot[index].isBool();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::GetBool(int &index) const
		{
			return mRoot[index].asBool();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddBool(const bool &value)
		{
			mRoot.append(value);
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
			return mRoot[index].isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsInt(int &index) const
		{
			return mRoot[index].isInt();
		}

		//////////////////////////////////////////////////////////////////////////
		int Array::GetInt(int &index) const
		{
			return mRoot[index].asInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddInt(const int &value)
		{
			mRoot.append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsDouble(int &index) const
		{
			return mRoot[index].isDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		double Array::GetDouble(int &index) const
		{
			return mRoot[index].asDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddDouble(const double &value)
		{
			mRoot.append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsUInt(int &index) const
		{
			return mRoot[index].isUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		unsigned int Array::GetUInt(int &index) const
		{
			return mRoot[index].asUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddUInt(const unsigned int &value)
		{
			mRoot.append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsInt64(int &index) const
		{
			return mRoot[index].isInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		Json::Value::Int64 Array::GetInt64(int &index) const
		{
			return mRoot[index].asInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddInt64(const Json::Value::Int64 &value)
		{
			mRoot.append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsUInt64(int &index) const
		{
			return mRoot[index].isUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		Json::Value::UInt64 Array::GetUInt64(int &index) const
		{
			return mRoot[index].asUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddUInt64(const Json::Value::UInt64 &value)
		{
			mRoot.append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsFloat(int &index) const
		{
			return mRoot[index].isNumeric();
		}

		//////////////////////////////////////////////////////////////////////////
		float Array::GetFloat(int &index) const
		{
			return mRoot[index].asFloat();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddFloat(const float &value)
		{
			mRoot.append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsString(int &index) const
		{
			return mRoot[index].isString();
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string Array::GetString(int &index) const
		{
			return mRoot[index].asString();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddString(const std::string &value)
		{
			mRoot.append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsArray(int &index) const
		{
			return mRoot[index].isArray();
		}

		//////////////////////////////////////////////////////////////////////////
		Array Array::GetArray(int &index) const
		{
			Array tempArray(mRoot[index]);
			return tempArray;
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddArray(Array &Array)
		{
			mRoot.append(Array.GetJSONRoot());
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsObject(int &index) const
		{
			return mRoot[index].isObject();
		}

		//////////////////////////////////////////////////////////////////////////
		Object Array::GetObject(int &index) const
		{
			Object tempObject(mRoot[index]);
			return tempObject;
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddObject(Object &Object)
		{
			mRoot.append(Object.GetJSONRoot());
		}
	}    
}