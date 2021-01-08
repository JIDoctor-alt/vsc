#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    map<int,int> ms;
    int N,M;
    cin>>N>>M;
    for(int i = 0;i < M;++i)
    {
        int id;
        cin>>id;
        ++ms[id];
    }
    int ans = 0,peonum = 0;
    for(int i = 0;i < N;++i)
    {
        string name;
        bool flag = false;
        cin>>name;
        int K;
        cin>>K;
        int cnt = 0;
        while(K--)
        {
            int id;
            cin>>id;
            if(ms[id])
            {
                if(!flag)
                {
                    flag = true;
                }
                ++ans;
                ++cnt;
                if(cnt == 1)
                {
                    cout<<name<<":";
                }
                printf(" %04d",id);
            }

        }

        if(flag)
        {
            cout<<endl;
            ++peonum;
        }
    }
    cout<<peonum<<" "<<ans<<endl;
    return 0;
}