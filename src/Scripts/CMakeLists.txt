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

SET (FILE_NAME Scripts)

# *****************************************************************************
# Create Environment Scripts **************************************************
# *****************************************************************************
IF (WIN32)
	MESSAGE (STATUS "Creating Windows Environment Scripts (Admin rights are needed to install scripts)")

	SET (PATH_TITLE "echo Setting up True Reality ${TR_VERSION} Build Environment")
	SET (PATH_CMD "SET PATH=${CMAKE_INSTALL_PREFIX}/bin;${CMAKE_INSTALL_PREFIX}/lib;${CMAKE_INSTALL_PREFIX}/include;%PATH%")
	SET (PATH_TR_ROOT "SET TR_ROOT=${CMAKE_INSTALL_PREFIX}")
	CONFIGURE_FILE ("${CMAKE_SOURCE_DIR}/src/Scripts/EnvScript.in" "${PROJECT_BINARY_DIR}/src/${FILE_NAME}/trEnv-${TR_VERSION_MAJOR}.${TR_VERSION_MINOR}.${TR_VERSION_YYMM}.cmd" NEWLINE_STYLE LF)

	SET (PATH_TITLE "echo Setting up True Reality ${TR_VERSION} Runtime Environment")
	SET (PATH_CMD "SET PATH=${CMAKE_INSTALL_PREFIX}/bin;${CMAKE_INSTALL_PREFIX}/lib;%PATH%")
	SET (PATH_TR_ROOT "SET TR_ROOT=${CMAKE_INSTALL_PREFIX}")
	CONFIGURE_FILE ("${CMAKE_SOURCE_DIR}/src/Scripts/EnvScript.in" "${PROJECT_BINARY_DIR}/src/${FILE_NAME}/trEnvRT-${TR_VERSION_MAJOR}.${TR_VERSION_MINOR}.${TR_VERSION_YYMM}.cmd" NEWLINE_STYLE LF)
ENDIF ()

# Set the source paths
SET (SOURCE_PATH ${PROJECT_BINARY_DIR}/src/${FILE_NAME})

# Sets the sources using "GLOB"
FILE (GLOB PROJECT_SOURCES "${SOURCE_PATH}/trEnv*.*")

# Generates the target for the project from sources
ADD_CUSTOM_TARGET (${FILE_NAME} SOURCES ${PROJECT_SOURCES})

# Place the project in a folder
SET_TARGET_PROPERTIES (${FILE_NAME} PROPERTIES FOLDER "ContentInstalls")

# Sets Project Install options
TR_INSTALL_SCRIPT_FILES ("${PROJECT_SOURCES}")