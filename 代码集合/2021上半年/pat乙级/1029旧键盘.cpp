#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
int main()
{
    string str,strre;
    set<char> st;
    vector<char> res;
    getline(cin,str);
    getline(cin,strre);
    for(int  i = 0;i < str.size();++i)
    {
        if(strre.find(str[i]) == string::npos)
        {
            char f = toupper(str[i]);
            if(st.count(f) == 0)
            {
                st.insert(f);
                res.push_back(f);
            }
        }
    }
    for(auto i : res)
    {
        cout<<i;
    }
    return 0;
}