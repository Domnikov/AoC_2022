#define TEST

#ifdef TEST
#define GRID
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;

std::set<std::tuple<LL,LL,LL>> cubes;

std::map<std::tuple<LL,LL,LL>, VECI> surf;

enum Sides{L,R,U,D,F,B};

std::tuple<LL,LL,LL> lub(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y+1, z+1};}
std::tuple<LL,LL,LL> lcb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y  , z+1};}
std::tuple<LL,LL,LL> ldb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y-1, z+1};}
std::tuple<LL,LL,LL> cub(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y+1, z+1};}
std::tuple<LL,LL,LL> ccb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y  , z+1};}
std::tuple<LL,LL,LL> cdb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y-1, z+1};}
std::tuple<LL,LL,LL> rub(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y+1, z+1};}
std::tuple<LL,LL,LL> rcb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y  , z+1};}
std::tuple<LL,LL,LL> rdb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y-1, z+1};}
std::tuple<LL,LL,LL> luc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y+1, z  };}
std::tuple<LL,LL,LL> lcc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y  , z  };}
std::tuple<LL,LL,LL> ldc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y-1, z  };}
std::tuple<LL,LL,LL> cuc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y+1, z  };}
std::tuple<LL,LL,LL> ccc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y  , z  };}
std::tuple<LL,LL,LL> cdc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y-1, z  };}
std::tuple<LL,LL,LL> ruc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y+1, z  };}
std::tuple<LL,LL,LL> rcc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y  , z  };}
std::tuple<LL,LL,LL> rdc(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y-1, z  };}
std::tuple<LL,LL,LL> luf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y+1, z-1};}
std::tuple<LL,LL,LL> lcf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y  , z-1};}
std::tuple<LL,LL,LL> ldf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y-1, z-1};}
std::tuple<LL,LL,LL> cuf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y+1, z-1};}
std::tuple<LL,LL,LL> ccf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y  , z-1};}
std::tuple<LL,LL,LL> cdf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y-1, z-1};}
std::tuple<LL,LL,LL> ruf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y+1, z-1};}
std::tuple<LL,LL,LL> rcf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y  , z-1};}
std::tuple<LL,LL,LL> rdf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y-1, z-1};}




void add(VECI& a, const VECI& b)
{
    FOR(i, a.size()){a[i] += b[i];}
}

VECI sides(std::tuple<LL,LL,LL> p, std::set<std::tuple<LL,LL,LL>>& vis)
{
    VECI vec = VECI{0,0,0,0,0,0};
    if(!vis.count(p) && surf.count(p))
    {
        vis.insert(p);
        auto [x, y, z] = p;
        P(x, y, z);
        vec = surf[p];
        // P_VEC(vec);
        add(vec, sides(lcc(p), vis));
        add(vec, sides(rcc(p), vis));
        add(vec, sides(cuc(p), vis));
        add(vec, sides(cdc(p), vis));
        add(vec, sides(ccf(p), vis));
        add(vec, sides(ccb(p), vis));
    }
    return vec;
}

std::set<std::tuple<LL,LL,LL>> inside(std::tuple<LL,LL,LL> p)
{
    std::set<std::tuple<LL,LL,LL>> vis;
    auto vec = sides(p, vis);
    LL resRL = vec[R] - vec[L];
    LL resUD = vec[U] - vec[D];
    LL resFB = vec[F] - vec[B];
    // bool isInside = !resRL && !resUD && !resFB && vec[R] > 0 && vec[L] > 0 && vec[U] > 0 && vec[D] > 0 && vec[F] > 0 && vec[B] > 0;
    bool isInside = (vec[R] + vec[L] + vec[U] + vec[D] + vec[F] + vec[B]) > vis.size();
    if(isInside)
    {
        P_RR("Inside:\n");
        auto [x, y, z] = p;
        P(x, y, z);
        P_VEC(vec);
        // for(auto v : vis) {auto [xx, yy, zz] = v; P(xx, yy, zz);P_VEC(surf[v]);}
    }
    return (isInside) ? vis : std::set<std::tuple<LL,LL,LL>>{};
}

int main(int argc, char** argv)
{
    LL score = 0;

    for(auto& i : in)
    {
        VECI vec;
        auto vecS = splitStr(i, ',');
        VECSTOA(vecS, vec);
        cubes.emplace(vec[0],vec[1],vec[2]);
    }
    VECI init{{0,0,0,0,0,0}};
    for(auto cb : cubes)
    {
        auto [x,y,z] = cb;

        {auto t = lub(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = lcb(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ldb(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = cub(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ccb(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = cdb(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = rub(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = rcb(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = rdb(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = luc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = lcc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ldc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = cuc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ccc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = cdc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ruc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = rcc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = rdc(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = luf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = lcf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ldf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = cuf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ccf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = cdf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = ruf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = rcf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}
        {auto t = rdf(cb);if(!cubes.count(t) && !surf.count(t)){surf.emplace(t,init);} P(__LINE__, surf.size());}

        if(!cubes.count(lcc(cb))){if(surf.count(lcc(cb)) == 0){surf.emplace(lcc(cb),init);}surf[lcc(cb)][L]++;score++;} P(surf.size());
        if(!cubes.count(rcc(cb))){if(surf.count(rcc(cb)) == 0){surf.emplace(rcc(cb),init);}surf[rcc(cb)][R]++;score++;} P(surf.size());
        if(!cubes.count(cuc(cb))){if(surf.count(cuc(cb)) == 0){surf.emplace(cuc(cb),init);}surf[cuc(cb)][U]++;score++;} P(surf.size());
        if(!cubes.count(cdc(cb))){if(surf.count(cdc(cb)) == 0){surf.emplace(cdc(cb),init);}surf[cdc(cb)][D]++;score++;} P(surf.size());
        if(!cubes.count(ccf(cb))){if(surf.count(ccf(cb)) == 0){surf.emplace(ccf(cb),init);}surf[ccf(cb)][F]++;score++;} P(surf.size());
        if(!cubes.count(ccb(cb))){if(surf.count(ccb(cb)) == 0){surf.emplace(ccb(cb),init);}surf[ccb(cb)][B]++;score++;} P(surf.size());

    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    P(surf.size());

    std::set<std::tuple<LL,LL,LL>> insides;
    for(auto s : surf)
    {
        // auto s = std::make_pair(std::make_tuple<LL,LL,LL>(0,0,0),VECI{0,0,0,0,0,0});
        if(insides.count(s.first) == 0)
        {
            auto set = inside(s.first);
            if(set.empty())
            {
                score+= s.second[0] + s.second[1] + s.second[2] + s.second[3] + s.second[4] + s.second[5];
            }
            for(auto st : set)
            {
                auto [x, y, z] = st;
                // P(x, y, z);
                insides.insert(st);
            }
        }
    }

    P_RR("Part2: %lld\n", score);
    return 0;
}
