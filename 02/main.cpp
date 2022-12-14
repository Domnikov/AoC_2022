// #define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif


int check(std::string A)
{
    if(A == "A X")return 0+3;
    if(A == "A Y")return 3+1;
    if(A == "A Z")return 6+2;
    if(A == "B X")return 0+1;
    if(A == "B Y")return 3+2;
    if(A == "B Z")return 6+3;
    if(A == "C X")return 0+2;
    if(A == "C Y")return 3+3;
    if(A == "C Z")return 6+1;

    P("error");
    exit(1);
}

int main(int argc, char** argv)
{
    auto input = getInput();
    int score = 0;
    for(auto i:input)
    {
        P(check(i));
        P(i);
        score += check(i);
    }
    P(score);
}
