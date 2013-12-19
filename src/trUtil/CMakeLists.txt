# Set the library name and preprocessing
SET(FILE_NAME trUtil)
SET(PRE_PROCESSING TR_UTIL_LIBRARY)

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
		optimized ${XERCES_LIBRARY}
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
		debug ${XERCES_LIBRARY_DEBUG}
	)
endif (TR_BUILD_WITH_DEBUG)

# Defines necessary preprocessor variables for project
add_definitions (-D${PRE_PROCESSING})

# Sets the headers file directory in IDEs
set (HEADERS_GROUP "Header Files")
source_group (${HEADERS_GROUP} FILES ${PROJECT_HEADERS})

# Generates the shared library for the project from sources
add_library (${FILE_NAME} SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
target_link_libraries (${FILE_NAME} ${EXTERNAL_LIBS})

TR_TARGET_OPTIONS (${FILE_NAME})