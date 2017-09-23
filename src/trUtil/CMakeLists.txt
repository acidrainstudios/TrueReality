# Set the library name and preprocessing
SET(FILE_NAME trUtil)
SET(PRE_PROCESSING TR_UTIL_LIBRARY)

# Set the source and include paths
SET(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/${FILE_NAME})
SET(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
FILE (GLOB BASE_SOURCES "${SOURCE_PATH}/*.cpp")
FILE (GLOB CONSOLE_SOURCES "${SOURCE_PATH}/Console/*.cpp")
FILE (GLOB LOGGING_SOURCES "${SOURCE_PATH}/Logging/*.cpp")
SET (PROJECT_SOURCES "${BASE_SOURCES};${CONSOLE_SOURCES};${LOGGING_SOURCES}")

# Sets the sources using "GLOB"
FILE (GLOB BASE_HEADERS "${HEADER_PATH}/*.h")
FILE (GLOB CONSOLE_HEADERS "${HEADER_PATH}/Console/*.h")
FILE (GLOB LOGGING_HEADERS "${HEADER_PATH}/Logging/*.h")
SET (PROJECT_HEADERS "${BASE_HEADERS};${CONSOLE_HEADERS};${LOGGING_HEADERS}")

# *****************************************************************************
# Project Folder Setup*********************************************************
# *****************************************************************************
SET (HEADERS_GROUP "Header Files")
SOURCE_GROUP (${HEADERS_GROUP} FILES ${BASE_HEADERS})
SET (SOURCES_GROUP "Source Files")
SOURCE_GROUP (${SOURCES_GROUP} FILES ${BASE_SOURCES})

# Console Groups***************************************************************
# Sets the header file folders in IDEs
SET (HEADERS_CONSOLE_GROUP "${HEADERS_GROUP}\\Console")
SOURCE_GROUP (${HEADERS_CONSOLE_GROUP} FILES ${CONSOLE_HEADERS})

# Sets the source file folders in IDEs
SET (SOURCES_CONSOLE_GROUP "${SOURCES_GROUP}\\Console")
SOURCE_GROUP (${SOURCES_CONSOLE_GROUP} FILES ${CONSOLE_SOURCES})

# Logging Groups***************************************************************
# Sets the header file folders in IDEs
SET (HEADERS_LOGGING_GROUP "${HEADERS_GROUP}\\Logging")
SOURCE_GROUP (${HEADERS_LOGGING_GROUP} FILES ${LOGGING_HEADERS})

# Sets the source file folders in IDEs
SET (SOURCES_LOGGING_GROUP "${SOURCES_GROUP}\\Logging")
SOURCE_GROUP (${SOURCES_LOGGING_GROUP} FILES ${LOGGING_SOURCES})

# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

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

# Defines necessary preprocessor variables for project
ADD_DEFINITIONS (-D${PRE_PROCESSING})

# Generates the shared library for the project from sources
ADD_LIBRARY (${FILE_NAME} SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
TARGET_LINK_LIBRARIES (${FILE_NAME} ${EXTERNAL_LIBS})

# Sets Project Build options
TR_TARGET_OPTIONS (${FILE_NAME})