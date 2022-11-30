#pragma once

#define P_RR(...) fprintf(stderr, __VA_ARGS__);

#define P_I(a) fprintf(stderr, #a " = %d\n", a);
#define P_F(a) fprintf(stderr, #a " = %f\n", a);

#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>


template<typename T>
void _P_VEC (const std::vector<T> vec)
{
    std::cerr << " = [";

    if(!vec.empty())
    {
        std::copy (vec.begin(), vec.end()-1, std::ostream_iterator<T>(std::cerr, ","));
        std::cerr << vec.back();
    }

    std::cerr << "]\n";
}


template<typename T>
void _P_VEC (const std::vector<std::vector<T>> vec)
{
    std::cout << ":" << std::endl;
    for(size_t i = 0; i < vec.size(); i++)
    {
        _P_VEC(vec[i]);
    }
}

#define P_VEC(a) fprintf(stderr, #a);_P_VEC(a)

template<typename T>
void _P_VECV (const std::vector<T> vec)
{
    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cerr << "\t" << i << "\t" << vec[i] << std::endl;
    }
}
#define P_VECV(a) fprintf(stderr, #a ":\n");_P_VECV(a)

template<typename T>
void _P_VECH (const std::vector<T> vec)
{
    std::cerr << "[";
    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cerr << vec[i] << "[" << i << "]";
        if(i != vec.size()-1)
        {
            std::cerr << ",";
        }
    }
    std::cerr << "]\n";
}
#define P_VECH(a) fprintf(stderr, #a " = ");_P_VECH(a)

#define FOR(i,a) for(decltype(a)  i{};  i != a; ++i)

