/**
 * @file macAPI.h(utils/cpf)
 * @author senyun.yao
 * @brief 
 * @version 0.1
 * @date 2021-11-11
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_CPF_MACAPI_H__
#define __DTY_NATIVE_CPF_MACAPI_H__

#if __DTY_AIS == 1
#include"./apple/iosm.h"
#elif __DTY_AIP == 1
#include"./apple/ios.h"
#elif __DTY_AMC == 1
#include"./apple/macos.h"
#endif

#endif // !__DTY_NATIVE_CPF_MACAPI_H__