/**
 * @file utilize.hh(utils/collection)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-04
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY__NATIVE_UTILS_COLLECTION_UTILIZE_H_H__
#define __DTY__NATIVE_UTILS_COLLECTION_UTILIZE_H_H__

#include"../../utilize.h"
#include"../../utilize.hh"

namespace dty::collection
{
    template<class T>
    _interface ICollection
    {

    };

    template<class T>
    _interface IList : public virtual ICollection<T>
    {

    };

    template<class T>
    _interface ISet : public virtual ICollection<T>
    {

    };

    template<class _K, class _V>
    _interface IDictionary : public virtual ICollection<KeyValuePair<_K, _V>>
    {

    };
}

#endif // !__DTY__NATIVE_UTILS_COLLECTION_UTILIZE_H_H__