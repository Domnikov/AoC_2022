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

std::set<std::tuple<LL,LL,LL>> cubes;

std::map<std::tuple<LL,LL,LL>, LL> surf;





int main(int argc, char** argv)
{
    LL score = 0;
    D = false;

    LL minX = 99999;
    LL minY = 99999;
    LL minZ = 99999;
    LL maxX = 0;
    LL maxY = 0;
    LL maxZ = 0;

    for(auto& i : in)
    {
        VECI vec;
        auto vecS = splitStr(i, ',');
        VECSTOA(vecS, vec);
        cubes.emplace(vec[0],vec[1],vec[2]);
        minX = std::min(minX, vec[0]);
        minY = std::min(minY, vec[1]);
        minZ = std::min(minZ, vec[2]);
        maxX = std::max(maxX, vec[0]);
        maxY = std::max(maxY, vec[1]);
        maxZ = std::max(maxZ, vec[2]);
    }
    for(auto cb : cubes)
    {
        auto [x,y,z] = cb;
        if(!cubes.count({x  , y-1, z  })){surf[{x  , y-1, z  }]++;score++;if(surf[{x  , y-1, z  }] == 6){surf.erase({x  , y-1, z  });}}
        if(!cubes.count({x-1, y  , z  })){surf[{x-1, y  , z  }]++;score++;if(surf[{x-1, y  , z  }] == 6){surf.erase({x-1, y  , z  });}}
        if(!cubes.count({x+1, y  , z  })){surf[{x+1, y  , z  }]++;score++;if(surf[{x+1, y  , z  }] == 6){surf.erase({x+1, y  , z  });}}
        if(!cubes.count({x  , y+1, z  })){surf[{x  , y+1, z  }]++;score++;if(surf[{x  , y+1, z  }] == 6){surf.erase({x  , y+1, z  });}}
        if(!cubes.count({x  , y  , z-1})){surf[{x  , y  , z-1}]++;score++;if(surf[{x  , y  , z-1}] == 6){surf.erase({x  , y  , z-1});}}
        if(!cubes.count({x  , y  , z+1})){surf[{x  , y  , z+1}]++;score++;if(surf[{x  , y  , z+1}] == 6){surf.erase({x  , y  , z+1});}}
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    D = false;
    P(surf.size());

    for(auto s : surf)
    {
        score+= s.second;
    }


    P_RR("Part2: %lld\n", score);
    return 0;
}
