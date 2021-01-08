#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
string s,t;
int n;
vector<string> ans;
bool f()
{
    stack<char> st;
    int i = 0,j = 0;
    for(;i < n;)
    {
        if(s[j] == t[i])
        {
            ++j,++i;
            ans.push_back("1->2");
        }
        else if(!st.empty()&&st.top() == t[i])
        {
            ++i;
            st.pop();
            ans.push_back("3->2");
        }
        else if(j < n && s[j] != t[i])
        {
            st.push(s[j]);
            ans.push_back("1->3");
            ++j;
        }
        else 
        {
            return false;
        }
    }
    return true;
}
int main()
{   
    cin>>s>>t;
    n = t.length();

    if(f())
    {
        for(auto i : ans)
            cout<<i<<endl;
    }
    else    
    {
        cout<<"Are you kidding me?\n";
    }
    return 0;
}