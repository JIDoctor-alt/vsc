#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G,rG;
vector<int> postOrder;///逆拓扑序列
vector<int> sccNo;
vector<bool> visited;
vector<vector<int> > res;
int sccflag;
int N,M,cnt;
void dfs1(int x)
{
    visited[x] = true;
    for(auto w : G[x])
    {
        if(!visited[w])
            dfs1(w);
    }
    postOrder.push_back(x);
}
void dfs2(int x)
{
    sccNo[x] = sccflag;
    for(auto w : rG[x])
    {
        if(sccNo[w] == 0)
            dfs2(w);
    }
}
void kosaraju()
{
    for(int i = 1;i <= N;++i)
    {
        if(!visited[i])
            dfs1(i);
    }
    reverse(postOrder.begin(),postOrder.end());
    fill(sccNo.begin(),sccNo.end(),0);
    for(auto x : postOrder)
    {
        if(sccNo[x] == 0)
        {
            ++sccflag;
            dfs2(x);
        }
    }
}
void dfs3(int x)
{
    visited[x] = true;
    ++cnt;
    for(auto w : rG[x])
    {
        if(!visited[w])
            dfs3(w);
    }
}
int CowsNum()
{
    int ans = 0;
    for(int i = 1;i <= N;++i)
    {
        if(sccNo[i] == sccflag)
        {
            cnt = 0;
            fill(visited.begin(),visited.end(),false);
            dfs3(i);
            if(cnt == N)
                ++ans;
        }
    }
    return ans;
}
int main()
{
    cin>>N>>M;
    G.resize(N+1);
    rG.resize(N+1);
    sccNo.resize(N+1);
    res.resize(N+1);
    visited = vector<bool>(N+1,false);
    while(M--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        rG[y].push_back(x);
    }
    kosaraju();
    cout<<CowsNum()<<endl;
}