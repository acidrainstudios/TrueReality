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
# @author Maxim Serebrennik

INCLUDE (CMakeDependentOption)
CMAKE_MINIMUM_REQUIRED(VERSION 3.11.0 FATAL_ERROR)
CMAKE_POLICY (VERSION 3.11.0)
IF (POLICY CMP0074)
  CMAKE_POLICY(SET CMP0074 NEW) # CMake 3.12 <package>_ROOT support
ENDIF ()


# Sets the path to custom CMake modules.
SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

# Sets a check to make sure cmake does change the source files.
SET (CMAKE_DISABLE_SOURCE_CHANGES ON)
SET (CMAKE_DISABLE_IN_SOURCE_BUILD ON)
INCLUDE (InSourceBuild)

# Loads extra CMake modules for the projects
INCLUDE (UtilityMacros)

#Sets up all the versioning information
INCLUDE (Version)

# Defines the project name
PROJECT (TrueReality-${TR_VERSION_MAJOR}.${TR_VERSION_MINOR} VERSION ${TR_VERSION} LANGUAGES CXX)

# Sets up the install options
SET (TR_DATA_INSTALLED "0" CACHE INTERNAL "System Use only: flag to show that Data was installed" FORCE)
SET (TR_EXT_INSTALLED "0" CACHE INTERNAL "System Use only: flag to show that Ext was installed" FORCE)
SET (TR_HEADERS_INSTALLED "0" CACHE INTERNAL "System Use only: flag to show that Headers were installed" FORCE)
INCLUDE (InstallMacros)

# Sets the build options
TR_BUILD_TYPE_OPTIONS()

# *****************************************************************************
# Sets user options ***********************************************************
# *****************************************************************************
OPTION (TR_UTIL "Enables the building of trUtil" ON)
CMAKE_DEPENDENT_OPTION (TR_BASE "Enables the building of trBase library" ON "TR_UTIL" OFF)
CMAKE_DEPENDENT_OPTION (TR_SG "Enables the building of trSG library that wraps OSG" ON "TR_UTIL; TR_BASE" OFF)
CMAKE_DEPENDENT_OPTION (TR_MANAGER "Enables the building of trManager library" ON "TR_UTIL; TR_BASE" OFF)
CMAKE_DEPENDENT_OPTION (TR_CORE "Enables the building of trCore library" ON "TR_MANAGER; TR_SG; TR_UTIL; TR_BASE" OFF)
CMAKE_DEPENDENT_OPTION (TR_APP "Enables the building of trApp library" ON "TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE" OFF)

# *****************************************************************************
# Sets Advanced options ***********************************************************
# *****************************************************************************
OPTION (TR_USE_DOUBLE_MATRIX "Set to OFF to build TR with float Matrix instead of double." ON)
MARK_AS_ADVANCED (TR_USE_DOUBLE_MATRIX)
OPTION (TR_USE_DOUBLE_VECTOR "Set to OFF to build TR with float Vector instead of double." ON)
MARK_AS_ADVANCED (TR_USE_DOUBLE_VECTOR)
OPTION (TR_BUILD_VERSIONED_LIBRARIES "Enables the building of unique versioned shared libraries" ON)
MARK_AS_ADVANCED (TR_BUILD_VERSIONED_LIBRARIES)
OPTION (CMAKE_USE_RELATIVE_PATHS "Uses relative paths in project settings" ON)
MARK_AS_ADVANCED (CMAKE_USE_RELATIVE_PATHS)

# *****************************************************************************
# Sets Utilities options ******************************************************
# *****************************************************************************
OPTION (TR_BUILD_UTILITIES "Enables the building of TR tools and utilities" ON)
CMAKE_DEPENDENT_OPTION (TR_START "Enables the building of trStart Utility" ON "TR_BUILD_UTILITIES; TR_UTIL; TR_CORE" OFF)
CMAKE_DEPENDENT_OPTION (TR_VERSION_UTIL "Enables the building of trVersion Utility" ON "TR_BUILD_UTILITIES; TR_UTIL" OFF)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# *****************************************************************************
# Sets Example options ********************************************************
# *****************************************************************************
OPTION (TR_BUILD_EXAMPLES "Enables the building of TR demos and examples" ON)
CMAKE_DEPENDENT_OPTION (EXAMPLES_ACTORS "Enables the building of exampleActors project" ON "TR_BUILD_EXAMPLES; TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE; TR_APP" OFF)
CMAKE_DEPENDENT_OPTION (EXAMPLES_ACTOR_MODULES "Enables the building of exampleActorModules project" ON "TR_BUILD_EXAMPLES; TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE; TR_APP" OFF)
CMAKE_DEPENDENT_OPTION (EXAMPLES_DIRECTOR "Enables the building of exampleDirector project" ON "TR_BUILD_EXAMPLES; TR_CORE; TR_MANAGER; TR_UTIL; TR_BASE; TR_APP" OFF)
CMAKE_DEPENDENT_OPTION (EXAMPLES_JSON "Enables the building of exampleJSON project" ON "TR_BUILD_EXAMPLES; TR_UTIL" OFF)
CMAKE_DEPENDENT_OPTION (EXAMPLES_LOGGING "Enables the building of exampleLogging project" ON "TR_BUILD_EXAMPLES; TR_UTIL" OFF)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# *****************************************************************************
# Sets Test options ***********************************************************
# *****************************************************************************
OPTION (TR_BUILD_TESTS "Enables the building of Unit Tests" ON)
CMAKE_DEPENDENT_OPTION (TESTS_TR_UTIL "Enables the building of trUtil Unit Tests" ON "TR_BUILD_TESTS; TR_UTIL" OFF)
CMAKE_DEPENDENT_OPTION (TESTS_TR_BASE "Enables the building of trBase Unit Tests" ON "TR_BUILD_TESTS; TR_BASE" OFF)
CMAKE_DEPENDENT_OPTION (TESTS_TR_MANAGER "Enables the building of trManager Unit Tests" ON "TR_BUILD_TESTS; TR_CORE; TR_MANAGER; TR_BASE" OFF)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# *****************************************************************************
# Sets Library Specific Dependencies*******************************************
# *****************************************************************************
IF (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)
    TR_DETECT_DEPENDENCY (OSG 3.6.0)
    TR_DETECT_DEPENDENCY (OpenThreads)
    INCLUDE_DIRECTORIES (SYSTEM ${OSG_INCLUDE_DIR} ${OpenThreads_INCLUDE_DIR})
ENDIF ()

# trUtil packages
IF (TR_UTIL)
    TR_DETECT_DEPENDENCY (bID)
    TR_DETECT_DEPENDENCY (JsonCpp)
    INCLUDE_DIRECTORIES (SYSTEM ${JSON_CPP_INCLUDE_DIR} ${bID_INCLUDE_DIR})
ENDIF ()

# Unit Tests
IF (TR_BUILD_TESTS)
    TR_DETECT_DEPENDENCY (GoogleTest)
    INCLUDE_DIRECTORIES (SYSTEM ${GOOGLE_TEST_INCLUDE_DIR})
ENDIF ()

# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Sets up platform specific configuration
INCLUDE (PlatformConfiguration)

# *****************************************************************************
# Set Float/Double Config header file *****************************************
# *****************************************************************************
SET (TR_FLOAT_DOUBLE_CONFIG_HEADER "${PROJECT_BINARY_DIR}/include/trUtil/TypeConfig.h")
CONFIGURE_FILE ("${CMAKE_CURRENT_SOURCE_DIR}/include/trUtil/TypeConfig.in" "${TR_FLOAT_DOUBLE_CONFIG_HEADER}")
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Generates the selected sub-folders for the code base
ADD_TR_SUBFOLDERS ()

#Copy all the needed files to the Build Folder
TR_INSTALL_BUILD_OPTIONS ()

# Displays the current version of True Reality ********************************
PRINT_TR_VERSION ()

MESSAGE(STATUS "True Reality Source directory: ${CMAKE_CURRENT_SOURCE_DIR}")
MESSAGE(STATUS "True Reality Build directory: ${PROJECT_BINARY_DIR}")
MESSAGE(STATUS "True Reality Install directory: ${CMAKE_INSTALL_PREFIX}\n")