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


#ifndef vrsMath_CPP
#define vrsMath_CPP

#include <math.h>

#include <dtCore/refptr.h>
#include <dtCore/uniqueid.h>

#include <vrsUtil\vrsMath.h>

namespace vrsUtil
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

#endif // vrsMath_CPP