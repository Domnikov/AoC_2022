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

VECII cubes;


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
        P(i);
        P_VEC(splitStr(i, ','));
        VECSTOA(splitStr(i, ','), vec);
        P_VEC(vec);
        cubes.push_back(vec);
        minX = std::min(minX, vec[0]);
        minY = std::min(minY, vec[1]);
        minZ = std::min(minZ, vec[2]);
        maxX = std::max(maxX, vec[0]);
        maxY = std::max(maxY, vec[1]);
        maxZ = std::max(maxZ, vec[2]);
    }
    P( minX, minY, minZ, maxX, maxY, maxZ);

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
