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
    unsigned char res1 : 8;
    unsigned char res2 : 8;
    unsigned char res3 : 8;
    unsigned char res4 : 8;
    unsigned char rob1 : 6;
    unsigned char rob2 : 6;
    unsigned char rob3 : 6;
    unsigned char rob4 : 6;
    unsigned char time : 6;
};

union St
{
    LL raw;
    step s;
};

LL calc(unsigned char cr1o, unsigned char cr2o, unsigned char cr3o, unsigned char cr3c, unsigned char cr4o, unsigned char cr4b)
{
    step init{1, 0, 0, 0, 0, 0, 0, 0, 0};

    std::queue<step> q{{init}};

    LL next{};
    LL max{};
    LL maxB{};
    char count{};
    P((int)cr1o, (int)cr2o, (int)cr3o, (int)cr3c, (int)cr4o, (int)cr4b);
    while(!q.empty())
    {
        auto [res1, res2, res3, res4, rob1, rob2, rob3, rob4, time] = q.front();
        P((int)time, (int)rob1, (int)rob2, (int)rob3, (int)rob4, (int)res1, (int)res2, (int)res3);
        if(time>4)exit(1);
        q.pop();
        max = std::max<LL>(max, res4);
        maxB= std::max<LL>(maxB,res3);
        if(time == T) {continue;}
        if(time >= 119 && rob3 == 0) continue;
        if(time >= 125 && rob4 == 0) continue;
        if(rob1 > 19 || rob2 > 19 || rob3 > 19) continue;
        // if(count < time){P((int)time, q.size(), (int)rob1, (int)rob2, (int)rob3, (int)rob4, max, maxB);count = time;max = 0;maxB = 0;}
        unsigned char Nres1 = rob1+res1;
        unsigned char Nres2 = rob2+res2;
        unsigned char Nres3 = rob3+res3;
        unsigned char Nres4 = rob4+res4;
        unsigned char Mcmo  = std::max(cr1o , std::max(cr2o , std::max(cr3o , cr4o )));
        if(res1 >= cr1o                ){q.push({rob1++, rob2  , rob3  , rob4  , (unsigned char)(Nres1-cr1o), (unsigned char)(Nres2     ), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), (unsigned char)(time+1)});}
        if(res1 >= cr2o                ){q.push({rob1  , rob2++, rob3  , rob4  , (unsigned char)(Nres1-cr2o), (unsigned char)(Nres2     ), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), (unsigned char)(time+1)});}
        if(res1 >= cr3o && res2 >= cr3c){q.push({rob1  , rob2  , rob3++, rob4  , (unsigned char)(Nres1-cr3o), (unsigned char)(Nres2-cr3c), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), (unsigned char)(time+1)});}
        if(res1 >= cr4o && res3 >= cr4b){q.push({rob1  , rob2  , rob3  , rob4++, (unsigned char)(Nres1-cr4o), (unsigned char)(Nres2     ), (unsigned char)(Nres3-cr4b), (unsigned char)(Nres4     ), (unsigned char)(time+1)});}
        if(Mcmo >= res1 && res3 <= cr4b){q.push({rob1  , rob2  , rob3  , rob4  , (unsigned char)(Nres1     ), (unsigned char)(Nres2     ), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), (unsigned char)(time+1)});}
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
        unsigned char cr1  = stoi(sent[ 6]);
        unsigned char cr2 = stoi(sent[12]);
        unsigned char cr3o = stoi(sent[18]);
        unsigned char cr3c = stoi(sent[21]);
        unsigned char cr4o = stoi(sent[27]);
        unsigned char cr4b = stoi(sent[30]);
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
