# True Reality Open Source Game and Simulation Engine
# Copyright � 2018 Acid Rain Studios LLC
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
# Author: Alexander Koufos

# ********************************************************************************
# Finds the OpenVR libraries *****************************************************
# ********************************************************************************
# ********************************************************************************
# Creates and sets variables to use through out cmake ****************************
# OpenVR_INCLUDE_DIR - Holds the path to the OpenVR Headers *************
# OpenVR_LIBRARY - Holds the path to the OpenVR library ***********************
# ********************************************************************************
# OpenVR_FOUND - Defined if the dependency is found **************************
# ********************************************************************************

SET(DEPENDENCY "OpenVR")

# Finds the include files necessary for compilation
FIND_PATH (${DEPENDENCY}_INCLUDE_DIR openvr/openvr.h
    HINTS
    $ENV{OPENVR_INC}
    $ENV{OPENVR_ROOT}/include
    $ENV{OPENVR_ROOT}/inc
    $ENV{OPENVR_ROOT}
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
        $ENV{OPENVR_LIB}
        $ENV{OPENVR_ROOT}/lib64
        $ENV{OPENVR_ROOT}/lib
        $ENV{OPENVR_ROOT}
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
    # Locates all OpenVR release libraries
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY openvr_api)
ENDIF (TR_BUILD_WITH_RELEASE)

IF (TR_BUILD_WITH_DEBUG)
    # Locates all OpenVR debug libraries
    FIND_DEPENDENCY_LIBRARY (${DEPENDENCY}_LIBRARY_DEBUG openvr_apid)
ENDIF (TR_BUILD_WITH_DEBUG)

SET (${DEPENDENCY}_FOUND "NO")
IF (${DEPENDENCY}_INCLUDE_DIR)
    SET (${DEPENDENCY}_FOUND "YES")
ENDIF (${DEPENDENCY}_INCLUDE_DIR)
