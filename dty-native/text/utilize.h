/**
 * @file utilize.h(text)
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_TEXT_UTILIZE_H__
#define __DTY_NATIVE_TEXT_UTILIZE_H__

#include"../utilize.hpp"
#include"../utils/pointer.hpp"
#include"../utils/string.hpp"

namespace dty::text
{
    enum class EncodingType
    {
        _UNKNOWN_,
        _ASCII_,
        _GBK_,
        _UNICODE_,
        _UTF8_
    };
}

#endif // !__DTY_NATIVE_TEXT_UTILIZE_H__