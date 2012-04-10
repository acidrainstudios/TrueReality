/*
Define rename criteria
(recall: NETCDF4|DAP=>RENAMEV3)
DAP=no  && NETCDF4=no  => use netcdf.h
DAP=no  && NETCDF4=yes => use netcdf3.h then nctonc3.h
DAP=yes && NETCDF4=no  => use netcdf.h then nctolnc3.h
DAP=yes && NETCDF4=yes => use netcdf3.h then nctonc3.h then nc3tolnc3.h
where
nctonc3.h converts nc_* to nc3_
nctolnc3.h converts selected nc_* to lnc3_*
nc3tolnc3.h converts selected nc3_* to lnc3_*

Note that this is tricky because DAP will be
taking over only selected API procedures such
as nc_open or nc_close.  This means that we
only want to rename those procedures
when dap is true.  That is why e.g. the nc3tolnc3.h files
and the netcdf3l.h file only define and rename
those selected procedures.
See also libncdap3/daprename.h
*/

#if defined(USE_DAP)
# if defined(USE_NETCDF4)
#  include "netcdf3.h"
#  include "nctonc3.h"
#  include "nc3tolnc3.h"
# else
#  include "netcdf.h"
#  include "nctolnc3.h"
# endif
#elif defined(USE_NETCDF4)
# include "netcdf3.h"
# include "nctonc3.h"
#else
#include "netcdf.h"
#endif
