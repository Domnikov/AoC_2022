#define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif


int check(char c)
{
    return -1;
}


int main(int argc, char** argv)
{
    auto in = getInput();
    ULL score = 0;

    std::set<std::pair<ULL,ULL>> vis;

    FOR(r,in.size())
    {
        ULL max = 0;
        FOR(c,in.size())
        {
            if(in[r][c] > max)
            {
                max = in[r][c];
                vis.emplace(std::pair<ULL,ULL>{r,c});
            }
            else break;
        }
        max = 0;
        for(int c = in.size()-1; c >= 0; --c)
        {
            if(in[r][c] > max)
            {
                max = in[r][c];
                vis.emplace(std::pair<ULL,ULL>{r,c});
            }
            else break;
        }
    }

    for(auto c : vis)
    {
        P(c.first,c.second);
    }


    P(vis.size());
    P(score);
}

