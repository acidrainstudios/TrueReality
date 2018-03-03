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

INCLUDE (CMakeDependentOption)
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0 FATAL_ERROR)
CMAKE_POLICY(VERSION 3.10.0)

# Sets the path to custom CMake modules. 
SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

# Sets a check to make sure cmake does change the source files.  
SET (CMAKE_DISABLE_SOURCE_CHANGES ON)

# *****************************************************************************
# Adds subfolders in the True Reality CMake GUI tab **********************************
# *****************************************************************************
MACRO (ADD_TR_SUBFOLDERS)

# Optional dependencies
	IF (TR_UTIL)
		ADD_SUBDIRECTORY (src/trUtil)
        SET (TR_UTIL_AVAILABLE "YES")
    ENDIF (TR_UTIL)

    IF (TR_BASE)
		ADD_SUBDIRECTORY (src/trBase)
        SET (TR_BASE_AVAILABLE "YES")
    ENDIF (TR_BASE)
    
    IF (TR_MANAGER)
		ADD_SUBDIRECTORY (src/trManager)
        SET (TR_MANAGER_AVAILABLE "YES")
    ENDIF (TR_MANAGER)
    
    IF (TR_CORE)
		ADD_SUBDIRECTORY (src/trCore)
        SET (TR_CORE_AVAILABLE "YES")
    ENDIF (TR_CORE)
    
    IF (TR_APP)
		ADD_SUBDIRECTORY (src/trApp)
        SET (TR_APP_AVAILABLE "YES")
    ENDIF (TR_APP)

    IF (TR_START)
		ADD_SUBDIRECTORY (src/trStart)
        SET (TR_START_AVAILABLE "YES")
    ENDIF (TR_START)

# Utilities folders
    IF (TR_VERSION)
        ADD_SUBDIRECTORY (src/trVersion)
        SET (TR_VERSION_AVAILABLE "YES")
    ENDIF (TR_VERSION)

# Examples folders
    IF (EXAMPLES_JSON)
        ADD_SUBDIRECTORY (Examples/Json)
        SET (EXAMPLES_JSON_AVAILABLE "YES")
    ENDIF (EXAMPLES_JSON)
    
    IF (EXAMPLES_DIRECTOR)
        ADD_SUBDIRECTORY (Examples/Director)
        SET (EXAMPLES_DIRECTOR_AVAILABLE "YES")
    ENDIF (EXAMPLES_DIRECTOR)
    
    IF (EXAMPLES_ACTORS)
        ADD_SUBDIRECTORY (Examples/Actors)
        SET (EXAMPLES_ACTORS_AVAILABLE "YES")
    ENDIF (EXAMPLES_ACTORS)
    
    IF (EXAMPLES_ACTOR_MODULES)
        ADD_SUBDIRECTORY (Examples/ActorModules)
        SET (EXAMPLES_ACTOR_MODULES_AVAILABLE "YES")
    ENDIF (EXAMPLES_ACTOR_MODULES)
    
 # Unit Test Folders
    IF (TESTS_TR_MANAGER)
        ADD_SUBDIRECTORY (Tests/TrManager)
        SET (TESTS_TR_MANAGER_AVAILABLE "YES")
    ENDIF (TESTS_TR_MANAGER)

ENDMACRO (ADD_TR_SUBFOLDERS)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Loads extra CMake modules for the projects
INCLUDE (UtilityMacros)

#Sets up all the versioning information
INCLUDE (Version) 

# Defines the project name
PROJECT (TrueReality VERSION ${TR_VERSION})

# *****************************************************************************
# Sets user options ***********************************************************
# *****************************************************************************
OPTION (TR_UTIL "Enables the building of trUtil" ON)
CMAKE_DEPENDENT_OPTION (TR_BASE "Enables the building of trBase library" ON "TR_UTIL" OFF)
CMAKE_DEPENDENT_OPTION (TR_MANAGER "Enables the building of trManager library" ON "TR_UTIL; TR_BASE" OFF)
CMAKE_DEPENDENT_OPTION (TR_CORE "Enables the building of trCore library" ON "TR_MANAGER; TR_UTIL; TR_BASE" OFF)
CMAKE_DEPENDENT_OPTION (TR_APP "Enables the building of trApp library" ON "TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE" OFF)

# *****************************************************************************
# Sets Advanced options ***********************************************************
# *****************************************************************************
OPTION(TR_USE_DOUBLE_MATRIX "Set to OFF to build TR with float Matrix instead of double." ON)
MARK_AS_ADVANCED(TR_USE_DOUBLE_MATRIX)
OPTION(TR_USE_DOUBLE_VECTOR "Set to OFF to build TR with float Vector instead of double." ON)
MARK_AS_ADVANCED(TR_USE_DOUBLE_VECTOR)
OPTION (TR_BUILD_VERSIONED_LIBRARIES "Enables the building of unique versioned shared libraries" ON)
MARK_AS_ADVANCED(TR_BUILD_VERSIONED_LIBRARIES)
OPTION (TR_BUILD_WITH_RELEASE "Enables the building of the release version of True Reality" ON)
MARK_AS_ADVANCED(TR_BUILD_WITH_RELEASE)
OPTION (TR_BUILD_WITH_DEBUG "Enables the building of the debug version of True Reality" ON)
MARK_AS_ADVANCED(TR_BUILD_WITH_DEBUG)
OPTION (CMAKE_USE_RELATIVE_PATHS "Uses relative paths in project settings" ON)
MARK_AS_ADVANCED(CMAKE_USE_RELATIVE_PATHS)

# *****************************************************************************
# Sets Utilities options ******************************************************
# *****************************************************************************
OPTION (TR_BUILD_UTILITIES "Enables the building of TR tools and utilities" ON)
CMAKE_DEPENDENT_OPTION (TR_START "Enables the building of trStart Utility" ON "TR_BUILD_UTILITIES; TR_UTIL; TR_CORE" OFF)
CMAKE_DEPENDENT_OPTION (TR_VERSION "Enables the building of trVersion Utility" ON "TR_BUILD_UTILITIES; TR_UTIL" OFF)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# *****************************************************************************
# Sets Example options ********************************************************
# *****************************************************************************
OPTION (TR_BUILD_EXAMPLES "Enables the building of TR demos and examples" ON)
CMAKE_DEPENDENT_OPTION (EXAMPLES_JSON "Enables the building of examplesJSON project" ON "TR_BUILD_EXAMPLES; TR_UTIL" OFF)
CMAKE_DEPENDENT_OPTION (EXAMPLES_DIRECTOR "Enables the building of examplesDirector project" ON "TR_BUILD_EXAMPLES; TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE; TR_APP" OFF)
CMAKE_DEPENDENT_OPTION (EXAMPLES_ACTORS "Enables the building of examplesActors project" ON "TR_BUILD_EXAMPLES; TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE; TR_APP" OFF)
CMAKE_DEPENDENT_OPTION (EXAMPLES_ACTOR_MODULES "Enables the building of examplesActorModuless project" ON "TR_BUILD_EXAMPLES; TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE; TR_APP" OFF)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# *****************************************************************************
# Sets Test options ***********************************************************
# *****************************************************************************
OPTION (TR_BUILD_TESTS "Enables the building of Unit Tests" ON)
CMAKE_DEPENDENT_OPTION (TESTS_TR_MANAGER "Enables the building of trManager Unit Tests" ON "TR_BUILD_TESTS; TR_CORE; TR_MANAGER; TR_BASE" OFF)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# *****************************************************************************
# Sets Library Specific Dependencies*******************************************
# *****************************************************************************
IF (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)    
    TR_DETECT_DEPENDENCY (OSG 3.4.0)
    TR_DETECT_DEPENDENCY (OpenThreads)
    INCLUDE_DIRECTORIES (${OSG_INCLUDE_DIR} ${OPENTHREADS_INCLUDE_DIR})
ENDIF (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)

# trUtil packages
IF (TR_UTIL)
	TR_DETECT_DEPENDENCY (JsonCpp)
	INCLUDE_DIRECTORIES (${JSON_CPP_INCLUDE_DIR})
ENDIF (TR_UTIL)

# trBase packages
IF (TR_BASE)
    TR_DETECT_DEPENDENCY (BoostLibs 1.61.0)
    INCLUDE_DIRECTORIES (${Boost_INCLUDE_DIRS})
ENDIF (TR_BASE)

# UNIT Tests
IF (TR_BUILD_TESTS)
    TR_DETECT_DEPENDENCY (GoogleTest)
    INCLUDE_DIRECTORIES (${GOOGLE_TEST_INCLUDE_DIR})
ENDIF (TR_BUILD_TESTS)

# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Sets up platform specific configuration
INCLUDE (PlatformConfiguration)

# Sets the Debug and Release library naming formats, but not executables.
IF(TR_BUILD_VERSIONED_LIBRARIES)    
    IF(WIN32)
        SET (CMAKE_SHARED_LIBRARY_PREFIX ${TR_SO_PREFIX})
        SET (CMAKE_STATIC_LIBRARY_PREFIX ${TR_SO_PREFIX})
    ELSEIF(APPLE)
        SET (CMAKE_SHARED_LIBRARY_PREFIX "${CMAKE_SHARED_LIBRARY_PREFIX}${TR_SO_PREFIX}")
        SET (CMAKE_STATIC_LIBRARY_PREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}${TR_SO_PREFIX}")
    ENDIF()
ENDIF(TR_BUILD_VERSIONED_LIBRARIES)

# Sets the postfix on libraries. 
SET (CMAKE_DEBUG_POSTFIX "-d" CACHE STRING "Set Debug library postfix" FORCE)
SET (CMAKE_RELEASE_POSTFIX "" CACHE STRING "Set Release library postfix" FORCE)
SET (CMAKE_RELWITHDEBINFO_POSTFIX "-rd" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
SET (CMAKE_MINSIZEREL_POSTFIX "-rms" CACHE STRING "Set MinSizeRel library postfix" FORCE)

# Sets the include directories; Visible to all CMakeLists.txt files
INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}
    ${TR_INCLUDE_DIR}
)

# Generates the selected sub-folders for the code base
ADD_TR_SUBFOLDERS()

# *****************************************************************************
# Set Float/Double Config header file *****************************************
# *****************************************************************************
SET(TR_FLOAT_DOUBLE_CONFIG_HEADER "${PROJECT_BINARY_DIR}/include/trUtil/TypeConfig.h")
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/include/trUtil/TypeConfig.in" "${TR_FLOAT_DOUBLE_CONFIG_HEADER}")
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Sets Available Build Types
SET (CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo;Release" CACHE STRING "TrueReality multi-config types" FORCE)

# Displays the current version of True Reality ********************************
PRINT_TR_VERSION()