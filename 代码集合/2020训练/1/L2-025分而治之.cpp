#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<vector<int> > g;
vector<bool> visited;
void dfs(int x)
{
    visited[x] = true;
    for(auto w : g[x])
    {
        if(!visited[w])
            dfs(w);
    }
}
int main()
{
    cin>>N>>M;
    g.resize(N+1);
    visited.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int K;
    cin>>K;
    while(K--)
    {
        int Np;
        cin>>Np;
        fill(visited.begin(),visited.end(),false);
        for(int i = 0;i < Np;++i)
        {
            int xid;
            cin>>xid;
            visited[xid] = true;
        }
        int ans = 0;
        for(int i = 1 ; i <= N;++i)
        {
            if(!visited[i])
            {
                dfs(i);
                ++ans;
            }
        }
        if(ans + Np == N)
        {
            cout<<"YES\n";
        }
        else 
        {
            cout<<"NO\n";
        }
    }
    return 0;
}