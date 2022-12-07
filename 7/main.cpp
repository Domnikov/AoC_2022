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
        if(res[res.length()-1] != '/')res += '/';
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

    FOR(i,in.size())
    {
    P(__LINE__);
        S s = in[i];
        P(s);
        if(s == "$ cd ..")
        {
    P(__LINE__);
            pwd.erase(pwd.end()-1);
        }
        else if(s.find("$ cd /") == 0)
        {
    P(__LINE__);
            S dir = s.substr(5);
            pwd.clear();
            pwd.push_back(dir);
        }
        else if(s.find("$ cd ") == 0)
        {
    P(__LINE__);
            S dir = s.substr(5);
            pwd.push_back(dir);
        }
        else if (s == "$ ls")
        {
    P(__LINE__);
            ULL size{};
            while(++i < in.size() && in[i][0] != '$')
            {
    P(__LINE__);
    P(in[i]);
                if(in[i].find("dir ") != 0)
                {
                    size += stoi(splitStr(in[i],' ')[0]);
                }
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

