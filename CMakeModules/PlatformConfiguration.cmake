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
# Common global definitions.***************************************************
# *****************************************************************************

# Require C++17 support, prefer ISO C++ over GNU variants,
# as relying solely on ISO C++ is more portable.
SET (CMAKE_CXX_STANDARD 17)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)
SET (CMAKE_CXX_EXTENSIONS OFF)

OPTION (CMAKE_USE_RELATIVE_PATHS "Uses relative paths in project settings" ON)

SET (TR_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
SET (TR_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

SET (OUTPUT_BINDIR ${PROJECT_BINARY_DIR}/bin)
MAKE_DIRECTORY (${OUTPUT_BINDIR})
SET (EXECUTABLE_OUTPUT_PATH ${OUTPUT_BINDIR})

SET (OUTPUT_LIBDIR ${PROJECT_BINARY_DIR}/lib)
MAKE_DIRECTORY (${OUTPUT_LIBDIR})
SET (LIBRARY_OUTPUT_PATH ${OUTPUT_LIBDIR})

SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${OUTPUT_LIBDIR} CACHE PATH "build directory")
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${OUTPUT_BINDIR} CACHE PATH "build directory")
IF (MSVC_IDE)
    SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BINDIR} CACHE PATH "build directory")
ELSE ()
    SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_LIBDIR} CACHE PATH "build directory")
ENDIF ()

# Sets the Debug and Release library naming formats, but not executables.
IF (TR_BUILD_VERSIONED_LIBRARIES)    
    IF (WIN32)
        SET (CMAKE_SHARED_LIBRARY_PREFIX ${TR_SO_PREFIX})
        SET (CMAKE_STATIC_LIBRARY_PREFIX ${TR_SO_PREFIX})
    ELSEIF (APPLE)
        SET (CMAKE_SHARED_LIBRARY_PREFIX "${CMAKE_SHARED_LIBRARY_PREFIX}${TR_SO_PREFIX}")
        SET (CMAKE_STATIC_LIBRARY_PREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}${TR_SO_PREFIX}")
    ENDIF ()
ENDIF ()

# Sets the postfix on libraries. 
SET (CMAKE_DEBUG_POSTFIX "-d" CACHE STRING "Set Debug library postfix" FORCE)
SET (CMAKE_RELEASE_POSTFIX "" CACHE STRING "Set Release library postfix" FORCE)
SET (CMAKE_RELWITHDEBINFO_POSTFIX "-rd" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
SET (CMAKE_MINSIZEREL_POSTFIX "-rms" CACHE STRING "Set MinSizeRel library postfix" FORCE)

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


# Sets the include directories; Visible to all CMakeLists.txt files
INCLUDE_DIRECTORIES (
    ${CMAKE_SOURCE_DIR}
    ${TR_INCLUDE_DIR}
    ${PROJECT_BINARY_DIR}/include
)

# *****************************************************************************
# Platform specific definitions.***********************************************
# *****************************************************************************
IF (APPLE)
    MESSAGE (STATUS "\nConfiguring for Apple")
    OPTION (TC_BUILD_FOR_IOS OFF)
ENDIF ()

IF (UNIX)
    MESSAGE (STATUS "\nConfiguring for Unix")
    READ_GCC_VERSION()
    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-non-virtual-dtor -Wreturn-type")
    SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread")

    MESSAGE (STATUS "GCC Version: ${GCC_MAJOR}.${GCC_MINOR}")
    MESSAGE (STATUS "CXX FLAGS: " ${CMAKE_CXX_FLAGS})
    MESSAGE (STATUS "Linker FLAGS: " ${CMAKE_EXE_LINKER_FLAGS})

    OPTION (CMAKE_VERBOSE_MAKEFILE "Users may enable the option in their local build tree to get more verbose output from Makefile builds and show each command line as it is launched." ON)
    OPTION (CMAKE_COLOR_MAKEFILE "When enabled, the generated Makefiles will produce colored output. Default is ON" ON)

    IF (CMAKE_INSTALL_PREFIX STREQUAL "/usr/local" OR CMAKE_INSTALL_PREFIX STREQUAL "/usr/local/")
        SET (CMAKE_INSTALL_PREFIX "/usr/local/${PROJECT_NAME}" CACHE STRING "TrueReality default install folder" FORCE)
    ELSEIF (CMAKE_INSTALL_PREFIX STREQUAL "/opt" OR CMAKE_INSTALL_PREFIX STREQUAL "/opt/")
        SET (CMAKE_INSTALL_PREFIX "/opt/${PROJECT_NAME}" CACHE STRING "TrueReality default install folder" FORCE)
    ENDIF ()
ENDIF ()

IF (WIN32)
    MESSAGE (STATUS "\nConfiguring for Windows")

    IF (MSVC_IDE)
	
        # Enables folder creation in VS projects. 
        SET_PROPERTY (GLOBAL PROPERTY USE_FOLDERS ON)
	
        # Set all the initial CXX options
        SET (CMAKE_CXX_FLAGS " /DWIN32 /D_WINDOWS /W3 /GR /EHsc /nologo")

        # Enable multi-core builds
        OPTION (TR_BUILD_WITH_MP "Enables the /MP multi-processor compiler option for Visual Studio 2005 and above" ON)		
        MARK_AS_ADVANCED (TR_BUILD_WITH_MP)
        IF (TR_BUILD_WITH_MP)
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
        ENDIF ()
		
        # Enable strict checking
        OPTION (TR_BUILD_WITH_STRICT "Enables the Option STRICT for VS compiler" ON)
        MARK_AS_ADVANCED (TR_BUILD_WITH_STRICT)
        IF (TR_BUILD_WITH_STRICT)
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTRICT")
        ENDIF ()
		
        # Reduce the number of default headers included in a VS build
        OPTION (TR_BUILD_WITH_LEAN_AND_MEAN "Enables the option LEAN_AND_MEAN for VS compiler, to speed up compilation" ON)
        MARK_AS_ADVANCED (TR_BUILD_WITH_LEAN_AND_MEAN)
        IF (TR_BUILD_WITH_LEAN_AND_MEAN)
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32_LEAN_AND_MEAN")
        ENDIF ()

        #If we are using Boost
        IF (BoostLibs_FOUND)
            #Sets temporary warning suppression flags. These should be revisited and rechecked at every VS version and Ext dependency change. 
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE") #Boost has a bug with using an old config file with VS2017
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DBOOST_ALL_DYN_LINK")                     #Force only boost dynamic libraries to be used
            LINK_DIRECTORIES (${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})                        #Force all projects to have boost dirs as aditional library paths
        ENDIF ()
    ENDIF ()
ENDIF ()

# For each configuration (Debug, Release, MinSizeRel... and/or anything the
# user chooses)
FOREACH (CONF ${CMAKE_CONFIGURATION_TYPES})
    # Go uppercase (DEBUG, RELEASE...)
    STRING (TOUPPER "${CONF}" CONF)
    SET ("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_LIBDIR}")
    SET ("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_BINDIR}")
    IF (MSVC_IDE)
        SET ("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_BINDIR}")
    ELSE ()
        SET ("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_LIBDIR}")
    ENDIF ()
ENDFOREACH ()

# Expose CMAKE variables to the GUI so users
# may set these values without needing to manipulate the environment.
SET (CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
SET (CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
SET (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} CACHE STRING "CXX Flags" FORCE)
SET (CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} CACHE STRING "Linker Flags" FORCE)


MESSAGE(STATUS "Configuring to use C++ ${CMAKE_CXX_STANDARD} standard with a ${CMAKE_BUILD_TYPE} build.")