// #define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif


int check(char c)
{
    return -1;
}

int main(int argc, char** argv)
{
    auto in = getInput();
    ULL score = 0;

    for(auto ss:in)
    {
        auto v0 = splitStr(ss[0],'-');
        auto v1 = splitStr(ss[1],'-');

        if(stoi(v1[1]) < stoi(v0[0]))
        {
            P_VECH(ss);
            score++;
        }
        else if(stoi(v0[1]) < stoi(v1[0]))
        {
            P_VECH(ss);
            score++;
        }

    }

    P(score);
    P(in.size() - score);
}
