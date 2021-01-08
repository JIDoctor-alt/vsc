#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int M,N,K;
bool f(vector<int>& ans)
{
    stack<int> st;
    int cnt = 1;
    for(auto e : ans)
    {
        while(st.empty()||!st.empty()&&st.top() < e)
        {
            st.push(cnt++);
        }

        if(st.size() > M)
            return false;
        
        if(!st.empty()&&st.top() == e)
        {
            st.pop();
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

    cin>>M>>N>>K;
    for(int i = 0;i < K;++i)
    {
       // stack<int> st;
        vector<int> ans;

        for(int j = 0; j < N;++j)
        {
            int id;
            cin>>id;
            ans.push_back(id);
        }
        cout<<(f(ans)  ? "YES\n" : "NO\n");

    }
}