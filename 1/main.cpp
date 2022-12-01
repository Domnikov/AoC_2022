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
    int max = 0;
    int sum = 0;
    while(std::cin >> str)
    {
        if(str.length() > 0)
        {
            sum += std::atoi(str.c_str());
        }
        else
        {
            max = std::max(max, sum);
            sum = 0;
        }
    }
    P(max);
}
