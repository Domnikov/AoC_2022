// #define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif


int check(std::string A)
{
}

int main(int argc, char** argv)
{
    auto input = getInput();
    int score = 0;

    for(auto i:input)
    {


        score += check(i);
    }

    P(score);
}
