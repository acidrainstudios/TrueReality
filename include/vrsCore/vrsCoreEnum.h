/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////

#ifndef COREDLL_ENUM_H
#define COREDLL_ENUM_H

#pragma warning( disable: 4251 )

#include "export.h"

#include <string>

#include <dtUtil/Enumeration.h>

namespace vrsCore
{
	////////////////////////////////////////////////////////////////////////////////
	//Sets the Render Bin Order, 0-100(although not limited to thoes numbers) 0 gets
	//rendered first and ends up at the back of the scene. 100 gets rendered last 
	//and ends up at the front of the scene. 50 is used as the default middle
	enum CORE_EXPORT RENDER_BIN_ORDER 
	{
		FIRST_RENDER_BIN = 0,
		DEFAULT_RENDER_BIN = 50,
		LAST_RENDER_BIN = 100
	};
	////////////////////////////////////////////////////////////////////////////////
	//Determins how the render bins are sorted internaly. By Depth, By State Complexity, 
	//or just inherited from the parent node. If the type is inherited, the bin number
	//is ignored and also inherited from parent. 
	class CORE_EXPORT RENDER_BIN_TYPE : public dtUtil::Enumeration
	{
		DECLARE_ENUM(RENDER_BIN_TYPE)

	public:
		static RENDER_BIN_TYPE INHERIT_BIN;
		static RENDER_BIN_TYPE DEPTH_SORTED_BIN;
		static RENDER_BIN_TYPE STATE_SORTED_BIN;
		RENDER_BIN_TYPE(const std::string& name);
	};
	////////////////////////////////////////////////////////////////////////////////
}

#endif //COREDLL_ENUM_H