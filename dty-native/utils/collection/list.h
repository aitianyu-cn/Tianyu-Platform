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
#include"./error.h"

namespace dty::collection
{
    template<typename T>
    class List final
    {
        __PRI__ T     __DPOINTER__ _ArrayList;
        __PRI__ int32 __POINTER__  _Count;
        __PRI__ int32 __POINTER__  _ArraySize;
        __PRI__ int32 __POINTER__  _Reference;
        __PRI__ bool  __VARIABLE__ _IsReadOnly;
        __PRI__ int32 __VARIABLE__ _MaxSize;

        __PUB__ List()
            : _Count(new int32(0)), _ArraySize(new int32(List<T>::ListDefaultSize)),
            _Reference(new int32(1)), _IsReadOnly(false),
            _AddRange_ForEach_Start(-1), _MaxSize(-1)
        {
            this->_ArrayList = new (T __POINTER__)[1];
            this->_ArrayList[0] = new T[List<T>::ListDefaultSize];
        }
        __PUB__ List(int32 __VARIABLE__ size) : _AddRange_ForEach_Start(-1), _MaxSize(-1)
        {
            size = List<T>::ListDefaultSize > size
                ? List<T>::ListDefaultSize : size;
            this->_ArraySize = new int32(size);

            this->_ArrayList = new (T __POINTER__)[1];
            this->_ArrayList[0] = new T[this->_ArraySize];

            this->_Count = new int32(0);
            this->_Reference = new int32(1);
            this->_IsReadOnly = false;
        }
        __PUB__ List(int32 __VARIABLE__ size, int32 __VARIABLE__ maxSize)
            : _AddRange_ForEach_Start(-1), _MaxSize(maxSize)
        {
            size = List<T>::ListDefaultSize > size
                ? List<T>::ListDefaultSize : size;
            if (size > maxSize)
                throw dty::except::ArgumentException();

            this->_ArraySize = new int32(size);

            this->_ArrayList = new (T __POINTER__)[1];
            this->_ArrayList[0] = new T[this->_ArraySize];

            this->_Count = new int32(0);
            this->_Reference = new int32(1);
            this->_IsReadOnly = false;
        }
        __PUB__ List(Array<T> __REFERENCE__ range) : _AddRange_ForEach_Start(-1)
            : _ArrayList(new (T __POINTER__)[1]), _MaxSize(-1)
        {
            if (range.IsNull() || 0 == range.Size())
            {
                // empty array should not to copy, to create a new space like normal
                this->_ArraySize = new int32(List<T>::ListDefaultSize);

                this->_ArrayList[0] = new T[this->_ArraySize];

                this->_Count = new int32(0);
                this->_Reference = new int32(1);
                this->_IsReadOnly = false;
            }
            else
            {

#ifdef __DTY_UNSAFE_MODE__
                this->_ArraySize = new int32(range.Size());

                this->_ArrayList[0] = __REF_TO_PTR__(range[0]);

                this->_Count = new int32(range.Size());
                this->_Reference = new int32(1);
                this->_IsReadOnly = false;

                // only when in unsafe mode, set array do not need to free memory
                range.SetNoDelete();
#else
                this->_ArraySize = new int32(range.Size() + List<T>::ListDefaultSize);

                this->_ArrayList[0] = new T[this->_ArraySize];

                this->_Count = new int32(range.Size());
                this->_Reference = new int32(1);
                this->_IsReadOnly = false;

                // in safe mode, copy all data from array range
                for (int32 i = 0; i < range.Size(); ++i)
                    this->_ArrayList[i] = range[i];
#endif // !__DTY_UNSAFE_MODE__
            }
        }
        __PUB__ List(const List<T> __REFERENCE__ list)
            : _ArrayList(list._ArrayList), _Count(list._Count), _ArraySize(list._ArraySize),
            _Reference(list._Reference), _IsReadOnly(list._IsReadOnly),
            _AddRange_ForEach_Start(-1), _MaxSize(list._MaxSize)
        {
            ++(__PTR_TO_VAR__ this->_Reference);
        }
        __PUB__ ~List()
        {
            if (1 == (__PTR_TO_VAR__(this->_Reference)))
            {
                delete this->_ArraySize;
                delete this->_Count;
                delete this->_Reference;

                delete [] this->_ArrayList[0];
                delete [] this->_ArrayList;
            }
            else
            {
                --(__PTR_TO_VAR__(this->_Reference));

                this->_ArrayList[0] = null;
                delete this->_ArrayList;
            }
        }

        __PUB__ void  __VARIABLE__ Clear()
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            delete [](this->_ArrayList[0]);

            this->_ArrayList[0] = new T[List<T>::ListDefaultSize];

            this->_SetCount(0);
            this->_SetCapacity(List<T>::ListDefaultSize);
        }
        __PUB__ int32 __VARIABLE__ Count()
        {
            return __PTR_TO_VAR__(this->_Count);
        }
        __PUB__ int32 __VARIABLE__ Capacity()
        {
            return __PTR_TO_VAR__(this->_ArraySize);
        }
        __PUB__ bool  __VARIABLE__ IsReadOnly()
        {
            return this->_IsReadOnly;
        }
        __PUB__ void  __VARIABLE__ SetReadOnly(bool __VARIABLE__ readOnly)
        {
            this->_IsReadOnly = readOnly;
        }

        __PUB__ void  __VARIABLE__ Add(const T __REFERENCE__ elem)
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            if (this->Count() >= this->Capacity())
                this->_SetCapacity(List<T>::ListGrowth(this->_ArrayList, this->Capacity()));

            this->_ArrayList[0][__PTR_TO_VAR__(this->_Count)] = elem;
            this->_IncreaseCount();
        }
        __PUB__ void  __VARIABLE__ AddRange(const Iterator<T> __REFERENCE__ range)
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            if (0 == range.Size())
                return;

            if (this->Count() >= this->Capacity())
                this->_SetCapacity(List<T>::ListGrowth(this->_ArrayList, this->Capacity(), range.Size()));

            this->_AddRange_ForEach_Start = -1;
            range.ForEach(this->_fnAddRange_ForEach);

            this->_SetCount(this->Count() + range.Size());
        }

        __PUB__ int32 __VARIABLE__ IndexOf(const T __REFERENCE__ elem)
        {
            if (0 == this->Count())
                return -1;

            const T __POINTER__ arr = this->_ArrayList[0];
            for (int32 i = 0; i < this->Count(); ++i)
                if (elem == arr[i])
                    return i;

            return -1;
        }
        __PUB__ int32 __VARIABLE__ IndexOf(T __REFERENCE__ elem, int32 __VARIABLE__ startIndex)
        {
            if (0 > startIndex || this->Count() <= startIndex)
                throw dty::except::ArgumentOutOfRangeException();

            if (0 == this->Count())
                return -1;

            const T __POINTER__ arr = this->_ArrayList[0];
            for (int32 i = startIndex; i < this->Count(); ++i)
                if (elem == arr[i])
                    return i;

            return -1;
        }
        __PUB__ int32 __VARIABLE__ IndexOf(T __REFERENCE__ elem, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex)
        {
            if (0 > startIndex || this->Count() <= startIndex || 0 > endIndex || startIndex > endIndex || this->Count() <= endIndex)
                throw dty::except::ArgumentOutOfRangeException();

            if (0 == this->Count())
                return -1;

            const T __POINTER__ arr = this->_ArrayList[0];
            for (int32 i = startIndex; i <= endIndex; ++i)
                if (elem == arr[i])
                    return i;

            return -1;
        }

        __PUB__ void  __VARIABLE__ Insert(int32 __VARIABLE__ index, T __REFERENCE__ elem)
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            if (0 > index || index > this->Count())
                throw dty::except::ArgumentOutOfRangeException();

            if (this->Count() >= this->Capacity())
                this->_SetCapacity(List<T>::ListGrowth(this->_ArrayList, this->Capacity()));

            for (int32 i = this->Count(); i < index; ++i)
                this->_ArrayList[0][i] = this->_ArrayList[0][i - 1];

            this->_ArrayList[0][index] = T;
            this->_IncreaseCount();
        }
        __PUB__ void  __VARIABLE__ InsertRange(int32 __VARIABLE__ index, Iterator<T> __VARIABLE__ range)
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            if (0 > index || index > this->Count())
                throw dty::except::ArgumentOutOfRangeException();

            if (0 == range.Size())
                return;

            if (this->Count() >= this->Capacity())
                this->_SetCapacity(List<T>::ListGrowth(this->_ArrayList, this->Capacity(), range.Size()));

            for (int32 i = this->Count() - 1; i > index; ++i)
                this->_ArrayList[0][i + range.Size()] = this->_ArrayList[0][i];

            this->_AddRange_ForEach_Start = index;
            range.ForEach(this->_fnAddRange_ForEach);

            this->_SetCount(this->Count() + range.Size());
        }
        __PUB__ void  __VARIABLE__ Remove(const T __REFERENCE__ elem)
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            if (0 == this->Count())
                return;
            int32 removeIndex = -1;

            try
            {
                for (int32 i = 0; i < this->Count(); ++i)
                    if (this->_ArrayList[0][i] == elem)
                    {
                        removeIndex = -1;
                        break;
                    }

                if (-1 != removeIndex)
                {
                    for (int32 i = removeIndex; i < this->Count() - 1; ++i)
                        this-- > _ArrayList[0][i] = this->_ArrayList[0][i + 1];

                    this->_DecreaseCount();
                }
            }
            catch (const std::exception)
            {
                throw dty::except::OperationNotSupportException();
            }

        }
        __PUB__ void  __VARIABLE__ RemoveAt(int32 __VARIABLE__ index)
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            if (0 > index || index > this->Count())
                throw dty::except::ArgumentOutOfRangeException();

            for (int32 i = index; i < this->Count() - 1; ++i)
                this-- > _ArrayList[0][i] = this->_ArrayList[0][i + 1];

            this->_DecreaseCount();
        }
        __PUB__ void  __VARIABLE__ RemoveRange(int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex)
        {
            if (this->_IsReadOnly)
                throw dty::collection::except::CollectionReadOnlyException();

            if (0 > startIndex || this->Count() <= startIndex || 0 > endIndex || startIndex > endIndex || this->Count() <= endIndex)
                throw dty::except::ArgumentOutOfRangeException();

            if (0 == this->Count())
                return;

            int32 removeCount = endIndex - startIndex + 1;
            int32 newCount = this->Count() - removeCount;
            for (int32 i = startIndex; i < newCount; ++i)
                this->_ArrayList[0][i] = this->_ArrayList[0][i + removeCount];

            this->_SetCount(newCount);
        }

        __PUB__ Array<T>    __VARIABLE__  CopyTo()
        {
            T __POINTER__ cpyList = new T[this->Count()];
            for (int32 i = 0; i < this->Count(); ++i)
                cpyList[i] = this->_ArrayList[0][i];

            return Array<T>(cpyList, this->Count());
        }
        __PUB__ Array<T>    __VARIABLE__  CopyTo(int32 __VARIABLE__ startIndex)
        {
            if (0 > startIndex || startIndex > this->Count())
                throw dty::except::ArgumentOutOfRangeException();

            int32 cpyCount = this->Count() - startIndex;
            T __POINTER__ cpyList = new T[cpyCount];
            for (int32 i = 0; i < cpyCount; ++i)
                cpyList[i] = this->_ArrayList[0][i + startIndex];

            return Array<T>(cpyList, cpyCount);
        }

        __PUB__ List<T>     __VARIABLE__  Clone()
        {
            if (0 == this->Count())
                return List<T>();

            T __POINTER__ cloneList = new T[this->Count()];
            for (int32 i = 0; i < this->Count(); ++i)
                cloneList[i] = this->_ArrayList[0][i];

            return List<T>(cloneList, this->Count());
        }

        __PUB__ Array<T>    __VARIABLE__  ToArray()
        {
            if (0 == this->Count())
                return Array<T>(null, 0);

            T __POINTER__ cloneList = new T[this->Count()];
            for (int32 i = 0; i < this->Count(); ++i)
                cloneList[i] = this->_ArrayList[0][i];

            return Array<T>(cloneList, this->Count());
        }
        __PUB__ Iterator<T> __VARIABLE__  GetIterator()
        {
            if (0 == this->Count())
                return Iterator<T>(null, 0);

            return Iterator<T>(this->_ArrayList[0], this->Count());
        }
        __PUB__ T           __REFERENCE__ operator[](int32 __VARIABLE__ index)
        {
            if (0 > index || this->Count() <= index)
                throw dty::except::ArgumentOutOfRangeException();

            return this->_ArrayList[0][index];
        }
#pragma region Private Functions
        __PRI__ List(T __POINTER__ source, int32 __VARIABLE__ count)
            : _Count(new int32(0)), _ArraySize(new int32(List<T>::ListDefaultSize)),
            _Reference(new int32(1)), _IsReadOnly(false),
            _AddRange_ForEach_Start(-1)
        {
            this->_ArrayList = new (T __POINTER__)[1];
            this->_ArrayList[0] = source;
        }

        __PRI__ void __VARIABLE__ _IncreaseCount()
        {
            ++(__PTR_TO_VAR__(this->_Count));
        }
        __PRI__ void __VARIABLE__ _DecreaseCount()
        {
            --(__PTR_TO_VAR__(this->_Count));
        }
        __PRI__ void __VARIABLE__ _SetCount(int32 __VARIABLE__ newCount)
        {
            (__PTR_TO_VAR__(this->_Count)) = newCount;
        }
        __PRI__ void __VARIABLE__ _SetCapacity(int32 __VARIABLE__ newCap)
        {
            (__PTR_TO_VAR__(this->_ArraySize)) = newCap;
        }

        __PRI__ int32 __VARIABLE__ _AddRange_ForEach_Start;
        __PRI__ void  __VARIABLE__ _fnAddRange_ForEach(T __REFERENCE__ elem)
        {
            if (-1 == this->_AddRange_ForEach_Start)
                this->_AddRange_ForEach_Start = this->Count();

            this->_ArrayList[0][this->_AddRange_ForEach_Start] = elem;

            ++(this->_AddRange_ForEach_Start);
        }
#pragma endregion
#pragma region Private Struct Defination Area
        __PRI__ const int32 ListDefaultSize = 8;
        __PRI__ const int32 ListDefaultGrow = 8;
        __PRI__ static int32 ListGrowth(T __DPOINTER__ source, int32 __VARIABLE__ currentSize)
        {
            return List<T>::ListGrowth(source, currentSize, 0);
        }
        __PRI__ static int32 ListGrowth(T __DPOINTER__ source, int32 __VARIABLE__ currentSize, int32 __VARIABLE__ minGrowth)
        {
            int32 newSize = List<T>::ListDefaultGrowth(currentSize);
            if (newSize < minGrowth)
                newSize = minGrowth + (minGrowth >> 1);

            T __POINTER__ newList = new T[newSize];
            for (int32 i = 0; i < currentSize; ++i)
                newList[i] = source[0][i];

            T __POINTER__ oldList = source[0];
            source[0] = newList;

            delete [] oldList;

            return newSize;
        }
        __PRI__ static int32 ListDefaultGrowth(int32 __VARIABLE__ currentSize)
#ifdef __DTY_DEEP_LEARNING_MODE__
        {

        }
        __PRI__ class ListSizeForecast final
        {
            __PRI__ const int32 __VARIABLE__ RecordSize = 64;
            __PRI__ int32 __VARIABLE__ _RecordGranularity[ListForecast::RecordSize];
            __PRI__ int32 __VARIABLE__ _Head;

            __PUB__ ListSizeForecast(int32 __VARIABLE__ initSize)
            {

            }
        };
#else
        {
            if (this->_MaxSize == this->_ArraySize)
                throw dty::collection::except::CollectionOverMaxSizeException();

            int32 growth = currentSize >> 2;
            growth = List<T>::ListDefaultGrow > growth ? List<T>::ListDefaultGrow : growth;

            return currentSize + growth >= this->_MaxSize ? this->_MaxSize : currentSize + growth;
        }
#endif // !__DTY_DEEP_LEARNING_MODE__
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