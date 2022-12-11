#define TEST
#include <stack>

#include <functional>
#include <vector>
struct M
{
    M(
        std::function<int(int)> worryCalc_,
        std::function<int(int)> test_,
        int ifTrue_,
        int ifFalse_,
        std::vector<int> items_
    ):worryCalc(worryCalc_),test(test_),ifTrue(ifTrue_),ifFalse(ifFalse_),items(items_)
    {
    }
    std::function<int(int)> worryCalc;
    std::function<int(int)> test;
    int ifTrue;
    int ifFalse;
    std::vector<int> items;
};
#ifdef TEST
    #include "in_test.hpp"


    std::vector<M> m{
    {[](int old){return old*19 ;}, [](int old){return old%23 == 0;},2, 3, {79,98}},
    {[](int old){return old+6  ;}, [](int old){return old%19 == 0;},2, 0, {54, 65, 75, 74}},
    {[](int old){return old*old;}, [](int old){return old%13 == 0;},1, 3, {79, 60, 97}},
    {[](int old){return old+3  ;}, [](int old){return old%17 == 0;},0, 1, {74}},
    };

#else
    #include "in.hpp"
#endif


auto in = getInput();



int main(int argc, char** argv)
{
    int score = 0;

    P(score);
}

