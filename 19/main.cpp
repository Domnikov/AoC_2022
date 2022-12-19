#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;

LL T = 24;


LL calc(VECII cost, VECI strtg)
{
    LL res[4] = {0, 0, 0, 0};
    LL rob[4] = {1, 0, 0, 0};

    LL next{};
    FOR(t, T)
    {

        if(
                res[0] >= cost[strtg[next]][0] &&
                res[1] >= cost[strtg[next]][1] &&
                res[2] >= cost[strtg[next]][2]
                )
        {
            FOR(i, 4) {res[i] += rob[i];}
            res[0] -= cost[strtg[next]][0];
            res[1] -= cost[strtg[next]][1];
            res[2] -= cost[strtg[next]][2];
            rob[strtg[next++]]++;
        }
        else
        {
            FOR(i, 4) {res[i] += rob[i];}
        }
        // P(t+1);
        // P(res[0], res[1], res[2], res[3]);
        // P(rob[0], rob[1], rob[2], rob[3]);
    };


    return res[3];
}


int main(int argc, char** argv)
{
    LL score = 0;

    LL num = 0;
    for(auto& i : in)
    {
        VECI strtg{{0,0,1,1,1,1,2,2,2,3,3,3}};
        auto sent = splitStr(i, ' ');
        LL oreCost     = stoi(sent[ 6]);
        LL clayCost    = stoi(sent[12]);
        LL obsOreCost  = stoi(sent[18]);
        LL obsClayCost = stoi(sent[21]);
        LL geoOreCost  = stoi(sent[27]);
        LL goeObsCost  = stoi(sent[30]);
        VECII cost{{oreCost, 0, 0}, {clayCost, 0, 0}, {obsOreCost, obsClayCost, 0}, {geoOreCost, 0, goeObsCost}};
        LL max {};
        do {
            P_VEC(strtg);
            if(strtg[0] == 2) break;
            max = std::max(max, calc(cost, strtg));
        } while(std::next_permutation(strtg.begin(), strtg.end()));

        score += ++num * max;
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
