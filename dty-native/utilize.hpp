/**
 * @file utilize.hpp(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-06
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_UTILIZE_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_UTILIZE_H_PLUS_PLUS__

#include "../commons/native/core/utilize.hpp"

namespace dty
{
    _interface IObjectConverter
    {
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize) = 0;
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) = 0;
    };
    _interface IStringConverter
    {
        __PUB__ virtual string __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize) const = 0;
        __PUB__ virtual string __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) const = 0;
    };

    template<typename _Key, typename _Val>
    class KeyValuePair final
    {
        __PUB__ _Key __VARIABLE__ Key;
        __PUB__ _Val __VARIABLE__ Value;

        __PUB__ KeyValuePair(_Key key, _Val val)
            : Key(key), Value(val)
        {

        }
        __PUB__ ~KeyValuePair() { }
    };

    namespace collection
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
            __PUB__ virtual ~IEquatable() { };

            __PUB__ virtual bool __VARIABLE__ Equals(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
        };

        template<class Elem>
        _interface ICompareable
        {
            __PUB__ virtual ~ICompareable() { };

            __PUB__ virtual CompareResult __VARIABLE__ CompareTo(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator <(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator >(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator <=(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator >=(Elem __REFERENCE__ other) = 0;
        };
    }
}

#endif // !__DTY_NATIVE_UTILS_UTILIZE_H_PLUS_PLUS__