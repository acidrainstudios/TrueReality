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


#ifndef vrsLogo_CPP
#define vrsLogo_CPP

#include <iostream>

#include "..\\..\\vrsVersionCTR\ProdVerNo.h"
#include <vrsUtil\vrsTextColor.h>
#include <vrsUtil\vrsLogo.h>

namespace vrsUtil
{
	void Logo( void )
	{

		#ifdef _WIN32
			#ifndef _DEBUG
			system("cls");
			#endif
		#endif
		
		vrsUtil::SetTxtColor(vrsUtil::BLUE);
		std::cout << "    ***********************************************************************\n " << std::endl;
		vrsUtil::SetTxtColor(vrsUtil::RED);
		std::cout << "                        ---------------------------- " << std::endl;
		vrsUtil::SetTxtColor(vrsUtil::YELLOW);
		std::cout << "                       Virtual Reality Simulation Lab\n " << std::endl;
		std::cout << "                            Version - ";
		

		int len = 0; 
		while (STRPRODUCTVER[len] != '\0')
		{
			if(STRPRODUCTVER[len]==',')
			{
				std::cout << ".";
			}
			else
				std::cout << STRPRODUCTVER[len];

			len++;
			
		}
		std::cout << std::endl;
		vrsUtil::SetTxtColor(vrsUtil::RED);
		std::cout << "                        ----------------------------\n\n\n " << std::endl;
		vrsUtil::SetTxtColor(vrsUtil::BLUE);
		std::cout << "        VR-Sim Lab ";
		
		len = 0; int dot = 0;
		while (STRPRODUCTVER[len] != '\0')
		{
			if(STRPRODUCTVER[len]==',')
			{
				if(dot==2)			
					break;
				else
					std::cout << ".";
					dot++;
			}
			else
				std::cout << STRPRODUCTVER[len];

			len++;
			
		}
		
		std::cout << " Is A Collection Of Simulation Modules Developed" << std::endl;
		std::cout << "           and Owned By Maxim Serebrennik for His Private and Public" << std::endl;
		std::cout << "       Projects. Some Modules Are Commercially Licensed and Some Are LGPL.\n\n" << std::endl;
		std::cout << "                     VR-Sim Lab Runs On Delta3D Game Engine\n\n" << std::endl;
		std::cout << "               For more information, contact Maxim Serebrennik at" << std::endl;
		std::cout << "                              MaximSter@gmail.com\n " << std::endl;
		std::cout << "    ***********************************************************************\n\n\n " << std::endl;
		vrsUtil::SetTxtColor(vrsUtil::GRAY);

	}
}

#endif // vrsLogo_CPP