/**
 * @file timer.hpp(dthread)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.timers.timer?view=net-6.0#constructors
 */

#ifndef __DTY_NATIVE_DTHREAD_TIMER_H_PLUS_PLUS__
#define __DTY_NATIVE_DTHREAD_TIMER_H_PLUS_PLUS__

#include "./utilize.hh"
#include "../dty.utils.hxx"

namespace dty::thread
{
    __PREDEFINE__ class Timer;
    class ElapsedEventArgs final : public virtual EventArgs
    {
        __PRO__ ElapsedEventArgs(DateTime __REFERENCE__ dateTime);

        __PUB__ ElapsedEventArgs(ElapsedEventArgs __REFERENCE__ args);
        __PUB__ virtual ~ElapsedEventArgs() override;

        __PUB__ DateTime __VARIABLE__ GetSignalTime();

        friend class Timer;
    };

    void __VARIABLE__(__POINTER__ fnElapsedEventHandler)(object __VARIABLE__ sender, ElapsedEventArgs __VARIABLE__ e);

    class ElapsedEventHandler final : public virtual dty::EventHandler<ElapsedEventArgs>
    {
        __PUB__ ElapsedEventHandler();
        __PUB__ virtual ~ElapsedEventHandler() override;
    };

    class TimerEventsList final
    {

    };

    class Timer final
    {
        __PUB__ Timer();
        __PUB__ Timer(double __VARIABLE__ interval);

        __PUB__ bool __VARIABLE__   GetAutoReset();
        __PUB__ bool __VARIABLE__   GetCanRaiseEvents();
        __PUB__ bool __VARIABLE__   GetEnabled();
        __PUB__ double __VARIABLE__ GetInterval();

        __PUB__ void __VARIABLE__ SetAutoReset(bool __VARIABLE__ autoReset);
        __PUB__ void __VARIABLE__ SetCanRaiseEvents(bool __VARIABLE__ canRaiseEvents);
        __PUB__ void __VARIABLE__ SetEnabled(bool __VARIABLE__ isEnabled);
        __PUB__ void __VARIABLE__ SetInterval(double __VARIABLE__ interval);
    };
}

#endif // !__DTY_NATIVE_DTHREAD_TIMER_H_PLUS_PLUS__