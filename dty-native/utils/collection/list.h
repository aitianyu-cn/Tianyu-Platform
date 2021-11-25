/**
 * @file list.h(utils/collection)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-25
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_COLLECTION_LIST_H__
#define __DTY_NATIVE_UTILS_COLLECTION_LIST_H__

#include"../utilize.h"
#include"../array.h"

namespace dty::collection
{
    template<typename T>
    class List final
    {
        __PRI__ T     __POINTER__ _ArrayList;
        __PRI__ int32 __VARIABLE__ _Count;
        __PRI__ int32 __VARIABLE__ _ArraySize;

        __PUB__ List();
        __PUB__ List(int32 __VARIABLE__ size);
        __PUB__ List(int32 __VARIABLE__ size, int32 __VARIABLE__ maxSize);
        __PUB__ List(Array<T>& range);

#pragma region Private Struct Defination Area

#pragma endregion
    };

    using BoolList = List<bool>;
    using ShortList = List<int16>;
    using IntList = List<int32>;
    using LongList = List<int64>;
    using FloatList = List<float>;
    using DoubleList = List<double>;
    using CharList = List<char>;
}

#endif // !__DTY_NATIVE_UTILS_COLLECTION_LIST_H__