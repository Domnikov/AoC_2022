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

S check(S cmd, int val)
{
    static int cycle = 1;
    static int sum = 1;
    S newScore;
    if(cmd == "noop")
    {
        auto pos = ++cycle % 40;
        {
            newScore += (pos >= sum && pos <= sum+3) ? "#" : ".";
        }
    }
    else if(cmd == "addx")
    {
        auto pos = ++cycle % 40;
        newScore += (pos >= sum && pos <= sum+3) ? "#" : ".";
        sum += val;
        pos = ++cycle % 40;
        newScore += (pos >= sum && pos <= sum+3) ? "#" : ".";
    }
    return newScore;
}

int main(int argc, char** argv)
{
    int score = 0;
    S disp = "#";

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

