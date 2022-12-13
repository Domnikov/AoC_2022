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

bool isList(S& s)
{
    return !isDigit(s);
}

// S getNext(S& s)
// {
//     if(s.empty()) return {};
//     if(s[0] == ',')
//     {
//         s = s.substr(1);
//     }
//     if(s[0] == '[')
//     {
//         s = s.substr(1);
//         return "[";
//     }
//     if(s[0] == ']')
//     {
//         s = s.substr(1);
//         return {};
//     }
//     if(isDigit(s[0]))
//     {
//         int len{};
//         while (isDigit(s[++len])){}
//         S res = s.substr(0, len);
//         s = s.substr(len);
//         return res;
//     }
//     P_RR("Oops. Nothing to do!!!\n");
//     exit(1);
// }
//
// VECI getList(S& s)
// {
//     VECS res;
//     if(s.empty())return res;
//     bool isList = (s[0] == '[');
//     P(isList, s[0]);
//     S next = getNext(s);
//     while(!next.empty())
//     {
//         if(isDigit(next)) res.push_back(stoi(next));
//         if(!res.empty() && next == "[")
//         {
//             break;
//         }
//         if(!isList)
//         {
//             break;
//         }
//         next = getNext(s);
//     }
//     return res;
// }


VECS getList(S s)
{
    P(__LINE__);
    VECS res;
    int bCnt = 0;
    size_t elSt=1;
    P(__LINE__);
    FOR(i, s.size())
    {
    P(__LINE__);
        char& c = s[i];
        P(c);
        if(c == '[')
        {
            bCnt++;
        }
        if(c == ']')
        {
            bCnt--;
        }
        if(bCnt == 0)
        {
            if(c == ',')
            {
                res.push_back(s.substr(elSt, i-elSt-1));
                elSt = i;
            }
        }
    P(__LINE__);
    }
    if(elSt != s.size()-1)
    {
        res.push_back(s.substr(elSt, s.size() - elSt - 1));
    }
    P(__LINE__);
    P_VEC(res);
    exit(1);
    if(res.size() == 1 && !isDigit(res[0]))
    {
        res = getList(res[0]);
    }
    P(__LINE__);
    return res;
}


int compareLists(VECS& l1, VECS& l2)
{
    FOR(i, +std::max(l1.size(), l2.size()))
    {
        if(i == l1.size() || i == l2.size())
        {
            if(l1.size() > l2.size())
            {
                P_RR("right out of elements\n");
                return 1;
            }
            if(l1.size() < l2.size())
            {
                P_RR("left out of elements\n");
                return -1;
            }
            else
            {
                P_RR("Both out of elements");
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
                    P_RR("Left lower: %lld < %lld\n", v1, v2);
                    return -1;
                }
                else if(v1 > v2)
                {
                    P_RR("Right lover: %lld > %lld\n", v1, v2);
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
        P_RR("right out of elements\n");
        return 1;
    }
    if(l1.empty())
    {
        P_RR("left out of elements\n");
        return -1;
    }
    P_RR("Equals -> continue\n");
    return 0;
}

bool compare(S s1, S s2)
{
    P(s1, s2);
    auto v1 = getList(s1);
    auto v2 = getList(s2);
    P_RR("Compare:\n");
    P_VEC(v1);
    P_VEC(v2);
    if(compareLists(v1, v2) < 0)
    {
        return true;
    }
    if(compareLists(v1, v2) > 0)
    {
        return false;
    }
    P_RR("Equal\n");
    exit(1);
}

int main(int argc, char** argv)
{
    LL score = 0;
    for(int i{}; i < in.size();i+=3)
    {
        auto s1 = in[i];
        auto s2 = in[i+1];
        if(in[i+2].size() > 0){P("MUST BE EMPTY");exit(1);}
        auto res = compare(s1, s2);
        if(res)
        {
            P_RR("Left lower\n");
            score += 1+i/3;
        }
        else
        {
            P_RR("Right lower or equal\n");
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
