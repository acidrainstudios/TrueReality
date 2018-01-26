/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
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
#include <trUtil/Console/Logo.h>

#include <trUtil/PlatformMacros.h>
#include <trUtil/VersionUtil.h>
#include <trUtil/Console/TextColor.h>

#include <iostream>

namespace trUtil
{
	namespace Console
	{
		void Logo(void)
		{
            trUtil::VersionUtil ver;

#ifdef TR_WIN
    #ifndef _DEBUG
			    system("cls");
    #endif
#elif TR_LINUX
    #ifndef _DEBUG
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n " << std::endl;
    #endif
#endif

            Console::TextColor(TXT_COLOR::BRIGHT_BLUE);
			std::cout << "    ***********************************************************************\n " << std::endl;
            Console::TextColor(TXT_COLOR::BRIGHT_RED);
			std::cout << "                        ---------------------------- " << std::endl;
            Console::TextColor(TXT_COLOR::BRIGHT_YELLOW);
			std::cout << "                                True Reality\n " << std::endl;
			std::cout << "                            Version - " << ver.GetVersionString() << std::endl;
            Console::TextColor(TXT_COLOR::BRIGHT_RED);
			std::cout << "                        ----------------------------\n\n\n " << std::endl;
            Console::TextColor(TXT_COLOR::BRIGHT_BLUE);

            
            std::cout << "       True Reality " << ver.GetMajorVersion() << "." << ver.GetMinorVersion();
			std::cout << " is an Open Source SDK of Virtual Reality" << std::endl;
			std::cout << "       Simulation Modules created and Copyright by Acid Rain Studios LLC" << std::endl;
			std::cout << "       for product development, testing, and sale. Some modules are" << std::endl;
			std::cout << "       commercially licensed and some are LGPL.\n\n" << std::endl;
			std::cout << "               For more information, contact the developers at" << std::endl;
            std::cout << "                        AcidRainStudiosLLC@gmail.com\n" << std::endl;
			std::cout << "    ***********************************************************************\n\n\n " << std::endl;
            Console::TextColor(TXT_COLOR::DEFAULT);

		}
	}	
}

