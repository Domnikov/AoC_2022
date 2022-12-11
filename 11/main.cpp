#define TEST
#include <stack>

#include <functional>
#include <vector>
#include <list>
struct M
{
    M(
        std::function<int(int)> worryCalc_,
        std::function<int(int)> test_,
        int ifTrue_,
        int ifFalse_,
        std::vector<int> items_
    ):worryCalc(worryCalc_),test(test_),ifTrue(ifTrue_),ifFalse(ifFalse_)
    {
        for(auto i : items_){items.push_back(i);}
    }
    std::function<int(int)> worryCalc;
    std::function<int(int)> test;
    int ifTrue;
    int ifFalse;
    std::vector<int> items;
};
#ifdef TEST
    #include "in_test.hpp"


    std::vector<M> mm{
    {[](int old){return old*19 ;}, [](int old){return old%23 == 0;},2, 3, {79,98}},
    {[](int old){return old+6  ;}, [](int old){return old%19 == 0;},2, 0, {54, 65, 75, 74}},
    {[](int old){return old*old;}, [](int old){return old%13 == 0;},1, 3, {79, 60, 97}},
    {[](int old){return old+3  ;}, [](int old){return old%17 == 0;},0, 1, {74}},
    };

#else
    std::vector<M> mm{
    {[](int old){return old*7  ;}, [](int old){return old%19 == 0;}, 6,  4, {65, 58, 93, 57, 66}},
    {[](int old){return old+4  ;}, [](int old){return old%3  == 0;}, 7,  5, {76, 97, 58, 72, 57, 92, 82}},
    {[](int old){return old*5  ;}, [](int old){return old%13 == 0;}, 5,  1, {90, 89, 96}},
    {[](int old){return old*old;}, [](int old){return old%17 == 0;}, 0,  4, {72, 63, 72, 99}},
    {[](int old){return old+1  ;}, [](int old){return old%2  == 0;}, 6,  2, {65}},
    {[](int old){return old+8  ;}, [](int old){return old%11 == 0;}, 7,  3, {97, 71}},
    {[](int old){return old+2  ;}, [](int old){return old%5  == 0;}, 2,  1, {83, 68, 88, 55, 87, 67}},
    {[](int old){return old+5  ;}, [](int old){return old%7  == 0;}, 3,  0, {64, 81, 50, 96, 82, 53, 62, 92}},
    };

#include "in.hpp"
#endif


auto in = getInput();

        int i{};
void check(M& m)
{
    while(!m.items.empty())
    {
         int it = m.items.front();
         m.items.erase(m.items.begin());
         it = m.worryCalc(it)/3;
         int to = m.test(it) ? m.ifTrue : m.ifFalse;
         mm[to].items.push_back(it);
         // P(i, it, to, m.items.size(), mm[to].items.size());
    }
}

int main(int argc, char** argv)
{
    int score = 0;
    int N = 20;
    FOR(n, N)
    {
        for(auto& m:mm)
        {
            i++;
            check(m);
        }
        i=0;
        P(n);
        for(auto& m:mm)
        {
            i++;
            P_RR("m: %d\t %lu\n", i, m.items.size());
        }
        P_RR("\n");
    }

    P(score);
}

