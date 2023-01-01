#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

#include<queue>
#include <list>

auto in = getInput();

void checkLand()
{
    if(in[          0].find('#') != std::string::npos)                            {in.insert(in.begin(), S(in[          0].size(), '.'));}
    if(in[in.size()-1].find('#') != std::string::npos)                            {in.insert(in.end  (), S(in[in.size()-1].size(), '.'));}
    if(std::any_of(in.begin(), in.end(), [](const auto& s){return s[         0] == '#';})) {std::for_each(in.begin(), in.end(), [](auto& s){s.insert(s.begin(), '.');});}
    if(std::any_of(in.begin(), in.end(), [](const auto& s){return s[s.size()-1] == '#';})) {std::for_each(in.begin(), in.end(), [](auto& s){s.insert(s.end  (), '.');});}
}


LL checkScore()
{
    auto countDashs = [](LL res, char c){return res + c=='#' ? 1 : 0;};
    LL res = std::accumulate(in.begin()+1, in.end()-1, 0, [countDashs](const auto& res, const auto& s){return res + std::accumulate(s.begin()+1, s.end()-1, 0, countDashs );});
    return res;
}


int main(int argc, char** argv)
{
    LL score = 0;

    P_VECV(in);
    checkLand();
    P_VECV(in);

    score = checkScore();
    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
