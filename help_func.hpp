#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

#define P_RR(...) fprintf(stderr, __VA_ARGS__);
#define P(a) std::cerr << #a << " = " << a << std::endl;

#define LL    long long
#define ULL   unsigned long long
#define S     std::string
#define VECI  std::vector<LL>
#define VECF  std::vector<double>
#define VECS  std::vector<S>
#define VECSS std::vector<std::vector<S>>

template<typename T>
void _P_VEC (const std::vector<T> vec)
{
    std::cerr << " = [";

    if(!vec.empty())
    {
        std::copy (vec.begin(), vec.end()-1, std::ostream_iterator<T>(std::cerr, ";"));
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
        std::cerr << i;
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

inline VECS splitStr(S str, char delim)
{
    VECS res;
    std::stringstream ss(str);
    while(ss.good())
    {
        std::string sub;
        std::getline(ss, sub, delim);
        res.push_back(sub);
    }
    return res;
}

inline VECS inToVecS(const char* fileName = "input")
{
    std::ifstream file(fileName);
    S str;
    VECS input;
    while (std::getline(file, str))
    {
        input.push_back(str);
    }
    return input;
}

inline VECI inToVecI(const char* fileName = "input")
{
    auto in = inToVecS(fileName);
    VECI input;
    std::transform(in.begin(), in.end(), std::back_inserter(input), [](const auto& s){return stoi(s);});
    return input;
}

inline VECF inToVecF(const char* fileName = "input")
{
    auto in = inToVecS(fileName);
    VECF input;
    std::transform(in.begin(), in.end(), std::back_inserter(input), [](const auto& s){return stof(s);});
    return input;
}

inline VECSS inToVecSS(char delim = ',', const char* fileName = "input")
{
    auto in = inToVecS(fileName);
    VECSS input;
    std::transform(in.begin(), in.end(), std::back_inserter(input), [delim](const auto& s){return splitStr(s, delim);});
    return input;
}
