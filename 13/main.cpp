#define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
int score = 0;

int main(int argc, char** argv)
{
    FOR(i, in.size())
    {
        auto& s = in[i];



    }

    P(score);
}

