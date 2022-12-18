#define TEST

#ifdef TEST
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

// bool inside

std::tuple<LL,LL,LL> u(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y-1, z  };}
std::tuple<LL,LL,LL> l(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x-1, y  , z  };}
std::tuple<LL,LL,LL> r(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x+1, y  , z  };}
std::tuple<LL,LL,LL> d(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y+1, z  };}
std::tuple<LL,LL,LL> f(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y  , z-1};}
std::tuple<LL,LL,LL> b(std::tuple<LL, LL, LL> p){auto [x, y, z] = p; return {x  , y  , z+1};}

void add(VECI& a, const VECI& b)
{
    FOR(i, a.size()){a[i] += b[i];}
}

VECI sides(std::tuple<LL,LL,LL> p)
{
    VECI vec = surf.count(p) ? surf[p] : VECI{0,0,0,0,0,0};
    add(vec, sides(u(p)));
    add(vec, sides(l(p)));
    add(vec, sides(r(p)));
    add(vec, sides(d(p)));
    add(vec, sides(f(p)));
    add(vec, sides(b(p)));

    return vec;
}

bool inside(std::tuple<LL,LL,LL> p)
{
    LL res{};
    auto vec = sides(p);
    res += vec[R] - vec[L];
    res += vec[U] - vec[D];
    res += vec[F] - vec[B];
    auto [x, y, z] = p;

    P(x, y, x, res);
    return res == 0;
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
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    P(surf.size());

    for(auto s : surf)
    {
        if(!inside(s.first))
        {
            score+= s.second[0] + s.second[1] + s.second[2] + s.second[3] + s.second[4] + s.second[5];
        }
    }


    P_RR("Part2: %lld\n", score);
    return 0;
}
