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


#ifndef vrsTextColor_H
#define vrsTextColor_H



#include "export.h"

namespace vrsUtil
{
	enum VRS_UTIL_EXPORT TXT_COLOR {
		BLUE	=	0,
		GREEN	=	1,
		RED		=	2,
		YELLOW	=	3,
		WHITE	=	4,
		CYAN	=	5,
		MAGENTA	=	6,
		GRAY	=	7
	};

	// Changes Text color in the consol window....
	void VRS_UTIL_EXPORT SetTxtColor(TXT_COLOR TextColor);

}

#endif // vrsTextColor_H