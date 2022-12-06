#define TEST
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
                    P(i);
                    break;
                }
        }

    }

    P(score);
}
