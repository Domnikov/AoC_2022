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


    std::map<char,ULL> map;
    S s = in[0];

    FOR(i,s.size())
    {
        if(map.size() < 3)
        {
            map[s[i]] = 0;
        }
        else{
            if(map.count(s[i]) && map[s[i]] == 0)
            {
                map[s[i]] = i;
                P(s[i]);
                P(i);
            }
        }

    }

    P(score);
}
