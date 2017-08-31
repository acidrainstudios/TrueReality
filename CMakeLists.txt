CMAKE_MINIMUM_REQUIRED(VERSION 3.5.0 FATAL_ERROR)

SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

#Sets up all the versioning information
INCLUDE (Version) 

SET (CMAKE_DISABLE_SOURCE_CHANGES ON)

# *****************************************************************************
# Adds subfolders in the True Reality CMake GUI tab **********************************
# *****************************************************************************
macro (ADD_TR_SUBFOLDERS)

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

endmacro (ADD_TR_SUBFOLDERS)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Defines the project name
project (TrueReality)

# Loads extra CMake modules for the projects
include (CMakeDependentOption)
include (UtilityMacros)

# *****************************************************************************
# Sets user options ***********************************************************
# *****************************************************************************
option (TR_UTIL "Enables the building of trUtil" ON)
cmake_dependent_option (TR_CORE "Enables the building of trCore library" ON "TR_UTIL" OFF)
cmake_dependent_option (TR_START "Enables the building of trStart executable" ON "TR_UTIL; TR_CORE" OFF)

# *****************************************************************************
# Sets Advanced options ***********************************************************
# *****************************************************************************
OPTION(TR_USE_DOUBLE_MATRIX "Set to OFF to build TR with float Matrix instead of double." ON)
MARK_AS_ADVANCED(TR_USE_DOUBLE_MATRIX)
OPTION(TR_USE_DOUBLE_VECTOR "Set to OFF to build TR with float Vector instead of double." ON)
MARK_AS_ADVANCED(TR_USE_DOUBLE_VECTOR)
option (TR_BUILD_VERSIONED_LIBRARIES "Enables the building of unique versioned shared libraries" ON)
MARK_AS_ADVANCED(TR_BUILD_VERSIONED_LIBRARIES)
option (TR_BUILD_WITH_RELEASE "Enables the building of the release version of True Reality" ON)
MARK_AS_ADVANCED(TR_BUILD_WITH_RELEASE)
option (TR_BUILD_WITH_DEBUG "Enables the building of the debug version of True Reality" ON)
MARK_AS_ADVANCED(TR_BUILD_WITH_DEBUG)
option (CMAKE_USE_RELATIVE_PATHS "Uses relative paths in project settings" ON)
MARK_AS_ADVANCED(CMAKE_USE_RELATIVE_PATHS)

# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

if (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)    
    TR_DETECT_DEPENDENCY (OSG)
    TR_DETECT_DEPENDENCY (OpenThreads)
    TR_DETECT_DEPENDENCY (Delta3D)
    TR_DETECT_DEPENDENCY (XercesC)
    include_directories (${DELTA3D_INCLUDE_DIR} ${OSG_INCLUDE_DIR} ${OPENTHREADS_INCLUDE_DIR})
endif (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)

# Sets up platform specific configuration
include (PlatformConfiguration)

#Sets the Debug and Release library naming formats, but not executables.
if(TR_BUILD_VERSIONED_LIBRARIES)    
    if(WIN32)
        set (CMAKE_SHARED_LIBRARY_PREFIX ${TR_SO_PREFIX})
        set (CMAKE_STATIC_LIBRARY_PREFIX ${TR_SO_PREFIX})
    elseif(APPLE)
        set (CMAKE_SHARED_LIBRARY_PREFIX "${CMAKE_SHARED_LIBRARY_PREFIX}${TR_SO_PREFIX}")
        set (CMAKE_STATIC_LIBRARY_PREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}${TR_SO_PREFIX}")
    endif()
endif(TR_BUILD_VERSIONED_LIBRARIES)

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
ADD_TR_SUBFOLDERS()

# *****************************************************************************
# Set Float/Double Config header file *****************************************
# *****************************************************************************
SET(TR_FLOAT_DOUBLE_CONFIG_HEADER "${PROJECT_BINARY_DIR}/include/trUtil/TypeConfig.h")
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/include/trUtil/TypeConfig.in"
               "${TR_FLOAT_DOUBLE_CONFIG_HEADER}")
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

set (CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo;Release" CACHE STRING "TrueReality multi-config types" FORCE)

# Displays the current version of True Reality ********************************
message (STATUS "\nTrue Reality v" ${TR_VERSION} "\n")