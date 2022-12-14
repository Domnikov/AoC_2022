#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
bool D = true;
using INT = __int128;

VECS grid(1000, S(1000, ' '));

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
    LL minX = grid[0].size(), maxX = 0, minY = grid.size(), maxY = 0;
    for(int i{}; i < in.size();i++ )
    {
        S line = in[i];
        int curX = -1;
        int curY = -1;
        while(!line.empty())
        {
            auto pos = line.find(" -> ");
            S cur;
            if(pos == S::npos){ cur = line; line.clear();}
            else {cur = line.substr(0, pos); line = line.substr(pos+4);}
            auto ab = splitStr(cur, ',');
            int nextX = stoi(ab[0]), nextY = stoi(ab[1]);
            if(curX != nextX && curY != nextY){P("PROBLEM");exit(1);}
        }
    }
    // P_VECV(grid);
    P_RR("Part1: %lld\n", score);

    D = false;
    score = 0;

    P_RR("Part2: %lld\n", score);
}
