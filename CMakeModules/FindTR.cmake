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


# ********************************************************************************
# Finds the True Reality libraries. **********************************************
# ********************************************************************************
# ********************************************************************************
# Creates and sets variables to use through out cmake **************************** 
# ********************************************************************************
# TR_FOUND - Defined if the dependency is found **********************************
# ********************************************************************************
# TR_INCLUDE_DIRS - Holds the paths to the TR Headers ****************************
# ********************************************************************************
# TR_APP_INCLUDE_DIR     - Holds the path to library headers *********************
# TR_BASE_INCLUDE_DIR    - Holds the path to library headers *********************
# TR_CORE_INCLUDE_DIR    - Holds the path to library headers *********************
# TR_MANAGER_INCLUDE_DIR - Holds the path to library headers *********************
# TR_SG_INCLUDE_DIR      - Holds the path to library headers *********************
# TR_UTIL_INCLUDE_DIR    - Holds the path to library headers *********************
# ********************************************************************************
# TR_LIBRARY_DIR - Holds the paths to all found libraries ************************
# ********************************************************************************
# TR_APP_LIBRARY           - Holds the path to the trApp library *****************
# TR_APP_LIBRARY_DEBUG     - Holds the path to the trApp debug library ***********
# TR_BASE_LIBRARY          - Holds the path to the trBase library ****************
# TR_BASE_LIBRARY_DEBUG    - Holds the path to the trBase debug library **********
# TR_CORE_LIBRARY          - Holds the path to the trCore library ****************
# TR_CORE_LIBRARY_DEBUG    - Holds the path to the trCore debug library **********
# TR_MANAGER_LIBRARY       - Holds the path to the trManager library *************
# TR_MANAGER_LIBRARY_DEBUG - Holds the path to the trManager debug library *******
# TR_SG_LIBRARY            - Holds the path to the trSG library ******************
# TR_SG_LIBRARY_DEBUG      - Holds the path to the trSG debug library ************
# TR_UTIL_LIBRARY          - Holds the path to the trUtil library ****************
# TR_UTIL_LIBRARY_DEBUG    - Holds the path to the trUtil debug library **********
# ********************************************************************************
# TR_APP_LIBRARY_FOUND           - Defined if the library is found ***************
# TR_APP_LIBRARY_DEBUG_FOUND     - Defined if the library is found ***************
# TR_BASE_LIBRARY_FOUND          - Defined if the library is found ***************
# TR_BASE_LIBRARY_DEBUG_FOUND    - Defined if the library is found ***************
# TR_CORE_LIBRARY_FOUND          - Defined if the library is found ***************
# TR_CORE_LIBRARY_DEBUG_FOUND    - Defined if the library is found ***************
# TR_MANAGER_LIBRARY_FOUND       - Defined if the library is found ***************
# TR_MANAGER_LIBRARY_DEBUG_FOUND - Defined if the library is found ***************
# TR_SG_LIBRARY_FOUND            - Defined if the library is found ***************
# TR_SG_LIBRARY_DEBUG_FOUND      - Defined if the library is found ***************
# TR_UTIL_LIBRARY_FOUND          - Defined if the library is found ***************
# TR_UTIL_LIBRARY_DEBUG_FOUND    - Defined if the library is found ***************
# ********************************************************************************

SET (DEPENDENCY "TR")
