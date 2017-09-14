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

#ifndef COREDLL_ENUM_H
#define COREDLL_ENUM_H

#pragma warning( disable: 4251 )

#include "export.h"

#include <string>

//#include <dtUtil/Enumeration.h>

namespace trCore
{
	//////////////////////////////////////////////////////////////////////////////////
	////Sets the Render Bin Order, 0-100(although not limited to thoes numbers) 0 gets
	////rendered first and ends up at the back of the scene. 100 gets rendered last 
	////and ends up at the front of the scene. 50 is used as the default middle
	//enum TR_CORE_EXPORT RENDER_BIN_ORDER 
	//{
	//	FIRST_RENDER_BIN = 0,
	//	DEFAULT_RENDER_BIN = 50,
	//	LAST_RENDER_BIN = 100
	//};
	//////////////////////////////////////////////////////////////////////////////////
	////Determins how the render bins are sorted internaly. By Depth, By State Complexity, 
	////or just inherited from the parent node. If the type is inherited, the bin number
	////is ignored and also inherited from parent. 
	//class TR_CORE_EXPORT RENDER_BIN_TYPE : public dtUtil::Enumeration
	//{
	//	DECLARE_ENUM(RENDER_BIN_TYPE)

	//public:
	//	static RENDER_BIN_TYPE INHERIT_BIN;
	//	static RENDER_BIN_TYPE DEPTH_SORTED_BIN;
	//	static RENDER_BIN_TYPE STATE_SORTED_BIN;
	//	RENDER_BIN_TYPE(const std::string& name);
	//};
	//////////////////////////////////////////////////////////////////////////////////
}

#endif //COREDLL_ENUM_H