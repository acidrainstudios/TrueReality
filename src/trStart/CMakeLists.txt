# True Reality Open Source Game and Simulation Engine
# Copyright © 2019 Acid Rain Studios LLC
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

# Set the executable name
SET (FILE_NAME trStart)

# Set the source and include paths
SET (HEADER_PATH ${CMAKE_SOURCE_DIR}/include/${FILE_NAME})
SET (SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
FILE (GLOB PROJECT_SOURCES "${SOURCE_PATH}/*.cpp")

# Sets the sources using "GLOB"
FILE (GLOB BASE_HEADERS "${HEADER_PATH}/*.h")
FILE (GLOB BASE_GEN_HEADERS "${PROJECT_BINARY_DIR}/include/${FILE_NAME}/*.h")
SET (PROJECT_HEADERS "${BASE_HEADERS};${BASE_GEN_HEADERS}")

# Sets the dependency libraries
SET (EXTERNAL_LIBS
    ${EXTERNAL_LIBS}
    optimized ${OpenThreads_LIBRARY}
    debug ${OpenThreads_LIBRARY_DEBUG}

    optimized ${OSG_LIBRARY} 
    debug ${OSG_LIBRARY_DEBUG}

    optimized ${OSG_DB_LIBRARY} 
    debug ${OSG_DB_LIBRARY_DEBUG} 
)

# *****************************************************************************
# Project Folder Setup ********************************************************
# *****************************************************************************
# Sets the headers file directory in IDEs
SET (HEADERS_GROUP "Header Files")
SOURCE_GROUP (${HEADERS_GROUP} FILES ${BASE_HEADERS} ${BASE_GEN_HEADERS})
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************

# Generates the executable for the project from sources
ADD_EXECUTABLE (${FILE_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
TARGET_LINK_LIBRARIES (${FILE_NAME} ${EXTERNAL_LIBS} trUtil trCore)

# Place the project in a folder
SET_TARGET_PROPERTIES (${FILE_NAME} PROPERTIES FOLDER "Utilities")

# Sets Project Build options
TR_TARGET_OPTIONS (${FILE_NAME})

# Sets Project Install options
TR_INSTALL_OPTIONS (${FILE_NAME})