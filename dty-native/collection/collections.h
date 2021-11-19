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

 /**
  * @brief Tianyu Collection Namespace
  *
  */
namespace dty::collection
{
    enum CompareResult
    {
        LESS = -1,
        EQUAL = 0,
        GREAT = 1
    };

    template<class Elem>
    _interface IEquatable
    {
        __PUB__ virtual ~IEquatable() = 0;

        __PUB__ virtual bool __VARIABLE__ Equals(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
    };

    template<class Elem>
    _interface ICompareable
    {
        __PUB__ virtual ~ICompareable() = 0;

        __PUB__ virtual CompareResult __VARIABLE__ CompareTo(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator <(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator >(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator <=(Elem __REFERENCE__ other) = 0;
        __PUB__ virtual bool __VARIABLE__ operator >=(Elem __REFERENCE__ other) = 0;
    };

    template<class Elem>
    class Iterator final
    {
        __PUB__ ~Iterator();

        __PUB__ void               __VARIABLE__ Reset();
        __PUB__ SmartPointer<Elem> __VARIABLE__ Current();
        __PUB__ SmartPointer<Elem> __VARIABLE__ Next();
        __PUB__ SmartPointer<Elem> __VARIABLE__ End();
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