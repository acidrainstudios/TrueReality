# Finds the include files necessary for compilation
FIND_PATH (JSON_CPP_INCLUDE_DIR json/json.h    
    HINTS
    $ENV{TR_INC}
    $ENV{TR_ROOT}/Ext/include
    $ENV{TR_ROOT}/Ext
    $ENV{TR_ROOT}/include
    $ENV{TR_ROOT}
    $ENV{JSON_INC}
    $ENV{JSON_ROOT}/include
    $ENV{JSON_ROOT}
    PATHS
    /usr/include
    /usr/local/include
    ~/Library/Frameworks
    /Library/Frameworks
)
MARK_AS_ADVANCED (JSON_CPP_INCLUDE_DIR)

MACRO (FIND_JSON_CPP_LIBRARY MYLIBRARY MYLIBRARYNAME)
    # Finds the library files necessary for compilation
    FIND_LIBRARY (${MYLIBRARY}
        NAMES ${MYLIBRARYNAME}
        HINTS
        $ENV{TR_ROOT}/Ext/lib64
        $ENV{TR_ROOT}/Ext/lib
        $ENV{TR_ROOT}/Ext
        $ENV{TR_LIB}
        $ENV{TR_ROOT}/lib64
        $ENV{TR_ROOT}/lib
        $ENV{TR_ROOT}
        $ENV{JSON_LIB}
        $ENV{JSON_ROOT}/lib64
        $ENV{JSON_ROOT}/lib
        $ENV{JSON_ROOT}
        PATHS
        /usr/lib64
        /usr/lib
        /usr/local/lib64
        /usr/local/lib
        ~/Library/Frameworks
        /Library/Frameworks
    )
    MARK_AS_ADVANCED (${MYLIBRARY})
ENDMACRO(FIND_JSON_CPP_LIBRARY MYLIBRARY MYLIBRARYNAME)

IF (TR_BUILD_WITH_RELEASE)
    # Locates all JSON_CPP release libraries
    FIND_JSON_CPP_LIBRARY (JSON_CPP_LIBRARY jsoncpp)
ENDIF (TR_BUILD_WITH_RELEASE)

IF (TR_BUILD_WITH_DEBUG)
    # Locates all JSON_CPP debug libraries
    FIND_JSON_CPP_LIBRARY (JSON_CPP_LIBRARY_DEBUG jsoncppd)
ENDIF (TR_BUILD_WITH_DEBUG)

SET (DEPENDENCY_FOUND "NO")
IF (JSON_CPP_INCLUDE_DIR)
    SET (DEPENDENCY_FOUND "YES")
ENDIF (JSON_CPP_INCLUDE_DIR)
