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

    FOR(i, 999999999)
    {
        monkeys.clear();
        monkeys["humn"] = i;
        while(!monkeys.count(rm1) || !monkeys.count(rm2))
        {
            for(auto s : in)
            {
                P(s);
                auto vec = splitStr(s, ':');
                S monkey = vec[0];

                if(!monkeys.count(monkey))
                {
                    P_LINE;
                    try
                    {
                    P_LINE;
                        LL num = stoll(vec[1]);
                    P_LINE;
                        monkeys[monkey] = num;
                    P_LINE;
                    }
                    catch(const std::invalid_argument& e)
                    {
                        auto subVec = splitStr(vec[1], ' ');
                    P_LINE;

                        S m1 = subVec[0];
                    P_LINE;
                        S op = subVec[1];
                    P_LINE;
                        S m2 = subVec[2];
                    P_LINE;

                        if(monkeys.count(m1) && monkeys.count(m2))
                        {
                    P_LINE;
                            P(m1, m2);
                    P_LINE;
                            INT num1 = monkeys[m1];
                    P_LINE;
                            INT num2 = monkeys[m2];
                    P_LINE;
                            P(m1, num1, op, num2, m2);
                    P_LINE;
                            switch(op[0])
                            {
                                case '+' : monkeys[monkey] = monkeys[m1] + monkeys[m2]; break;
                                case '-' : monkeys[monkey] = monkeys[m1] - monkeys[m2]; break;
                                case '*' : monkeys[monkey] = monkeys[m1] * monkeys[m2]; break;
                                case '/' : monkeys[monkey] = monkeys[m1] / monkeys[m2]; break;
                            }
                    P_LINE;
                        }
                    P_LINE;
                    }
                    P_LINE;
                }
                    P_LINE;
            }
                    P_LINE;
                    P(i);
        }
                    P_LINE;

        if(monkeys.at(rm1) ==  monkeys.at(rm2))
        {
            score = i;
            break;
        }
    }

    P("Part2: ", score);
    return 0;
}
