#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
int N,M;
vector<bool> visited;
vector<bool> fl;
bool flag;
void dfs(int x)
{
    visited[x] = true;

    for(auto &w : G[x])
    {
        if(!visited[w]&&!fl[w])
        {
            flag = false;
            return;
        }
    }
}
bool judge()
{
    flag = true;
    for(int i = 1;i <= N;++i)
    {
        if(!visited[i] && !fl[i])
        {
            dfs(i);
            if(!flag)
                break;
        }
    }
    return flag;
}
int main()
{
    cin>>N>>M;
    G.resize(N+1);
    visited.resize(N+1);
    fl.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int K;
    cin>>K;
    while(K--)
    {
         int d;
         cin>>d;
         fill(fl.begin(),fl.end(),false);
         fill(visited.begin(),visited.end(),false);
         for(int i = 0;i < d;++i)
         {
             int w;
             cin>>w;
             fl[w] = true;
         }
         cout<<(judge() ? "YES\n" : "NO\n");
    }

    return 0;
}