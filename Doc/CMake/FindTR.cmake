# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.
#
# @author Acid Rain Studios LLC


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
        SET (LIB_NAME ${MYLIBRARYNAME}-d)
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
        SET (${DEPENDENCY}_${VARNAME}_LIBRARY_FOUND "YES")
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

# Sets TR_FOUND flag
SET (${DEPENDENCY}_FOUND "NO")
IF (${DEPENDENCY}_APP_LIBRARY_FOUND AND ${DEPENDENCY}_BASE_LIBRARY_FOUND AND ${DEPENDENCY}_CORE_LIBRARY_FOUND AND ${DEPENDENCY}_MANAGER_LIBRARY_FOUND AND ${DEPENDENCY}_SG_LIBRARY_FOUND AND ${DEPENDENCY}_UTIL_LIBRARY_FOUND )
    
    # All the library header folders should be in the same place, so we can just use the Core libraries path
    SET(${DEPENDENCY}_INCLUDE_DIR ${${DEPENDENCY}_CORE_INCLUDE_DIR})   
    SET (${DEPENDENCY}_FOUND "YES")
ENDIF ()