#include "gmock/gmock.h"
#include "baseball.h"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached)
{
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}

int main()
{
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}