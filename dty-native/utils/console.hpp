/**
 * @file console.hpp(utils)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.console?view=net-6.0
 */

#ifndef __DTY_NATIVE_UTILS_CONSOLE_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_CONSOLE_H_PLUS_PLUS__

#include "../utilize.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    // Console for Pure C Mode

typedef struct dty_native_c_console
{

}CConsole;

__DEFAULT__ const CConsole __VARIABLE__ TianyuConsole;

#ifdef __cplusplus
}
#endif // !__cplusplus

#ifdef __cplusplus

#include "../utilize.hpp"

namespace dty
{
    static class Console final
    {

    };
}

#endif // !__cplusplus

#endif // !__DTY_NATIVE_UTILS_CONSOLE_H_PLUS_PLUS__