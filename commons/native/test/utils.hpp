/**
 * @file utils.hpp(tianyu-test)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-06
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_FRAMEWORK_TIANYU_TEST_UTILS_H_PLUS_PLUS__
#define __DTY_FRAMEWORK_TIANYU_TEST_UTILS_H_PLUS_PLUS__

#include "./utils/utilize.h"

#ifdef __cplusplus

#include "./utils/utilize.hpp"

namespace dty::framework::dtest::core
{
    // DTest checking type enum
    // Get the label for different checking ways
    // + EXPECT   : that is a non-interrupted checking
    // + ASSERT   : that is a stricted checking
    // + CUSTOMER : that is a customer checking can provide a custom 
    //              detection to indicate what is failure
    enum class DTestCheckType
    {
        EXPECT,
        ASSERT,
        CUSTOMER
    };

    // DTest Checking/Spec/Topic Result/State
    // Get the label for test states
    // + UnDetected : that indicates the test has not been run
    // + Success    : that indicates the test has passed
    // + Failed     : that indicates the test has failed entirely
    // + UnStable   : that indicates the test has some failures
    //                but has not blocked the whole test
    // + Aborted    : that indicates the test has been canceled
    //                by a critical error
    enum class DTestState
    {
        UnDetected = 0b00000001,
        Success = 0b00000010,
        Failed = 0b00000100,
        UnStable = 0b00001000,
        Aborted = 0b00010000
    };
}

#endif // !__cplusplus

#endif // !__DTY_FRAMEWORK_TIANYU_TEST_UTILS_H_PLUS_PLUS__