/**
 * @file object_dynamic.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-23
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_DYNAMIC_OBJECT_H__
#define __DTY_NATIVE_UTILS_DYNAMIC_OBJECT_H__

#include"./utilize.h"
#include"./string.h"

namespace dty
{
    class DynamicObject
    {
        template<typename T>
        T __VARIABLE__ GetValue(String __VARIABLE__ str);
        template<typename T>
        T __VARIABLE__ GetValue(const string __VARIABLE__ str);
    };
}

#endif // !__DTY_NATIVE_UTILS_DYNAMIC_OBJECT_H__