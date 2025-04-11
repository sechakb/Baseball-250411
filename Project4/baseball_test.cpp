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
    Baseball game;
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
}