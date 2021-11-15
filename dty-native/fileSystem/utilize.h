/**
 * @file utilize.h(fileSystem)
 * @author senyun.yao
 * @brief Public common for Tianyu File System
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_FILESYSTEM_UTILIZE_H__
#define __DTY_NATIVE_FILESYSTEM_UTILIZE_H__

#include"../utilize.h"

namespace dty
{
    namespace fs
    {
        struct Bitmap
        {
            byte   __POINTER__ _Map;
            uint64 __VARIABLE__ _MapSize;
            uint64 __VARIABLE__ _ItemCount;
        };
    }
}

#endif // !__DTY_NATIVE_FILESYSTEM_UTILIZE_H__