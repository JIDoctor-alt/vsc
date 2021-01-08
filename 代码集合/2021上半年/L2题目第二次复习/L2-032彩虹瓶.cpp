#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int N,M,K;
int main()
{
    
    cin>>N>>M>>K;
    vector<int> stu;
    stu.resize(N);
    while(K--)
    {
        bool flag = true;
        for(int i = 0;i < N;++i)
            cin>>stu[i];
        stack<int> ps;
        int ans = 1;
        for(int i = 0;i < N;++i)
        {
            int p = stu[i];
            if(p == ans)
            {
                ++ans;
            }
            else 
            {
                    while(!ps.empty()&&ps.top() == ans)
                    {
                        ps.pop();
                        ++ans;
                    }
                    ps.push(p);
                    if(ps.size() > M)
                    {
                        flag = false;
                        break;
                    }
            }
        }
        if(flag)
        {
            while(!ps.empty()&&ans == ps.top())
            {
                ps.pop();
                ++ans;
            }
        }
        if(ans == N+1)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;

    }
    return 0;
}