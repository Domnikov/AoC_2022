#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;


LL calc(LL oreCost , LL clayCost , LL obsOreCost, LL obsClayCost, LL geoOreCost, LL goeObsCost)
{
    FOR(i, 24)
    ;
}


int main(int argc, char** argv)
{
    LL score = 0;

    LL num = 0;
    for(auto& i : in)
    {
        auto sent = splitStr(i, ' ');
        LL oreCost     = stoi(sent[ 6]);
        LL clayCost    = stoi(sent[12]);
        LL obsOreCost  = stoi(sent[18]);
        LL obsClayCost = stoi(sent[21]);
        LL geoOreCost  = stoi(sent[27]);
        LL goeObsCost  = stoi(sent[30]);
        P(oreCost, clayCost, obsOreCost, obsClayCost, geoOreCost, goeObsCost);
        // score += calc(oreCost, clayCost, obsOreCost, obsClayCost, geoOreCost, goeObsCost);
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
