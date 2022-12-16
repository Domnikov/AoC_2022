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

using Vt = std::map<S, std::tuple<S, LL, VECS, bool>>;
Vt V;
VECII graph;
VECS heads;
VECI flows;
LL maxTime = 30;

LL getNum(S s){return std::distance(heads.begin(), (std::find(BE(heads), s)));}

VECI getPath(S src, S dst)
{
    VECSS paths{{src}};

    FOR(i, 999999)
    {
        decltype(paths) newP;
        for(const auto& p : paths)
        {
            if(p.back() == dst)
            {
                VECI res;
                auto func = [](const auto& s) -> LL{return getNum(s);};
                std::transform(p.begin(), p.end(), std::back_inserter(res), func);
                return res;
            }
            for(const auto& n : std::get<2>(V.at(p.back())))
            {
                if(std::find(BE(p), n) == p.end())
                {
                    auto copy = p;
                    copy.push_back(n);
                    newP.push_back(copy);
                }
            }
        }
        paths = newP;
    }

    P("Cannot find path from %s to %s\n", src.c_str(), dst.c_str());

    return {};
}

VECII getGraph(const Vt& val)
{
    VECII res;
    for(const auto& v : heads)
    {
        res.push_back({});
        for(const auto& sub : heads)
        {
            auto path = getPath(v, sub);
            res.back().push_back(path.size());
        }
    }
    return res;
}

VECI calc(VECI path, LL time)
{
    P_VEC(path);
    VECI res;

    int maxScore{};
    int maxId = -1;

    FOR(i, heads.size())
    {
        if(std::find(BE(path), i) == path.end())
        {
            LL timeLeft = maxTime - time - graph[i][path.back()];
            if(timeLeft >= 0)
            {
                LL score = timeLeft * flows[i];
                if(score > maxScore)
                {
                    maxScore = score;
                    maxId = i;
                }
            }
        }
    }

    if(maxId == -1)
    {
        res = path;
    }
    else
    {
        time += graph[path.back()][maxId];
        path.push_back(maxId);
        res = calc(path, time);
    }

    return res;
}

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
    heads.push_back("AA");
    flows.push_back(0);
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
        if(flow > 0)
        {
            heads.push_back(cur);
            flows.push_back(flow);
        }
    }

    graph = getGraph(V);
    P_VEC(heads);
    P_VEC(graph);

    auto path = calc({0}, 0);
    P_VEC(path);

    LL time = maxTime;
    for(LL i = 1; i < path.size(); i++)
    {
        time -= graph[path[i-1]][path[i]];
        score += time * flows[path[i]];
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
