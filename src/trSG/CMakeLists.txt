# True Reality Open Source Game and Simulation Engine
# Copyright © 2018 Acid Rain Studios LLC
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
SET (FILE_NAME trSG)
SET (PRE_PROCESSING TR_SG_LIBRARY)

# Set the source and include paths
SET (HEADER_PATH ${CMAKE_SOURCE_DIR}/include/${FILE_NAME})
SET (SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
FILE (GLOB PROJECT_SOURCES "${SOURCE_PATH}/*.cpp")
SET (PROJECT_BUILDABLE_SOURCES ${PROJECT_SOURCES})

# Sets the sources using "GLOB"
FILE (GLOB BASE_HEADERS "${HEADER_PATH}/*.h")
FILE (GLOB BASE_GEN_HEADERS "${PROJECT_BINARY_DIR}/include/${FILE_NAME}/*.h")
SET (PROJECT_HEADERS "${BASE_HEADERS};${BASE_GEN_HEADERS}")

# *****************************************************************************
# Project Folder Setup ********************************************************
# *****************************************************************************
# Sets the header file folders in IDEs
SET (HEADERS_GROUP "Header Files")
SOURCE_GROUP (${HEADERS_GROUP} FILES ${BASE_HEADERS} ${BASE_GEN_HEADERS})

# Sets the source file folders in IDEs
SET (SOURCES_GROUP "Source Files")
SOURCE_GROUP (${SOURCES_GROUP} FILES ${PROJECT_SOURCES})
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Sets the libraries
SET (EXTERNAL_LIBS)
IF (TR_BUILD_WITH_RELEASE)
    SET (EXTERNAL_LIBS
        ${EXTERNAL_LIBS}
        optimized ${OpenThreads_LIBRARY}
        optimized ${OSG_LIBRARY} 
        optimized ${OSG_DB_LIBRARY} 
        optimized ${OSG_GA_LIBRARY} 
        optimized ${OSG_VIEWER_LIBRARY} 
    )
ENDIF ()
IF (TR_BUILD_WITH_DEBUG)
    SET (EXTERNAL_LIBS
        ${EXTERNAL_LIBS}
        debug ${OpenThreads_LIBRARY_DEBUG}
        debug ${OSG_LIBRARY_DEBUG}
        debug ${OSG_DB_LIBRARY_DEBUG} 
        debug ${OSG_GA_LIBRARY_DEBUG}
        debug ${OSG_VIEWER_LIBRARY_DEBUG}
    )
ENDIF ()

# Defines necessary preprocessor variables for project
ADD_DEFINITIONS (-D${PRE_PROCESSING})

# Generates the shared library for the project from sources
ADD_LIBRARY (${FILE_NAME} SHARED ${PROJECT_HEADERS} ${PROJECT_BUILDABLE_SOURCES})

# Links the external libraries to the newly created library
TARGET_LINK_LIBRARIES (${FILE_NAME} ${EXTERNAL_LIBS} trUtil)

# Place the project in a folder
SET_TARGET_PROPERTIES (${FILE_NAME} PROPERTIES FOLDER "TrueRealitySDK")

# Sets Project Build options
TR_TARGET_OPTIONS (${FILE_NAME})

# Sets Project Install options
TR_INSTALL_OPTIONS (${FILE_NAME})