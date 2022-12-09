 #define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();

int main(int argc, char** argv)
{
    int score = 0;

    P(score);
}

