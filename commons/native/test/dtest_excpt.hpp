/**
 * @file dtest_excpt.hpp(tianyu-test)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-07
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_FRAMEWORK_TIANYU_TEST_DTEST_EXCPT_H_PLUS_PLUS__
#define __DTY_FRAMEWORK_TIANYU_TEST_DTEST_EXCPT_H_PLUS_PLUS__

#include"./dtest_core.hpp"

 //
 //
#define DTEST_CHECKER_GETANEM(type, dataType) DTestChecker##dataType##_##type

//
//
#define DTEST_CHECKER_CLASS(check_type, data_type)\
    class DTEST_CHECKER_GETANEM(check_type, data_type)


namespace dty::framework::dtest::core
{
    __DEFAULT__ bool __VARIABLE__ CustomerFailureChecker
    (
        DTestState __VARIABLE__ state,
        int32      __VARIABLE__ failure_level
    );

    DTEST_CHECKER_CLASS(EQ, )
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            object         __VARIABLE__ val1,
            object         __VARIABLE__ val2
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2
            )
        {

        }

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            object         __VARIABLE__ val1,
            object         __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2,
                int32          __VARIABLE__  failure_level
            )
        {

        }
    };

    DTEST_CHECKER_CLASS(NE, )
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            object         __VARIABLE__ val1,
            object         __VARIABLE__ val2
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2
            )
        {

        }

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            object         __VARIABLE__ val1,
            object         __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2,
                int32          __VARIABLE__  failure_level
            )
        {

        }
    };

    DTEST_CHECKER_CLASS(GT, )
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2
            )
        {

        }

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2,
                int32          __VARIABLE__  failure_level
            )
        {

        }
    };

    DTEST_CHECKER_CLASS(LT, )
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2
            )
        {

        }

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            int32          __VARIABLE__ val1,
            int32          __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ template<typename T1, typename T2>
            static void __VARIABLE__ Checker
            (
                TestInfo       __POINTER__   test_info,
                int32          __VARIABLE__  line,
                DTestCheckType __VARIABLE__  type,
                T1             __REFERENCE__ val1,
                T2             __REFERENCE__ val2,
                int32          __VARIABLE__  failure_level
            )
        {

        }
    };

    DTEST_CHECKER_CLASS(EQ, float)
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            float          __VARIABLE__ val1,
            float          __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            double         __VARIABLE__ val1,
            double         __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            float          __VARIABLE__ val1,
            float          __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            double         __VARIABLE__ val1,
            double         __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );
    };

    DTEST_CHECKER_CLASS(GT, float)
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            float          __VARIABLE__ val1,
            float          __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            double         __VARIABLE__ val1,
            double         __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            float          __VARIABLE__ val1,
            float          __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            double         __VARIABLE__ val1,
            double         __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );
    };

    DTEST_CHECKER_CLASS(LT, float)
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            float          __VARIABLE__ val1,
            float          __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            double         __VARIABLE__ val1,
            double         __VARIABLE__ val2
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            float          __VARIABLE__ val1,
            float          __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );

        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            double         __VARIABLE__ val1,
            double         __VARIABLE__ val2,
            int32          __VARIABLE__ failure_level
        );
    };

    DTEST_CHECKER_CLASS(EQ, string)
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2
        );
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2,
            int32          __VARIABLE__ failure_level
        );
    };

    DTEST_CHECKER_CLASS(NE, string)
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2
        );
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2,
            int32          __VARIABLE__ failure_level
        );
    };

    DTEST_CHECKER_CLASS(LT, string)
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2
        );
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2,
            int32          __VARIABLE__ failure_level
        );
    };

    DTEST_CHECKER_CLASS(GT, string)
    {
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2
        );
        __PUB__ static void __VARIABLE__ Checker
        (
            TestInfo       __POINTER__  test_info,
            int32          __VARIABLE__ line,
            DTestCheckType __VARIABLE__ type,
            const string   __VARIABLE__ str1,
            const string   __VARIABLE__ str2,
            int32          __VARIABLE__ failure_level
        );
    };
}

#endif // !__DTY_FRAMEWORK_TIANYU_TEST_DTEST_EXCPT_H_PLUS_PLUS__