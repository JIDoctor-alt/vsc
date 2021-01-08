#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;
using pii = pair<int,int>;
struct edge
{
    int to,cost;
};
vector<int> Rc,totalPeo,PeoNum;
vector<int> dis,pre;
vector<vector<edge> > G;
int N,M,S,D;
void Dijkstra()
{
    dis = vector<int>(N,0x3f3f3f3f);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    dis[S] = 0;
    Rc[S] = 1;
    totalPeo[S] = PeoNum[S];
    pre[S] = -1;    

    pq.push({dis[S],S});

    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();

        int x = v.second;

        if(dis[x] < v.first)
            continue;
        
        for(auto &w : G[x])
        {
            int e = w.to,l = w.cost;
            if(dis[e] > dis[x] + l)
            {
                Rc[e] = Rc[x];
                totalPeo[e] = totalPeo[x] + PeoNum[e];
                dis[e] = dis[x] + l;
                pre[e] = x;

                pq.push({dis[e],e});
            }
            else if(dis[e] == dis[x] + l)
            {
                 Rc[e] += Rc[x];
                
                 if(totalPeo[e] < totalPeo[x] + PeoNum[e])
                 {
                     totalPeo[e] = totalPeo[x] + PeoNum[e];
                     pre[e] = x;
                 }
            }
        }
    }
}
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
int  main()
{
    cin>>N>>M>>S>>D;
    G.resize(N);
    Rc.resize(N);
    totalPeo.resize(N);
    PeoNum.resize(N);
    pre.resize(N);

    for(int i = 0; i < N;++i)
    {
        cin>>PeoNum[i];//救援队的数目
    }
    for(int i = 0;i < M;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }

    Dijkstra();

    cout<<Rc[D]<<" "<<totalPeo[D]<<endl;
    printPath(D);
    return 0;
}