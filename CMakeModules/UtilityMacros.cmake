MACRO (TR_DETECT_DEPENDENCY arg)
    MESSAGE (STATUS "Detecting ${arg}...")
    FIND_PACKAGE (${arg} REQUIRED)
    IF (DEPENDENCY_FOUND)
        MESSAGE (STATUS "Found ${arg}!")
        INCLUDE_DIRECTORIES(${${arg}_INCLUDE_DIR})
    ELSE (DEPENDENCY_FOUND)
        MESSAGE ("${arg} not found!")
    ENDIF (DEPENDENCY_FOUND)
ENDMACRO (TR_DETECT_DEPENDENCY arg)

MACRO (TR_TARGET_OPTIONS arg)
    SET_TARGET_PROPERTIES (
        ${arg}
        PROPERTIES
        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
		RELWITHDEBINFO_POSTFIX ${CMAKE_RELWITHDEBINFO_POSTFIX}
        VERSION ${TR_VERSION_MAJOR}.${TR_VERSION_MINOR}.${TR_VERSION_YYMM}.${TR_VERSION_BUILD}
        SOVERSION ${TR_SOVERSION}
    )
    IF (MSVC_IDE)
        TARGET_COMPILE_OPTIONS (
            ${arg} PRIVATE
        	/nologo /GR
            $<$<CONFIG:Debug>:/Od /Ob0 /RTC1 /D_DEBUG /Zi>
			$<$<CONFIG:RelWithDebInfo>:/MD /Zi /O2 /Ob1 /D>            
			$<$<CONFIG:Release>:/MT /O2 /Ob2 /MD>			
        )
	ELSEIF (UNIX)
        TARGET_COMPILE_OPTIONS (
            ${arg} PRIVATE
        	-Wall -pedantic -Wextra #-Werror
            $<$<CONFIG:Debug>: -g -O0 -D_DEBUG>
            $<$<CONFIG:RelWithDebInfo>: -g -O3 -DNDEBUG>
			$<$<CONFIG:Release>: -O3 -DNDEBUG>
        )
    ENDIF (MSVC_IDE)
ENDMACRO (TR_TARGET_OPTIONS arg)

MACRO(READ_GCC_VERSION)
    IF (CMAKE_COMPILER_IS_GNUCC)
        EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion
			OUTPUT_VARIABLE GCC_VERSION)
		STRING(REGEX MATCHALL "[0-9]+" GCC_VERSION_COMPONENTS ${GCC_VERSION})
	    LIST(GET GCC_VERSION_COMPONENTS 0 GCC_MAJOR)
		LIST(GET GCC_VERSION_COMPONENTS 1 GCC_MINOR)
	ENDIF()
ENDMACRO(READ_GCC_VERSION)

# *****************************************************************************
# Checks if the version we are looking for is the one we found. ***************
# *****************************************************************************
MACRO(CHECK_VERSION packVer verToFind)
    IF("${packVer}" VERSION_LESS "${verToFind}")
        MESSAGE(SEND_ERROR "Found version is too old! Requested version: ${verToFind} Found: ${packVer}")
    ENDIF()
ENDMACRO(CHECK_VERSION packVer verToFind)

# *****************************************************************************
# Adds a post build process to create a Google Test info file *****************
# in a build project **********************************************************
# *****************************************************************************
MACRO (SET_GOOGLE_TEST_OPTIONS projectName)    
    IF (MSVC_IDE)
		ADD_CUSTOM_COMMAND(TARGET ${projectName} 
		POST_BUILD
		COMMAND echo "This is used for Google Test Adapter in MS Visual Studio" > $<TARGET_FILE:${projectName}>".is_google_test"
		)
    ENDIF (MSVC_IDE)
ENDMACRO (SET_GOOGLE_TEST_OPTIONS target)
