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


#ifndef vrsTextColor_CPP
#define vrsTextColor_CPP

#include "..\\Include\vrsTextColor.h"

#if defined(_WIN32)

#include <windows.h>



namespace vrsUtil
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