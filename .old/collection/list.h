/**
 * @file list.h(collection)
 * @author senyun.yao
 * @brief 
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_COLLECTION_LIST_H__
#define __DTY_NATIVE_COLLECTION_LIST_H__

#include"./collections.h"
#include"../smartPointer.h"

namespace dty::collection
{
    /**
     * @brief List部分需要提供如下的基本数据结构：
     *        1. list类
     *           List
     *           SortedList
     *           LinkedList
     *        2. Stack类
     *           Stack
     *           LinkedStack
     *        3. Queue类
     *           Queue
     *           LinkedQueue
     *        4. 其他
     */

    template<class T>
    class List
    {
        __PUB__ void __VARIABLE__ Clear();
        __PUB__ bool __VARIABLE__ IsFixedSize();
        __PUB__ bool __VARIABLE__ IsReadOnly();

        __PUB__ bool  __VARIABLE__ InsertAt(int32 __VARIABLE__ index, SmartPointer<T> __VARIABLE__ obj);
        __PUB__ bool  __VARIABLE__ RemoveAt(int32 __VARIABLE__ index);
        __PUB__ bool  __VARIABLE__ Add(SmartPointer<T> __VARIABLE__ elem);
        __PUB__ bool  __VARIABLE__ AddRange(Array<T> __REFERENCE__ range);
        __PUB__ bool  __VARIABLE__ Remove(T __REFERENCE__ elem);
        __PUB__ bool  __VARIABLE__ Contains(T __REFERENCE__ elem);
        __PUB__ int32 __VARIABLE__ IndexOf(T __REFERENCE__ elem);

        __PUB__ T __REFERENCE__ operator[](int32 __VARIABLE__ index);
    };

    template<class T>
    class SortedList
    {
        __PUB__ typedef int32 __VARIABLE__ (__POINTER__ fnSortedFunction)(T __REFERENCE__ objA, T __REFERENCE__ objB);

        __PUB__ void __VARIABLE__ Sort();
        __PUB__ void __VARIABLE__ Sort(fnSortedFunction __VARIABLE__ sortFunc)
    };

    template<class T>
    class LinkedList
    {

    };

    template<class T>
    class Stack : public IStack
    {
        __PUB__ void            __VARIABLE__ Clear();
        __PUB__ bool            __VARIABLE__ Contains(T __REFERENCE__ other);
        __PUB__ SmartPointer<T> __VARIABLE__ Pop();
        __PUB__ void            __VARIABLE__ Push(SmartPointer<T> __VARIABLE__ obj);
        __PUB__ SmartPointer<T> __VARIABLE__ Peek();
    };
    
    template<class T>
    class LinkedStack : public IStack
    {

    };

    template<class T>
    class Queue : public IQueue
    {
        __PUB__ void            __VARIABLE__ Clear();
        __PUB__ bool            __VARIABLE__ Contains(T __REFERENCE__ other);
        __PUB__ SmartPointer<T> __VARIABLE__ Dequeue();
        __PUB__ void            __VARIABLE__ Enqueue(SmartPointer<T> __VARIABLE__ obj);
        __PUB__ SmartPointer<T> __VARIABLE__ Peek();
    };
    
    template<class T>
    class LinkedQueue : public IQueue
    {

    };
}

#endif // !__DTY_NATIVE_COLLECTION_LIST_H__