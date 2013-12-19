# Set the executable name
SET(FILE_NAME trStart)

# Set the source and include paths
SET(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/${FILE_NAME})
SET(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
file (GLOB PROJECT_SOURCES "${SOURCE_PATH}/*.cpp")

# Sets the sources using "GLOB"
file (GLOB PROJECT_HEADERS "${HEADER_PATH}/*.h")

# Sets the libraries
SET (EXTERNAL_LIBS)
if (TR_BUILD_WITH_RELEASE)
	set (EXTERNAL_LIBS
		${EXTERNAL_LIBS}
		optimized ${OPENTHREADS_LIBRARY}
		optimized ${OSG_LIBRARY} 
        optimized ${OSG_DB_LIBRARY} 
		optimized ${DELTA3D_ABC_LIBRARY}
		optimized ${DELTA3D_CORE_LIBRARY}
		optimized ${DELTA3D_GAME_LIBRARY}
		optimized ${DELTA3D_UTIL_LIBRARY}
		optimized ${DELTA3D_ACTORS_LIBRARY}
	)
endif (TR_BUILD_WITH_RELEASE)
if (TR_BUILD_WITH_DEBUG)
	set (EXTERNAL_LIBS
		${EXTERNAL_LIBS}
		debug ${OPENTHREADS_LIBRARY_DEBUG}
		debug ${OSG_LIBRARY_DEBUG}
        debug ${OSG_DB_LIBRARY_DEBUG} 
		debug ${DELTA3D_ABC_LIBRARY_DEBUG}
		debug ${DELTA3D_CORE_LIBRARY_DEBUG}
		debug ${DELTA3D_GAME_LIBRARY_DEBUG}
		debug ${DELTA3D_UTIL_LIBRARY_DEBUG}
		debug ${DELTA3D_ACTORS_LIBRARY_DEBUG}
	)
endif (TR_BUILD_WITH_DEBUG)

# Sets the headers file directory in IDEs
set (HEADERS_GROUP "Header Files")
source_group (${HEADERS_GROUP} FILES ${PROJECT_HEADERS})

# Generates the executable for the project from sources
add_executable (${FILE_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
target_link_libraries (${FILE_NAME} ${EXTERNAL_LIBS} trUtil trCore)

TR_TARGET_OPTIONS (${FILE_NAME})