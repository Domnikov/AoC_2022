#define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();

struct point
{
    int x;
    int y;

    point& operator+(point s){x+=s.x;y+=s.y;return *this;}

    void move(char c)
    {
        switch(c)
        {
            case 'U': y+=1;break;
            case 'D': y-=1;break;
            case 'L': x+=1;break;
            case 'R': x-=1;break;
        };
    }
};

int main(int argc, char** argv)
{
    int score = 0;

    point h{0,0};
    point t{0,0};

    std::map<point, int> v;

    for(auto p:in)
    {
        char cmd = p[0];
        int val = stoi(p.substr(2));
        FOR(i,val)
        {
            h.move(cmd);
            if( abs(h.x-t.x) > 1 || abs(h.y-t.y) > 1 )
            {
                if(h.x == t.x)
                {
                    t.y += (h.y > t.y) ? 1 : -1;
                }
                else if(h.y == t.y)
                {
                    t.x += (h.x > t.x) ? 1 : -1;
                }
                else
                {
                    t.y += (h.y > t.y) ? 1 : -1;
                    t.x += (h.x > t.x) ? 1 : -1;
                }

                v[t]++;
            }
        }

    }
    score = v.size();
    P(score);
}

