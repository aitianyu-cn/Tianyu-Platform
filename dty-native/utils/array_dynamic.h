/**
 * @file array_dynamic.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-23
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_DYNAMIC_ARRAY_H__
#define __DTY_NATIVE_UTILS_DYNAMIC_ARRAY_H__

#include"./iterator.h"

namespace dty::collection
{
    template<class Elem>
    class DynamicArray final
    {
        __PUB__ DynamicArray();
        __PUB__ DynamicArray(int32 __VARIABLE__ initSize);
        __PUB__ DynamicArray(int32 __VARIABLE__ initSize, int32 __VARIABLE__ limitSize);
        __PUB__ DynamicArray(Elem __POINTER__ source, int32 __VARIABLE__ length);
        __PUB__ DynamicArray(Elem __POINTER__ source, int32 __VARIABLE__ length, int32 __VARIABLE__ limitSize);
        __PUB__ DynamicArray(Elem __POINTER__ source, int32 __VARIABLE__ length, bool __VARIABLE__ needFree);
        __PUB__ DynamicArray(Elem __POINTER__ source, int32 __VARIABLE__ length, int32 __VARIABLE__ limitSize, bool __VARIABLE__ needFree);
        __PUB__ ~DynamicArray();

        __PUB__ int32 __VARIABLE__ Length();
        __PUB__ bool  __VARIABLE__ IsEmpty();

        __PUB__ void  __VARIABLE__ Add(Elem __REFERENCE__ elem);
        __PUB__ void  __VARIABLE__ AddRange(Elem __POINTER__ elem, int32 __VARIABLE__ length);
        __PUB__ void  __VARIABLE__ Insert(Elem __REFERENCE__ elem, int32 __VARIABLE__ index);
        __PUB__ void  __VARIABLE__ Shift(Elem __REFERENCE__ elem);

        __PUB__ void  __VARIABLE__ Remove(int32 __VARIABLE__ index);

        __PUB__ Elem           __REFERENCE__ operator[](int32 __VARIABLE__ index);
        __PUB__ Iterator<Elem> __POINTER__   GetIterator();
    };
}

#endif // !__DTY_NATIVE_UTILS_DYNAMIC_ARRAY_H__