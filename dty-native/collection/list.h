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
    template<class Elem>
    _interface IList : public virtual ICollection<Elem>
    {
        __PUB__ virtual ~IList() = 0;

        __PUB__ virtual bool __VARIABLE__ IsFixedSize() = 0;
        __PUB__ virtual bool __VARIABLE__ IsReadOnly() = 0;

        __PUB__ virtual bool  __VARIABLE__  InsertAt(int32 __VARIABLE__ index, Elem __REFERENCE__ obj) = 0;
        __PUB__ virtual bool  __VARIABLE__  RemoveAt(int32 __VARIABLE__ index) = 0;
        __PUB__ virtual bool  __VARIABLE__  Add(Elem __REFERENCE__ elem) = 0;
        __PUB__ virtual bool  __VARIABLE__  AddRange(ICollection<Elem> __REFERENCE__ range) = 0;
        __PUB__ virtual void  __VARIABLE__  Clear() = 0;
        __PUB__ virtual bool  __VARIABLE__  Remove(Elem __REFERENCE__ elem) = 0;
        __PUB__ virtual bool  __VARIABLE__  Contains(Elem __REFERENCE__ elem) = 0;
        __PUB__ virtual int32 __VARIABLE__  IndexOf(Elem __REFERENCE__ elem) = 0;

        __PUB__ virtual Elem  __REFERENCE__ operator[](int32 __VARIABLE__ index) = 0;
    };

    template<class Elem>
    _interface ISortedList : public virtual IList<Elem>
    {
        __PUB__ typedef int32 __VARIABLE__ (__POINTER__ fnSortedFunction)(Elem __REFERENCE__ objA, Elem __REFERENCE__ objB);

        __PUB__ virtual ~ISortedList() = 0;

        __PUB__ virtual void __VARIABLE__ Sort() = 0;
        __PUB__ virtual void __VARIABLE__ Sort(fnSortedFunction __VARIABLE__ sortFunc) = 0;
    };

    template<class Elem>
    _interface IQueue : public virtual ICollection<Elem>
    {
        __PUB__ virtual ~IQueue() = 0;

        __PUB__ virtual void               __VARIABLE__ Clear() = 0;
        __PUB__ virtual bool               __VARIABLE__ Contains(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ Dequeue() = 0;
        __PUB__ virtual void               __VARIABLE__ Enqueue(SmartPointer<Elem> __REFERENCE__ obj) = 0;
        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ Peek() = 0;
    };

    template<class Elem>
    _interface IStack : public virtual ICollection<Elem>
    {
        __PUB__ virtual ~IStack() = 0;

        __PUB__ virtual void               __VARIABLE__ Clear() = 0;
        __PUB__ virtual bool               __VARIABLE__ Contains(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ Pop() = 0;
        __PUB__ virtual void               __VARIABLE__ Push(SmartPointer<Elem> __REFERENCE__ obj) = 0;
        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ Peek() = 0;
    };

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
    class List : public virtual IList<T>
    {

    };

    template<class T>
    class SortedList : public virtual ISortedList<T>
    {

    };

    template<class T>
    class LinkedList : public virtual IList<T>
    {

    };

    template<class T>
    class Stack : public virtual IStack
    {

    };
    
    template<class T>
    class LinkedStack : public virtual IStack
    {

    };

    template<class T>
    class Queue : public virtual IQueue
    {

    };
    
    template<class T>
    class LinkedQueue : public virtual IQueue
    {

    };
}

#endif // !__DTY_NATIVE_COLLECTION_LIST_H__