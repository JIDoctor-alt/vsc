#include<iostream>
#include<set>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    int N,K,M;
    cin>>N>>M>>K;
   
    while(K--)
    {
        int cnt = 1;
        stack<int> st;

        bool flag = true;
        vector<int> cont;
        for(int i = 0;i < N;++i)
        {
            int xid;
            cin>>xid;
            cont.push_back(xid);
        }
        

        for(auto &e : cont)
        {
           
            if(e == cnt)
            {
                ++cnt;
            }
            else 
            {

                while(!st.empty()&&cnt == st.top())
                {
                    ++cnt;
                    st.pop();
                }

                st.push(e);

                if(st.size() > M)
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
        {
            while(!st.empty()&&cnt == st.top())
            {
                ++cnt;
                st.pop();
            }
        }
        cout<<(cnt == N +1? "YES\n" : "NO\n");
    }
    return 0;
}