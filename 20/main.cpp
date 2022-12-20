#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

#include<queue>
#include <list>

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;


int main(int argc, char** argv)
{
    LL score = 0;

    std::vector<LL> list;
    std::transform(BE(in), std::back_inserter(list), [](auto& a){return stoi(a);});
    std::vector<LL> moved(list.size(), -1);

    FOR(i, list.size())
    {
        P_VEC(list);
        P_VEC(moved);
        if(moved[i] < 0 && list[i] != 0)
        {
            LL num = list[i];
            LL pos = (1000*list.size() + num)%list.size();
            P(num, pos);
            list.erase(list.begin() + i);
            moved.erase(moved.begin() + i);
            if(pos > i)
            {
                list.insert(list.begin()+pos, num);
                moved.insert(moved.begin()+pos, i);
                i--;
            }
            else// if(pos < i)
            {
                list.insert(list.begin()+pos, num);
                moved.insert(moved.begin()+pos, i);
            }
        }
    }
    P_VEC(list);

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
