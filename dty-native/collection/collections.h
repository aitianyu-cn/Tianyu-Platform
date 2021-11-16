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
    /**
     * @brief 用于ICompareable接口的比较返回值枚举
     * 
     */
    enum CompareResult
    {
        /**
         * @brief 小于（-1）
         * 
         */
        LESS = -1,
        /**
         * @brief 等于（0）
         * 
         */
        EQUAL = 0,
        /**
         * @brief 大于（1）
         * 
         */
        GREAT = 1
    };

    /**
     * @brief IEquatable接口用于提供判断对象是否相等的接口
     * 
     * @tparam 模板数据类型
     */
    template<class Elem>
    _interface IEquatable
    {
        /**
         * @brief 返回一个boolean表示当前实例于指定的对象是否相等
         * 
         * @param other 指定的对象
         * @return {bool} true当前实例与制定对象相等，false则不相等
         */
        __PUB__ virtual bool __VARIABLE__ Equals(Elem __REFERENCE__ other) = 0;
        /**
         * @brief 相等判断运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool} 返回true表示当前实例与指定对象相等，false则不相等 
         */
        __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
        /**
         * @brief 不相等运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool} 返回true表示当前实例与指定对象不相等，false则相等 
         */
        __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
    };

    /**
     * @brief ICompareable用于提供判断指定对象与当前对象大小关系判断的接口
     * 
     * @tparam Elem 模板数据类型
     */
    template<class Elem>
    _interface ICompareable
    {
        /**
         * @brief 判断当前实例与指定对象之间的大小关系
         * 
         * @param other 指定的对象
         * @return {CompareResult} 比较的结果
         */
        __PUB__ virtual CompareResult __VARIABLE__ CompareTo(Elem __REFERENCE__ other) = 0;/**
         * @brief 相等判断运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool} 返回true表示当前实例与指定对象相等，false则不相等 
         */
        __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
        /**
         * @brief 不相等运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool} 返回true表示当前实例与指定对象不相等，false则相等 
         */
        __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
        /**
         * @brief 小于运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool}
         */
        __PUB__ virtual bool __VARIABLE__ operator <(Elem __REFERENCE__ other) = 0;
        /**
         * @brief 大于运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool}
         */
        __PUB__ virtual bool __VARIABLE__ operator >(Elem __REFERENCE__ other) = 0;
        /**
         * @brief 小于等于运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool}
         */
        __PUB__ virtual bool __VARIABLE__ operator <=(Elem __REFERENCE__ other) = 0;
        /**
         * @brief 大于等于运算符重载
         * 
         * @param other 被比较的对象
         * @return {bool}
         */
        __PUB__ virtual bool __VARIABLE__ operator >=(Elem __REFERENCE__ other) = 0;
    };

    template<class Elem>
    abstract class Iterator
    {

        __PUB__ virtual void __VARIABLE__  Reset() = 0;
        __PUB__ virtual Elem __REFERENCE__ Current() = 0;
        __PUB__ virtual Elem __REFERENCE__ Next() = 0;
        __PUB__ virtual Elem __VARIABLE__  End() = 0;
    };

    template<class Elem>
    _interface IEnumerable
    {
        __PUB__ typedef void __VARIABLE__ (__POINTER__ fnForEach)(Elem __REFERENCE__ elem);
        __PUB__ typedef bool __VARIABLE__ (__POINTER__ fnMapping)(Elem __REFERENCE__ elem);

        __PUB__ virtual Iterator<Elem> __REFERENCE__ GetIterator() = 0;

        __PUB__ virtual void  __VARIABLE__ ForEach(fnForEach __VARIABLE__ foreachFunc) = 0;
        __PUB__ virtual Elem  __POINTER__  Map(int32 __REFERENCE__ resultLength, fnMapping __VARIABLE__ foreachFunc) = 0;
        __PUB__ virtual Elem  __POINTER__  Filter(int32 __REFERENCE__ resultLength, fnMapping __VARIABLE__ foreachFunc) = 0;
        __PUB__ virtual Elem  __VARIABLE__ Find(fnMapping __VARIABLE__ foreachFunc) = 0;
        __PUB__ virtual int32 __VARIABLE__ FindIndex(fnMapping __VARIABLE__ foreachFunc) = 0;
        __PUB__ virtual void  __VARIABLE__ Every(fnMapping __VARIABLE__ foreachFunc) = 0;
    };

    __PREDEFINE__ template<class Elem> _interface ICollection;

    template<class Elem>
    class Array final : public IEnumerable<Elem>
    {
        __PRI__ Elem  __POINTER__  _Array;
        __PRI__ int32 __VARIABLE__ _Count;

        __PUB__ Array();
        __PUB__ ~Array();

        __PUB__ int32 __VARIABLE__  Size();
        __PUB__ Elem  __REFERENCE__ operator[](int32 __VARIABLE__ index);

        __PUB__ virtual Iterator<Elem> __REFERENCE__ GetIterator() override;

        __PUB__ friend class ICollection<Elem>;
    };

    template<class Elem>
    _interface ICollection : public virtual IEnumerable<Elem>
    {
        __PUB__ virtual int32       __VARIABLE__  Count() = 0;
        __PUB__ virtual bool        __VARIABLE__  IsEmpty() = 0;
        __PUB__ virtual Array<Elem> __REFERENCE__ ToArray() = 0;

        __PUB__ virtual void  __VARIABLE__  Clear() = 0;
        __PUB__ virtual bool  __VARIABLE__  Add(Elem __REFERENCE__ elem) = 0;
        __PUB__ virtual bool  __VARIABLE__  AddRange(ICollection<Elem> __REFERENCE__ range) = 0;
        __PUB__ virtual bool  __VARIABLE__  Remove(Elem __REFERENCE__ elem) = 0;
        __PUB__ virtual bool  __VARIABLE__  Contains(Elem __REFERENCE__ elem) = 0;
        __PUB__ virtual int32 __VARIABLE__  IndexOf(Elem __REFERENCE__ elem) = 0;

        __PUB__ virtual Elem  __REFERENCE__ operator[](int32 __VARIABLE__ index) = 0;
    };
}

#endif // !__DTY_NATIVE_COLLECTION_COLLECTIONS_H__