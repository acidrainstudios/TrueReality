CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2 FATAL_ERROR)

SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

SET (TR_SOURCE_DIR ${CMAKE_SOURCE_DIR})

# *****************************************************************************
# Adds subfolders in the True Reality CMake GUI tab **********************************
# *****************************************************************************
macro (ADD_TRUEREALITY_SUBFOLDERS)

# Optional dependencies
	if (TR_UTIL)
		add_subdirectory (src/trUtil)
        set (TR_UTIL_AVAILABLE "YES")
    endif (TR_UTIL)
    
    if (TR_CORE)
		add_subdirectory (src/trCore)
        set (TR_CORE_AVAILABLE "YES")
    endif (TR_CORE)
    
    if (TR_START)
		add_subdirectory (src/trStart)
        set (TR_START_AVAILABLE "YES")
    endif (TR_START)

endmacro (ADD_TRUEREALITY_SUBFOLDERS)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Defines the project name
project (TrueReality)

# Loads extra CMake modules for the projects
include (CMakeDependentOption)
include (UtilityMacros)
include (ProgramInstall)

# *****************************************************************************
# Sets user options ***********************************************************
# *****************************************************************************
option (TR_UTIL "Enables the building of trUtil" ON)
cmake_dependent_option (TR_CORE "Enables the building of trCore library" ON "TR_UTIL" OFF)
cmake_dependent_option (TR_START "Enables the building of trStart executable" ON "TR_UTIL; TR_CORE" OFF)

# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

if (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)    
    TR_DETECT_DEPENDENCY (OSG)
    TR_DETECT_DEPENDENCY  (OpenThreads)
    include_directories (${OSG_INCLUDE_DIR} ${OPENTHREADS_INCLUDE_DIR})
endif (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)

# Sets up platform specific configuration
include (PlatformConfiguration)

#Sets the postfix on libraries. 
set (CMAKE_DEBUG_POSTFIX "-d" CACHE STRING "Set Debug library postfix" FORCE)
set (CMAKE_RELEASE_POSTFIX "" CACHE STRING "Set Release library postfix" FORCE)
set (CMAKE_RELWITHDEBINFO_POSTFIX "-rd" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
set (CMAKE_MINSIZEREL_POSTFIX "-rms" CACHE STRING "Set MinSizeRel library postfix" FORCE)


# Sets the include directories; Visible to all CMakeLists.txt files
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${TR_INCLUDE_DIR}
    ${TR_EXT_INCLUDE_DIR}    # Might be a redundancy and needs to be checked
)

# Generates the selected sub-folders for the code base
ADD_TRUEREALITY_SUBFOLDERS ()

set (CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo;Release" CACHE STRING "TrueReality multi-config types" FORCE)
