# True Reality Open Source Game and Simulation Engine
# Copyright © 2018 Acid Rain Studios LLC
#
# This library is free software; you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation; either version 3.0 of the License, or (at your option)
# any later version.
#
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# Author: Maxim Serebrennik

# ********************************************************************************
# Finds the Google Test libaries. ************************************************
# ********************************************************************************
# ********************************************************************************
# Creates and sets variables to use through out cmake ****************************
# GoogleTest_INCLUDE_DIR - Holds the path to the Google Test Headers *************
# GoogleTest_LIBRARY - Holds the path to the gtest library ***********************
# GoogleTest_LIBRARY_MAIN - Holds the path to the gtest_main library *************
# GoogleTest_LIBRARY_DEBUG - Holds the path to the gtest Debug library ***********
# GoogleTest_LIBRARY_MAIN_DEBUG - Holds the path to the gtest_main debug library**
# ********************************************************************************
# GoogleTest_FOUND - Defined if the dependency is found **************************
# ********************************************************************************

SET(DEPENDENCY "GoogleTest")

# Finds the include files necessary for compilation
FIND_PATH (${DEPENDENCY}_INCLUDE_DIR gtest/gtest.h    
    HINTS
    $ENV{GOOGLETEST_INC}
    $ENV{GOOGLETEST_ROOT}/include
    $ENV{GOOGLETEST_ROOT}/inc
    $ENV{GOOGLETEST_ROOT}
    $ENV{TR_INC}
    $ENV{TR_ROOT}/Ext/include
    $ENV{TR_ROOT}/Ext
    $ENV{TR_ROOT}/include
    $ENV{TR_ROOT}
    PATHS
    /usr/include
    /usr/local/include
    ~/Library/Frameworks
    /Library/Frameworks
)
MARK_AS_ADVANCED (${DEPENDENCY}_INCLUDE_DIR)

MACRO (FIND_DEPENDENCY_LIBRARY MYLIBRARY MYLIBRARYNAME)
    # Finds the library files necessary for compilation
    FIND_LIBRARY (${MYLIBRARY}
        NAMES ${MYLIBRARYNAME}
        HINTS
        $ENV{GOOGLETEST_LIB}
        $ENV{GOOGLETEST_ROOT}/lib64
        $ENV{GOOGLETEST_ROOT}/lib
        $ENV{GOOGLETEST_ROOT}
        $ENV{TR_ROOT}/Ext/lib64
        $ENV{TR_ROOT}/Ext/lib
        $ENV{TR_ROOT}/Ext
        $ENV{TR_LIB}
        $ENV{TR_ROOT}/lib64
        $ENV{TR_ROOT}/lib
        $ENV{TR_ROOT}
        PATHS
        /usr/lib64
        /usr/lib
        /usr/local/lib64
        /usr/local/lib
        ~/Library/Frameworks
        /Library/Frameworks
    )
    MARK_AS_ADVANCED (${MYLIBRARY})
ENDMACRO(FIND_DEPENDENCY_LIBRARY MYLIBRARY MYLIBRARYNAME)

IF (TR_BUILD_WITH_RELEASE)
    # Locates all GOOGLE_TEST release libraries
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY gtest)
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY_MAIN gtest_main)
ENDIF (TR_BUILD_WITH_RELEASE)

IF (TR_BUILD_WITH_DEBUG)
    # Locates all GOOGLE_TEST debug libraries (in this case there are no debug libs)
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY_DEBUG gtestd)
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY_MAIN_DEBUG gtest_maind)
ENDIF (TR_BUILD_WITH_DEBUG)

SET (${DEPENDENCY}_FOUND "NO")
IF (${DEPENDENCY}_INCLUDE_DIR)
    SET (${DEPENDENCY}_FOUND "YES")
ENDIF (${DEPENDENCY}_INCLUDE_DIR)
