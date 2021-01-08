#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string answer,str;
    getline(cin,answer);
    getline(cin,str);
    vector<char> res;
    bool flag = true;
    if(str.find('+') != string::npos)
    {
        flag = false;
    }
    for(int i = 0;i < str.size();++i)
    {
        char c = str[i];
        if(!flag)
        {
            if(isupper(str[i]))
            {
                continue;
            }
        }
        if(isalpha(c))
        {
            c = toupper(c);
        }
        if(answer.find(c) == string::npos)
        {
            res.push_back(str[i]);
        }
    }
    if(res.size() == 0)
    {
        cout<<" "<<endl;
    }
    else 
    {
       for(auto i : res)
       {
           cout<<i;
       }
    }
    return 0;
}