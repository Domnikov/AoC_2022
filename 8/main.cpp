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
        char max = 0;
        FOR(c,in[r].size())
        {
            if(in[r][c] > max)
            {
                // if(r != 0 && c != 0 && r < in.size()-1 && c < in[0].size()-1) P(">",r,c,in[r][c],max);
                max = in[r][c];
                vis.emplace(std::pair<ULL,ULL>{r,c});
            }
            // else break;
        }
        max = 0;
        for(int c = in[r].size()-1; c >= 0; --c)
        {
            if(in[r][c] > max)
            {
                // if(r != 0 && c != 0 && r < in.size()-1 && c < in[0].size()-1) P("<",r,c,in[r][c],max);
                max = in[r][c];
                vis.emplace(std::pair<ULL,ULL>{r,c});
            }
            // else break;
        }
    }
    P(" ");

    FOR(c,in[0].size())
    {
        char max = 0;
        FOR(r,in.size())
        {
            if(in[r][c] > max)
            {
                // if(r != 0 && c != 0 && r < in.size()-1 && c < in[0].size()-1) P(r,c,in[r][c],max);
                max = in[r][c];
                vis.emplace(std::pair<ULL,ULL>{r,c});
            }
            // else break;
        }
        max = 0;
        for(int r = in.size()-1; r >= 0; --r)
        {
            if(in[r][c] > max)
            {
                // if(r != 0 && c != 0 && r < in.size()-1 && c < in[0].size()-1) P(r,c,in[r][c],max);
                max = in[r][c];
                vis.emplace(std::pair<ULL,ULL>{r,c});
            }
            // else break;
        }
    }
    P(" ");

    for(auto v : vis)
    {
        ULL r = v.first;
        ULL c = v.second;
        if(r != 0 && c != 0 && r < in.size()-1 && c < in[0].size()-1)
            P(r,c,in[r][c]);
    }


    P(vis.size());
    P(score);
}

