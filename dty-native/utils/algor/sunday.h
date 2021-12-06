/**
 * @file sunday.h(utils/algor)
 * @author senyun.yap
 * @brief
 * @version 0.1
 * @date 2021-11-23
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_ALGOR_SUNDAY_H__
#define __DTY_NATIVE_UTILS_ALGOR_SUNDAY_H__

#include"../../utilize.hpp"

namespace dty::algor
{
    template<typename T>
    class Sunday
    {
#pragma region Private Internal Collection
        __PRI__ class TListItem
        {
            __PUB__ T         __REFERENCE__ Value;
            __PUB__ int32     __VARIABLE__  Shift;

            __PUB__ TListItem __POINTER__   Next;

            __PUB__ TListItem(T __REFERENCE__ value, int32 __VARIABLE__ shift)
                : Value(value), Shift(shift), Next(null)
            {

            }
        };
#pragma endregion

        __PRI__ T         __POINTER__  _SubBunch;
        __PRI__ int32     __VARIABLE__ _Length;
        __PRI__ TListItem __POINTER__  _SubBunchShift;

        __PUB__ Sunday(T __POINTER__ subBunch, int32 __VARIABLE__ length);
        __PUB__ virtual ~Sunday();

        __PUB__ int32 __VARIABLE__ IndexOf(T __POINTER__ bunch, int32 __VARIABLE__ length);
        __PUB__ int32 __VARIABLE__ Find(T __POINTER__ bunch, int32 __VARIABLE__ length);
    };
}

#endif // !__DTY_NATIVE_UTILS_ALGOR_SUNDAY_H__