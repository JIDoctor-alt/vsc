#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
vector<bool> vis,occupied;
int N,M,K;
void dfs(int x)
{
    vis[x] = true;
    for(auto &w : G[x])
    {
        if(!vis[w]&&!occupied[w])
            dfs(w);
    }
}
int judge()
{
    int  cnt = 0;

    for(int i = 1;i <= N;++i)
    {
        if(!vis[i]&&!occupied[i])
        {
            ++cnt;
            dfs(i);
        }
    }
    return cnt;
}
int main()
{
    cin>>N>>M>>K;
    G.resize(N+1);
    vis.resize(N+1);
    occupied.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int  i = 0;i < K;++i)
    {
        fill(occupied.begin(),occupied.end(),false);
        fill(vis.begin(),vis.end(),false);

        int oc;
        cin>>oc;
        occupied[oc] = true;
        cout<<(judge() - 1)<<endl;
    }


    return 0;
}