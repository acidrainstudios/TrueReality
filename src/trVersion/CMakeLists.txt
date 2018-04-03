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
# Author: Maxim Serebrennik

# Set the executable name
SET(FILE_NAME trVersion)

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
		optimized ${OpenThreads_LIBRARY}
		optimized ${OSG_LIBRARY} 
        optimized ${OSG_DB_LIBRARY} 
	)
ENDIF (TR_BUILD_WITH_RELEASE)
IF (TR_BUILD_WITH_DEBUG)
	SET (EXTERNAL_LIBS
		${EXTERNAL_LIBS}
		debug ${OpenThreads_LIBRARY_DEBUG}
		debug ${OSG_LIBRARY_DEBUG}
        debug ${OSG_DB_LIBRARY_DEBUG} 
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
SET_TARGET_PROPERTIES (${FILE_NAME} PROPERTIES FOLDER "Utilities")

# Sets Project Build options
TR_TARGET_OPTIONS (${FILE_NAME})