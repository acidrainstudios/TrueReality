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
# Configures the installation options for the given project *******************
# *****************************************************************************
MACRO (TR_INSTALL_OPTIONS arg)
    IF(TR_DATA_INSTALLED EQUAL 0)      
        SET (TR_DATA_INSTALLED "1" CACHE INTERNAL "System Use only: flag to show that Data was installed" FORCE)
        INSTALL(CODE "MESSAGE(\"Installing the Data folder.\")")
        IF (MSVC_IDE)
            INSTALL(DIRECTORY "${CMAKE_SOURCE_DIR}/Data" DESTINATION .)
	    ELSEIF (UNIX)
            INSTALL(DIRECTORY "${CMAKE_SOURCE_DIR}/Data" DESTINATION ${PROJECT_NAME})
        ENDIF (MSVC_IDE)
    ENDIF()
    
    INSTALL(CODE "MESSAGE(\"Installing the ${arg} project.\")")
    IF (MSVC_IDE)
        INSTALL(
            TARGETS ${arg}
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib
            )
	ELSEIF (UNIX)
        INSTALL(
            TARGETS ${arg}
            RUNTIME DESTINATION ${PROJECT_NAME}/bin
            LIBRARY DESTINATION ${PROJECT_NAME}/lib
            ARCHIVE DESTINATION ${PROJECT_NAME}/lib
            )
    ENDIF (MSVC_IDE)
ENDMACRO (TR_INSTALL_OPTIONS arg)

# *****************************************************************************
# Configures the build folder, making sure it has all the needed data files ***
# *****************************************************************************
MACRO (TR_INSTALL_BUILD_OPTIONS)
#IF(CMAKE_BUILD_DIRECTORY NOT EQUAL PROJECT_VERSION)
        MESSAGE (STATUS "Copying the Data folder to ${CMAKE_BINARY_DIR} \n")
        IF (MSVC_IDE)
            FILE(COPY "${CMAKE_SOURCE_DIR}/Data" DESTINATION .)
            #INSTALL(DIRECTORY "${CMAKE_SOURCE_DIR}/Data" DESTINATION .)
	    ELSEIF (UNIX)
            FILE(COPY "${CMAKE_SOURCE_DIR}/Data" DESTINATION ${PROJECT_NAME})
            #INSTALL(DIRECTORY "${CMAKE_SOURCE_DIR}/Data" DESTINATION ${PROJECT_NAME})
        ENDIF (MSVC_IDE)
ENDMACRO (TR_INSTALL_BUILD_OPTIONS)