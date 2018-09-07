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
# @author Maxim Serebrennik
# @author Robert Osfield


# ********************************************************************************
# Finds the FFMPEG libraries. ****************************************************
# ********************************************************************************
# ********************************************************************************
# Creates and sets variables to use through out cmake ****************************
# FFmpeg is usually build in Release or Debug, but not both, so these variables **
# will link to the one version that is present on the system ********************* 
# ********************************************************************************
# FFMPEG_INCLUDE_DIRS - Holds the paths to the FFMPEG Headers ********************
# ********************************************************************************
# FFMPEG_LIBAVUTIL_INCLUDE_DIR - Holds the path to library headers ***************
# FFMPEG_LIBAVCODEC_INCLUDE_DIR - holds the path to library headers **************
# FFMPEG_LIBAVFORMAT_INCLUDE_DIR - holds the path to library headers *************
# FFMPEG_LIBAVDEVICE_INCLUDE_DIR - holds the path to library headers *************
# FFMPEG_LIBSWRESAMPLE_INCLUDE_DIR   - holds the path to library headers *********
# FFMPEG_LIBSWSCALE_INCLUDE_DIR - holds the path to library headers **************
# ********************************************************************************
# FFMPEG_LIBRARY_DIR - Holds the paths to all found libraries ********************
# ********************************************************************************
# FFMPEG_LIBAVUTIL_LIBRARY - Holds the path to the avutil library ****************
# FFMPEG_LIBAVCODEC_LIBRARY - holds the path to the avcodec library **************
# FFMPEG_LIBAVFORMAT_LIBRARY - holds the path to the avformat library ************
# FFMPEG_LIBAVDEVICE_LIBRARY - holds the path to the avdevice library ************
# FFMPEG_LIBSWRESAMPLE_LIBRARY   - holds the path to the swresample library ******
# FFMPEG_LIBSWSCALE_LIBRARY - holds the path to the swscale library **************
# ********************************************************************************
# FFMPEG_FOUND - Defined if the dependency is found ******************************
# ********************************************************************************
# FFMPEG_LIBAVUTIL_FOUND - Defined if the library is found ***********************
# FFMPEG_LIBAVCODEC_FOUND - Defined if the library is found **********************
# FFMPEG_LIBAVFORMAT_FOUND - Defined if the library is found *********************
# FFMPEG_LIBAVDEVICE_FOUND - Defined if the library is found *********************
# FFMPEG_LIBSWRESAMPLE_FOUND - Defined if the library is found *******************
# FFMPEG_LIBSWSCALE_FOUND - Defined if the library is found **********************
# ********************************************************************************

SET (DEPENDENCY "FFMPEG")
# ********************************************************************************
# Macro to find header and lib directories ***************************************
# example: FFMPEG_FIND_LIB(AVFORMAT avformat avformat.h) *************************
# ********************************************************************************
MACRO (FFMPEG_FIND_LIB VARNAME MYLIBRARYNAME HEADERNAME)

    FIND_PATH(${DEPENDENCY}_${VARNAME}_INCLUDE_DIR lib${MYLIBRARYNAME}/${HEADERNAME}
        HINTS
        $ENV{FFMPEG_ROOT}
        $ENV{FFMPEG_ROOT}/include
        $ENV{TR_INC}
        $ENV{TR_ROOT}/Ext/include
        $ENV{TR_ROOT}/Ext
        $ENV{TR_ROOT}/include
        $ENV{TR_ROOT}
        PATHS
        /usr/include
        /usr/local/include
        /opt/include
        /opt/local/include
        ~/Library/Frameworks
        /Library/Frameworks
    )
    MARK_AS_ADVANCED (${DEPENDENCY}_${VARNAME}_INCLUDE_DIR)

    FIND_LIBRARY(${DEPENDENCY}_${VARNAME}_LIBRARY
        NAMES ${MYLIBRARYNAME}
        HINTS
        $ENV{FFMPEG_ROOT}/lib64
        $ENV{FFMPEG_ROOT}/lib
        $ENV{FFMPEG_ROOT}
        $ENV{TR_LIB}
        $ENV{TR_ROOT}/Ext/lib64
        $ENV{TR_ROOT}/Ext/lib
        $ENV{TR_ROOT}/Ext
        $ENV{TR_ROOT}/lib64
        $ENV{TR_ROOT}/lib
        $ENV{TR_ROOT}
        PATHS
        /usr/lib64
        /usr/lib
        /usr/local/lib64
        /usr/local/lib
        /opt/lib64
        /opt/lib
        /opt/local/lib64
        /opt/local/lib
        ~/Library/Frameworks
        /Library/Frameworks
    )
    MARK_AS_ADVANCED (${DEPENDENCY}_${VARNAME}_LIBRARY)

    IF (${DEPENDENCY}_${VARNAME}_LIBRARY AND ${DEPENDENCY}_${VARNAME}_INCLUDE_DIR)
        SET (${DEPENDENCY}_${VARNAME}_FOUND "YES")
    ENDIF ()

ENDMACRO ()

IF (TR_BUILD_WITH_RELEASE)
    # Locates all FFMPEG release libraries
    FFMPEG_FIND_LIB(LIBAVFORMAT avformat avformat.h)
    FFMPEG_FIND_LIB(LIBAVDEVICE avdevice avdevice.h)
    FFMPEG_FIND_LIB(LIBAVCODEC  avcodec  avcodec.h)
    FFMPEG_FIND_LIB(LIBAVUTIL   avutil   avutil.h)
    FFMPEG_FIND_LIB(LIBSWRESAMPLE   swresample   swresample.h)
    FFMPEG_FIND_LIB(LIBSWSCALE  swscale  swscale.h)
ENDIF ()

IF (TR_BUILD_WITH_DEBUG)
    # Locates all FFMPEG debug libraries (in this case it is the same as Release, but left here for future options)
    FFMPEG_FIND_LIB(LIBAVFORMAT avformat avformat.h)
    FFMPEG_FIND_LIB(LIBAVDEVICE avdevice avdevice.h)
    FFMPEG_FIND_LIB(LIBAVCODEC  avcodec  avcodec.h)
    FFMPEG_FIND_LIB(LIBAVUTIL   avutil   avutil.h)
    FFMPEG_FIND_LIB(LIBSWRESAMPLE   swresample   swresample.h)
    FFMPEG_FIND_LIB(LIBSWSCALE  swscale  swscale.h)
ENDIF ()

SET (${DEPENDENCY}_FOUND "NO")
IF (${DEPENDENCY}_LIBAVFORMAT_FOUND AND ${DEPENDENCY}_LIBAVDEVICE_FOUND AND ${DEPENDENCY}_LIBAVCODEC_FOUND AND ${DEPENDENCY}_LIBAVUTIL_FOUND AND ( ${DEPENDENCY}_LIBSWRESAMPLE_FOUND OR ${DEPENDENCY}_LIBAVRESAMPLE_FOUND ) )
    # Note we don't check FFMPEG_LIBSWSCALE_FOUND here, it's optional.
    
    SET(${DEPENDENCY}_INCLUDE_DIRS
        ${${DEPENDENCY}_LIBAVFORMAT_INCLUDE_DIRS}
        ${${DEPENDENCY}_LIBAVDEVICE_INCLUDE_DIRS}
        ${${DEPENDENCY}_LIBAVCODEC_INCLUDE_DIRS}
        ${${DEPENDENCY}_LIBAVUTIL_INCLUDE_DIRS}
        )   

    SET (FFMPEG_LIBRARY_DIR ${FFMPEG_LIBAVFORMAT_LIBRARY_DIRS})

    # Note we don't add FFMPEG_LIBSWSCALE_LIBRARIES here, it will be added if found later.
    SET (${DEPENDENCY}_LIBRARIES
        ${${DEPENDENCY}_LIBAVFORMAT_LIBRARIES}
        ${${DEPENDENCY}_LIBAVDEVICE_LIBRARIES}
        ${${DEPENDENCY}_LIBAVCODEC_LIBRARIES}
        ${${DEPENDENCY}_LIBAVUTIL_LIBRARIES}
        )

    SET (${DEPENDENCY}_FOUND "YES")
ENDIF ()