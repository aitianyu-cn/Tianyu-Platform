#include"../dtest_def.hpp"

namespace aaa::bbb::ccc
{
    class C : public DTEST_TOPIC_BASE
    {
        __PUB__ static void __VARIABLE__ BeforeAll();
        __PUB__ static void __VARIABLE__ AfterAll();
    };
}

DTEST_SPEC_NAMESPACE(aaa::bbb::ccc, C, B, abc)
{
    EXPECT_EQ(true, false);
}

int main()
{
    return 0;
}