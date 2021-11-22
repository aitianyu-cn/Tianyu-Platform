/**
 * @file iterator.g.h(utils)
 * @author senyun.yao
 * @brief collection base for tianyu platform
 * @version 0.1
 * @date 2021-11-15
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_ITERATOR_G_H__
#define __DTY_NATIVE_UTILS_ITERATOR_G_H__

#include"./utilize.r.h"
#include"./smartPointer.g.h"

 /**
  * @brief Tianyu Collection Namespace
  *
  */
namespace dty::collection
{
    template<class Elem>
    class FilterResult final
    {
        __PRI__ Elem  __POINTER__  Elems;
        __PRI__ int32 __VARIABLE__ Length;
        __PRI__ int32 __VARIABLE__ Size;
        __PRI__ bool  __VARIABLE__ NeedFree;

        __PUB__ FilterResult()
            : Elems(null), Length(0), Size(0), NeedFree(false)
        {

        }
        __PUB__ FilterResult(Elem __POINTER__ elems, int32 __VARIABLE__ length, int32 __VARIABLE__ size, bool __VARIABLE__ needFree = true)
            : NeedFree(needFree)
        {
            if (null == elems)
                throw dty::except::ArgumentNullException();

            if (0 >= length || length > size)
                throw dty::except::ArgumentOutOfRangeException();

            this->Elems = elems;
            this->Length = length;
            this->Size = size;
        }
        __PUB__ ~FilterResult()
        {
            if (!this->NeedFree)
                return;

            if (1 == this->Size)
                delete this->Elems;
            else
                delete [] this->Elems;
        }

        __PUB__ bool  __VARIABLE__ IsEmpty()
        {
            return 0 == this->Length;
        }
        __PUB__ int32 __VARIABLE__ GetLength()
        {
            return this->Length;
        }
        __PUB__ Elem  __REFERENCE__ operator[](int32 __VARIABLE__ index)
        {
            if (index >= this->Length)
                throw dty::except::ArgumentOutOfRangeException();

            return this->Elems[index];
        }
    };

    template<class Elem>
    class Iterator final
    {
        __PUB__ typedef void __VARIABLE__(__POINTER__ fnItemMap)(Elem __REFERENCE__ elem);
        __PUB__ typedef bool __VARIABLE__(__POINTER__ fnItemCheck)(Elem __REFERENCE__ elem);

        __PRI__ Elem  __POINTER__  _Pointer;
        __PRI__ int32 __VARIABLE__ _Size;
        __PRI__ bool  __VARIABLE__ _NeedFree;

        __PRI__ int32 __VARIABLE__ _Current;

        __PUB__ explicit Iterator(Elem __POINTER__ pointer, int32 __VARIABLE__ size, bool __VARIABLE__ needFree = false)
            : _NeedFree(needFree), _Current(0)
        {
            if (null == pointer)
                throw dty::except::ArgumentNullException();

            if (0 >= size)
                throw dty::except::ArgumentOutOfRangeException();

            this->_Pointer = pointer;
            this->_Size = size;
        }
        __PUB__ ~Iterator()
        {
            if (!this->_NeedFree)
                return;

            if (1 == this->_Size)
                delete this->_Pointer;
            else
                delete[] this->_Pointer;
        }

        __PUB__ void               __VARIABLE__ Reset()
        {
            this->_Current = 0;
        }
        __PUB__ SmartPointer<Elem> __VARIABLE__ Current()
        {
            return SmartPointer<Elem>((this->_Pointer) + this->_Current, 1, true);
        }
        __PUB__ SmartPointer<Elem> __VARIABLE__ Next()
        {
            if (this->_Current < this->_Size - 1)
                ++(this->_Current);

            return SmartPointer<Elem>((this->_Pointer) + this->_Current, 1, true);
        }
        __PUB__ SmartPointer<Elem> __VARIABLE__ End()
        {
            return SmartPointer<Elem>((this->_Pointer) + this->_Size - 1, 1, true);
        }


        __PUB__ void               __VARIABLE__ ForEach(fnItemMap __VARIABLE__ fnForEach)
        {
            for (int32 i = 0; i < this->_Size; ++i)
                fnForEach(this->_Pointer[i]);
        }
        __PUB__ Elem               __POINTER__  Some(fnItemCheck __VARIABLE__ fnForEach)
        {
            for (int32 i = 0; i < this->_Size; ++i)
                if (!fnForEach(this->_Pointer[i]))
                    return (this->_Pointer) + i;

            return null;
        }
        __PUB__ FilterResult<Elem> __VARIABLE__ Filter(fnItemCheck __VARIABLE__ fnForEach)
        {
            Elem __POINTER__ results = new Elem[this->_Size];
            int32 length = 0;

            for (int32 i = 0; i < this->_Size; ++i)
                if (fnForEach(this->_Pointer[i]))
                    results[length++] = (this->_Pointer) + i;

            if (0 == length)
            {
                delete [] results;
                return FilterResult<Elem>();
            }

            return FilterResult<Elem>(results, length, this->_Size);
        }
        __PUB__ FilterResult<Elem> __VARIABLE__ Every(fnItemCheck __VARIABLE__ fnForEach)
        {
            Elem __POINTER__ results = new Elem[this->_Size];
            int32 length = 0;

            for (int32 i = 0; i < this->_Size; ++i)
                if (!fnForEach(this->_Pointer[i]))
                    results[length++] = (this->_Pointer) + i;

            if (0 == length)
            {
                delete [] results;
                return FilterResult<Elem>();
            }

            return FilterResult<Elem>(results, length, this->_Size);
        }
        __PUB__ Elem               __POINTER__  Find(fnItemCheck __VARIABLE__ fnForEach)
        {
            for (int32 i = 0; i < this->_Size; ++i)
                if (fnForEach(this->_Pointer[i]))
                    return (this->_Pointer) + i;

            return null;
        }
        __PUB__ int32              __VARIABLE__ FindIndex(fnItemCheck __VARIABLE__ fnForEach)
        {
            for (int32 i = 0; i < this->_Size; ++i)
                if (fnForEach(this->_Pointer[i]))
                    return i;

            return -1;
        }
    };

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

#endif // !__DTY_NATIVE_UTILS_ITERATOR_G_H__
