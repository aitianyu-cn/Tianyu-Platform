/**
 * @file thread.hpp(dthread)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-04
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_DTHREAD_THREAD_H_PLUS_PLUS__
#define __DTY_NATIVE_DTHREAD_THREAD_H_PLUS_PLUS__

#include "./utilize.hh"

namespace dty::thread
{
    enum class ThreadPriority :int32
    {
        AboveNormal = 3,
        BelowNormal = 1,
        Highest = 4,
        Lowest = 0,
        Normal = 2
    };

    enum class ThreadState :int32
    {
        Aborted = 256,
        AbortRequested = 128,
        Background = 4,
        Running = 0,
        Stopped = 16,
        StopRequested = 1,
        Suspended = 64,
        SuspendRequested = 2,
        Unstarted = 8,
        WaitSleepJoin = 32
    };
}

#endif // !__DTY_NATIVE_DTHREAD_THREAD_H_PLUS_PLUS__