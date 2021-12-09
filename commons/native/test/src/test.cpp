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

    EXPECT_FLOAT_EQ(1.0, 2.0);
    EXPECT_FLOAT_GT(1.0, 2.0);
    EXPECT_FLOAT_LT(1.0, 2.0);
    EXPECT_FLOAT_1(1.0);
    EXPECT_FLOAT_0(1.0);

    EXPECT_STR_EQ("", "");
    EXPECT_STR_NE("", "");
    EXPECT_STR_LT("", "");
    EXPECT_STR_GT("", "");
    EXPECT_STR_IS_EMPTY("");
    EXPECT_STR_NOT_EMPTY("");

    EXPECT_THROW({ TC1 a;TC1 b; })EXPECT_CATCH(int32 b)EXPECT_CATCH(string c)EXPECT_CATCH_FOR_STATE(bool a, UnStable);
    ASSERT_THROW({ TC1 a;TC1 b; })ASSERT_CATCH(int32 b)ASSERT_CATCH(string c)ASSERT_CATCH_FOR_STATE(bool a, UnStable);



    ASSERT_EQ(A, B);

    ASSERT_EQ(1, 2);
    ASSERT_NE(1, 2);
    ASSERT_GT(1, 2);
    ASSERT_LT(1, 2);
    ASSERT_IS_NULL((void*)1);
    ASSERT_NOT_NULL((void*)1);
    ASSERT_TRUE(1);
    ASSERT_FALSE(1);
    ASSERT_1(1);
    ASSERT_0(1);

    ASSERT_FLOAT_EQ(1.0, 2.0);
    ASSERT_FLOAT_GT(1.0, 2.0);
    ASSERT_FLOAT_LT(1.0, 2.0);
    ASSERT_FLOAT_1(1.0);
    ASSERT_FLOAT_0(1.0);

    ASSERT_STR_EQ("", "");
    ASSERT_STR_NE("", "");
    ASSERT_STR_LT("", "");
    ASSERT_STR_GT("", "");
    ASSERT_STR_IS_EMPTY("");
    ASSERT_STR_NOT_EMPTY("");

    try
    {

    }
    catch (void*)
    {

    }
}

int main()
{
    return 0;
}