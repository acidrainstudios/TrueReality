# *****************************************************************************
# *****************************************************************************
# FindBoostLibs uses CMakes FindBoost to find specific boost libraries ********
# *****************************************************************************
# All search options and Boost configurations should be placed here ***********
# *****************************************************************************
# *****************************************************************************
FIND_PACKAGE (Boost ${BoostLibs_FIND_VERSION} REQUIRED COMPONENTS 
    #atomic 
    chrono 
    #container 
    #context 
    #coroutine 
    date_time         
    #filesystem 
    #graph 
    #iostreams 
    #locale 
    #log_setup 
    #log        
    #math_c99f 
    #math_c99l 
    #math_c99 
    #math_tr1f 
    #math_tr1l 
    #math_tr1         
    #prg_exec_monitor 
    program_options 
    #random 
    #regex 
    #serialization 
    #signals 
    system 
    thread 
    #timer 
    #type_erasure 
    unit_test_framework 
    #wave 
    #wserialization        
    )
# *****************************************************************************
# *****************************************************************************
# *****************************************************************************