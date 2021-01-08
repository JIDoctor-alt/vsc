#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    string str;
    int id;
    bool operator<(const node e)const
    {
        if(str.size() != e.str.size())
             return str.size() < e.str.size();
        else 
            return id < e.id;
    }
};
vector<node> st;
int main()
{
    string str;
    int cnt = 0;
    while(cin>>str && str != "#")
    {
        ++cnt;
        node c;
        c.str = str;
        c.id = cnt;
        st.push_back(c);
    }
    sort(st.begin(),st.end());
    for(auto &e : st)
    {
        cout<<e.str<<" ";
    }

    return 0;
}