// #define TEST

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
    unsigned char res1;
    unsigned char res2;
    unsigned char res3;
    unsigned char res4;
    unsigned char rob1;
    unsigned char rob2;
    unsigned char rob3;
    unsigned char rob4;
    unsigned char time;
};

union St
{
    LL raw;
    step s;
};

LL calc(unsigned char cr1o, unsigned char cr2o, unsigned char cr3o, unsigned char cr3c, unsigned char cr4o, unsigned char cr4b)
{
    step init{0, 0, 0, 0, 1, 0, 0, 0, 0};

    std::queue<step> q{{init}};

    LL next{};
    LL max{};
    // LL maxB{};
    char count{};
    P((int)cr1o, (int)cr2o, (int)cr3o, (int)cr3c, (int)cr4o, (int)cr4b);
    LL maxR{};
    while(!q.empty())
    {
        auto [res1, res2, res3, res4, rob1, rob2, rob3, rob4, time] = q.front();
        q.pop();
        max = std::max<LL>(max, res4);
        // maxB= std::max<LL>(maxB,res3);
        LL Rsum = (rob1 + rob2 + 2*rob3 + 2*rob4);
        maxR = std::max<LL>(maxR, Rsum);
        if(count < time){P((int)time, q.size(), (int)rob1, (int)rob2, (int)rob3, (int)rob4, max);count = time;}
        if(time >= 113 && Rsum*9/5 < maxR)continue;
        if(time == T) {continue;}
        if(time >= 12 && rob2 == 0) continue;
        if(time >= 21 && rob3 == 0) continue;
        if(time >= 123 && rob4 == 0) continue;
        if(rob1 > 11 || rob2 > 11 || rob3 > 11) continue;
        if(time >= 21 && (res4+2) < max) continue;
        if(time >= 15 && (rob1 >= 5*rob2 || rob2 >= 5*rob1))continue;
        unsigned char Nres1 = rob1+res1;
        unsigned char Nres2 = rob2+res2;
        unsigned char Nres3 = rob3+res3;
        unsigned char Nres4 = rob4+res4;
        unsigned char Mcmo  = std::max(cr1o , std::max(cr2o , std::max(cr3o , cr4o )));
        // if(time == 15 && res4 > 0){P((int)time, (int)rob1, (int)rob2, (int)rob3, (int)rob4, (int)res1, (int)res2, (int)res3, (int)res4, (int)Nres4);}
        // if(time>4)exit(1);
        if(res1 >= cr1o                ){q.push({(unsigned char)(Nres1-cr1o), (unsigned char)(Nres2     ), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), (unsigned char)(rob1+1), (unsigned char)(rob2 ), (unsigned char)(rob3 ), (unsigned char)(rob4 ), (unsigned char)(time+1)});}
        if(res1 >= cr2o                ){q.push({(unsigned char)(Nres1-cr2o), (unsigned char)(Nres2     ), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), (unsigned char)(rob1 ), (unsigned char)(rob2+1), (unsigned char)(rob3 ), (unsigned char)(rob4 ), (unsigned char)(time+1)});}
        if(res1 >= cr3o && res2 >= cr3c){q.push({(unsigned char)(Nres1-cr3o), (unsigned char)(Nres2-cr3c), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), (unsigned char)(rob1 ), (unsigned char)(rob2 ), (unsigned char)(rob3+1), (unsigned char)(rob4 ), (unsigned char)(time+1)});}
        if(res1 >= cr4o && res3 >= cr4b){q.push({(unsigned char)(Nres1-cr4o), (unsigned char)(Nres2     ), (unsigned char)(Nres3-cr4b), (unsigned char)(Nres4     ), (unsigned char)(rob1 ), (unsigned char)(rob2 ), (unsigned char)(rob3 ), (unsigned char)(rob4+1), (unsigned char)(time+1)});}
        if(Mcmo*2 >= res1 && res3 <= cr4b*2){q.push({(unsigned char)(Nres1     ), (unsigned char)(Nres2     ), (unsigned char)(Nres3     ), (unsigned char)(Nres4     ), rob1  , rob2  , rob3  , rob4  , (unsigned char)(time+1)});}
    }


    return max;
}


int main(int argc, char** argv)
{
    LL score = 0;

    LL num = 0;
#if 0
    for(auto& i : in)
    {
        auto sent = splitStr(i, ' ');
        unsigned char cr1  = stoi(sent[ 6]);
        unsigned char cr2 = stoi(sent[12]);
        unsigned char cr3o = stoi(sent[18]);
        unsigned char cr3c = stoi(sent[21]);
        unsigned char cr4o = stoi(sent[27]);
        unsigned char cr4b = stoi(sent[30]);
        LL max = calc(cr1, cr2, cr3o, cr3c, cr4o, cr4b);

        score += ++num * max;
        P(num, max, score);

    }

    P_RR("Part1: %lld\n", score);
#endif
    //========================================================
    score = 0;
    num = 0;
    T = 32;
    for(int i = 0; i < 3; i++)
    {
        const auto& s = in[i];
        auto sent = splitStr(s, ' ');
        unsigned char cr1  = stoi(sent[ 6]);
        unsigned char cr2  = stoi(sent[12]);
        unsigned char cr3o = stoi(sent[18]);
        unsigned char cr3c = stoi(sent[21]);
        unsigned char cr4o = stoi(sent[27]);
        unsigned char cr4b = stoi(sent[30]);
        LL max = calc(cr1, cr2, cr3o, cr3c, cr4o, cr4b);

        score += ++num * max;
        P(num, max, score);

    }

    P_RR("Part2: %lld\n", score);
    return 0;
}
