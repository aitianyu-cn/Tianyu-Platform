/**
 * @file utils.hpp(tianyu-make)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-06
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_FRAMEWORK_TIANYU_MAKE_UTILS_H_PLUS_PLUS__
#define __DTY_FRAMEWORK_TIANYU_MAKE_UTILS_H_PLUS_PLUS__

#include"commons/native/core/utilize.hpp"

namespace dty::framework::dmake
{
    enum class DMakeLogState : int32
    {
        MESSAGE,
        INFOMATION,
        WARNING,
        ERROR,
        CRITICAL
    };
}

#endif // !__DTY_FRAMEWORK_TIANYU_MAKE_UTILS_H_PLUS_PLUS__