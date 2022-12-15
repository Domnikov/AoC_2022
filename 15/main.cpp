#define TEST

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

auto in = getInput();
bool D = true;
using INT = __int128;

std::vector<std::pair<int, int>> sen;
std::vector<std::pair<int, int>> bec;
VECS grid(30, S(30, ' '));

int X(int x){return x+2;}
int Y(int y){return y+2;}

int main(int argc, char** argv)
{
    LL score = 0;
    D = false;
    for(int i{}; i < in.size();i++ )
    {
        S line = in[i];
        P(line);
        auto vec = splitStr(line, ' ');
        int sx = stoi(vec[2].substr(2, vec[2].size() - 3));
        P(sx);
        int sy = stoi(vec[3].substr(2, vec[3].size() - 3));
        P(sy);
        int bx = stoi(vec[8].substr(2, vec[8].size() - 3));
        P(bx);
        int by = stoi(vec[9].substr(2                   ));
        P(by);

        sen.push_back({sx, sy});
        bec.push_back({bx, by});

        grid[X(sx)][Y(sy)] = 'S';
        grid[X(bx)][Y(by)] = 'B';

    }
    P_VECV(grid);

    P_RR("Part1: %lld\n", score);

    D = false;
    score = 0;

    P_RR("Part2: %lld\n", score);
}
