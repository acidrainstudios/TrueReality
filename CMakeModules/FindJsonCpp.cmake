# True Reality Open Source Game and Simulation Engine
# Copyright � 2019 Acid Rain Studios LLC
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
# Finds the JsonCpp libaries. ****************************************************
# ********************************************************************************
# ********************************************************************************
# Creates and sets variables to use through out cmake ****************************
# JsonCpp_INCLUDE_DIR - Holds the path to the JsonCpp Headers ********************
# JsonCpp_LIBRARY - Holds the path to the JsonCpp library ************************
# JsonCpp_LIBRARY_DEBUG - Holds the path to the JsonCpp Debug library ************
# ********************************************************************************
# JsonCpp_FOUND - Defined if the dependency is found *****************************
# ********************************************************************************

SET (DEPENDENCY "JsonCpp")

# Finds the include files necessary for compilation
FIND_PATH (${DEPENDENCY}_INCLUDE_DIR json/json.h
    HINTS
    $ENV{JSON_INC}
    $ENV{JSON_ROOT}/include
    $ENV{JSON_ROOT}
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
        $ENV{JSON_LIB}
        $ENV{JSON_ROOT}/lib
        $ENV{JSON_ROOT}
        $ENV{TR_LIB}
        $ENV{TR_ROOT}/Ext/lib
        $ENV{TR_ROOT}/Ext
        $ENV{TR_ROOT}/lib
        $ENV{TR_ROOT}
        PATHS
        /usr/lib
        /usr/local/lib
        ~/Library/Frameworks
        /Library/Frameworks
    )
    MARK_AS_ADVANCED (${MYLIBRARY})
ENDMACRO ()

IF (TR_BUILD_WITH_RELEASE)
    # Locates all JSON_CPP release libraries
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY jsoncpp)
ENDIF ()

IF (TR_BUILD_WITH_DEBUG)
    # Locates all JSON_CPP debug libraries
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY_DEBUG jsoncppd)
ENDIF ()

SET (${DEPENDENCY}_FOUND "NO")
IF ((${DEPENDENCY}_LIBRARY OR ${DEPENDENCY}_LIBRARY_DEBUG) AND ${DEPENDENCY}_INCLUDE_DIR)
    SET (${DEPENDENCY}_FOUND "YES")
ENDIF ()
