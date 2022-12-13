#pragma once
#include "../help_func.hpp"

inline auto getInput()
{
    VECS input {
"[1,1,3,1,1]",
"[1,1,5,1,1]",
"",
"[[1],[2,3,4]]",
"[[1],4]",
"",
"[9]",
"[[8,7,6]]",
"",
"[[4,4],4,4]",
"[[4,4],4,4,4]",
"",
"[7,7,7,7]",
"[7,7,7]",
"",
"[]",
"[3]",
"",
"[[[]]]",
"[[]]",
"",
"[1,[2,[3,[4,[5,6,7]]]],8,9]",
"[1,[2,[3,[4,[5,6,0]]]],8,9]",
"",
"[2,1]",
"[[0,0,0],[2]]",
"",
"[[],[10,[5],[],[6,[2,4,4,8,9],[0,0,8,9],[8],4]],[5,[],7,3,[[5],[8,9,1],7,[9]]],[6,5]]",
"[[[3,[],[],[3],[6,1,4,4]],5,[],6],[[[6,6,2]],5,[5,5],7],[[[9,8,1,10,0],1,[2,10,0,9,6]],1,4,9]]",
"",
   };

    return input;
}
