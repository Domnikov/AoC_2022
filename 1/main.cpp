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
    std::vector<int> vec;
    int sum = 0;
    std::ifstream file("input2");
    while(std::getline(file, str))
    {
        if(str.length() > 0)
        {
            sum += std::atoi(str.c_str());
        }
        else
        {
            vec.push_back(sum);
            sum = 0;
        }
    }
    std::sort(vec.begin(), vec.end());
    P(vec.back() + *(vec.end()-2) + *(vec.end()-1));
}
