#define TEST
#include <stack>

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
#ifdef TEST
    b.push_back({'Z', 'N'});
    b.push_back({'M', 'C', 'D'});
    b.push_back({'P'});
#else
//         [M]     [B]             [N]
// [T]     [H]     [V] [Q]         [H]
// [Q]     [N]     [H] [W] [T]     [Q]
// [V]     [P] [F] [Q] [P] [C]     [R]
// [C]     [D] [T] [N] [N] [L] [S] [J]
// [D] [V] [W] [R] [M] [G] [R] [N] [D]
// [S] [F] [Q] [Q] [F] [F] [F] [Z] [S]
// [N] [M] [F] [D] [R] [C] [W] [T] [M]
//  1   2   3   4   5   6   7   8   9

    b.push_back({'N','S','D','C','V','Q','T'});
    b.push_back({'M','F','V'});
    b.push_back({'F','Q','W','D','P','N','H','M'});
    b.push_back({'D','Q','R','T','F'});
    b.push_back({'R','F','M','N','Q','H','V','B'});
    b.push_back({'C','F','G','N','P','W','Q'});
    b.push_back({'W','F','R','L','C','T'});
    b.push_back({'T','Z','N','S'});
    b.push_back({'M','S','D','J','R','Q','H','N'});
#endif


    for(auto s:in)
    {
        P_VEC(s);
        int m = stoi(s[1]);
        int from = stoi(s[3])-1;
        int to = stoi(s[5])-1;
        P(m);
        P(from);
        P(to);

        std::stack<char> stack;
        FOR(i, m)
        {
            char c = b[from].back();
            stack.emplace(c);
            b[from].erase(b[from].end()-1);
        }
        while(!stack.empty())
        {
            auto c = stack.top();
            b[to].push_back(c);
            stack.pop();
        }
    }

    for(auto v : b)
    {
        P(v.back());
    }
    P_VEC(b);


    P(score);
}
