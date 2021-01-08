#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,E;
vector<vector<int> > g;
vector<bool> visited;
void dfs(int x)
{
    visited[x] = true;
    cout<<x<<" ";
    for(auto &w : g[x])
    {
        if(!visited[w])
        {
            dfs(w);
        }
    }
}
void bfs(int x)
{
    queue<int> pq;
    pq.push(x);
    visited[x] = true;
    cout<<"{ ";
    while (!pq.empty())
    {
        int v = pq.front();
        pq.pop();
        cout<<v<<" ";
        for(auto &w : g[v])
        {
            if(!visited[w])
            {
                visited[w] = true;
                pq.push(w);
            }
        }
    }
    cout<<"}\n";
}
int main()
{
    cin>>N>>E;
    g.resize(N);
    visited.resize(N);
    for(int i = 0;i < E;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0;i < N;++i)
        sort(g[i].begin(),g[i].end());
    
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i])
        {
            cout<<"{ ";
            dfs(i);
            cout<<"}\n"; 
        }
    }
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i])
        {
            bfs(i);
        }
    }
    return 0;
}