#include"../dtest_def.hpp"

namespace aaa::bbb::ccc
{
    class C : public DTEST_TOPIC_BASE
    {
        __PUB__ static void __VARIABLE__ BeforeAll();
        __PUB__ static void __VARIABLE__ AfterAll();
    };
}

#define TEST_CHECK()\


class TC1 { };
class TC2 { };

DTEST_SPEC_NAMESPACE(aaa::bbb::ccc, C, B, abc)
{
    // if (this->hasError)
    // {
    //     // notify abort
    // }
    // else
    // {
    //     // todo: check v1 == v2
    //     // if (failed)
    //     // {
    //     //      notify failed
    //     //      if (assert)
    //     //          return;
    //     // }
    // }

    TC1 A, B;

    EXPECT_EQ(A, B);

    EXPECT_EQ(1, 2);
    EXPECT_NE(1, 2);
    EXPECT_GT(1, 2);
    EXPECT_LT(1, 2);
    EXPECT_IS_NULL((void*)1);
    EXPECT_NOT_NULL((void*)1);
    EXPECT_TRUE(1);
    EXPECT_FALSE(1);
    EXPECT_1(1);
    EXPECT_0(1);
}

int main()
{
    return 0;
}