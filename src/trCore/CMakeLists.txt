# True Reality Open Source Game and Simulation Engine
# Copyright © 2017 Acid Rain Studios LLC
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

# Set the library name and preprocessing
SET(FILE_NAME trCore)
SET(PRE_PROCESSING TR_CORE_LIBRARY)

# Set the source and include paths
SET(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/${FILE_NAME})
SET(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
FILE (GLOB PROJECT_SOURCES "${SOURCE_PATH}/*.cpp")

# Sets the sources using "GLOB"
FILE (GLOB PROJECT_HEADERS "${HEADER_PATH}/*.h")

# Sets the header file folders in IDEs
SET (HEADERS_GROUP "Header Files")
SOURCE_GROUP (${HEADERS_GROUP} FILES ${PROJECT_HEADERS})

# Sets the source file folders in IDEs
SET (SOURCES_GROUP "Source Files")
SOURCE_GROUP (${SOURCES_GROUP} FILES ${PROJECT_SOURCES})

# Sets the libraries
SET (EXTERNAL_LIBS)
IF (TR_BUILD_WITH_RELEASE)
	SET (EXTERNAL_LIBS
		${EXTERNAL_LIBS}
		optimized ${OPENTHREADS_LIBRARY}
		optimized ${OSG_LIBRARY} 
        optimized ${OSG_DB_LIBRARY} 
        optimized ${OSG_GA_LIBRARY} 
		optimized ${OSG_VIEWER_LIBRARY} 
	)
ENDIF (TR_BUILD_WITH_RELEASE)
IF (TR_BUILD_WITH_DEBUG)
	SET (EXTERNAL_LIBS
		${EXTERNAL_LIBS}
		debug ${OPENTHREADS_LIBRARY_DEBUG}
		debug ${OSG_LIBRARY_DEBUG}
        debug ${OSG_DB_LIBRARY_DEBUG} 
		debug ${OSG_GA_LIBRARY_DEBUG}
		debug ${OSG_VIEWER_LIBRARY_DEBUG}
	)
ENDIF (TR_BUILD_WITH_DEBUG)

# Defines necessary preprocessor variables for project
ADD_DEFINITIONS (-D${PRE_PROCESSING})

# Generates the shared library for the project from sources
ADD_LIBRARY (${FILE_NAME} SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Links the external libraries to the newly created library
TARGET_LINK_LIBRARIES (${FILE_NAME} ${EXTERNAL_LIBS} trUtil trBase)

# Place the project in a folder
SET_TARGET_PROPERTIES (${FILE_NAME} PROPERTIES FOLDER "TrueRealitySDK")

# Sets Project Build options
TR_TARGET_OPTIONS (${FILE_NAME})