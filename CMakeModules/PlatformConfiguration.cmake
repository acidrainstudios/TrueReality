# Platform specific definitions
if (WIN32)
    message(STATUS "Configuring for Windows")

	if (MSVC_IDE)
		option (TR_BUILD_WITH_MP "Enables the /MP multi-processor compiler option for Visual Studio 2005 and above" ON)		
		mark_as_advanced (TR_BUILD_WITH_MP)
		if (TR_BUILD_WITH_MP)
			set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
		endif (TR_BUILD_WITH_MP)
		
		option (TR_BUILD_WITH_STRICT "Enables the Option STRICT for VS compiler" ON)
		mark_as_advanced (TR_BUILD_WITH_STRICT)
		if (TR_BUILD_WITH_STRICT)
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTRICT")
		endif (TR_BUILD_WITH_STRICT)
		
		option (TR_BUILD_WITH_LEAN_AND_MEAN "Enables the option LEAN_AND_MEAN for VS compiler, to speed up compilation" ON)
		mark_as_advanced (TR_BUILD_WITH_LEAN_AND_MEAN)
		if (TR_BUILD_WITH_LEAN_AND_MEAN)
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32_LEAN_AND_MEAN")
		endif (TR_BUILD_WITH_LEAN_AND_MEAN)
	endif (MSVC_IDE)

endif (WIN32)

# Common global definitions
option (CMAKE_USE_RELATIVE_PATHS "Uses relative paths in project settings" ON)

set (TR_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (TR_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set (OUTPUT_BINDIR ${PROJECT_BINARY_DIR}/bin)
make_directory (${OUTPUT_BINDIR})
set (EXECUTABLE_OUTPUT_PATH ${OUTPUT_BINDIR})

set (OUTPUT_LIBDIR ${PROJECT_BINARY_DIR}/lib)
make_directory (${OUTPUT_LIBDIR})
set (LIBRARY_OUTPUT_PATH ${OUTPUT_LIBDIR})

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${OUTPUT_LIBDIR} CACHE PATH "build directory")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${OUTPUT_BINDIR} CACHE PATH "build directory")
if (MSVC_IDE)
	set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BINDIR} CACHE PATH "build directory")
else (MSVC_IDE)
	set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_LIBDIR} CACHE PATH "build directory")
endif (MSVC_IDE)

# For each configuration (Debug, Release, MinSizeRel... and/or anything the
# user chooses)
foreach (CONF ${CMAKE_CONFIGURATION_TYPES})
	# Go uppercase (DEBUG, RELEASE...)
	string (TOUPPER "${CONF}" CONF)
	set ("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_LIBDIR}")
	set ("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_BINDIR}")
	if (MSVC_IDE)
		set ("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_BINDIR}")
	else ()
	    set ("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_LIBDIR}")
	endif ()
endforeach ()

# Expose CMAKE_INCLUDE_PATH and CMAKE_LIBARY_PATH to the GUI so users
# may set these values without needing to manipulate the environment.
set (CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
set (CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
