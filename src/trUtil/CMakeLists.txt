# True Reality Open Source Game and Simulation Engine
# Copyright � 2018 Acid Rain Studios LLC
#
# This library is free software; you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation; either version 3.0 of the License, or (at your option)
# any later version.
#
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# @author Maxim Serebrennik

# Set the library name and preprocessing
SET (FILE_NAME trUtil)
SET (PRE_PROCESSING TR_UTIL_LIBRARY)

# Set the source and include paths
SET (HEADER_PATH ${CMAKE_SOURCE_DIR}/include/${FILE_NAME})
SET (SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
FILE (GLOB BASE_SOURCES "${SOURCE_PATH}/*.cpp")
FILE (GLOB CONSOLE_SOURCES    "${SOURCE_PATH}/Console/*.cpp")
FILE (GLOB LOGGING_SOURCES    "${SOURCE_PATH}/Logging/*.cpp")
FILE (GLOB JSON_SOURCES        "${SOURCE_PATH}/JSON/*.cpp")
SET (PROJECT_SOURCES "${BASE_SOURCES};${CONSOLE_SOURCES};${LOGGING_SOURCES};${JSON_SOURCES}")

# Sets the sources using "GLOB"
FILE (GLOB BASE_HEADERS "${HEADER_PATH}/*.h")
FILE (GLOB BASE_GEN_HEADERS "${PROJECT_BINARY_DIR}/include/${FILE_NAME}/*.h")
FILE (GLOB CONSOLE_HEADERS    "${HEADER_PATH}/Console/*.h")
FILE (GLOB LOGGING_HEADERS    "${HEADER_PATH}/Logging/*.h")
FILE (GLOB JSON_HEADERS        "${HEADER_PATH}/JSON/*.h")
SET (PROJECT_HEADERS "${BASE_HEADERS};${BASE_GEN_HEADERS};${CONSOLE_HEADERS};${LOGGING_HEADERS};${JSON_HEADERS}")

# *****************************************************************************
# Project Folder Setup*********************************************************
# *****************************************************************************
SET (HEADERS_GROUP "Header Files")
SOURCE_GROUP (${HEADERS_GROUP} FILES ${BASE_HEADERS} ${BASE_GEN_HEADERS})
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

# Json Groups******************************************************************
# Sets the header file folders in IDEs
SET (HEADERS_JSON_GROUP "${HEADERS_GROUP}\\JSON")
SOURCE_GROUP (${HEADERS_JSON_GROUP} FILES ${JSON_HEADERS})

# Sets the source file folders in IDEs
SET (SOURCES_JSON_GROUP "${SOURCES_GROUP}\\JSON")
SOURCE_GROUP (${SOURCES_JSON_GROUP} FILES ${JSON_SOURCES})

# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Sets the dependency libraries
SET (EXTERNAL_LIBS
    ${EXTERNAL_LIBS}
    optimized ${OpenThreads_LIBRARY}
    debug ${OpenThreads_LIBRARY_DEBUG}

    optimized ${OSG_LIBRARY} 
    debug ${OSG_LIBRARY_DEBUG}

    optimized ${OSG_DB_LIBRARY} 
    debug ${OSG_DB_LIBRARY_DEBUG}

    optimized ${JsonCpp_LIBRARY}
    debug ${JsonCpp_LIBRARY_DEBUG}
)

# Defines necessary preprocessor variables for project
ADD_DEFINITIONS (-D${PRE_PROCESSING})

# Generates the shared library for the project from sources
ADD_LIBRARY (${FILE_NAME} SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
TARGET_LINK_LIBRARIES (${FILE_NAME} ${EXTERNAL_LIBS})

# Place the project in a folder
SET_TARGET_PROPERTIES (${FILE_NAME} PROPERTIES FOLDER "TrueRealitySDK")

# Sets Project Build options
TR_TARGET_OPTIONS (${FILE_NAME})

# Sets Project Install options
TR_INSTALL_OPTIONS (${FILE_NAME})