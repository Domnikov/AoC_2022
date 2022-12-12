#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

#include <cmath>

auto in = getInput();

using INT = __int128;

int main(int argc, char** argv)
{
    LL score = 0;
    FOR(i, in.size())
    {
        auto& s = in[i];
    }
    P_RR("Part1: %lld\n", score);

    score = 0;
    FOR(i, in.size())
    {
        auto& s = in[i];
    }
    P_RR("Part2: %lld\n", score);
}
