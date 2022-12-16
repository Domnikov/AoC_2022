#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
bool D = true;
using INT = __int128;
using VECC = std::vector<char>;


using V_t = std::map<char, std::tuple<char, LL, VECC, bool>>;
V_t V;
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


VECC getPathIf(char cur, LL flow, const V_t& val)
{
    char dst = 0;
    for(auto& v:val)
    {
        if(std::get<1>(v.second) == flow)
        {
            dst = v.first;
        }
    }
    if(!dst) return{};
    std::vector<VECC>paths{{cur}};
    while(true)
    {
        std::vector<VECC>nextPaths{{cur}};
        for(auto p: paths)
        {
            if(p.back() == dst)
            {
                return p;
            }
            for(const auto& n : std::get<2>(val.at(p.back())))
            {
                VECC newPath = p;
                newPath.push_back(n);
                nextPaths.push_back(newPath);
            }
        }
        std::swap(paths, nextPaths);
    }


    P_RR("No path %c to %c \n", cur, dst);
    exit(0);
}

VECI get3MaxClosed(V_t val)
{
    VECI allFlows;
    P_LINE;
    while(auto it = std::find_if(BE(val), [](const auto& a){return !std::get<3>(a.second);}) != val.end()){val.erase(it);}
    std::transform(BE(val), std::back_inserter(allFlows), [](const auto& a){return std::get<1>(a.second);});
    std::sort(BE(allFlows));

    LL max1 = *(allFlows.end()-1);
    LL max2 = *(allFlows.end()-2);
    LL max3 = *(allFlows.end()-3);
    return{max1, max2, max3};
}


std::pair<LL, LL> steP(char cur, decltype(V) val, LL time, LL score);
std::pair<LL, LL> planNext(char cur, decltype(V) val, LL time, LL score)
{
    auto maxFows = get3MaxClosed(val);
    std::vector<std::pair<LL, LL>> ress;
    LL curP = countP(val);
    for(auto m : maxFows)
    {
        if(m == 1){return {0,0};}
        auto path = getPathIf(cur, m, val);
        if(D)
        {
            FOR(i, time)P_RR("  ");
            P_VEC(path);
        }
        LL newTime = time+path.size();
        if(newTime >= maxTime)
        {
            return {0, score + curP * maxTime-time};
        }
        ress.push_back(steP(path.back(), val, time+path.size(), score + path.size()*curP));
    }
    std::sort(BE(ress));
    return {ress.back().first, ress.back().second};
}


std::pair<LL, LL> steP(char cur, decltype(V) val, LL time, LL score)
{
    auto& [curAgain, flow, nexts, open] = val[cur];
    open = true;
    time++;
    score += countP(val);
    auto res = planNext(cur, val, time, score);
    if(D)
    {
        FOR(i, time)P_RR("  ");
        P(cur, time, score);
    }

    return res;
}

int main(int argc, char** argv)
{
    LL score = 0;
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

    auto [step, newScore] = planNext('A', V, 0, 0);

    P_RR("Part1: %lld\n", score);
//========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
