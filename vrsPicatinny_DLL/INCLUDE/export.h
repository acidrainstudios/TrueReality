/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Picatinny Arsenal Demo Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRSPICATINNYDLL_EXPORT_H
#define VRSPICATINNYDLL_EXPORT_H


#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#  ifdef VRS_PICATINNY_LIBRARY
#    define VRS_PICATINNY_EXPORT __declspec(dllexport)
#  else
#    define VRS_PICATINNY_EXPORT __declspec(dllimport)
#  endif
#else
#  define VRS_PICATINNY_EXPORT
#endif


#endif //VRSPICATINNYDLL_EXPORT_H