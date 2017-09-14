CMAKE_MINIMUM_REQUIRED(VERSION 3.5.0 FATAL_ERROR)

SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

#Sets up all the versioning information
INCLUDE (Version) 

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
    
    IF (TR_CORE)
		ADD_SUBDIRECTORY (src/trCore)
        SET (TR_CORE_AVAILABLE "YES")
    ENDIF (TR_CORE)
    
    IF (TR_START)
		ADD_SUBDIRECTORY (src/trStart)
        SET (TR_START_AVAILABLE "YES")
    ENDIF (TR_START)

ENDMACRO (ADD_TR_SUBFOLDERS)
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Defines the project name
PROJECT (TrueReality)

# Loads extra CMake modules for the projects
INCLUDE (CMakeDependentOption)
INCLUDE (UtilityMacros)

# *****************************************************************************
# Sets user options ***********************************************************
# *****************************************************************************
OPTION (TR_UTIL "Enables the building of trUtil" ON)
CMAKE_DEPENDENT_OPTION (TR_CORE "Enables the building of trCore library" ON "TR_UTIL" OFF)
CMAKE_DEPENDENT_OPTION (TR_START "Enables the building of trStart executable" ON "TR_UTIL; TR_CORE" OFF)

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
# *****************************************************************************
# *****************************************************************************

IF (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)    
    TR_DETECT_DEPENDENCY (OSG)
    TR_DETECT_DEPENDENCY (OpenThreads)
    INCLUDE_DIRECTORIES (${OSG_INCLUDE_DIR} ${OPENTHREADS_INCLUDE_DIR})
ENDIF (TR_BUILD_WITH_RELEASE OR TR_BUILD_WITH_DEBUG)

# Sets up platform specific configuration
INCLUDE (PlatformConfiguration)

#Sets the Debug and Release library naming formats, but not executables.
IF(TR_BUILD_VERSIONED_LIBRARIES)    
    IF(WIN32)
        SET (CMAKE_SHARED_LIBRARY_PREFIX ${TR_SO_PREFIX})
        SET (CMAKE_STATIC_LIBRARY_PREFIX ${TR_SO_PREFIX})
    ELSEIF(APPLE)
        SET (CMAKE_SHARED_LIBRARY_PREFIX "${CMAKE_SHARED_LIBRARY_PREFIX}${TR_SO_PREFIX}")
        SET (CMAKE_STATIC_LIBRARY_PREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}${TR_SO_PREFIX}")
    ENDIF()
ENDIF(TR_BUILD_VERSIONED_LIBRARIES)

#Sets the postfix on libraries. 
SET (CMAKE_DEBUG_POSTFIX "-d" CACHE STRING "Set Debug library postfix" FORCE)
SET (CMAKE_RELEASE_POSTFIX "" CACHE STRING "Set Release library postfix" FORCE)
SET (CMAKE_RELWITHDEBINFO_POSTFIX "-rd" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
SET (CMAKE_MINSIZEREL_POSTFIX "-rms" CACHE STRING "Set MinSizeRel library postfix" FORCE)


# Sets the include directories; Visible to all CMakeLists.txt files
INCLUDE_DIRECTORIES(
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

SET (CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo;Release" CACHE STRING "TrueReality multi-config types" FORCE)

# Displays the current version of True Reality ********************************
MESSAGE (STATUS "\nTrue Reality v" ${TR_VERSION} "\n")