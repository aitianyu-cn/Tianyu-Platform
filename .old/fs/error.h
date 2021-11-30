/**
 * @file error.h(utils/fs)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_FS_ERROR_H__
#define __DTY_NATIVE_UTILS_FS_ERROR_H__

#include"../error.h"

namespace dty::fs::except
{
    constexpr uint64 __VARIABLE__ DTY_FileSystem_ErrorBandException = 0x0100000000000001ULL;

    class ErrorFileSystemBandException final : public dty::except::Exception
    {
        __PUB__ ErrorFileSystemBandException();

        __PUB__ virtual ~ErrorFileSystemBandException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
#pragma endregion
    };
}

#endif // !__DTY_NATIVE_UTILS_FS_ERROR_H__