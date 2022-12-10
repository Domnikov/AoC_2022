 #define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();

bool isSpecial(LL cycle)
{
    if(
            cycle == 20 ||
            cycle == 60 ||
            cycle ==100 ||
            cycle ==140 ||
            cycle ==180 ||
            cycle ==220) return true;

    return false;
}

int check(S cmd, int val)
{
    static int cycle = 0;
    static int sum = 1;
    int newScore = 0;
    if(cmd == "noop")
    {
        if(isSpecial(++cycle))
        {
            newScore = sum;
        }
    }
    else if(cmd == "addx")
    {
        if(isSpecial(++cycle))
        {
            newScore = sum;
        }
        sum += val;
        P(val,sum);
        if(isSpecial(++cycle))
        {
             newScore += sum;
        }
    }
    return newScore;
}

int main(int argc, char** argv)
{
    int score = 0;


    for(auto s:in)
    {
        auto vec = splitStr(s,' ');

        int addScore{}, addCycle{};
        score += check(vec[0], (vec.size() == 1) ? 0 : stoi(vec[1]));
    }

    P(score);
}

