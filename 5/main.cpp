#define TEST

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

    std::vector<std::vector<char>> b;
    b.push_back({'N', 'Z'});
    b.push_back({'D', 'C', 'M'});
    b.push_back({'P'});


    for(auto s:in)
    {
        int m = stoi(s[1]);
        int from = stoi(s[3])-1;
        int to = stoi(s[5])-1;
        P(m);
        P(from);
        P(to);

        FOR(i, m)
        {
            char c = b[from].back();
            P(c);
            b[from].erase(b[from].end()-1);
            b[to].push_back(c);
        }
    }

    for(auto v : b)
    {
        P(v.back());
    }


    P(score);
}
