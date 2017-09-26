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


#include <trUtil/JSON/Array.h>

#include <trUtil/WarningUtils.h>
#include <trUtil/JSON/Object.h>
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
		Array::Array(const Value &Array)
		{
			mRoot = Array;
		}

		//////////////////////////////////////////////////////////////////////////
		Array::~Array()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		TR_DISABLE_WARNING_START_MSVC(4172)
		Value& Array::operator[](int index)
		{
			if (index < 0)
			{
				LOG_E("Array Index cannot be negative!");
			}
			return mRoot[index];
		}
		TR_DISABLE_WARNING_END
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
			return mRoot[index].IsNull();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddNull()
		{
			mRoot.Append(Value());
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsBool(int &index) const
		{
			return mRoot[index].IsBool();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::GetBool(int &index) const
		{
			return mRoot[index].GetBool();
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
			return mRoot[index].IsNumber();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsInt(int &index) const
		{
			return mRoot[index].IsInt();
		}

		//////////////////////////////////////////////////////////////////////////
		int Array::GetInt(int &index) const
		{
			return mRoot[index].GetInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddInt(const int &value)
		{
			mRoot.Append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsDouble(int &index) const
		{
			return mRoot[index].IsDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		double Array::GetDouble(int &index) const
		{
			return mRoot[index].GetDouble();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddDouble(const double &value)
		{
			mRoot.Append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsUInt(int &index) const
		{
			return mRoot[index].IsUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		unsigned int Array::GetUInt(int &index) const
		{
			return mRoot[index].GetUInt();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddUInt(const unsigned int &value)
		{
			mRoot.Append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsInt64(int &index) const
		{
			return mRoot[index].IsInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		Int64 Array::GetInt64(int &index) const
		{
			return mRoot[index].GetInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddInt64(const Int64 &value)
		{
			mRoot.Append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsUInt64(int &index) const
		{
			return mRoot[index].IsUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		UInt64 Array::GetUInt64(int &index) const
		{
			return mRoot[index].GetUInt64();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddUInt64(const UInt64 &value)
		{
			mRoot.Append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsFloat(int &index) const
		{
			return mRoot[index].IsFloat();
		}

		//////////////////////////////////////////////////////////////////////////
		float Array::GetFloat(int &index) const
		{
			return mRoot[index].GetFloat();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddFloat(const float &value)
		{
			mRoot.Append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsString(int &index) const
		{
			return mRoot[index].IsString();
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string Array::GetString(int &index) const
		{
			return mRoot[index].GetString();
		}

		//////////////////////////////////////////////////////////////////////////
		void Array::AddString(const std::string &value)
		{
			mRoot.Append(value);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsArray(int &index) const
		{
			return mRoot[index].IsArray();
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
			mRoot.Append(Array.GetJSONRoot());
		}

		//////////////////////////////////////////////////////////////////////////
		bool Array::IsObject(int &index) const
		{
			return mRoot[index].IsObject();
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
			mRoot.Append(Object.GetJSONRoot());
		}
	}    
}