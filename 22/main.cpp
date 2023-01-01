// #define TEST

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
bool D = true;

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

void flipUp   ()
{
    auto posDot = std::distance(std::find_if(in.rbegin()+2, in.rend(), [](const auto& s){return s[x]== '.';}), in.rend()-1);
    auto posDsh = std::distance(std::find_if(in.rbegin()+2, in.rend(), [](const auto& s){return s[x]== '#';}), in.rend()-1);
    auto posOoo = std::distance(std::find_if(in.rbegin()+2, in.rend(), [](const auto& s){return s[x]== 'o';}), in.rend()-1);

    if(posDsh < posDot || posDsh < posOoo)
    {
        y = std::max(posDot, posOoo);
        in[y][x] = 'o';
    }
}


void flipDown ()
{
    auto posDot = std::distance(in.begin(), std::find_if(in.begin(), in.end()-2, [](const auto& s){return s[x]== '.';}));
    auto posDsh = std::distance(in.begin(), std::find_if(in.begin(), in.end()-2, [](const auto& s){return s[x]== '#';}));
    auto posOoo = std::distance(in.begin(), std::find_if(in.begin(), in.end()-2, [](const auto& s){return s[x]== 'o';}));

    if(posDsh > posDot || posDsh > posOoo)
    {
        y = std::min(posDot, posOoo);
        in[y][x] = 'o';
    }
}


void flipLeft ()
{
    auto posDot = in[y].rfind('.');
    auto posDsh = in[y].rfind('#');
    auto posOoo = in[y].rfind('o');

    if(posDsh < posDot || posDsh < posOoo)
    {
        x = std::max(posDot, posOoo);
        in[y][x] = 'o';
    }
}


void flipRight()
{
    auto posDot = in[y].find('.');
    auto posDsh = in[y].find('#');
    auto posOoo = in[y].find('o');

    if(posDsh > posDot || posDsh > posOoo)
    {
        x = std::min(posDot, posOoo);
        in[y][x] = 'o';
    }
}


int main(int argc, char** argv)
{
    LL score = 0;

    x = in[1].find('.')-1;
    y = 1;
    X = in[1].size();
    Y = in.size()-2;

    bool isNext = true;
    while(isNext)
    {
        auto num = getCmdNum();
        auto f = dir == right ? 'R' : (dir == down ? 'D' : (dir == left ? 'L' : 'U'));
        if(in[y][x] == 'X')in[y][x]='o';
        FOR(i, num)
        {
            auto c = in[y+my][x+mx];
            if(c == '.' || c == 'o')
            {
                y += my;
                x += mx;
                in[y][x] = 'o';
            }
            else if(c == ' ' || c == '_')
            {
                switch(dir)
                {
                    case DIR::up   : flipUp   (); break;
                    case DIR::down : flipDown (); break;
                    case DIR::left : flipLeft (); break;
                    case DIR::right: flipRight(); break;
                }
            }
        }
        isNext = changeDir();
        in[y][x]='X';
    }
    in[y][x]='o';


    auto f = dir == right ? 0 : (dir == down ? 1 : (dir == left ? 2 : 3));
    auto row = y;
    auto col = x;

    score = 1000*row + 4*col + f;

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    cmds = *(in.end()-1);

    dir = DIR::right;

    x = in[1].find('.')-1;
    y = 1;
    X = in[1].size();
    Y = in.size()-2;

    isNext = true;
    while(isNext)
    {
        auto num = getCmdNum();
        auto f = dir == right ? 'R' : (dir == down ? 'D' : (dir == left ? 'L' : 'U'));
        if(in[y][x] == 'X')in[y][x]='o';
        FOR(i, num)
        {
            auto c = in[y+my][x+mx];
            if(c == '.' || c == 'o')
            {
                y += my;
                x += mx;
                in[y][x] = 'o';
            }
            else if(c == ' ' || c == '_')
            {
                switch(dir)
                {
                    case DIR::up   : flipUp   (); break;
                    case DIR::down : flipDown (); break;
                    case DIR::left : flipLeft (); break;
                    case DIR::right: flipRight(); break;
                }
            }
        }
        isNext = changeDir();
        in[y][x]='X';
    }


    f = dir == right ? 0 : (dir == down ? 1 : (dir == left ? 2 : 3));
    row = y;
    col = x;

    score = 1000*row + 4*col + f;


    P_RR("Part2: %lld\n", score);
    return 0;
}
