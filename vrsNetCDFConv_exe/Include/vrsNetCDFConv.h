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


#ifndef VRS_VRSNETCDFCONV_H
#define VRS_VRSNETCDFCONV_H

#include "..\\..\\vrsUFVG_dll\Include\NetCDFReader.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include <math.h>


class vrsNetCDFConv
{
public:

	vrsNetCDFConv(void);			//Constructor

									//Converts the netCDF file
	void Convert(std::string InFilePath, std::string OutFilePath);


	~vrsNetCDFConv(void){};			//Destructor

protected:

private:

	//NetCDFReader mReader;			//Reads Data from the datafile

	
};




#endif //VRS_VRSNETCDFCONVR_H