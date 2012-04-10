/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* WTRNOISE DLL Stevens University Collision Avoidance Project
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owners of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author WTRNOISE Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRSWTRNOISEDLL_EXPORT_H
#define VRSWTRNOISEDLL_EXPORT_H


#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#  ifdef VRS_WTRNOISE_LIBRARY
#    define VRS_WTRNOISE_EXPORT __declspec(dllexport)
#  else
#    define VRS_WTRNOISE_EXPORT __declspec(dllimport)
#  endif
#else
#  define VRS_WTRNOISE_EXPORT
#endif


#endif //VRSWTRNOISEDLL_EXPORT_H