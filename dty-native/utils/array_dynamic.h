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
    constexpr int32 __VARIABLE__ __DynamicArrayBaseSize = 8;
    template<class Elem>
    class DynamicArray final
    {
        __PRI__ Elem  __DPOINTER__ _Array;

        __PRI__ int32 __POINTER__  _ArraySize;
        __PRI__ int32 __POINTER__  _Reference;

        __PRI__ int32 __POINTER__  _Count;
        __PRI__ int32 __VARIABLE__ _InitSize;
        __PRI__ int32 __VARIABLE__ _LimitSize;
        __PRI__ bool  __VARIABLE__ _NeedFree;

        __PUB__ DynamicArray()
            : _Array(new (Elem __POINTER__)[1]), _ArraySize(new int32(__DynamicArrayBaseSize)), _Reference(new int32(1)),
            _InitSize(__DynamicArrayBaseSize), _Count(new int32(0)), _LimitSize(-1), _NeedFree(true)
        {
            this->_Array[0] = new Elem[this->__GetArraySize()];
        }
        __PUB__ DynamicArray(int32 __VARIABLE__ initSize)
        {
            if (0 >= initSize)
                throw dty::except::ArgumentOutOfRangeException();

            initSize = __DynamicArrayBaseSize > initSize ? __DynamicArrayBaseSize : initSize;

            this->__InitData(initSize, true, -1);

            this->_Array[0] = new Elem[this->__GetArraySize()];
        }
        __PUB__ DynamicArray(int32 __VARIABLE__ initSize, int32 __VARIABLE__ limitSize)
        {
            if (0 >= initSize || 0 >= limitSize)
                throw dty::except::ArgumentException();

            initSize = __DynamicArrayBaseSize > initSize ? __DynamicArrayBaseSize : initSize;
            if (limitSize < initSize)
                throw dty::except::ArgumentException();

            this->__InitData(initSize, true, limitSize);

            this->_Array[0] = new Elem[this->__GetArraySize()];
        }
        __PUB__ DynamicArray(Elem __POINTER__ source, int32 __VARIABLE__ length, bool __VARIABLE__ needFree = true)
        {
            if (null == source)
                throw dty::except::ArgumentNullException();

            if (0 >= length)
                throw dty::except::ArgumentOutOfRangeException();

            int32 __VARIABLE__ initSize = __DynamicArrayBaseSize > length ? __DynamicArrayBaseSize : length;

            this->__InitData(initSize, needFree, -1);

            this->_Array[0] = new Elem[this->__GetArraySize()];
            for (int32 i = 0; i < length; ++i)
                this->_Array[0][i] = source[i];

            this->__SetCount(length);

            if (needFree)
                delete [] source;
        }
        __PUB__ DynamicArray(Elem __POINTER__ source, int32 __VARIABLE__ length, int32 __VARIABLE__ limitSize, bool __VARIABLE__ needFree = true)
        {
            if (0 >= initSize || 0 >= limitSize)
                throw dty::except::ArgumentException();

            int32 __VARIABLE__ initSize = __DynamicArrayBaseSize > initSize ? __DynamicArrayBaseSize : initSize;
            if (limitSize < initSize)
                throw dty::except::ArgumentException();

            this->__InitData(initSize, needFree, limitSize);

            this->_Array[0] = new Elem[this->__GetArraySize()];
            for (int32 i = 0; i < length; ++i)
                this->_Array[0][i] = source[i];

            this->__SetCount(length);

            if (needFree)
                delete [] source;
        }
        __PUB__ DynamicArray(const DynamicArray<Elem> __REFERENCE__ array)
            : _Array(array._Array), _ArraySize(array._ArraySize), _Reference(array._Reference), _Count(array._Count),
            _InitSize(array._InitSize), _LimitSize(array._LimitSize), _NeedFree(array._NeedFree)
        {
            ++(__PTR_TO_VAR__(this->_Reference));
        }
        __PUB__ ~DynamicArray()
        {
            if (1 == (__PTR_TO_VAR__(this->_Reference)))
            {
                delete [](this->_Array[0]);
                delete [] this->_Array;
                delete this->_ArraySize;
                delete this->_Reference;
                delete this->_Count;
            }
            else
                --(__PTR_TO_VAR__(this->_Reference));
        }

        __PUB__ void  __VARIABLE__ Clear()
        {
            delete [](this->_Array[0]);
            this->__SetCount(0);
            (__PTR_TO_VAR__(this->_ArraySize)) = this->_InitSize;
            this->_Array[0] = new Elem[this->__GetArraySize()];
        }
        __PUB__ int32 __VARIABLE__ Length()
        {
            return __PTR_TO_VAR__(this->_Count);
        }
        __PUB__ bool  __VARIABLE__ IsEmpty()
        {
            return 0 == this->Length();
        }

        __PUB__ void  __VARIABLE__ Add(Elem __REFERENCE__ elem);
        __PUB__ void  __VARIABLE__ AddRange(Elem __POINTER__ elem, int32 __VARIABLE__ length);
        __PUB__ void  __VARIABLE__ Insert(Elem __REFERENCE__ elem, int32 __VARIABLE__ index);
        __PUB__ void  __VARIABLE__ Shift(Elem __REFERENCE__ elem);

        __PUB__ void  __VARIABLE__ Remove(int32 __VARIABLE__ index);

        __PUB__ Elem           __REFERENCE__ operator[](int32 __VARIABLE__ index);
        __PUB__ Iterator<Elem> __POINTER__   GetIterator();

        __PRI__ void  __VARIABLE__ __InitData(int32 __VARIABLE__ initSize, bool __VARIABLE__ needFree, int32 __VARIABLE__ limitSize)
        {
            this->_ArraySize = new int32(initSize);
            this->_Reference = new int32(1);
            this->_Count = new int32(0);
            this->_InitSize = initSize;
            this->_LimitSize = limitSize;
            this->_NeedFree = needFree;

            this->_Array = new (Elem __POINTER__)[1];
        }
        __PRI__ int32 __VARIABLE__ __GetArraySize()
        {
            return __PTR_TO_VAR__(this->_ArraySize);
        }

        __PRI__ void  __VARIABLE__ __IncreaseCount()
        {
            ++(__PTR_TO_VAR__(this->_Count));
        }
        __PRI__ void  __VARIABLE__ __DecreaseCount()
        {
            --(__PTR_TO_VAR__(this->_Count));
        }
        __PRI__ void  __VARIABLE__ __SetCount(int32 __VARIABLE__ count)
        {
            (__PTR_TO_VAR__(this->_Count)) = count;
        }
    };
}

#endif // !__DTY_NATIVE_UTILS_DYNAMIC_ARRAY_H__