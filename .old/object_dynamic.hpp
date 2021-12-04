/**
 * @file object_dynamic.hpp(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-23
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_DYNAMIC_OBJECT_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_DYNAMIC_OBJECT_H_PLUS_PLUS__

#include"./utilize.hh"
#include"./pointer.hpp"
#include"./string.hpp"

namespace dty
{
    using Parameters = SmartPointer<void>;
    using Returns = SmartPointer<void>;

    typedef void    __VARIABLE__(__POINTER__ fnDynamicObjectFunction)(Parameters __VARIABLE__ params);
    typedef Returns __VARIABLE__(__POINTER__ fnDynamicObjectMethod)(Parameters __VARIABLE__ params);

    enum class IndexResultType
    {
        Property,
        Function,
        Method
    };

    class IndexResult
    {
        __PUB__ IndexResultType __VARIABLE__ ResultType;
        __PUB__ object          __VARIABLE__ Result;
    };

    class DynamicObject
    {
#pragma region Properties Interface
        __PUB__ void   __VARIABLE__ AddProp(String __VARIABLE__ name, object __VARIABLE__ prop);
        __PUB__ void   __VARIABLE__ RemoveProp(String __VARIABLE__ name);
        __PUB__ void   __VARIABLE__ UpdateProp(String __VARIABLE__ name, object __VARIABLE__ prop);
        __PUB__ object __VARIABLE__ GetProp(String __VARIABLE__ name);

        __PUB__ template<typename T>
            T __VARIABLE__ GetProp(String __VARIABLE__ str);
#pragma endregion

#pragma region Functions Interface
        __PUB__ void __VARIABLE__ AddMethod(String __VARIABLE__ name, fnDynamicObjectFunction __VARIABLE__ func);
        __PUB__ void __VARIABLE__ AddMethod(String __VARIABLE__ name, fnDynamicObjectMethod __VARIABLE__ method);
        __PUB__ void __VARIABLE__ UpdateMethod(String __VARIABLE__ name);
        __PUB__ void __VARIABLE__ RemoveMethod(String __VARIABLE__ name);

        __PUB__ void __VARIABLE__ CallFunction(String __VARIABLE__ name);
        __PUB__ void __VARIABLE__ CallFunction(String __VARIABLE__ name, Parameters __VARIABLE__ params);

        __PUB__ Returns __VARIABLE__ CallMethod(String __VARIABLE__ name);
        __PUB__ Returns __VARIABLE__ CallMethod(String __VARIABLE__ name, Parameters __VARIABLE__ params);
#pragma endregion

        __PUB__ IndexResult __VARIABLE__ operator[](String __VARIABLE__ name);
    };
}

#endif // !__DTY_NATIVE_UTILS_DYNAMIC_OBJECT_H_PLUS_PLUS__