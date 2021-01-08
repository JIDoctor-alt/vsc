#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
string s,t;
vector<string> ans;
int n;
bool f()
{
    stack<char> stk;
    for(int i = 0,j = 0;i < n;)
    {
        if(s[j] == t[i])
        {
            ans.push_back("1->2");
            ++i,++j;
        }
        else if(!stk.empty()&&stk.top() == t[i])
        {
            stk.pop();
            ++i;
            ans.push_back("3->2");
        }
        else if(j < n && s[j] != t[i])
        {
            stk.push(s[j++]);
            ans.push_back("1->3");
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
    n = s.length();
    if(f())
    {
        for(auto i : ans)
        {
            cout<<i<<endl;
        }
    }
    else 
    {
        cout<<"Are you kidding me?"<<endl;
    }
    return 0;
}