# True Reality Open Source Game and Simulation Engine
# Copyright © 2021 Acid Rain Studios LLC
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
# Sets up flags to track what folders and objects have been installed *********
# *****************************************************************************
SET (TR_DATA_INSTALLED "0" CACHE INTERNAL "System Use only: flag to show that Data was installed" FORCE)
SET (TR_EXT_INSTALLED "0" CACHE INTERNAL "System Use only: flag to show that Ext was installed" FORCE)
SET (TR_HEADERS_INSTALLED "0" CACHE INTERNAL "System Use only: flag to show that Headers were installed" FORCE)

# *****************************************************************************
# Sets up default Windows install folders
# *****************************************************************************

IF (WIN32 AND NOT PATH_IS_SET)
    IF (CMAKE_SIZEOF_VOID_P MATCHES "8")
        SET (CMAKE_INSTALL_PREFIX "C:/Program Files/${CMAKE_PROJECT_NAME}" CACHE STRING "Install Path" FORCE)
    ELSE ()
        SET (CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/${CMAKE_PROJECT_NAME}" CACHE STRING "Install Path" FORCE)
    ENDIF ()
    SET (PATH_IS_SET "YES" CACHE INTERNAL "Install Path Flag" FORCE)
ENDIF ()

# *****************************************************************************
# Configures the installation options for the given project *******************
# *****************************************************************************
MACRO (TR_INSTALL_OPTIONS arg)
    IF (TR_DATA_INSTALLED EQUAL 0)
        INSTALL (CODE "MESSAGE(\"Installing the Data folder.\")")
        INSTALL (DIRECTORY "${CMAKE_SOURCE_DIR}/Data" DESTINATION .)
        SET (TR_DATA_INSTALLED "1" CACHE INTERNAL "System Use only: flag to show that Data was installed" FORCE)
    ENDIF ()

    IF (TR_EXT_INSTALLED EQUAL 0)
        INSTALL (CODE "MESSAGE(\"Installing the External Dependencies.\")")
        IF (EXISTS "${CMAKE_SOURCE_DIR}/Ext")
			IF (TR_INSTALL_INTEGRATED_EXT)
				INSTALL (DIRECTORY "${CMAKE_SOURCE_DIR}/Ext/"    DESTINATION .)
			ELSE ()
				INSTALL (DIRECTORY "${CMAKE_SOURCE_DIR}/Ext"    DESTINATION .)
			ENDIF ()
            SET (TR_EXT_INSTALLED "1" CACHE INTERNAL "System Use only: flag to show that the Ext folder was installed" FORCE)
        ELSE ()
            INSTALL (CODE "MESSAGE(\"Ext folder is missing from ${CMAKE_SOURCE_DIR}\")")
		ENDIF ()
    ENDIF ()

    IF (TR_HEADERS_INSTALLED EQUAL 0)
        INSTALL (CODE "MESSAGE(\"Installing the SDKs headers folder.\")")
        INSTALL (DIRECTORY "${CMAKE_SOURCE_DIR}/include" DESTINATION .)
		IF(EXISTS "${PROJECT_BINARY_DIR}/include")
			INSTALL (DIRECTORY "${PROJECT_BINARY_DIR}/include" DESTINATION .)
		ENDIF ()

        SET (TR_HEADERS_INSTALLED "1" CACHE INTERNAL "System Use only: flag to show that headers were installed" FORCE)
    ENDIF ()

    INSTALL (CODE "MESSAGE(\"Installing the ${arg} project.\")")
    INSTALL (
            TARGETS ${arg}
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib
            )
ENDMACRO ()

# *****************************************************************************
# Configures the installation options for the environment scripts project *****
# *****************************************************************************
MACRO (TR_INSTALL_SCRIPT_FILES filesList)
    IF (WIN32)
        INSTALL (CODE "MESSAGE(\"Installing the Environment Scripts.\")")
	    INSTALL (FILES ${filesList} DESTINATION $ENV{windir})
    ELSEIF (UNIX)
        INSTALL (CODE "MESSAGE(\"Installing the Environment Scripts.\")")
	    INSTALL (FILES ${filesList} DESTINATION /usr/local/bin PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
    ENDIF ()
ENDMACRO ()

# *****************************************************************************
# Configures the build folder, making sure it has all the needed data files ***
# *****************************************************************************
MACRO (TR_INSTALL_BUILD_OPTIONS)
    MESSAGE (STATUS "Copying the Data folder to ${CMAKE_BINARY_DIR} \n")
    FILE (COPY "${CMAKE_SOURCE_DIR}/Data" DESTINATION .)
ENDMACRO ()