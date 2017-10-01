# Set the executable name
SET(FILE_NAME exampleJSON)

# Set the source and include paths
SET(HEADER_PATH ${CMAKE_SOURCE_DIR}/Examples/Json)
SET(SOURCE_PATH ${CMAKE_SOURCE_DIR}/Examples/Json)

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
		optimized ${JSON_CPP_LIBRARY} 
	)
ENDIF (TR_BUILD_WITH_RELEASE)
IF (TR_BUILD_WITH_DEBUG)
	SET (EXTERNAL_LIBS
		${EXTERNAL_LIBS}
		debug ${OPENTHREADS_LIBRARY_DEBUG}
		debug ${OSG_LIBRARY_DEBUG}
        debug ${OSG_DB_LIBRARY_DEBUG} 
		debug ${JSON_CPP_LIBRARY_DEBUG}
	)
ENDIF (TR_BUILD_WITH_DEBUG)

# Sets the headers file directory in IDEs
SET (HEADERS_GROUP "Header Files")
SOURCE_GROUP (${HEADERS_GROUP} FILES ${PROJECT_HEADERS})

# Generates the executable for the project from sources
ADD_EXECUTABLE (${FILE_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
TARGET_LINK_LIBRARIES (${FILE_NAME} ${EXTERNAL_LIBS} trUtil)

# Place the project in a folder
SET_TARGET_PROPERTIES (${FILE_NAME} PROPERTIES FOLDER "Examples")

TR_TARGET_OPTIONS (${FILE_NAME})