/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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


#ifndef Logo_CPP
#define Logo_CPP

#include <iostream>

#include <trUtil\ConsoleTextColor.h>
#include <trUtil\Logo.h>

namespace trUtil
{
	void Logo( void )
	{

		#ifdef _WIN32
			#ifndef _DEBUG
			system("cls");
			#endif
		#endif
		
		trUtil::Console::ConsoleTextColor(trUtil::Console::BLUE);
		std::cout << "    ***********************************************************************\n " << std::endl;
		trUtil::Console::ConsoleTextColor(trUtil::Console::RED);
		std::cout << "                        ---------------------------- " << std::endl;
		trUtil::Console::ConsoleTextColor(trUtil::Console::YELLOW);
		std::cout << "                       Virtual Reality Simulation Lab\n " << std::endl;
		std::cout << "                            Version - ";
		

		int len = 0; 
		/*while (STRPRODUCTVER[len] != '\0')
		{
			if(STRPRODUCTVER[len]==',')
			{
				std::cout << ".";
			}
			else
				std::cout << STRPRODUCTVER[len];

			len++;
			
		}*/
		std::cout << std::endl;
		trUtil::Console::ConsoleTextColor(trUtil::Console::RED);
		std::cout << "                        ----------------------------\n\n\n " << std::endl;
		trUtil::Console::ConsoleTextColor(trUtil::Console::BLUE);
		std::cout << "        VR-Sim Lab ";
		
		len = 0; int dot = 0;
		/*while (STRPRODUCTVER[len] != '\0')
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
			
		}*/
		
		std::cout << " Is A Collection Of Simulation Modules Developed" << std::endl;
		std::cout << "           and Owned By Maxim Serebrennik for His Private and Public" << std::endl;
		std::cout << "       Projects. Some Modules Are Commercially Licensed and Some Are LGPL.\n\n" << std::endl;
		std::cout << "                     VR-Sim Lab Runs On Delta3D Game Engine\n\n" << std::endl;
		std::cout << "               For more information, contact Maxim Serebrennik at" << std::endl;
		std::cout << "                              MaximSter@gmail.com\n " << std::endl;
		std::cout << "    ***********************************************************************\n\n\n " << std::endl;
		trUtil::Console::ConsoleTextColor(trUtil::Console::GRAY);

	}
}

#endif // Logo_CPP