// #define TEST
#include <stack>

#include <functional>
#include <vector>
#include <list>
#define ULL unsigned long long
struct M
{
    M(
        std::function<ULL(ULL)> worryCalc_,
        std::function<ULL(ULL)> test_,
        int ifTrue_,
        int ifFalse_,
        std::vector<ULL> items_
    ):worryCalc(worryCalc_),test(test_),ifTrue(ifTrue_),ifFalse(ifFalse_)
    {
        for(auto i : items_){items.push_back(i);}
    }
    std::function<ULL(ULL)> worryCalc;
    std::function<ULL(ULL)> test;
    int ifTrue;
    int ifFalse;
    std::vector<ULL> items;
    int counter{};
};
#ifdef TEST
    #include "in_test.hpp"


    std::vector<M> mm{
    {[](ULL old){return old*19 ;}, [](ULL old){return old%23 == 0;},2, 3, {79,98}},
    {[](ULL old){return old+6  ;}, [](ULL old){return old%19 == 0;},2, 0, {54, 65, 75, 74}},
    {[](ULL old){return old*old;}, [](ULL old){return old%13 == 0;},1, 3, {79, 60, 97}},
    {[](ULL old){return old+3  ;}, [](ULL old){return old%17 == 0;},0, 1, {74}},
    };
    int DIV = (23*19*17*13);
#else
    std::vector<M> mm{
    {[](ULL old){return old*7  ;}, [](ULL old){return old%19 == 0;}, 6,  4, {65, 58, 93, 57, 66}},
    {[](ULL old){return old+4  ;}, [](ULL old){return old%3  == 0;}, 7,  5, {76, 97, 58, 72, 57, 92, 82}},
    {[](ULL old){return old*5  ;}, [](ULL old){return old%13 == 0;}, 5,  1, {90, 89, 96}},
    {[](ULL old){return old*old;}, [](ULL old){return old%17 == 0;}, 0,  4, {72, 63, 72, 99}},
    {[](ULL old){return old+1  ;}, [](ULL old){return old%2  == 0;}, 6,  2, {65}},
    {[](ULL old){return old+8  ;}, [](ULL old){return old%11 == 0;}, 7,  3, {97, 71}},
    {[](ULL old){return old+2  ;}, [](ULL old){return old%5  == 0;}, 2,  1, {83, 68, 88, 55, 87, 67}},
    {[](ULL old){return old+5  ;}, [](ULL old){return old%7  == 0;}, 3,  0, {64, 81, 50, 96, 82, 53, 62, 92}},
    };
    int DIV = 19*3*13*17*2*11*5*7;

#include "in.hpp"
#endif


auto in = getInput();

        int i{};
void check(M& m)
{
    while(!m.items.empty())
    {
         ULL it = m.items.front();
         m.items.erase(m.items.begin());
         it = m.worryCalc(it)%DIV;
         int to = m.test(it) ? m.ifTrue : m.ifFalse;
         mm[to].items.push_back(it);
         m.counter++;
         // P(i, it, to, m.items.size(), mm[to].items.size());
    }
}

int main(int argc, char** argv)
{
    int score = 0;
    int N = 10000;
    // int N = 20;
    FOR(n, N)
    {
        for(auto& m:mm)
        {
            i++;
            check(m);
        }
        i=0;
        int nn = n+1;
        if(nn == 20 || nn%1000 == 0)P(nn);
        for(auto& m:mm)
        {
            i++;
            if(nn == 20 || nn%1000 == 0)P_RR("m: %d\t %lu c=%d\n", i, m.items.size(), m.counter);
            if(n%1000 == 0)P_VEC(m.items);
        }
        if(n%1000 == 0)P_RR("\n");
    }
    VECI ins;
        for(auto& m:mm)
        {
            P(m.counter);
            ins.push_back(m.counter);
        }

    std::sort(BE(ins));

    P(*(ins.rbegin()) * *(ins.rbegin()+1));
}

