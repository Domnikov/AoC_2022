// #define TEST

#ifdef TEST
#include "in_test.hpp"
    S rm1 = "pppw", rm2 = "sjmn";
#else
#include "in.hpp"
    S rm1 = "fglq", rm2 = "fzbp";
#endif

#include<queue>
#include <list>

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;
bool D = false;


int main(int argc, char** argv)
{
    INT score = 0;

    std::map<S, INT> monkeys;

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
                    INT num = stoll(vec[1]);
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

    P("Part1: ", score);
    //========================================================
    score = 0;
    std::map<S, std::function<INT()>> monkeysF;

    // monkeys["humn"] = [&score]() -> INT {return static_cast<INT>(0);};
    monkeysF["humn"] = [&score]{return score;};
    while(!monkeysF.count(rm1) || !monkeysF.count(rm2))
    {
        for(auto s : in)
        {
            auto vec = splitStr(s, ':');
            S monkey = vec[0];

            if(!monkeysF.count(monkey))
            {
                try
                {
                    INT num = stoll(vec[1]);
                    monkeysF[monkey] = [&score, num]() -> INT {return num;};
                }
                catch(const std::invalid_argument& e)
                {
                    auto subVec = splitStr(vec[1], ' ');

                    S m1 = subVec[0];
                    S op = subVec[1];
                    S m2 = subVec[2];

                    if(monkeysF.count(m1) && monkeysF.count(m2))
                    {
                        auto num1 = monkeysF[m1];
                        auto num2 = monkeysF[m2];
                        switch(op[0])
                        {
                            case '+' : monkeysF[monkey] = [num1, num2]{return num1()+num2();}; break;
                            case '-' : monkeysF[monkey] = [num1, num2]{return num1()-num2();}; break;
                            case '*' : monkeysF[monkey] = [num1, num2]{return num1()*num2();}; break;
                            case '/' : monkeysF[monkey] = [num1, num2]{return num1()/num2();}; break;
                        }
                    }
                }
            }
        }
    }
    P_LINE;

    auto rm1F = monkeysF[rm1];
    auto rm2V = monkeysF[rm2]();

    score = 1;
    for(score = 100000000000; rm1F() > rm2V; score += 100000000000/100)
    {
        // P(rm1F(), rm2V);
    }

    P("Part2: ", score);
    return 0;
}
