#define TEST

#include "../help_func.hpp"
#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif
#include <fstream>

int main(int argc, char** argv)
{
    std::string str;
    int max = 0;
    int sum = 0;
    std::ifstream file("input2");
    while(std::getline(file, str))
    {
        if(str.length() > 0)
        {
            sum += std::atoi(str.c_str());
            // P(sum);
        }
        else
        {
            max = std::max(max, sum);
            sum = 0;
            P(max);
        }
    }
    // P(max);
}
