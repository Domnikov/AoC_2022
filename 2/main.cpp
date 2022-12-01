//#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

int main(int argc, char** argv)
{
    auto input = getInput();

    P_VEC(input);
}
