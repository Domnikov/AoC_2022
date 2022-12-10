#define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();

S check(S cmd, int val)
{
    static int cycle = 0;
    static int sum = 0;
    S newScore;
    if(cmd == "noop")
    {
        auto pos = cycle++ % 40;
        newScore += (pos >= sum && pos <= sum+3) ? "#" : ".";
    }
    else if(cmd == "addx")
    {
        auto pos = cycle++ % 40;
        newScore += (pos >= sum && pos <= sum+3) ? "#" : ".";
        pos = cycle++ % 40;
        sum += val;
        newScore += (pos >= sum && pos <= sum+3) ? "#" : ".";
    }
    P(sum, newScore);
    return newScore;
}

int main(int argc, char** argv)
{
    int score = 0;
    S disp;

    for(auto s:in)
    {
        auto vec = splitStr(s,' ');

        int addScore{}, addCycle{};
        disp += check(vec[0], (vec.size() == 1) ? 0 : stoi(vec[1]));
    }

    P(score);


    FOR(i, disp.size())
    {
        if(i%40 == 0)std::cerr << "\n";
        std::cerr<<disp[i];
    }
}

