/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
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

#include <trUtil/TypeConfig.h>


namespace trUtil
{
/// OS Defines
#if defined (WIN32) || defined (_WIN32) || defined (__WIN32__)
    #define TR_WIN

    #if _MSC_VER < 1900
        #ifndef snprintf
            #define snprintf _snprintf
        #endif
        #ifndef stricmp
            #define stricmp _stricmp
        #endif
    #endif    

#elif defined(__APPLE__)
    #define TR_APPLE
#else
    #define TR_LINUX
#endif
}