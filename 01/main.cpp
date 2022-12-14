//#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

int main(int argc, char** argv)
{
    auto input = getInput();
    VECI vec;
    int sum = 0;
    for(auto str : input)
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
    P(vec.back() + *(vec.end()-2) + *(vec.end()-3));
}
