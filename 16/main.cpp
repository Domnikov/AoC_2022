#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
bool D = true;
using INT = __int128;

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
    for(int i{}; i < in.size();i++ )
    {

    }

    P_RR("Part1: %lld\n", score);
//========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
