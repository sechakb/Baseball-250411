#include "gmock/gmock.h"
#include "baseball.h"

TEST(BaseballGame, TryGameTest)
{
    EXPECT_EQ(1, 1);
}

int main()
{
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}