/**
 * @file utilize.h(exception)
 * @author senyun.yao
 * @brief 
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_EXCEPTION_UTILIZE_H__
#define __DTY_NATIVE_EXCEPTION_UTILIZE_H__

#include"../utilize.h"

namespace dty::except
{
#pragma region Exception ID Macros

constexpr uint64 __VARIABLE__ DTY_Generic_Exception = 0x0000000000000001ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_NullPointerException = 0x0000000000000002ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_ArithmeticException = 0x0000000000000003ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_IndexOutOfRangeException = 0x0000000000000004ULL;

constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentException = 0x1000000000000001ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentNullException = 0x1000000000000002ULL;
constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentOutOfRangeException = 0x1000000000000003ULL;
#pragma endregion
}

#endif // !__DTY_NATIVE_EXCEPTION_UTILIZE_H__