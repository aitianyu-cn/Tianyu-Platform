/**
 * @file string_builder.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-23
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_STRING_BUILDER_H__
#define __DTY_NATIVE_UTILS_STRING_BUILDER_H__

#include"./string.h"

namespace dty
{
    class StringBuilder final
    {
        __PUB__ StringBuilder();
        __PUB__ ~StringBuilder();

        __PUB__ SmartPointer<String> __VARIABLE__ ToString();
    };
}

#endif // !__DTY_NATIVE_UTILS_STRING_BUILDER_H__