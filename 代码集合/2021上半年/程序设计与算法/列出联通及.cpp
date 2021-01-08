#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
vector<bool> visited;
vector<set<int> > G;
int N,E;
void dfs(int x)
{
    visited[x] = true;
    cout<<" "<<x;
    for(auto w : G[x])
    {
        if(!visited[w])
        {
            dfs(w);
        }
    }
}
void bfs(int x)
{
    visited[x] = true;
    queue<int> pq;
    pq.push(x);
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        cout<<" "<<v;
        for(auto w : G[v])
        {
            if(!visited[w])
            {
                visited[w] = true;
                pq.push(w);
            }
        }
    }
}
int main()
{
    cin>>N>>E;
    G.resize(N);
    visited.resize(N);
    for(int i = 0;i < E;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].insert(y);
        G[y].insert(x);
    }
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i])
        {
            cout<<"{";
            dfs(i);
            cout<<" }\n";
        }
    }
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i])
        {
            cout<<"{";
            bfs(i);
            cout<<" }\n";
        }
    }
    return  0;
}