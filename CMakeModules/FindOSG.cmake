# Finds the include files necessary for compilation
find_path (OSG_INCLUDE_DIR osg/Referenced
    HINTS
    $ENV{TR_INC}
    $ENV{TR_ROOT}/Ext/include
    $ENV{TR_ROOT}/Ext
    $ENV{TR_ROOT}/include
    $ENV{TR_ROOT}
    $ENV{OSG_INC}
    $ENV{OSG_ROOT}/include
    $ENV{OSG_ROOT}
)
mark_as_advanced (OSG_INCLUDE_DIR)

macro (FIND_OSG_LIBRARY MYLIBRARY MYLIBRARYNAME)
    # Finds the library files necessary for compilation
    find_library (${MYLIBRARY}
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
    )
    mark_as_advanced (${MYLIBRARY})
endmacro(FIND_OSG_LIBRARY MYLIBRARY MYLIBRARYNAME)

if (TR_BUILD_WITH_RELEASE)
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
endif (TR_BUILD_WITH_RELEASE)

if (TR_BUILD_WITH_DEBUG)
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
endif (TR_BUILD_WITH_DEBUG)

# Try to ascertain the version...
if(OSG_INCLUDE_DIR)
    if(OpenSceneGraph_DEBUG)
        message(STATUS "[ FindOpenSceneGraph.cmake:${CMAKE_CURRENT_LIST_LINE} ] "
            "Detected OSG_INCLUDE_DIR = ${OSG_INCLUDE_DIR}")
    endif()

    set(_osg_Version_file "${OSG_INCLUDE_DIR}/osg/Version")
    if("${OSG_INCLUDE_DIR}" MATCHES "\\.framework$" AND NOT EXISTS "${_osg_Version_file}")
        set(_osg_Version_file "${OSG_INCLUDE_DIR}/Headers/Version")
    endif()

    if(EXISTS "${_osg_Version_file}")
      file(STRINGS "${_osg_Version_file}" _osg_Version_contents
           REGEX "#define (OSG_VERSION_[A-Z]+|OPENSCENEGRAPH_[A-Z]+_VERSION)[ \t]+[0-9]+")
    else()
      set(_osg_Version_contents "unknown")
    endif()

    string(REGEX MATCH ".*#define OSG_VERSION_MAJOR[ \t]+[0-9]+.*"
        _osg_old_defines "${_osg_Version_contents}")
    string(REGEX MATCH ".*#define OPENSCENEGRAPH_MAJOR_VERSION[ \t]+[0-9]+.*"
        _osg_new_defines "${_osg_Version_contents}")
    if(_osg_old_defines)
        string(REGEX REPLACE ".*#define OSG_VERSION_MAJOR[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MAJOR ${_osg_Version_contents})
        string(REGEX REPLACE ".*#define OSG_VERSION_MINOR[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MINOR ${_osg_Version_contents})
        string(REGEX REPLACE ".*#define OSG_VERSION_PATCH[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_PATCH ${_osg_Version_contents})
    elseif(_osg_new_defines)
        string(REGEX REPLACE ".*#define OPENSCENEGRAPH_MAJOR_VERSION[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MAJOR ${_osg_Version_contents})
        string(REGEX REPLACE ".*#define OPENSCENEGRAPH_MINOR_VERSION[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_MINOR ${_osg_Version_contents})
        string(REGEX REPLACE ".*#define OPENSCENEGRAPH_PATCH_VERSION[ \t]+([0-9]+).*"
            "\\1" _osg_VERSION_PATCH ${_osg_Version_contents})
    else()
        message(WARNING "[ FindOpenSceneGraph.cmake:${CMAKE_CURRENT_LIST_LINE} ] "
            "Failed to parse version number, please report this as a bug")
    endif()
    unset(_osg_Version_contents)

    set(OPENSCENEGRAPH_VERSION "${_osg_VERSION_MAJOR}.${_osg_VERSION_MINOR}.${_osg_VERSION_PATCH}"
                                CACHE INTERNAL "The version of OSG which was detected")
    if(OpenSceneGraph_DEBUG)
        message(STATUS "[ FindOpenSceneGraph.cmake:${CMAKE_CURRENT_LIST_LINE} ] "
            "Detected version ${OPENSCENEGRAPH_VERSION}")
    endif()
endif()

set (DEPENDENCY_FOUND "NO")
if (OSG_LIBRARY AND OSG_INCLUDE_DIR)
    set (DEPENDENCY_FOUND "YES")
endif (OSG_LIBRARY AND OSG_INCLUDE_DIR)
