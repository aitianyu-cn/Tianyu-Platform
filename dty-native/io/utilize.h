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

    // Pure C Mode

// IO Handle
// Provide a 64bits unsigned integer number to indicate a io instance.
// for for each type of IO instance, some specified operating ways 
// should be provided.
// There are some common way to IO base to provide some interface for
// disk and file. in order to provide a more open way to support additional
// io instance type, a register is provided as an externed api, by the new
// api, IOHandle could to support some customized instance not only file
// and disk.
typedef uint64 IOHandle;
typedef struct _dty_io_error_package
{
    int32 __POINTER__  Errors;
    int32 __VARIABLE__ ErrorCount;
}IOErrors;

IOHandle __VARIABLE__ dty_io_fopen
(
    const string __VARIABLE__ path,
    int32        __VARIABLE__ sourceType,
    int32        __VARIABLE__ access,
    bool         __VARIABLE__ ignoreCurrent
);
void     __VARIABLE__ dty_io_fclose(IOHandle __VARIABLE__ handle);
void     __VARIABLE__ dty_io_fflush(IOHandle __VARIABLE__ handle);
int32    __VARIABLE__ dty_io_fread(IOHandle __VARIABLE__ handle, byte __POINTER__ buffer, int32 __VARIABLE__ length);
void     __VARIABLE__ dty_io_fwrite(IOHandle __VARIABLE__ handle, byte __POINTER__ buffer, int32 __VARIABLE__ length);
bool     __VARIABLE__ dty_io_feof(IOHandle __VARIABLE__ handle);
uint64   __VARIABLE__ dty_io_fsize(IOHandle __VARIABLE__ handle);
uint64   __VARIABLE__ dty_io_fgetPos(IOHandle __VARIABLE__ handle);
void     __VARIABLE__ dty_io_fsetPos(IOHandle __VARIABLE__ handle, uint64 __VARIABLE__ newPos);
void     __VARIABLE__ dty_io_frewind(IOHandle __VARIABLE__ handle);
bool     __VARIABLE__ dty_io_fhasError(IOHandle __VARIABLE__ handle);
IOErrors __VARIABLE__ dty_io_fgetError(IOHandle __VARIABLE__ handle);
void     __VARIABLE__ dty_io_fclrError(IOHandle __VARIABLE__ handle);

bool __VARIABLE__ dty_io_fcreate(const string __VARIABLE__ path, int32 __VARIABLE__ sourceType);
bool __VARIABLE__ dty_io_frmFile(const string __VARIABLE__ path);
bool __VARIABLE__ dty_io_frmFolder(const string __VARIABLE__ path, bool __VARIABLE__ withSub);
bool __VARIABLE__ dty_io_fcopy(const string __VARIABLE__ source, const string __VARIABLE__ target);
bool __VARIABLE__ dty_io_fmove(const string __VARIABLE__ source, const string __VARIABLE__ target);
bool __VARIABLE__ dty_io_frename(const string __VARIABLE__ source, const string __VARIABLE__ newName);

typedef void     __VARIABLE__(__POINTER__ fn_dty_io_ext_operator_n_n)(byte __VARIABLE__ id[dty_native_id_default_size]);
typedef void     __VARIABLE__(__POINTER__ fn_dty_io_ext_operator_n_ui64)(byte __VARIABLE__ id[dty_native_id_default_size], uint64 __VARIABLE__ value_64);
typedef bool     __VARIABLE__(__POINTER__ fn_dty_io_ext_operator_rbool)(byte __VARIABLE__ id[dty_native_id_default_size]);
typedef uint64   __VARIABLE__(__POINTER__ fn_dty_io_ext_operator_rui64)(byte __VARIABLE__ id[dty_native_id_default_size]);
typedef IOErrors __VARIABLE__(__POINTER__ fn_dty_io_ext_operator_rioerr)(byte __VARIABLE__ id[dty_native_id_default_size]);

typedef int32 __VARIABLE__(__POINTER__ fn_dty_io_ext_read)(byte __VARIABLE__ id[dty_native_id_default_size], byte __POINTER__ buffer, int32 __VARIABLE__ length);
typedef void  __VARIABLE__(__POINTER__ fn_dty_io_ext_write)(byte __VARIABLE__ id[dty_native_id_default_size], byte __POINTER__ buffer, int32 __VARIABLE__ length);

typedef struct _dty_io_ext_operator
{
    fn_dty_io_ext_operator_n_n    __VARIABLE__ io_close;
    fn_dty_io_ext_operator_n_n    __VARIABLE__ io_flush;
    fn_dty_io_ext_read            __VARIABLE__ io_read;
    fn_dty_io_ext_write           __VARIABLE__ io_write;
    fn_dty_io_ext_operator_rbool  __VARIABLE__ io_eof;
    fn_dty_io_ext_operator_rui64  __VARIABLE__ io_size;
    fn_dty_io_ext_operator_rui64  __VARIABLE__ io_getPos;
    fn_dty_io_ext_operator_n_ui64 __VARIABLE__ io_setPos;
    fn_dty_io_ext_operator_n_n    __VARIABLE__ io_rewind;
    fn_dty_io_ext_operator_rbool  __VARIABLE__ io_hasError;
    fn_dty_io_ext_operator_rioerr __VARIABLE__ io_getError;
    fn_dty_io_ext_operator_n_n    __VARIABLE__ io_clrError;
}IOExtOperator;

IOHandle __VARIABLE__ dty_io_ext_open(byte __VARIABLE__ id[dty_native_id_default_size], IOExtOperator __VARIABLE__ extOperator);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_IO_UTILIZE_H__