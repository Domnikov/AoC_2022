#define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();

int check(char c)
{
    return -1;
}

ULL left(ULL R, ULL C)
{
    int height = in[R][C];
    ULL res = 0;
    // for(ULL c = C-1; c >= 0; --c)
    // {
    //     if(in[R][c] < height) res++;
    // }
    return res;
}


ULL right(ULL R, ULL C)
{
    if(C == in[R].size()-1)
        return 0;
    int height = in[R][C];
    ULL res = 0;
    // for(ULL c = C+1; c < in[R].size(); c++)
    // {
    //     if(in[R][c] < height) res++;
    // }
    return res;
}


ULL top(ULL R, ULL C)
{
    int height = in[R][C];
    ULL res = 0;
    // for(ULL r = R-1; r >= 0; --r)
    // {
    //     if(in[r][C] < height) res++;
    // }
    return res;
}


ULL bottom(ULL R, ULL C)
{
    if(R == in.size()-1)
        return 0;
    int height = in[R][C];
    ULL res = 0;
    // for(ULL r = R+1; r < in.size(); r++)
    // {
    //     if(in[r][C] < height) res++;
    // }
    return res;
}


int main(int argc, char** argv)
{
    ULL score = 0;

    FOR(r,in.size())
    {
        FOR(c,in[r].size())
        {
            score = std::max(score, left(r,c)*right(r,c)*top(r,c)*bottom(r,c));
        }
    }

    P(score);
}

