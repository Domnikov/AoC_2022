#define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
int score = 0;



std::set<std::pair<int,int>> inv(int X, int Y)
{
    std::set<std::pair<int,int>> res;
    char cur = in[Y][X];
    for(int y = std::max<int>(0, Y-1); y <= std::min<int>(Y+1, in.size()-1);y++)
        for(int x = std::max<int>(0, X-1); x <= std::min<int>(X+1, in[y].size()-1);x++)
        {
            if(((abs(X-x)+abs(Y-y)) ==1))
            {
            int dif = in[y][x]-cur;
            // P_RR("%d[%c] ", dif, in[y][x]);
                if( (in[y][x]-cur) == 1 || in[y][x] == cur)
                {
                    // P(x,y);
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
            in[y][x] = 'a'-1;
            break;
        }
    }


    FOR(n,40)
    {
        P(n);
        score++;
        for(auto& l:loc)
        {
            auto res = inv(l.first, l.second);
            P(res.size());
            std::copy(BE(res), std::inserter(next, next.begin()));
        }
        loc = next;
        next.clear();
    }
    P_RR("NOT FOUND\n");
}

