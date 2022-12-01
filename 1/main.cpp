#define TEST

#include "../help_func.hpp"
#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

int main(int argc, char** argv)
{
    std::string str;
    std::cin >> str;
    P_VEC(in);
}
