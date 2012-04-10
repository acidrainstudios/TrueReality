# Install script for directory: D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/src/osgOcean

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/osgOcean")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "C:/Program Files (x86)/osgOcean/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/lib/Debug/osgOceanD.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "C:/Program Files (x86)/osgOcean/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/lib/Release/osgOcean.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "C:/Program Files (x86)/osgOcean/bin" TYPE SHARED_LIBRARY FILES "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/bin/Debug/osgOceanD.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "C:/Program Files (x86)/osgOcean/bin" TYPE SHARED_LIBRARY FILES "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/bin/Release/osgOcean.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "C:/Program Files (x86)/osgOcean/include/osgOcean" TYPE FILE FILES
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/Cylinder"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/DistortionSurface"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/FFTOceanSurface"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/FFTSimulation"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/GodRays"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/GodRayBlendSurface"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/MipmapGeometry"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/OceanScene"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/OceanTechnique"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/OceanTile"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/RandUtils"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/ScreenAlignedQuad"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/ShaderManager"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/SiltEffect"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/WaterTrochoids"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/Export"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/include/osgOcean/Version"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "C:/Program Files (x86)/osgOcean/bin/resources/shaders" TYPE FILE FILES
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/water.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/water.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/godrays.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/godrays.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/godray_screen_blend.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/godray_screen_blend.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/godray_glare.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/godray_glare.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/silt_quads.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/silt_quads.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/silt_points.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/silt_points.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/streak.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/streak.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/glare_composite.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/glare_composite.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/downsample_glare.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/downsample.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/downsample.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/gaussian1.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/gaussian1.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/gaussian2.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/gaussian2.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/dof_combiner.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/dof_combiner.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/water_distortion.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/water_distortion.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/default_scene.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/default_scene.frag"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/heightmap.vert"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/shaders/heightmap.frag"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "C:/Program Files (x86)/osgOcean/bin/resources/textures" TYPE FILE FILES
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/textures/sea_foam.png"
    "D:/Development/D3D/D3D250Stuff/OceanExt/osgocean/resources/textures/sun_glare.png"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

