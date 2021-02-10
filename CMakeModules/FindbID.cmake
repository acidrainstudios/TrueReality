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

# ********************************************************************************
# Finds the bID headers, which are the boost UUID extracted header files. ********
# ********************************************************************************
# ********************************************************************************
# Creates and sets variables to use through out cmake ****************************
# bID_INCLUDE_DIR - Holds the path to the bID Headers ****************************
# ********************************************************************************
# bID_FOUND - Defined if the dependency is found *********************************
# ********************************************************************************

SET (DEPENDENCY "bID")

# Finds the include files necessary for compilation
FIND_PATH (${DEPENDENCY}_INCLUDE_DIR bID/version.hpp
    HINTS
    $ENV{bID_INC}
    $ENV{bID_ROOT}/include
    $ENV{bID_ROOT}/inc
    $ENV{bID_ROOT}
    $ENV{TR_INC}
    $ENV{TR_ROOT}/Ext/include
    $ENV{TR_ROOT}/Ext
    $ENV{TR_ROOT}/include
    $ENV{TR_ROOT}
    PATHS
    /usr/include
    /usr/local/include
    ~/Library/Frameworks
    /Library/Frameworks
)
MARK_AS_ADVANCED (${DEPENDENCY}_INCLUDE_DIR)

SET (${DEPENDENCY}_FOUND "NO")
IF (${DEPENDENCY}_INCLUDE_DIR)
    SET (${DEPENDENCY}_FOUND "YES")
ENDIF ()