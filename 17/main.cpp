#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

auto in = getInput();
bool D = true;
using INT = __int128;
using VECC = std::vector<char>;

VECSS F{
{"####"}
,
{" # ",
"###",
" # "}
,
{
"  #",
"  #",
"###"}
,
{"#",
"#",
"#",
"#"}
,
{"##",
"##"}};

VECS C{2022, S(7, ' ') };

bool canMove(LL x, LL y, LL shape)
{
    auto& sh = F[shape];
    P(C.size(), x, y, shape, sh[0].size(), sh.size());
    if(x < 0)                           {P(__LINE__);return false;}
    if( (x+sh[0].size()) > C[0].size() ){P(__LINE__);return false;}
    if( (y + sh.size()) > C.size() )    {P(__LINE__);return false;}

    for(LL xx = 0; xx < sh[0].size(); xx++)
    {
        for(LL yy = 0; yy < sh.size(); yy++)
        {
            if(sh[yy][xx] == '#' && C[y+yy][x+xx] == '#')
            {
                P(__LINE__);
                return false;
            }
        }
    }
    P(__LINE__);
    return true;
}

void fix(LL x, LL y, LL shape, char c = '#')
{
    auto& sh = F[shape];
    P_LINE;
    P(C.size(), x, y, shape, sh[0].size(), sh.size());
    P_LINE;
    for(LL xx = 0; xx < sh[0].size(); xx++)
    {
    P_LINE;
        for(LL yy = 0; yy < sh.size(); yy++)
        {
    P_LINE;
            if(sh[yy][xx] == '#')
            {
    P_LINE;
                C[y+yy][x+xx] = c;
            }
    P_LINE;
        }
    P_LINE;
    }
    P_LINE;
}

void draw(LL score, LL x = -1, LL y = -1, LL shape = -1)
{
    VECS copy;
    if(shape != -1)
    {
        copy = C;
        fix(x, y, shape, '@');
    }
    for(size_t s = score; s < C.size(); s++)
    {
        P_RR("|%s|\n", C[s].c_str());
    }
    P_RR("+-------+\n");
    P(score, C.size())
    if(shape != -1)
    {
        C = copy;
    }
}

int main(int argc, char** argv)
{
    LL score = C.size();
    D = true;

    LL cmd = 0;
    FOR(n, 2)
    {
    P_LINE;
        auto shape = n%F.size();
        LL y = score - 3 - F[shape].size();
        LL x = 2;
        bool stopped = false;
    P_LINE;
        while(!stopped)
        {
    P_LINE;
            char c = in[0][cmd++];
            LL newX = (c == '<') ? x-1 : x+1;
            if(D){draw(y, x, y, shape);P(c);}
            if(canMove(newX, y, shape))
            {
                x = newX;
                P_RR("MOVE\n");
            }
            if(D)draw(y, x, y, shape);
            if(canMove(x, y+1, shape))
            {
                y++;
            }
            else
            {
                stopped = true;
                score = y;
                fix(x, y, shape);
            }
    P_LINE;
        }
    P_LINE;
        if(D)draw(score);
    P_LINE;
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
