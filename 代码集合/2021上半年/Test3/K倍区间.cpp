#include<iostream>
#include<vector>
using namespace std;
int N,K;
vector<int> g;
int testnum = 0,ans = 0;
void f()
{
     for(int i = 0;i < N;++i)
    {
        testnum = g[i];
        if(testnum % K == 0)
            ans++;
        for(int j = i+1;j < N;++j)
        {
                testnum += g[j];
                if(testnum % K ==0)
                    ans++;
        }
    }
}
void dfs(int x)
{
    if(x >= N)
        return;
    if(testnum % K == 0)
        ++ans;
    testnum += g[x];
    dfs(x+1);
}
int main()
{
    cin>>N>>K;
    g.resize(N);
    for(int i = 0;i < N;++i)
        cin>>g[i];
    
    for(int i = 0;i < N;++i)
    {
        testnum = g[i];
        dfs(i+1);
    }
    cout<<ans<<endl;
    return 0;
}