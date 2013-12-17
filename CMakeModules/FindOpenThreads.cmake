# Finds the include files necessary for compilation
find_path (OPENTHREADS_INCLUDE_DIR OpenThreads/Thread
    HINTS
    $ENV{TR_INC}
    $ENV{TR_ROOT}/Ext/include
    $ENV{TR_ROOT}/Ext
    $ENV{TR_ROOT}/include
    $ENV{TR_ROOT}
    $ENV{OPENTHREADS_INC}
    $ENV{OPENTHREADS_ROOT}/include
    $ENV{OPENTHREADS_ROOT}
    $ENV{OSG_INC}
    $ENV{OSG_ROOT}/include
    $ENV{OSG_ROOT}
)
mark_as_advanced (OPENTHREADS_INCLUDE_DIR)

macro (FIND_OPENTHREADS_LIBRARY MYLIBRARY MYLIBRARYNAME)
    # Finds the library files necessary for compilation
    find_library (${MYLIBRARY}
        NAMES ${MYLIBRARYNAME}
        HINTS
        $ENV{TR_ROOT}/Ext/lib
        $ENV{TR_ROOT}/Ext
        $ENV{TR_LIB}
        $ENV{TR_ROOT}/lib64
        $ENV{TR_ROOT}/lib
        $ENV{TR_ROOT}
        $ENV{OPENTHREADS_LIB}
        $ENV{OPENTHREADS_ROOT}/lib64
        $ENV{OPENTHREADS_ROOT}/lib
        $ENV{OPENTHREADS_ROOT}
        $ENV{OSG_INC}
        $ENV{OSG_ROOT}/lib64
        $ENV{OSG_ROOT}/lib
        $ENV{OSG_ROOT}
    )
    mark_as_advanced (${MYLIBRARY})
endmacro(FIND_OPENTHREADS_LIBRARY MYLIBRARY MYLIBRARYNAME)

if (TC_BUILD_WITH_RELEASE)
    # Locates all OPENTHREADS release libraries
    FIND_OPENTHREADS_LIBRARY (OPENTHREADS_LIBRARY OpenThreads)
endif (TC_BUILD_WITH_RELEASE)

if (TC_BUILD_WITH_DEBUG)
    # Locates all OPENTHREADS debug libraries
    FIND_OPENTHREADS_LIBRARY (OPENTHREADS_LIBRARY_DEBUG OpenThreadsd)
endif (TC_BUILD_WITH_DEBUG)

set (DEPENDENCY_FOUND "NO")
if (OPENTHREADS_LIBRARY AND OPENTHREADS_INCLUDE_DIR)
    set (DEPENDENCY_FOUND "YES")
endif (OPENTHREADS_LIBRARY AND OPENTHREADS_INCLUDE_DIR)
