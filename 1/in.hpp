#pragma once
#include "../help_func.hpp"
#include <fstream>

VECS getInput()
{
    std::ifstream file("input");
    std::string str;
    VECS input;
    while (std::getline(file, str))
    {
        input.push_back(str);
    }
}
