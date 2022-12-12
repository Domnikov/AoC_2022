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

std::unordered_set<std::pair<int,int>, pair_hash> inv(int X, int Y)
{
    std::unordered_set<std::pair<int,int>, pair_hash> res;
    char cur = in[Y][X];
    for(int y = std::max<int>(0, Y-1); y <= std::min<int>(Y+1, in.size()-1);y++)
        for(int x = std::max<int>(0, X-1); x <= std::min<int>(X+1, in[y].size()-1);x++)
        {
            if(((abs(X-x)+abs(Y-y)) ==1))
            {
            int dif = in[y][x]-cur;
            // P_RR("%d[%c] ", dif, in[y][x]);
                if( abs(in[y][x]-cur) < 2)
                {
                    // P(x,y);
                    res.emplace(std::make_pair(x,y));
                }
                if(in[y][x] == 'E' && cur == 'z')
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
    std::unordered_set<std::pair<int,int>, pair_hash> loc;
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


    FOR(n,40000)
    {
        P(n, loc.size());
        score++;
        for(auto& l:loc)
        {
            auto res = inv(l.first, l.second);
            // P(res.size());
            std::copy_if(BE(res), std::inserter(next, next.begin()), [&loc](const auto& p){return std::find(BE(loc), p) == loc.end();});
        }
        loc = next;
        next.clear();
    }
    P_RR("NOT FOUND\n");
}

