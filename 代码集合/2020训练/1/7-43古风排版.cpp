#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    string sx;
    getline(cin,sx);
    set<char> st;

    for(auto &c : sx)
    {
        st.insert(c);
    }
    for(auto &c : str)
    {
        if(!st.count(c))
            cout<<c;
    }
    return 0;
}