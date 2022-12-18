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
    for(LL xx = 0; xx < sh[0].size(); xx++)
    {
        for(LL yy = 0; yy < sh.size(); yy++)
        {
            if(sh[yy][xx] == '#')
            {
                C[y+yy][x+xx] = c;
            }
        }
    }
}

void draw(LL score, LL x = -1, LL y = -1, LL shape = -1)
{
    VECS copy;
    if(shape != -1)
    {
        copy = C;
    }
    fix(x, y, shape, '@');
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
    LL score = 0;
    D = true;

    LL cmd = 0;
    FOR(n, 1)
    {
        LL y = C.size() - (score + 4);
        LL x = 2;
        auto shape = n%F.size();
        bool stopped = false;
        while(!stopped)
        {
            char c = in[0][cmd++];
            LL newX = (x == '<') ? x-1 : x+1;
            if(D){P(c);draw(y, x, y, shape);}
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
        }
        if(D)draw(score);
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    D = false;

    P_RR("Part2: %lld\n", score);
    return 0;
}
