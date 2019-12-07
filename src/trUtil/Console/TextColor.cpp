/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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
* @author Maxim Serebrennik
*/
#include <trUtil/Console/TextColor.h>


#if defined(_WIN32)
  #include <windows.h>
#endif 

#include <iostream>


namespace trUtil::Console
{
    //////////////////////////////////////////////////////////////////////////
    void TextColor(TXT_COLOR TextColor)
    {
#if defined(_WIN32)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get handle to standard output 
#endif

        switch (TextColor)
        {
        case BRIGHT_RED:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
#else
            std::cout << "\033[0;31m";
#endif //defined(_WIN32))
            break;
        case RED:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
#else
            std::cout << "\033[2;31m";
#endif
            break;
        case BRIGHT_GREEN:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#else
            std::cout << "\033[0;32m";
#endif
            break;
        case GREEN:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
#else
            std::cout << "\033[2;32m";
#endif
            break;
        case BRIGHT_BLUE:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#else
            std::cout << "\033[0;34m";
#endif
            break;
        case BLUE:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
#else
            std::cout << "\033[3;34m";
#endif
            break;
        case BRIGHT_YELLOW:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
#else
            std::cout << "\033[0;33m";
#endif
            break;
        case YELLOW:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
#else
            std::cout << "\033[2;33m";
#endif
            break;
        case WHITE:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
#else
            std::cout << "\033[0;37m";
#endif
            break;
        case BRIGHT_CYAN:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#else
            std::cout << "\033[0;36m";
#endif
            break;
        case CYAN:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
            std::cout << "\033[2;36m";
#endif
            break;
        case BRIGHT_MAGENTA:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#else
            std::cout << "\033[0;35m";
#endif
            break;
        case MAGENTA:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
#else
            std::cout << "\033[2;35m";
#endif
            break;
        case GRAY:
#if defined(_WIN32)
#else
            std::cout << "\033[2;37m";
            break;
#endif
        default:
#if defined(_WIN32)
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
#else
            std::cout << "\033[0m";
#endif
            break;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void PrintAllColors()
    {
        //Print a sample of colors on the screen
        TextColor(DEFAULT);          std::cout << "DEFAULT" << std::endl;
        TextColor(BRIGHT_RED);       std::cout << "BRIGHT_RED" << std::endl;
        TextColor(RED);              std::cout << "RED" << std::endl;
        TextColor(BRIGHT_GREEN);     std::cout << "BRIGHT_GREEN" << std::endl;
        TextColor(GREEN);            std::cout << "GREEN" << std::endl;
        TextColor(BRIGHT_BLUE);      std::cout << "BRIGHT_BLUE" << std::endl;
        TextColor(BLUE);             std::cout << "BLUE" << std::endl;
        TextColor(BRIGHT_YELLOW);    std::cout << "BRIGHT_YELLOW" << std::endl;
        TextColor(YELLOW);           std::cout << "YELLOW" << std::endl;
        TextColor(WHITE);            std::cout << "WHITE" << std::endl;
        TextColor(BRIGHT_CYAN);      std::cout << "BRIGHT_CYAN" << std::endl;
        TextColor(CYAN);             std::cout << "CYAN" << std::endl;
        TextColor(BRIGHT_MAGENTA);   std::cout << "BRIGHT_MAGENTA" << std::endl;
        TextColor(MAGENTA);          std::cout << "MAGENTA" << std::endl;
        TextColor(GRAY);             std::cout << "GRAY" << std::endl;


        //Change the color back to normal
        TextColor(DEFAULT);
            
    }
}