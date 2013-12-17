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


#ifndef Math_CPP
#define Math_CPP

#include <math.h>

#include <dtCore/refptr.h>
#include <dtCore/uniqueid.h>

#include <trUtil\Math.h>

namespace trUtil
{

	inline void SinCos(double x, double & SinVal, double & CosVal)
	{
		SinVal=sin(x);
		CosVal=cos(x);
	}

	inline double Deg2Rad(double Degree)
	{
		return osg::DegreesToRadians(Degree);
	}

	inline float Deg2Rad(float Degree)
	{
		return osg::DegreesToRadians(Degree);
	}

	inline double CheckState(double State)
	{
		if (State == 0)
			return 0;
		else if(State < 0)
			return -1;
		else
			return 1;
	}

}

#endif // Math_CPP