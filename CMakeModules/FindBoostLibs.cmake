# True Reality Open Source Game and Simulation Engine
# Copyright © 2018 Acid Rain Studios LLC
#
# This library is free software; you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation; either version 3.0 of the License, or (at your option)
# any later version.
#
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# Author: Maxim Serebrennik

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