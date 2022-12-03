// #define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif


int check(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return 27+c-'A';
    }
    if(c >= 'a' && c <= 'z')
    {
        return 1+c-'a';
    }
    P("ERR");
    return -1;
}

int main(int argc, char** argv)
{
    auto input = getInput();
    ULL score = 0;

    for(size_t i = 0; i < input.size();i+=3)
    {
        S f = input[i];
        S s = input[i+1];
        S t = input[i+2];

        for(auto c : f)
        {
            if(std::any_of(s.begin(), s.end(), [c](auto cc){return c == cc;}))
            {
                if(std::any_of(t.begin(), t.end(), [c](auto cc){return c == cc;}))
                {
                    P(c);
                    score += check(c);
                    break;;
                }
            }

        }

    }

    P(score);
}
