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
    _interface IDictionary 
        : public virtual ICollection<KeyValuePair<_Key, _Value>>
    {
        /**
         * @brief Add a new record to Dictionary instance from specified key and value.
         * 
         * @param key added key
         * @param value added value
         * @return {bool}return true if the key is added successful, and false not.
         */
        __PUB__ virtual bool __VARIABLE__ Add(_Key __REFERENCE__ key, _Value __REFERENCE__ value) = 0;
        /**
         * @brief Remove a specified key from the dictionary instance.
         * 
         * @param key the key does need to be removed
         * @return {bool}return true if the key is removed and false not.
         */
        __PUB__ virtual bool __VARIABLE__ Remove(_Key __REFERENCE__ key) = 0;
        /**
         * @brief Update a existed key to set a new value.
         * 
         * @param key the key does need to be added
         * @param value the new value of the key
         * @return {bool} return true if the key is existed and update successful and false not.
         */
        __PUB__ virtual bool __VARIABLE__ Update(_Key __REFERENCE__ key, _Value __REFERENCE__ value) = 0;
        /**
         * @brief Add a value of the key, if the key is existed, then update the value.
         * 
         * @param key the key does need to be added or updated
         * @param value new value
         */
        __PUB__ virtual void __VARIABLE__ AddOrUpdate(_Key __REFERENCE__ key, _Value __REFERENCE__ value) = 0;
        /**
         * @brief Check the specified key whether is exist.
         * 
         * @param key checked key
         * @return {bool} return true if the key is found and false is not found.
         */
        __PUB__ virtual bool   __VARIABLE__  ContainsKey(_Key __REFERENCE__ key) = 0;

        /**
         * @brief Operator overried to use an indexer to get a value of the key.
         * 
         * @param key the key does needs to be find
         * @return {_Value} return a value reference of the found key, the return is unstabled for the key is not found.
         */
        __PUB__ virtual _Value __REFERENCE__ operator[](_Key __REFERENCE__ key) = 0;

        /**
         * @brief Get the Key Iterator object
         * 
         * @return {Iterator} return a iterator reference of the keys
         */
        __PUB__ virtual Iterator<_Key>   __REFERENCE__ GetKeyIterator() = 0;
        /**
         * @brief Get the Value Iterator object
         * 
         * @return {Iterator} return a iterator reference of the values 
         */
        __PUB__ virtual Iterator<_Value> __REFERENCE__ GetValueIterator() = 0;
    };
}

#endif // !__DTY_NATIVE_COLLECTION_DICTIONARY_H__