#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

#include<queue>
#include <list>

auto in = getInput();

enum DIR
{
    NN, WW, EE, SS, DIR_CNT
};

std::map<std::pair<LL,LL>, VECI> elfs;

void checkLand()
{
    if(in[          0].find('#') != std::string::npos)                            {in.insert(in.begin(), S(in[          0].size(), '.'));}
    if(in[in.size()-1].find('#') != std::string::npos)                            {in.insert(in.end  (), S(in[in.size()-1].size(), '.'));}
    if(std::any_of(in.begin(), in.end(), [](const auto& s){return s[         0] == '#';})) {std::for_each(in.begin(), in.end(), [](auto& s){s.insert(s.begin(), '.');});}
    if(std::any_of(in.begin(), in.end(), [](const auto& s){return s[s.size()-1] == '#';})) {std::for_each(in.begin(), in.end(), [](auto& s){s.insert(s.end  (), '.');});}
}


LL checkScore()
{
    auto countDashs = [](LL r, char c) -> LL{LL rr = c == '#'; return r+rr;};
    LL res = std::accumulate(in.begin()+1, in.end()-1, 0, [countDashs](const auto& r, const auto& s){return r + std::accumulate(s.begin()+1, s.end()-1, 0, countDashs );});
    return res;
}

LL countEmpty()
{
    return (in.size()-2)*(in[0].size()-2) - checkScore();
}

LL ifN(std::pair<LL,LL> p)
{
    auto [y,x] = p;
    LL nw = in[y-1][x-1] == '.';
    LL nn = in[y-1][x  ] == '.';
    LL ne = in[y-1][x+1] == '.';
    return (nw+nn+ne) == 0;
}

LL ifS(std::pair<LL,LL> p)
{
    auto [y,x] = p;
    LL nw = in[y+1][x-1] == '.';
    LL nn = in[y+1][x  ] == '.';
    LL ne = in[y+1][x+1] == '.';
    return (nw+nn+ne) == 0;
}

LL ifW(std::pair<LL,LL> p)
{
    auto [y,x] = p;
    LL nw = in[y-1][x-1] == '.';
    LL nn = in[y  ][x-1] == '.';
    LL ne = in[y+1][x-1] == '.';
    return (nw+nn+ne) == 0;
}

LL ifE(std::pair<LL,LL> p)
{
    auto [y,x] = p;
    LL nw = in[y-1][x+1] == '.';
    LL nn = in[y  ][x+1] == '.';
    LL ne = in[y+1][x+1] == '.';
    return (nw+nn+ne) == 0;
}

int main(int argc, char** argv)
{
    LL score = 0;
    checkLand();
    FOR(y, in.size())
    {
        FOR(x, in[y].size())
        {
            if(in[y][x] == '#')
            {
                elfs[std::make_pair(y, x)] = VECI(DIR_CNT, 0LL);
            }
        }
    }
    FOR(i, 10)
    {
        std::map<std::pair<LL,LL>, std::pair<LL,LL>> plan;
        FOR(y, in.size())
        {
            FOR(x, in[y].size())
            {
                if(in[y][x] == '#')
                {
                }
            }
        }
        checkLand();
    }

    score = countEmpty();
    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
