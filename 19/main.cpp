#define TEST

#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

#include<queue>

auto in = getInput();
using INT = __int128;
using VECC = std::vector<char>;

LL T = 24;

struct step
{
    char rob1 : 4;
    char rob2 : 4;
    char rob3 : 4;
    char rob4 : 4;
    char res1 : 4;
    char res2 : 4;
    char res3 : 4;
    char res4 : 4;
    char time : 5;
};

union St
{
    LL raw;
    step s;
};

LL calc(char cr1o, char cr2o, char cr3o, char cr3c, char cr4o, char cr4b)
{
    step init{1, 0, 0, 0, 0, 0, 0, 0, 0};

    std::queue<step> q{{init}};

    LL next{};
    LL max{};
    char count{};
    while(!q.empty())
    {
        auto [rob1, rob2, rob3, rob4, res1, res2, res3, res4, time] = q.front();
        q.pop();
        if(time == T) {max = std::max<LL>(max, res4);P(rob1, rob2, rob3, rob4, res4, max);continue;}
        if(time >= 14 && rob3 == 0) continue;
        if(count < time){P((int)time, q.size(), (int)rob1, (int)rob2, (int)rob3, (int)rob4);count = time;}
        char Nres1 = rob1+res1;
        char Nres2 = rob1+res2;
        char Nres3 = rob1+res3;
        char Nres4 = rob1+res4;
        if(res1 > cr1o               ){q.push({rob1++, rob2  , rob3  , rob4  , (char)(Nres1-cr1o), (char)(Nres2     ), (char)(Nres3     ), (char)(Nres4     ), (char)(time+1)});}
        if(res1 > cr2o               ){q.push({rob1  , rob2++, rob3  , rob4  , (char)(Nres1     ), (char)(Nres2     ), (char)(Nres3     ), (char)(Nres4     ), (char)(time+1)});}
        if(res1 > cr3o && res2 > cr3c){q.push({rob1  , rob2  , rob3++, rob4  , (char)(Nres1     ), (char)(Nres2     ), (char)(Nres3     ), (char)(Nres4     ), (char)(time+1)});}
        if(res1 > cr4o && res3 > cr4b){q.push({rob1  , rob2  , rob3  , rob4++, (char)(Nres1     ), (char)(Nres2     ), (char)(Nres3     ), (char)(Nres4     ), (char)(time+1)});}
                                      {q.push({rob1  , rob2  , rob3  , rob4  , (char)(Nres1     ), (char)(Nres2     ), (char)(Nres3     ), (char)(Nres4     ), (char)(time+1)});}
    }


    return max;
}


int main(int argc, char** argv)
{
    LL score = 0;

    LL num = 0;
    for(auto& i : in)
    {
        auto sent = splitStr(i, ' ');
        char cr1  = stoi(sent[ 6]);
        char cr2 = stoi(sent[12]);
        char cr3o = stoi(sent[18]);
        char cr3c = stoi(sent[21]);
        char cr4o = stoi(sent[27]);
        char cr4b = stoi(sent[30]);
        LL max = std::max(max, calc(cr1, cr2, cr3o, cr3c, cr4o, cr4b));

        P(num, max);

        score += ++num * max;
    }

    P_RR("Part1: %lld\n", score);
    //========================================================
    score = 0;

    P_RR("Part2: %lld\n", score);
    return 0;
}
