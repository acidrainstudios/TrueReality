# True Reality Open Source Game and Simulation Engine
# Copyright © 2019 Acid Rain Studios LLC
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

# *****************************************************************************
# Adds subfolders in the True Reality build folder ****************************
# *****************************************************************************
MACRO (ADD_TR_SUBFOLDERS)
# Optional dependencies
    MESSAGE (STATUS "Creating Selected Source Folders")
    IF (TR_UTIL)
        ADD_SUBDIRECTORY (src/trUtil)
        SET (TR_UTIL_AVAILABLE "YES")
    ENDIF ()

    IF (TR_BASE)
        ADD_SUBDIRECTORY (src/trBase)
        SET (TR_BASE_AVAILABLE "YES")
    ENDIF ()

    IF (TR_SG)
        ADD_SUBDIRECTORY (src/trSG)
        SET (TR_SG_AVAILABLE "YES")
    ENDIF ()

    IF (TR_MANAGER)
        ADD_SUBDIRECTORY (src/trManager)
        SET (TR_MANAGER_AVAILABLE "YES")
    ENDIF ()

    IF (TR_CORE)
        ADD_SUBDIRECTORY (src/trCore)
        SET (TR_CORE_AVAILABLE "YES")
    ENDIF ()

    IF (TR_APP)
        ADD_SUBDIRECTORY (src/trApp)
        SET (TR_APP_AVAILABLE "YES")
    ENDIF ()

    IF (TR_START)
        ADD_SUBDIRECTORY (src/trStart)
        SET (TR_START_AVAILABLE "YES")
    ENDIF ()

# Utilities folders
    MESSAGE (STATUS "Creating Selected Utility Folders")
    IF (TR_VERSION_UTIL)
        ADD_SUBDIRECTORY (src/trVersion)
        SET (TR_VERSION_UTIL_AVAILABLE "YES")
    ENDIF ()

# Examples folders
    MESSAGE (STATUS "Creating Selected Example Folders")

    IF (EXAMPLES_ACTORS)
        ADD_SUBDIRECTORY (Examples/Actors)
        SET (EXAMPLES_ACTORS_AVAILABLE "YES")
    ENDIF ()

    IF (EXAMPLES_ACTOR_MODULES)
        ADD_SUBDIRECTORY (Examples/ActorModules)
        SET (EXAMPLES_ACTOR_MODULES_AVAILABLE "YES")
    ENDIF ()

    IF (EXAMPLES_DIRECTOR)
        ADD_SUBDIRECTORY (Examples/Director)
        SET (EXAMPLES_DIRECTOR_AVAILABLE "YES")
    ENDIF ()

    IF (EXAMPLES_JSON)
        ADD_SUBDIRECTORY (Examples/Json)
        SET (EXAMPLES_JSON_AVAILABLE "YES")
    ENDIF ()

    IF (EXAMPLES_LOGGING)
        ADD_SUBDIRECTORY (Examples/Logging)
        SET (EXAMPLES_LOGGING_AVAILABLE "YES")
    ENDIF ()

 # Unit Test Folders
    MESSAGE (STATUS "Creating Selected Tests Folders")

    IF (TESTS_TR_UTIL)
        ADD_SUBDIRECTORY (Tests/TrUtil)
        SET (TESTS_TR_UTIL_AVAILABLE "YES")
    ENDIF ()

    IF (TESTS_TR_BASE)
        ADD_SUBDIRECTORY (Tests/TrBase)
        SET (TESTS_TR_BASE_AVAILABLE "YES")
    ENDIF ()

    IF (TESTS_TR_MANAGER)
        ADD_SUBDIRECTORY (Tests/TrManager)
        SET (TESTS_TR_MANAGER_AVAILABLE "YES")
    ENDIF ()
ENDMACRO ()

# *****************************************************************************
# Attempts to find a specified dependency *************************************
# *****************************************************************************
MACRO (TR_DETECT_DEPENDENCY arg)
    MESSAGE (STATUS "Detecting ${arg}...")
    FIND_PACKAGE (${arg} ${ARGV1} REQUIRED)
    IF (${arg}_FOUND)
        MESSAGE (STATUS "Found ${arg}!")
        INCLUDE_DIRECTORIES(${${arg}_INCLUDE_DIR})
    ELSE ()
        MESSAGE ("${arg} not found!")
    ENDIF ()
ENDMACRO ()

# *****************************************************************************
# Attempts to find out if the generator system can support ********************
# multi config builds, and sets build options appropriately. ******************
# *****************************************************************************
MACRO (TR_BUILD_TYPE_OPTIONS)
    # Sets Available Build Types
    IF ("MinSizeRel" IN_LIST CMAKE_CONFIGURATION_TYPES)
        SET (CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "TrueReality multi-config types" FORCE)
    ELSEIF (NOT "Debug" IN_LIST CMAKE_CONFIGURATION_TYPES AND NOT "Release" IN_LIST CMAKE_CONFIGURATION_TYPES AND
        NOT "RelWithDebInfo" IN_LIST CMAKE_CONFIGURATION_TYPES)
        SET (CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "TrueReality multi-config types" FORCE)
    ENDIF ()

    IF (NOT CMAKE_BUILD_TYPE STREQUAL "Release" AND NOT CMAKE_BUILD_TYPE STREQUAL "Debug" AND NOT CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        SET (CMAKE_BUILD_TYPE "Release" CACHE STRING "TrueReality default build type" FORCE)
    ENDIF ()
    SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})

    # Configures what builds are active depending on the generator platform
    GET_PROPERTY(IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
    IF (IS_MULTI_CONFIG)
        OPTION (TR_BUILD_WITH_RELEASE "Enables the building of the release version of True Reality" ON)
        MARK_AS_ADVANCED (TR_BUILD_WITH_RELEASE)
        OPTION (TR_BUILD_WITH_DEBUG "Enables the building of the debug version of True Reality" ON)
        MARK_AS_ADVANCED (TR_BUILD_WITH_DEBUG)
    ELSE ()
        IF (CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
            SET (TR_BUILD_WITH_RELEASE "ON" CACHE INTERNAL  "Enables the building of the release version of True Reality" FORCE)
        ELSEIF (CMAKE_BUILD_TYPE STREQUAL "Debug")
            SET (TR_BUILD_WITH_DEBUG "ON" CACHE INTERNAL  "Enables the building of the debug version of True Reality" FORCE)
        ENDIF ()
    ENDIF ()

    # Tell CMake to look for libraries in 'lib64' as well as in 'lib' (when building x86_64 on Linux)
    IF (UNIX)
        SET_PROPERTY (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS ON)
    ENDIF ()
ENDMACRO ()

# *****************************************************************************
# Configures the given projects build options *********************************
# *****************************************************************************
MACRO (TR_TARGET_OPTIONS arg)
    SET_TARGET_PROPERTIES (
        ${arg}
        PROPERTIES
        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
        RELWITHDEBINFO_POSTFIX ${CMAKE_RELWITHDEBINFO_POSTFIX}
        VERSION ${TR_VERSION_MAJOR}.${TR_VERSION_MINOR}.${TR_VERSION_YYMM}.${TR_VERSION_BUILD}
        SOVERSION ${TR_SOVERSION}
    )
    IF (MSVC_IDE)
        TARGET_COMPILE_OPTIONS (
            ${arg} PRIVATE
            $<$<CONFIG:Debug>:/Od /Ob0 /RTC1 /D_DEBUG /Zi>
            $<$<CONFIG:RelWithDebInfo>:/MD /Zi /O2 /Ob1 /D>
            $<$<CONFIG:Release>:/O2 /Ob2 /MD>
        )
    ELSEIF (UNIX)
        TARGET_COMPILE_OPTIONS (
            ${arg} PRIVATE
            -Wall -pedantic -Wextra -fPIC #-Werror
            $<$<CONFIG:Debug>: -g -O0 -D_DEBUG>
            $<$<CONFIG:RelWithDebInfo>: -g -O3 -DNDEBUG>
            $<$<CONFIG:Release>: -O3 -DNDEBUG>
        )
    ENDIF ()
ENDMACRO ()

# *****************************************************************************
# Reads the installed GCC version *********************************************
# *****************************************************************************
MACRO (READ_GCC_VERSION)
    IF (CMAKE_COMPILER_IS_GNUCXX)
        EXECUTE_PROCESS (COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
        STRING (REGEX MATCHALL "[0-9]+" GCC_VERSION_COMPONENTS ${GCC_VERSION})
        LIST (GET GCC_VERSION_COMPONENTS 0 GCC_MAJOR)
        LIST (LENGTH GCC_VERSION_COMPONENTS LIST_LEN)
        IF (LIST_LEN GREATER 1)
            LIST (GET GCC_VERSION_COMPONENTS 1 GCC_MINOR)
        ELSE ()
            SET(GCC_MINOR "X")
        ENDIF ()
    ENDIF ()
ENDMACRO ()

# *****************************************************************************
# Checks if the version we are looking for is the one we found. ***************
# *****************************************************************************
MACRO (CHECK_VERSION packName packVer verToFind)
    IF("${packVer}" VERSION_LESS "${verToFind}")
        MESSAGE(SEND_ERROR "Found version is too old!
        Required: v${verToFind}         Found: v${packVer}
        ")
    ELSE ()
        MESSAGE(STATUS "${packName} Version: ${packVer}")
    ENDIF ()
ENDMACRO ()

# *****************************************************************************
# Adds a post build process to create a Google Test info file *****************
# in a build project **********************************************************
# *****************************************************************************
MACRO (SET_GOOGLE_TEST_OPTIONS projectName)
    IF (MSVC_IDE)
		ADD_CUSTOM_COMMAND(TARGET ${projectName}
		POST_BUILD
		COMMAND echo "This is used for Google Test Adapter in MS Visual Studio" > $<TARGET_FILE:${projectName}>".is_google_test"
		)
    ENDIF ()
ENDMACRO ()