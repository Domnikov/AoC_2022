#define TEST
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

    std::pair<int, int> h{0,0};
    std::pair<int, int> t{0,0};

    std::map<std::pair<int, int>, int> v;

    for(auto p:in)
    {
        char cmd = p[0];
        int val = stoi(p.substr(2));
        FOR(i,val)
        {
            move(h, cmd);
            P_RR("H[%d,%d] \t",h.first,h.second);
            if( abs(h.first-t.first) > 1 || abs(h.second-t.second) > 1 )
            {
                if(h.first == t.first)
                {
                    t.second += (h.second > t.second) ? 1 : -1;
                }
                else if(h.second == t.second)
                {
                    t.first += (h.first > t.first) ? 1 : -1;
                }
                else
                {
                    t.second += (h.second > t.second) ? 1 : -1;
                    t.first += (h.first > t.first) ? 1 : -1;
                }
                P_RR("T[%d,%d] \t",t.first,t.second);
            }
            P_RR("\n");
            v[t]++;
        }

    }

    for(auto p : v)
    {
        // P(p.first.first, p.first.second, p.second);
    }


    score = v.size();
    P(score);
}

