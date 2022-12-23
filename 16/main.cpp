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

void P_PER(VECI vec)
{
    for(auto i : vec)
    {
        P_RR("%s; ", heads[i].c_str());
    }
    P_RR("\t");
}

std::pair<LL, LL> countScore(VECI path)
{
    LL score{};
    LL time = maxTime;
    for(LL i = 1; i < path.size(); i++)
    {
        time -= graph[path[i-1]][path[i]];
        LL flow = flows[path[i]];
        if(time > 0) {score += time * flow;}
        // P(heads[path[i]], time, flow, time*flow, score);
    }
    return {score, time};
}


std::pair<LL, LL> countScore2(VECI path)
{
    P_VEC(path);
    LL score{};
    LL time = maxTime;
    for(LL i = 2; i < path.size(); i+=2)
    {
        time -= graph[path[i-1]][path[i]];
        LL flow = flows[path[i]];
        if(time > 0) {score += time * flow;}
        P(heads[path[i]], time, flow, time*flow, score);
    }
    time = maxTime;
    for(LL i = 3; i < path.size(); i+=2)
    {
        time -= graph[path[i-1]][path[i]];
        LL flow = flows[path[i]];
        if(time > 0) {score += time * flow;}
        P(heads[path[i]], time, flow, time*flow, score);
    }
    return {score, time};
}

VECI calc(VECI path, VECI init,  LL time)
{
    VECI res;
    LL N = heads.size();
    LL INF = 99999999;
    std::vector<VECII> V{VECII{}};
    // VECI init{0,9,4,14,6,7,11,3,2,1,12,8,13,15,5,10};
    // FOR(i, N){init.push_back(i);}
    FOR(i, N){V.push_back(VECII{init});}

    for(LL k = 0; k < N-1; k++)
    {
        VECII newV;
        // FOR(i, N)
        {
            newV.push_back(V.back()[0]);
            for(LL j = 1; j < N;++j)
            {
                if(D){P(k, heads[j],V.back().size());}
                LL maxScore = 0;
                VECI maxVector;
                for(LL i = 0; i < V.back().size(); ++i)
                {
                    // FOR(ii, V[i].size())
                    // LL ii = V[i].size() - 1;
                    {
                        if(i == j) continue;
                        auto copy = V.back()[i];
                        if(D){P_PER(copy);P(heads[i], i, j);}
                        auto it = std::find(BE(copy), j);
                        if(it == copy.end()){P_LINE;exit(1);}
                        copy.erase(it);
                        LL shift = copy.size() - k;
                        if(shift < 0 || shift > copy.size()){P(shift, k, copy.size());P_LINE;exit(1);}
                        it = copy.begin() + shift;
                        copy.insert(it, j);
                        auto score = countScore(copy);
                        if(D){P_PER(copy);P(score.first);}
                        if(/*score.second > 0 &&*/ score.first > maxScore)
                        {
                            maxScore = score.first;
                            maxVector = copy;
                        }
                    }
                }
                newV.push_back(maxVector);
            }
        }
        V.push_back(newV);
        if(D){for(auto& v : V){P_VEC(V);}}
    }

    LL resScore = 0;
    LL counter{};
    for(auto& k : V)
    {
        for(auto j: k)
        {
            auto jScore = countScore(j);

            if(D){P_PER(j);}
            if(D){P(jScore.first);}
            if(resScore < jScore.first)
            {
                resScore = jScore.first;
                res = j;
            }
        }

        counter++;
        if(D){P(counter, resScore);}
    }

    return res;
}


VECI calc2(VECI path, VECI init, LL time)
{
    // P_VEC(path);
    VECI res;
    LL N = heads.size();
    LL INF = 99999999;
    std::vector<VECII> V{VECII{}};
    // VECI init{0,1,14,6,7,4,13,2,5,10,15,12,8,9,11,3};
    // FOR(i, N){init.push_back(i);}
    FOR(i, N){V.push_back(VECII{init});}

    for(LL k = 0; k < N-1; k++)
    {
        VECII newV;
        // FOR(i, N)
        {
            newV.push_back(V.back()[0]);
            for(LL j = 1; j < N;++j)
            {
                if(D){P(k, heads[j],V.back().size());}
                LL maxScore = 0;
                VECI maxVector;
                for(LL i = 0; i < V.back().size(); ++i)
                {
                    // FOR(ii, V[i].size())
                    // LL ii = V[i].size() - 1;
                    {
                        if(i == j) continue;
                        auto copy = V.back()[i];
                        if(D){P_PER(copy);P(heads[i], i, j);}
                        auto it = std::find(BE(copy), j);
                        if(it == copy.end()){P_LINE;exit(1);}
                        copy.erase(it);
                        LL shift = copy.size() - k;
                        if(shift < 0 || shift > copy.size()){P(shift, k, copy.size());P_LINE;exit(1);}
                        it = copy.begin() + shift;
                        copy.insert(it, j);
                        auto score = countScore2(copy);
                        if(D){P_PER(copy);P(score.first);}
                        if(/*score.second > 0 &&*/ score.first > maxScore)
                        {
                            maxScore = score.first;
                            maxVector = copy;
                        }
                    }
                }
                newV.push_back(maxVector);
            }
        }
        V.push_back(newV);
        if(D){for(auto& v : V){P_VEC(V);}}
    }

    LL resScore = 0;
    LL counter{};
    for(auto& k : V)
    {
        for(auto j: k)
        {
            auto jScore = countScore2(j);

            if(D){P_PER(j);}
            if(D){P(jScore.first);}
            if(resScore < jScore.first)
            {
                resScore = jScore.first;
                res = j;
            }
        }

        counter++;
        if(D){P(counter, resScore);}
    }

    return res;
}
// LL brute()

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
    // if(D)
    {
        P_VEC(heads);
        P_VEC(graph);
    }

    VECI init;
    FOR(i, graph.size()){init.push_back(i);}
    VECI newPath = init, path;
    do
    {
        std::swap(path, newPath);
        newPath = calc({0}, path, 0);
    }while(path != newPath);

    auto sc = countScore(path);
    if(D){P_VEC(path);}
    while(sc.second < 0)
    {
        path.pop_back();
        sc = countScore(path);
        if(D)
        {
            P_VEC(path);
            P(sc.first, sc.second);
        }
    }

    score = countScore(path).first;

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    D = false;
    maxTime = 26;

    newPath = init;
    do
    {
        std::swap(path, newPath);
        newPath = calc2({0}, path, 0);
    }while(path != newPath);
    sc = countScore2(path);

    D = true;
    if(D){P_VEC(path);}
    while(sc.second < 0)
    {
        path.pop_back();
        sc = countScore2(path);
        if(D)
        {
            P_VEC(path);
            P(sc.first, sc.second);
        }
    }

    score = countScore2(path).first;

    P_RR("Part2: %lld\n", score);
    return 0;
}
