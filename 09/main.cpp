// #define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();

    void move(std::pair<int, int>& p, char c)
    {
        switch(c)
        {
            case 'U': p.first+=1;break;
            case 'D': p.first-=1;break;
            case 'R': p.second+=1;break;
            case 'L': p.second-=1;break;
        };
    }

int main(int argc, char** argv)
{
    int score = 0;
    const static int N = 10;
    std::pair<int, int> t[N];


    std::map<std::pair<int, int>, int> v[9];

    for(int i = 0; i <N; ++i)
    {
        t[i] = std::pair<int,int>{0,0};
        v[i] = std::map<std::pair<int, int>, int>{};
    }

    for(auto p:in)
    {
        char cmd = p[0];
        int val = stoi(p.substr(2));
        FOR(i,val)
        {
            move(t[0], cmd);
            P_RR("H[%d,%d] \t",t[0].first,t[0].second);
            for(int i = 1; i <N; ++i)
            {
                if( abs(t[i-1].first-t[i].first) > 1 || abs(t[i-1].second-t[i].second) > 1 )
                {
                    if(t[i-1].first == t[i].first)
                    {
                        t[i].second += (t[i-1].second > t[i].second) ? 1 : -1;
                    }
                    else if(t[i-1].second == t[i].second)
                    {
                        t[i].first += (t[i-1].first > t[i].first) ? 1 : -1;
                    }
                    else
                    {
                        t[i].second += (t[i-1].second > t[i].second) ? 1 : -1;
                        t[i].first += (t[i-1].first > t[i].first) ? 1 : -1;
                    }
                    P_RR("T[%d,%d] \t",t[i].first,t[i].second);
                }
                v[i][t[i]]++;
            }
            P_RR("\n");
            v[0][t[0]]++;
        }

    }

    for(auto p : v)
    {
        // P(p.first.first, p.first.second, p.second);
    }


    score = v[N-1].size();
    P(score);
}

