#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;
using pii = pair<int,int>;
int N,M;
vector<vector<int> > G;
vector<bool> visited;
vector<set<int> > result;
void bfs(int x)
{
    visited[x] = true;
    queue<pii> pq;
    pq.push({x,0});
    while (!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        if(v.second <= 6)
            result[x].insert(v.first);
        for(auto w : G[v.first])
        {
            if(!visited[w])
            {
                visited[w] = true;
                pq.push({w,v.second + 1});
            }
        }
    }
    
}
int main()
{
    cin>>N>>M;
    G.resize(N+1);
    visited.resize(N+1);
    result.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1;i <= N;++i)
    {
        fill(visited.begin(),visited.end(),false);
        bfs(i);
    }
    for(int i = 1;i <= N;++i)
    {
        double pa = (result[i].size()*100)/(N*1.0);
        cout<<i<<": "<<fixed<<setprecision(2)<<pa<<"%"<<endl;
    }
    return 0;
}