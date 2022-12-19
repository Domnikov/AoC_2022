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


LL calc(VECI cost, VECI rob, VECI res, LL time)
{
    if(time >= 24){if(res[3] > 9){P(res[3]);} return res[3];}
    LL oreCost     = cost[0];
    LL clayCost    = cost[1];
    LL obsOreCost  = cost[2];
    LL obsClayCost = cost[3];
    LL geoOreCost  = cost[4];
    LL goeObsCost  = cost[5];
    LL ore = res[0], clay = res[1], obs = res[2], geo = res[3];
    LL orR = rob[0], clR = rob[1], obR = rob[2], geR = rob[3];

    LL score{};

    ore += orR;
    clay += clR;
    obs += obR;
    geo += geR;

    if(res[0] >= oreCost                             && orR <= (clR+1)*2) { score = std::max(score, calc(cost, {orR+1, clR, obR, geR}, {ore - oreCost, clay, obs, geo}, time+1)); }
    if(res[0] >= clayCost                            && clR <= (orR+1) * 2 && clR <= (obR+1)*2) { score = std::max(score, calc(cost, {orR, clR+1, obR, geR}, {ore - clayCost, clay, obs, geo}, time+1)); }
    if(res[0] >= obsOreCost && res[1] >= obsClayCost && obR <= (geR+1) * 2) { score = std::max(score, calc(cost, {orR, clR, obR+1, geR}, {ore - obsOreCost, clay - obsClayCost, obs, geo}, time+1)); }
    if(res[0] >= geoOreCost && res[2] >= goeObsCost) { score = std::max(score, calc(cost, {orR, clR, obR, geR+1}, {ore - geoOreCost, clay, obs - goeObsCost, geo}, time+1)); }
    if(ore <= geoOreCost) { score = std::max(score, calc(cost, {orR, clR, obR, geR}, {ore, clay, obs, geo}, time+1)); }

    return score;
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
        score += ++num * calc({oreCost, clayCost, obsOreCost, obsClayCost, geoOreCost, goeObsCost}, {1, 0, 0, 0}, {0, 0, 0, 0}, 0);
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
