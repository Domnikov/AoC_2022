#define TEST
#include <stack>

#ifdef TEST
    #include "in_test.hpp"
#else
    #include "in.hpp"
#endif

S get_path(VECS pwd)
{
    S res;
    for(auto d:pwd)
    {
        res += d;
    }
    return res;
}

int check(char c)
{
    return -1;
}

int main(int argc, char** argv)
{
    auto in = getInput();

    std::map<S, ULL> fs;
    VECS pwd;

    P(__LINE__);
    FOR(i,in.size())
    {
        S s = in[i];
        if(s == "$ cd ..")
        {
            pwd.erase(pwd.end()-1);
        }
        else if(s.find("$ cd /") == 0)
        {
            S dir = s.substr(3);
            pwd.clear();
            pwd.push_back(dir);
        }
        else if(s.find("$ cd ") == 0)
        {
            S dir = s.substr(3);
            pwd.push_back("/" + dir);
        }
        else if (s == "$ ls")
        {
            ULL size{};
            while(++i < in.size() && in[i][0] != '$')
            {
                size += stoi(splitStr(in[i],' ')[0]);
            }
            S path = get_path(pwd);
            P(path,size);
            fs[path] = size;
            --i;
        }
    }
    for(auto p : fs)
    {
        S dir = p.first;
        ULL size = p.second;
        P(dir,size);
    }

    ULL score = 0;
    P(score);
}

