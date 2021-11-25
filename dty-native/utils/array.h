/**
 * @file array.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_ARRAY_H__
#define __DTY_NATIVE_UTILS_ARRAY_H__

#include"./iterator.h"

namespace dty::collection
{
    template<class Elem>
    using ArrayIterator_SP = SmartPointer<Iterator<Elem>>;

    template<class Elem>
    class Array final
    {
        __PRI__ Elem  __POINTER__  _Array;
        __PRI__ int32 __VARIABLE__ _Count;
        __PRI__ int32 __POINTER__  _Reference;
        __PRI__ bool  __VARIABLE__ _NeedFree;

        __PUB__ Array(Elem __POINTER__ arraySrc, int32 __VARIABLE__ count, bool __VARIABLE__ needFree = true)
            : _Reference(null), _NeedFree(needFree)
        {
            if (null == arraySrc)
                throw dty::except::ArgumentNullException();

            if (0 >= count)
                throw dty::except::ArgumentOutOfRangeException();

            this->_Array = arraySrc;
            this->_Count = count;

            // record the instance reference only when 
            // the lifecycle of current pointer is mananged by Array
            if (this->_NeedFree)
                this->_Reference = new int32(1);
        }
        __PUB__ Array(const Array<Elem> __REFERENCE__ arr)
            : _Array(arr._Array), _Count(arr._Count), _Reference(arr._Reference), _NeedFree(arr._NeedFree)
        {
            if (this->_NeedFree)
                (__PTR_TO_VAR__(this->_Reference)) += 1;
        }
        __PUB__ ~Array()
        {
            if (!this->_NeedFree)
                return;

            if (1 == (__PTR_TO_VAR__(this->_Reference)))
            {
                delete [] this->_Array;
                delete this->_Reference;
            }
            else
                (__PTR_TO_VAR__(this->_Reference)) -= 1;
        }

        __PUB__ bool           __VARIABLE__   IsNull()
        {
            return null == this->_Array;
        }
        __PUB__ int32          __VARIABLE__   Size()
        {
            return this->_Count;
        }
        __PUB__ Elem           __REFERENCE__  operator[](int32 __VARIABLE__ index)
        {
            if (index >= this->_Count)
                throw dty::except::ArgumentOutOfRangeException();

            return this->_Array[index];
        }
        __PUB__ Iterator<Elem> __VARIABLE__   GetIterator()
        {
            return Iterator<Elem>(this->_Array, this->_Count);
        }

#ifdef __DTY_UNSAFE_MODE__
        __PUB__ void           __VARIABLE__   SetNoDelete()
        {

        }
        __PUB__ void           __VARIABLE__   SetNeedDelete()
        {

        }
#endif // !__DTY_UNSAFE_MODE__
    };

    using ByteArray = Array<byte>;
    using BoolArray = Array<bool>;
    using ShortArray = Array<int16>;
    using IntArray = Array<int32>;
    using LongArray = Array<int64>;
    using FloatArray = Array<float>;
    using DoubleArray = Array<double>;
    using CharArray = Array<char>;
}

#endif // !__DTY_NATIVE_UTILS_ARRAY_H__