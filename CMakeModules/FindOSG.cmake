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

#find_package(OpenSceneGraph ${OSG_FIND_VERSION} REQUIRED
#osg
#osgAnimation
#osgDB
##osgEphemeris
#osgFX
#osgGA
#osgManipulator
#osgParticle
##osgPPU
#osgPresentation
#osgShadow
#osgSim
#osgTerrain
#osgText
#osgUI
#osgUtil
#osgViewer
#osgVolume
#osgWidget
#)

# Finds the include files necessary for compilation
FIND_PATH (OSG_INCLUDE_DIR osg/Referenced
    HINTS
    $ENV{TR_INC}
    $ENV{TR_ROOT}/Ext/include
    $ENV{TR_ROOT}/Ext
    $ENV{TR_ROOT}/include
    $ENV{TR_ROOT}
    $ENV{OSG_INC}
    $ENV{OSG_ROOT}/include
    $ENV{OSG_ROOT}
    PATHS
    /usr/include
    /usr/local/include
    ~/Library/Frameworks
    /Library/Frameworks
)
MARK_AS_ADVANCED (OSG_INCLUDE_DIR)

MACRO (FIND_OSG_LIBRARY MYLIBRARY MYLIBRARYNAME)
    # Finds the library files necessary for compilation
    FIND_LIBRARY (${MYLIBRARY}
		NAMES ${MYLIBRARYNAME}
		HINTS
		$ENV{TR_ROOT}/Ext/lib64
		$ENV{TR_ROOT}/Ext/lib
		$ENV{TR_ROOT}/Ext
		$ENV{TR_LIB}
		$ENV{TR_ROOT}/lib
		$ENV{TR_ROOT}
		$ENV{OSG_LIB}
		$ENV{OSG_ROOT}/lib64
		$ENV{OSG_ROOT}/lib
		$ENV{OSG_ROOT}
		PATHS
		/usr/lib64
		/usr/lib
		/usr/local/lib64
		/usr/local/lib
		~/Library/Frameworks
		/Library/Frameworks
    )
    MARK_AS_ADVANCED (${MYLIBRARY})
ENDMACRO(FIND_OSG_LIBRARY MYLIBRARY MYLIBRARYNAME)

# Try to ascertain the version...
IF(OSG_INCLUDE_DIR)
    IF(OpenSceneGraph_DEBUG)
        MESSAGE(STATUS "[ FindOpenSceneGraph.cmake:${CMAKE_CURRENT_LIST_LINE} ] "
            "Detected OSG_INCLUDE_DIR = ${OSG_INCLUDE_DIR}")
    ENDIF()

    SET(_osg_Version_file "${OSG_INCLUDE_DIR}/osg/Version")
    IF("${OSG_INCLUDE_DIR}" MATCHES "\\.framework$" AND NOT EXISTS "${_osg_Version_file}")
        SET(_osg_Version_file "${OSG_INCLUDE_DIR}/Headers/Version")
    ENDIF()

    IF(EXISTS "${_osg_Version_file}")
      FILE(STRINGS "${_osg_Version_file}" _osg_Version_contents
           REGEX "#define (OSG_VERSION_[A-Z]+|OPENSCENEGRAPH_[A-Z]+_VERSION)[ \t]+[0-9]+")
    ELSE()
      SET(_osg_Version_contents "unknown")
    ENDIF()

    STRING(REGEX MATCH ".*#define OSG_VERSION_MAJOR[ \t]+[0-9]+.*"
        _osg_old_defines "${_osg_Version_contents}")
    STRING(REGEX MATCH ".*#define OPENSCENEGRAPH_MAJOR_VERSION[ \t]+[0-9]+.*"
        _osg_new_defines "${_osg_Version_contents}")
    IF(_osg_old_defines)
        STRING(REGEX REPLACE ".*#define OSG_VERSION_MAJOR[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MAJOR ${_osg_Version_contents})
        STRING(REGEX REPLACE ".*#define OSG_VERSION_MINOR[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MINOR ${_osg_Version_contents})
        STRING(REGEX REPLACE ".*#define OSG_VERSION_PATCH[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_PATCH ${_osg_Version_contents})
    ELSEIF(_osg_new_defines)
        STRING(REGEX REPLACE ".*#define OPENSCENEGRAPH_MAJOR_VERSION[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MAJOR ${_osg_Version_contents})
        STRING(REGEX REPLACE ".*#define OPENSCENEGRAPH_MINOR_VERSION[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MINOR ${_osg_Version_contents})
        STRING(REGEX REPLACE ".*#define OPENSCENEGRAPH_PATCH_VERSION[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_PATCH ${_osg_Version_contents})
    ELSE()
        MESSAGE(WARNING "[ FindOpenSceneGraph.cmake:${CMAKE_CURRENT_LIST_LINE} ] "
            "Failed to parse version number, please report this as a bug")
    ENDIF()
    UNSET(_osg_Version_contents)

    SET(OPENSCENEGRAPH_VERSION "${_osg_VERSION_MAJOR}.${_osg_VERSION_MINOR}.${_osg_VERSION_PATCH}"
                                CACHE INTERNAL "The version of OSG which was detected")
    IF(OpenSceneGraph_DEBUG)
        MESSAGE(STATUS "[ FindOpenSceneGraph.cmake:${CMAKE_CURRENT_LIST_LINE} ] "
            "Detected version ${OPENSCENEGRAPH_VERSION}")
    ENDIF()
ENDIF()

IF (TR_BUILD_WITH_RELEASE)
    # Locates all OSG release libraries
    FIND_OSG_LIBRARY (OSG_LIBRARY osg)
    FIND_OSG_LIBRARY (OSG_ANIMATION_LIBRARY osgAnimation)
    FIND_OSG_LIBRARY (OSG_DB_LIBRARY osgDB)
    FIND_OSG_LIBRARY (OSG_EPHEMERIS_LIBRARY osgEphemeris)
    FIND_OSG_LIBRARY (OSG_FX_LIBRARY osgFX)
    FIND_OSG_LIBRARY (OSG_GA_LIBRARY osgGA)
    FIND_OSG_LIBRARY (OSG_MANIPULATOR_LIBRARY osgManipulator)
    FIND_OSG_LIBRARY (OSG_PARTICLE_LIBRARY osgParticle)
    FIND_OSG_LIBRARY (OSG_PPU_LIBRARY osgPPU)
    FIND_OSG_LIBRARY (OSG_PRESENTATION_LIBRARY osgPresentation)
    FIND_OSG_LIBRARY (OSG_SHADOW_LIBRARY osgShadow)
    FIND_OSG_LIBRARY (OSG_SIM_LIBRARY osgSim)
    FIND_OSG_LIBRARY (OSG_TERRAIN_LIBRARY osgTerrain)
    FIND_OSG_LIBRARY (OSG_TEXT_LIBRARY osgText)
    FIND_OSG_LIBRARY (OSG_UI_LIBRARY osgUI)
    FIND_OSG_LIBRARY (OSG_UTIL_LIBRARY osgUtil)
    FIND_OSG_LIBRARY (OSG_VIEWER_LIBRARY osgViewer)
    FIND_OSG_LIBRARY (OSG_VOLUME_LIBRARY osgVolume)
    FIND_OSG_LIBRARY (OSG_WIDGET_LIBRARY osgWidget)
ENDIF (TR_BUILD_WITH_RELEASE)

IF (TR_BUILD_WITH_DEBUG)
    # Locates all OSG debug libraries
    FIND_OSG_LIBRARY (OSG_LIBRARY_DEBUG osgd)
    FIND_OSG_LIBRARY (OSG_ANIMATION_LIBRARY_DEBUG osgAnimationd)
    FIND_OSG_LIBRARY (OSG_DB_LIBRARY_DEBUG osgDBd)
    FIND_OSG_LIBRARY (OSG_EPHEMERIS_LIBRARY_DEBUG osgEphemerisd)
    FIND_OSG_LIBRARY (OSG_FX_LIBRARY_DEBUG osgFXd)
    FIND_OSG_LIBRARY (OSG_GA_LIBRARY_DEBUG osgGAd)
    FIND_OSG_LIBRARY (OSG_MANIPULATOR_LIBRARY_DEBUG osgManipulatord)
    FIND_OSG_LIBRARY (OSG_PARTICLE_LIBRARY_DEBUG osgParticled)
    FIND_OSG_LIBRARY (OSG_PPU_LIBRARY_DEBUG osgPPUd)
    FIND_OSG_LIBRARY (OSG_PRESENTATION_LIBRARY_DEBUG osgPresentationd)
    FIND_OSG_LIBRARY (OSG_SHADOW_LIBRARY_DEBUG osgShadowd)
    FIND_OSG_LIBRARY (OSG_SIM_LIBRARY_DEBUG osgSimd)
    FIND_OSG_LIBRARY (OSG_TERRAIN_LIBRARY_DEBUG osgTerraind)
    FIND_OSG_LIBRARY (OSG_TEXT_LIBRARY_DEBUG osgTextd)
    FIND_OSG_LIBRARY (OSG_UI_LIBRARY_DEBUG osgUId)
    FIND_OSG_LIBRARY (OSG_UTIL_LIBRARY_DEBUG osgUtild)
    FIND_OSG_LIBRARY (OSG_VIEWER_LIBRARY_DEBUG osgViewerd)
    FIND_OSG_LIBRARY (OSG_VOLUME_LIBRARY_DEBUG osgVolumed)
    FIND_OSG_LIBRARY (OSG_WIDGET_LIBRARY_DEBUG osgWidgetd)
ENDIF (TR_BUILD_WITH_DEBUG)

SET (DEPENDENCY_FOUND "NO")
IF (OSG_LIBRARY AND OSG_INCLUDE_DIR)
    SET (DEPENDENCY_FOUND "YES")
    
    IF(OSG_FIND_VERSION)
        CHECK_VERSION("OSG" ${OPENSCENEGRAPH_VERSION} ${OSG_FIND_VERSION})	
    ELSE()
        MESSAGE(STATUS "OSG Version: ${OPENSCENEGRAPH_VERSION}")
    ENDIF()

ENDIF (OSG_LIBRARY AND OSG_INCLUDE_DIR)