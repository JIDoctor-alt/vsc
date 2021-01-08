#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int N,M,K;
int te[1005];
int main()
{
    cin>>N>>M>>K;
    while(K--)
    {
        vector<int> peo;
        for(int i = 0;i < N;++i)
        {
            int nx;
            cin>>nx;
            peo.push_back(nx);
        }
        stack<int> st;
        int cnt = 1;
        bool flag = true;
        for(auto w : peo)
        {
            int coutx = w;
            if(coutx == cnt)
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
                st.push(coutx);
                if(st.size() > M)
                {
                    flag = false;
                    break;
                }
            }
            
        }


        if(flag&&!st.empty())
            {
                while(!st.empty()&&st.top()==cnt)
                {
                    st.pop();
                    ++cnt;
                }
            }
            cout<<(cnt == N + 1 ? "YES\n" : "NO\n");
    }
    return 0;
}