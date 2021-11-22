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
    class Array final
    {
        __PRI__ Elem  __POINTER__  _Array;
        __PRI__ int32 __VARIABLE__ _Count;
        __PRI__ bool  __VARIABLE__ _NeedFree;

        __PUB__ Array(Elem __POINTER__ arraySrc, int32 __VARIABLE__ count, bool __VARIABLE__ needFree = true)
            : _NeedFree(needFree)
        {
            if (null == arraySrc)
                throw dty::except::ArgumentNullException();

            if (0 >= count)
                throw dty::except::ArgumentOutOfRangeException();

            this->_Array = arraySrc;
            this->_Count = count;
        }
        __PUB__ ~Array()
        {
            if (!this->_NeedFree)
                return;

            if (1 == this->_Count)
                delete this->_Array;
            else
                delete [] this->_Array;
        }

        __PUB__ bool           __VARIABLE__  IsNull()
        {
            return null == this->_Array;
        }
        __PUB__ int32          __VARIABLE__  Size()
        {
            return this->_Count;
        }
        __PUB__ Elem           __REFERENCE__ operator[](int32 __VARIABLE__ index)
        {
            if (index >= this->_Count)
                throw dty::except::ArgumentOutOfRangeException();

            return this->_Array[index];
        }
        __PUB__ Iterator<Elem> __POINTER__   GetIterator()
        {
            return new SmartPointer<Iterator<Elem>>(new Iterator<Elem>(this->_Array, this->_Count));
        }
    };
}

#endif // !__DTY_NATIVE_UTILS_ARRAY_H__