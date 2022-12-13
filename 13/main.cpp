// #define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

#include <cmath>

auto in = getInput();
bool D = true;
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
    return !s.empty();
}

bool isList(S& s)
{
    return !isDigit(s);
}

VECS getList(S s)
{
    VECS res;
    int bCnt = 0;
    size_t elSt=0;
    for(size_t i = 0; i < s.size(); ++i)
    {
        char& c = s[i];
        if(c == '[')
        {
            bCnt++;
        }
        if(c == ']')
        {
            bCnt--;
        }
        if(bCnt == 0 || i == s.size()-1)
        {
            if(c == ',' || i == s.size()-1)
            {
                if(i == s.size()-1) i = s.size();
                S elem = s.substr(elSt, i-elSt);
                if(elem[0] == '[' && elem[elem.size()-1] == ']') elem = elem.substr(1, elem.size()-2);
                res.push_back(elem);
                elSt = i+1;
            }
        }
    }
    // if(res.size() == 1 && !isDigit(res[0]))
    // {
    //     res = getList(res[0].substr(1, res[0].size()-2));
    // }
    // res.erase(std::remove_if(BE(res), [](const auto& s){ return s == "[]";}), res.end());
    return res;
}


int compareLists(VECS& l1, VECS& l2)
{
    if(D)P_RR("Compare:\n");
    if(D){P_VEC(l1);}
    if(D){P_VEC(l2);}
    FOR(i, +std::max(l1.size(), l2.size()))
    {
        if(i == l1.size() || i == l2.size())
        {
            if(l1.size() > l2.size())
            {
                if(D)P_RR("right out of elements\n");
                return 1;
            }
            if(l1.size() < l2.size())
            {
                if(D)P_RR("left out of elements\n");
                return -1;
            }
            else
            {
                if(D)P_RR("Both out of elements");
                break;
            }
        }
        else
        {
            if(!isList(l1[i]) && !isList(l2[i]))
            {
                LL v1 = stoi(l1[i]);
                LL v2 = stoi(l2[i]);
                if(v1 < v2)
                {
                    if(D)P_RR("Left lower: %lld < %lld\n", v1, v2);
                    return -1;
                }
                else if(v1 > v2)
                {
                    if(D)P_RR("Right lover: %lld > %lld\n", v1, v2);
                    return 1;
                }
            }
            else
            {
                VECS list1 = getList(l1[i]);
                VECS list2 = getList(l2[i]);
                auto res = compareLists(list1, list2);
                if(res != 0){return res;}
            }
        }
    }
    if(l2.empty())
    {
        if(D)P_RR("right out of elements\n");
        return 1;
    }
    if(l1.empty())
    {
        if(D)P_RR("left out of elements\n");
        return -1;
    }
    if(D)P_RR("Equals -> continue\n");
    return 0;
}

bool compare(S s1, S s2)
{
    if(D)P(s1, s2);
    auto v1 = getList(s1);
    auto v2 = getList(s2);
    auto res = compareLists(v1, v2);
    if(res < 0)
    {
        return true;
    }
    if(res > 0)
    {
        return false;
    }
    if(D)P_RR("Equal\n");
    exit(1);
}

int main(int argc, char** argv)
{
    LL score = 0;
    for(int i{}; i < in.size();i+=3)
    {
        auto s1 = in[i];
        auto s2 = in[i+1];
        P_RR("%s\n", s1.c_str());
        P_RR("%s\n", s2.c_str());
        if(in[i+2].size() > 0){if(D)P("MUST BE EMPTY");exit(1);}
        auto res = compare(s1, s2);
        if(res)
        {
            P_RR("+\n");
            if(D)P_RR("Left lower\n");
            score += 1+i/3;
        }
        else
        {
            P_RR("-\n");
            if(D)P_RR("Right lower or equal\n");
        }
    }
    P_RR("Part1: %lld\n", score);

    score = 0;
    FOR(i, in.size())
    {
        auto& s = in[i];
    }
    P_RR("Part2: %lld\n", score);
}
