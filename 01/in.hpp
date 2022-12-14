#pragma once
#include "../help_func.hpp"

inline VECS getInput()
{
    std::ifstream file("input");
    std::string str;
    VECS input;
    while (std::getline(file, str))
    {
        input.push_back(str);
    }
    return input;
}
