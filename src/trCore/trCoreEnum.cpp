/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2013
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

#ifndef COREDLL_ENUM_CPP
#define COREDLL_ENUM_CPP

#include <trCore\ActorObject.h>

namespace trCore
{
	////////////////////////////////////////////////////////////////////////////////
	IMPLEMENT_ENUM(RENDER_BIN_TYPE);
	
	RENDER_BIN_TYPE::RENDER_BIN_TYPE(const std::string& name)
	: dtUtil::Enumeration(name)
	{
		AddInstance(this);
	}

	RENDER_BIN_TYPE RENDER_BIN_TYPE::INHERIT_BIN("Inherit From Parent Node");
	RENDER_BIN_TYPE RENDER_BIN_TYPE::DEPTH_SORTED_BIN("DepthSortedBin");
	RENDER_BIN_TYPE RENDER_BIN_TYPE::STATE_SORTED_BIN("RenderBin");
	////////////////////////////////////////////////////////////////////////////////
}

#endif //COREDLL_ENUM_CPP