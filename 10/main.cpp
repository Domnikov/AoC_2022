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
            P(s, cycle, newScore, newScore*cycle);
            newScore *= cycle;
        }
    }
    else if(cmd == "addx")
    {
        if(isSpecial(++cycle))
        {
            newScore = sum;
            P("add before", cycle, newScore, newScore*cycle);
            newScore *= cycle;
        }
        sum += val;
        if(cycle > 180)P(sum, val);
        if(isSpecial(++cycle))
        {
            newScore += sum;
            P("add after", cycle, newScore, newScore*cycle);
            newScore *= cycle;
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

