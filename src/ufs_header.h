/******************************************************************************\
*  ufsHeader.h                                                                 *
*                                                                              *
*  Internal header for describing a ufs header.                                *
*  This also introduces two functions for manipulating headers.                *
*                                                                              *
*              Written by A.N.                                  12-01-2026     *
*                                                                              *
\******************************************************************************/

#ifndef UFS_HEADER_H
#define UFS_HEADER_H

#include <stdint.h>
#include "ufs_defs.h"
#include "ufs_image.h"

struct ufsFileStruct {
    uint8_t isOwend;
    uint64_t strOffset;
};

struct ufsAreaStruct {
    uint8_t isOwend;
    uint64_t strOffset;
};

struct ufsNodeStruct {
    uint8_t isOwend;
    ufsIdType left, right;
    ufsIdType key[2];
    uint8_t numKeys;
};

struct ufsHeaderStruct {
    uint32_t magicNumber;
    uint32_t version;

    uint64_t sizes[ UFS_TYPES_COUNT ],
             offsets[ UFS_TYPES_COUNT ];
};

struct ufsHeaderSizeRequestStruct {
    uint64_t numFiles;
    uint64_t numAreas;
    uint64_t numNodes;
    uint64_t numStrBytes;
};

extern struct ufsHeaderSizeRequestStruct ufsDefaultSizeRequest;

ufsImagePtr ufsHeaderInit( const char *path,
                           struct ufsHeaderSizeRequestStruct sizes );

ufsImagePtr ufsHeaderValidate( ufsImagePtr img );

struct ufsHeaderStruct *ufsHeaderGet( ufsImagePtr img );

#endif /* UFS_HEADER_H */
