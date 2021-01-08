#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int M,N,K;
bool judge(vector<int>& ves)
{
    int cnt = 1;
    stack<int> st;
    for(auto &e : ves)
    {
        while (st.empty()||(!st.empty()&&st.top() < e))
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
    while(K--)
    {
        vector<int> ves;
        for(int i = 0;i < N;++i)
        {
            int x;
            cin>>x;
            ves.push_back(x);
        }
        cout<<(judge(ves) ? "YES\n" : "NO\n");
    }
    return 0;
}