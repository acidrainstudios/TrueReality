/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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
#pragma once

#include <trUtil/Export.h>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::Console
{
    /**
        * @enum    TXT_COLOR
        *
        * @brief   Color Modes for the Console Window
        *
        * @author Maxim Serebrennik
        */
    enum TR_UTIL_EXPORT TXT_COLOR
    {
        DEFAULT,
        BRIGHT_RED,
        RED,
        BRIGHT_GREEN,
        GREEN,
        BRIGHT_BLUE,
        BLUE,
        BRIGHT_YELLOW,
        YELLOW,
        WHITE,
        BRIGHT_CYAN,
        CYAN,
        BRIGHT_MAGENTA,
        MAGENTA,
        GRAY
    };

    /**
        * @fn  void TextColor(TXT_COLOR TextColor);
        *
        * @brief   Changes Text color in the console window....
        *
        * @author Maxim Serebrennik
        *
        * @param   TextColor   The text color.
        */
    void TR_UTIL_EXPORT TextColor(TXT_COLOR TextColor);

    /**
        * @fn  void PrintAllColors();
        *
        * @brief   Prints an example of all available colors This is usually used for testing and
        *          development.
        *
        * @author Maxim Serebrennik
        */
    void TR_UTIL_EXPORT PrintAllColors();
}