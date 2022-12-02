#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif


int check(std::string A)
{
    if(A == "A X")return 3+1;
    if(A == "A Y")return 6+2;
    if(A == "A Z")return 1+3;
    if(A == "B X")return 1+1;
    if(A == "B Y")return 3+2;
    if(A == "B Z")return 6+3;
    if(A == "C X")return 6+1;
    if(A == "C Y")return 1+2;
    if(A == "C Z")return 3+3;

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
