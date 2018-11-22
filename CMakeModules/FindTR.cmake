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
# @author Maxim Serebrennik


# ********************************************************************************
# Finds the True Reality libraries. **********************************************
# ********************************************************************************
# ********************************************************************************
# Creates and sets variables to use through out cmake **************************** 
# ********************************************************************************
# TR_FOUND - Defined if the dependency is found **********************************
# ********************************************************************************
# TR_INCLUDE_DIR - Holds the paths to the TR Headers *****************************
# ********************************************************************************
# TR_APP_INCLUDE_DIR     - Holds the path to library headers *********************
# TR_BASE_INCLUDE_DIR    - Holds the path to library headers *********************
# TR_CORE_INCLUDE_DIR    - Holds the path to library headers *********************
# TR_MANAGER_INCLUDE_DIR - Holds the path to library headers *********************
# TR_SG_INCLUDE_DIR      - Holds the path to library headers *********************
# TR_UTIL_INCLUDE_DIR    - Holds the path to library headers *********************
# ********************************************************************************
# TR_APP_LIBRARY           - Holds the path to the trApp library *****************
# TR_APP_DEBUG_LIBRARY     - Holds the path to the trApp debug library ***********
# TR_BASE_LIBRARY          - Holds the path to the trBase library ****************
# TR_BASE_DEBUG_LIBRARY    - Holds the path to the trBase debug library **********
# TR_CORE_LIBRARY          - Holds the path to the trCore library ****************
# TR_CORE_DEBUG_LIBRARY    - Holds the path to the trCore debug library **********
# TR_MANAGER_LIBRARY       - Holds the path to the trManager library *************
# TR_MANAGER_DEBUG_LIBRARY - Holds the path to the trManager debug library *******
# TR_SG_LIBRARY            - Holds the path to the trSG library ******************
# TR_SG_DEBUG_LIBRARY      - Holds the path to the trSG debug library ************
# TR_UTIL_LIBRARY          - Holds the path to the trUtil library ****************
# TR_UTIL_DEBUG_LIBRARY    - Holds the path to the trUtil debug library **********
# ********************************************************************************
# TR_APP_LIBRARY_FOUND           - Defined if the library is found ***************
# TR_APP_DEBUG_LIBRARY_FOUND     - Defined if the library is found ***************
# TR_BASE_LIBRARY_FOUND          - Defined if the library is found ***************
# TR_BASE_DEBUG_LIBRARY_FOUND    - Defined if the library is found ***************
# TR_CORE_LIBRARY_FOUND          - Defined if the library is found ***************
# TR_CORE_DEBUG_LIBRARY_FOUND    - Defined if the library is found ***************
# TR_MANAGER_LIBRARY_FOUND       - Defined if the library is found ***************
# TR_MANAGER_DEBUG_LIBRARY_FOUND - Defined if the library is found ***************
# TR_SG_LIBRARY_FOUND            - Defined if the library is found ***************
# TR_SG_DEBUG_LIBRARY_FOUND      - Defined if the library is found ***************
# TR_UTIL_LIBRARY_FOUND          - Defined if the library is found ***************
# TR_UTIL_DEBUG_LIBRARY_FOUND    - Defined if the library is found ***************
# ********************************************************************************

SET (DEPENDENCY "TR")
# ********************************************************************************
# Macro to find header and lib directories ***************************************
# Example 1: TR_FIND_LIB(UTIL_DEBUG trUtil "YES") ********************************
# Searches for trUtild library and sets TR_UTIL_DEBUG_LIBRARY_FOUND **************
# Example 2: TR_FIND_LIB(UTIL trUtil "NO") ***************************************
# Searches for trUtil library and sets TR_UTIL_LIBRARY_FOUND *********************
# ********************************************************************************
MACRO (TR_FIND_LIB VARNAME MYLIBRARYNAME DEBUG)
    FIND_PATH(${DEPENDENCY}_${VARNAME}_INCLUDE_DIR ${MYLIBRARYNAME}/Export.h
        HINTS
        $ENV{TR_INC}
        $ENV{TR_ROOT}/include
        $ENV{TR_ROOT}
        PATHS
        /usr/include
        /usr/local/include
        /opt/include
        /opt/local/include
        ~/Library/Frameworks
        /Library/Frameworks
    )
    MARK_AS_ADVANCED (${DEPENDENCY}_${VARNAME}_INCLUDE_DIR)

    IF (${DEBUG})
        SET (LIB_NAME ${MYLIBRARYNAME}d)
    ELSE ()
        SET (LIB_NAME ${MYLIBRARYNAME})
    ENDIF ()

    FIND_LIBRARY(${DEPENDENCY}_${VARNAME}_LIBRARY
        NAMES ${LIB_NAME}
        HINTS
        $ENV{TR_LIB}
        $ENV{TR_ROOT}/lib
        $ENV{TR_ROOT}
        PATHS
        /usr/lib64
        /usr/lib
        /usr/local/lib64
        /usr/local/lib
        /opt/lib64
        /opt/lib
        /opt/local/lib64
        /opt/local/lib
        ~/Library/Frameworks
        /Library/Frameworks
    )
    MARK_AS_ADVANCED (${DEPENDENCY}_${VARNAME}_LIBRARY)

    IF (${DEPENDENCY}_${VARNAME}_LIBRARY AND ${DEPENDENCY}_${VARNAME}_INCLUDE_DIR)
        SET (${DEPENDENCY}_${VARNAME}_FOUND "YES")
    ENDIF ()
ENDMACRO ()

# ********************************************************************************
# Macro to find header and lib directories for both debug and release libs *******
# Example: TR_FIND_LIBRARY(UTIL trUtil)  *****************************************
# Searches for trUtild library, if found sets TR_UTIL_DEBUG_LIBRARY_FOUND and ****
# for trUtil library setting TR_UTIL_LIBRARY_FOUND *******************************
# ********************************************************************************
MACRO (TR_FIND_LIBRARY VARNAME MYLIBRARYNAME)
    TR_FIND_LIB(${VARNAME} ${MYLIBRARYNAME} "NO")
    TR_FIND_LIB(${VARNAME}_DEBUG ${MYLIBRARYNAME} "YES")
ENDMACRO ()

# Find the individual libraries
TR_FIND_LIBRARY(APP     trApp)
TR_FIND_LIBRARY(BASE    trBase)
TR_FIND_LIBRARY(CORE    trCore)
TR_FIND_LIBRARY(MANAGER trManager)       
TR_FIND_LIBRARY(SG      trSG)
TR_FIND_LIBRARY(UTIL    trUtil)