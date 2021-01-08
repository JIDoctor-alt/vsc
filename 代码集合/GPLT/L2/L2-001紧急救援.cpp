#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
struct edge{
    int to,l;
};
int N,M,S,D;
vector<int> dis,team,totalTeam,Rc,pre;
vector<vector<edge> > G;
void Dijkstra(){
    dis = vector<int>(N,0x3f3f3f3f);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    dis[S] = 0;
    Rc[S] = 1;
    totalTeam[S] = team[S];
    pq.push({0,S});

    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();

        int  x = v.second;
        if(dis[x] < v.first)
            continue;

        for(auto &e : G[x]){

            if(dis[e.to] > dis[x] + e.l){
                Rc[e.to] = Rc[x];
                totalTeam[e.to] = totalTeam[x] + team[e.to];
                dis[e.to] = dis[x] + e.l;
                pre[e.to] = x;
                pq.push({dis[e.to],e.to});
            }else if(dis[e.to] == dis[x] + e.l){
                Rc[e.to] += Rc[x];

                if(totalTeam[e.to] < totalTeam[x] + team[e.to])
                {
                    pre[e.to] = x;
                    totalTeam[e.to] = totalTeam[x] + team[e.to];
                }
            }
        }
    }
}
void printPath(int x){
    if(x == S)
    {
        cout<<x;
        return;
    }
    printPath(pre[x]);
    cout<<" "<<x;
}
int main()
{
    cin>>N>>M>>S>>D;
    team.resize(N);
    totalTeam.resize(N);
    Rc.resize(N);
    G.resize(N);
    pre.resize(N);
    for(int i = 0;i < N;++i){
        cin>>team[i];
    }
    for(int i = 0;i < M;++i){
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }
    Dijkstra();
    cout<<Rc[D]<<" "<<totalTeam[D]<<endl;
    printPath(D);
    return 0;
}