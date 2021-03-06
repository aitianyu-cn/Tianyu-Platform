/**
 * @file error_list.h(fs/internal)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-08
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_FS_INTERNAL_ERROR_LIST_H__
#define __DTY_NATIVE_FS_INTERNAL_ERROR_LIST_H__

#include "../utilize.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    // pure C mode error list

// Define C mode error stack ring size
// error stack used a ring to save errors, in currently, only 16 errors can be
// saved, the newest error will overwrite the oldest one if errors count over 16
__DEFAULT__ const int32 __VARIABLE__ dty_fs_internal_error_list_stack_size = 16;

// FileSystem internal error list
// to use a stack ring(implement by a array)
typedef struct dty_fs_internal_error_list
{
    // error list count to record the errors count in the stack ring
    // this item that indicate the actual error count of the current 
    // list
    int16 __VARIABLE__ _count;
    // error header of this list
    // error list uses this item to save the index of the newest error
    int16 __VARIABLE__ _header;
    // error stack ring
    // to save errors(each error uses a unified 32bits integer number)
    int32 __VARIABLE__ _errors[dty_fs_internal_error_list_stack_size];
}_ErrorList;

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_FS_INTERNAL_ERROR_LIST_H__