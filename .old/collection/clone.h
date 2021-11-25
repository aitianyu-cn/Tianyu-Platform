/**
 * @file clone.h(collection)
 * @author senyun.yao
 * @brief 
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_COLLECTION_CLONE_H__
#define __DTY_NATIVE_COLLECTION_CLONE_H__

#include"../utilize.h"
#include"../smartPointer.h"

namespace dty::collection
{
    template<class Elem>
    _interface ICloneable
    {
        __PUB__ virtual ~ICloneable() = 0;

        __PUB__ virtual SmartPointer<Elem> __VARIABLE__ Clone() = 0;
    };
}

#endif // !__DTY_NATIVE_COLLECTION_CLONE_H__