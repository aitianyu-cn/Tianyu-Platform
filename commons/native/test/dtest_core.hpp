/**
 * @file dtest_core.hpp(tianyu-test)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-06
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_FRAMEWORK_TIANYU_TEST_DTEST_CORE_H_PLUS_PLUS__
#define __DTY_FRAMEWORK_TIANYU_TEST_DTEST_CORE_H_PLUS_PLUS__

#include"./utils.hpp"

 // DTEST_SPEC:     用于定义一个Unit Test，包含topic和Unit Test Name
 // DTEST_RUN_SPEC: 用于运行指定的Unit Test，需要提供topic和Unit Test Name
 // DTEST_RUN_ALL:  用于运行所有定义的Unit Test
 // DTEST_RUN_UNIT: 用于运行指定的一组Unit Test，需要提供topic

 // 需要先定义一个topic，然后基于这个topic定义


#define DTEST_DISALLOW_COPY(type)   \
        __PUB__ type(const type __REFERENCE__ other) = delete

#define DTEST_DISALLOW_ASSIGN(type) \
        __PUB__ type __REFERENCE__ operator=(const type __REFERENCE__ other) = delete

#define DTEST_DISALLOW_MOVE(type)   \
        __PUB__ type(const type __REFERENCE__ __REFERENCE__ other) = delete

#define DTEST_DISALLOW_COPY_AND_ASSIGN(type)    \
        DTEST_DISALLOW_COPY(type);              \
        DTEST_DISALLOW_ASSIGN(type)                       

namespace dty::framework::dtest::core
{
    __DEFAULT__ typedef void __VARIABLE__(__POINTER__ TopicBeforeDelegate)(void);
    __DEFAULT__ typedef void __VARIABLE__(__POINTER__ TopicAfterDelegate)(void);

    abstract class Topic
    {
        __PUB__ Topic() = default;
        __PUB__ virtual ~Topic() = default;

        __PUB__ virtual void __VARIABLE__ BeforeTest() { }
        __PUB__ virtual void __VARIABLE__ AfterTest() { }
        __PUB__ virtual void __VARIABLE__ Run() = 0;

        __PUB__ virtual string __VARIABLE__ Description() const = 0;

        DTEST_DISALLOW_COPY_AND_ASSIGN(Topic);

        __PUB__ static void __VARIABLE__ BeforeAll();
        __PUB__ static void __VARIABLE__ AfterAll();
    };

    class CodeLocation final
    {
        __PUB__ CodeLocation(const string __VARIABLE__ file, int32 __VARIABLE__ line);

        __PUB__ static CodeLocation __VARIABLE__ GetCodeLocation(const string __VARIABLE__ file, int32 __VARIABLE__ line);
    };

    class TestInfo final
    {
        __PUB__ TestInfo
        (
            const string        __VARIABLE__ topicNamespace,
            const string        __VARIABLE__ topicName,
            const string        __VARIABLE__ specName,
            const string        __VARIABLE__ description,
            CodeLocation        __VARIABLE__ codeLocation,
            TopicBeforeDelegate __VARIABLE__ fnBeforTest,
            TopicAfterDelegate  __VARIABLE__ fnAfterTest,
            Topic               __POINTER__  oTestSpec
        );
        __PUB__ ~TestInfo();


        __PUB__ void Test();
    };
}

#endif // !__DTY_FRAMEWORK_TIANYU_TEST_DTEST_CORE_H_PLUS_PLUS__