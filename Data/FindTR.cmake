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
        $ENV{TR_ROOT}/build/include
        $ENV{TR_ROOT}
        PATHS
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}/include
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*/include
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*
        C:/Program Files/TrueReality-*/include
        C:/Program Files/TrueReality-*
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}/include
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*/include
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*
        /usr/local/TrueReality-*/include
        /usr/local/TrueReality-*
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}.${${DEPENDENCY}_FIND_VERSION_TWEAK}/include
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}.${${DEPENDENCY}_FIND_VERSION_TWEAK}
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}*/include
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}*
        /usr/local/TrueReality/*/include
        /usr/local/TrueReality/*
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
        $ENV{TR_ROOT}/build/lib
        $ENV{TR_ROOT}
        PATHS
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}/lib
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*/lib
        C:/Program Files/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*
        C:/Program Files/TrueReality-*/lib
        C:/Program Files/TrueReality-*
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}/lib
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*/lib
        /usr/local/TrueReality-${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}*
        /usr/local/TrueReality-*/lib
        /usr/local/TrueReality-*
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}.${${DEPENDENCY}_FIND_VERSION_TWEAK}/lib
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}.${${DEPENDENCY}_FIND_VERSION_TWEAK}
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}*/lib
        /usr/local/TrueReality/${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}*
        /usr/local/TrueReality/*/lib
        /usr/local/TrueReality/*
        /usr/lib*
        /usr/local/lib*
        /opt/lib*
        /opt/local/lib*
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
    IF (TR_BUILD_WITH_RELEASE)
        TR_FIND_LIB(${VARNAME} ${MYLIBRARYNAME} "NO")
    ENDIF ()
    IF (TR_BUILD_WITH_DEBUG)
        TR_FIND_LIB(${VARNAME}_DEBUG ${MYLIBRARYNAME} "YES")
    ENDIF ()
    IF (NOT TR_BUILD_WITH_RELEASE AND NOT TR_BUILD_WITH_DEBUG)
        TR_FIND_LIB(${VARNAME} ${MYLIBRARYNAME} "NO")
        TR_FIND_LIB(${VARNAME}_DEBUG ${MYLIBRARYNAME} "YES")
    ENDIF ()
ENDMACRO ()

# Find the individual libraries
TR_FIND_LIBRARY(APP     trApp)
TR_FIND_LIBRARY(BASE    trBase)
TR_FIND_LIBRARY(CORE    trCore)
TR_FIND_LIBRARY(MANAGER trManager)
TR_FIND_LIBRARY(SG      trSG)
TR_FIND_LIBRARY(UTIL    trUtil)

# Sets TR_FOUND flag if we have TR of the version the user asked for
SET (${DEPENDENCY}_FOUND "NO")
IF ((${DEPENDENCY}_APP_LIBRARY_FOUND AND ${DEPENDENCY}_BASE_LIBRARY_FOUND AND ${DEPENDENCY}_CORE_LIBRARY_FOUND AND ${DEPENDENCY}_MANAGER_LIBRARY_FOUND AND ${DEPENDENCY}_SG_LIBRARY_FOUND AND ${DEPENDENCY}_UTIL_LIBRARY_FOUND) OR
     (${DEPENDENCY}_APP_DEBUG_LIBRARY_FOUND AND ${DEPENDENCY}_BASE_DEBUG_LIBRARY_FOUND AND ${DEPENDENCY}_CORE_DEBUG_LIBRARY_FOUND AND ${DEPENDENCY}_MANAGER_DEBUG_LIBRARY_FOUND AND ${DEPENDENCY}_SG_DEBUG_LIBRARY_FOUND AND ${DEPENDENCY}_UTIL_DEBUG_LIBRARY_FOUND))

    # All the library header folders should be in the same place, so we can just use the Core libraries path
    IF (TR_BUILD_WITH_RELEASE)
        SET(${DEPENDENCY}_INCLUDE_DIR ${${DEPENDENCY}_CORE_INCLUDE_DIR})
    ENDIF ()
    IF (TR_BUILD_WITH_DEBUG)
        SET(${DEPENDENCY}_INCLUDE_DIR ${${DEPENDENCY}_CORE_DEBUG_INCLUDE_DIR})
    ENDIF ()

    # Sets the path to the found TR Version file and reads it
    SET (TR_VERSION_FILE "${CMAKE_CURRENT_LIST_DIR}/Config/Version.trver")
    FILE (READ ${TR_VERSION_FILE} TR_VERSION_CONTENT)

    IF ("${TR_VERSION_CONTENT}" STREQUAL "")
        MESSAGE("Missing TR version file")
    ENDIF ()

    # Parse the version file
    STRING (REGEX MATCH "Build\" : ([0-9]+)" TR_VERSION_TWEAK ${TR_VERSION_CONTENT})
    STRING (REGEX MATCH "Major\" : ([0-9]+)" TR_VERSION_MAJOR ${TR_VERSION_CONTENT})
    STRING (REGEX MATCH "Minor\" : ([0-9]+)" TR_VERSION_MINOR ${TR_VERSION_CONTENT})
    STRING (REGEX MATCH "YYMM\" : \"([0-9]+)" TR_VERSION_PATCH ${TR_VERSION_CONTENT})
    STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_TWEAK ${TR_VERSION_TWEAK})
    STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_MAJOR ${TR_VERSION_MAJOR})
    STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_MINOR ${TR_VERSION_MINOR})
    STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_PATCH ${TR_VERSION_PATCH})

    SET (TR_VERSION ${TR_VERSION_MAJOR}.${TR_VERSION_MINOR}.${TR_VERSION_PATCH}.${TR_VERSION_TWEAK})
    SET (TR_SOVERSION ${TR_VERSION_MAJOR}${TR_VERSION_MINOR})

    MESSAGE (STATUS "True Reality Engine version is ${${DEPENDENCY}_VERSION}")

    # Check if we have the right version
    IF (${DEPENDENCY}_FIND_VERSION)
        IF ("${${DEPENDENCY}_VERSION}" VERSION_LESS "${${DEPENDENCY}_FIND_VERSION}")
            SET (${DEPENDENCY}_FOUND "NO")
            MESSAGE ("Detected version of ${DEPENDENCY} is too low. Requested version was ${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}.${${DEPENDENCY}_FIND_VERSION_TWEAK}")
        ELSEIF (${DEPENDENCY}_FIND_VERSION_EXACT AND NOT "$${DEPENDENCY}_VERSION}" VERSION_EQUAL "${${DEPENDENCY}_FIND_VERSION}")
            MESSAGE ("Detected version of ${DEPENDENCY} does not equal the requested. Requested version was ${${DEPENDENCY}_FIND_VERSION_MAJOR}.${${DEPENDENCY}_FIND_VERSION_MINOR}.${${DEPENDENCY}_FIND_VERSION_PATCH}.${${DEPENDENCY}_FIND_VERSION_TWEAK} and the detected one is ${${DEPENDENCY}_VERSION}")
            SET (${DEPENDENCY}_FOUND "NO")
        ELSE ()
            SET (${DEPENDENCY}_FOUND "YES")
        ENDIF ()
    ELSE ()
        SET (${DEPENDENCY}_FOUND "YES")
    ENDIF ()
ENDIF ()
