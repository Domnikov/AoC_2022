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
LL minX = grid[0].size(), maxX = 0, minY = grid.size(), maxY = 0;

void drawGrid()
{
    P(minX, maxX, minY, maxY);
    P_RR("\n");
    for(size_t y = minY-10; y < maxY+10; ++y)
    {
        for(size_t x = minX-10; x < maxX+10; ++x)
        {
            P_RR("%c", grid[y][x]);
        }
        P_RR("\n");
    }
}

void drawLine(int x1, int x2, int y1, int y2)
{
    if(x1 == x2)
    {
        if(y1 > y2)std::swap(y1, y2);
        for(size_t y = y1; y <= y2; y++)
        {
            grid[y][x1] = '#';
        }
    }
    if(y1 == y2)
    {
        if(x1 > x2)std::swap(x1, x2);
        for(size_t x = x1; x <= x2; x++)
        {
            grid[y1][x] = '#';
        }
    }
}

std::tuple<int, int, bool> whereCanGo(int x, int y)
{
    if(grid[y+1][x  ] == ' ') return {x  , y+1, true};
    if(grid[y+1][x-1] == ' ') return {x-1, y+1, true};
    if(grid[y+1][x+1] == ' ') return {x+1, y+1, true};
    return {x, y, false};
}

bool nextDrop()
{
    int x = 500, y = 0;
    bool can{};
    do
    {
        auto [nX, nY, canGo] = whereCanGo(x, y);
        if(nY == maxY) break;
        can = canGo;
        grid[y][x] = ' ';
        x = nX;
        y = nY;
        grid[y][x] = 'o';
    }
    while(can);
    return y < maxY;
}

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
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
            maxX = std::max<size_t>(maxX, nextX);
            maxY = std::max<size_t>(maxY, nextY);
        }
    }

    for(int i = 0; i < 200; i++)
    {
        if(!nextDrop())break;
        drawGrid();
    }

    drawGrid();
    P_RR("Part1: %lld\n", score);

    D = false;
    score = 0;

    P_RR("Part2: %lld\n", score);
}
