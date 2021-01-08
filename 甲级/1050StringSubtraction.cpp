#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    set<char> st;
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    for(auto &c : str2)
    {
        st.insert(c);
    }
    for(auto &w : str1)
    {
        if(!st.count(w))
            cout<<w;
    }

    return 0;
}