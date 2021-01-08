#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<functional>
using namespace std;
using pii = pair<int,int>;// 对应最短路径值，对应结点
struct Edge
{
    int to, w;
};
vector<Edge> g[100005];
int d[100005];
int N, M ,S,D;
void dijkstra(int s)
{
    fill(d, d + N + 1,0x3f3f3f3f);
    d[s] = 0;
    priority_queue<pii, vector<pii> , greater<pii> > pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto n = pq.top();
        pq.pop();
        int x = n.second, c = n.first;
        if(c > d[x])//队列中所保存的已经找到的结点之前的dis
            continue;
        for(auto &e : g[x])
        {
            int i = e.to , w = e.w;
            if(d[i] > d[x] + w)
            {
                d[i] = d[x] + w;
                pq.push({d[i],i});
            }
        }
    }
}
int main()
{
    cin>>N>>M>>S>>D;//顶点数，边数，起点
    while(M--)
    {
        int x,y,w;//v1 , v2 , w{v1,v2}
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    
    dijkstra(S);
    cout<<d[D]<<endl;
    return 0;
}
/*
4 5 0
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2
*/