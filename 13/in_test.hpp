#pragma once
#include "../help_func.hpp"

inline auto getInput()
{
    VECS input {
"4",
"[4]",
"",
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
""
   };

    return input;
}
