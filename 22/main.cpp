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

enum DIR
{
    up,down,left,right
};

int main(int argc, char** argv)
{
    LL score = 0;

    std::map<S, INT> monkeys;


    auto cmds = *(in.end()-1);

    LL x = in[0].find('.');
    LL y = 0;
    DIR dir = DIR::right;

    in[y][x] = 'X';

    FOR(i, in.size()-2)
    {
        auto s = in[i];
        P(s);
    }



    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;



    P_RR("Part2: %lld\n", score);
    return 0;
}
