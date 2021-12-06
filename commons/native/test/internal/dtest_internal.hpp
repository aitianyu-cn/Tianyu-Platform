/**
 * @file dtest_internal.hpp(tianyu-test/internal)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-06
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_FRAMEWORK_TIANYU_TEST_INTERNAL_DTEST_INTERNAL_H_PLUS_PLUS__
#define __DTY_FRAMEWORK_TIANYU_TEST_INTERNAL_DTEST_INTERNAL_H_PLUS_PLUS__

#include"../utils.hpp"
#include"../dtest_core.hpp"

#include <type_traits>

 // DTEST_SPEC:     用于定义一个Unit Test，包含topic和Unit Test Name
 // DTEST_RUN_SPEC: 用于运行指定的Unit Test，需要提供topic和Unit Test Name
 // DTEST_RUN_ALL:  用于运行所有定义的Unit Test
 // DTEST_RUN_UNIT: 用于运行指定的一组Unit Test，需要提供topic

namespace dty::framework::dtest::internal
{
    ::dty::framework::dtest::core::TestInfo __POINTER__ RegisterTestSpec
    (
        const string __VARIABLE__ topicNamespace,
        const string __VARIABLE__ topicName,
        const string __VARIABLE__ specName,
        const string __VARIABLE__ description,
        ::dty::framework::dtest::core::CodeLocation        __VARIABLE__ codeLocation,
        ::dty::framework::dtest::core::TopicBeforeDelegate __VARIABLE__ fnBeforTest,
        ::dty::framework::dtest::core::TopicAfterDelegate  __VARIABLE__ fnAfterTest,
        ::dty::framework::dtest::core::Topic               __POINTER__  oTestSpec
    );

    template<typename T>
    struct SpecApiHandler : T
    {
        using TestType =
            typename std::conditional<sizeof(T) != 0, ::dty::framework::dtest::core::Topic, void>::type;

        static ::dty::framework::dtest::core::TopicBeforeDelegate __VARIABLE__ GetTopicBeforeAll()
        {
            return __REFERENCE__ T::BeforeAll;
        }

        static ::dty::framework::dtest::core::TopicAfterDelegate  __VARIABLE__ GetTopicAfterAll()
        {
            return __REFERENCE__ T::AfterAll;
        }
    };

    class Test final
    {

    };

    typedef const object TypeId;

    template<typename T>
    class TypeIdHelper
    {
        __PUB__ static bool _dummy;
    };

    template<typename T>
    bool TypeIdHelper<T>::_dummy = false;

    template<typename T>
    TypeId GetTypeId()
    {
        return &(TypeIdHelper<T>::_dummy);
    }
}

#endif // !__DTY_FRAMEWORK_TIANYU_TEST_INTERNAL_DTEST_INTERNAL_H_PLUS_PLUS__