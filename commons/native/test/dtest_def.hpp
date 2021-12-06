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

#define DTEST_GET_STRING(source) #source

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
        : public DTEST_TOPIC_BASE

#define DTEST_TOPIC_BEFORE_TEST() \
    __PUB__ virtual void __VARIABLE__ BeforeTest() override

#define DTEST_TOPIC_AFTER_TEST() \
    __PUB__ virtual void __VARIABLE__ AfterTest() override

// Get a unique spec name for new spec from specified topic and spec
// name
// Use "DTEST_" + topic_name + "_" + spec_name + "_TOPIC" to define
#define DTEST_SPEC_NAME(topic, spec) DTEST_##topic##_##spec##_SPEC

#define DTEST_SPEC_NAMESPACE_CONCAT(topic_namespace, topic_name) \
    topic_namespace::topic_name

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
    void   __VARIABLE__ DTEST_SPEC_NAME(topic_name, spec_name)::Run()

void Expect
(
    const ::dty::framework::dtest::core::TestInfo __POINTER__ test,
    bool val1,
    bool val2
);

#define EXPECT_EQ(val1, val2) \
    Expect(this->_Test, val1, val2)

#endif // !__DTY_FRAMEWORK_TIANYU_TEST_DTEST_DEF_H_PLUS_PLUS__