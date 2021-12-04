/**
 * @file utilize.hh(dthread)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-04
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_DTHREAD_UTILIZE_H_H__
#define __DTY_NATIVE_DTHREAD_UTILIZE_H_H__

#include "../utilize.hpp"

#ifdef __DTY_WIN
#include "windows.h"
#else
#include "unistd.h"
#endif // !__DTY_WIN __DTY_APF __DTY_LNX

namespace dty::thread
{
    uint32 __VARIABLE__ ThreadSleep(uint32 __VARIABLE__ milliseconds)
    {
#ifdef __DTY_WIN
        Sleep(milliseconds);
        return 0;
#else
        return sleep(milliseconds / 1000);
#endif // !__DTY_WIN __DTY_APF __DTY_LNX
    }
}

#endif // !__DTY_NATIVE_DTHREAD_UTILIZE_H_H__