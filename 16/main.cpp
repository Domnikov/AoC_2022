// #define TEST

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
    P_LINE;
    char dst = 0;
    for(auto& v:val)
    {
        if(std::get<1>(v.second) == flow)
        {
            dst = v.first;
        }
    }
    P_LINE;
    if(!dst) return{};
    std::vector<VECC>paths{{cur}};
    P_LINE;
    while(true)
    {
        P(paths.size());
        std::vector<VECC>nextPaths{{cur}};
        for(auto p: paths)
        {
            if(p.back() == dst)
            {
                return p;
            }
            for(const auto& n : std::get<2>(val.at(p.back())))
            {
                if(std::find(BE(p), n) == p.end())
                {
                    VECC newPath = p;
                    newPath.push_back(n);
                    nextPaths.push_back(newPath);
                }
            }
        }
        std::swap(paths, nextPaths);
    }

    P_LINE;

    P_RR("No path %c to %c \n", cur, dst);
    exit(0);
}

VECI get3MaxClosed(V_t val)
{
    P_LINE;
    VECI allFlows;
    auto it = val.begin();
    while((it = std::find_if(BE(val), [](const auto& a){return std::get<3>(a.second);})) != val.end())
    {
        val.erase(it);
    }
    std::transform(BE(val), std::back_inserter(allFlows), [](const auto& a){return std::get<1>(a.second);});
    std::sort(BE(allFlows));

    LL max1 = *(allFlows.end()-1);
    LL max2 = *(allFlows.end()-2);
    LL max3 = *(allFlows.end()-3);
    P_LINE;
    return{max1, max2, max3};
}


std::pair<LL, LL> steP(char cur, decltype(V) val, LL time, LL score);
std::pair<LL, LL> planNext(char cur, decltype(V) val, LL time, LL score)
{
    P_LINE;
    // if(time < 20)P(time);
    auto maxFows = get3MaxClosed(val);
    std::vector<std::pair<LL, LL>> ress;
    LL curP = countP(val);
    P_LINE;
    for(auto m : maxFows)
    {
        if(m == 1){return {0,0};}
    P_LINE;
        auto path = getPathIf(cur, m, val);
    P_LINE;
        if(D)
        {
            FOR(i, time)P_RR(" ");
            P_VEC(path);
        }
        LL pathLen = path.size()-1;
        LL newTime = time+pathLen;
    P_LINE;
        if(newTime >= maxTime)
        {
            static LL max{};
            LL newScore = score + curP * (maxTime-time);
            max = std::max(max, newScore);
    P_LINE;
            if(D){FOR(i, time)P_RR(" ");P(max, newScore, score, maxTime-time, curP);}
            // if(newScore == 1512)exit(1);
            return {0, newScore};
        }
        LL newScore = score + curP * pathLen;
    P_LINE;
        ress.push_back(steP(path.back(), val, newTime, newScore));
    P_LINE;
    }
    P_LINE;
    std::sort(BE(ress));
    P_LINE;
    return {ress.back().first, ress.back().second};
}


std::pair<LL, LL> steP(char cur, decltype(V) val, LL time, LL score)
{
    P_LINE;
    auto& [curAgain, flow, nexts, open] = val[cur];
    open = true;
    time++;
    score += countP(val);
    P_LINE;
    if(D)
    {
        FOR(i, time)P_RR(" ");
        P(cur, time, score, countP(val));
    P_LINE;
    }
    if(time == maxTime)
    {
        if(D)
        {
            FOR(i, time)P_RR(" ");
            P("Exit after turnon", cur, time, score);
        }
    P_LINE;
        return {0, score};
    }
    auto res = planNext(cur, val, time, score);
    P_LINE;

    return res;
}

int main(int argc, char** argv)
{
    LL score = 0;
    D = true;
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

    auto [step, newScore] = planNext('A', V, 1, 0);
    score = newScore;
    P_RR("Part1: %lld\n", score);
//========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
