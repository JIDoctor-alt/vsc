#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
vector<vector<int> > G;
vector<bool> visited;
void dfs(int x)
{
    visited[x] = true;
    for(auto &w : G[x])
    {
        if(!visited[w])
            dfs(w);
    }
}
int repairRoad(int x)
{
    fill(visited.begin(),visited.end(),false);
    visited[x] = true;
    int cnt = 0;//计数器记录多少连通分量
    for(int i = 1;i <= N;++i)
    {
        if(!visited[i])
        {
            dfs(i);
            ++cnt;
        }
    }
    return cnt-1;    
}
int main()
{
    cin>>N>>M>>K;
    G.resize(N+1);
    visited.resize(N+1);
    while (M--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    while (K--)
    {
        int id;
        cin>>id;
        cout<<repairRoad(id)<<endl;
    }
    
    
    return 0;
}