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

LL x, y, X, Y;
LL mx = 1;
LL my = 0;
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
        switch(dir)
        {
            case up   : dir = left ; break;
            case down : dir = right; break;
            case left : dir = down ; break;
            case right: dir = up   ; break;
        }
    }
    else if(cmds[0] == 'R')
    {
        switch(dir)
        {
            case up   : dir = right; break;
            case down : dir = left ; break;
            case left : dir = up   ; break;
            case right: dir = down ; break;
        }
    }
    else
    {
        return false;
    }
    switch(dir)
    {
        case up   : mx =  0; my = -1; break;
        case down : mx =  0; my =  1; break;
        case left : mx = -1; my =  0; break;
        case right: mx =  1; my =  0; break;
    }
    cmds = cmds.substr(1);
    return true;
}

int main(int argc, char** argv)
{
    LL score = 0;

    x = in[1].find('.');
    y = 0;
    X = in[1].size();
    Y = in.size()-2;

    P(in[1],x, y, X, Y, in[y][x]);

    FOR(i, in.size()-2)
    {
        auto s = in[i];
        P(s);
    }

    bool isNext = true;
    while(isNext)
    {
        auto num = getCmdNum();
        P(x, y, num, mx, my);
        FOR(i, num)
        {
            P(i,in[y+my][x+mx]);
            if(in[y+my][x+mx] == '.' || in[y+my][x+mx] == 'o')
            {
                y += my;
                x += mx;
                in[y][x] = 'o';
            }
        }
        isNext = changeDir();
    }

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
