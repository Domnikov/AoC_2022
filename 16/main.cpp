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


using V_t = std::map<S, std::tuple<S, LL, VECS, bool>>;
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


VECS getPathIf(S cur, LL flow)//, const V_t& val)
{
    S dst;
    auto& val = V;
    for(auto& v:val)
    {
        if(std::get<1>(v.second) == flow)
        {
            dst = v.first;
        }
    }
    if(dst.empty()) return{};
    std::vector<VECS>paths{{cur}};
    if(cur == dst) return paths[0];
    while(true)
    {
        decltype(paths) nextPaths{{cur}};
        for(const auto& p: paths)
        {
            if(p.back() == dst)
            {
                return p;
            }
            auto& curVal = val.at(p.back());
            auto& allNexts = std::get<2>(curVal);
            for(const auto& n : allNexts)
            {
                if(std::find(BE(p), n) == p.end())
                {
                    VECS newPath = p;
                    newPath.push_back(n);
                    nextPaths.push_back(newPath);
                }
            }
        }
        std::swap(paths, nextPaths);
    }


    P_RR("No path %s to %s \n", cur.c_str(), dst.c_str());
    exit(0);
}

VECSS get3MaxClosed(S cur, V_t val)
{
    VECI allFlows;
    auto it = val.begin();
    LL N = 3;
    while((it = std::find_if(BE(val), [](const auto& a){return std::get<3>(a.second);})) != val.end())
    {
        val.erase(it);
    }
    std::transform(BE(val), std::back_inserter(allFlows), [](const auto& a){return std::get<1>(a.second);});
    std::sort(BE(allFlows));

    VECSS res;
    LL curP = countP(val);
    LL maxLen;
    for(int i = 0; i < allFlows.size(); ++i)
    {
        LL dst = allFlows.back();
        if(dst == 0) break;
        allFlows.pop_back();
        auto path = getPathIf(cur, dst);//, val);
        maxLen = std::max<LL>(maxLen, path.size());
        res.push_back(path);
    }
    if(res.empty()){return {};}
    size_t idx = 0;
    auto countPath = [maxLen, &res, curP](LL i){LL curLen = res[i].size();LL nextP = std::get<1>(V[res[i].back()]);return (curP*(curLen)) + (curP+nextP)*(maxLen-curLen);};
    auto compPath = [countPath, res](const auto& a, const auto& b)
    {
        LL indxA = std::distance(res.begin(), std::find(BE(res), a));
        LL indxB = std::distance(res.begin(), std::find(BE(res), b));
        return countPath(indxA) < countPath(indxB);
    };
    std::sort(BE(res), compPath);
    while(res.size() > N)
    {
        res.pop_back();
    }
    return res;
}


std::pair<LL, LL> steP(S cur, decltype(V) val, LL time, LL score);
std::pair<LL, LL> planNext(S cur, decltype(V) val, LL time, LL score)
{
    // if(time < 20)P(time);
    auto maxFlows = get3MaxClosed(cur, val);
    if(maxFlows.empty())
    {
        return {0, score + (maxTime-time)*countP(val)};
    }
    std::vector<std::pair<LL, LL>> ress;
    LL curP = countP(val);
    for(auto m : maxFlows)
    {
        // if(m == 1){return {0,0};}
        // auto path = getPathIf(cur, m, val);
        auto& path = m;
        if(D)
        {
            FOR(i, time)P_RR(" ");
            P_VEC(path);
        }
        LL pathLen = path.size()-1;
        LL newTime = time+pathLen;
        if(newTime >= maxTime)
        {
            static LL max{};
            LL newScore = score + curP * (maxTime-time);
            max = std::max(max, newScore);
            if(D){FOR(i, time)P_RR(" ");P(max, newScore, score, maxTime-time, curP);}
            // if(newScore == 1512)exit(1);
            return {0, newScore};
        }
        LL newScore = score + curP * pathLen;
        ress.push_back(steP(path.back(), val, newTime, newScore));
    }
    std::sort(BE(ress));
    return {ress.back().first, ress.back().second};
}


std::pair<LL, LL> steP(S cur, decltype(V) val, LL time, LL score)
{
    auto& [curAgain, flow, nexts, open] = val[cur];
    open = true;
    time++;
    score += countP(val);
    if(D)
    {
        FOR(i, time)P_RR(" ");
        P(cur, time, score, countP(val));
    }
    if(time == maxTime)
    {
        if(D)
        {
            FOR(i, time)P_RR(" ");
            P("Exit after turnon", cur, time, score);
        }
        return {0, score};
    }
    auto res = planNext(cur, val, time, score);

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
        VECS next;
        for(int n = 9; n < splitted.size();++n)
        {
            next.push_back(replace(splitted[n], ","));
        }
        V[cur] = {cur, flow, next, false};
    }

    auto [step, newScore] = planNext("AA", V, 1, 0);
    score = newScore;
    P_RR("Part1: %lld\n", score);
//========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
