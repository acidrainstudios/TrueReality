/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owner of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* This software was developed by Maxim Serebrennik for various projects he worked on. 
* For more information e-mail him at MaximSter@gmail.com
*
* @author Maxim Serebrennik
*////////////////////////////////////////////////////////////////////////////////


#ifndef Main_CPP
#define Main_CPP

#include "..\\Include\vrsNetCDFConv.h"


#include <iostream>


void ShowUsageAndExit()
{
	std::cerr << "\nConverts Naval NetCDF File to vrsUFPG Data\n\n";
	std::cerr << "Usage: vrsNetCDFConv.exe <Input File Path> <Output File Path>\n";
	std::cerr << "   Ex: vrsNetCDFConv Data/nyhops.cdf Data/NetCDF \n";

	exit(0);
}

void main(int argc, char** argv)
{

	vrsNetCDFConv netCDF;

	if(argc<3 || argc>3)
	{
		ShowUsageAndExit();
	}
	else
	{
		netCDF.Convert(argv[1], argv[2]);
	}
	//netCDF.Convert("Data/nyhops.cdf", "Data/NetCDF");

}

#endif // Main_CPP