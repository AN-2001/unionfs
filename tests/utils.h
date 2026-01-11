/******************************************************************************\
*  utils.h                                                                     *
*                                                                              *
*  Contains common testing utilities.                                          *
*                                                                              *
*              Written by A.N.                                  11-01-2026     *
*                                                                              *
\******************************************************************************/


#ifndef UFS_TESTING
#error "Attempting to use test utility functions outside of tests, utilities aren't safe for proper use."
#endif

#ifndef UFS_TEST_UTILS_H
#define UFS_TEST_UTILS_H

#define UFS_TEST_UTILS_BUFF_SIZE (1024)
#include <stdbool.h>

struct ufsTestUtilsFileNameStruct {
    char name[ UFS_TEST_UTILS_BUFF_SIZE ];
    int fd;
};

bool ufsTestUtilsGetTmpFileName( struct ufsTestUtilsFileNameStruct *fn );

bool ufsTestUtilsGetTmpFile( struct ufsTestUtilsFileNameStruct *fn );

int getFileNameSetup( void **state );

int getFileSetup( void **state );

int cleanUpTeardown( void **state );

#endif /* UFS_TEST_UTILS_H */
