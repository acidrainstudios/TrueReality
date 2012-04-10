#pragma once

#if defined(_WIN32)
#  ifdef DT_OCEAN_LIBRARY
#    define DT_OCEAN_EXPORT __declspec(dllexport)
#  else
#    define DT_OCEAN_EXPORT __declspec(dllimport)
#  endif
#else
// FIXME!
#  define DT_OCEAN_EXPORT
#endif
