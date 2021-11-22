/**
 * @file compare.r.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-19
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_INTERFACE_R_H__
#define __DTY_NATIVE_UTILS_INTERFACE_R_H__

#include"./utilize.r.h"

namespace dty::collection
{
    enum class CompareResult : int32
    {
        LESS = -1,
        EQUAL = 0,
        GREAT = 1
    };

    template<class Elem>
    _interface IEquatable
    {
        __PUB__ virtual ~IEquatable() {};

        __PUB__ virtual bool __VARIABLE__ Equals(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
    };

    template<class Elem>
    _interface ICompareable
    {
        __PUB__ virtual ~ICompareable() {};

        __PUB__ virtual CompareResult __VARIABLE__ CompareTo(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator <(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator >(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator <=(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator >=(Elem __REFERENCE__ other) = 0;
    };
}

#endif // !__DTY_NATIVE_UTILS_INTERFACE_R_H__
