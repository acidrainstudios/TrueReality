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
# Ensures that the user does not build in the source folder *******************
# Unlike the build in CMake function, this returns a better Error Message *****
# *****************************************************************************
FUNCTION (CHECK_FOR_INSOURCE_BUILD)
  # Find our paths, even with simlinks
  GET_FILENAME_COMPONENT (srcdir "${CMAKE_SOURCE_DIR}" REALPATH)
  GET_FILENAME_COMPONENT (bindir "${CMAKE_BINARY_DIR}" REALPATH)

  IF ("${srcdir}" STREQUAL "${bindir}")
    MESSAGE ("\nPlease select a different Build folder. In-source builds are not allowed.\n\n\n")
    MESSAGE (FATAL_ERROR "Quitting configuration...\n\n")
  ENDIF()
ENDFUNCTION()

CHECK_FOR_INSOURCE_BUILD()