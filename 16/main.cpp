#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
bool D = true;
using INT = __int128;


std::map<char, std::tuple<char, LL, std::vector<char>, bool>> V;
LL maxTime = 30;

LL countP(const decltype(V)& val)
{
    LL score{};
    for(const auto& v:val)
    {
        const auto& [cur, flow, next, open] = v.second;

        if(open)
        {
            score += flow;
        }
    }
    return score;
}



std::pair<LL, LL> stePp(LL time, char prev, char cur, decltype(V)& val, int onlyMove = 0)
{
    if(time == 30)
    {
        return {0, 0};
    }

    if(time <= 10)P(time, prev, cur, countP(val));

    auto& [curAgain, flow, next, open] = val[cur];
    std::vector<std::pair<LL,LL>> variants;

    if(!open)
    {
        decltype(V) copy = val;
        auto& [curAgainCopy, flowCopy, nextCopy, openCopy] = copy[cur];
        openCopy = true;
        variants.push_back(stePp(time+1, cur, cur, copy, 0));
    }
    if(onlyMove < 5)for(auto& n : next)
    {
        decltype(V) copy = val;
        if(n != prev) variants.push_back(stePp(time+1, cur, n, copy, onlyMove+1));
    }

    std::pair<LL,LL> best{0,0};
    for(const auto& v:variants)
    {
        if(best.second < v.second)
        {
            best = v;
        }
    }
    LL thisScore = countP(val);
    best.second += thisScore;
    return best;
}

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
    for(int i{}; i < in.size();i++ )
    {
        auto splitted = splitStr(in[i], ' ');
        S cur = splitted[1];
        LL flow = stoi(replace(replace(splitted[4], "rate="),  ";"));
        std::vector<char> next;
        for(int n = 9; n < splitted.size();++n)
        {
            next.push_back(replace(splitted[n], ",")[0]);
        }
        V[cur[0]] = {cur[0], flow, next, false};
    }

    // auto [step, newScore] = stePp(0, 'A', 'A', V);

    std::map<std::pair<decltype(V), char>,LL> moves;

    FOR(time, 30)
    {
        for(auto& m : moves)
        {
            auto& [pair, score] = m;
            auto& [val, cur] = pair;
            auto& [curAgain, flow, next, open] = val[cur];

        }
    }

    P_RR("Part1: %lld\n", score);
//========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
