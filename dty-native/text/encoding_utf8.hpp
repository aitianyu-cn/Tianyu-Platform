/**
 * @file encoding_utf8.hpp(text)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-03
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_TEXT_ENCODING_UTF_EIGHT_H_PLUS_PLUS__
#define __DTY_NATIVE_TEXT_ENCODING_UTF_EIGHT_H_PLUS_PLUS__

#include"./encoding.hpp"

namespace dty::text
{
    class UTF8Encoding final : public Encoding
    {
        __PUB__ UTF8Encoding();
        __PUB__ virtual ~UTF8Encoding() override;

#pragma region  Encoding Base Functions
        __PUB__ virtual string __VARIABLE__ GetName() const override;

        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(byte_ptr __VARIABLE__ bytes) override;
        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(byte_ptr __VARIABLE__ bytes, EncodingType __VARIABLE__ codeType) override;
        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(String __VARIABLE__ str) override;
        __PUB__ virtual byte_ptr __VARIABLE__ GetBytes(String __VARIABLE__ str, EncodingType __VARIABLE__ codeType) override;

        __PUB__ virtual String __VARIABLE__ GetString(byte_ptr __VARIABLE__ bytes) override;
        __PUB__ virtual String __VARIABLE__ GetString(String __VARIABLE__ str) override;
#pragma endregion
    };
}


#endif // !__DTY_NATIVE_TEXT_ENCODING_UTF_EIGHT_H_PLUS_PLUS__