#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

#include<queue>
#include <list>

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;
bool D = false;


int main(int argc, char** argv)
{
    LL score = 0;

    std::map<S, INT> monkeys;

    FOR(i, in.size()-1)
    {
        auto s = in[i];
        P(s);
    }

    P(*(in.end()-1));


    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;



    P_RR("Part2: %lld\n", score);
    return 0;
}
