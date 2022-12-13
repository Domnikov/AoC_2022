#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

#include <cmath>

auto in = getInput();

using INT = __int128;

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isDigit(S s)
{
    for(auto c : s)
    {
        if(!isDigit(c)) return false;
    }
    return true;
}

S getNext(S& s)
{
    if(s.empty()) return {};
    if(s[0] == ',')
    {
        s = s.substr(1);
    }
    if(s[0] == '[')
    {
        s = s.substr(1);
        return "[";
    }
    if(s[0] == ']')
    {
        s = s.substr(1);
        return {};
    }
    if(isDigit(s[0]))
    {
        int len{};
        while (isDigit(len++)){}
        S res = s.substr(0, len);
        s = s.substr(len);
        return res;
    }
    P_RR("Oops. Nothing to do!!!\n");
    exit(1);
}

VECI getList(S& s)
{
    VECI res;
    S next = getNext(s);
    while(!next.empty())
    {
        if(isDigit(next)) res.push_back(stoi(next));
        next = getNext(s);
    }
    return res;
}

bool compare(S s1, S s2)
{
    P(s1, s2);
    auto b1 = s1.begin();
    auto b2 = s2.begin();
    for(int n = 0; true; ++n)
    {
        auto v1 = getList(s1);
        auto v2 = getList(s2);
        P_RR("Compare:\n");
        P_VEC(v1);
        P_VEC(v2);
        FOR(i, +std::max(v1.size(), v2.size()))
        {
            if(i == v1.size() || i == v2.size())
            {
                if(v1.size() > v2.size())
                {
                    P_RR("right out of elements\n");
                    return false;
                }
                if(v1.size() < v2.size())
                {
                    P_RR("left out of elements\n");
                    return true;
                }
                else
                {
                    P_RR("Both out of elements");
                    break;
                }
            }
            else if(v1[i] < v2[i])
            {
                P_RR("%lld < %lld\n", v1[i], v2[i]);
            }
        }
        P_RR("Equals -> continue\n");
    }
}

int main(int argc, char** argv)
{
    LL score = 0;
    for(int i{}; i < in.size();i+=3)
    {
        auto s1 = in[i].substr(1, in[i].size()-2);
        auto s2 = in[i+1].substr(1, in[i+1].size()-2);
        if(in[i+2].size() > 0){P("MUST BE EMPTY");exit(1);}

        score += compare(s1,s2) ? (1+i/3) : 0;
    }
    P_RR("Part1: %lld\n", score);

    score = 0;
    FOR(i, in.size())
    {
        auto& s = in[i];
    }
    P_RR("Part2: %lld\n", score);
}
