# Platform specific definitions
IF (APPLE)
    MESSAGE(STATUS "Configuring for Apple")
	OPTION (TC_BUILD_FOR_IOS OFF)
ENDIF(APPLE)

IF (UNIX)
    MESSAGE(STATUS "Configuring for Unix")
	READ_GCC_VERSION()
	SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-non-virtual-dtor -Wreturn-type")
	IF (GCC_VERSION LESS 6.0.0)
		SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
		MESSAGE (STATUS "GCC Version: " ${GCC_VERSION})
        MESSAGE (STATUS "CXX FLAGS: " ${CMAKE_CXX_FLAGS})
	ENDIF (GCC_VERSION LESS 6.0.0)
    OPTION (CMAKE_VERBOSE_MAKEFILE "Users may enable the option in their local build tree to get more verbose output from Makefile builds and show each command line as it is launched." ON)
    OPTION (CMAKE_COLOR_MAKEFILE "When enabled, the generated Makefiles will produce colored output. Default is ON" ON)
ENDIF(UNIX)

IF (WIN32)
    MESSAGE(STATUS "Configuring for Windows")

	IF (MSVC_IDE)
	
		# Enables folder creation in VS projects. 
		SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
	
		# Enable multicore builds
		OPTION (TR_BUILD_WITH_MP "Enables the /MP multi-processor compiler option for Visual Studio 2005 and above" ON)		
		MARK_AS_ADVANCED (TR_BUILD_WITH_MP)
		IF (TR_BUILD_WITH_MP)
			SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
		ENDIF (TR_BUILD_WITH_MP)
		
		# Enable strict checking
		OPTION (TR_BUILD_WITH_STRICT "Enables the Option STRICT for VS compiler" ON)
		MARK_AS_ADVANCED (TR_BUILD_WITH_STRICT)
		IF (TR_BUILD_WITH_STRICT)
			SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTRICT")
		ENDIF (TR_BUILD_WITH_STRICT)
		
		# Reduce the number of default headers included in a VS build
		OPTION (TR_BUILD_WITH_LEAN_AND_MEAN "Enables the option LEAN_AND_MEAN for VS compiler, to speed up compilation" ON)
		MARK_AS_ADVANCED (TR_BUILD_WITH_LEAN_AND_MEAN)
		IF (TR_BUILD_WITH_LEAN_AND_MEAN)
			SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32_LEAN_AND_MEAN")
		ENDIF (TR_BUILD_WITH_LEAN_AND_MEAN)

        #If we are using Boost
        IF (BoostLibs_FOUND)
            #Sets temporary warning suppression flags. These should be revisited and rechecked at every VS version and Ext dependency change. 
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE") #Boost has a bug with using an old config file with VS2017
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DBOOST_ALL_DYN_LINK")                     #Force only boost dynamic libraries to be used
            LINK_DIRECTORIES (${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})                        #Force all projects to have boost dirs as aditional library paths
        ENDIF(BoostLibs_FOUND)

        #If we are using Google Test
        IF (GoogleTest_FOUND)
            #Sets temporary warning suppression flags. These should be revisited and rechecked at every VS version and Ext dependency change. 
            SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING")     #GTest uses old TR1 Namespaces 
        ENDIF(GoogleTest_FOUND)

	ENDIF (MSVC_IDE)

ENDIF (WIN32)

# Common global definitions
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
ELSE (MSVC_IDE)
	SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_LIBDIR} CACHE PATH "build directory")
ENDIF (MSVC_IDE)

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

# Expose CMAKE_INCLUDE_PATH and CMAKE_LIBARY_PATH to the GUI so users
# may set these values without needing to manipulate the environment.
SET (CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
SET (CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
