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

#ifndef COREDLL_ENUM_CPP
#define COREDLL_ENUM_CPP

#include <vrsCore\ActorObject.h>

namespace vrsCore
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