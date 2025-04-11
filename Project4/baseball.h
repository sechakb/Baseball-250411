#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult
{
    int strikes;
    int balls;
    bool solved;
};

class Baseball
{
public:
    explicit Baseball(const string &question) : question(question) {}

    GuessResult guess(const string &guessNumber)
    {
        AssertIllegalArgument(guessNumber);

        GuessResult stRet;
        stRet.strikes = GetNumOfStrike(guessNumber);
        stRet.balls = GetNumOfBall(guessNumber);
        stRet.solved = (stRet.strikes == 3);

        return stRet;
    }
private:
    string question;

    void AssertIllegalArgument(const string &guessNumber)
    {
        if (guessNumber.length() != 3)
        {
            throw length_error("Must be three letters.");
        }

        for (char ch : guessNumber)
        {
            if (ch < '0' || ch > '9')
            {
                throw invalid_argument("Must be number");
            }
        }

        if (IsDuplicatedNumber(guessNumber))
        {
            throw invalid_argument("Must not have the same number");
        }
    }

    bool IsDuplicatedNumber(const string &guessNumber)
    {
        return (guessNumber[0] == guessNumber[1]) || (guessNumber[0] == guessNumber[2]) || (guessNumber[1] == guessNumber[2]);
    }

    int GetNumOfStrike(const string &guessNumber)
    {
        return (guessNumber[0] == question[0]) + (guessNumber[1] == question[1]) + (guessNumber[2] == question[2]);
    }

    int GetNumOfBall(const string &guessNumber)
    {
        int nBall = 0;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (i == j)
                {
                    continue;   // strike
                }

                nBall += (guessNumber[i] == question[j]);
            }
        }
        return nBall;
    }
};