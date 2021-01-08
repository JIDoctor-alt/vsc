#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N,M,K;
int main()
{
    cin>>N>>M>>K;
    for(int j = 0;j < K;++j)
    {
        vector<int> ves;
        for(int i = 0;i < N;++i)
        {
            int x;
            cin>>x;
            ves.push_back(x);
        }
        int cnt = 1;
        stack<int> st;
        bool flag = true;
        for(auto &x : ves)
        {

            if(cnt == x)
            {
                ++cnt;
            }
            else 
            {
                while(!st.empty()&&st.top() == cnt)
                {
                    st.pop();
                    ++cnt;
                }
                st.push(x);

                if(st.size()> M)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            while(!st.empty()&&st.top() == cnt)
            {
                ++cnt;
                st.pop();
            }
        }
        cout<<(cnt == N + 1 ? "YES\n" : "NO\n");
    }
    return 0;
}