/**
 * @file encoding.hpp(text)
 * @author senyun.yao
 * @brief 用于天宇库/平台的字符串类型转换基类
 * @brief Abstract class: String encode converter base class for Tianyu library and platform
 * @version 0.1
 * @date 2021-12-03
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_TEXT_ENCODING_H_PLUS_PLUS__
#define __DTY_NATIVE_TEXT_ENCODING_H_PLUS_PLUS__

#include"./utilize.hh"

namespace dty::text
{
    abstract class Encoding
    {
        __PUB__ Encoding();
        __PUB__ virtual ~Encoding();

        __PUB__ virtual string __VARIABLE__ GetName() const = 0;

        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(byte_ptr __VARIABLE__ bytes) = 0;
        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(byte_ptr __VARIABLE__ bytes, EncodingType __VARIABLE__ codeType) = 0;
        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(String __VARIABLE__ str) = 0;
        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(String __VARIABLE__ str, EncodingType __VARIABLE__ codeType) = 0;

        __PUB__ virtual String __VARIABLE__ GetString(byte_ptr __VARIABLE__ bytes) = 0;
        __PUB__ virtual String __VARIABLE__ GetString(String __VARIABLE__ str) = 0;

#pragma region Static Properties and Methods
        __PUB__ static String __VARIABLE__ Convert(byte_ptr __VARIABLE__ bytes, EncodingType __VARIABLE__ sType, EncodingType __VARIABLE__ tType);
        __PUB__ static String __VARIABLE__ Convert(String __VARIABLE__ str, EncodingType __VARIABLE__ sType, EncodingType __VARIABLE__ tType);

        __PUB__ static Encoding __REFERENCE__ ASCII;
        __PUB__ static Encoding __REFERENCE__ GBK;
        __PUB__ static Encoding __REFERENCE__ Unicode;
        __PUB__ static Encoding __REFERENCE__ UTF8;
#pragma endregion
    };
}

#endif // !__DTY_NATIVE_TEXT_ENCODING_H_PLUS_PLUS__