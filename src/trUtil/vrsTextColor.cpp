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


#ifndef vrsTextColor_CPP
#define vrsTextColor_CPP

#include <trUtil\vrsTextColor.h>

#if defined(_WIN32)

#include <windows.h>



namespace trUtil
{
	
	inline void SetTxtColor(TXT_COLOR TextColor)
	{
		#if defined(_WIN32)
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get handle to standard output 

		switch(TextColor)
		{
		case BLUE:
			SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case GREEN:
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case RED:
			SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		case YELLOW:
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN |FOREGROUND_RED  | FOREGROUND_INTENSITY);
			break;
		case WHITE:
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN |FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		case CYAN:
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case MAGENTA:
			SetConsoleTextAttribute(hConsole,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		default:
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN |FOREGROUND_BLUE | FOREGROUND_RED);
			break;
		}
		#endif //defined(_WIN32)
	}
	

}

#endif //defined(_WIN32)

#endif // vrsTextColor_CPP