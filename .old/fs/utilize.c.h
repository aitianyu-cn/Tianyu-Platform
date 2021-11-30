/**
 * @file utilize.c.h(utils/fs)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_FS_UTILIZE_C_H__
#define __DTY_NATIVE_UTILS_FS_UTILIZE_C_H__

#include"../utilize.c.h"

#define __FILESYSTEM_ID_LENGTH__                        16
#define __FILESYSTEM_TABLE_SIZE__                       256
#define __FILESYSTEM_NAME_SIZE__                        512

#define __FILESYSTEM_USER_TABLE_ITEM_ID_LENGTH__        __FILESYSTEM_ID_LENGTH__
#define __FILESYSTEM_USER_TABLE_ITEM_SORTNAME_LENGTH__  __FILESYSTEM_ID_LENGTH__

#define __FILESYSTEM_USER_TABLE_SIZE__                  __FILESYSTEM_TABLE_SIZE__

#define __FILESYSTEM_SECURE_ACCESS_TABLE_SIZE__         __FILESYSTEM_TABLE_SIZE__
#define __FILESYSTEM_SECURE_ENCODE_STATE_LENGTH__       384

#define __FILESYSTEM_ITEM_ID_LENGTH__                   __FILESYSTEM_ID_LENGTH__
#define __FILESYSTEM_ITEM_NAME_LENGTH__                 512
#define __FILESYSTEM_ITEM_ADDRESS_COUNT__               30
#define __FILESYSTEM_ITEM_ADDRESS_SPACE__               180

#define __FILESYSTEM_ITEM_DIRECT_ADDRESS_COUNT__        30
#define __FILESYSTEM_ITEM_ONCE_ADDRESS_COUNT__          14
#define __FILESYSTEM_ITEM_TWICE_ADDRESS_COUNT__         14
#define __FILESYSTEM_ITEM_TRIPLE_ADDRESS_COUNT__        14

#define __FILESYSTEM_ITEM_DATA_BLOCK_HEADER_SIZE__      30
#define __FILESYSTEM_MIR_SIZE__                         

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    typedef struct fs_user_table_item
    {
        byte __VARIABLE__ UserId[__FILESYSTEM_USER_TABLE_ITEM_ID_LENGTH__];
        byte __VARIABLE__ UserName[__FILESYSTEM_USER_TABLE_ITEM_SORTNAME_LENGTH__];
    }FS_UserTableItem;

    typedef struct fs_security_domain
    {
        byte __VARIABLE__ SecurityEncodeState[__FILESYSTEM_SECURE_ENCODE_STATE_LENGTH__];
        byte __VARIABLE__ SecurityAccessibility[__FILESYSTEM_SECURE_ACCESS_TABLE_SIZE__];

        FS_UserTableItem __VARIABLE__ UserTable[__FILESYSTEM_USER_TABLE_SIZE__];
    }FS_SecurityDomain;

    typedef struct fs_main_item_record_base
    {
        uint64 __VARIABLE__ ParentItemIndex;
        byte   __VARIABLE__ ItemId[__FILESYSTEM_ITEM_ID_LENGTH__];
        uint64 __VARIABLE__ CreateTime;
        uint64 __VARIABLE__ UpdateTime;
        uint64 __VARIABLE__ AccessTime;
        uint64 __VARIABLE__ Attributes;
        int64  __VARIABLE__ ItemSize;
        int32  __VARIABLE__ ItemBlocks;
        byte   __VARIABLE__ ItemName[__FILESYSTEM_ITEM_NAME_LENGTH__];
        byte   __VARIABLE__ ItemSecureAccessibility[__FILESYSTEM_SECURE_ACCESS_TABLE_SIZE__];
    }FS_MainItemRecordBase;

    #ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_UTILS_FS_UTILIZE_C_H__