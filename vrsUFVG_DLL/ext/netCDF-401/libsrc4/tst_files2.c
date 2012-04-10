/* This is part of the netCDF package.
   Copyright 2005 University Corporation for Atmospheric Research/Unidata
   See COPYRIGHT file for conditions of use.

   Test netcdf-4 variables. 
   $Id: tst_files2.c,v 1.3 2009/02/20 18:18:40 ed Exp $
*/

#include <nc_tests.h>
#include "netcdf.h"

int
main(int argc, char **argv)
{

   printf("\n*** Testing netcdf-4 file functions, some more.\n");
   printf("**** testing multiple open files...");
   {
#define VAR_NAME "Captain_Kirk"
#define NDIMS 1      
#define NUM_FILES 30
#define TEXT_LEN 15
#define D1_NAME "tl"      
      int ncid[NUM_FILES], nvars_in, varids_in[1], varid;
      int dimid, time_id;
      size_t count[NDIMS], index[NDIMS] = {0};
      const char ttext[TEXT_LEN + 1] = "20051224.150000";
      const char ttext_in[TEXT_LEN + 1];
      char file_name[NC_MAX_NAME + 1];
      int nvars, ndims, ngatts, unlimdimid;
      int ndims_in, natts_in, dimids_in[NDIMS];
      char var_name_in[NC_MAX_NAME + 1];
      size_t chunks[NDIMS] = {TEXT_LEN + 1};
      nc_type xtype_in;
      int f;

      /* Create a bunch of files. */
      for (f = 0; f < NUM_FILES; f++)
      {
	 sprintf(file_name, "tst_files2_%d.nc", f);
	 if (nc_create(file_name, NC_NETCDF4, &ncid[f])) ERR;
	 if (nc_def_dim(ncid[f], D1_NAME, TEXT_LEN + 1, &dimid)) ERR;
	 if (nc_def_var(ncid[f], VAR_NAME, NC_CHAR, NDIMS, &dimid, &varid)) ERR;
	 if (f % 2 == 0)
	    if (nc_def_var_chunking(ncid[f], varid, 0, chunks)) ERR;
	 
	 /* Write one time to the coordinate variable. */
	 count[0] = TEXT_LEN + 1;
	 if (nc_put_vara_text(ncid[f], varid, index, count, ttext)) ERR;
      }

      /* Read something from each file. */
      for (f = 0; f < NUM_FILES; f++)
      {
	 if (nc_get_vara_text(ncid[f], varid, index, count, (char *)ttext_in)) ERR;
	 if (strcmp(ttext_in, ttext)) ERR;
      }

      /* Close all open files. */
      for (f = 0; f < NUM_FILES; f++)
	 if (nc_close(ncid[f])) ERR;
   }

   SUMMARIZE_ERR;
   FINAL_RESULTS;
}
