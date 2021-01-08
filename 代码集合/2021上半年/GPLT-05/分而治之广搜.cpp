#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector< vector<int> > g;
vector<bool> visited;
int N,M,K,Np;
bool bfs(int x)
{
    queue<int> pq;
    pq.push(x);
    visited[x] = true;
    while (!pq.empty())
    {
        int v  =  pq.front();
        pq.pop();
        for(auto w : g[v])
            if(!visited[w])
                return true;    
    }
    return false;
}
bool check()
{
    for(int i = 1;i <= N;++i)
        if(!visited[i] && bfs(i))
            return false;
    return true;

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
    cin>>K;
    while (K--)
    {
        fill(visited.begin(),visited.end(),false);
        cin>>Np;
        while (Np--)
        {
            int num;
            cin>>num;
            visited[num] = true;
        }
        
        cout<<(check() ? "YES\n":"NO\n");
    }
    
    
    return 0;
}