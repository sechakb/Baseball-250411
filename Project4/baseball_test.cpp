#include "gmock/gmock.h"
#include "baseball.h"

int main()
{
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

class BaseballFixture : public testing::Test
{
public:
    Baseball game{"123"};
    void assertIllegalArgument(string guessNumber)
    {
        // game.guess() 수행 후, Exception이 발생해야 PASS이다.
        // EXPECT_THROW(game.guess(guessNumber), exception);
        try
        {
            game.guess(guessNumber);
            FAIL();
        }
        catch(const exception& e)
        {
            // PASS
        }
    }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Return2Strike0Ball)
{
    GuessResult result = game.guess("124");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Return1Strike2Ball)
{
    GuessResult result = game.guess("132");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(1, result.strikes);
    EXPECT_EQ(2, result.balls);
}