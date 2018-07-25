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
# *****************************************************************************
# FindBoostLibs uses CMakes FindBoost to find specific boost libraries ********
# *****************************************************************************
# All search options and Boost configurations should be placed here ***********
# *****************************************************************************
# *****************************************************************************

# This module finds headers and requested component libraries OR a CMake
# package configuration file provided by a "Boost CMake" build.  For the
# latter case skip to the "Boost CMake" section below.  For the former
# case results are reported in variables::
#
#   BoostLibs_FOUND        - True if headers and requested libraries were found
#   Boost_FOUND            - True if headers and requested libraries were found
#   Boost_INCLUDE_DIRS     - Boost include directories
#   Boost_LIBRARY_DIRS     - Link directories for Boost libraries
#   Boost_LIBRARIES        - Boost component libraries to be linked
#   Boost_<C>_FOUND        - True if component <C> was found (<C> is upper-case)
#   Boost_<C>_LIBRARY      - Libraries to link for component <C> (may include
#                            target_link_libraries debug/optimized keywords)
#   Boost_VERSION          - BOOST_VERSION value from boost/version.hpp
#   Boost_LIB_VERSION      - Version string appended to library filenames
#   Boost_MAJOR_VERSION    - Boost major version number (X in X.y.z)
#   Boost_MINOR_VERSION    - Boost minor version number (Y in x.Y.z)
#   Boost_SUBMINOR_VERSION - Boost subminor version number (Z in x.y.Z)
#   Boost_LIB_DIAGNOSTIC_DEFINITIONS (Windows)
#                          - Pass to add_definitions() to have diagnostic
#                            information about Boost's automatic linking
#                            displayed during compilation
#
# This module reads hints about search locations from variables::
#
#   BOOST_ROOT             - Preferred installation prefix
#    (or BOOSTROOT)
#   BOOST_INCLUDEDIR       - Preferred include directory e.g. <prefix>/include
#   BOOST_LIBRARYDIR       - Preferred library directory e.g. <prefix>/lib
#   Boost_NO_SYSTEM_PATHS  - Set to ON to disable searching in locations not
#                            specified by these hint variables. Default is OFF.
#   Boost_ADDITIONAL_VERSIONS
#                          - List of Boost versions not known to this module
#                            (Boost install locations may contain the version)
#
# and saves search results persistently in CMake cache entries::
#
#   Boost_INCLUDE_DIR         - Directory containing Boost headers
#   Boost_LIBRARY_DIR_RELEASE - Directory containing release Boost libraries
#   Boost_LIBRARY_DIR_DEBUG   - Directory containing debug Boost libraries
#   Boost_<C>_LIBRARY_DEBUG   - Component <C> library debug variant
#   Boost_<C>_LIBRARY_RELEASE - Component <C> library release variant

SET(DEPENDENCY "BoostLibs")

FIND_PACKAGE (Boost ${BoostLibs_FIND_VERSION} REQUIRED COMPONENTS 
    #atomic 
    chrono 
    #container 
    #context 
    #coroutine 
    date_time         
    #filesystem 
    #graph 
    #iostreams 
    #locale 
    #log_setup 
    #log        
    #math_c99f 
    #math_c99l 
    #math_c99 
    #math_tr1f 
    #math_tr1l 
    #math_tr1         
    #prg_exec_monitor 
    program_options 
    #random 
    #regex 
    #serialization 
    #signals 
    system 
    thread 
    #timer 
    #type_erasure 
    unit_test_framework 
    #wave 
    #wserialization        
    )

SET (${DEPENDENCY}_FOUND "NO")
IF (Boost_FOUND)
    SET (${DEPENDENCY}_FOUND "YES")
ENDIF ()
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************