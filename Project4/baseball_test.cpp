#include "gmock/gmock.h"
#include "baseball.h"

int main()
{
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached)
{
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar)
{
    Baseball game;
    EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}