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


std::tuple<LL,LL,LL> u(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y-1, z  };}
std::tuple<LL,LL,LL> l(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y  , z  };}
std::tuple<LL,LL,LL> r(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y  , z  };}
std::tuple<LL,LL,LL> d(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y+1, z  };}
std::tuple<LL,LL,LL> f(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y  , z-1};}
std::tuple<LL,LL,LL> b(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y  , z+1};}

std::tuple<LL,LL,LL> lub(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y+1, z+1};}
std::tuple<LL,LL,LL> rub(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y+1, z+1};}
std::tuple<LL,LL,LL> ldb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y-1, z+1};}
std::tuple<LL,LL,LL> rdb(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y-1, z+1};}
std::tuple<LL,LL,LL> luf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y+1, z-0};}
std::tuple<LL,LL,LL> ruf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y+1, z-1};}
std::tuple<LL,LL,LL> ldf(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y-1, z-1};}
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
        {
            // auto [x, y, z] = p;
            // P(x, y, z);
            vec = surf[p];
            // P_VEC(vec);
            add(vec, sides(u(p), vis));
            add(vec, sides(l(p), vis));
            add(vec, sides(r(p), vis));
            add(vec, sides(d(p), vis));
            add(vec, sides(f(p), vis));
            add(vec, sides(b(p), vis));
        }
    }
    return vec;
}

std::set<std::tuple<LL,LL,LL>> inside(std::tuple<LL,LL,LL> p)
{
    std::set<std::tuple<LL,LL,LL>> vis;
    auto vec = sides(p, vis);
    if(p == std::make_tuple(3,3,3)) {P_VEC(vec);P(vis.size());}
    LL resRL = vec[R] - vec[L];
    LL resUD = vec[U] - vec[D];
    LL resFB = vec[F] - vec[B];
    // bool isInside = !resRL && !resUD && !resFB && vec[R] > 0 && vec[L] > 0 && vec[U] > 0 && vec[D] > 0 && vec[F] > 0 && vec[B] > 0;
    bool isInside = (vec[R] + vec[L] + vec[U] + vec[D] + vec[F] + vec[B]) > vis.size();
    if(isInside)
    {
        auto [x, y, z] = p;
        // P(x, y, z);
        P_VEC(vec);
        for(auto v : vis) {auto [xx, yy, zz] = v; P(xx, yy, zz);P_VEC(surf[v]);}
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
        if(!cubes.count(u(cb))){if(surf.count(u(cb)) == 0){surf.emplace(u(cb),init);}surf[{x  , y-1, z  }][U]++;score++;}
        if(!cubes.count(l(cb))){if(surf.count(l(cb)) == 0){surf.emplace(l(cb),init);}surf[{x-1, y  , z  }][L]++;score++;}
        if(!cubes.count(r(cb))){if(surf.count(r(cb)) == 0){surf.emplace(r(cb),init);}surf[{x+1, y  , z  }][R]++;score++;}
        if(!cubes.count(d(cb))){if(surf.count(d(cb)) == 0){surf.emplace(d(cb),init);}surf[{x  , y+1, z  }][D]++;score++;}
        if(!cubes.count(f(cb))){if(surf.count(f(cb)) == 0){surf.emplace(f(cb),init);}surf[{x  , y  , z-1}][F]++;score++;}
        if(!cubes.count(b(cb))){if(surf.count(b(cb)) == 0){surf.emplace(b(cb),init);}surf[{x  , y  , z+1}][B]++;score++;}

        if(!cubes.count(lub(cb)) && !surf.count(lub(cb))){surf.emplace(lub(cb),init);}
        if(!cubes.count(rub(cb)) && !surf.count(rub(cb))){surf.emplace(rub(cb),init);}
        if(!cubes.count(ldb(cb)) && !surf.count(ldb(cb))){surf.emplace(ldb(cb),init);}
        if(!cubes.count(rdb(cb)) && !surf.count(rdb(cb))){surf.emplace(rdb(cb),init);}
        if(!cubes.count(luf(cb)) && !surf.count(luf(cb))){surf.emplace(luf(cb),init);}
        if(!cubes.count(ruf(cb)) && !surf.count(ruf(cb))){surf.emplace(ruf(cb),init);}
        if(!cubes.count(ldf(cb)) && !surf.count(ldf(cb))){surf.emplace(ldf(cb),init);}
        if(!cubes.count(rdf(cb)) && !surf.count(rdf(cb))){surf.emplace(rdf(cb),init);}
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    P(surf.size());

    std::set<std::tuple<LL,LL,LL>> insides;
    for(auto s : surf)
    {
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
