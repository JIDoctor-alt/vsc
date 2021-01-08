#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using pii = pair<int,int>;
struct Edge
{
    int to,w;
};
vector<vector<Edge> > G;
vector<int> dis;
vector<int> Cost;
vector<int> pre;
vector<int> ans;
vector<int> CountCost;
int N,M,S,D;
void printPath(int x)
{
    if(pre[x] == -1)
    {
        cout<<x;
        return;
    }
    printPath(pre[x]);
    cout<<" "<<x;
}
void Dijkstra()
{
    fill(dis.begin(),dis.end(),0x3f3f3f3f);
    dis[S] = 0;
    ans[S] = 1;
    CountCost[S] = Cost[S];
    pre[S] = -1;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,S});
    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        int w = v.first, x = v.second;

        if(dis[x] < w)
            continue;

        for(auto &e : G[x])
        {
            if(dis[e.to] > dis[x] + e.w)
            {
                dis[e.to] = dis[x] + e.w;
                pre[e.to] = x;
                ans[e.to] = ans[x];
                CountCost[e.to] =Cost[e.to] + CountCost[x];

                pq.push({dis[e.to],e.to});
            }
            else if(dis[e.to] == dis[x] + e.w)
            {
                
                ans[e.to] += ans[x];
                if(CountCost[e.to] < Cost[e.to] + CountCost[x])
                {
                    CountCost[e.to] = Cost[e.to] + CountCost[x];
                    pre[e.to] = x;//五条不同的最短路径
                }
              //  pre[e.to] = x;
                dis[e.to] = dis[x] + e.w;
            }
        }
    }
}
int main()
{
    cin>>N>>M>>S>>D;
    G.resize(N);
    dis.resize(N);
    Cost.resize(N);
    pre.resize(N);
    ans.resize(N);
    CountCost.resize(N);

    for(int i = 0;i < N;i++)
        cin>>Cost[i];
    for(int i = 0;i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }
    Dijkstra();
    cout<<ans[D]<<" "<<CountCost[D]<<endl;
    printPath(D);
    return 0;
}