/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Camera Tracker Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRSTRACKERDLL_EXPORT_H
#define VRSTRACKERDLL_EXPORT_H


#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#  ifdef VRS_TRACKER_LIBRARY
#    define VRS_TRACKER_EXPORT __declspec(dllexport)
#  else
#    define VRS_TRACKER_EXPORT __declspec(dllimport)
#  endif
#else
#  define VRS_TRACKER_EXPORT
#endif


#endif //VRSTRACKERDLL_EXPORT_H