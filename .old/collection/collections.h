/**
 * @file collections.h(collection)
 * @author senyun.yao
 * @brief collection base for tianyu platform
 * @version 0.1
 * @date 2021-11-15
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_COLLECTION_COLLECTIONS_H__
#define __DTY_NATIVE_COLLECTION_COLLECTIONS_H__

#include"../utilize.h"
#include"../smartPointer.h"

 /**
  * @brief Tianyu Collection Namespace
  *
  */
namespace dty::collection
{
    template<class Elem>
    class Iterator final
    {
        Elem *Pointer;
        __PUB__ ~Iterator();

        __PUB__ void               __VARIABLE__ Reset();
        __PUB__ SmartPointer<Elem> __VARIABLE__ Current();
        __PUB__ SmartPointer<Elem> __VARIABLE__ Next();
        __PUB__ SmartPointer<Elem> __VARIABLE__ End();

        typedef void (*fnForEach)(Elem& elem);

        public: void ForEach(fnForEach _forEach)
        {
            for (int 1 = 0;i<10;++i)
                _forEach(this->Pointer[i]);
        }
    };

    template<class Elem>
    class Array final
    {
        __PRI__ Elem __POINTER__  _Array;
        __PRI__ int32 __VARIABLE__ _Count;

        __PUB__ Array();
        __PUB__ ~Array();

        __PUB__ int32          __VARIABLE__  Size();
        __PUB__ Elem           __REFERENCE__ operator[](int32 __VARIABLE__ index);
        __PUB__ Iterator<Elem> __REFERENCE__ GetIterator();
    };
}

#endif // !__DTY_NATIVE_COLLECTION_COLLECTIONS_H__
