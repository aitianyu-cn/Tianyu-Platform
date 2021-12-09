/**
 * @file dtest.hpp(tianyu-test)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-06
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_FRAMEWORK_TIANYU_TEST_DTEST_DEF_H_PLUS_PLUS__
#define __DTY_FRAMEWORK_TIANYU_TEST_DTEST_DEF_H_PLUS_PLUS__

#include"./internal/dtest_internal.hpp"
#include"./dtest_excpt.hpp"

 // Define the basic Topic class
 // the topic class(abstract class) must to be used for all topics
 // the macro defination that is used to make code clearly without
 // a big length string
#define DTEST_TOPIC_BASE ::dty::framework::dtest::core::Topic

// Get a unique topic name for new topic type
// Use "DTEST_" + topic_name + "_TOPIC" to define
#define DTEST_TOPIC_NAME(topic_name) DTEST_##topic_name##_TOPIC

// Get a topic type sign that uses default topic name and externed
// from base topic class
// pay attention to the topic should be a abstract class and should
// not to realize the abstract function. (even though there is not
// any error will be caused if the abstract function is realized)
#define DTEST_TOPIC(topic_name)            \
        class DTEST_TOPIC_NAME(topic_name) \
        : public DTEST_TOPIC_BASE          \

// Define the override replacement
// Used for topic to realize the BeforeTest function
// to get a unified defination for all topic
#define DTEST_TOPIC_BEFORE_TEST()                           \
    __PUB__ virtual void __VARIABLE__ BeforeTest() override \

// Define the override replacement
// Used for topic to realize the AfterTest function
// to get a unified defination for all topic
#define DTEST_TOPIC_AFTER_TEST()                            \
    __PUB__ virtual void __VARIABLE__ AfterTest() override  \

// Get a unique spec name for new spec from specified topic and spec
// name
// Use "DTEST_" + topic_name + "_" + spec_name + "_TOPIC" to define
#define DTEST_SPEC_NAME(topic, spec) DTEST_##topic##_##spec##_SPEC

#define DTEST_SPEC_NAMESPACE_CONCAT(topic_namespace, topic_name) \
    topic_namespace::topic_name                                  \

// Get a spec type that uses specified topic
// To get a whole defination and only post a function implementation
// to user that is end of the define as a function
#define DTEST_SPEC_NAMESPACE(topic_namespace, topic_name, spec_name, description)       \
    class DTEST_SPEC_NAME(topic_name, spec_name)                                        \
        : public DTEST_SPEC_NAMESPACE_CONCAT(topic_namespace, topic_name)               \
    {                                                                                   \
        __PUB__          DTEST_SPEC_NAME(topic_name, spec_name)() = default;            \
        __PUB__ virtual ~DTEST_SPEC_NAME(topic_name, spec_name)() = default;            \
                                                                                        \
        DTEST_DISALLOW_COPY_AND_ASSIGN(DTEST_SPEC_NAME(topic_name, spec_name));         \
                                                                                        \
        __PUB__ virtual string __VARIABLE__ Description() const override;               \
        __PUB__ virtual void   __VARIABLE__ Run() override;                             \
                                                                                        \
        __PRI__ static ::dty::framework::dtest::core::TestInfo __POINTER__ const _Test; \
    };                                                                                  \
    ::dty::framework::dtest::core::TestInfo __POINTER__ const                           \
                DTEST_SPEC_NAME(topic_name, spec_name)::_Test =                         \
    ::dty::framework::dtest::internal::RegisterTestSpec                                 \
    (                                                                                   \
    #topic_namespace, #topic_name, #spec_name, #description,                            \
    ::dty::framework::dtest::core::CodeLocation::GetCodeLocation(__FILE__, __LINE__),   \
    ::dty::framework::dtest::internal::SpecApiHandler<                                  \
        DTEST_SPEC_NAMESPACE_CONCAT(topic_namespace, topic_name)>::GetTopicBeforeAll(), \
    ::dty::framework::dtest::internal::SpecApiHandler<                                  \
        DTEST_SPEC_NAMESPACE_CONCAT(topic_namespace, topic_name)>::GetTopicAfterAll(),  \
    new DTEST_SPEC_NAME(topic_name, spec_name)()                                        \
    );                                                                                  \
    string __VARIABLE__ DTEST_SPEC_NAME(topic_name, spec_name)::Description() const     \
    {                                                                                   \
            return #description;                                                        \
    }                                                                                   \
    void   __VARIABLE__ DTEST_SPEC_NAME(topic_name, spec_name)::Run()                   \

// ========================================================================================
// Expects define area
// ========================================================================================

// DTest Expect compare template macro-define
// this compare function is used to compare two values by the indicated
// way
// type: EQ, NE, GT, LT
// val : automated type derivation 
#define DTEST_EXCEPT_CMP_TEMPLATE(type, val1, val2)             \
    ::dty::framework::dtest::core::DTEST_CHECKER_GETANEM(type)  \
    ::Checker                                                   \
    (                                                           \
        this->_Test,                                            \
        __LINE__,                                               \
        ::dty::framework::dtest::core::DTestCheckType::EXPECT,  \
        val1,                                                   \
        val2                                                    \
    )                                                           \

// *******
// EXPECTs
// *******

// Expect
// Compare two value whether are equal or not.
// if failed, only has influence to current check.
#define EXPECT_EQ(val1, val2)                  \
    DTEST_EXCEPT_CMP_TEMPLATE(EQ, val1, val2)  \

// Expect
// Compare two value whether are not equal.
// if failed, only has influence to current check.
#define EXPECT_NE(val1, val2)                  \
    DTEST_EXCEPT_CMP_TEMPLATE(NE, val1, val2)  \

// Expect
// Compare two value whether the first one is great
// than another one.
// if failed, only has influence to current check.
#define EXPECT_GT(val1, val2)                  \
    DTEST_EXCEPT_CMP_TEMPLATE(GT, val1, val2)  \

// Expect
// Compare two value whether the first one is less
// than another one.
// if failed, only has influence to current check.
#define EXPECT_LT(val1, val2)                  \
    DTEST_EXCEPT_CMP_TEMPLATE(LT, val1, val2)  \

// Expect
// Check the value is null or not.
// if failed, only has influence to current check.
#define EXPECT_IS_NULL(val)                    \
    DTEST_EXCEPT_CMP_TEMPLATE(EQ, val, null)   \

// Expect
// Check the value whether is not null.
// if failed, only has influence to current check.
#define EXPECT_NOT_NULL(val)                   \
    DTEST_EXCEPT_CMP_TEMPLATE(NE, val, null)   \

// Expect
// Check the value is true or not.
// if failed, only has influence to current check.
#define EXPECT_TRUE(val)                       \
    DTEST_EXCEPT_CMP_TEMPLATE(EQ, val, true)   \

// Expect
// Check the value whether is false.
// if failed, only has influence to current check.
#define EXPECT_FALSE(val)                      \
    DTEST_EXCEPT_CMP_TEMPLATE(EQ, val, false)  \

// Expect
// Check the value whether equals to integer(1).
// if failed, only has influence to current check.
#define EXPECT_1(val)                      \
    DTEST_EXCEPT_CMP_TEMPLATE(EQ, val, 1)  \

// Expect
// Check the value whether equals to integer(0).
// if failed, only has influence to current check.
#define EXPECT_0(val)                      \
    DTEST_EXCEPT_CMP_TEMPLATE(EQ, val, 0)  \


#define EXPECT_FLOAT_EQ(val1, val2)
#define EXPECT_FLOAT_GT(val1, val2)
#define EXPECT_FLOAT_LT(val1, val2)
#define EXPECT_FLOAT_1(val1, val2)
#define EXPECT_FLOAT_0(val1, val2)

#define EXPECT_STR_EQ(str1, str2)
#define EXPECT_STR_NE(str1, str2)
#define EXPECT_STR_GT(str1, str2)
#define EXPECT_STR_LT(str1, str2)
#define EXPECT_STR_IS_EMPTY(str)
#define EXPECT_STR_NOT_EMPTY(str)

// *******
// ASSERTs
// *******

#define ASSERT_EQ(val1, val2)
#define ASSERT_NE(val1, val2)
#define ASSERT_GT(val1, val2)
#define ASSERT_LT(val1, val2)
#define ASSERT_IS_NULL(val)
#define ASSERT_NOT_NULL(val)
#define ASSERT_TRUE(val)
#define ASSERT_FALSE(val)
#define ASSERT_1(val)
#define ASSERT_0(val)

#define ASSERT_FLOAT_EQ(val1, val2)
#define ASSERT_FLOAT_GT(val1, val2)
#define ASSERT_FLOAT_LT(val1, val2)
#define ASSERT_FLOAT_1(val1, val2)
#define ASSERT_FLOAT_0(val1, val2)

#define ASSERT_STR_EQ(str1, str2)
#define ASSERT_STR_NE(str1, str2)
#define ASSERT_STR_GT(str1, str2)
#define ASSERT_STR_LT(str1, str2)
#define ASSERT_STR_IS_EMPTY(str)
#define ASSERT_STR_NOT_EMPTY(str)

#endif // !__DTY_FRAMEWORK_TIANYU_TEST_DTEST_DEF_H_PLUS_PLUS__