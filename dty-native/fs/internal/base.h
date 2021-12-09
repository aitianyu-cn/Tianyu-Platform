/**
 * @file base.h(fs/internal)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-09
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_FS_INTERNAL_BASE_H__
#define __DTY_NATIVE_FS_INTERNAL_BASE_H__

#include "../utilize.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

__DEFAULT__ const int32 __VARIABLE__ dty_fs_internal_user_table_size = 256;

typedef struct dty_fs_internal_user_table
{

}_FSUserTable;

typedef struct dty_fs_internal_file_info
{

}_FSFileInfo;

typedef struct dty_fs_internal_folder_info
{

}_FSFolderInfo;

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_FS_INTERNAL_BASE_H__