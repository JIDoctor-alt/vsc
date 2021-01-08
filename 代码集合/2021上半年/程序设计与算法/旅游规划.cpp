#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using pii = pair<int,int>;
struct Edge
{
    int to,w;
    int cost;
};
vector<vector<Edge> > G;
vector<int> dis;
vector<int> CountCost;
int N,M,S,D;
void Dijkstra()
{
    fill(dis.begin(),dis.end(),0x3f3f3f3f);
    dis[S] = 0;
    CountCost[S] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,S});
    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        int d = v.first, x = v.second;
        if(d > dis[x])
            continue;
        for(auto &e : G[x])
        {
            if(dis[x] + e.w < dis[e.to])
            {
                dis[e.to] = dis[x] + e.w;
                pq.push({dis[e.to],e.to});
                CountCost[e.to] = CountCost[x] + e.cost;
            }else if(dis[x] + e.w == dis[e.to])
            {

                if(CountCost[e.to] > CountCost[x] + e.cost)
                    CountCost[e.to] = CountCost[x] + e.cost;
                dis[e.to] = dis[x] + e.w;
                pq.push({dis[e.to],e.to});
            }
        }
    }
}
int main()
{
    cin>>N>>M>>S>>D;
    G.resize(N);
    dis.resize(N);
    CountCost.resize(N);
    for(int i = 0;i < M;++i)
    {
        int x,y,c,d;
        cin>>x>>y>>c>>d;
        G[x].push_back({y,c,d});
        G[y].push_back({x,c,d});
    }
    Dijkstra();
    cout<<dis[D]<<" "<<CountCost[D]<<endl;
    return 0;
}