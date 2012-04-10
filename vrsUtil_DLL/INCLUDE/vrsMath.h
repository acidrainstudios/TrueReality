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