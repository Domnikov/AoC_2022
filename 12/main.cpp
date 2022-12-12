// #define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
int score = 0;
#include <unordered_set>


struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};
std::unordered_set<std::pair<int,int>, pair_hash> loc;

std::unordered_set<std::pair<int,int>, pair_hash> inv(int X, int Y)
{
    std::unordered_set<std::pair<int,int>, pair_hash> res;
    char cur = in[Y][X];
    // if(cur == 'l')P(in[Y-1][X],in[Y+1][X],in[Y][X-1],in[Y][X+1]);
    for(int y = std::max<int>(0, Y-1); y <= std::min<int>(Y+1, in.size()-1);y++)
        for(int x = std::max<int>(0, X-1); x <= std::min<int>(X+1, in[y].size()-1);x++)
        {
            if(((abs(X-x)+abs(Y-y)) ==1))
            {
            int dif = in[y][x]-cur;
                // if(cur == 'l'){ P_RR("%d[%c] ", dif, in[y][x]);}
                if( (in[y][x]-cur) < 2)
                {
                    // P(x,y);
                    res.emplace(std::make_pair(x,y));
                }
                if(in[y][x] == 'E' && cur == 'z')
                {
                    FOR(y, in.size())
                        FOR(x,in[y].size())
                        {
                            if(std::find(BE(loc), std::make_pair<int,int>(x,y)) != loc.end()) in[y][x] = in[y][x] - 'a' + 'A';
                        }
                    P(score);
                    exit(0);
                }
            }
        }
    return res;
}

int main(int argc, char** argv)
{
    std::unordered_set<std::pair<int,int>, pair_hash> next;

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


    char max = 'a',min = 'z';
    FOR(n,4000)
    {
        P(n, loc.size());
        score++;
        for(auto& l:loc)
        {
            auto res = inv(l.first, l.second);
            min = std::min(min, in[l.second][l.first]);
            max = std::max(max, in[l.second][l.first]);
            std::copy(BE(res), std::inserter(next, next.begin()));
        }
        std::copy(BE(next), std::inserter(loc, loc.begin()));
        next.clear();
    }
    FOR(y, in.size())
        FOR(x,in[y].size())
        {
            if(std::find(BE(loc), std::make_pair<int,int>(x,y)) != loc.end()) in[y][x] = in[y][x] - 'a' + 'A';
        }
    for(auto& line: in)
    {
        P(line);
    }
    P(min, max);
    P_RR("NOT FOUND\n");
}

