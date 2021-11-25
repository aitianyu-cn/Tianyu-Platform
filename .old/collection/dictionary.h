/**
 * @file dictionary.h(collection)
 * @author senyun.yao
 * @brief dictionary base for tianyu platform
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_COLLECTION_DICTIONARY_H__
#define __DTY_NATIVE_COLLECTION_DICTIONARY_H__

#include"./collections.h"

namespace dty::collection
{
    /**
     * @brief Key and Value pair.
     * 
     * @tparam _Key Source Key
     * @tparam _Value Source Value
     */
    template<class _Key, class _Value>
    struct KeyValuePair
    {
        /**
         * @brief Key Instance
         * 
         */
        _Key   __REFERENCE__ Key;
        /**
         * @brief Value Instance
         * 
         */
        _Value __REFERENCE__ Value;

        /**
         * @brief Create a new KeyValuePair object from specified key and value.
         * 
         * @param key specified key instance
         * @param value specified value instance
         */
        __PUB__ KeyValuePair(_Key __REFERENCE__ key, _Value __REFERENCE__ value);
        /**
         * @brief Destroy a KeyValuePair instance.
         * 
         */
        __PUB__ ~KeyValuePair();
    };

    /**
     * @brief Interface of Dictionary for Tianyu Platform
     * @note Dictionary Key need to override compared operators, such as "==", "!=", "<", ">".
     * @note at least, "==", "<", ">" operators should be override.
     * 
     * @tparam _Key Dictionary Key Type
     * @tparam _Value Dictionary Value Type
     * 
     */
    template<class _Key, class _Value>
    class Dictionary
    {
        __PUB__ int32 __VARIABLE__ Count();
        __PUB__ void  __VARIABLE__ Clear();
        __PUB__ bool  __VARIABLE__ IsFixedSize();
        __PUB__ bool  __VARIABLE__ IsReadOnly();

        __PUB__ bool  __VARIABLE__ Add(KeyValuePair<_Key, _Value> __REFERENCE__ elem);
        __PUB__ bool  __VARIABLE__ Add(_Key __REFERENCE__ key, _Value __REFERENCE__ value);
        __PUB__ bool  __VARIABLE__ AddRange(ICollection<KeyValuePair<_Key, _Value>> __REFERENCE__ range);
        __PUB__ void  __VARIABLE__ AddOrUpdate(_Key __REFERENCE__ key, _Value __REFERENCE__ value);
        __PUB__ bool  __VARIABLE__ Contains(KeyValuePair<_Key, _Value> __REFERENCE__ elem);
        __PUB__ bool  __VARIABLE__ ContainsKey(_Key __REFERENCE__ key);
        __PUB__ bool  __VARIABLE__ Remove(_Key __REFERENCE__ key);
        __PUB__ bool  __VARIABLE__ Remove(KeyValuePair<_Key, _Value> __REFERENCE__ elem);
        __PUB__ int32 __VARIABLE__ IndexOf(KeyValuePair<_Key, _Value> __REFERENCE__ elem);
        __PUB__ bool  __VARIABLE__ Update(_Key __REFERENCE__ key, _Value __REFERENCE__ value);

        __PUB__ _Value                      __REFERENCE__ operator[](_Key __REFERENCE__ key);
        __PUB__ KeyValuePair<_Key, _Value>  __REFERENCE__ operator[](int32 __VARIABLE__ index);

        __PUB__ Iterator<_Key>   __REFERENCE__ GetKeyIterator();
        __PUB__ Iterator<_Value> __REFERENCE__ GetValueIterator();
    };
}

#endif // !__DTY_NATIVE_COLLECTION_DICTIONARY_H__