/* This is part of the netCDF package.
   Copyright 2005 University Corporation for Atmospheric Research/Unidata
   See COPYRIGHT file for conditions of use.

   Test HDF5 file code. These are not intended to be exhaustive tests,
   but they use HDF5 the same way that netCDF-4 does, so if these
   tests don't work, than netCDF-4 won't work either.

   $Id: tst_h_files2.c,v 1.3 2009/03/03 18:12:30 ed Exp $
*/
#include <config.h>
#include <nc_tests.h>
#include "netcdf.h"
#include <nc4internal.h>
#include <H5DSpublic.h>

#define FILE_NAME "tst_h_files2.h5"

int
main()
{
   printf("\n*** Checking HDF5 file functions some more.\n");
   printf("*** Checking opaque attribute creation...");
#define OPAQUE_SIZE 20
#define OPAQUE_NAME "type"
#define ATT_NAME "att_name"
#define DIM_LEN 3
   {
      hid_t fileid, access_plist, typeid, spaceid, attid, fapl_id, grpid;
      hsize_t dims[1]; /* netcdf attributes always 1-D. */
      unsigned char data[DIM_LEN][OPAQUE_SIZE];
      hsize_t num_obj, i;
      int obj_class;
      char obj_name[NC_MAX_NAME + 1];
      H5T_class_t class;
      size_t type_size;
      int j, k;

      /* Initialize some data. */
      for (j = 0; j < DIM_LEN; j++)
	 for (k = 0; k < OPAQUE_SIZE; k++)
	    data[j][k] = 42;

      /* Set the access list so that closes will fail if something is
       * still open in the file. */
      if ((access_plist = H5Pcreate(H5P_FILE_ACCESS)) < 0) ERR;
      if (H5Pset_fclose_degree(access_plist, H5F_CLOSE_SEMI)) ERR;

      /* Create file. */
      if ((fileid = H5Fcreate(FILE_NAME, H5F_ACC_TRUNC, H5P_DEFAULT, 
			      access_plist)) < 0) ERR;
      /* Add an opaque type. */
      if ((typeid = H5Tcreate(H5T_OPAQUE, OPAQUE_SIZE)) < 0) ERR;
      if (H5Tcommit(fileid, OPAQUE_NAME, typeid) < 0) ERR;
      
      /* Add attribute of this type. */
      dims[0] = 3;
      if ((spaceid = H5Screate_simple(1, dims, NULL)) < 0) ERR;
      if ((attid = H5Acreate(fileid, ATT_NAME, typeid, spaceid, H5P_DEFAULT)) < 0) ERR;
      if (H5Awrite(attid, typeid, data) < 0) ERR;

      if (H5Aclose(attid) < 0) ERR;
      if (H5Sclose(spaceid) < 0) ERR;
      if (H5Tclose(typeid) < 0) ERR;
      if (H5Fclose(fileid) < 0) ERR;
      if (H5Pclose(access_plist) < 0) ERR;

   }
   SUMMARIZE_ERR;

   FINAL_RESULTS;
}
