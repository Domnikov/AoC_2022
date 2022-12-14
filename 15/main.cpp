// #define TEST

#ifdef TEST
    #include "in_test.hpp"
    LL L = 10;
#else
    #include "in.hpp"
    LL L = 2000000;
#endif

auto in = getInput();
bool D = true;
using INT = __int128;

std::vector<std::pair<LL, LL>> sen;
std::vector<std::pair<LL, LL>> bec;
VECI senPwr;

LL X(LL x){return x+10;}
LL Y(LL y){return y+10;}

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
    LL minx = 999999999, maxx = 0;
    LL miny = 999999999, maxy = 0;
    for(int i{}; i < in.size();i++ )
    {
        S line = in[i];
        auto vec = splitStr(line, ' ');
        LL sx = stoi(vec[2].substr(2, vec[2].size() - 3));
        LL sy = stoi(vec[3].substr(2, vec[3].size() - 3));
        LL bx = stoi(vec[8].substr(2, vec[8].size() - 3));
        LL by = stoi(vec[9].substr(2                   ));

        sen.push_back({sx, sy});
        bec.push_back({bx, by});
        senPwr.push_back(abs(sx-bx) + abs(sy-by));

        minx = std::min(minx, sx-senPwr.back());
        maxx = std::max(maxx, sx+senPwr.back());
        miny = std::min(miny, sy-senPwr.back());
        maxy = std::max(maxy, sy+senPwr.back());

    }

    LL y = L;
    for(LL i = minx-2; i <= maxx+2;++i)
    {
        bool empty = false;
        FOR(id, sen.size())
        {
            LL sx = sen[id].first;
            LL sy = sen[id].second;
            LL dist = abs(sx-i) + abs(sy-y);
            if(dist <= senPwr[id])
            {
                empty = std::find(BE(bec), std::pair<LL,LL>{i, y}) == bec.end();
            }
        }
        if(empty&&(y == L))
        {
            score++;
        }
    }
    P_RR("Part1: %lld\n", score);

    D = false;
    score = 0;
    minx = 999999999, maxx = 0;
    miny = 999999999, maxy = 0;
    FOR(id, sen.size())
    {
        LL sx = sen[id].first ;
        LL sy = sen[id].second;
        minx = std::min(minx, sx);
        maxx = std::max(maxx, sx);
        miny = std::min(miny, sy);
        maxy = std::max(maxy, sy);
    }
    for(LL y = miny; y <= maxy; y++)
    {
        LL min = minx;
        bool found = false;
        while(!found && min < maxx)
        {
            found = true;
            FOR(id, sen.size())
            {
                LL sx = sen[id].first;
                LL sy = sen[id].second;
                LL dist = abs(sx-min) + abs(sy-y);
                if(dist <= senPwr[id])
                {
                    min = sx + senPwr[id] - abs(sy-y) + 1;
                    found = false;
                    break;
                }
            }
            if(found)
            {
                score = 4000000 * min + y;
                P_RR("Part2: %lld\n", score);
                return 0;
            }
        }
    }
    P("Didm't find");
    return 1;
}
