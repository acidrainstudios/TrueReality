# Set the library name and preprocessing
SET(FILE_NAME trUtil)
SET(PRE_PROCESSING TR_UTIL_LIBRARY)

# Set the source and include paths
SET(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/${FILE_NAME})
SET(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
FILE (GLOB PROJECT_SOURCES "${SOURCE_PATH}/*.cpp")

# Sets the sources using "GLOB"
FILE (GLOB PROJECT_HEADERS "${HEADER_PATH}/*.h")

# Sets the libraries
SET (EXTERNAL_LIBS)
IF (TR_BUILD_WITH_RELEASE)
	SET (EXTERNAL_LIBS
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
ENDIF (TR_BUILD_WITH_RELEASE)
IF (TR_BUILD_WITH_DEBUG)
	SET (EXTERNAL_LIBS
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
ENDIF (TR_BUILD_WITH_DEBUG)

# Defines necessary preprocessor variables for project
ADD_DEFINITIONS (-D${PRE_PROCESSING})

# Sets the headers file directory in IDEs
SET (HEADERS_GROUP "Header Files")
SOURCE_GROUP (${HEADERS_GROUP} FILES ${PROJECT_HEADERS})

# Generates the shared library for the project from sources
ADD_LIBRARY (${FILE_NAME} SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
TARGET_LINK_LIBRARIES (${FILE_NAME} ${EXTERNAL_LIBS})

# Sets Project Build options
TR_TARGET_OPTIONS (${FILE_NAME})