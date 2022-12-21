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

    std::map<S, LL> monkeys;

    while(!monkeys.count("root"))
    {
        for(auto s : in)
        {
            auto vec = splitStr(s, ':');
            S monkey = vec[0];

            if(!monkeys.count(monkey))
            {
                try
                {
                    LL num = stoll(vec[1]);
                    monkeys[monkey] = num;
                }
                catch(const std::invalid_argument& e)
                {
                    auto subVec = splitStr(vec[1], ' ');

                    S m1 = subVec[0];
                    S op = subVec[1];
                    S m2 = subVec[2];

                    if(monkeys.count(m1) && monkeys.count(m2))
                    {
                        switch(op[0])
                        {
                            case '+' : monkeys[monkey] = monkeys[m1] + monkeys[m2]; break;
                            case '-' : monkeys[monkey] = monkeys[m1] - monkeys[m2]; break;
                            case '*' : monkeys[monkey] = monkeys[m1] * monkeys[m2]; break;
                            case '/' : monkeys[monkey] = monkeys[m1] / monkeys[m2]; break;
                        }
                    }
                }
            }
        }
    }

    score = monkeys["root"];

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
