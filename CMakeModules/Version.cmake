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


# *****************************************************************************
# Displays the current version of True Reality ********************************
# *****************************************************************************
# *****************************************************************************
# Creates and sets version variables to use through out cmake *****************
# TR_VERSION_MAJOR - the major version number *********************************
# TR_VERSION_MINOR - the minor version number *********************************
# TR_VERSION_YYMM - the Year and Month number *********************************
# TR_VERSION_BUILD - build number *********************************************
# *****************************************************************************
# TR_VERSION - The combined version number ************************************
# TR_SOVERSION - The combined version number for libraries ********************
# TR_SO_PREFIX - The prefix that is used for all TR Libraries *****************
# *****************************************************************************
SET (TR_VERSION_FILE "${CMAKE_SOURCE_DIR}/Data/Config/Version.trver")
FILE(READ ${TR_VERSION_FILE} TR_VERSION_CONTENT)

IF("${TR_VERSION_CONTENT}" STREQUAL "")
    MESSAGE("Missing the version file")
ENDIF()

STRING (REGEX MATCH "Build\" : ([0-9]+)" TR_VERSION_BUILD ${TR_VERSION_CONTENT})
STRING (REGEX MATCH "Major\" : ([0-9]+)" TR_VERSION_MAJOR ${TR_VERSION_CONTENT})
STRING (REGEX MATCH "Minor\" : ([0-9]+)" TR_VERSION_MINOR ${TR_VERSION_CONTENT})
STRING (REGEX MATCH "YYMM\" : \"([0-9]+)" TR_VERSION_YYMM ${TR_VERSION_CONTENT})
STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_BUILD ${TR_VERSION_BUILD})
STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_MAJOR ${TR_VERSION_MAJOR})
STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_MINOR ${TR_VERSION_MINOR})
STRING (REGEX REPLACE "([^0-9]+)([0-9]+)" "\\2" TR_VERSION_YYMM ${TR_VERSION_YYMM})

SET (TR_VERSION ${TR_VERSION_MAJOR}.${TR_VERSION_MINOR}.${TR_VERSION_YYMM}.${TR_VERSION_BUILD})
SET (TR_SOVERSION ${TR_VERSION_MAJOR}${TR_VERSION_MINOR})
SET (TR_SO_PREFIX "tr${TR_SOVERSION}-")
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************