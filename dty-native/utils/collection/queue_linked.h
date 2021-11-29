/**
 * @file queue_linked.h(utils/collection)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_COLLECTION_LINKEDQUEUE_H__
#define __DTY_NATIVE_UTILS_COLLECTION_LINKEDQUEUE_H__

#include"../utilize.h"
#include"./error.h"
#include"../array.h"

namespace dty::collection
{
    template<class T>
    class LinkedQueueNode final
    {
        __PUB__ T                  __VARIABLE__ _Elem;
        __PUB__ LinkedQueueNode<T> __POINTER__  _Next;
    };

    template<class T>
    class LinkedQueue final
    {
        __PRI__ LinkedQueueNode<T> __DPOINTER__ _Queue;

        __PRI__ int32        __POINTER__  _Count;
        __PRI__ int32        __VARIABLE__ _MaxSize;
        __PRI__ int32        __POINTER__  _Reference;

        __PUB__ LinkedQueue()
            : _Queue(new (LinkedQueueNode<T> __POINTER__)[2]), _Count(new int32(0)),
            _MaxSize(-1), _Reference(new int32(1))
        {
            LinkedQueueNode<T> __POINTER__ queueHeader = new LinkedQueueNode<T>();
            queueHeader->_Next = null;

            this->_Queue[0] = queueHeader;
            this->_Queue[1] = queueHeader;
        }
        __PUB__ LinkedQueue(int32 __VARIABLE__ maxSize)
            : _Queue(new (LinkedQueueNode<T> __POINTER__)[2]), _Count(new int32(0)),
            _MaxSize(0 >= maxSize ? -1 : maxSize), _Reference(new int32(1))
        {
            LinkedQueueNode<T> __POINTER__ queueHeader = new LinkedQueueNode<T>();
            queueHeader->_Next = null;

            this->_Queue[0] = queueHeader;
            this->_Queue[1] = queueHeader;
        }
        __PUB__ LinkedQueue(Array<T> __VARIABLE__ range)
            : _Queue(new (LinkedQueueNode<T> __POINTER__)[2]), _Count(new int32(0)),
            _MaxSize(-1), _Reference(new int32(1))
        {
            LinkedQueueNode<T> __POINTER__ queueHeader = new LinkedQueueNode<T>();
            queueHeader->_Next = null;

            this->_Queue[0] = queueHeader;
            this->_Queue[1] = queueHeader;

            Iterator<T> iter = range.GetIterator();
            iter.ForEach(this->Enqueue);
        }
        __PUB__ LinkedQueue(const LinkedQueue<T> __REFERENCE__ queue)
            : _Queue(new (LinkedQueueNode<T> __POINTER__)[2]), _Count(queue._Count),
            _MaxSize(queue._MaxSize), _Reference(queue._Reference)
        {
            this->_Queue[0] = queue._Queue[0];
            this->_Queue[1] = queue._Queue[1];

            ++(__PTR_TO_VAR__(this->_Reference));
        }

        __PUB__ ~LinkedQueue()
        {
            if (1 == (__PTR_TO_VAR__(this->_Reference)))
            {
                this->Clear();
                delete (this->_Count);
                delete (this->_Reference);
            }
            else
                --(__PTR_TO_VAR__(this->_Reference));

            delete [](this->_Queue);
        }

        __PUB__ void  __VARIABLE__ Clear()
        {
            if (0 == this->Count())
                return;

            LinkedQueueNode<T> __POINTER__ newHead = this->_Queue[0];
            while (null != newHead->_Next)
            {
                LinkedQueueNode<T> __POINTER__ del = newHead->_Next;
                newHead->_Next = del->_Next;

                delete del;
            }

            this->_Queue[1] = this->_Queue[0];
            (__PTR_TO_VAR__(this->Count)) = 0;
        }
        __PUB__ bool  __VARIABLE__ IsEmpty()
        {
            return 0 == this->Count();
        }
        __PUB__ int32 __VARIABLE__ Count()
        {
            return __PTR_TO_VAR__(this->_Count);
        }

        __PUB__ void __VARIABLE__  Enqueue(T __REFERENCE__ elem)
        {
            if (this->Count() >= this->_MaxSize)
                throw dty::collection::except::CollectionOverMaxSizeException();

            LinkedQueueNode<T> __POINTER__ newNode = new LinkedQueueNode<T>();
            newNode->_Elem = elem;
            newNode->_Next = null;

            this->UpdateEnd();

            LinkedQueueNode<T> __POINTER__ end = this->_Queue[1];
            end->_Next = newNode;
            this->_Queue[1] = newNode;
            ++(__PTR_TO_VAR__(this->_Count));
        }
        __PUB__ T    __VARIABLE__  Dequeue()
        {
            if (0 == this->Count())
                throw dty::except::IndexOutOfRangeException();

            LinkedQueueNode<T> __POINTER__ head = this->_Queue[0];
            LinkedQueueNode<T> __POINTER__ first = head->_Next;

            head->_Next = first->_Next;
            --(__PTR_TO_VAR__(this->_Count));

            T result = first->_Elem;
            delete first;

            return result;
        }
        __PUB__ T    __REFERENCE__ Peek()
        {
            if (0 == this->Count())
                throw dty::except::IndexOutOfRangeException();

            LinkedQueueNode<T> __POINTER__ head = this->_Queue[0];
            return head->_Next->_Elem;
        }

        __PUB__ Array<T> __VARIABLE__ ToArray()
        {
            if (0 == this->Count())
                return Array<T>(null, 0);

            T __POINTER__ array = new T[this->Count()];
            LinkedQueueNode<T> __POINTER__ head = this->_Queue[0];
            int32 actualSize = 0;

            for (
                LinkedQueueNode<T> __POINTER__ elem = head->_Next;
                actualSize < this->Count() && null != elem;
                ++actualSize, elem = elem->_Next
                )
                array[actualSize] = elem->_Elem;

            return Array<T>(array, actualSize);
        }

        __PRI__ void __VARIABLE__  UpdateEnd()
        {
            if (0 == this->Count())
                return;

            LinkedQueueNode<T> __POINTER__ end = this->_Queue[1];
            if (null == end->_Next)
                return;

            while (null != end->_Next)
                end = end->_Next;

            this->_Queue[1] = end;
        }
    };
}

#endif // !__DTY_NATIVE_UTILS_COLLECTION_LINKEDQUEUE_H__