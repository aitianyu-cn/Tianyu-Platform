/**
 * @file utilize.h(io)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-01
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_IO_UTILIZE_H__
#define __DTY_NATIVE_IO_UTILIZE_H__

#include"../utilize.h"

#define __DTY_IO_SOURCE_TYPE_UNKN__   0
#define __DTY_IO_SOURCE_TYPE_FILE__   1
#define __DTY_IO_SOURCE_TYPE_DISK__   2
#define __DTY_IO_SOURCE_TYPE_FOLDER__ 3

#define __DTY_IO_SOURCE_ACCESS_RW__ 3
#define __DTY_IO_SOURCE_ACCESS_RO__ 2
#define __DTY_IO_SOURCE_ACCESS_WO__ 1
#define __DTY_IO_SOURCE_ACCESS_NO__ 0

#define __DTY_IO_ERROR_ER_NOT_EXIST__ -1
#define __DTY_IO_ERROR_ER_NO_ACCESS__ -2

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

typedef uint64 IOHandle;
typedef struct _dty_io_error_package
{
    int32 __POINTER__  Errors;
    int32 __VARIABLE__ ErrorCount;
}IOErrors;

IOHandle __VARIABLE__ dty_fopen
(
    const string __VARIABLE__ path,
    int32        __VARIABLE__ sourceType,
    int32        __VARIABLE__ access,
    bool         __VARIABLE__ ignoreCurrent
);
void     __VARIABLE__ dty_fclose(IOHandle __VARIABLE__ handle);
void     __VARIABLE__ dty_fflush(IOHandle __VARIABLE__ handle);
int32    __VARIABLE__ dty_fread(IOHandle __VARIABLE__ handle, byte __POINTER__ buffer, int32 __VARIABLE__ length);
void     __VARIABLE__ dty_fwrite(IOHandle __VARIABLE__ handle, byte __POINTER__ buffer, int32 __VARIABLE__ length);
bool     __VARIABLE__ dty_feof(IOHandle __VARIABLE__ handle);
uint64   __VARIABLE__ dty_fsize(IOHandle __VARIABLE__ handle);
uint64   __VARIABLE__ dty_fgetPos(IOHandle __VARIABLE__ handle);
void     __VARIABLE__ dty_fsetPos(IOHandle __VARIABLE__ handle, uint64 __VARIABLE__ newPos);
void     __VARIABLE__ dty_frewind(IOHandle __VARIABLE__ handle);
bool     __VARIABLE__ dty_fhasError(IOHandle __VARIABLE__ handle);
IOErrors __VARIABLE__ dty_fgetError(IOHandle __VARIABLE__ handle);
void     __VARIABLE__ dty_fclrError(IOHandle __VARIABLE__ handle);

bool __VARIABLE__ dty_fcreate(const string __VARIABLE__ path, int32 __VARIABLE__ sourceType);
bool __VARIABLE__ dty_frmFile(const string __VARIABLE__ path);
bool __VARIABLE__ dty_frmFolder(const string __VARIABLE__ path, bool __VARIABLE__ withSub);
bool __VARIABLE__ dty_fcopy(const string __VARIABLE__ source, const string __VARIABLE__ target);
bool __VARIABLE__ dty_fmove(const string __VARIABLE__ source, const string __VARIABLE__ target);
bool __VARIABLE__ dty_frename(const string __VARIABLE__ source, const string __VARIABLE__ newName);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_IO_UTILIZE_H__