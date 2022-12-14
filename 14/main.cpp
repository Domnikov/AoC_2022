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

void drawLine(int x1, int x2, int y1, int y2)
{
    if(x1 == x2)
    {
        for(size_t y = y1; y <= y2; y++)
        {
            grid[y][x1] = '#';
        }
    }
    if(y1 == y2)
    {
        for(size_t x = x1; x <= x2; x++)
        {
            grid[y1][x] = '#';
        }
    }
}

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
    LL minX = grid[0].size(), maxX = 0, minY = grid.size(), maxY = 0;
    for(int i{}; i < in.size();i++ )
    {
        S line = in[i];
        size_t curX = -1;
        size_t curY = -1;
        while(!line.empty())
        {
            auto pos = line.find(" -> ");
            S cur;
            if(pos == S::npos){ cur = line; line.clear();}
            else {cur = line.substr(0, pos); line = line.substr(pos+4);}
            auto ab = splitStr(cur, ',');
            size_t nextX = stoi(ab[0]), nextY = stoi(ab[1]);
            if(curX != -1)
            {
                drawLine(curX, nextX, curY, nextY);
            }
            curX = nextX;
            curY = nextY;
            minX = std::min<size_t>(minX, nextX);
            minY = std::min<size_t>(minY, nextY);
            maxX = std::min<size_t>(maxX, nextX);
            maxY = std::min<size_t>(maxY, nextY);
        }
    }
    P(minX, maxX, minY, maxY);
    P_RR("\n");
    for(size_t y = minY-1; y < maxY+1; ++y)
    {
        for(size_t x = minX-1; x < maxX+1; ++x)
        {
            P_RR("%c", grid[y][x]);
        }
        P_RR("\n");
    }
    // P_VECV(grid);
    P_RR("Part1: %lld\n", score);

    D = false;
    score = 0;

    P_RR("Part2: %lld\n", score);
}
