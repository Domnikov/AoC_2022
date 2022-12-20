// #define TEST

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

bool D = false;


int main(int argc, char** argv)
{
    LL score = 0;
    {
        std::vector<LL> list;
        std::transform(BE(in), std::back_inserter(list), [](auto& a){return stoi(a);});
        std::vector<LL> moved(list.size(), -1);

        LL size = list.size()-1;
        FOR(i, list.size())
        {
            if(moved[i] < 0 && list[i] != 0)
            {
                LL num = list[i];
                LL pos = (1000*size + i + num)%size;
                if(pos == 0){pos = size;}
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
        size = list.size();
        LL beg = std::distance(list.begin(), std::find(BE(list), 0));

        auto n1k = list[(beg+1000)%size];
        auto n2k = list[(beg+2000)%size];
        auto n3k = list[(beg+3000)%size];
        score = n1k+n2k+n3k;
        P_RR("Part1: %lld\n", score);
    }
    //========================================================
    score = 0;
    {
        D = false;
        std::vector<INT> list;
        INT K = 811589153;
        std::transform(BE(in), std::back_inserter(list), [K](auto& a){return K*static_cast<INT>(stoll(a));});
        std::vector<LL> moved(list.size(), -1);
        std::vector<LL> order;
        std::generate_n(std::back_inserter(order), list.size(), [n = 0] () mutable { return n++; });
        std::vector<LL> small;
        std::transform(BE(list), std::back_inserter(small), [size = list.size()-1](auto& a){
                auto res = a;
                INT size1K = size*1000;
                INT sz = size;
                // if(res < 0) {res -= (res/size)*size;}
                while(res < 0){res += size1K;}
                return res%sz;
                // return(1000*size + res%size)%size;
                });

        ULL size = list.size()-1;
        if(D)P_VEC(list);
        FOR(n, 10){
            P(n);
        FOR(ii, list.size())
        {
            LL i = std::distance(order.begin(), std::find(BE(order), ii));
            if(/*moved[i] < 0 &&*/ list[i] != 0)
            {
                if(D)P_VEC(list);
                LL num = list[i];
                LL numSmall = small[i];
                LL pos = (1000*size + i + numSmall)%size;
                // LL pos = (numSmall+i)%size;
                if(pos == 0){pos = size;}
                if(D)P(i, num, numSmall, pos);
                list.erase(list.begin() + i);
                moved.erase(moved.begin() + i);
                order.erase(order.begin() + i);
                small.erase(small.begin() + i);

                    list.insert(list.begin()+pos, num);
                    moved.insert(moved.begin()+pos, i);
                    order.insert(order.begin()+pos, ii);
                    small.insert(small.begin()+pos, numSmall);
            }
        }
        P_RR("%d\n", n);
        // if(D)P_VEC(list);
        }
        size = list.size();
        LL beg = std::distance(list.begin(), std::find(BE(list), 0));

        auto n1k = list[(beg+1000)%size];
        auto n2k = list[(beg+2000)%size];
        auto n3k = list[(beg+3000)%size];
        score = n1k+n2k+n3k;
    }

    P_RR("Part2: %lld\n", score);
    return 0;
}
