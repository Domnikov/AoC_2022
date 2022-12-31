#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

#include<queue>
#include <list>

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;
bool D = false;

enum DIR
{
    up,down,left,right
};

auto cmds = *(in.end()-1);

LL x = in[0].find('.')-1;
LL y = 0;
LL X = in[0].size();
DIR dir = DIR::right;


LL getCmdNum()
{
    auto pos = std::min(cmds.size(), std::min(cmds.find('R'), cmds.find('L')));
    auto numStr = cmds.substr(0, pos);
    cmds = cmds.substr(pos);
    return stoll(numStr);
}

bool changeDir()
{
    if(cmds[0] == 'L')
    {
    }
    else if(cmds[0] == 'R')
    {
    }
    else
    {
        return false;
    }
    cmds = cmds.substr(1);
    return true;
}

int main(int argc, char** argv)
{
    LL score = 0;

    FOR(i, in.size()-2)
    {
        auto s = in[i];
        P(s);
    }



    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;



    P_RR("Part2: %lld\n", score);
    return 0;
}
