// #define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif


int check(char c)
{
    return -1;
}

int main(int argc, char** argv)
{
    auto in = getInput();
    ULL score = 0;


    S s = in[0];
    ULL marker = 0;

    FOR(i,s.size())
    {
        if(i>4)
        {
            char a = s[i-3];
            char b = s[i-2];
            char c = s[i-1];
            char d = s[i-0];

            if(a != b && b != c && c != d && a != c && a != d && b != d)
                {
                    P(i+1);
                    marker = i;
                    break;
                }
        }

    }

    marker = 0;
    for(int i = marker+14; i < s.length(); i++)
    {
        std::set<char> set;
        FOR(j,14)
        {
            set.emplace(s[i-j]);
        }

        if(set.size() == 14)
        {
            P(i+1);
            break;
        }
        P(i+0);
        P(set.size());

    }


    P(score);
}

