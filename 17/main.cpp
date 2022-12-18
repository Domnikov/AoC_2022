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

std::deque<S> C{8000, S(7, ' ') };

bool canMove(LL x, LL y, LL shape)
{
    auto& sh = F[shape];
    if(x < 0)                           {return false;}
    if( (x+sh[0].size()) > C[0].size() ){return false;}
    if( (y + sh.size()) > C.size() )    {return false;}

    for(LL xx = 0; xx < sh[0].size(); xx++)
    {
        for(LL yy = 0; yy < sh.size(); yy++)
        {
            if(sh[yy][xx] == '#' && C[y+yy][x+xx] == '#')
            {
                return false;
            }
        }
    }
    return true;
}

void fix(LL x, LL y, LL shape, char c = '#')
{
    auto& sh = F[shape];
    // P(C.size(), x, y, shape, sh[0].size(), sh.size());
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
    std::deque<S> copy;
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


LL sim(LL N)
{
    LL cmd = 0;
    LL height = C.size();
    LL cuts{};
    LL frame = 100;
    LL maxFrames = 4;
    S templ(7, ' ');
    FOR(n, N)
    {
        auto shape = n%F.size();
        LL y = height - 3 - F[shape].size();
        LL x = 2;
        bool stopped = false;
        while(!stopped)
        {
            char c = in[0][(cmd++)%in[0].size()];
            LL newX = (c == '<') ? x-1 : x+1;
            // if(D){draw(y, x, y, shape);P(c);}
            if(canMove(newX, y, shape))
            {
                x = newX;
            }
            // if(D)draw(y, x, y, shape);
            if(canMove(x, y+1, shape))
            {
                y++;
            }
            else
            {
                stopped = true;
                height = std::min(y, height);
                fix(x, y, shape);
                if((C.size() - height) > maxFrames*frame)
                {
                    FOR(i, frame)
                    {
                        C.pop_back();
                        C.push_front(templ);
                    }
                    cuts += 1;
                    height += frame;
                }
            }
        }
        if(D)draw(height);
    }
    return (C.size() - height) + cuts * frame;
}

int main(int argc, char** argv)
{
    LL score = C.size();
    D = false;

    score = sim(2022);

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;
    D = false;

    LL NNN = 100;//0000000000;
    FOR(n, NNN)
    {
        static LL cnt{};
        static LL ctr = 1;
        if(cnt++ > ctr){P(ctr);P(NNN);ctr *= 10;}
        asm("");
    }

    P_RR("Part2: %lld\n", score);
    return 0;
}
