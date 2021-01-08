#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int M,N,K;
bool f(vector<int>& ves)
{
    stack<int> st;
    int cnt = 1;

    for(auto &e : ves)
    {
        while(st.empty() || (!st.empty()&&st.top() < e))
        {
            st.push(cnt++);
        }
        
        if(st.size() > M)
            return false;
        
        if(!st.empty() && st.top() == e)
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
        vector<int> ves;
        for(int j = 0;j < N;++j)
        {
            int x;
            cin>>x;
            ves.push_back(x);
        }
        cout<<(f(ves) ? "YES\n" : "NO\n");
    }
    return 0;
}