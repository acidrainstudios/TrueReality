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


#ifndef vrsMath_H
#define vrsMath_H


#include "export.h"

#include <osg/Math>

namespace vrsUtil
{	

	// Pi
	static const double	Pi = osg::PI;
	
	// 1/PI
	static const double ONE_OVER_PI = 1.0/Pi;

	// Pi/180
	static const double ONE80_OVER_PI = (180.0*ONE_OVER_PI);

	// Takes a Value X and outputs its Sin and Cos by reference
	void VRS_UTIL_EXPORT SinCos(double x, double & SinVal, double & CosVal);

	// Takes Degrees and converts them to Radians
	double VRS_UTIL_EXPORT Deg2Rad(double Degree);

	// Takes Degrees and converts them to Radians
	float VRS_UTIL_EXPORT Deg2Rad(float Degree);

	// Checks if State is = to 0, less then 0 or greater, and outputs -1, 0, 1
	double VRS_UTIL_EXPORT CheckState(double State);

}


#endif // vrsMath_H