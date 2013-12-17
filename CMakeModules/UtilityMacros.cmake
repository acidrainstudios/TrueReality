macro (TR_DETECT_DEPENDENCY arg)
    message (STATUS "Detecting ${arg}...")
    find_package (${arg} REQUIRED)
    if (DEPENDENCY_FOUND)
        message (STATUS "Found ${arg}!")
        include_directories(${${arg}_INCLUDE_DIR})
    else (DEPENDENCY_FOUND)
        message ("${arg} not found!")
    endif (DEPENDENCY_FOUND)
endmacro (TR_DETECT_DEPENDENCY arg)

macro (TR_TARGET_OPTIONS arg)
    set_target_properties (
        ${arg}
        PROPERTIES
        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
		RELWITHDEBINFO_POSTFIX ${CMAKE_RELWITHDEBINFO_POSTFIX}
    )
    if (MSVC_IDE)
        target_compile_options (
            ${arg} PRIVATE
        	/nologo /GR
            $<$<CONFIG:Debug>:/Od /Ob0 /RTC1 /D_DEBUG /Zi>
			$<$<CONFIG:RelWithDebInfo>:/MD /Zi /O2 /Ob1 /D>            
			$<$<CONFIG:Release>:/MT /O2 /Ob2 /MD>			
        )
    endif (MSVC_IDE)
endmacro (TR_TARGET_OPTIONS arg)
