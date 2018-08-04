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
    
    IF (TR_MANAGER)
        ADD_SUBDIRECTORY (src/trManager)
        SET (TR_MANAGER_AVAILABLE "YES")
    ENDIF ()
    
    IF (TR_CORE)
        ADD_SUBDIRECTORY (src/trCore)
        SET (TR_CORE_AVAILABLE "YES")
    ENDIF ()
    
    IF (TR_VR)
        ADD_SUBDIRECTORY (src/trVR)
        SET (TR_VR_AVAILABLE "YES")
    ENDIF (TR_VR)
    
    IF (TR_APP)
        ADD_SUBDIRECTORY (src/trApp)
        SET (TR_APP_AVAILABLE "YES")
    ENDIF ()

    IF (TR_START)
        ADD_SUBDIRECTORY (src/trStart)
        SET (TR_START_AVAILABLE "YES")
    ENDIF ()

    IF (TR_MPEG)
    	ADD_SUBDIRECTORY (src/trMPEG)
        SET (TR_MPEG_AVAILABLE "YES")
    ENDIF ()

# Utilities folders
    MESSAGE (STATUS "Creating Selected Utility Folders")
    IF (TR_VERSION)
        ADD_SUBDIRECTORY (src/trVersion)
        SET (TR_VERSION_AVAILABLE "YES")
    ENDIF ()

# Examples folders
    MESSAGE (STATUS "Creating Selected Example Folders")
    IF (EXAMPLES_VIRTUAL_REALITY)
        ADD_SUBDIRECTORY (Examples/VirtualReality)
        SET (EXAMPLES_VIRTUAL_REALITY_AVAILABLE "YES")
    ENDIF ()

    IF (EXAMPLES_LOGGING)
        ADD_SUBDIRECTORY (Examples/Logging)
        SET (EXAMPLES_LOGGING_AVAILABLE "YES")
    ENDIF ()

    IF (EXAMPLES_JSON)
        ADD_SUBDIRECTORY (Examples/Json)
        SET (EXAMPLES_JSON_AVAILABLE "YES")
    ENDIF ()
    
    IF (EXAMPLES_DIRECTOR)
        ADD_SUBDIRECTORY (Examples/Director)
        SET (EXAMPLES_DIRECTOR_AVAILABLE "YES")
    ENDIF ()
    
    IF (EXAMPLES_ACTORS)
        ADD_SUBDIRECTORY (Examples/Actors)
        SET (EXAMPLES_ACTORS_AVAILABLE "YES")
    ENDIF ()
    
    IF (EXAMPLES_ACTOR_MODULES)
        ADD_SUBDIRECTORY (Examples/ActorModules)
        SET (EXAMPLES_ACTOR_MODULES_AVAILABLE "YES")
    ENDIF ()
    
 # Unit Test Folders
    MESSAGE (STATUS "Creating Selected Tests Folders")
    
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
            /nologo /GR
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
    IF (CMAKE_COMPILER_IS_GNUCC)
        EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
		STRING(REGEX MATCHALL "[0-9]+" GCC_VERSION_COMPONENTS ${GCC_VERSION})
	    LIST(GET GCC_VERSION_COMPONENTS 0 GCC_MAJOR)
		LIST(GET GCC_VERSION_COMPONENTS 1 GCC_MINOR)
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