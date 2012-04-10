/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////




#ifndef VRSUTILDLL_EXPORT_H
#define VRSUTILDLL_EXPORT_H


#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#  ifdef VRS_UTIL_LIBRARY
#    define VRS_UTIL_EXPORT __declspec(dllexport)
#  else
#    define VRS_UTIL_EXPORT __declspec(dllimport)
#  endif
#else
#   ifdef VRS_UTIL_LIBRARY
#      define VRS_UTIL_EXPORT __attribute__ ((visibility("default")))
#   else
#      define VRS_UTIL_EXPORT
#   endif 
#endif

#endif //VRSUTILDLL_EXPORT_H