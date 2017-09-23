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

#pragma once

#include <json/json.h>

namespace trUtil
{
	namespace JSON
	{
		typedef Json::Value Value;
		typedef Json::Value::UInt UInt;
		typedef Json::Value::Int Int;
		typedef Json::Value::UInt64 UInt64;
		typedef Json::Value::Int64 Int64;
		typedef Json::Value::LargestInt LargestInt;
		typedef Json::Value::LargestUInt LargestUInt;
		typedef Json::Value::ArrayIndex ArrayIndex;
	}
}