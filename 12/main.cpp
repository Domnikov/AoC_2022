// #define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
int score = 0;



std::set<std::pair<int,int>> inv(int X, int Y, char cur)
{
    std::set<std::pair<int,int>> res;
    for(int y = std::max<int>(0, Y-1); y <= std::min<int>(Y+1, in.size());y++)
        for(int x = std::max<int>(0, X-1); x <= std::min<int>(X+1, in[y].size());x++)
        {
            if(x != X && y != Y && ((abs(X-x)+abs(Y-y)) ==1))
            {
                if( (in[y][x]-cur) == 1)
                {
                    res.emplace(std::make_pair(x,y));
                }
                if(in[y][x] == 'E')
                {
                    P(score);
                    exit(0);
                }
            }
        }
    return res;
}

int main(int argc, char** argv)
{
    int score = 0;
    std::set<std::pair<int,int>> loc;
    std::set<std::pair<int,int>> next;

    FOR(y, in.size())
    {
        if(auto x = in[y].find('S') != S::npos)
        {
            x = x-1;
            P(x,y);
            loc.emplace(std::make_pair(x,y));
            break;
        }
    }
    char cur = 'a'-1;


    FOR(n,400)
    {
        score++;
        for(auto& l:loc)
        {
            auto res = inv(l.first, l.second, cur);
            std::copy(BE(res), std::inserter(next, next.begin()));
        }
        loc = next;
        next.clear();
    }
    P_RR("NOT FOUND\n");
}

